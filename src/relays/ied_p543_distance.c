/* ============================================================
 *  ied_p543_distance.c — P543 Distance Protection Relay
 *  GI 150kV ANTAM POMALAA — Line-1 and Line-2 protection
 *
 *  Standalone executable: E05_P543.exe / E06_P543.exe
 *  Static model:          model_E05_P543 / model_E06_P543
 *
 *  Protection functions:
 *    PDIS1-4  Distance protection zones 1-4
 *    PTRC1    Trip relay
 *    RREC1    Auto-reclose
 *    RSYN1    Synchronism check
 *    MMXU1    Measurement (V, I, W, VAr, Hz)
 *
 *  Usage: E05_P543.exe config/E05_P543.json
 * ============================================================ */
#include "ied_server_base.h"
#include "iec61850_server.h"
#include "hal_thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* ---- Import the compiled static model ----
 * Which model is linked depends on CMakeLists target.
 * The extern symbol is model_E05_P543 or model_E06_P543. */
#ifndef MODEL_EXTERN
#define MODEL_EXTERN model_E05_P543
#endif
extern IedModel MODEL_EXTERN;

/* ---- Protection state machine ---- */
typedef enum {
    ST_IDLE = 0,
    ST_STARTED,           /* Pickup / start */
    ST_TRIPPED,           /* Trip issued */
    ST_AR_DEAD_TIME,      /* Auto-reclose dead time */
    ST_AR_SYNC_CHECK,     /* Sync check */
    ST_AR_RECLOSED,       /* Reclosed, reclaim time running */
    ST_LOCKOUT,           /* Final trip, locked out */
} ProtState;

/* ---- Per-instance context ---- */
typedef struct {
    ProtState state;
    int       fault_zone;       /* 1-4, 0=none */
    int       fault_active;     /* 1=injected fault present */
    uint64_t  state_enter_ms;
    int       ar_attempts;

    /* Simulated analogs */
    float i_a, i_b, i_c;       /* Phase currents (A) */
    float v_a, v_b, v_c;       /* Phase voltages (kV) */
    float freq;
    float tot_w, tot_var;
} P543Context;

/* ---- Nominal values ---- */
#define NOMINAL_V   86.6f
#define NOMINAL_I   200.0f
#define NOMINAL_F   50.0f
#define FAULT_I     5000.0f
#define RECLAIM_MS  5000

/* ---- Helper: update a data attribute by short ref ---- */
static void set_bool(IedServer s, IedModel *m, const char *ref, int val) {
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(m, ref);
    if (da) {
        IedServer_lockDataModel(s);
        IedServer_updateBooleanAttributeValue(s, da, val ? true : false);
        IedServer_unlockDataModel(s);
    }
}

static void set_float(IedServer s, IedModel *m, const char *ref, float val) {
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(m, ref);
    if (da) {
        IedServer_lockDataModel(s);
        IedServer_updateFloatAttributeValue(s, da, val);
        IedServer_unlockDataModel(s);
    }
}

static void set_int(IedServer s, IedModel *m, const char *ref, int val) {
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(m, ref);
    if (da) {
        IedServer_lockDataModel(s);
        IedServer_updateInt32AttributeValue(s, da, val);
        IedServer_unlockDataModel(s);
    }
}

static void set_time(IedServer s, IedModel *m, const char *ref, uint64_t ms) {
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(m, ref);
    if (da) {
        IedServer_lockDataModel(s);
        IedServer_updateUTCTimeAttributeValue(s, da, ms);
        IedServer_unlockDataModel(s);
    }
}

/* ---- Get LD instance name from model ---- */
static const char *get_ld_inst(IedModel *model) {
    LogicalDevice *ld = model->firstChild;
    return ld ? ld->name : "UNKNOWN";
}

/* ---- Zone delay lookup ---- */
static int zone_delay(const IedConfig *cfg, int zone) {
    switch (zone) {
        case 1: return cfg->prot.zone1_delay_ms;
        case 2: return cfg->prot.zone2_delay_ms;
        case 3: return cfg->prot.zone3_delay_ms;
        case 4: return cfg->prot.zone4_delay_ms;
        default: return cfg->prot.zone2_delay_ms;
    }
}

