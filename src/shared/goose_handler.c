/* ============================================================
 *  goose_handler.c — Per-IED GOOSE subscriber logic
 *  Registers subscriptions from JSON config and dispatches
 *  actions (intertrip, CB status, etc.) on the local IedServer.
 * ============================================================ */
#include "goose_handler.h"
#include <stdio.h>
#include <string.h>

/* ---- Context passed to each subscriber callback ---- */
typedef struct {
    IedServer      server;
    IedModel      *model;
    const char    *ied_name;
    GooseSubEntry  entry;    /* copy of the subscription config */
    int            last_trip_state;
    ConsoleCommandFn cmd_fn;
    void          *ctx_ptr;
} GooseSubCtx;

/* Max number of concurrent contexts */
#define MAX_CTX 16
static GooseSubCtx g_ctx_pool[MAX_CTX];
static int g_ctx_count = 0;

/* ---- Helper: open the local CB on intertrip ---- */
static void action_intertrip_open_cb(GooseSubCtx *ctx, MmsValue *values) {
    if (!values) return;

    /* The incoming dataset is BBTrip: [0]=PDIF1.Op.general or PTRC1.Tr.general */
    MmsValue *trip_val = MmsValue_getElement(values, 0);
    if (!trip_val) return;

    bool tripped = MmsValue_getBoolean(trip_val);
    
    if (tripped == ctx->last_trip_state) return;
    ctx->last_trip_state = tripped;
    
    if (ctx->cmd_fn) {
        ctx->cmd_fn(ctx->server, ctx->model, NULL, 
                    tripped ? "external_trip_set" : "external_trip_clear", 
                    ctx->ctx_ptr);
    }
    
    if (!tripped) return;

    printf("[GOOSE RX] %s: Intertrip received from %s — opening CB\n",
           ctx->ied_name, ctx->entry.gocbRef);

    /* Find XCBR1.Pos.stVal in local model and set to OPEN (Dbpos=1) */
    /* Search all LDs for XCBR1 */
    LogicalDevice *ld = ctx->model->firstChild;
    while (ld) {
        char ref[128];
        snprintf(ref, sizeof(ref), "%s/XCBR1.Pos.stVal", ld->name);
        DataAttribute *da = (DataAttribute*)
            IedModel_getModelNodeByShortObjectReference(ctx->model, ref);
        if (da) {
            IedServer_lockDataModel(ctx->server);
            IedServer_updateDbposValue(ctx->server, da, 1); /* OPEN */
            IedServer_unlockDataModel(ctx->server);
            printf("[GOOSE RX] %s: %s/XCBR1.Pos -> OPEN\n",
                   ctx->ied_name, ld->name);
            break;
        }
        ld = (LogicalDevice*)((ModelNode*)ld)->sibling;
    }
}

/* ---- Helper: log incoming CB status ---- */
static void action_log_cb_status(GooseSubCtx *ctx, MmsValue *values) {
    if (!values) return;
    MmsValue *pos = MmsValue_getElement(values, 0);
    if (!pos) return;
    int dbpos = MmsValue_toInt32(pos);
    const char *str = (dbpos == 1) ? "OPEN" :
                      (dbpos == 2) ? "CLOSED" : "INTERMEDIATE";
    printf("[GOOSE RX] %s: CB status from %s = %s\n",
           ctx->ied_name, ctx->entry.gocbRef, str);
}

/* ---- Helper: read E04 CouplerReady status ---- */
static void action_coupler_status(GooseSubCtx *ctx, MmsValue *values) {
    if (!values) return;
    
    /* E04 SwitchStatus dataset has CouplerReady (GGIO1.Ind1.stVal) at index 5 */
    if (MmsValue_getArraySize(values) <= 5) return;
    MmsValue *ready_val = MmsValue_getElement(values, 5);
    if (!ready_val) return;
    
    bool is_ready = MmsValue_getBoolean(ready_val);
    if (ctx->cmd_fn) {
        ctx->cmd_fn(ctx->server, ctx->model, NULL,
                    is_ready ? "coupler_ready_set" : "coupler_ready_clear",
                    ctx->ctx_ptr);
    }
}

/* ---- Main GOOSE listener callback ---- */
static void goose_listener(GooseSubscriber sub, void *param) {
    GooseSubCtx *ctx = (GooseSubCtx *)param;

    if (!GooseSubscriber_isValid(sub)) return;

    MmsValue *values = GooseSubscriber_getDataSetValues(sub);

    /* Dispatch by action string */
    int matched = 0;
    if (strcmp(ctx->entry.action, "intertrip_open_cb") == 0) {
        matched = 1;
        action_intertrip_open_cb(ctx, values);
    } else if (strcmp(ctx->entry.action, "log_cb_status") == 0) {
        matched = 1;
        action_log_cb_status(ctx, values);
    } else if (strcmp(ctx->entry.action, "coupler_status") == 0) {
        matched = 1;
        action_coupler_status(ctx, values);
    } else {
        printf("[GOOSE RX] %s: Unhandled action '%s' for %s\n",
               ctx->ied_name, ctx->entry.action, ctx->entry.gocbRef);
    }

    if (!matched) {
        printf("[GOOSE RX DEBUG] %s: Packet received but action unmatched (goCbRef: %s)\n", ctx->ied_name, ctx->entry.gocbRef);
    }
}

/* ---- Initialize ---- */
GooseReceiver goose_handler_init(const IedConfig *cfg,
                                 IedServer server,
                                 IedModel *model,
                                 ConsoleCommandFn cmd_fn,
                                 void *ctx_ptr)
{
    if (cfg->num_goose_subs == 0) return NULL;

    GooseReceiver receiver = GooseReceiver_create();
    if (cfg->goose_interface[0] != '\0')
        GooseReceiver_setInterfaceId(receiver, cfg->goose_interface);

    printf("[GOOSE] Registering %d subscriptions for %s:\n",
           cfg->num_goose_subs, cfg->ied_name);

    for (int i = 0; i < cfg->num_goose_subs && g_ctx_count < MAX_CTX; i++) {
        GooseSubCtx *ctx = &g_ctx_pool[g_ctx_count++];
        ctx->server   = server;
        ctx->model    = model;
        ctx->ied_name = cfg->ied_name;
        ctx->entry    = cfg->goose_subs[i];
        ctx->cmd_fn   = cmd_fn;
        ctx->ctx_ptr  = ctx_ptr;

        GooseSubscriber sub = GooseSubscriber_create(
            (char*)cfg->goose_subs[i].gocbRef, NULL);
        GooseSubscriber_setAppId(sub, cfg->goose_subs[i].appId);
        GooseSubscriber_setListener(sub, goose_listener, ctx);
        GooseReceiver_addSubscriber(receiver, sub);

        printf("  [%d] GoCbRef=%s AppID=%d action=%s\n",
               i, cfg->goose_subs[i].gocbRef,
               cfg->goose_subs[i].appId, cfg->goose_subs[i].action);
    }

    GooseReceiver_start(receiver);
    printf("[GOOSE] Receiver %s (%s)\n",
           GooseReceiver_isRunning(receiver) ? "started" : "FAILED",
           cfg->ied_name);

    return receiver;
}

/* ---- Cleanup ---- */
void goose_handler_cleanup(GooseReceiver receiver) {
    if (receiver) {
        GooseReceiver_stop(receiver);
        GooseReceiver_destroy(receiver);
    }
    g_ctx_count = 0;
}
