/* ============================================================
 *  fault_engine.c — Fault simulation engine implementation
 *  Implements ANSI protection logic for GI 150kV
 *  Updated: per-bay IedRef — each bay has its own IedServer refs
 * ============================================================ */
#include "fault_engine.h"
#include "ied_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* ---- Timing constants (ms) ---- */
#define ZONE1_DELAY_MS        0      /* Instantaneous         */
#define ZONE2_DELAY_MS      400      /* ~300-500ms            */
#define ZONE3_DELAY_MS     1000      /* ~1000ms               */
#define ZONE4_DELAY_MS      500      /* ~500ms reverse        */
#define AR_DEAD_TIME_MS     800      /* 0.3-1.0s typ          */
#define AR_RECLAIM_TIME_MS 5000      /* Reclaim timer         */
#define CBF_TIME_MS         150      /* Breaker failure 100-200ms */
#define DIFF_TRIP_MS          5      /* <25ms busbar diff      */
#define TRF_DIFF_MS          10      /* Transformer diff      */

/* ---- Normal operating values ---- */
#define NOMINAL_V_KV    86.6f   /* 150/sqrt(3) kV phase     */
#define NOMINAL_I_A    200.0f   /* Typical load current      */
#define NOMINAL_FREQ    50.0f   /* Hz                        */
#define FAULT_I_A     5000.0f   /* Fault current             */

/* ---- Helper: look up a DA node and update it ---- */
static void update_da_bool(FaultIedRef *r, const char *ref, int val) {
    if (!r->srv || !r->mdl) return;
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(r->mdl, ref);
    if (da) {
        IedServer_lockDataModel(r->srv);
        IedServer_updateBooleanAttributeValue(r->srv, da, val ? true : false);
        IedServer_unlockDataModel(r->srv);
    }
}

static void update_da_int(FaultIedRef *r, const char *ref, int val) {
    if (!r->srv || !r->mdl) return;
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(r->mdl, ref);
    if (da) {
        IedServer_lockDataModel(r->srv);
        IedServer_updateInt32AttributeValue(r->srv, da, val);
        IedServer_unlockDataModel(r->srv);
    }
}

static void update_da_dbpos(FaultIedRef *r, const char *ref, int val) {
    if (!r->srv || !r->mdl) return;
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(r->mdl, ref);
    if (da) {
        IedServer_lockDataModel(r->srv);
        IedServer_updateDbposValue(r->srv, da, val);
        IedServer_unlockDataModel(r->srv);
    }
}

static void update_da_float(FaultIedRef *r, const char *ref, float val) {
    if (!r->srv || !r->mdl) return;
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(r->mdl, ref);
    if (da) {
        IedServer_lockDataModel(r->srv);
        IedServer_updateFloatAttributeValue(r->srv, da, val);
        IedServer_unlockDataModel(r->srv);
    }
}

static void update_da_time(FaultIedRef *r, const char *ref, uint64_t ms) {
    if (!r->srv || !r->mdl) return;
    DataAttribute *da = (DataAttribute*)
        IedModel_getModelNodeByShortObjectReference(r->mdl, ref);
    if (da) {
        IedServer_lockDataModel(r->srv);
        IedServer_updateUTCTimeAttributeValue(r->srv, da, ms);
        IedServer_unlockDataModel(r->srv);
    }
}

/* Update CB position via BCU IED ref: DPC stVal 1=open, 2=closed */
static void update_cb_pos(BayState *bay, int closed) {
    bay->cb_closed = closed;
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/XCBR1.Pos.stVal", bay->ld_bcu);
    update_da_dbpos(&bay->bcu, ref, closed ? 2 : 1);
    snprintf(ref, sizeof(ref), "%s/XCBR1.Pos.t", bay->ld_bcu);
    update_da_time(&bay->bcu, ref, Hal_getTimeInMs());
}

