/* ============================================================
 *  ied_config.c — JSON configuration loader implementation
 *  Uses cJSON (MIT license) for parsing
 * ============================================================ */
#include "ied_config.h"
#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- Helper: safe string copy from JSON ---- */
static void json_str(cJSON *obj, const char *key, char *dst, int maxlen) {
    cJSON *item = cJSON_GetObjectItemCaseSensitive(obj, key);
    if (cJSON_IsString(item) && item->valuestring) {
        strncpy(dst, item->valuestring, maxlen - 1);
        dst[maxlen - 1] = '\0';
    }
}

static int json_int(cJSON *obj, const char *key, int def) {
    cJSON *item = cJSON_GetObjectItemCaseSensitive(obj, key);
    return cJSON_IsNumber(item) ? item->valueint : def;
}

static float json_float(cJSON *obj, const char *key, float def) {
    cJSON *item = cJSON_GetObjectItemCaseSensitive(obj, key);
    return cJSON_IsNumber(item) ? (float)item->valuedouble : def;
}

static bool json_bool(cJSON *obj, const char *key, bool def) {
    cJSON *item = cJSON_GetObjectItemCaseSensitive(obj, key);
    if (cJSON_IsBool(item)) return cJSON_IsTrue(item);
    return def;
}

/* ---- Initialize with defaults ---- */
void ied_config_defaults(IedConfig *cfg) {
    memset(cfg, 0, sizeof(*cfg));
    strcpy(cfg->ip, "127.0.0.1");
    cfg->port = 102;

    cfg->prot.nominal_v_kv  = 86.6f;
    cfg->prot.nominal_i_a   = 200.0f;
    cfg->prot.nominal_freq  = 50.0f;

    /* Distance defaults */
    cfg->prot.zone1_reach_ohm = 12.5f;  cfg->prot.zone1_delay_ms = 0;
    cfg->prot.zone2_reach_ohm = 25.0f;  cfg->prot.zone2_delay_ms = 400;
    cfg->prot.zone3_reach_ohm = 50.0f;  cfg->prot.zone3_delay_ms = 1000;
    cfg->prot.zone4_reach_ohm = 10.0f;  cfg->prot.zone4_delay_ms = 500;
    cfg->prot.ar_enabled = true;
    cfg->prot.ar_max_attempts = 1;
    cfg->prot.ar_dead_time_ms = 800;

    /* Overcurrent defaults */
    cfg->prot.i_pickup_a = 800.0f;
    cfg->prot.time_dial  = 0.1f;

    /* Differential defaults */
    cfg->prot.diff_threshold = 0.2f;
}

