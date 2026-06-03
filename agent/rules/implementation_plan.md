# GI 150kV ANTAM POMALAA — SAS Simulator, CID Generation & Fault Engine

Build a functional IEC 61850 MMS server simulating the complete ANTAM POMALAA substation (9 bays, 33 IEDs), a comprehensive CID file with all data models, and a fault simulation engine that drives protection logic and GOOSE publishing.

## User Review Required

> [!IMPORTANT]
> **Scope**: This plan produces a SINGLE combined IED server (not 33 separate servers) to simulate the entire substation. Each real IED (C264, P543, P643, etc.) becomes a Logical Device within one IEC 61850 server. This keeps the simulator manageable while faithfully representing the data model.

> [!WARNING]
> **GOOSE on Windows**: GOOSE publishing requires raw Ethernet sockets. On Windows, this needs WinPcap/Npcap. The server will compile and run MMS services regardless, but GOOSE publishing may require Npcap to be installed. The fault engine will update MMS data attributes with or without GOOSE.

## Proposed Changes

### Component 1: CID File — Complete ANTAM POMALAA Data Model

Generates a single comprehensive CID file representing the entire substation.

---

#### [NEW] [antam_pomalaa.cid](file:///c:/goose/iec61850-client/config/antam_pomalaa.cid)

**Substation Section:**
- `Substation name="GI_ANTAM_POMALAA"` with `VoltageLevel` 150kV
- 6 bays (=E01–E06) mapped as `Bay` elements with `ConductingEquipment` (CBR, DIS, CTR)

**Communication Section:**
- MMS SubNetwork (8-MMS): one `ConnectedAP` with IP `10.0.0.100`
- GOOSE SubNetwork (8-GOOSE): per-bay `GSE` entries with unique MAC/APPID for trip, status, and interlock GOOSE messages

**IED Section — Logical Devices:**

| LD inst | Real IED | LN Classes |
|---|---|---|
| `E01_BCU` | C264 TRF-1 Control | LLN0, LPHD, XCBR1, CSWI1, XSWI1-3, GGIO1 |
| `E01_P643` | P643 TRF-1 Diff | LLN0, LPHD, PDIF1, PTRC1, PTOV1, PHIZ1 |
| `E01_P142HV` | P142 TRF-1 HV | LLN0, LPHD, PTOC1-2, PTOC3-4 (N), PTRC1 |
| `E01_P142LV` | P142 TRF-1 LV | LLN0, LPHD, PTOC1-2, PTOC3-4 (N), PTRC1 |
| `E02_BCU` | C264 TRF-2 Control | (same as E01_BCU) |
| `E02_P643` | P643 TRF-2 Diff | (same as E01_P643) |
| `E02_P142HV` | P142 TRF-2 HV | (same as E01_P142HV) |
| `E02_P142LV` | P142 TRF-2 LV | (same as E01_P142LV) |
| `E03_BCU` | C264 TRF-3 Control | (same as E01_BCU) |
| `E03_P643` | P643 TRF-3 Diff | (same as E01_P643) |
| `E03_P142HV` | P142 TRF-3 HV | (same as E01_P142HV) |
| `E03_P142LV` | P142 TRF-3 LV | (same as E01_P142LV) |
| `E04_BCU` | C264 Coupler | LLN0, LPHD, XCBR1, CSWI1, XSWI1-2, GGIO1 |
| `E04_P143` | P143 Coupler Prot | LLN0, LPHD, PTOC1-2, PTOC3-4 (N), PTRC1 |
| `E05_BCU` | C264 Line-1 | LLN0, LPHD, XCBR1, CSWI1, XSWI1-2, GGIO1 |
| `E05_P142` | P142 Line-1 Backup | LLN0, LPHD, PTOC1-2, PTOC3-4 (N), PTRC1 |
| `E05_P543` | P543 Line-1 Main | LLN0, LPHD, PDIS1-4, PTRC1, RREC1, RSYN1, MMXU1 |
| `E06_BCU` | C264 Line-2 | (same as E05_BCU) |
| `E06_P142` | P142 Line-2 Backup | (same as E05_P142) |
| `E06_P543` | P543 Line-2 Main | (same as E05_P543) |
| `E00_P746Z1` | P746 BB Zone 1 | LLN0, LPHD, PDIF1, PTRC1, RBRF1, RSYN1 |
| `E00_P746Z2` | P746 BB Zone 2 | (same as E00_P746Z1) |
| `E00_P746CZ` | P746 BB Check | (same as E00_P746Z1) |
| `E00_IO` | C264 Common I/O | LLN0, LPHD, GGIO1 (station aux inputs) |
| `E00_MEAS` | ION 8650 Metering | LLN0, LPHD, MMXU1 (energy metering) |

