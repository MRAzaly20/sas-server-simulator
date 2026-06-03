/* ============================================================
 *  gse_stubs.c — Stub GSEControlBlock definitions
 *  genmodel could not resolve GSE entries in per-IED CIDs
 *  due to a parser bug. These stubs satisfy the linker.
 *  Phase 3 will replace these with real GOOSE wiring.
 * ============================================================ */
#include "iec61850_server.h"

/* BCU GOOSE stubs */
GSEControlBlock model_E01_BCU_E01BCU_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
GSEControlBlock model_E02_BCU_E02BCU_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
GSEControlBlock model_E03_BCU_E03BCU_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
GSEControlBlock model_E04_BCU_E04BCU_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
GSEControlBlock model_E05_BCU_E05BCU_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
GSEControlBlock model_E06_BCU_E06BCU_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};

/* Busbar P746 GOOSE stubs */
GSEControlBlock model_E00_P746_E00P746Z1_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
GSEControlBlock model_E00_P746_E00P746Z2_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
GSEControlBlock model_E00_P746_E00P746CZ_LLN0_gse0 = {NULL, NULL, NULL, NULL, 0, false, NULL, 0, 0};