/* Set protection trip signal via prot IED ref */
static void set_trip(BayState *bay, int tripped, uint64_t now) {
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.general", bay->ld_prot);
    update_da_bool(&bay->prot, ref, tripped);
    snprintf(ref, sizeof(ref), "%s/PTRC1.Tr.t", bay->ld_prot);
    update_da_time(&bay->prot, ref, now);
}

/* Set protection start/operate via prot IED ref */
static void set_prot_op(BayState *bay, const char *ln,
                        int operated, uint64_t now) {
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/%s.Op.general", bay->ld_prot, ln);
    update_da_bool(&bay->prot, ref, operated);
    snprintf(ref, sizeof(ref), "%s/%s.Op.t", bay->ld_prot, ln);
    update_da_time(&bay->prot, ref, now);
}

/* Set auto-reclose state via prot IED ref */
static void set_ar_state(BayState *bay, int state, uint64_t now) {
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/RREC1.AutoRecSt.stVal", bay->ld_prot);
    update_da_int(&bay->prot, ref, state);
    snprintf(ref, sizeof(ref), "%s/RREC1.AutoRecSt.t", bay->ld_prot);
    update_da_time(&bay->prot, ref, now);
}

/* Update analog measurements via prot IED ref */
static void update_analogs(BayState *bay) {
    if (!bay->ld_prot) return;
    char ref[128];
    snprintf(ref, sizeof(ref), "%s/MMXU1.TotW.mag.f", bay->ld_prot);
    update_da_float(&bay->prot, ref, bay->tot_w);
    snprintf(ref, sizeof(ref), "%s/MMXU1.TotVAr.mag.f", bay->ld_prot);
    update_da_float(&bay->prot, ref, bay->tot_var);
    snprintf(ref, sizeof(ref), "%s/MMXU1.Hz.mag.f", bay->ld_prot);
    update_da_float(&bay->prot, ref, bay->freq);
}

/* ---- Helper: find bay by ID ---- */
static BayState *find_bay(FaultEngine *eng, const char *bay_id) {
    for (int i = 0; i < eng->num_bays; i++)
        if (strcmp(eng->bays[i].bay_id, bay_id) == 0)
            return &eng->bays[i];
    return NULL;
}

/* ---- Shared bay-definition table ---- */
static void init_bay_table(FaultEngine *eng) {
    struct { const char *id, *bcu, *prot, *backup; BayType type; } defs[] = {
        {"E01","E01BCU","E01P643","E01P142HV", BAY_TRANSFORMER},
        {"E02","E02BCU","E02P643","E02P142HV", BAY_TRANSFORMER},
        {"E03","E03BCU","E03P643","E03P142HV", BAY_TRANSFORMER},
        {"E04","E04BCU","E04P143",NULL,        BAY_COUPLER},
        {"E05","E05BCU","E05P543","E05P142",   BAY_LINE},
        {"E06","E06BCU","E06P543","E06P142",   BAY_LINE},
    };
    int n = sizeof(defs)/sizeof(defs[0]);

    for (int i = 0; i < n; i++) {
        BayState *b = &eng->bays[i];
        b->bay_id       = defs[i].id;
        b->ld_bcu       = defs[i].bcu;
        b->ld_prot      = defs[i].prot;
        b->ld_backup    = defs[i].backup;
        b->bay_type     = defs[i].type;
        b->cb_closed    = 1;
        b->dis_bus_closed = 1;
        b->dis_line_closed = 1;
        b->earth_closed = 0;
        b->v_a = b->v_b = b->v_c = NOMINAL_V_KV;
        b->i_a = b->i_b = b->i_c = NOMINAL_I_A;
        b->freq = NOMINAL_FREQ;
        b->tot_w = 25.0f;
        b->tot_var = 8.0f;
        b->prot_state = PROT_IDLE;
        b->active_fault = FAULT_NONE;
        b->ar_max = (defs[i].type == BAY_LINE) ? 1 : 0;
        /* IedRef fields default to NULL until populated by init functions */
    }
    eng->num_bays = n;
}

/* ============================================================
 *  MONOLITHIC INIT — all bays share the same IedServer/IedModel
 * ============================================================ */
