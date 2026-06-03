/* ============================================================
 *  sas_server_distributed.c — Multi-IED MMS + GOOSE Server
 *  GI 150kV A — 18 IED instances + GOOSE pub/sub
 *
 *  Usage:
 *    sas_distributed.exe [goose_interface]
 *
 *    goose_interface  Npcap device name for GOOSE TX/RX.
 *                     Example on Windows (run as Admin):
 *                       "\Device\NPF_{XXXXXXXX-...}"
 *                     Omit for MMS-only mode (no GOOSE on wire).
 * ============================================================ */
#include "ied_manager.h"
#include "fault_engine.h"
#include "goose_matrix.h"
#include "goose_receiver.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ---- Import all per-IED static models ---- */
extern IedModel model_E01_BCU;
extern IedModel model_E01_P643;
extern IedModel model_E01_P142;
extern IedModel model_E02_BCU;
extern IedModel model_E02_P643;
extern IedModel model_E02_P142;
extern IedModel model_E03_BCU;
extern IedModel model_E03_P643;
extern IedModel model_E03_P142;
extern IedModel model_E04_BCU;
extern IedModel model_E04_P143;
extern IedModel model_E05_BCU;
extern IedModel model_E05_P543;
extern IedModel model_E05_P142;
extern IedModel model_E06_BCU;
extern IedModel model_E06_P543;
extern IedModel model_E06_P142;
extern IedModel model_E00_P746;

static volatile int running = 0;
static IedManager   iedManager;
static FaultEngine  faultEngine;
static GooseReceiver gooseReceiver = NULL;

/* ---- Signal handler ---- */
void sigint_handler(int signalId) {
    (void)signalId;
    running = 0;
}

/* ---- IED definition table: name, IP, port, model ---- */
typedef struct {
    const char *ied_name;
    const char *ip;
    int port;
    IedModel *model;
} IedDef;

static IedDef ied_defs[] = {
    /* Bay E01 — Transformer */
    {"E01_BCU",  "127.0.0.1", 10201, &model_E01_BCU},
    {"E01_P643", "127.0.0.1", 10211, &model_E01_P643},
    {"E01_P142", "127.0.0.1", 10212, &model_E01_P142},
    /* Bay E02 — Transformer */
    {"E02_BCU",  "127.0.0.1", 10202, &model_E02_BCU},
    {"E02_P643", "127.0.0.1", 10221, &model_E02_P643},
    {"E02_P142", "127.0.0.1", 10222, &model_E02_P142},
    /* Bay E03 — Transformer */
    {"E03_BCU",  "127.0.0.1", 10203, &model_E03_BCU},
    {"E03_P643", "127.0.0.1", 10231, &model_E03_P643},
    {"E03_P142", "127.0.0.1", 10232, &model_E03_P142},
    /* Bay E04 — Bus Coupler */
    {"E04_BCU",  "127.0.0.1", 10204, &model_E04_BCU},
    {"E04_P143", "127.0.0.1", 10241, &model_E04_P143},
    /* Bay E05 — Line */
    {"E05_BCU",  "127.0.0.1", 10205, &model_E05_BCU},
    {"E05_P543", "127.0.0.1", 10251, &model_E05_P543},
    {"E05_P142", "127.0.0.1", 10252, &model_E05_P142},
    /* Bay E06 — Line */
    {"E06_BCU",  "127.0.0.1", 10206, &model_E06_BCU},
    {"E06_P543", "127.0.0.1", 10261, &model_E06_P543},
    {"E06_P142", "127.0.0.1", 10262, &model_E06_P142},
    /* Station level — Busbar Protection */
    {"E00_P746", "127.0.0.1", 10200, &model_E00_P746},
};

#define NUM_IEDS (sizeof(ied_defs)/sizeof(ied_defs[0]))

/* ---- Console reader thread (Windows) ---- */
#ifdef _WIN32
#include <windows.h>

static void console_reader_thread(void *param) {
    (void)param;
    char line[256];

    printf("\n");
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║  GI 150kV A — Distributed SAS Simulator ║\n");
    printf("║  %2d IEDs | MMS + GOOSE Pub/Sub active              ║\n", (int)NUM_IEDS);
    printf("║  Type 'help' for commands, 'quit' to exit           ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    printf("\nSAS> ");
    fflush(stdout);

    while (running) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            size_t len = strlen(line);
            if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
            if (len > 1 && line[len-2] == '\r') line[len-2] = '\0';

            if (strlen(line) == 0) { printf("SAS> "); fflush(stdout); continue; }
            if (strcmp(line, "quit") == 0 || strcmp(line, "exit") == 0) {
                running = 0; break;
            }
            if (strcmp(line, "ieds") == 0) {
                ied_manager_print_status(&iedManager);
            } else if (!fault_engine_parse_command(&faultEngine, line)) {
                printf("Unknown command: '%s'. Type 'help' for usage.\n", line);
            }
            printf("SAS> ");
            fflush(stdout);
        }
    }
}
#endif /* _WIN32 */

