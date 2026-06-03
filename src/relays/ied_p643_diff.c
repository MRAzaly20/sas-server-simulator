/* ============================================================
 *  ied_p643_diff.c — MiCOM P643 Transformer Differential
 *  GI 150kV A — Transformer bays E01, E02, E03
 *
 *  Protection functions:
 *    87T   Biased differential (HV vs LV winding)
 *    87REF Restricted earth fault
 *    24    Overfluxing (V/Hz)
 *    49    Thermal overload
 *    46    Negative phase sequence
 *    PTRC1 Trip relay
 *    MMXU1 Measurements
 *
 *  No auto-reclose — transformer faults → immediate lockout
 *
 *  Usage: E01_P643.exe config/E01_P643.json
 * ============================================================ */
#include "ied_server_base.h"
#include "iec61850_server.h"
#include "hal_thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef MODEL_EXTERN
#define MODEL_EXTERN model_E01_P643
#endif
extern IedModel MODEL_EXTERN;

typedef enum {
    DIFF_IDLE = 0,
    DIFF_STARTED,
    DIFF_TRIPPED,
    DIFF_LOCKOUT,
} DiffState;

typedef struct {
    DiffState state;
    int       fault_active;
    uint64_t  state_enter_ms;

    /* Simulated winding currents */
    float i_hv_a, i_hv_b, i_hv_c;  /* HV side */
    float i_lv_a, i_lv_b, i_lv_c;  /* LV side */
    float v_a, v_b, v_c;
    float freq;
} P643Context;

#define NOMINAL_V   86.6f
#define NOMINAL_I   200.0f
#define NOMINAL_F   50.0f
#define DIFF_TRIP_MS 10    /* <25ms for 87T */

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

/* ---- Differential current check ---- */
static float calc_diff_current(P643Context *ctx) {
    float diff_a = fabsf(ctx->i_hv_a - ctx->i_lv_a);
    float diff_b = fabsf(ctx->i_hv_b - ctx->i_lv_b);
    float diff_c = fabsf(ctx->i_hv_c - ctx->i_lv_c);
    return (diff_a > diff_b) ? (diff_a > diff_c ? diff_a : diff_c)
                             : (diff_b > diff_c ? diff_b : diff_c);
}

/* ============================================================
 *  PROTECTION TICK
 * ============================================================ */
static void p643_tick(IedServer server, IedModel *model,
                      const IedConfig *cfg, uint64_t now_ms, void *ctx_ptr)
{
    P643Context *ctx = (P643Context *)ctx_ptr;
    uint64_t elapsed = now_ms - ctx->state_enter_ms;
    const char *ld = get_ld(model);
    char ref[128];

    /* Normal analog noise */
    if (ctx->state == DIFF_IDLE && !ctx->fault_active) {
        float noise = (float)(rand() % 100 - 50) / 1000.0f;
        ctx->i_hv_a = NOMINAL_I + noise * 5;
        ctx->i_hv_b = NOMINAL_I - noise * 3;
        ctx->i_hv_c = NOMINAL_I + noise * 2;
        /* LV side should match HV (ratio-corrected) in normal state */
        ctx->i_lv_a = ctx->i_hv_a + noise * 0.1f;
        ctx->i_lv_b = ctx->i_hv_b - noise * 0.1f;
        ctx->i_lv_c = ctx->i_hv_c + noise * 0.05f;
        ctx->v_a = NOMINAL_V + noise;
        ctx->freq = NOMINAL_F + noise * 0.01f;
    }

    /* ---- Update MMXU analogs (3-phase WYE CDC) ---- */
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsA.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->i_hv_a);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsB.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->i_hv_b);
    snprintf(ref, sizeof(ref), "%s/MMXU1.A.phsC.cVal.mag.f", ld);
    set_float(server, model, ref, ctx->i_hv_c);
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
    case DIFF_IDLE:
        break;

    case DIFF_STARTED: {
        float idiff = calc_diff_current(ctx);
        if (idiff > cfg->prot.diff_threshold * NOMINAL_I &&
            (int)elapsed >= DIFF_TRIP_MS)
        {
            /* 87T TRIP */
            snprintf(ref, sizeof(ref), "%s/PDIF1.Op.general", ld);
            set_bool(server, model, ref, 1);
            snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.general", ld);
            set_bool(server, model, ref, 1);

            printf("[PROT %s] 87T DIFFERENTIAL TRIP (%dms)\n",
                   cfg->ied_name, DIFF_TRIP_MS);
            ctx->state = DIFF_TRIPPED;
            ctx->state_enter_ms = now_ms;
        }
        break;
    }

    case DIFF_TRIPPED:
        /* Transformer faults → always lockout, never auto-reclose */
        printf("[PROT %s] LOCKOUT — transformer fault, no auto-reclose\n",
               cfg->ied_name);
        ctx->state = DIFF_LOCKOUT;
        break;

    case DIFF_LOCKOUT:
        break;
    }
}

