/* ============================================================
 *  ied_server_base.h — Reusable IED server skeleton
 *  Each per-IED executable calls ied_server_run() with its
 *  compiled static model and a protection tick callback.
 * ============================================================ */
#ifndef IED_SERVER_BASE_H
#define IED_SERVER_BASE_H

#include "iec61850_server.h"
#include "ied_config.h"
#include <stdint.h>

/* ---- Protection tick callback ----
 * Called periodically by the main loop.
 * The IED-specific logic (distance, diff, OC) implements this. */
typedef void (*ProtectionTickFn)(IedServer server, IedModel *model,
                                 const IedConfig *cfg, uint64_t now_ms,
                                 void *ctx);

/* ---- Console command callback (optional) ----
 * Handles IED-specific console commands (e.g. "inject ph-e 1").
 * Return 1 if handled, 0 if not recognized. */
typedef int (*ConsoleCommandFn)(IedServer server, IedModel *model,
                                const IedConfig *cfg, const char *cmd,
                                void *ctx);

/* ---- Run the IED server ----
 * This is the main entry point for every per-IED executable.
 * It handles the full lifecycle:
 *   1. Load JSON config
 *   2. Set GOOSE interface
 *   3. Start MMS server
 *   4. Enable GOOSE publishing
 *   5. Register GOOSE subscriptions
 *   6. Run main loop calling tick_fn
 *   7. Graceful shutdown on SIGINT
 *
 * Returns 0 on clean exit, -1 on error. */
int ied_server_run(IedModel *model,
                   const char *config_path,
                   ProtectionTickFn tick_fn,
                   ConsoleCommandFn cmd_fn,
                   void *ctx);

#endif /* IED_SERVER_BASE_H */