void fault_engine_init(FaultEngine *eng, IedServer server, IedModel *model) {
    memset(eng, 0, sizeof(*eng));
    init_bay_table(eng);

    /* Assign same server/model to all bay sub-IEDs */
    for (int i = 0; i < eng->num_bays; i++) {
        BayState *b = &eng->bays[i];
        b->bcu.srv    = server;  b->bcu.mdl    = model;
        b->prot.srv   = server;  b->prot.mdl   = model;
        b->backup.srv = server;  b->backup.mdl = model;
        update_cb_pos(b, 1);
    }
    printf("[FAULT ENGINE] Initialized (monolithic) with %d bays\n", eng->num_bays);
}

/* ============================================================
 *  DISTRIBUTED INIT — each bay sub-IED uses its own IedServer
 *  IED naming convention: E01_BCU, E01_P643, E01_P142, etc.
 * ============================================================ */
void fault_engine_init_distributed(FaultEngine *eng, IedManager *mgr) {
    memset(eng, 0, sizeof(*eng));
    init_bay_table(eng);

    /* Bay-to-IED-name mapping table */
    struct {
        const char *bay_id;
        const char *bcu_ied;
        const char *prot_ied;
        const char *backup_ied;
    } ied_map[] = {
        {"E01", "E01_BCU", "E01_P643", "E01_P142"},
        {"E02", "E02_BCU", "E02_P643", "E02_P142"},
        {"E03", "E03_BCU", "E03_P643", "E03_P142"},
        {"E04", "E04_BCU", "E04_P143", NULL},
        {"E05", "E05_BCU", "E05_P543", "E05_P142"},
        {"E06", "E06_BCU", "E06_P543", "E06_P142"},
    };

    for (int i = 0; i < eng->num_bays; i++) {
        BayState *b = &eng->bays[i];

        /* Look up BCU IED */
        IedInstance *bcu_inst = ied_manager_find(mgr, ied_map[i].bcu_ied);
        if (bcu_inst && bcu_inst->server) {
            b->bcu.srv = bcu_inst->server;
            b->bcu.mdl = bcu_inst->model;
        } else {
            printf("[FAULT ENGINE] WARNING: BCU IED '%s' not found/running\n",
                   ied_map[i].bcu_ied);
        }

        /* Look up main protection IED */
        IedInstance *prot_inst = ied_manager_find(mgr, ied_map[i].prot_ied);
        if (prot_inst && prot_inst->server) {
            b->prot.srv = prot_inst->server;
            b->prot.mdl = prot_inst->model;
        } else {
            printf("[FAULT ENGINE] WARNING: Prot IED '%s' not found/running\n",
                   ied_map[i].prot_ied);
        }

        /* Look up backup protection IED (optional) */
        if (ied_map[i].backup_ied) {
            IedInstance *bkp_inst = ied_manager_find(mgr, ied_map[i].backup_ied);
            if (bkp_inst && bkp_inst->server) {
                b->backup.srv = bkp_inst->server;
                b->backup.mdl = bkp_inst->model;
            }
        }

        /* Set initial CB position */
        update_cb_pos(b, 1);
    }
    printf("[FAULT ENGINE] Initialized (distributed) with %d bays\n", eng->num_bays);
}

/* ---- Get zone delay ---- */
static uint32_t zone_delay_ms(int zone) {
    switch (zone) {
        case 1: return ZONE1_DELAY_MS;
        case 2: return ZONE2_DELAY_MS;
        case 3: return ZONE3_DELAY_MS;
        case 4: return ZONE4_DELAY_MS;
        default: return ZONE2_DELAY_MS;
    }
}