/* ---- Load from JSON file ---- */
int ied_config_load(IedConfig *cfg, const char *json_path) {
    ied_config_defaults(cfg);

    FILE *f = fopen(json_path, "rb");
    if (!f) {
        printf("[CONFIG] ERROR: Cannot open '%s'\n", json_path);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *data = (char *)malloc(len + 1);
    fread(data, 1, len, f);
    data[len] = '\0';
    fclose(f);

    cJSON *root = cJSON_Parse(data);
    free(data);

    if (!root) {
        printf("[CONFIG] ERROR: JSON parse error in '%s': %s\n",
               json_path, cJSON_GetErrorPtr());
        return -1;
    }

    /* Top-level fields */
    json_str(root, "ied_name", cfg->ied_name, sizeof(cfg->ied_name));
    json_str(root, "ip", cfg->ip, sizeof(cfg->ip));
    cfg->port = json_int(root, "port", cfg->port);
    json_str(root, "goose_interface", cfg->goose_interface, sizeof(cfg->goose_interface));

    /* Protection settings */
    cJSON *prot = cJSON_GetObjectItemCaseSensitive(root, "protection");
    if (prot) {
        json_str(prot, "type", cfg->prot.type, sizeof(cfg->prot.type));

        cfg->prot.zone1_reach_ohm = json_float(prot, "zone1_reach_ohm", cfg->prot.zone1_reach_ohm);
        cfg->prot.zone1_delay_ms  = json_int(prot, "zone1_delay_ms", cfg->prot.zone1_delay_ms);
        cfg->prot.zone2_reach_ohm = json_float(prot, "zone2_reach_ohm", cfg->prot.zone2_reach_ohm);
        cfg->prot.zone2_delay_ms  = json_int(prot, "zone2_delay_ms", cfg->prot.zone2_delay_ms);
        cfg->prot.zone3_reach_ohm = json_float(prot, "zone3_reach_ohm", cfg->prot.zone3_reach_ohm);
        cfg->prot.zone3_delay_ms  = json_int(prot, "zone3_delay_ms", cfg->prot.zone3_delay_ms);
        cfg->prot.zone4_reach_ohm = json_float(prot, "zone4_reach_ohm", cfg->prot.zone4_reach_ohm);
        cfg->prot.zone4_delay_ms  = json_int(prot, "zone4_delay_ms", cfg->prot.zone4_delay_ms);

        cfg->prot.ar_enabled      = json_bool(prot, "ar_enabled", cfg->prot.ar_enabled);
        cfg->prot.ar_max_attempts = json_int(prot, "ar_max_attempts", cfg->prot.ar_max_attempts);
        cfg->prot.ar_dead_time_ms = json_int(prot, "ar_dead_time_ms", cfg->prot.ar_dead_time_ms);

        cfg->prot.i_pickup_a     = json_float(prot, "i_pickup_a", cfg->prot.i_pickup_a);
        cfg->prot.curve_type     = json_int(prot, "curve_type", cfg->prot.curve_type);
        cfg->prot.time_dial      = json_float(prot, "time_dial", cfg->prot.time_dial);
        cfg->prot.diff_threshold = json_float(prot, "diff_threshold", cfg->prot.diff_threshold);

        cfg->prot.nominal_v_kv   = json_float(prot, "nominal_v_kv", cfg->prot.nominal_v_kv);
        cfg->prot.nominal_i_a    = json_float(prot, "nominal_i_a", cfg->prot.nominal_i_a);
        cfg->prot.nominal_freq   = json_float(prot, "nominal_freq", cfg->prot.nominal_freq);
    }

    /* GOOSE subscriptions */
    cJSON *subs = cJSON_GetObjectItemCaseSensitive(root, "goose_subscriptions");
    if (cJSON_IsArray(subs)) {
        int n = cJSON_GetArraySize(subs);
        if (n > MAX_GOOSE_SUBS) n = MAX_GOOSE_SUBS;
        cfg->num_goose_subs = n;

        for (int i = 0; i < n; i++) {
            cJSON *entry = cJSON_GetArrayItem(subs, i);
            GooseSubEntry *se = &cfg->goose_subs[i];
            json_str(entry, "gocbRef", se->gocbRef, sizeof(se->gocbRef));
            se->appId = json_int(entry, "appId", 0);
            json_str(entry, "action", se->action, sizeof(se->action));
        }
    }

    cJSON_Delete(root);
    printf("[CONFIG] Loaded: %s (%s:%d, GOOSE iface=%s, %d subs)\n",
           cfg->ied_name, cfg->ip, cfg->port,
           cfg->goose_interface[0] ? cfg->goose_interface : "none",
           cfg->num_goose_subs);
    return 0;
}

/* ---- Print config ---- */
void ied_config_print(const IedConfig *cfg) {
    printf("  IED Name:   %s\n", cfg->ied_name);
    printf("  IP:Port:    %s:%d\n", cfg->ip, cfg->port);
    printf("  GOOSE NIC:  %s\n", cfg->goose_interface[0] ? cfg->goose_interface : "(none)");
    printf("  Prot Type:  %s\n", cfg->prot.type);
    if (cfg->num_goose_subs > 0) {
        printf("  GOOSE Subs: %d\n", cfg->num_goose_subs);
        for (int i = 0; i < cfg->num_goose_subs; i++)
            printf("    [%d] AppID=%d action=%s\n", i,
                   cfg->goose_subs[i].appId, cfg->goose_subs[i].action);
    }
}
