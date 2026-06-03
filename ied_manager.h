/* ============================================================
 *  ied_manager.h — Multi-IED instance manager
 *  Spawns independent IedServer threads for each physical IED
 * ============================================================ */
#ifndef IED_MANAGER_H
#define IED_MANAGER_H

#include "iec61850_server.h"
#include "hal_thread.h"
#include <stdint.h>

#define MAX_IEDS 20

/* ---- Per-IED instance ---- */
typedef struct {
    char         ied_name[32];          /* e.g. "E05_BCU"           */
    char         ip[16];                /* bind IP address           */
    int          port;                  /* MMS port (default 102)    */
    char         goose_interface[128];  /* Npcap NIC for GOOSE TX/RX */

    IedServer    server;                /* libiec61850 server handle  */
    IedModel    *model;                 /* static model pointer       */

    Thread       thread;               /* server thread              */
    int          running;              /* thread control flag        */
} IedInstance;

/* ---- Manager context ---- */
typedef struct {
    IedInstance  ieds[MAX_IEDS];
    int          num_ieds;
    char        *goose_interface;  /* Npcap interface for GOOSE  */
} IedManager;

/* ---- API ---- */

/* Initialize the manager (does not start IEDs) */
void ied_manager_init(IedManager *mgr, const char *goose_interface);

/* Add an IED instance (model must be a static model pointer) */
int ied_manager_add(IedManager *mgr, const char *ied_name,
                    const char *ip, int port, IedModel *model);

/* Start all IED servers (each in its own thread) */
void ied_manager_start_all(IedManager *mgr);

/* Stop all IED servers */
void ied_manager_stop_all(IedManager *mgr);

/* Find an IED instance by name */
IedInstance *ied_manager_find(IedManager *mgr, const char *ied_name);

/* Print status of all IED instances */
void ied_manager_print_status(IedManager *mgr);

#endif /* IED_MANAGER_H */