/* ---- Process line bay protection ---- */
static void tick_line(FaultEngine *eng, BayState *bay, uint64_t now) {
    uint64_t elapsed = now - bay->state_enter_ms;

    switch (bay->prot_state) {
    case PROT_IDLE:
        break;

    case PROT_STARTED: {
        uint32_t delay = zone_delay_ms(bay->fault_zone);
        if (elapsed >= delay) {
            printf("[PROT] %s: Zone %d TRIP (after %ums)\n",
                   bay->bay_id, bay->fault_zone, delay);
            char ln[16];
            snprintf(ln, sizeof(ln), "PDIS%d", bay->fault_zone);
            set_prot_op(bay, ln, 1, now);
            set_trip(bay, 1, now);
            update_cb_pos(bay, 0);
            bay->prot_state = PROT_TRIPPED;
            bay->state_enter_ms = now;
            bay->i_a = bay->i_b = bay->i_c = 0;
            bay->tot_w = bay->tot_var = 0;
        }
        break;
    }
    case PROT_TRIPPED:
        if (bay->ar_max > 0 && bay->ar_attempts < bay->ar_max) {
            printf("[PROT] %s: Starting auto-reclose dead time (%dms)\n",
                   bay->bay_id, AR_DEAD_TIME_MS);
            bay->prot_state = PROT_AR_DEAD_TIME;
            bay->state_enter_ms = now;
            set_ar_state(bay, 1, now);
        } else {
            printf("[PROT] %s: LOCKOUT — no auto-reclose\n", bay->bay_id);
            bay->prot_state = PROT_AR_LOCKOUT;
            bay->state_enter_ms = now;
        }
        break;

    case PROT_AR_DEAD_TIME:
        if (elapsed >= AR_DEAD_TIME_MS) {
            printf("[PROT] %s: Dead time expired → Sync check (25)\n", bay->bay_id);
            bay->prot_state = PROT_AR_SYNC_CHECK;
            bay->state_enter_ms = now;
        }
        break;

    case PROT_AR_SYNC_CHECK:
        printf("[PROT] %s: Sync check PASS → Reclosing breaker\n", bay->bay_id);
        update_cb_pos(bay, 1);
        bay->ar_attempts++;
        bay->prot_state = PROT_AR_RECLOSED;
        bay->state_enter_ms = now;
        set_ar_state(bay, 2, now);
        if (bay->active_fault != FAULT_NONE) {
            printf("[PROT] %s: Fault persists after reclose!\n", bay->bay_id);
            bay->i_a = bay->i_b = FAULT_I_A;
        } else {
            bay->v_a = bay->v_b = bay->v_c = NOMINAL_V_KV;
            bay->i_a = bay->i_b = bay->i_c = NOMINAL_I_A;
            bay->freq = NOMINAL_FREQ;
            bay->tot_w = 25.0f; bay->tot_var = 8.0f;
        }
        break;

    case PROT_AR_RECLOSED:
        if (bay->active_fault != FAULT_NONE && elapsed >= 100) {
            printf("[PROT] %s: FINAL TRIP → LOCKOUT (86)\n", bay->bay_id);
            update_cb_pos(bay, 0);
            bay->prot_state = PROT_AR_LOCKOUT;
            bay->state_enter_ms = now;
            bay->i_a = bay->i_b = bay->i_c = 0;
            set_ar_state(bay, 3, now);
        } else if (bay->active_fault == FAULT_NONE && elapsed >= AR_RECLAIM_TIME_MS) {
            printf("[PROT] %s: Reclaim time expired — AR SUCCESSFUL\n", bay->bay_id);
            char ln[16];
            snprintf(ln, sizeof(ln), "PDIS%d", bay->fault_zone);
            set_prot_op(bay, ln, 0, now);
            set_trip(bay, 0, now);
            set_ar_state(bay, 0, now);
            bay->prot_state = PROT_IDLE;
            bay->ar_attempts = 0;
        }
        break;

    case PROT_AR_LOCKOUT:
        break;

    default: break;
    }
}

