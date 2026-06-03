/* ============================================================
 *  goose_matrix.c — GOOSE Subscriber Matrix implementation
 *  GI 150kV ANTAM POMALAA — Complete inter-IED GOOSE wiring
 *
 *  Subscriber matrix (source → action):
 *
 *  E00_P746 Zone 1 BBTrip  → OPEN XCBR on E01, E02, E03, E04, E05
 *  E00_P746 Zone 2 BBTrip  → OPEN XCBR on E04, E06
 *  E00_P746 Check Zone     → Log (AND-gate with zone trip, informational)
 *  E01–E06 BCU SwitchStatus → Log CB state change (observability)
 *
 *  All GoCbRef strings derived directly from CID files.
 * ============================================================ */
#include "goose_matrix.h"
#include <stdio.h>
#include <string.h>

/* ---- Module-level references ---- */
static FaultEngine *g_eng = NULL;
static IedManager  *g_mgr = NULL;

/* ---- Helper: open breaker on a BCU IED model ---- */
static void open_breaker_on_bcu(const char *ied_name, const char *ld_inst) {
    if (!g_mgr) return;

    IedInstance *inst = ied_manager_find(g_mgr, ied_name);
    if (!inst || !inst->server) {
        printf("[GOOSE RX] WARNING: IED '%s' not found for intertrip\n", ied_name);
        return;
    }

    /* Build the XCBR1.Pos.stVal reference */
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/XCBR1.Pos.stVal", ld_inst);

    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(inst->model, ref);

    if (da) {
        IedServer_lockDataModel(inst->server);
        /* Dbpos: 1 = OPEN */
        IedServer_updateDbposValue(inst->server, da, 1);
        IedServer_unlockDataModel(inst->server);
        printf("[GOOSE RX] %-10s XCBR1.Pos → OPEN (intertrip)\n", ied_name);
    } else {
        printf("[GOOSE RX] WARNING: DA not found: %s on IED %s\n", ref, ied_name);
    }
}

/* ---- Handler: Busbar Zone 1 trip from E00_P746 ----
 *  Dataset BBTrip: [0] PDIF1.Op.general, [1] RBRF1.OpEx.general
 *  Zone 1 connected: E01, E02, E03, E04, E05                    */
static void handle_bb_zone1(MmsValue *values) {
    if (!values) return;

    bool pdif_op  = MmsValue_getBoolean(MmsValue_getElement(values, 0));
    bool rbrf_op  = MmsValue_getBoolean(MmsValue_getElement(values, 1));

    printf("[GOOSE RX] E00_P746 Zone1: PDIF1.Op=%d  RBRF1.OpEx=%d\n",
           pdif_op, rbrf_op);

    if (pdif_op) {
        printf("[GOOSE RX] ══════ BUSBAR ZONE 1 TRIP — Intertripping E01,E02,E03,E04,E05 ══════\n");
        open_breaker_on_bcu("E01_BCU", "E01BCU");
        open_breaker_on_bcu("E02_BCU", "E02BCU");
        open_breaker_on_bcu("E03_BCU", "E03BCU");
        open_breaker_on_bcu("E04_BCU", "E04BCU");
        open_breaker_on_bcu("E05_BCU", "E05BCU");
    }
}

/* ---- Handler: Busbar Zone 2 trip from E00_P746 ----
 *  Dataset BBTrip: [0] PDIF1.Op.general, [1] RBRF1.OpEx.general
 *  Zone 2 connected: E04, E06                                   */
static void handle_bb_zone2(MmsValue *values) {
    if (!values) return;

    bool pdif_op = MmsValue_getBoolean(MmsValue_getElement(values, 0));
    bool rbrf_op = MmsValue_getBoolean(MmsValue_getElement(values, 1));

    printf("[GOOSE RX] E00_P746 Zone2: PDIF1.Op=%d  RBRF1.OpEx=%d\n",
           pdif_op, rbrf_op);

    if (pdif_op) {
        printf("[GOOSE RX] ══════ BUSBAR ZONE 2 TRIP — Intertripping E04,E06 ══════\n");
        open_breaker_on_bcu("E04_BCU", "E04BCU");
        open_breaker_on_bcu("E06_BCU", "E06BCU");
    }
}