/* ---- Console commands ---- */
static int p643_command(IedServer server, IedModel *model,
                        const IedConfig *cfg, const char *cmd, void *ctx_ptr)
{
    P643Context *ctx = (P643Context *)ctx_ptr;
    (void)server; (void)model;

    if (strncmp(cmd, "inject ", 7) == 0) {
        if (ctx->state != DIFF_IDLE) {
            printf("[PROT %s] Already active\n", cfg->ied_name);
            return 1;
        }
        char type[32] = {0};
        sscanf(cmd + 7, "%31s", type);

        printf("\n[FAULT %s] Injecting %s fault\n\n", cfg->ied_name, type);
        ctx->fault_active = 1;
        ctx->state = DIFF_STARTED;
        ctx->state_enter_ms = Hal_getTimeInMs();

        if (strcmp(type, "87T") == 0 || strcmp(type, "diff") == 0) {
            /* Internal winding fault: HV current spikes, LV stays normal */
            ctx->i_hv_a = 5000.0f;
            ctx->i_lv_a = NOMINAL_I;
            printf("[PROT %s] 87T Differential START\n", cfg->ied_name);
        } else if (strcmp(type, "87REF") == 0 || strcmp(type, "ref") == 0) {
            ctx->i_hv_a = 2000.0f;
            ctx->i_lv_a = NOMINAL_I;
            printf("[PROT %s] 87REF Restricted Earth Fault START\n", cfg->ied_name);
        }
        return 1;
    }
    if (strcmp(cmd, "reset") == 0) {
        printf("[PROT %s] Full RESET\n", cfg->ied_name);
        ctx->fault_active = 0;
        ctx->state = DIFF_IDLE;
        ctx->i_hv_a = ctx->i_hv_b = ctx->i_hv_c = NOMINAL_I;
        ctx->i_lv_a = ctx->i_lv_b = ctx->i_lv_c = NOMINAL_I;
        const char *ld = get_ld(model);
        char ref[128];
        snprintf(ref, sizeof(ref), "%s/PDIF1.Op.general", ld);
        set_bool(server, model, ref, 0);
        snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.general", ld);
        set_bool(server, model, ref, 0);
        return 1;
    }
    if (strncmp(cmd, "help", 4) == 0) {
        printf("P643 Differential Relay commands:\n");
        printf("  inject 87T    — Inject transformer differential fault\n");
        printf("  inject 87REF  — Inject restricted earth fault\n");
        printf("  reset         — Full reset to normal\n");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) { printf("Usage: %s <config.json>\n", argv[0]); return 1; }
    P643Context ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.i_hv_a = ctx.i_hv_b = ctx.i_hv_c = NOMINAL_I;
    ctx.i_lv_a = ctx.i_lv_b = ctx.i_lv_c = NOMINAL_I;
    ctx.v_a = ctx.v_b = ctx.v_c = NOMINAL_V;
    ctx.freq = NOMINAL_F;
    return ied_server_run(&MODEL_EXTERN, argv[1], p643_tick, p643_command, &ctx);
}