/* ---- Process transformer bay protection ---- */
static void tick_transformer(FaultEngine *eng, BayState *bay, uint64_t now) {
    (void)eng;
    uint64_t elapsed = now - bay->state_enter_ms;

    switch (bay->prot_state) {
    case PROT_STARTED:
        if (elapsed >= TRF_DIFF_MS) {
            printf("[PROT] %s: 87T Differential TRIP (%ums)\n", bay->bay_id, TRF_DIFF_MS);
            set_prot_op(bay, "PDIF1", 1, now);
            set_trip(bay, 1, now);
            update_cb_pos(bay, 0);
            bay->i_a = bay->i_b = bay->i_c = 0;
            bay->tot_w = bay->tot_var = 0;
            bay->prot_state = PROT_AR_LOCKOUT;
            bay->state_enter_ms = now;
            printf("[PROT] %s: LOCKOUT — transformer fault, no auto-reclose\n", bay->bay_id);
        }
        break;
    default: break;
    }
}

/* ---- Process coupler bay protection ---- */
static void tick_coupler(FaultEngine *eng, BayState *bay, uint64_t now) {
    (void)eng;
    uint64_t elapsed = now - bay->state_enter_ms;

    switch (bay->prot_state) {
    case PROT_STARTED:
        if (elapsed >= ZONE2_DELAY_MS) {
            printf("[PROT] %s: 50/51 Overcurrent TRIP\n", bay->bay_id);
            set_prot_op(bay, "PTOC1", 1, now);
            set_trip(bay, 1, now);
            update_cb_pos(bay, 0);
            bay->i_a = bay->i_b = bay->i_c = 0;
            bay->prot_state = PROT_AR_LOCKOUT;
            bay->state_enter_ms = now;
        }
        break;
    default: break;
    }
}

/* ---- Process busbar fault — trips all zone breakers ---- */
static void tick_busbar_fault(FaultEngine *eng, uint64_t now, int zone) {
    /* Look up the busbar protection IED — by finding bays, not a fixed server */
    /* The busbar prot signals are handled via the E00_P746 IED directly in
       sas_server_distributed. Here we trip all connected bay CBs. */

    printf("[PROT] BUSBAR Zone %d: 87B differential + Check Zone → TRIP\n", zone);

    const char *zone1_bays[] = {"E01","E02","E03","E04","E05"};
    const char *zone2_bays[] = {"E04","E06"};
    const char **trip_bays = (zone == 1) ? zone1_bays : zone2_bays;
    int n = (zone == 1) ? 5 : 2;

    for (int i = 0; i < n; i++) {
        BayState *b = find_bay(eng, trip_bays[i]);
        if (b && b->cb_closed) {
            printf("[PROT] BUSBAR: Trip breaker %s\n", b->bay_id);
            update_cb_pos(b, 0);
            b->i_a = b->i_b = b->i_c = 0;
            b->tot_w = b->tot_var = 0;
            b->prot_state = PROT_AR_LOCKOUT;
        }
    }
}

/* ---- Main tick ---- */
void fault_engine_tick(FaultEngine *eng, uint64_t now_ms) {
    static int busbar_z1_active = 0, busbar_z2_active = 0;

    for (int i = 0; i < eng->num_bays; i++) {
        BayState *bay = &eng->bays[i];

        /* Update analog noise */
        float noise = (float)(rand() % 100 - 50) / 1000.0f;
        if (bay->prot_state == PROT_IDLE && bay->cb_closed) {
            bay->v_a = NOMINAL_V_KV + noise * 2;
            bay->v_b = NOMINAL_V_KV - noise;
            bay->v_c = NOMINAL_V_KV + noise * 0.5f;
            bay->freq = NOMINAL_FREQ + noise * 0.01f;
        }
        update_analogs(bay);

        switch (bay->bay_type) {
        case BAY_LINE:        tick_line(eng, bay, now_ms);        break;
        case BAY_TRANSFORMER: tick_transformer(eng, bay, now_ms); break;
        case BAY_COUPLER:     tick_coupler(eng, bay, now_ms);     break;
        default: break;
        }
    }

    if (busbar_z1_active) {
        tick_busbar_fault(eng, now_ms, 1);
        busbar_z1_active = 0;
    }
    if (busbar_z2_active) {
        tick_busbar_fault(eng, now_ms, 2);
        busbar_z2_active = 0;
    }
}