/* ---- Handler: Busbar Check Zone from E00_P746 ----
 *  Informational — check zone confirms busbar fault validity    */
static void handle_bb_checkzone(MmsValue *values) {
    if (!values) return;
    bool pdif_op = MmsValue_getBoolean(MmsValue_getElement(values, 0));
    printf("[GOOSE RX] E00_P746 CheckZone: PDIF1.Op=%d (and-gate confirm)\n", pdif_op);
}

/* ---- Handler: BCU SwitchStatus (CB / disconnector positions) ----
 *  Dataset: [0] XCBR1.Pos.stVal (Dbpos), [1] XCBR1.Pos.q, [2] CSWI1.Pos.stVal
 *  Observability — logs CB state changes to console             */
static void handle_bcu_switch(const char *ied_name, MmsValue *values) {
    if (!values) return;

    /* Dbpos enum: 0=intermediate, 1=OPEN, 2=CLOSED, 3=bad-state */
    MmsValue *xcbr_pos = MmsValue_getElement(values, 0);
    int dbpos = MmsValue_toInt32(xcbr_pos);

    const char *pos_str = "INTERMEDIATE";
    if (dbpos == 1) pos_str = "OPEN";
    else if (dbpos == 2) pos_str = "CLOSED";
    else if (dbpos == 3) pos_str = "BAD-STATE";

    printf("[GOOSE RX] %-10s XCBR1.Pos = %s (dbpos=%d)\n",
           ied_name, pos_str, dbpos);
}

/* ---- Primary GOOSE listener — dispatches to handlers ---- */
static void gooseListener(GooseSubscriber subscriber, void *parameter) {
    (void)parameter;

    const char *goCbRef = GooseSubscriber_getGoCbRef(subscriber);

    if (!GooseSubscriber_isValid(subscriber)) {
        /* Could be stNum=0 heartbeat or invalid frame */
        printf("[GOOSE RX] Invalid/heartbeat from: %s\n", goCbRef);
        return;
    }

    MmsValue *values = GooseSubscriber_getDataSetValues(subscriber);

    /* ================================================================
     * Busbar protection (E00_P746) — Safety-critical intertrip paths
     * ================================================================ */

    /* Zone 1: E00_P746/E00P746Z1/LLN0$GO$gcbE00P746Z1 */
    if (strcmp(goCbRef, "E00_P746E00P746Z1/LLN0$GO$gcbE00P746Z1") == 0) {
        handle_bb_zone1(values);
        return;
    }
    /* Zone 2: E00_P746/E00P746Z2/LLN0$GO$gcbE00P746Z2 */
    if (strcmp(goCbRef, "E00_P746E00P746Z2/LLN0$GO$gcbE00P746Z2") == 0) {
        handle_bb_zone2(values);
        return;
    }
    /* Check Zone: E00_P746/E00P746CZ/LLN0$GO$gcbE00P746CZ */
    if (strcmp(goCbRef, "E00_P746E00P746CZ/LLN0$GO$gcbE00P746CZ") == 0) {
        handle_bb_checkzone(values);
        return;
    }

    /* ================================================================
     * BCU Switch Status — CB/disconnector position observability
     * ================================================================ */
    if (strcmp(goCbRef, "E01_BCUE01BCU/LLN0$GO$gcbE01BCU") == 0) {
        handle_bcu_switch("E01_BCU", values); return;
    }
    if (strcmp(goCbRef, "E02_BCUE02BCU/LLN0$GO$gcbE02BCU") == 0) {
        handle_bcu_switch("E02_BCU", values); return;
    }
    if (strcmp(goCbRef, "E03_BCUE03BCU/LLN0$GO$gcbE03BCU") == 0) {
        handle_bcu_switch("E03_BCU", values); return;
    }
    if (strcmp(goCbRef, "E04_BCUE04BCU/LLN0$GO$gcbE04BCU") == 0) {
        handle_bcu_switch("E04_BCU", values); return;
    }
    if (strcmp(goCbRef, "E05_BCUE05BCU/LLN0$GO$gcbE05BCU") == 0) {
        handle_bcu_switch("E05_BCU", values); return;
    }
    if (strcmp(goCbRef, "E06_BCUE06BCU/LLN0$GO$gcbE06BCU") == 0) {
        handle_bcu_switch("E06_BCU", values); return;
    }

    /* Unknown GOOSE — log it */
    printf("[GOOSE RX] Unhandled GoCbRef: %s\n", goCbRef);
}

