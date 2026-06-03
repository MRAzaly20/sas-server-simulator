/* ============================================================
 *  ied_p746_busbar.c — MiCOM P746 Busbar Protection
 *  GI 150kV — Station level E00
 *
 *  3 zones (in one CID model with 3 logical devices):
 *    Zone 1 — Busbar section A (E01, E02, E03, E04, E05)
 *    Zone 2 — Busbar section B (E04, E06)
 *    Check Zone — covers both sections (AND gate)
 *
 *  Protection functions per zone:
 *    87B   Busbar differential (sum of bay currents)
 *    50BF  Breaker failure protection
 *    74TC  Trip circuit supervision
 *
 *  GOOSE Publisher:  3 BBTrip datasets (Z1, Z2, CZ)
 *  GOOSE Subscriber: 6 BCU SwitchStatus (for CBF monitoring)
 *
 *  Usage: E00_P746.exe config/E00_P746.json
 * ============================================================ */
#include "ied_server_base.h"
#include "iec61850_server.h"
#include "hal_thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef MODEL_EXTERN
#define MODEL_EXTERN model_E00_P746
#endif
extern IedModel MODEL_EXTERN;

typedef enum {
    BB_IDLE = 0,
    BB_STARTED,
    BB_TRIPPED,
    BB_LOCKOUT,
} BBState;

typedef struct {
    BBState  z1_state;      /* Zone 1 */
    BBState  z2_state;      /* Zone 2 */
    int      z1_fault;
    int      z2_fault;
    uint64_t z1_enter_ms;
    uint64_t z2_enter_ms;

    /* Simulated sum-of-currents per zone */
    float i_diff_z1;
    float i_diff_z2;
} P746Context;

#define BB_DIFF_TRIP_MS 5     /* <25ms typical */
#define BB_DIFF_THRESHOLD 200.0f  /* Differential threshold (A) */

/* ---- Find LD by name pattern ---- */
static LogicalDevice *find_ld(IedModel *m, const char *pattern) {
    LogicalDevice *ld = m->firstChild;
    while (ld) {
        if (strstr(ld->name, pattern)) return ld;
        ld = (LogicalDevice*)((ModelNode*)ld)->sibling;
    }
    return NULL;
}

static void set_bool_ld(IedServer s, IedModel *m, const char *ld_name,
                        const char *ref_suffix, int v)
{
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/%s", ld_name, ref_suffix);
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(m, ref);
    if (da) {
        IedServer_lockDataModel(s);
        IedServer_updateBooleanAttributeValue(s, da, v ? true : false);
        IedServer_unlockDataModel(s);
    }
}

/* ============================================================
 *  PROTECTION TICK
 * ============================================================ */
static void p746_tick(IedServer server, IedModel *model,
                      const IedConfig *cfg, uint64_t now_ms, void *ctx_ptr)
{
    P746Context *ctx = (P746Context *)ctx_ptr;
    (void)cfg;

    /* Find the logical devices for each zone */
    LogicalDevice *ld_z1 = find_ld(model, "Z1");
    LogicalDevice *ld_z2 = find_ld(model, "Z2");
    LogicalDevice *ld_cz = find_ld(model, "CZ");

    /* Use first LD if zone-specific ones not found */
    if (!ld_z1) ld_z1 = model->firstChild;
    const char *z1_name = ld_z1 ? ld_z1->name : "Z1";
    const char *z2_name = ld_z2 ? ld_z2->name : "Z2";
    const char *cz_name = ld_cz ? ld_cz->name : "CZ";

    /* ---- Zone 1 state machine ---- */
    switch (ctx->z1_state) {
    case BB_IDLE:
        break;
    case BB_STARTED:
        if ((int)(now_ms - ctx->z1_enter_ms) >= BB_DIFF_TRIP_MS) {
            set_bool_ld(server, model, z1_name, "PDIF1.Op.general", 1);
            set_bool_ld(server, model, z1_name, "PTRC1.Tr.general", 1);
            /* Check zone AND gate */
            set_bool_ld(server, model, cz_name, "PDIF1.Op.general", 1);

            printf("[PROT %s] Zone 1 87B TRIP (%dms) — tripping E01-E05\n",
                   cfg->ied_name, BB_DIFF_TRIP_MS);
            ctx->z1_state = BB_TRIPPED;
            ctx->z1_enter_ms = now_ms;
        }
        break;
    case BB_TRIPPED:
        printf("[PROT %s] Zone 1 LOCKOUT\n", cfg->ied_name);
        ctx->z1_state = BB_LOCKOUT;
        break;
    case BB_LOCKOUT:
        break;
    }

    /* ---- Zone 2 state machine ---- */
    switch (ctx->z2_state) {
    case BB_IDLE:
        break;
    case BB_STARTED:
        if ((int)(now_ms - ctx->z2_enter_ms) >= BB_DIFF_TRIP_MS) {
            set_bool_ld(server, model, z2_name, "PDIF1.Op.general", 1);
            set_bool_ld(server, model, z2_name, "PTRC1.Tr.general", 1);
            set_bool_ld(server, model, cz_name, "PDIF1.Op.general", 1);

            printf("[PROT %s] Zone 2 87B TRIP (%dms) — tripping E04, E06\n",
                   cfg->ied_name, BB_DIFF_TRIP_MS);
            ctx->z2_state = BB_TRIPPED;
            ctx->z2_enter_ms = now_ms;
        }
        break;
    case BB_TRIPPED:
        printf("[PROT %s] Zone 2 LOCKOUT\n", cfg->ied_name);
        ctx->z2_state = BB_LOCKOUT;
        break;
    case BB_LOCKOUT:
        break;
    }
}