/* ---- Issue trip ---- */
static void do_trip(IedServer s, IedModel *m, P543Context *ctx,
                    const IedConfig *cfg, uint64_t now) {
    const char *ld = get_ld_inst(m);
    char ref[128];

    /* PDIS zone operate */
    snprintf(ref, sizeof(ref), "%s/PDIS%d.Op.general", ld, ctx->fault_zone);
    set_bool(s, m, ref, 1);
    snprintf(ref, sizeof(ref), "%s/PDIS%d.Op.t", ld, ctx->fault_zone);
    set_time(s, m, ref, now);

    /* PTRC trip relay */
    snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.general", ld);
    set_bool(s, m, ref, 1);
    snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.t", ld);
    set_time(s, m, ref, now);

    /* Zero current (CB opened) */
    ctx->i_a = ctx->i_b = ctx->i_c = 0;
    ctx->tot_w = ctx->tot_var = 0;

    printf("[PROT %s] Zone %d TRIP (after %dms)\n",
           cfg->ied_name, ctx->fault_zone, zone_delay(cfg, ctx->fault_zone));
}

/* ---- Clear trip signals ---- */
static void clear_trip(IedServer s, IedModel *m, P543Context *ctx) {
    const char *ld = get_ld_inst(m);
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/PDIS%d.Op.general", ld, ctx->fault_zone);
    set_bool(s, m, ref, 0);
    snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.general", ld);
    set_bool(s, m, ref, 0);
}