/* ---- Register all subscriptions ---- */
void goose_matrix_init(GooseReceiver receiver,
                       FaultEngine  *eng,
                       IedManager   *mgr)
{
    g_eng = eng;
    g_mgr = mgr;

    printf("[GOOSE INIT] Registering GOOSE Subscribers...\n");

    /* ---- Busbar Zone 1 — E00_P746 / E00P746Z1 / AppID=4097 ----
     * NOTE: AppID 4097 is shared with BCU GoCBs; GoCbRef is the discriminator. */
    GooseSubscriber subBBZ1 = GooseSubscriber_create(
        "E00_P746E00P746Z1/LLN0$GO$gcbE00P746Z1", NULL);
    GooseSubscriber_setAppId(subBBZ1, 4097);
    GooseSubscriber_setListener(subBBZ1, gooseListener, NULL);
    GooseReceiver_addSubscriber(receiver, subBBZ1);
    printf("[GOOSE INIT]  + E00_P746 Zone1  (AppID=4097, GoCB=gcbE00P746Z1)\n");

    /* ---- Busbar Zone 2 — E00_P746 / E00P746Z2 / AppID=4098 ---- */
    GooseSubscriber subBBZ2 = GooseSubscriber_create(
        "E00_P746E00P746Z2/LLN0$GO$gcbE00P746Z2", NULL);
    GooseSubscriber_setAppId(subBBZ2, 4098);
    GooseSubscriber_setListener(subBBZ2, gooseListener, NULL);
    GooseReceiver_addSubscriber(receiver, subBBZ2);
    printf("[GOOSE INIT]  + E00_P746 Zone2  (AppID=4098, GoCB=gcbE00P746Z2)\n");

    /* ---- Busbar Check Zone — E00_P746 / E00P746CZ / AppID=4099 ---- */
    GooseSubscriber subBBCZ = GooseSubscriber_create(
        "E00_P746E00P746CZ/LLN0$GO$gcbE00P746CZ", NULL);
    GooseSubscriber_setAppId(subBBCZ, 4099);
    GooseSubscriber_setListener(subBBCZ, gooseListener, NULL);
    GooseReceiver_addSubscriber(receiver, subBBCZ);
    printf("[GOOSE INIT]  + E00_P746 CheckZ (AppID=4099, GoCB=gcbE00P746CZ)\n");

    /* ---- BCU Switch Status (AppID=4097 shared — match by GoCbRef) ---- */
    const struct {
        const char *gocbRef;
        const char *label;
    } bcu_subs[] = {
        {"E01_BCUE01BCU/LLN0$GO$gcbE01BCU", "E01_BCU"},
        {"E02_BCUE02BCU/LLN0$GO$gcbE02BCU", "E02_BCU"},
        {"E03_BCUE03BCU/LLN0$GO$gcbE03BCU", "E03_BCU"},
        {"E04_BCUE04BCU/LLN0$GO$gcbE04BCU", "E04_BCU"},
        {"E05_BCUE05BCU/LLN0$GO$gcbE05BCU", "E05_BCU"},
        {"E06_BCUE06BCU/LLN0$GO$gcbE06BCU", "E06_BCU"},
    };

    for (int i = 0; i < (int)(sizeof(bcu_subs)/sizeof(bcu_subs[0])); i++) {
        GooseSubscriber sub = GooseSubscriber_create(bcu_subs[i].gocbRef, NULL);
        /* AppID=4097, but receiver matches on full GoCbRef string */
        GooseSubscriber_setAppId(sub, 4097);
        GooseSubscriber_setListener(sub, gooseListener, NULL);
        GooseReceiver_addSubscriber(receiver, sub);
        printf("[GOOSE INIT]  + %-10s      (AppID=4097, GoCB=%s)\n",
               bcu_subs[i].label, bcu_subs[i].gocbRef + strlen(bcu_subs[i].label));
    }

    printf("[GOOSE INIT] Total: 9 GOOSE subscriptions registered\n");
}