/* ---- Inject a fault ---- */
int fault_engine_inject(FaultEngine *eng, const char *bay_id,
                        FaultType type, int zone) {
    uint64_t now = Hal_getTimeInMs();

    if (type == FAULT_BUSBAR_ZONE1 || type == FAULT_BUSBAR_ZONE2) {
        int z = (type == FAULT_BUSBAR_ZONE1) ? 1 : 2;
        printf("\n[FAULT] ═══════════════════════════════════════════\n");
        printf("[FAULT] BUSBAR ZONE %d INTERNAL FAULT INJECTED\n", z);
        printf("[FAULT] ═══════════════════════════════════════════\n\n");
        tick_busbar_fault(eng, now, z);
        return 0;
    }

    BayState *bay = find_bay(eng, bay_id);
    if (!bay) {
        printf("[FAULT] ERROR: Bay '%s' not found\n", bay_id);
        return -1;
    }
    if (bay->prot_state != PROT_IDLE) {
        printf("[FAULT] ERROR: Bay '%s' already has active fault\n", bay_id);
        return -1;
    }

    printf("\n[FAULT] ═══════════════════════════════════════════\n");
    printf("[FAULT] Bay %s: Fault type %d injected", bay_id, type);
    if (bay->bay_type == BAY_LINE) printf(" (Zone %d)", zone);
    printf("\n[FAULT] ═══════════════════════════════════════════\n\n");

    bay->active_fault = type;
    bay->fault_zone = zone;
    bay->prot_state = PROT_STARTED;
    bay->state_enter_ms = now;
    bay->ar_attempts = 0;

    bay->i_a = FAULT_I_A;
    bay->i_b = (type == FAULT_THREE_PHASE || type == FAULT_PHASE_PHASE) ? FAULT_I_A : NOMINAL_I_A;
    bay->i_c = (type == FAULT_THREE_PHASE) ? FAULT_I_A : NOMINAL_I_A;

    if (bay->ld_prot) {
        if (bay->bay_type == BAY_LINE) {
            char ln[16];
            snprintf(ln, sizeof(ln), "PDIS%d", zone > 0 ? zone : 1);
            printf("[PROT] %s: %s START pickup\n", bay_id, ln);
        } else if (bay->bay_type == BAY_TRANSFORMER) {
            printf("[PROT] %s: 87T Differential START\n", bay_id);
        } else if (bay->bay_type == BAY_COUPLER) {
            printf("[PROT] %s: 50/51 Overcurrent START\n", bay_id);
        }
    }
    return 0;
}

/* ---- Clear a fault ---- */
void fault_engine_clear(FaultEngine *eng, const char *bay_id) {
    BayState *bay = find_bay(eng, bay_id);
    if (!bay) return;
    printf("[FAULT] Bay %s: Fault CLEARED\n", bay_id);
    bay->active_fault = FAULT_NONE;
}

/* ---- Print all bay statuses ---- */
void fault_engine_print_status(FaultEngine *eng) {
    printf("\n╔═══════════════════════════════════════════════════════╗\n");
    printf("║           SAS SIMULATOR — BAY STATUS                  ║\n");
    printf("╠═══════╦═══════╦════════════╦═════════════════════════╣\n");
    printf("║ Bay   ║  CB   ║ Prot State ║ Fault                   ║\n");
    printf("╠═══════╬═══════╬════════════╬═════════════════════════╣\n");

    const char *prot_names[] = {
        "IDLE","STARTED","TRIPPED","AR_DEAD","AR_SYNC",
        "AR_RECLOSED","LOCKOUT","CBF_WAIT","CBF_BACKUP"
    };
    const char *fault_names[] = {
        "NONE","PH-PH","PH-E","3PH","DBL-E",
        "BB-Z1","BB-Z2","87T","87REF"
    };

    for (int i = 0; i < eng->num_bays; i++) {
        BayState *b = &eng->bays[i];
        printf("║ %-5s ║ %-5s ║ %-10s ║ %-23s ║\n",
               b->bay_id,
               b->cb_closed ? "CLOSE" : "OPEN ",
               prot_names[b->prot_state],
               fault_names[b->active_fault]);
    }
    printf("╚═══════╩═══════╩════════════╩═════════════════════════╝\n\n");
}