/* ---- Console commands ---- */
static int p746_command(IedServer server, IedModel *model,
                        const IedConfig *cfg, const char *cmd, void *ctx_ptr)
{
    P746Context *ctx = (P746Context *)ctx_ptr;
    (void)server; (void)model;

    if (strcmp(cmd, "inject bb-z1") == 0) {
        if (ctx->z1_state != BB_IDLE) {
            printf("[PROT %s] Zone 1 already active\n", cfg->ied_name);
            return 1;
        }
        printf("\n[FAULT %s] Busbar Zone 1 fault injected\n\n", cfg->ied_name);
        ctx->z1_fault = 1;
        ctx->z1_state = BB_STARTED;
        ctx->z1_enter_ms = Hal_getTimeInMs();
        ctx->i_diff_z1 = 8000.0f;
        return 1;
    }
    if (strcmp(cmd, "inject bb-z2") == 0) {
        if (ctx->z2_state != BB_IDLE) {
            printf("[PROT %s] Zone 2 already active\n", cfg->ied_name);
            return 1;
        }
        printf("\n[FAULT %s] Busbar Zone 2 fault injected\n\n", cfg->ied_name);
        ctx->z2_fault = 1;
        ctx->z2_state = BB_STARTED;
        ctx->z2_enter_ms = Hal_getTimeInMs();
        ctx->i_diff_z2 = 8000.0f;
        return 1;
    }
    if (strcmp(cmd, "reset") == 0) {
        printf("[PROT %s] Full RESET — all zones\n", cfg->ied_name);
        ctx->z1_fault = ctx->z2_fault = 0;
        ctx->z1_state = ctx->z2_state = BB_IDLE;
        ctx->i_diff_z1 = ctx->i_diff_z2 = 0;

        LogicalDevice *ld = model->firstChild;
        while (ld) {
            set_bool_ld(server, model, ld->name, "PDIF1.Op.general", 0);
            set_bool_ld(server, model, ld->name, "PTRC1.Tr.general", 0);
            ld = (LogicalDevice*)((ModelNode*)ld)->sibling;
        }
        return 1;
    }
    if (strncmp(cmd, "help", 4) == 0) {
        printf("P746 Busbar Protection commands:\n");
        printf("  inject bb-z1  — Busbar Zone 1 fault\n");
        printf("  inject bb-z2  — Busbar Zone 2 fault\n");
        printf("  reset         — Full reset all zones\n");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) { printf("Usage: %s <config.json>\n", argv[0]); return 1; }
    P746Context ctx;
    memset(&ctx, 0, sizeof(ctx));
    return ied_server_run(&MODEL_EXTERN, argv[1], p746_tick, p746_command, &ctx);
}
