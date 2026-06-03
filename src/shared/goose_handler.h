/* ============================================================
 *  goose_handler.h — Per-IED GOOSE subscriber/publisher logic
 *  Each IED only subscribes to the streams it needs.
 * ============================================================ */
#ifndef GOOSE_HANDLER_H
#define GOOSE_HANDLER_H

#include "iec61850_server.h"
#include "goose_receiver.h"
#include "goose_subscriber.h"
#include "ied_config.h"
#include "ied_server_base.h"

/* Initialize GOOSE receiver with subscriptions from config.
 * Returns the GooseReceiver handle (caller owns it), or NULL on failure. */
GooseReceiver goose_handler_init(const IedConfig *cfg,
                                 IedServer server,
                                 IedModel *model,
                                 ConsoleCommandFn cmd_fn,
                                 void *ctx_ptr);

/* Stop and destroy the GOOSE receiver */
void goose_handler_cleanup(GooseReceiver receiver);

#endif /* GOOSE_HANDLER_H */
