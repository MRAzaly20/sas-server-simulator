/* ============================================================
 *  sas_server.c — IEC 61850 MMS Server for GI 150kV ANTAM POMALAA
 *  Simulates 9 bays / 25 Logical Devices with fault injection
 * ============================================================ */
#include "iec61850_server.h"
#include "hal_thread.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "static_model.h"
#include "fault_engine.h"
#include "goose_matrix.h"
#include "goose_receiver.h"

static int running = 0;
static IedServer iedServer = NULL;
static FaultEngine faultEngine;
static GooseReceiver gooseReceiver = NULL;

/* ---- Signal handler ---- */
void sigint_handler(int signalId) {
    running = 0;
}

/* ---- Control handler for all XCBR/CSWI/XSWI DOs ---- */
static ControlHandlerResult
controlHandler(ControlAction action, void *param, MmsValue *value, bool test) {
    if (test) return CONTROL_RESULT_OK;

    const char *objRef = ControlAction_getControlObject(action) ? 
        ModelNode_getObjectReference((ModelNode*)ControlAction_getControlObject(action), NULL) : "unknown";


    /* Get the controlled DO reference */
    char ref[256];
    strncpy(ref, ControlAction_getControlObject(action) ?
            ModelNode_getObjectReference(
                (ModelNode*)ControlAction_getControlObject(action), NULL) : "unknown",
            sizeof(ref) - 1);

    printf("[CONTROL] Operate: %s = %s\n", ref,
           MmsValue_getBoolean(value) ? "ON(Close)" : "OFF(Open)");

    return CONTROL_RESULT_OK;
}

/* ---- Thread for reading console commands ---- */
#ifdef _WIN32
#include <windows.h>
#include <conio.h>

static void console_reader_thread(void *param) {
    FaultEngine *eng = (FaultEngine*)param;
    char line[256];

    printf("\n");
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║  GI 150kV ANTAM POMALAA — SAS Fault Simulator   ║\n");
    printf("║  Type 'help' for commands, 'quit' to exit       ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    printf("\nSAS> ");
    fflush(stdout);

    while (running) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            /* Trim newline */
            size_t len = strlen(line);
            if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
            if (len > 1 && line[len-2] == '\r') line[len-2] = '\0';

            if (strlen(line) == 0) { printf("SAS> "); fflush(stdout); continue; }
            if (strcmp(line, "quit") == 0 || strcmp(line, "exit") == 0) {
                running = 0;
                break;
            }
            if (!fault_engine_parse_command(eng, line)) {
                printf("Unknown command: '%s'. Type 'help' for usage.\n", line);
            }
            printf("SAS> ");
            fflush(stdout);
        }
    }
}
#endif

/* ---- Main ---- */
int main(int argc, char **argv) {
    int tcpPort = 102;
    char *gooseIf = NULL;

    if (argc > 1) tcpPort = atoi(argv[1]);
    if (argc > 2) gooseIf = argv[2];

    printf("═══════════════════════════════════════════════════\n");
    printf("  GI 150kV ANTAM POMALAA — SAS Simulator Server\n");
    printf("  IEC 61850 MMS Server + Fault Simulation Engine\n");
    printf("═══════════════════════════════════════════════════\n\n");

    /* Create server with static model */
    IedServerConfig config = IedServerConfig_create();
    iedServer = IedServer_createWithConfig(&iedModel, NULL, config);
    IedServer_setLocalIpAddress(iedServer, "127.0.0.1");
    IedServerConfig_destroy(config);

    if (gooseIf) {
        printf("[SERVER] Using GOOSE interface: %s\n", gooseIf);
        IedServer_setGooseInterfaceId(iedServer, gooseIf);
    }

    /* Start MMS server */
    IedServer_start(iedServer, tcpPort);

    if (!IedServer_isRunning(iedServer)) {
        printf("[SERVER] ERROR: Failed to start on port %d\n", tcpPort);
        IedServer_destroy(iedServer);
        return 1;
    }

    printf("[SERVER] MMS server started on port %d\n", tcpPort);
    printf("[SERVER] Logical Devices: 25 (bays E01-E06 + E00 busbar/IO/metering)\n");

    /* Enable GOOSE publishing */
    IedServer_enableGoosePublishing(iedServer);
    printf("[SERVER] GOOSE publishing enabled\n");

    /* Initialize fault engine */
    fault_engine_init(&faultEngine, iedServer, (IedModel*)&iedModel);
    fault_engine_print_status(&faultEngine);

    /* Initialize GOOSE Receiver */
    gooseReceiver = GooseReceiver_create();
    if (gooseIf) {
        GooseReceiver_setInterfaceId(gooseReceiver, gooseIf);
        printf("[SERVER] GOOSE Receiver using interface: %s\n", gooseIf);
    } else {
        printf("[SERVER] GOOSE Receiver using default interface.\n");
    }
    goose_matrix_init(gooseReceiver, &faultEngine);
    GooseReceiver_start(gooseReceiver);
    printf("[SERVER] GOOSE Receiver started\n");

    /* Start console reader thread */
    running = 1;
    signal(SIGINT, sigint_handler);

    #ifdef _WIN32
    Thread consoleThread = Thread_create((ThreadExecutionFunction)console_reader_thread,
                                         &faultEngine, false);
    Thread_start(consoleThread);
    #endif

    /* Main loop — tick fault engine + update simulated values */
    printf("[SERVER] Main loop running (1s cycle)...\n\n");

    while (running) {
        uint64_t now = Hal_getTimeInMs();
        fault_engine_tick(&faultEngine, now);
        Thread_sleep(1000);
    }

    printf("\n[SERVER] Shutting down...\n");

    if (gooseReceiver) {
        GooseReceiver_stop(gooseReceiver);
        GooseReceiver_destroy(gooseReceiver);
    }
    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);

    printf("[SERVER] Stopped.\n");
    return 0;
}