/* ---- Parse console command ---- */
int fault_engine_parse_command(FaultEngine *eng, const char *cmd) {
    char bay[16] = {0}, type_str[32] = {0};
    int zone = 1;

    if (strncmp(cmd, "status", 6) == 0) {
        fault_engine_print_status(eng);
        return 1;
    }
    if (strncmp(cmd, "clear ", 6) == 0) {
        sscanf(cmd + 6, "%15s", bay);
        fault_engine_clear(eng, bay);
        return 1;
    }
    if (strncmp(cmd, "reset ", 6) == 0) {
        sscanf(cmd + 6, "%15s", bay);
        BayState *b = find_bay(eng, bay);
        if (b) {
            b->prot_state = PROT_IDLE;
            b->active_fault = FAULT_NONE;
            b->ar_attempts = 0;
            b->v_a = b->v_b = b->v_c = NOMINAL_V_KV;
            b->i_a = b->i_b = b->i_c = NOMINAL_I_A;
            b->freq = NOMINAL_FREQ;
            b->tot_w = 25.0f; b->tot_var = 8.0f;
            update_cb_pos(b, 1);
            set_trip(b, 0, Hal_getTimeInMs());
            if (b->ar_max > 0)
                set_ar_state(b, 0, Hal_getTimeInMs());
            printf("[ENGINE] Bay %s RESET to normal\n", bay);
        }
        return 1;
    }
    if (strncmp(cmd, "fault ", 6) == 0) {
        int n = sscanf(cmd + 6, "%15s %31s %d", bay, type_str, &zone);
        if (n < 2) {
            printf("Usage: fault <bay> <type> [zone]\n");
            printf("  Types: ph-ph, ph-e, 3ph, 87T, 87REF, 50/51, bb-z1, bb-z2\n");
            printf("  Bays:  E01-E06\n");
            printf("  Zone:  1-4 (line bays only)\n");
            return 1;
        }

        FaultType ft = FAULT_NONE;
        if (strcmp(type_str, "ph-ph") == 0)      ft = FAULT_PHASE_PHASE;
        else if (strcmp(type_str, "ph-e") == 0)  ft = FAULT_PHASE_EARTH;
        else if (strcmp(type_str, "3ph") == 0)   ft = FAULT_THREE_PHASE;
        else if (strcmp(type_str, "87T") == 0)   ft = FAULT_TRANSFORMER_DIFF;
        else if (strcmp(type_str, "87REF") == 0) ft = FAULT_TRANSFORMER_REF;
        else if (strcmp(type_str, "50/51") == 0) ft = FAULT_PHASE_PHASE;
        else if (strcmp(type_str, "bb-z1") == 0) ft = FAULT_BUSBAR_ZONE1;
        else if (strcmp(type_str, "bb-z2") == 0) ft = FAULT_BUSBAR_ZONE2;
        else { printf("Unknown fault type: %s\n", type_str); return 1; }

        fault_engine_inject(eng, bay, ft, zone);
        return 1;
    }
    if (strncmp(cmd, "help", 4) == 0) {
        printf("\n=== SAS SIMULATOR COMMANDS ===\n");
        printf("  fault <bay> <type> [zone]  — Inject fault\n");
        printf("  clear <bay>                — Clear fault (self-healing)\n");
        printf("  reset <bay>                — Full reset to normal\n");
        printf("  status                     — Print all bay statuses\n");
        printf("  quit                       — Stop server\n");
        printf("\nFault types: ph-ph, ph-e, 3ph, 87T, 87REF, 50/51, bb-z1, bb-z2\n");
        printf("Bays: E01 E02 E03 (transformers), E04 (coupler), E05 E06 (lines)\n");
        printf("Zones: 1-4 (line bays only, default=1)\n\n");
        return 1;
    }
    return 0;
}