**DataTypeTemplates** — ~25 LNodeTypes, ~30 DOTypes, ~15 DATypes, ~10 EnumTypes covering:
- XCBR (DPC Pos, SPC BlkOpn/BlkCls), CSWI (DPC Pos), XSWI (DPC Pos)
- PDIS (ACT Op/Str per zone), PTOC (ACT Op/Str), PDIF (ACT Op)
- PTRC (ACT Tr), RREC (ACT Op, INS AutoRecSt), RSYN (SPS RsSyn)
- MMXU (MV TotW/TotVAr/TotVA/Hz, WYE PhV/A), RBRF (ACT Op)
- Standard CDCs: INC, INS, SPS, SPC, DPC, MV, WYE, ACT, ACD, LPL, DPL

---

### Component 2: IEC 61850 MMS Server

The server loads the CID-derived model, serves MMS, handles controls, and publishes GOOSE messages.

---

#### [NEW] [sas_server/](file:///c:/goose/sas_server/) (new directory)

#### [NEW] [CMakeLists.txt](file:///c:/goose/sas_server/CMakeLists.txt)
- Links against libiec61850 static libraries
- Includes fault engine and server source files
- Copies `model.cfg` to build directory

#### [NEW] [sas_server.c](file:///c:/goose/sas_server/sas_server.c)
- Loads model from `model.cfg` via `ConfigFileParser_createModelFromConfigFileEx()`
- Resolves key DataAttribute pointers via `IedModel_getModelNodeByShortObjectReference()`
- Registers `ControlHandler` callbacks for all XCBR/CSWI/XSWI DOs
- Main loop: updates simulated analog values (voltage ≈ 150kV ± noise, current ≈ load, frequency ≈ 50Hz ± drift) every 1 second
- Fault engine integration: calls `fault_engine_tick()` each cycle to process active faults
- GOOSE publishing: `IedServer_enableGoosePublishing()` for trip/status datasets
- Console command interface: type fault commands (e.g., `fault E05 ph-ph zone1`) to inject faults

---

### Component 3: Fault Simulation Engine

A C library implementing protection relay logic based on ANSI functions documented in the architecture.

---

#### [NEW] [fault_engine.h](file:///c:/goose/sas_server/fault_engine.h)

```c
/* Fault types */
typedef enum {
    FAULT_NONE,
    FAULT_PHASE_PHASE,      /* A-B, B-C, C-A */
    FAULT_PHASE_EARTH,      /* A-G, B-G, C-G */
    FAULT_THREE_PHASE,      /* A-B-C */
    FAULT_DOUBLE_EARTH,     /* A-B-G */
    FAULT_BUSBAR_INTERNAL,  /* Zone 1 or Zone 2 bus */
    FAULT_TRANSFORMER_INTERNAL, /* Winding fault */
} FaultType;

/* Protection sequence state */
typedef enum {
    PROT_IDLE,
    PROT_STARTED,       /* Str/pickup */
    PROT_TRIPPED,       /* Op/trip issued */
    PROT_AR_DEAD_TIME,  /* Auto-reclose dead time */
    PROT_AR_SYNC_CHECK, /* Sync check before reclose */
    PROT_AR_RECLOSED,   /* Reclosed, in reclaim time */
    PROT_AR_LOCKOUT,    /* Final trip, lockout */
    PROT_CBF_WAIT,      /* Breaker failure timer */
    PROT_CBF_BACKUP,    /* CBF escalation */
} ProtState;

/* Bay state (one per LD) */
typedef struct {
    const char *bay_id;    /* e.g., "E05" */
    int cb_closed;         /* circuit breaker state */
    int dis_bus_closed;    /* busbar-side disconnector */
    int dis_line_closed;   /* line-side disconnector */
    int earth_closed;      /* earthing switch */
    float v_a, v_b, v_c;  /* phase voltages */
    float i_a, i_b, i_c;  /* phase currents */
    float freq;            /* frequency */
    ProtState prot_state;
    FaultType active_fault;
    uint64_t fault_start_ms;
    int ar_attempts;
} BayState;

/* Engine API */
void fault_engine_init(IedServer server, IedModel *model);
void fault_engine_inject(const char *bay_id, FaultType type, ...);
void fault_engine_tick(uint64_t now_ms);  /* called every cycle */
void fault_engine_clear(const char *bay_id);
```