/* ---- Main ---- */
int main(int argc, char **argv) {
    /* argv[1] = optional GOOSE interface.
     *   Windows: adapter number from find.exe (e.g. "4")
     *   Linux:   interface name (e.g. "eth0")               */
    const char *goose_interface = (argc > 1) ? argv[1] : NULL;

    printf("═══════════════════════════════════════════════════════\n");
    printf("  GI 150kV A — Distributed SAS Simulator\n");
    printf("  %d IED instances (multi-threaded MMS servers)\n", (int)NUM_IEDS);
    if (goose_interface)
        printf("  GOOSE interface: %s\n", goose_interface);
    else
        printf("  GOOSE interface: not set (MMS-only, no wire GOOSE)\n");
    printf("  Usage: %s [interface_number]\n", argv[0]);
    printf("    Run find.exe to list available adapters.\n");
    printf("═══════════════════════════════════════════════════════\n\n");

    /* -----------------------------------------------------------
     * 1. Initialize IED Manager and register all IEDs
     * ----------------------------------------------------------- */
    ied_manager_init(&iedManager, goose_interface);

    for (int i = 0; i < (int)NUM_IEDS; i++) {
        ied_manager_add(&iedManager,
                        ied_defs[i].ied_name,
                        ied_defs[i].ip,
                        ied_defs[i].port,
                        ied_defs[i].model);
    }

    /* -----------------------------------------------------------
     * 2. Start all IED MMS servers (each in own thread)
     *    + enables GOOSE publishing + sets GOOSE interface per IED
     * ----------------------------------------------------------- */
    ied_manager_start_all(&iedManager);

    /* -----------------------------------------------------------
     * 3. Initialize fault engine in distributed mode
     *    Each bay gets its own server/model references
     * ----------------------------------------------------------- */
    fault_engine_init_distributed(&faultEngine, &iedManager);
    fault_engine_print_status(&faultEngine);

    /* -----------------------------------------------------------
     * 4. Initialize GOOSE Receiver (subscriber side)
     *    One shared GooseReceiver captures all incoming GOOSE
     * ----------------------------------------------------------- */
    gooseReceiver = GooseReceiver_create();

    if (goose_interface) {
        GooseReceiver_setInterfaceId(gooseReceiver, goose_interface);
        printf("[GOOSE] Receiver using interface: %s\n", goose_interface);
    } else {
        printf("[GOOSE] Receiver: no GOOSE interface set (subscriptions inactive)\n");
    }

    /* Register all 9 GOOSE subscriptions */
    goose_matrix_init(gooseReceiver, &faultEngine, &iedManager);

    /* Start raw socket capture thread — only if we have a valid interface */
    if (goose_interface) {
        GooseReceiver_start(gooseReceiver);
        printf("[GOOSE] Receiver started (%s)\n",
               GooseReceiver_isRunning(gooseReceiver) ? "OK" : "FAILED");
    } else {
        printf("[GOOSE] Receiver NOT started (no NIC — MMS-only mode)\n");
    }

    /* -----------------------------------------------------------
     * 5. Main loop
     * ----------------------------------------------------------- */
    running = 1;
    signal(SIGINT, sigint_handler);

#ifdef _WIN32
    Thread consoleThread = Thread_create(
        (ThreadExecutionFunction)console_reader_thread, NULL, false);
    Thread_start(consoleThread);
#endif

    printf("[SERVER] All %d IED instances active. Main loop running (1s tick)...\n\n",
           (int)NUM_IEDS);

    while (running) {
        uint64_t now = Hal_getTimeInMs();
        fault_engine_tick(&faultEngine, now);
        Thread_sleep(1000);
    }

    /* -----------------------------------------------------------
     * 6. Graceful shutdown
     * ----------------------------------------------------------- */
    printf("\n[SERVER] Shutting down...\n");

    if (gooseReceiver) {
        GooseReceiver_stop(gooseReceiver);
        GooseReceiver_destroy(gooseReceiver);
    }

    ied_manager_stop_all(&iedManager);
    printf("[SERVER] Done.\n");
    return 0;
}
