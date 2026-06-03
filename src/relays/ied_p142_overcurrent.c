/* ============================================================
 *  ied_p142_overcurrent.c — MiCOM P142/P143 Overcurrent Relay
 *  GI 150kV — All bays backup protection
 *
 *  Protection functions:
 *    50   Instantaneous phase overcurrent
 *    51   Time overcurrent (IDMT/definite)
 *    50N  Instantaneous earth fault
 *    51N  Time earth fault
 *    46   Negative sequence overcurrent
 *    PTRC1 Trip relay
 *
 *  Usage: E01_P142.exe config/E01_P142.json
 * ============================================================ */
#include "ied_server_base.h"
#include "iec61850_server.h"
#include "hal_thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef MODEL_EXTERN
#define MODEL_EXTERN model_E01_P142
#endif
extern IedModel MODEL_EXTERN;

typedef enum {
    OC_IDLE = 0,
    OC_PICKUP,           /* Overcurrent detected, timing */
    OC_TRIPPED,
    OC_LOCKOUT,
} OCState;

typedef struct {
    OCState  state;
    int      fault_active;
    int      fault_stage;      /* 1=50 instant, 2=51 IDMT */
    uint64_t state_enter_ms;

    float i_a, i_b, i_c;
    float v_a, v_b, v_c;
    float freq;
} P142Context;

#define NOMINAL_V   86.6f
#define NOMINAL_I   200.0f
#define NOMINAL_F   50.0f
#define INST_TRIP_MS  0       /* 50 — instantaneous */
#define IDMT_BASE_MS  500     /* 51 — base time at TMS=1.0, I=2xIpickup */

static const char *get_ld(IedModel *m) {
    return m->firstChild ? m->firstChild->name : "UNKNOWN";
}

static void set_bool(IedServer s, IedModel *m, const char *ref, int v) {
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(m, ref);
    if (da) {
        IedServer_lockDataModel(s);
        IedServer_updateBooleanAttributeValue(s, da, v ? true : false);
        IedServer_unlockDataModel(s);
    }
}

static void set_float(IedServer s, IedModel *m, const char *ref, float v) {
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(m, ref);
    if (da) {
        IedServer_lockDataModel(s);
        IedServer_updateFloatAttributeValue(s, da, v);
        IedServer_unlockDataModel(s);
    }
}

/* ---- IDMT operating time (IEC standard inverse) ----
 * T = TMS * 0.14 / ((I/Is)^0.02 - 1)
 * Simplified for simulation */
static int calc_idmt_time_ms(float i_fault, float i_pickup, float tms) {
    if (i_fault <= i_pickup) return 99999;
    float ratio = i_fault / i_pickup;
    float t = tms * 0.14f / (powf(ratio, 0.02f) - 1.0f);
    return (int)(t * 1000.0f);
}

/* ============================================================
 *  PROTECTION TICK
 * ============================================================ */