#### [NEW] [fault_engine.c](file:///c:/goose/sas_server/fault_engine.c)

**Fault injection flow:**
1. `fault_engine_inject("E05", FAULT_PHASE_PHASE)` sets `BayState.active_fault`
2. `fault_engine_tick()` each cycle:
   - If fault active → set fault currents (high magnitude), set PDIS.Str (start)
   - Evaluate zone reach: Zone 1 (~0ms) → immediate trip, Zone 2 (~400ms) → delayed
   - On trip: set PTRC.Tr.general=true, open XCBR.Pos (DPC stVal=01=Open)
   - Update GOOSE trip dataset → triggers multicast burst
   - If RREC enabled (line bays): start dead time → sync check → reclose or lockout
   - If CBF (busbar): monitor CB current after trip, escalate after ~150ms

**Protection logic implemented per bay type:**

| Bay Type | Primary ANSI | Backup ANSI | Auto-Reclose | GOOSE Trip |
|---|---|---|---|---|
| Transformer | 87T, 87REF (P643) | 51, 51N (P142) | No | HV+LV breakers |
| Line | 21 Zones (P543) | 51, 51N (P142) | Yes (79+25) | Own breaker |
| Coupler | 50/51 (P143) | P746 boundary | No | Coupler breaker |
| Busbar | 87B (P746×3) | 50BF escalation | No | All zone breakers |

**Inter-bay GOOSE effects:**
- Busbar fault → trip all breakers in faulted zone
- Transformer diff trip → trip HV + LV side breakers
- Line distance blocking → adjacent P543 blocking signal
- CBF escalation → adjacent breaker backup trip

---

### Component 4: Build Integration

#### [NEW] [run_server.bat](file:///c:/goose/sas_server/run_server.bat)
- Builds and launches the SAS server on port 102

---

## Verification Plan

### Automated Tests

1. **CID Validation**: Run `java -jar genmodel.jar antam_pomalaa.cid` — must produce `model.cfg` without errors.
   ```
   cd c:\goose\libiec61850\tools\model_generator
   java -jar genmodel.jar c:\goose\iec61850-client\config\antam_pomalaa.cid
   ```

2. **Server Build**: CMake build must succeed without errors.
   ```
   cd c:\goose\sas_server
   mkdir build && cd build
   cmake .. -G "MinGW Makefiles"
   cmake --build .
   ```

3. **Server Launch**: Server must start and listen on port 102 without crash.
   ```
   cd c:\goose\sas_server\build
   .\sas_server.exe
   # Expect: "Server started on port 102"
   ```

### Manual Verification

1. **Client Connection**: Launch the existing GTK4 client (`iec61850_client.exe`), connect to `localhost:102`. Verify:
   - All 25 Logical Devices appear in the tree view
   - Expanding any LD shows expected LN classes (XCBR, PDIS, PTRC, MMXU, etc.)
   - Analog values (voltage, current, frequency) update periodically
   - XCBR/CSWI control operations (open/close breaker) succeed

2. **Fault Injection**: In the server console, type `fault E05 ph-ph zone1`. Verify:
   - Console prints protection sequence trace (PDIS Z1 → PTRC trip → XCBR open)
   - Client sees XCBR.Pos change to Open, PTRC.Tr.general = true
   - Auto-reclose sequence visible (dead time → sync check → reclose)
   - Type `fault E01 87T` — verify transformer differential trip

3. **Busbar Fault Escalation**: Type `fault BB zone1`. Verify:
   - All Zone 1 breakers (TRF-1, TRF-2, TRF-3, Line-1, Coupler) open
   - Zone 2 bays not affected
   - Console shows dual-zone check (Zone 1 AND Check Zone required)
