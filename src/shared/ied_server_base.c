/* ============================================================
 *  ied_server_base.c — Reusable IED server skeleton implementation
 *  Handles MMS server lifecycle, GOOSE pub/sub, and main loop.
 * ============================================================ */
#include "ied_server_base.h"
#include "goose_handler.h"
#include "hal_thread.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static volatile int g_running = 0;

static void sigint_handler(int sig) {
    (void)sig;
    g_running = 0;
}

/* ---- Console reader thread ---- */
typedef struct {
    IedServer          server;
    IedModel          *model;
    const IedConfig   *cfg;
    ConsoleCommandFn   cmd_fn;
    void              *ctx;
} ConsoleCtx;

#ifdef _WIN32
#include <windows.h>
static void console_thread_fn(void *param) {
    ConsoleCtx *c = (ConsoleCtx *)param;
    char line[256];

    printf("\nSAS [%s]> ", c->cfg->ied_name);
    fflush(stdout);

    while (g_running) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            size_t len = strlen(line);
            if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';
            if (len > 1 && line[len-2] == '\r') line[len-2] = '\0';

            if (strlen(line) == 0) {
                printf("SAS [%s]> ", c->cfg->ied_name);
                fflush(stdout);
                continue;
            }
            if (strcmp(line, "quit") == 0 || strcmp(line, "exit") == 0) {
                g_running = 0;
                break;
            }
            if (strcmp(line, "help") == 0) {
                printf("  quit/exit  — Stop this IED server\n");
                printf("  status     — Show IED status\n");
                if (c->cmd_fn)
                    printf("  (IED-specific commands available)\n");
            } else if (strcmp(line, "status") == 0) {
                printf("  IED:    %s\n", c->cfg->ied_name);
                printf("  MMS:    %s:%d\n", c->cfg->ip, c->cfg->port);
                printf("  GOOSE:  %s\n",
                       c->cfg->goose_interface[0] ? c->cfg->goose_interface : "(none)");
                printf("  Type:   %s\n", c->cfg->prot.type);
            } else if (c->cmd_fn) {
                if (!c->cmd_fn(c->server, c->model, c->cfg, line, c->ctx)) {
                    printf("Unknown command: '%s'. Type 'help'.\n", line);
                }
            } else {
                printf("Unknown command: '%s'. Type 'help'.\n", line);
            }
            printf("SAS [%s]> ", c->cfg->ied_name);
            fflush(stdout);
        }
    }
}
#endif

/* ---- Main server lifecycle ---- */
int ied_server_run(IedModel *model,
                   const char *config_path,
                   ProtectionTickFn tick_fn,
                   ConsoleCommandFn cmd_fn,
                   void *ctx)
{
    IedConfig cfg;

    /* 1. Load config */
    if (ied_config_load(&cfg, config_path) != 0) {
        printf("[ERROR] Failed to load config: %s\n", config_path);
        return -1;
    }

    printf("\n");
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║  GI 150kV ANTAM POMALAA — IED Server                ║\n");
    printf("║  %-48s  ║\n", cfg.ied_name);
    printf("║  Type: %-42s  ║\n", cfg.prot.type);
    printf("╚══════════════════════════════════════════════════════╝\n\n");

    /* 2. Create IED server */
    IedServerConfig srvConfig = IedServerConfig_create();
    IedServer server = IedServer_createWithConfig(model, NULL, srvConfig);
    IedServerConfig_destroy(srvConfig);

    if (!server) {
        printf("[ERROR] Failed to create IedServer for %s\n", cfg.ied_name);
        return -1;
    }

    /* 3. Set GOOSE interface BEFORE start (per libiec61850 API order) */
    if (cfg.goose_interface[0] != '\0') {
        IedServer_setGooseInterfaceId(server, cfg.goose_interface);
        printf("[%s] GOOSE interface: %s\n", cfg.ied_name, cfg.goose_interface);
    }

    /* 4. Bind IP and start MMS */
    IedServer_setLocalIpAddress(server, cfg.ip);
    IedServer_start(server, cfg.port);

    if (!IedServer_isRunning(server)) {
        printf("[ERROR] Failed to start MMS on %s:%d\n", cfg.ip, cfg.port);
        IedServer_destroy(server);
        return -1;
    }
    printf("[%s] MMS server started on %s:%d\n", cfg.ied_name, cfg.ip, cfg.port);

    /* 5. Enable GOOSE publishing (AFTER start) */
    IedServer_enableGoosePublishing(server);
    printf("[%s] GOOSE publishing enabled\n", cfg.ied_name);

    /* 6. Setup GOOSE receiver/subscriptions */
    GooseReceiver gooseRx = NULL;
    if (cfg.goose_interface[0] != '\0' && cfg.num_goose_subs > 0) {
        gooseRx = goose_handler_init(&cfg, server, model, cmd_fn, ctx);
        if (gooseRx) {
            printf("[%s] GOOSE receiver started with %d subscriptions\n",
                   cfg.ied_name, cfg.num_goose_subs);
        }
    }

    /* 7. Main loop */
    g_running = 1;
    signal(SIGINT, sigint_handler);

#ifdef _WIN32
    ConsoleCtx consoleCtx = { server, model, &cfg, cmd_fn, ctx };
    Thread consoleThread = Thread_create(
        (ThreadExecutionFunction)console_thread_fn, &consoleCtx, false);
    Thread_start(consoleThread);
#endif

    printf("[%s] Server running. Type 'help' for commands, Ctrl-C to quit.\n\n",
           cfg.ied_name);

    while (g_running) {
        uint64_t now = Hal_getTimeInMs();
        if (tick_fn)
            tick_fn(server, model, &cfg, now, ctx);
        Thread_sleep(100);  /* 100ms tick */
    }

    /* 8. Shutdown */
    printf("\n[%s] Shutting down...\n", cfg.ied_name);
    if (gooseRx)
        goose_handler_cleanup(gooseRx);
    IedServer_stop(server);
    IedServer_destroy(server);
    printf("[%s] Done.\n", cfg.ied_name);
    return 0;
}
