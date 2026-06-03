/* ============================================================
 *  fault_engine.h — Fault simulation engine for SAS simulator
 *  GI 150kV ANTAM POMALAA — Protection logic per ANSI functions
 * ============================================================ */
#ifndef FAULT_ENGINE_H
#define FAULT_ENGINE_H

#include "iec61850_server.h"
#include "hal_thread.h"
#include "ied_manager.h"
#include <stdint.h>

/* ---- IED reference (server + model pair) used per bay sub-IED ---- */
typedef struct {
    IedServer  srv;   /* libiec61850 server handle (NULL = not available) */
    IedModel  *mdl;   /* static model pointer      (NULL = not available) */
} FaultIedRef;

/* ---- Fault types ---- */
typedef enum {
    FAULT_NONE = 0,
    FAULT_PHASE_PHASE,        /* A-B, B-C, C-A             */
    FAULT_PHASE_EARTH,        /* A-G, B-G, C-G             */
    FAULT_THREE_PHASE,        /* A-B-C                     */
    FAULT_DOUBLE_EARTH,       /* A-B-G                     */
    FAULT_BUSBAR_ZONE1,       /* Busbar Zone 1 internal    */
    FAULT_BUSBAR_ZONE2,       /* Busbar Zone 2 internal    */
    FAULT_TRANSFORMER_DIFF,   /* 87T winding fault         */
    FAULT_TRANSFORMER_REF,    /* 87REF restricted E/F      */
} FaultType;

/* ---- Protection sequence state ---- */
typedef enum {
    PROT_IDLE = 0,
    PROT_STARTED,             /* Str / pickup              */
    PROT_TRIPPED,             /* Op / trip issued           */
    PROT_AR_DEAD_TIME,        /* Auto-reclose dead time     */
    PROT_AR_SYNC_CHECK,       /* Sync check before reclose  */
    PROT_AR_RECLOSED,         /* Reclosed, reclaim time     */
    PROT_AR_LOCKOUT,          /* Final trip, lockout (86)   */
    PROT_CBF_WAIT,            /* Breaker failure timer      */
    PROT_CBF_BACKUP,          /* CBF escalation             */
} ProtState;

/* ---- Bay types ---- */
typedef enum {
    BAY_TRANSFORMER,
    BAY_LINE,
    BAY_COUPLER,
    BAY_BUSBAR,
} BayType;

/* ---- Per-bay state ---- */
#define MAX_BAYS 10

typedef struct {
    const char *bay_id;       /* e.g., "E01", "E05"        */
    const char *ld_bcu;       /* LD inst for BCU           */
    const char *ld_prot;      /* LD inst for main prot     */
    const char *ld_backup;    /* LD inst for backup prot   */
    BayType     bay_type;

    /* Per-bay IED server references (populated at init) */
    FaultIedRef bcu;          /* E01_BCU server/model      */
    FaultIedRef prot;         /* E01_P643/P543 server/model */
    FaultIedRef backup;       /* E01_P142 server/model     */

    /* Equipment state */
    int  cb_closed;           /* Circuit breaker: 1=closed  */
    int  dis_bus_closed;      /* Bus-side disconnector      */
    int  dis_line_closed;     /* Line-side disconnector     */
    int  earth_closed;        /* Earthing switch            */

    /* Simulated analog values */
    float v_a, v_b, v_c;     /* Phase voltages (kV)        */
    float i_a, i_b, i_c;     /* Phase currents (A)         */
    float freq;               /* Frequency (Hz)             */
    float tot_w, tot_var;     /* Power (MW, MVAr)           */

    /* Protection state */
    ProtState   prot_state;
    FaultType   active_fault;
    int         fault_zone;   /* Distance zone (1-4)        */
    uint64_t    state_enter_ms;
    int         ar_attempts;
    int         ar_max;       /* Max AR attempts (typ 1)    */
} BayState;

/* ---- Engine context ---- */
typedef struct {
    BayState    bays[MAX_BAYS];
    int         num_bays;
} FaultEngine;

/* ---- API ---- */

/* Initialize for monolithic mode — one server/model for all bays */
void  fault_engine_init(FaultEngine *eng, IedServer server, IedModel *model);

/* Initialize for distributed mode — looks up per-IED servers from manager */
void  fault_engine_init_distributed(FaultEngine *eng, IedManager *mgr);

void  fault_engine_tick   (FaultEngine *eng, uint64_t now_ms);
int   fault_engine_inject (FaultEngine *eng, const char *bay_id, FaultType type, int zone);
void  fault_engine_clear  (FaultEngine *eng, const char *bay_id);
void  fault_engine_print_status(FaultEngine *eng);
int   fault_engine_parse_command(FaultEngine *eng, const char *cmd);

#endif /* FAULT_ENGINE_H */