/* ---- Update MMXU analogs (3-phase WYE CDC + aggregates) ---- */
static void update_analogs(IedServer s, IedModel *m, P543Context *ctx) {
    const char *ld = get_ld_inst(m);
    char ref[128];

    /* --- Phase Currents: MMXU1.A (WYE CDC) --- */
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsA.cVal.mag.f", ld);
    set_float(s, m, ref, ctx->i_a);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsB.cVal.mag.f", ld);
    set_float(s, m, ref, ctx->i_b);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsC.cVal.mag.f", ld);
    set_float(s, m, ref, ctx->i_c);

    /* Phase angles (120° separation) */
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsA.cVal.ang.f", ld);
    set_float(s, m, ref, 0.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsB.cVal.ang.f", ld);
    set_float(s, m, ref, -120.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsC.cVal.ang.f", ld);
    set_float(s, m, ref, 120.0f);

    /* --- Phase Voltages: MMXU1.PhV (WYE CDC) --- */
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsA.cVal.mag.f", ld);
    set_float(s, m, ref, ctx->v_a);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsB.cVal.mag.f", ld);
    set_float(s, m, ref, ctx->v_b);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsC.cVal.mag.f", ld);
    set_float(s, m, ref, ctx->v_c);

    /* Phase angles (120° separation) */
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsA.cVal.ang.f", ld);
    set_float(s, m, ref, 0.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsB.cVal.ang.f", ld);
    set_float(s, m, ref, -120.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsC.cVal.ang.f", ld);
    set_float(s, m, ref, 120.0f);

    /* --- Aggregate measurements --- */
    snprintf(ref, sizeof(ref), "%s/MMXU1.TotW.mag.f", ld);
    set_float(s, m, ref, ctx->tot_w);
    snprintf(ref, sizeof(ref), "%s/MMXU1.TotVAr.mag.f", ld);
    set_float(s, m, ref, ctx->tot_var);
    snprintf(ref, sizeof(ref), "%s/MMXU1.Hz.mag.f", ld);
    set_float(s, m, ref, ctx->freq);
}

/* ---- Set AR state ---- */
static void set_ar_state(IedServer s, IedModel *m, int state, uint64_t now) {
    const char *ld = get_ld_inst(m);
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/RREC1.AutoRecSt.stVal", ld);
    set_int(s, m, ref, state);
    snprintf(ref, sizeof(ref), "%s/RREC1.AutoRecSt.t", ld);
    set_time(s, m, ref, now);
}

/* ============================================================
 *  PROTECTION TICK — called every 100ms by ied_server_base
 * ============================================================ */
static void p543_tick(IedServer server, IedModel *model,
                      const IedConfig *cfg, uint64_t now_ms, void *ctx_ptr)
{
    P543Context *ctx = (P543Context *)ctx_ptr;
    uint64_t elapsed = now_ms - ctx->state_enter_ms;

    /* Normal-state analog noise */
    if (ctx->state == ST_IDLE && !ctx->fault_active) {
        float noise = (float)(rand() % 100 - 50) / 1000.0f;
        ctx->v_a = NOMINAL_V + noise * 2;
        ctx->v_b = NOMINAL_V - noise;
        ctx->v_c = NOMINAL_V + noise * 0.5f;
        ctx->i_a = NOMINAL_I + noise * 10;
        ctx->i_b = NOMINAL_I - noise * 5;
        ctx->i_c = NOMINAL_I + noise * 3;
        ctx->freq = NOMINAL_F + noise * 0.01f;
        ctx->tot_w = 25.0f + noise;
        ctx->tot_var = 8.0f + noise * 0.5f;
    }

    update_analogs(server, model, ctx);

    switch (ctx->state) {
    case ST_IDLE:
        break;

    case ST_STARTED: {
        int delay = zone_delay(cfg, ctx->fault_zone);
        if ((int)elapsed >= delay) {
            do_trip(server, model, ctx, cfg, now_ms);
            ctx->state = ST_TRIPPED;
            ctx->state_enter_ms = now_ms;
        }
        break;
    }

    case ST_TRIPPED:
        if (cfg->prot.ar_enabled && ctx->ar_attempts < cfg->prot.ar_max_attempts) {
            printf("[PROT %s] Starting AR dead time (%dms)\n",
                   cfg->ied_name, cfg->prot.ar_dead_time_ms);
            ctx->state = ST_AR_DEAD_TIME;
            ctx->state_enter_ms = now_ms;
            set_ar_state(server, model, 1, now_ms);
        } else {
            printf("[PROT %s] LOCKOUT — no auto-reclose\n", cfg->ied_name);
            ctx->state = ST_LOCKOUT;
        }
        break;

    case ST_AR_DEAD_TIME:
        if ((int)elapsed >= cfg->prot.ar_dead_time_ms) {
            printf("[PROT %s] Dead time expired → Sync check\n", cfg->ied_name);
            ctx->state = ST_AR_SYNC_CHECK;
            ctx->state_enter_ms = now_ms;
        }
        break;

    case ST_AR_SYNC_CHECK:
        /* Simulate sync check pass (instantaneous for sim) */
        printf("[PROT %s] Sync check PASS → Reclosing\n", cfg->ied_name);
        ctx->ar_attempts++;
        ctx->state = ST_AR_RECLOSED;
        ctx->state_enter_ms = now_ms;
        set_ar_state(server, model, 2, now_ms);
        if (ctx->fault_active) {
            printf("[PROT %s] Fault persists after reclose!\n", cfg->ied_name);
            ctx->i_a = ctx->i_b = FAULT_I;
        } else {
            /* Fault cleared — restore normal */
            ctx->i_a = ctx->i_b = ctx->i_c = NOMINAL_I;
            ctx->v_a = ctx->v_b = ctx->v_c = NOMINAL_V;
            ctx->freq = NOMINAL_F;
            ctx->tot_w = 25.0f;
            ctx->tot_var = 8.0f;
        }
        break;

    case ST_AR_RECLOSED:
        if (ctx->fault_active && elapsed >= 100) {
            printf("[PROT %s] FINAL TRIP → LOCKOUT (86)\n", cfg->ied_name);
            do_trip(server, model, ctx, cfg, now_ms);
            ctx->state = ST_LOCKOUT;
            ctx->state_enter_ms = now_ms;
            set_ar_state(server, model, 3, now_ms);
        } else if (!ctx->fault_active && (int)elapsed >= RECLAIM_MS) {
            printf("[PROT %s] Reclaim time expired — AR SUCCESSFUL\n", cfg->ied_name);
            clear_trip(server, model, ctx);
            set_ar_state(server, model, 0, now_ms);
            ctx->state = ST_IDLE;
            ctx->ar_attempts = 0;
        }
        break;

    case ST_LOCKOUT:
        /* Stay locked out until manual reset */
        break;
    }
}

/* ============================================================
 *  CONSOLE COMMANDS — inject faults, clear, reset
 * ============================================================ */
static int p543_command(IedServer server, IedModel *model,
                        const IedConfig *cfg, const char *cmd, void *ctx_ptr)
{
    P543Context *ctx = (P543Context *)ctx_ptr;
    (void)server; (void)model;

    if (strncmp(cmd, "inject ", 7) == 0) {
        char type_str[32] = {0};
        int zone = 1;
        sscanf(cmd + 7, "%31s %d", type_str, &zone);

        if (ctx->state != ST_IDLE) {
            printf("[PROT %s] Already active (state=%d)\n", cfg->ied_name, ctx->state);
            return 1;
        }

        if (zone < 1 || zone > 4) zone = 1;

        printf("\n[FAULT %s] Injecting %s fault, Zone %d\n\n",
               cfg->ied_name, type_str, zone);

        ctx->fault_active = 1;
        ctx->fault_zone = zone;
        ctx->state = ST_STARTED;
        ctx->state_enter_ms = Hal_getTimeInMs();
        ctx->ar_attempts = 0;

        /* Spike fault current */
        ctx->i_a = FAULT_I;
        ctx->i_b = (strcmp(type_str, "3ph") == 0 || strcmp(type_str, "ph-ph") == 0)
                   ? FAULT_I : NOMINAL_I;
        ctx->i_c = (strcmp(type_str, "3ph") == 0) ? FAULT_I : NOMINAL_I;

        printf("[PROT %s] PDIS%d START pickup\n", cfg->ied_name, zone);
        return 1;
    }

    if (strcmp(cmd, "clear") == 0) {
        printf("[FAULT %s] Fault CLEARED\n", cfg->ied_name);
        ctx->fault_active = 0;
        return 1;
    }

    if (strcmp(cmd, "reset") == 0) {
        printf("[FAULT %s] Full RESET\n", cfg->ied_name);
        ctx->fault_active = 0;
        ctx->state = ST_IDLE;
        ctx->fault_zone = 0;
        ctx->ar_attempts = 0;
        ctx->i_a = ctx->i_b = ctx->i_c = NOMINAL_I;
        ctx->v_a = ctx->v_b = ctx->v_c = NOMINAL_V;
        ctx->freq = NOMINAL_F;
        ctx->tot_w = 25.0f;
        ctx->tot_var = 8.0f;
        clear_trip(server, model, ctx);
        set_ar_state(server, model, 0, Hal_getTimeInMs());
        return 1;
    }

    if (strncmp(cmd, "help", 4) == 0) {
        printf("P543 Distance Relay commands:\n");
        printf("  inject <type> [zone]  — Inject fault (ph-ph, ph-e, 3ph)\n");
        printf("  clear                 — Clear injected fault\n");
        printf("  reset                 — Full reset to normal\n");
        return 1;
    }

    return 0;
}

/* ============================================================
 *  MAIN — entry point for E05_P543.exe / E06_P543.exe
 * ============================================================ */
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <config.json>\n", argv[0]);
        printf("Example: %s config/E05_P543.json\n", argv[0]);
        return 1;
    }

    P543Context ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.i_a = ctx.i_b = ctx.i_c = NOMINAL_I;
    ctx.v_a = ctx.v_b = ctx.v_c = NOMINAL_V;
    ctx.freq = NOMINAL_F;
    ctx.tot_w = 25.0f;
    ctx.tot_var = 8.0f;

    return ied_server_run(&MODEL_EXTERN, argv[1],
                          p543_tick, p543_command, &ctx);
}