static void p142_tick(IedServer server, IedModel *model,
                      const IedConfig *cfg, uint64_t now_ms, void *ctx_ptr)
{
    P142Context *ctx = (P142Context *)ctx_ptr;
    uint64_t elapsed = now_ms - ctx->state_enter_ms;
    const char *ld = get_ld(model);
    char ref[128];

    /* Normal analog noise */
    if (ctx->state == OC_IDLE && !ctx->fault_active) {
        float noise = (float)(rand() % 100 - 50) / 1000.0f;
        ctx->i_a = NOMINAL_I + noise * 10;
        ctx->i_b = NOMINAL_I - noise * 5;
        ctx->i_c = NOMINAL_I + noise * 3;
        ctx->v_a = NOMINAL_V + noise;
        ctx->freq = NOMINAL_F + noise * 0.01f;
    }

    /* ---- Update MMXU analogs (3-phase WYE CDC) ---- */
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsA.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->i_a);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsB.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->i_b);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsC.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->i_c);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsA.cVal.ang.f", ld);
    set_float(server, model, ref, 0.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsB.cVal.ang.f", ld);
    set_float(server, model, ref, -120.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsC.cVal.ang.f", ld);
    set_float(server, model, ref, 120.0f);

    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsA.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->v_a);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsB.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->v_b);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsC.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->v_c);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsA.cVal.ang.f", ld);
    set_float(server, model, ref, 0.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsB.cVal.ang.f", ld);
    set_float(server, model, ref, -120.0f);
    snprintf(ref, sizeof(ref), "%s/MMXU1.PhV.phsC.cVal.ang.f", ld);
    set_float(server, model, ref, 120.0f);

    snprintf(ref, sizeof(ref), "%s/MMXU1.Hz.mag.f", ld);
    set_float(server, model, ref, ctx->freq);

    switch (ctx->state) {
    case OC_IDLE: {
        /* Calculate residual current (3I0) approximation assuming 0, -120, +120 angles */
        float i_re = ctx->i_a - 0.5f * ctx->i_b - 0.5f * ctx->i_c;
        float i_im = 0.866025f * (ctx->i_c - ctx->i_b);
        float i_res = sqrtf(i_re * i_re + i_im * i_im);
        float i_pickup_n = cfg->prot.i_pickup_a * 0.2f; /* Earth fault at 20% of phase pickup */

        /* Check Earth Fault 50N / 51N first */
        if (i_res > i_pickup_n) {
            if (i_res > i_pickup_n * 10.0f) {
                printf("[PROT %s] PTOC1 50N INSTANTANEOUS EF PICKUP (%.0fA)\n", cfg->ied_name, i_res);
                ctx->fault_stage = 3;
            } else {
                printf("[PROT %s] PTOC1 51N IDMT EF PICKUP (%.0fA > %.0fA)\n", cfg->ied_name, i_res, i_pickup_n);
                ctx->fault_stage = 4;
            }
            ctx->state = OC_PICKUP;
            ctx->state_enter_ms = now_ms;
        } 
        /* Autonomous monitoring: check if phase current exceeds pickup */
        else if (ctx->i_a > cfg->prot.i_pickup_a ||
                 ctx->i_b > cfg->prot.i_pickup_a ||
                 ctx->i_c > cfg->prot.i_pickup_a)
        {
            float max_i = ctx->i_a > ctx->i_b ?
                         (ctx->i_a > ctx->i_c ? ctx->i_a : ctx->i_c) :
                         (ctx->i_b > ctx->i_c ? ctx->i_b : ctx->i_c);

            /* Check 50 (instantaneous) threshold: 10x pickup */
            if (max_i > cfg->prot.i_pickup_a * 10.0f) {
                printf("[PROT %s] PTOC1 50 INSTANTANEOUS PICKUP (%.0fA)\n",
                       cfg->ied_name, max_i);
                ctx->fault_stage = 1;
            } else {
                printf("[PROT %s] PTOC1 51 IDMT PICKUP (%.0fA > %.0fA)\n",
                       cfg->ied_name, max_i, cfg->prot.i_pickup_a);
                ctx->fault_stage = 2;
            }
            ctx->state = OC_PICKUP;
            ctx->state_enter_ms = now_ms;
        }
        break;
    }

    case OC_PICKUP: {
        int trip_time;
        if (ctx->fault_stage == 1 || ctx->fault_stage == 3) {
            trip_time = INST_TRIP_MS;
        } else {
            float max_i;
            if (ctx->fault_stage == 4) {
                float i_re = ctx->i_a - 0.5f * ctx->i_b - 0.5f * ctx->i_c;
                float i_im = 0.866025f * (ctx->i_c - ctx->i_b);
                max_i = sqrtf(i_re * i_re + i_im * i_im);
            } else {
                max_i = ctx->i_a > ctx->i_b ?
                             (ctx->i_a > ctx->i_c ? ctx->i_a : ctx->i_c) :
                             (ctx->i_b > ctx->i_c ? ctx->i_b : ctx->i_c);
            }
            float pickup = (ctx->fault_stage == 4) ? cfg->prot.i_pickup_a * 0.2f : cfg->prot.i_pickup_a;
            trip_time = calc_idmt_time_ms(max_i, pickup, cfg->prot.time_dial);
        }

        if ((int)elapsed >= trip_time) {
            snprintf(ref, sizeof(ref), "%s/PTOC1.Op.general", ld);
            set_bool(server, model, ref, 1);
            snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.general", ld);
            set_bool(server, model, ref, 1);

            const char *trip_type = "51 IDMT";
            if (ctx->fault_stage == 1) trip_type = "50 INSTANTANEOUS";
            else if (ctx->fault_stage == 3) trip_type = "50N INSTANTANEOUS EF";
            else if (ctx->fault_stage == 4) trip_type = "51N IDMT EF";

            printf("[PROT %s] PTOC1 %s TRIP (after %dms)\n",
                   cfg->ied_name, trip_type, trip_time);
            ctx->i_a = ctx->i_b = ctx->i_c = 0;
            ctx->state = OC_TRIPPED;
            ctx->state_enter_ms = now_ms;
        }
        break;
    }

    case OC_TRIPPED:
        printf("[PROT %s] LOCKOUT — backup overcurrent\n", cfg->ied_name);
        ctx->state = OC_LOCKOUT;
        break;

    case OC_LOCKOUT:
        break;
    }
}

