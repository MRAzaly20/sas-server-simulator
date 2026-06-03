# Multi-Executable IED Architecture — GI 150kV ANTAM POMALAA

Refactor into **18 independent executables** matching the real substation architecture. Each IED gets its own folder, JSON config, and autonomous protection loop.

## User Review Required

> [!IMPORTANT]
> **Folder structure change:** Per the task requirement, each IED now lives in a structured folder under `bays/`. The shared base library stays in `sas_server/`. This replaces the flat layout.

> [!IMPORTANT]
> **Scope:** This plan covers the **18 IEDs on the 150kV side** (7 BCUs, 3 P643, 5 P142, 1 P143, 2 P543, 3 P746 zones) — **not** the 30kV feeders, energy meters (ION 8650), or REG-DA units, which can be added later.

---

## Proposed Folder Structure

```
sas_server/
├── shared/                     # Shared base library
│   ├── ied_server_base.h/c     # Server lifecycle skeleton
│   ├── ied_config.h/c          # JSON config loader
│   ├── goose_handler.h/c       # Per-IED GOOSE sub/pub
│   └── cJSON.h/c               # JSON parser (MIT)
│
├── ieds/                       # Static models (CID-generated .c/.h)
│   ├── E01_BCU.c/h, E01_P643.c/h, E01_P142.c/h
│   ├── E02_BCU.c/h, E02_P643.c/h, E02_P142.c/h
│   ├── E03_BCU.c/h, E03_P643.c/h, E03_P142.c/h
│   ├── E04_BCU.c/h, E04_P143.c/h
│   ├── E05_BCU.c/h, E05_P543.c/h, E05_P142.c/h
│   ├── E06_BCU.c/h, E06_P543.c/h, E06_P142.c/h
│   └── E00_P746.c/h
│
├── bays/                       # Per-bay structured folders
│   ├── E01_TRF1/               # Transformer Bay 1
│   │   ├── E01_BCU.c           # C264 BCU main (XCBR, CSWI, interlocking)
│   │   ├── E01_P643.c          # P643 Differential main (87T, 87REF)
│   │   ├── E01_P142.c          # P142 Overcurrent main (50/51)
│   │   ├── config/
│   │   │   ├── E01_BCU.json
│   │   │   ├── E01_P643.json
│   │   │   └── E01_P142.json
│   │   └── README.md
│   ├── E02_TRF2/               # Transformer Bay 2 (identical to E01)
│   ├── E03_TRF3/               # Transformer Bay 3 (identical to E01)
│   ├── E04_COUPLER/            # Bus Coupler Bay
│   │   ├── E04_BCU.c
│   │   ├── E04_P143.c
│   │   └── config/
│   ├── E05_LINE1/              # Line-1 Bay
│   │   ├── E05_BCU.c
│   │   ├── E05_P543.c          # ← Already implemented
│   │   ├── E05_P142.c
│   │   └── config/
│   ├── E06_LINE2/              # Line-2 Bay
│   │   ├── E06_BCU.c
│   │   ├── E06_P543.c
│   │   ├── E06_P142.c
│   │   └── config/
│   └── E00_BUSBAR/             # Busbar Protection
│       ├── E00_P746.c          # P746×3 zones in one exe
│       └── config/
│
├── CMakeLists.txt              # Builds all 18 executables
└── launch_all.bat              # Starts all 18 processes
```

---

## Proposed Changes

### Shared Base Library (already created)

| Status | File | Purpose |
|---|---|---|
| ✅ Done | [ied_server_base.h/c](file:///c:/goose/sas_server/ied_server_base.c) | Server lifecycle: config → GOOSE NIC → MMS start → GOOSE pub → tick loop |
| ✅ Done | [ied_config.h/c](file:///c:/goose/sas_server/ied_config.c) | JSON config loader using cJSON |
| ✅ Done | [goose_handler.h/c](file:///c:/goose/sas_server/goose_handler.c) | Config-driven GOOSE subscriber with action dispatch |
| ✅ Done | [cJSON.h/c](file:///c:/goose/sas_server/cJSON.c) | MIT-licensed JSON parser |

---

### Per-IED Executables (by IED type)

#### P543 Distance Relay (E05, E06) — ✅ Done
- [ied_p543_distance.c](file:///c:/goose/sas_server/ied_p543_distance.c) — PDIS 4 zones, PTRC trip, RREC auto-reclose, MMXU analogs

#### [NEW] C264 Bay Control Unit (E01–E06 BCU)
- `ied_c264_bcu.c` — XCBR/CSWI control, GOOSE interlock subscriber, CB status publisher
- Subscribes to: P746 busbar trip (intertrip), protection IED trip signals
- Publishes: SwitchStatus dataset (XCBR1.Pos, CSWI1.Pos)

#### [NEW] P643 Transformer Differential (E01–E03)
- `ied_p643_diff.c` — 87T biased differential, 87REF restricted earth fault
- No auto-reclose (transformer faults → lockout per standard)
- Publishes: DiffTrip dataset

#### [NEW] P142/P143 Overcurrent Backup (all bays)
- `ied_p142_overcurrent.c` — 50/51/50N/51N with IDMT curves
- Reused for P143 (same protection functions)

#### [NEW] P746 Busbar Protection (E00)
- `ied_p746_busbar.c` — 3 zones (Zone 1, Zone 2, Check Zone)
- 87B sum-of-currents differential
- 50BF breaker failure monitoring
- Publishes: BBTrip Z1/Z2/CZ GOOSE
- Subscribes to: all 6 BCU SwitchStatus for CBF

---

### Build System

#### [MODIFY] [CMakeLists.txt](file:///c:/goose/sas_server/CMakeLists_ied.txt)

Extend `add_ied_exe()` function to reference bay folder mains:
```cmake
# Transformer Bay E01
add_ied_exe(E01_BCU   bays/E01_TRF1/E01_BCU.c   E01_BCU.c   model_E01_BCU)
add_ied_exe(E01_P643  bays/E01_TRF1/E01_P643.c  E01_P643.c  model_E01_P643)
add_ied_exe(E01_P142  bays/E01_TRF1/E01_P142.c  E01_P142.c  model_E01_P142)
# ... 18 total targets
```

---

## Verification Plan

### Build
```bash
cmake .. -G "MinGW Makefiles" && mingw32-make -j4
# Expected: 18 .exe files
```

### MMS per-IED
```bash
iec61850_client.exe 127.0.0.1 10251  # E05_P543
iec61850_client.exe 127.0.0.1 10201  # E01_BCU
```

### GOOSE (Wireshark `eth.type == 0x88b8`)
- 9 distinct GoCBRef streams with heartbeats

### Autonomous Protection
```
# E05_P543 console: inject ph-e 1
# → Zone 1 START → TRIP → CB open → GOOSE published
```

### Busbar Intertrip
```
# E00_P746 console: inject bb-z1
# → GOOSE BBTrip Z1 → E01-E05 BCUs all open CBs
```
