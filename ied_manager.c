/* ============================================================
 *  ied_manager.c — Multi-IED instance manager implementation
 *  Each IED runs its own IedServer in a dedicated thread
 * ============================================================ */
#include "ied_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- Thread function for a single IED server ---- */
static void ied_server_thread(void *param) {
    IedInstance *inst = (IedInstance *)param;

    IedServerConfig config = IedServerConfig_create();
    inst->server = IedServer_createWithConfig(inst->model, NULL, config);
    IedServerConfig_destroy(config);

    if (!inst->server) {
        printf("[IED %s] ERROR: Failed to create server\n", inst->ied_name);
        return;
    }

    /* Step 1: Set GOOSE interface FIRST (before start, per official example).
     * On Windows: pass adapter number (e.g. "4") from find.exe output.
     * On Linux: pass interface name (e.g. "eth0"). */
    if (inst->goose_interface[0] != '\0') {
        IedServer_setGooseInterfaceId(inst->server, inst->goose_interface);
        printf("[IED %s] GOOSE interface: %s\n",
               inst->ied_name, inst->goose_interface);
    }

    /* Step 2: Bind MMS to specific IP */
    IedServer_setLocalIpAddress(inst->server, inst->ip);

    /* Step 3: Start MMS server */
    IedServer_start(inst->server, inst->port);

    if (!IedServer_isRunning(inst->server)) {
        printf("[IED %s] ERROR: Failed to start on %s:%d\n",
               inst->ied_name, inst->ip, inst->port);
        IedServer_destroy(inst->server);
        inst->server = NULL;
        return;
    }

    printf("[IED %s] MMS server started on %s:%d\n",
           inst->ied_name, inst->ip, inst->port);

    /* Step 4: Enable GOOSE publishing (AFTER start, per official example) */
    IedServer_enableGoosePublishing(inst->server);

    /* Keep running until stop */
    while (inst->running) {
        Thread_sleep(500);
    }

    IedServer_stop(inst->server);
    IedServer_destroy(inst->server);
    inst->server = NULL;
    printf("[IED %s] Server stopped\n", inst->ied_name);
}

/* ---- Initialize ---- */
void ied_manager_init(IedManager *mgr, const char *goose_interface) {
    memset(mgr, 0, sizeof(*mgr));
    if (goose_interface)
        mgr->goose_interface = strdup(goose_interface);
}

/* ---- Add IED ---- */
int ied_manager_add(IedManager *mgr, const char *ied_name,
                    const char *ip, int port, IedModel *model) {
    if (mgr->num_ieds >= MAX_IEDS) {
        printf("[MANAGER] ERROR: Maximum IED count (%d) reached\n", MAX_IEDS);
        return -1;
    }

    IedInstance *inst = &mgr->ieds[mgr->num_ieds];
    strncpy(inst->ied_name, ied_name, sizeof(inst->ied_name) - 1);
    strncpy(inst->ip, ip, sizeof(inst->ip) - 1);
    inst->port = port;
    inst->model = model;
    inst->server = NULL;
    inst->running = 0;

    /* Propagate GOOSE interface to each IED instance */
    if (mgr->goose_interface) {
        strncpy(inst->goose_interface, mgr->goose_interface,
                sizeof(inst->goose_interface) - 1);
    }

    mgr->num_ieds++;
    return 0;
}

/* ---- Start all ---- */
void ied_manager_start_all(IedManager *mgr) {
    printf("\n[MANAGER] Starting %d IED servers...\n", mgr->num_ieds);
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║   IED Name       IP              Port   Status      ║\n");
    printf("╠══════════════════════════════════════════════════════╣\n");

    for (int i = 0; i < mgr->num_ieds; i++) {
        IedInstance *inst = &mgr->ieds[i];
        inst->running = 1;

        inst->thread = Thread_create(
            (ThreadExecutionFunction)ied_server_thread, inst, false);
        Thread_start(inst->thread);

        /* Small delay to stagger startup */
        Thread_sleep(100);
    }

    /* Wait a moment for all to start */
    Thread_sleep(500);

    for (int i = 0; i < mgr->num_ieds; i++) {
        IedInstance *inst = &mgr->ieds[i];
        printf("║   %-14s  %-14s  %-5d  %-10s ║\n",
               inst->ied_name, inst->ip, inst->port,
               (inst->server && IedServer_isRunning(inst->server)) ? "RUNNING" : "FAILED");
    }
    printf("╚══════════════════════════════════════════════════════╝\n\n");
}

/* ---- Stop all ---- */
void ied_manager_stop_all(IedManager *mgr) {
    printf("[MANAGER] Stopping all IED servers...\n");
    for (int i = 0; i < mgr->num_ieds; i++) {
        mgr->ieds[i].running = 0;
    }
    /* Wait for threads to finish */
    Thread_sleep(2000);
    printf("[MANAGER] All IED servers stopped.\n");
}

/* ---- Find IED by name ---- */
IedInstance *ied_manager_find(IedManager *mgr, const char *ied_name) {
    for (int i = 0; i < mgr->num_ieds; i++) {
        if (strcmp(mgr->ieds[i].ied_name, ied_name) == 0)
            return &mgr->ieds[i];
    }
    return NULL;
}

/* ---- Print status ---- */
void ied_manager_print_status(IedManager *mgr) {
    printf("\n╔══════════════════════════════════════════════════════╗\n");
    printf("║         IED MANAGER — STATUS                        ║\n");
    printf("╠══════════════════════════════════════════════════════╣\n");
    printf("║ IED Name         IP             Port   Status       ║\n");
    printf("╠══════════════════════════════════════════════════════╣\n");

    for (int i = 0; i < mgr->num_ieds; i++) {
        IedInstance *inst = &mgr->ieds[i];
        const char *status = "STOPPED";
        if (inst->server && IedServer_isRunning(inst->server))
            status = "RUNNING";
        else if (inst->running)
            status = "STARTING";

        printf("║ %-16s %-14s %-6d %-12s ║\n",
               inst->ied_name, inst->ip, inst->port, status);
    }
    printf("╚══════════════════════════════════════════════════════╝\n\n");
}
