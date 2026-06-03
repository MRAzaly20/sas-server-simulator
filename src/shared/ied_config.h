/* ============================================================
 *  ied_config.h — JSON configuration loader for per-IED executables
 *  GI 150kV — Multi-executable IED architecture
 * ============================================================ */
#ifndef IED_CONFIG_H
#define IED_CONFIG_H

#include <stdbool.h>

#define MAX_GOOSE_SUBS 10
#define MAX_ACTION_LEN 64

/* ---- GOOSE subscription entry ---- */
typedef struct {
    char  gocbRef[128];       /* e.g. "E00_P746E00P746Z1/LLN0$GO$gcbE00P746Z1" */
    int   appId;              /* e.g. 4097 */
    char  action[MAX_ACTION_LEN]; /* e.g. "intertrip_open_cb" */
} GooseSubEntry;

/* ---- Protection settings ---- */
typedef struct {
    char  type[32];           /* "distance", "differential", "overcurrent", "BCU", "busbar" */

    /* Distance relay settings (P543) */
    float zone1_reach_ohm;
    int   zone1_delay_ms;
    float zone2_reach_ohm;
    int   zone2_delay_ms;
    float zone3_reach_ohm;
    int   zone3_delay_ms;
    float zone4_reach_ohm;
    int   zone4_delay_ms;
    bool  ar_enabled;
    int   ar_max_attempts;
    int   ar_dead_time_ms;

    /* Overcurrent settings (P142/P143) */
    float i_pickup_a;         /* Pickup current (A) */
    int   curve_type;         /* 0=definite, 1=IDMT */
    float time_dial;          /* Time multiplier */

    /* Differential settings (P643) */
    float diff_threshold;     /* Differential current threshold */

    /* Common nominal values */
    float nominal_v_kv;       /* 86.6 kV (150/sqrt(3)) */
    float nominal_i_a;        /* 200 A */
    float nominal_freq;       /* 50 Hz */
} ProtectionSettings;

/* ---- Complete IED configuration ---- */
typedef struct {
    char  ied_name[32];       /* e.g. "E05_P543" */
    char  ip[16];             /* e.g. "127.0.0.1" */
    int   port;               /* e.g. 10251 */
    char  goose_interface[128]; /* e.g. "4" (Windows adapter number) */

    ProtectionSettings prot;

    GooseSubEntry goose_subs[MAX_GOOSE_SUBS];
    int           num_goose_subs;
} IedConfig;

/* ---- API ---- */

/* Load config from JSON file. Returns 0 on success, -1 on error. */
int  ied_config_load(IedConfig *cfg, const char *json_path);

/* Print loaded config to stdout for verification */
void ied_config_print(const IedConfig *cfg);

/* Initialize config with defaults */
void ied_config_defaults(IedConfig *cfg);

#endif /* IED_CONFIG_H */