/* ---- Console commands ---- */
static int p142_command(IedServer server, IedModel *model,
                        const IedConfig *cfg, const char *cmd, void *ctx_ptr)
{
    P142Context *ctx = (P142Context *)ctx_ptr;
    (void)server; (void)model;

    if (strncmp(cmd, "inject ", 7) == 0) {
        if (ctx->state != OC_IDLE) {
            printf("[PROT %s] Already active\n", cfg->ied_name);
            return 1;
        }
        float current = 0;
        int is_earth = 0;
        const char *arg = cmd + 7;
        
        if (strncmp(arg, "earth ", 6) == 0) {
            is_earth = 1;
            arg += 6;
        } else if (strncmp(arg, "phase ", 6) == 0) {
            arg += 6;
        }
        
        sscanf(arg, "%f", &current);
        if (current <= 0) current = 5000.0f;

        printf("\n[FAULT %s] Injecting %.0fA %s fault\n\n",
               cfg->ied_name, current, is_earth ? "Earth (50N/51N)" : "Phase (50/51)");
        ctx->fault_active = 1;
        ctx->i_a = current;
        if (is_earth) {
            ctx->i_b = 0.0f;  /* Single Line to Ground */
            ctx->i_c = 0.0f;
        } else {
            /* Balanced 3-phase fault to prevent zero-sequence/residual current */
            ctx->i_b = current;
            ctx->i_c = current;
        }
        return 1;
    }
    if (strcmp(cmd, "reset") == 0) {
        printf("[PROT %s] Full RESET\n", cfg->ied_name);
        ctx->fault_active = 0;
        ctx->state = OC_IDLE;
        ctx->i_a = ctx->i_b = ctx->i_c = NOMINAL_I;
        const char *ld = get_ld(model);
        char ref[128];
        snprintf(ref, sizeof(ref), "%s/PTOC1.Op.general", ld);
        set_bool(server, model, ref, 0);
        snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.general", ld);
        set_bool(server, model, ref, 0);
        return 1;
    }
    if (strncmp(cmd, "help", 4) == 0) {
        printf("P142/P143 Overcurrent commands:\n");
        printf("  inject [amps]        — Inject overcurrent phase fault (default 5000A)\n");
        printf("  inject earth [amps]  — Inject single line to ground fault\n");
        printf("  reset                — Full reset\n");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) { printf("Usage: %s <config.json>\n", argv[0]); return 1; }
    P142Context ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.i_a = ctx.i_b = ctx.i_c = NOMINAL_I;
    ctx.v_a = ctx.v_b = ctx.v_c = NOMINAL_V;
    ctx.freq = NOMINAL_F;
    return ied_server_run(&MODEL_EXTERN, argv[1], p142_tick, p142_command, &ctx);
}
