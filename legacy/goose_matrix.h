/* ============================================================
 *  goose_matrix.h — GOOSE Subscriber Matrix
 *  Receives GOOSE from all IEDs and drives inter-trip actions
 * ============================================================ */
#ifndef GOOSE_MATRIX_H
#define GOOSE_MATRIX_H

#include "iec61850_server.h"
#include "goose_receiver.h"
#include "goose_subscriber.h"
#include "fault_engine.h"
#include "ied_manager.h"

/* ============================================================
 *  AppID table — from CID files (decimal values)
 *  GoCbRef format: {IED_NAME}{LD_INST}/LLN0$GO$gcb{GoCBName}
 * ============================================================
 *
 *  IED          LD inst       GoCB name         AppID
 *  E01_BCU      E01BCU        gcbE01BCU          4097 (0x1001)
 *  E02_BCU      E02BCU        gcbE02BCU          4097 (0x1001)  <- same AppID, diff MAC
 *  E03_BCU      E03BCU        gcbE03BCU          4097
 *  E04_BCU      E04BCU        gcbE04BCU          4097
 *  E05_BCU      E05BCU        gcbE05BCU          4097
 *  E06_BCU      E06BCU        gcbE06BCU          4097
 *  E00_P746     E00P746Z1     gcbE00P746Z1       4097 (same as BCU — use GoCbRef to distinguish)
 *  E00_P746     E00P746Z2     gcbE00P746Z2       4098 (0x1002)
 *  E00_P746     E00P746CZ     gcbE00P746CZ       4099 (0x1003)
 *
 *  Datasets:
 *  BCU  SwitchStatus : [0] XCBR1.Pos.stVal (Dbpos), [1] XCBR1.Pos.q, [2] CSWI1.Pos.stVal
 *  P746 BBTrip       : [0] PDIF1.Op.general (BOOLEAN), [1] RBRF1.OpEx.general (BOOLEAN)
 * ============================================================ */

/* Initialize the full GOOSE subscriber matrix.
 * All subscriptions are registered on 'receiver'.
 * 'eng' is used for protection state tracking (fault injection).
 * 'mgr' is used to find per-IED servers for model updates. */
void goose_matrix_init(GooseReceiver receiver,
                       FaultEngine  *eng,
                       IedManager   *mgr);

#endif /* GOOSE_MATRIX_H */
