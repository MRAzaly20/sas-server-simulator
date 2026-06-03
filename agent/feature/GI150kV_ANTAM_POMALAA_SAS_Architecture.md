# Substation Automation System (SAS) Architecture Documentation

## GI 150kV ANTAM POMALAA — SAS & CRP

**Document Reference:** E2010-96317-BD-01-SAD
**Project:** GI 150KV ANTAM POMALAA — SAS & CRP
**End User:** PT. ANTAM Tbk.
**Contractor:** PT. High Volt Technology
**Manufacturer:** PT. Schneider Indonesia — Infrastructure Business
**Customer Order No:** 200/HVT-SCHNEIDERINDONESIA/PO/VIII/2023 R1 — dated: 2023-08-14
**Revision:** A | **Date:** 25 September 2023
**Drawn by:** FSR | **Checked by:** HK | **Approved by:** TNN

---

## Table of Contents

1. [System Architecture Overview](#1-system-architecture-overview)
2. [Communication Architecture](#2-communication-architecture)
3. [Station Level Equipment](#3-station-level-equipment)
4. [Bay Level — Complete Bay Inventory](#4-bay-level--complete-bay-inventory)
5. [Transformer Bay 1 — =E01](#5-transformer-bay-1--e01)
6. [Transformer Bay 2 — =E02](#6-transformer-bay-2--e02)
7. [Transformer Bay 3 — =E03](#7-transformer-bay-3--e03)
8. [Coupler Bay — =E04](#8-coupler-bay--e04)
9. [Line-1 Bay — =E05](#9-line-1-bay--e05)
10. [Line-2 Bay — =E06](#10-line-2-bay--e06)
11. [Busbar Protection Panel — =E00+R1](#11-busbar-protection-panel--e00r1)
12. [Common IED I/O Panel — =E00+X3](#12-common-ied-io-panel--e00x3)
13. [Energy Meter Panel — =E00+P1](#13-energy-meter-panel--e00p1)
14. [30kV Feeder Bays — Sheet 005](#14-30kv-feeder-bays--sheet-005)
15. [SCADA &amp; Remote Communication](#15-scada--remote-communication)
16. [IED Equipment Summary](#16-ied-equipment-summary)
17. [ANSI Protection Function Master Reference](#17-ansi-protection-function-master-reference)

---

## 1. System Architecture Overview

### 1.1 Architecture Type

The GI 150kV ANTAM POMALAA Substation Automation System (SAS) implements a **two-level hierarchical IEC 61850-compliant architecture**:

```
┌──────────────────────────────────────────────────────────────────────────┐
│                         STATION LEVEL                                    │
│                                                                          │
│   ┌──────────────┐      ┌──────────────┐     ┌────────┐   ┌───────────┐  │ 
│   │  SAS PANEL 1 │      │  SAS PANEL 2 │     │  SCADA │   │ENGINEERING│  │
│   │  =E00+X1     │      │  =E00+X2     │     │GATEWAY │   │WORKSTATION│  │
│   │  SVR1 / OWS1 │      │  SVR2 / OWS2 │     │SAITEL  │   │ LAPTOP    │  │
│   │  SW1         │      │  SW2         │     │  DP    │   └───────────┘  │
│   └──────┬───────┘      └──────┬───────┘     └────────┘                  │
│          │                     │                                         │
│          └──────────┬──────────┘                                         │
│                     │  IEC 61850                                         │
│              Fiber Optical Ring                                          │
└─────────────────────┬────────────────────────────────────────────────────┘
                      │
┌─────────────────────┴────────────────────────────────────────────────────┐
│                          BAY LEVEL                                       │
│                                                                          │
│  ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐          │
│  │ =E01 │ │ =E02 │ │ =E03 │ │ =E04 │ │ =E05 │ │ =E06 │ │=E00  │          │
│  │TRF-1 │ │TRF-2 │ │TRF-3 │ │CPLR  │ │LINE-1│ │LINE-2│ │+R1   │          │
│  │CTRL  │ │CTRL  │ │CTRL  │ │ C&P  │ │ C&P  │ │ C&P  │ │BUSBAR│          │
│  │PROT  │ │PROT  │ │PROT  │ │      │ │      │ │      │ │PROT  │          │
│  └──────┘ └──────┘ └──────┘ └──────┘ └──────┘ └──────┘ └──────┘          │
└──────────────────────────────────────────────────────────────────────────┘
```

### 1.2 Architecture Key Characteristics

| Parameter                  | Specification                                         |
| -------------------------- | ----------------------------------------------------- |
| Standard                   | IEC 61850 Ed.2                                        |
| Station Bus                | Fiber Optical Ring — IEC 61850 MMS (Station Level)   |
| Bay Bus                    | Fiber Optic — IEC 61850 GOOSE (Bay Level)            |
| Time Synchronisation       | GPS — HOPF 8030HEPTA (PTP/SNTP)                      |
| Redundancy                 | Dual Server (SVR1 + SVR2), Dual Switch (SW1 + SW2)    |
| Remote Protocol (to SCADA) | IEC 60870-5-101 (serial) and IEC 60870-5-104 (TCP/IP) |
| HMI                        | Dual Control Desk with 24" monitors + KVM Extender    |
| Total Bays                 | 9 main bays + 30kV feeder extension                   |

### 1.3 Panel Inventory Summary

| Panel Designation | Panel Name                         | Location     |
| ----------------- | ---------------------------------- | ------------ |
| =E00+X1           | SAS Panel 1                        | Control Room |
| =E00+X2           | SAS Panel 2                        | Control Room |
| =E01+W1           | Transformer-1 Control Panel        | Relay Room   |
| =E01+R1           | Transformer-1 Protection Panel     | Relay Room   |
| =E02+W1           | Transformer-2 Control Panel        | Relay Room   |
| =E02+R1           | Transformer-2 Protection Panel     | Relay Room   |
| =E03+W1           | Transformer-3 Control Panel        | Relay Room   |
| =E03+R1           | Transformer-3 Protection Panel     | Relay Room   |
| =E04+WR1          | Coupler Control & Protection Panel | Relay Room   |
| =E05+WR1          | Line-1 Control & Protection Panel  | Relay Room   |
| =E06+WR1          | Line-2 Control & Protection Panel  | Relay Room   |
| =E00+R1           | Busbar Protection Panel (150kV)    | Relay Room   |
| =E00+X3           | Common IED I/O Panel               | Relay Room   |
| =E00+P1           | 150kV Energy Meter Panel           | Relay Room   |

---

## 2. Communication Architecture

### 2.1 Station Bus — IEC 61850 Fiber Optical Ring

The station-level communication backbone uses a **redundant Fiber Optical Ring** based on IEC 61850. All bay-level IEDs connect to this ring via per-bay Ethernet switches.

```
                    ┌─────────────┐
                    │  GPS CLOCK  │
                    │ HOPF 8030   │ Time Sync (PTP/SNTP)
                    └──────┬──────┘
                           │
              ┌────────────┴────────────┐
              │                         │
      ┌───────┴────────┐       ┌────────┴───────┐
      │  ETHERNET SW1  │       │  ETHERNET SW2  │
      │  SAS PANEL 1   │       │  SAS PANEL 2   │
      │  =E00+X1       │       │  =E00+X2       │
      └───────┬────────┘       └────────┬───────┘
              │                         │
              └──────────┬──────────────┘
                         │
              ┌──────────┴──────────────────────────────────────┐
              │         IEC 61850 Fiber Optical Ring             │
              │                                                  │
     ┌────────┴───┐  ┌──────────┐  ┌──────────┐  ┌──────────┐  │
     │  Bay SW    │  │  Bay SW  │  │  Bay SW  │  │  Bay SW  │  │
     │  =E01+W1   │  │ =E02+W1  │  │ =E03+W1  │  │ =E04+WR1 │  │
     └────────────┘  └──────────┘  └──────────┘  └──────────┘  │
     ┌────────────┐  ┌──────────┐  ┌──────────┐                 │
     │  Bay SW    │  │  Bay SW  │  │  Bay SW  │                 │
     │  =E05+WR1  │  │ =E06+WR1 │  │ =E00+R1  │                 │
     └────────────┘  └──────────┘  └──────────┘                 │
              └──────────────────────────────────────────────────┘
```

### 2.2 Communication Link Types

| Link Type                        | Cable       | Application                           |
| -------------------------------- | ----------- | ------------------------------------- |
| Fiber Optic Patch Cord Multimode | Orange line | Station bus ring, IED-to-switch       |
| UTP CAT-4 Cable                  | Blue line   | Station LAN (workstations, servers)   |
| RS232/RS485 Cable                | Green line  | Legacy serial devices (Modem, REG-DA) |
| Coaxial Cable                    | Brown line  | GPS antenna feed                      |
| VGA, Keyboard, Mouse Cables      | Grey line   | HMI peripherals, KVM                  |

### 2.3 IEC 61850 Services Used

| Service                                          | Layer        | Application                                         |
| ------------------------------------------------ | ------------ | --------------------------------------------------- |
| MMS (Manufacturing Message Specification)        | Station Bus  | SCADA read/write, monitoring, RCB subscription      |
| GOOSE (Generic Object-Oriented Substation Event) | Bay Bus      | Inter-bay interlocking, fast trip signals, blocking |
| SNTP/PTP (IEEE 1588)                             | Time Sync    | All IED timestamp synchronisation via GPS           |
| IEC 60870-5-104                                  | WAN (TCP/IP) | Remote SCADA via Router                             |
| IEC 60870-5-101                                  | WAN (Serial) | Legacy remote SCADA via Modem                       |

### 2.4 GOOSE Inter-Bay Logic

GOOSE messaging is used for the following inter-bay functions:

- **Busbar protection trip** → All breaker bay trip coils (P746 → all bays)
- **Line distance protection blocking** → Adjacent bay blocking signals (P543 inter-bay)
- **Transformer differential trip** → LV side breaker trip (P643 → 30kV bay)
- **Auto-reclose signals** → Line bays sync-check (P543 → P543)
- **Interlocking conditions** → Bay control units (C264 → C264)

---

## 3. Station Level Equipment

### 3.1 SAS Panel 1 — =E00+X1

**Function:** Primary station-level control, monitoring, and data concentration.

| Tag      | Equipment         | Model / Make          | Function                                          |
| -------- | ----------------- | --------------------- | ------------------------------------------------- |
| -SVR1    | Server 1          | Advantech             | Primary SCADA server, IEC 61850 data concentrator |
| -OWS1    | Local HMI 1       | Advantech Workstation | Primary operator workstation                      |
| -SW1     | Ethernet Switch 1 | Kyland                | Station bus ring switch (ring node 1)             |
| -KVM EXT | KVM Extender      | —                    | Local/Remote HMI extension to Control Desk 1      |

### 3.2 SAS Panel 2 — =E00+X2

**Function:** Redundant station-level control, monitoring, and data concentration.

| Tag      | Equipment                | Model / Make          | Function                                     |
| -------- | ------------------------ | --------------------- | -------------------------------------------- |
| -SVR2    | Server 2                 | Advantech             | Redundant SCADA server, hot-standby          |
| -OWS2    | Local HMI 2              | Advantech Workstation | Secondary operator workstation               |
| -SW2     | Ethernet Switch 2        | Kyland                | Station bus ring switch (ring node 2)        |
| -GPS     | GPS Time Reference Clock | HOPF 8030HEPTA        | GPS-based time synchronisation for all IEDs  |
| -KVM EXT | KVM Extender             | —                    | Local/Remote HMI extension to Control Desk 2 |

### 3.3 Control Desks

Two operator control desks are provided:

| Item             | Control Desk 1           | Control Desk 2             |
| ---------------- | ------------------------ | -------------------------- |
| Monitor          | 24" display — Monitor 1 | 24" display — Monitor 2   |
| Keyboard & Mouse | Full set                 | Full set                   |
| Speakers         | Yes                      | Yes                        |
| KVM Remote       | Yes (from =E00+X1)       | Yes (from =E00+X2)         |
| Printer          | —                       | Color Laser Printer        |
| GPS Antenna      | —                       | Antenne GPS (to 8030HEPTA) |

### 3.4 Gateway and Remote Communication Equipment

| Tag     | Equipment | Model                          | Protocol                 | Destination                     |
| ------- | --------- | ------------------------------ | ------------------------ | ------------------------------- |
| -GTW    | Gateway   | SAITEL DP (Schneider Electric) | IEC 60870-5-104 (TCP/IP) | Control Centre / SCADA (remote) |
| -MDM    | Modem     | DCE IG202T                     | IEC 60870-5-101 (serial) | Control Centre / SCADA (backup) |
| -ROUTER | Router    | —                             | TCP/IP                   | WAN / Control Centre            |

> **Note:** Communication to the Control Centre/SCADA is explicitly marked as "Out of Scope" in the SAS architecture drawing but the gateway infrastructure is provided within this project scope.

### 3.5 Engineering Laptop

A dedicated **Engineering Laptop/Workstation** is provided at station level for IED configuration, IEC 61850 SCL engineering, and relay settings management. It connects to the station LAN via UTP and can access all bay IEDs.

---

## 4. Bay Level — Complete Bay Inventory

### 4.1 Bay Summary Table

| No. | Bay ID  | Bay Name                 | Panel Type                      | Separate C&P Panels | Key IEDs                    |
| --- | ------- | ------------------------ | ------------------------------- | ------------------- | --------------------------- |
| 1   | =E01    | Transformer-1 (150/30kV) | Control + Protection (separate) | Yes                 | C264, P643, P142×2, REG-DA |
| 2   | =E02    | Transformer-2 (150/30kV) | Control + Protection (separate) | Yes                 | C264, P643, P142×2, REG-DA |
| 3   | =E03    | Transformer-3 (150/30kV) | Control + Protection (separate) | Yes                 | C264, P643, P142×2, REG-DA |
| 4   | =E04    | Coupler (Bus Section)    | Combined C&P                    | No                  | C264, P143                  |
| 5   | =E05    | Line-1                   | Combined C&P                    | No                  | C264, P142, P543            |
| 6   | =E06    | Line-2                   | Combined C&P                    | No                  | C264, P142, P543            |
| 7   | =E00+R1 | Busbar Protection 150kV  | Protection only                 | N/A                 | P746×3                     |
| 8   | =E00+X3 | Common IED I/O           | I/O only                        | N/A                 | C264 (IED I/O)              |
| 9   | =E00+P1 | Energy Meter Panel       | Metering only                   | N/A                 | ION 8650×5                 |

### 4.2 Bay Architecture Pattern

**Transformer Bays (=E01, =E02, =E03) — Separated Panel Architecture:**

```
┌──────────────────────────────┐    ┌──────────────────────────────┐
│   CONTROL PANEL (=ExW1)      │    │  PROTECTION PANEL (=ExR1)    │
│                              │    │                              │
│  -SW  Ethernet Switch        │    │  -SW  Ethernet Switch        │
│  -A30 MiCOM C264 (BCU)       │    │  -F87T MiCOM P643            │
│  -N90 REG-DA (AVR)           │    │  -F501 MiCOM P142            │
│                              │    │  -F502 MiCOM P142            │
└──────────────────────────────┘    └──────────────────────────────┘
           │                                      │
           └──────────────┬───────────────────────┘
                          │  IEC 61850 / GOOSE
                     Fiber Optical Ring
```

**Line/Coupler Bays (=E04, =E05, =E06) — Integrated Panel Architecture:**

```
┌──────────────────────────────────────────┐
│     COMBINED CONTROL & PROTECTION        │
│     PANEL (=Ex+WR1)                      │
│                                          │
│  -SW   Ethernet Switch                   │
│  -A30  MiCOM C264 (Bay Control Unit)     │
│  -F50  MiCOM P142/P143 (O/C & E/F)      │
│  -F21  MiCOM P543 (Distance) [Line only] │
└──────────────────────────────────────────┘
                    │
               IEC 61850 / GOOSE
              Fiber Optical Ring
```

---

## 5. Transformer Bay 1 — =E01

### 5.1 Overview

| Parameter          | Detail                                                         |
| ------------------ | -------------------------------------------------------------- |
| Bay Name           | Transformer Bay 1                                              |
| Voltage Ratio      | 150kV / 30kV                                                   |
| Control Panel      | =E01+W1 (Transformer-1 Control Panel)                          |
| Protection Panel   | =E01+R1 (Transformer-1 Protection Panel)                       |
| Panel Architecture | Separated — dedicated control and protection cubicles         |
| IEC 61850          | Each panel has own Ethernet switch; communicates on fiber ring |

---

### 5.2 Control Panel — =E01+W1

#### 5.2.1 Equipment

| Tag  | Model                  | Manufacturer       | Function                                                       |
| ---- | ---------------------- | ------------------ | -------------------------------------------------------------- |
| -SW  | Kyland Ethernet Switch | Kyland             | Bay-level IEC 61850 switch, connects panel IEDs to fiber ring  |
| -A30 | MiCOM C264             | Schneider Electric | Bay Control Unit (BCU) — supervisory control and interlocking |
| -N90 | REG-DA                 | A-Eberle           | Automatic Voltage Regulator — tap changer control             |

#### 5.2.2 Bay Control Unit — MiCOM C264 (-A30)

The MiCOM C264 is the primary **Bay Control Unit (BCU)** responsible for:

**Control Functions:**

- Supervisory control of all switchgear in the transformer bay (HV breaker, HV disconnectors, earthing switches)
- Local/Remote switching mode selection
- Interlocking logic enforcement (topology-based interlocking)
- Bay-level Single Line Diagram (SLD) display
- Event logging and disturbance recording integration
- IEC 61850 ACSI server — publishes bay control status via MMS to station level
- GOOSE subscriber for protection trip status and busbar protection commands

**Communication:**

- IEC 61850 MMS — reports to SVR1/SVR2 via fiber ring
- IEC 61850 GOOSE — inter-bay interlocking with adjacent bays and busbar protection

#### 5.2.3 Automatic Voltage Regulator — REG-DA (-N90)

| Parameter     | Detail                                           |
| ------------- | ------------------------------------------------ |
| Manufacturer  | A-Eberle                                         |
| Model         | REG-DA                                           |
| Function      | Automatic on-load tap changer (OLTC) control     |
| Communication | RS485 serial to MiCOM C264 (via IEC 61850 proxy) |

**Control Functions:**

- Automatic voltage regulation maintaining LV bus voltage within ±% setpoint
- Manual tap raise/lower via BCU or HMI command
- Parallel operation of transformers with circulating current minimisation (CAN protocol between REG-DA units)
- Tap position readback (ANSI 27/59 voltage monitoring)
- Tap operation counter for maintenance scheduling

---

### 5.3 Protection Panel — =E01+R1

#### 5.3.1 Equipment

| Tag   | Model                  | Manufacturer       | ANSI Functions                  | Role                                      |
| ----- | ---------------------- | ------------------ | ------------------------------- | ----------------------------------------- |
| -SW   | Kyland Ethernet Switch | Kyland             | —                              | Bay protection IEC 61850 switch           |
| -F87T | MiCOM P643             | Schneider Electric | 87T, 87REF, 24, 49, 46          | Main transformer differential protection  |
| -F501 | MiCOM P142             | Schneider Electric | 50, 51, 50N, 51N, 64REF, 49, 46 | HV overcurrent and earth fault protection |
| -F502 | MiCOM P142             | Schneider Electric | 50, 51, 50N, 51N, 64REF         | LV overcurrent and earth fault protection |

---

#### 5.3.2 Main Transformer Differential Protection — MiCOM P643 (-F87T)

The MiCOM P643 is a **numerical transformer differential protection relay** providing the primary protection for the 150/30kV power transformer.

**Protection Functions:**

| ANSI Code | Function                       | Description                                                                                                                                    |
| --------- | ------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| 87T       | Biased Differential Protection | Compares HV and LV currents with percentage-biased characteristic; operates for internal faults while stable during inrush and through-fault   |
| 87REF     | Restricted Earth Fault         | High-impedance or low-impedance REF on HV winding and LV winding; detects winding-to-earth faults near the neutral point below 87T sensitivity |
| 24        | Overfluxing (V/Hz)             | Detects transformer overfluxing due to overvoltage or underfrequency; alarm and trip stages                                                    |
| 49        | Thermal Overload               | Thermal image model of transformer winding temperature; alarm and trip based on thermal state                                                  |
| 46        | Negative Phase Sequence (NPS)  | Detects unbalanced loading or phase loss conditions                                                                                            |

**Key Technical Features:**

- Second and fifth harmonic restraint to block during magnetising inrush
- CT ratio and vector group compensation (all winding configurations)
- On-load tap changer (OLTC) compensation
- Winding 1 (HV), Winding 2 (LV), and optional Winding 3 current inputs
- Fault location and event recording
- IEC 61850 GOOSE trip output to HV and LV circuit breakers

---

#### 5.3.3 HV Side Overcurrent & Earth Fault — MiCOM P142 (-F501)

The MiCOM P142 (-F501) provides **backup and primary overcurrent protection on the high-voltage (150kV) side** of the transformer.

**Protection Functions:**

| ANSI Code | Function                      | Description                                                                                |
| --------- | ----------------------------- | ------------------------------------------------------------------------------------------ |
| 50        | Instantaneous Overcurrent     | High-set instantaneous element for close-in HV faults; fast trip without intentional delay |
| 51        | Time-Overcurrent (Phase)      | IDMT/definite-time overcurrent; operates for sustained phase overcurrent conditions        |
| 50N       | Instantaneous Earth Fault     | Instantaneous zero-sequence (earth fault) detection; high sensitivity for earth faults     |
| 51N       | Time-Delayed Earth Fault      | IDMT/definite-time earth fault; backup earth fault protection with time grading            |
| 64REF     | Restricted Earth Fault        | Sensitive earth fault detection within HV winding zone (high-impedance scheme)             |
| 49        | Thermal Overload              | Secondary thermal model for HV winding; provides backup to P643 thermal function           |
| 46        | Negative Sequence Overcurrent | NPS overcurrent for unbalance detection                                                    |

**Curve Characteristics:**

- Phase overcurrent: IEC standard inverse / very inverse / extremely inverse or definite time
- Earth fault: IEC/IEEE selectable curve types
- Multiple setting groups (up to 4) for different system configurations

---

#### 5.3.4 LV Side Overcurrent & Earth Fault — MiCOM P142 (-F502)

The MiCOM P142 (-F502) provides **overcurrent protection on the low-voltage (30kV) side** of the transformer.

**Protection Functions:**

| ANSI Code | Function                  | Description                                       |
| --------- | ------------------------- | ------------------------------------------------- |
| 50        | Instantaneous Overcurrent | Fast phase fault detection on LV bus              |
| 51        | Time-Overcurrent (Phase)  | IDMT phase overcurrent with LV-side grading       |
| 50N       | Instantaneous Earth Fault | Fast earth fault on LV neutral                    |
| 51N       | Time-Delayed Earth Fault  | Graded earth fault backup                         |
| 64REF     | Restricted Earth Fault    | LV winding restricted earth fault zone protection |

**Coordination Role:**

- Coordinates with 30kV feeder bay overcurrent relays downstream
- Provides backup to P643 differential for LV-side external faults
- Time-graded above outgoing 30kV bay relays

---

## 6. Transformer Bay 2 — =E02

### 6.1 Overview

| Parameter        | Detail                                   |
| ---------------- | ---------------------------------------- |
| Bay Name         | Transformer Bay 2                        |
| Voltage Ratio    | 150kV / 30kV                             |
| Control Panel    | =E02+W1                                  |
| Protection Panel | =E02+R1                                  |
| Architecture     | **Identical to Transformer Bay 1** |

### 6.2 Equipment — Identical to Bay 1

Transformer Bay 2 is a **full duplicate** of Transformer Bay 1 in terms of equipment, functions, settings philosophy, and IEC 61850 configuration.

**Control Panel =E02+W1:**

| Tag  | Model         | Function                                                                     |
| ---- | ------------- | ---------------------------------------------------------------------------- |
| -SW  | Kyland Switch | Bay IEC 61850 switch                                                         |
| -A30 | MiCOM C264    | Bay Control Unit (identical functions to =E01 BCU)                           |
| -N90 | REG-DA        | Automatic Voltage Regulator (parallel operation with TRF-1 and TRF-3 REG-DA) |

**Protection Panel =E02+R1:**

| Tag   | Model         | ANSI Functions                  | Role                         |
| ----- | ------------- | ------------------------------- | ---------------------------- |
| -SW   | Kyland Switch | —                              | Protection panel switch      |
| -F87T | MiCOM P643    | 87T, 87REF, 24, 49, 46          | Main differential protection |
| -F501 | MiCOM P142    | 50, 51, 50N, 51N, 64REF, 49, 46 | HV overcurrent & earth fault |
| -F502 | MiCOM P142    | 50, 51, 50N, 51N, 64REF         | LV overcurrent & earth fault |

> For full function descriptions, refer to Section 5 (Transformer Bay 1) — all functions are identical.

### 6.3 REG-DA Parallel Operation

The three REG-DA units on Transformer 1, 2, and 3 are interconnected for **parallel transformer voltage regulation**. The active REG-DA acts as master and synchronises tap position across all three units to minimise circulating reactive current.

---

## 7. Transformer Bay 3 — =E03

### 7.1 Overview

| Parameter        | Detail                                             |
| ---------------- | -------------------------------------------------- |
| Bay Name         | Transformer Bay 3                                  |
| Voltage Ratio    | 150kV / 30kV                                       |
| Control Panel    | =E03+W1                                            |
| Protection Panel | =E03+R1                                            |
| Architecture     | **Identical to Transformer Bay 1 and Bay 2** |

### 7.2 Equipment

**Control Panel =E03+W1:**

| Tag  | Model         | Function                    |
| ---- | ------------- | --------------------------- |
| -SW  | Kyland Switch | Bay IEC 61850 switch        |
| -A30 | MiCOM C264    | Bay Control Unit            |
| -N90 | REG-DA        | Automatic Voltage Regulator |

**Protection Panel =E03+R1:**

| Tag   | Model         | ANSI Functions                  | Role                         |
| ----- | ------------- | ------------------------------- | ---------------------------- |
| -SW   | Kyland Switch | —                              | Protection panel switch      |
| -F87T | MiCOM P643    | 87T, 87REF, 24, 49, 46          | Main differential protection |
| -F501 | MiCOM P142    | 50, 51, 50N, 51N, 64REF, 49, 46 | HV overcurrent & earth fault |
| -F502 | MiCOM P142    | 50, 51, 50N, 51N, 64REF         | LV overcurrent & earth fault |

> For full function descriptions, refer to Section 5 (Transformer Bay 1).

---

## 8. Coupler Bay — =E04

### 8.1 Overview

| Parameter         | Detail                                                    |
| ----------------- | --------------------------------------------------------- |
| Bay Name          | Coupler (Bus Section / Bus Coupler)                       |
| Panel Designation | =E04+WR1                                                  |
| Panel Type        | **Combined Control & Protection Panel**             |
| Function          | Interconnects Busbar Section A and Busbar Section B       |
| Architecture      | Single integrated cubicle for both control and protection |

The bus coupler bay allows the two 150kV busbar sections to be paralleled or separated for operational flexibility and load management.

---

### 8.2 Equipment — =E04+WR1

| Tag  | Model                  | Manufacturer       | Function                                      |
| ---- | ---------------------- | ------------------ | --------------------------------------------- |
| -SW  | Kyland Ethernet Switch | Kyland             | Combined C&P bay IEC 61850 switch             |
| -A30 | MiCOM C264             | Schneider Electric | Bay Control Unit — coupler switching control |
| -F50 | MiCOM P143             | Schneider Electric | Overcurrent & Earth Fault protection          |

---

### 8.3 Control Functions — MiCOM C264 (-A30)

**Control Functions:**

- Supervisory control of the bus coupler circuit breaker
- Supervisory control of bus coupler disconnectors (Busbar A side and Busbar B side)
- Supervisory control of coupler earthing switches
- Interlocking: ensures bus coupler cannot be closed into a busbar fault condition; coordinates with busbar protection GOOSE blocking
- Local/Remote mode selection
- IEC 61850 MMS reporting to station level servers
- GOOSE subscriber for busbar protection trip and blocking signals

**Busbar Interlocking Logic (via GOOSE):**

- Receives busbar health status from P746 busbar protection
- Inhibits close command if busbar protection indicates fault condition
- Coordinates with line bay BCUs for bus transfer operations

---

### 8.4 Protection Functions — MiCOM P143 (-F50)

| ANSI Code | Function                        | Description                                                                                  |
| --------- | ------------------------------- | -------------------------------------------------------------------------------------------- |
| 50        | Instantaneous Phase Overcurrent | Fast-trip element for close-in bus coupler faults; set above maximum through-fault current   |
| 51        | Time-Overcurrent (Phase)        | IDMT overcurrent for bus coupler thermal protection; graded with transformer and line relays |
| 50N       | Instantaneous Earth Fault       | Instantaneous zero-sequence overcurrent for single-phase and double-phase-to-earth faults    |
| 51N       | Time-Delayed Earth Fault        | IDMT earth fault with time coordination above busbar protection operating time               |

**Coordination Philosophy:**

- Phase overcurrent (51) graded above outgoing line relay time but below transformer relay
- Earth fault (51N) graded with system neutral earthing philosophy
- Instantaneous elements (50/50N) set to provide fast clearance without coordination requirement for bus faults

**Trip Outputs:**

- Trip bus coupler circuit breaker
- GOOSE trip signal to busbar protection zone boundary

---

## 9. Line-1 Bay — =E05

### 9.1 Overview

| Parameter         | Detail                                                                          |
| ----------------- | ------------------------------------------------------------------------------- |
| Bay Name          | Line-1 (150kV Transmission Line)                                                |
| Panel Designation | =E05+WR1                                                                        |
| Panel Type        | **Combined Control & Protection Panel**                                   |
| Function          | 150kV transmission line feeder — protection and control                        |
| Architecture      | Single integrated cubicle — control, primary protection, and backup protection |

---

### 9.2 Equipment — =E05+WR1

| Tag  | Model                  | Manufacturer       | ANSI Functions                                         | Role                                                |
| ---- | ---------------------- | ------------------ | ------------------------------------------------------ | --------------------------------------------------- |
| -SW  | Kyland Ethernet Switch | Kyland             | —                                                     | Bay IEC 61850 switch                                |
| -A30 | MiCOM C264             | Schneider Electric | BCU, 25 (via IED)                                      | Bay Control Unit with sync-check supervision        |
| -F50 | MiCOM P142             | Schneider Electric | 50, 51, 50N, 51N, 46                                   | Backup overcurrent & earth fault protection         |
| -F21 | MiCOM P543             | Schneider Electric | 21, 21N, 67, 67N, 79, 25, 27, 59, 46, 50, 51, 50N, 51N | Main distance, auto-reclose, directional protection |

---

### 9.3 Control Functions — MiCOM C264 (-A30)

**Control Functions:**

- Supervisory control of Line-1 circuit breaker
- Supervisory control of Line-1 disconnectors (busbar side and line side)
- Supervisory control of Line-1 earthing switches (cable/line earth)
- Interlocking: prevents circuit breaker close when line earth switch closed; ensures disconnectors in correct position before breaker operation
- Local/Remote mode selection and authority management
- Bay SLD display via local HMI
- IEC 61850 MMS reporting: breaker position, disconnector status, earth switch status, alarms
- GOOSE subscriber: distance protection trip initiation, auto-reclose in progress flag, sync-check result

**Sync-Check Supervision:**

- Receives sync-check result from MiCOM P543 (-F21) via GOOSE
- Inhibits close command if P543 reports out-of-synchronism conditions
- Provides manual close override (with appropriate authority level)

---

### 9.4 Backup Protection — MiCOM P142 (-F50)

The MiCOM P142 provides **backup overcurrent protection** for Line-1, independent of the main distance relay.

| ANSI Code | Function                        | Description                                                                                         |
| --------- | ------------------------------- | --------------------------------------------------------------------------------------------------- |
| 50        | Instantaneous Phase Overcurrent | High-set instantaneous for close-in line faults; set below minimum fault current at relay location  |
| 51        | Time-Overcurrent (Phase)        | IDMT overcurrent; backup to distance protection for phase faults; graded with remote end protection |
| 50N       | Instantaneous Earth Fault       | Instantaneous earth fault for close-in single-phase-to-earth faults                                 |
| 51N       | Time-Delayed Earth Fault        | IDMT earth fault; backup for earth faults beyond distance relay reach; graded with remote infeed    |
| 46        | Negative Sequence Overcurrent   | Phase unbalance and open-conductor detection                                                        |

**Independence from Main Protection:**

- Separate CT inputs from P543 to ensure protection independence
- Separate trip output to breaker trip coil (TC2) — P142 trips TC2, P543 trips TC1
- This dual-trip arrangement ensures protection operation even with one trip coil failure

---

### 9.5 Main Distance & Auto-Reclose Protection — MiCOM P543 (-F21)

The MiCOM P543 is a **full-scheme numerical distance protection relay** providing the primary protection for Line-1 transmission line.

#### 9.5.1 Distance Protection Functions

| ANSI Code | Function                      | Description                                                                                                                                                       |
| --------- | ----------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 21        | Phase-Phase Distance          | Mho or quadrilateral distance characteristic; Zone 1 (instantaneous, ~80% line), Zone 2 (time-delayed, ~120% line), Zone 3 (time-delayed, reverse/forward backup) |
| 21N       | Phase-Earth Distance          | Zero-sequence compensated distance for single-phase-to-earth faults; separate reach settings for each zone                                                        |
| 67        | Directional Phase Overcurrent | Forward/reverse directional overcurrent element; aids discrimination for complex fault conditions                                                                 |
| 67N       | Directional Earth Fault       | Directional zero-sequence element for earth fault discrimination; sensitive residual current directional element                                                  |

#### 9.5.2 Distance Zone Configuration

| Zone   | Direction          | Reach                | Time Delay          | Purpose                                             |
| ------ | ------------------ | -------------------- | ------------------- | --------------------------------------------------- |
| Zone 1 | Forward            | ~80% of line length  | Instantaneous (0ms) | Main fast clearance for faults in first 80% of line |
| Zone 2 | Forward            | ~120% of line length | ~300–500ms         | Backup for faults beyond Zone 1 and remote bus      |
| Zone 3 | Forward/Reverse    | ~200% of line length | ~1000ms             | Remote backup / busbar backup                       |
| Zone 4 | Reverse (optional) | Set by system study  | ~500ms              | Reverse reach for line-end fault detection          |

#### 9.5.3 Auto-Reclose Functions

| ANSI Code | Function          | Description                                                                                                                                                        |
| --------- | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 79        | Auto-Reclose (AR) | Single-phase and three-phase auto-reclose; dead time and reclaim time configurable; coordinates with remote end AR via transfer trip scheme                        |
| 25        | Sync-Check        | Checks voltage magnitude, phase angle (typically ≤25°), and frequency difference (≤0.1Hz) before issuing reclose command; prevents reclosing out-of-synchronism |
| 27        | Undervoltage      | Detects line de-energisation for AR dead line check; confirms line is dead before reclose if configured for dead-line/live-bus                                     |
| 59        | Overvoltage       | Detects overvoltage conditions; used in conjunction with AR voltage supervision                                                                                    |

**Auto-Reclose Sequence:**

```
Fault Detected → Zone 1/2 Trip → Breaker Opens
     → Dead Time (configurable, typ. 0.3–1.0s for single-phase)
     → Sync-Check (25): Voltage / Angle / Frequency OK?
          Yes → Reclose Pulse → Breaker Closes → Reclaim Time
               → Stable: AR Successful, reset
               → Fault Persists: Final Trip — Lockout (86)
          No  → Inhibit reclose, wait or alarm
```

#### 9.5.4 Additional Protection Functions

| ANSI Code | Function                  | Description                                      |
| --------- | ------------------------- | ------------------------------------------------ |
| 50        | Instantaneous Overcurrent | High-set phase overcurrent within distance relay |
| 51        | Time-Overcurrent          | Backup phase overcurrent within distance relay   |
| 50N       | Instantaneous Earth Fault | High-set earth fault within distance relay       |
| 51N       | Time-Delayed Earth Fault  | Backup earth fault within distance relay         |
| 46        | Negative Sequence         | Unbalance detection integrated in P543           |

#### 9.5.5 Communication-Aided Protection Schemes

The MiCOM P543 supports **teleprotection schemes** for high-speed fault clearance coordinated with the remote end relay:

| Scheme                                      | Description                                                                                                  |
| ------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| PUTT (Permissive Under-reach Transfer Trip) | Remote end sends permissive signal when Zone 2 detects fault; local relay trips if own Zone 2 also picked up |
| POTT (Permissive Over-reach Transfer Trip)  | Remote end sends permissive signal when Zone 2 detects fault; local relay trips on receipt of permissive     |
| DTT (Direct Transfer Trip)                  | Direct trip command sent to remote end; no local measurement required                                        |
| Blocking Scheme                             | Remote end sends blocking signal for external faults; local relay inhibited from tripping                    |

> **Note:** The specific teleprotection scheme implemented depends on the communication channel (pilot wire, fibre, or power line carrier) available between the substations — to be confirmed during detailed engineering.

---

## 10. Line-2 Bay — =E06

### 10.1 Overview

| Parameter         | Detail                                                        |
| ----------------- | ------------------------------------------------------------- |
| Bay Name          | Line-2 (150kV Transmission Line)                              |
| Panel Designation | =E06+WR1                                                      |
| Panel Type        | **Combined Control & Protection Panel**                 |
| Architecture      | **Identical to Line-1 Bay (=E05)**                      |
| Function          | Second 150kV transmission line — full protection and control |

---

### 10.2 Equipment — =E06+WR1

| Tag  | Model                  | Manufacturer       | ANSI Functions                       | Role                                     |
| ---- | ---------------------- | ------------------ | ------------------------------------ | ---------------------------------------- |
| -SW  | Kyland Ethernet Switch | Kyland             | —                                   | Bay IEC 61850 switch                     |
| -A30 | MiCOM C264             | Schneider Electric | BCU, 25 supervision                  | Bay Control Unit                         |
| -F50 | MiCOM P142             | Schneider Electric | 50, 51, 50N, 51N, 46                 | Backup overcurrent & earth fault         |
| -F21 | MiCOM P543             | Schneider Electric | 21, 21N, 67, 67N, 79, 25, 27, 59, 46 | Main distance, auto-reclose, directional |

---

### 10.3 Control Functions — MiCOM C264 (-A30)

Identical in scope to Line-1 Bay C264 (Section 9.3), applied to Line-2 circuit breaker and disconnectors:

- Supervisory control: Line-2 circuit breaker, disconnectors (busbar and line side), earthing switches
- Interlocking enforcement (same topology-based logic as Line-1)
- Local/Remote mode
- IEC 61850 MMS and GOOSE services
- Sync-check gate from P543 Line-2

---

### 10.4 Backup Protection — MiCOM P142 (-F50)

Identical to Line-1 MiCOM P142 (-F50) in Section 9.4:

| ANSI Code | Function                            |
| --------- | ----------------------------------- |
| 50        | Instantaneous Phase Overcurrent     |
| 51        | Time-Overcurrent (Phase) — IDMT/DT |
| 50N       | Instantaneous Earth Fault           |
| 51N       | Time-Delayed Earth Fault            |
| 46        | Negative Sequence Overcurrent       |

Separate CT inputs and separate trip coil (TC2) ensure independence from the main distance relay.

---

### 10.5 Main Distance & Auto-Reclose Protection — MiCOM P543 (-F21)

Identical in capability and configuration philosophy to Line-1 MiCOM P543 (-F21) in Section 9.5.

All distance zones (Zone 1–4), auto-reclose (79), sync-check (25), voltage supervision (27/59), directional elements (67/67N), and teleprotection scheme support apply equally to Line-2.

**Key Difference:** Zone reach settings, directional elements, and auto-reclose parameters are individually set for Line-2 based on Line-2 specific system studies (line impedance, infeed conditions, and remote end protection coordination).

---

## 11. Busbar Protection Panel — =E00+R1

### 11.1 Overview

| Parameter             | Detail                                |
| --------------------- | ------------------------------------- |
| Panel Name            | Busbar Protection Panel — 150kV      |
| Panel Designation     | =E00+R1                               |
| Panel Type            | Protection only (no control function) |
| Protection Philosophy | Low-impedance busbar differential     |
| Zones                 | 3 zones (Zone 1, Zone 2, Check Zone)  |

The busbar protection panel provides **high-speed discriminative protection** for the 150kV busbar, detecting internal faults and issuing selective trip commands to all connected bay circuit breakers within the faulted bus zone.

---

### 11.2 Equipment

| Tag    | Model      | Manufacturer       | ANSI Functions  | Role                              |
| ------ | ---------- | ------------------ | --------------- | --------------------------------- |
| -F87B1 | MiCOM P746 | Schneider Electric | 87B, 74TC, 50BF | Busbar differential — Zone 1     |
| -F87B2 | MiCOM P746 | Schneider Electric | 87B, 74TC, 50BF | Busbar differential — Zone 2     |
| -F87B3 | MiCOM P746 | Schneider Electric | 87B, 74TC, 50BF | Busbar differential — Check Zone |

---

### 11.3 Protection Functions — MiCOM P746 (×3)

#### Zone 1 — MiCOM P746 (-F87B1)

| ANSI Code | Function                              | Description                                                                                                                                                                 |
| --------- | ------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 87B       | Busbar Differential Protection Zone 1 | Algebraic summation of all current feeders connected to Busbar Zone 1; operates when differential current exceeds threshold; selective trip to Zone 1 circuit breakers only |
| 74TC      | Trip Circuit Supervision              | Monitors integrity of all trip circuits connected to Zone 1 breakers; alarm on open-circuit trip coil wiring                                                                |
| 50BF      | Breaker Failure Protection            | Monitors breaker current after trip command; if breaker fails to clear within CBF time (typically 100–200ms), initiates backup trip to adjacent breakers and busbar zone   |

#### Zone 2 — MiCOM P746 (-F87B2)

| ANSI Code | Function                              | Description                                                                                                 |
| --------- | ------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| 87B       | Busbar Differential Protection Zone 2 | Same principle as Zone 1 but covering second busbar section; selective trip to Zone 2 circuit breakers only |
| 74TC      | Trip Circuit Supervision              | Same as Zone 1                                                                                              |
| 50BF      | Breaker Failure                       | Same as Zone 1, for Zone 2 connected breakers                                                               |

#### Check Zone — MiCOM P746 (-F87B3)

| ANSI Code | Function                       | Description                                                                                                                                                                        |
| --------- | ------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 87B       | Busbar Differential Check Zone | Covers entire busbar (both sections) as a supervisory check; must agree with Zone 1 or Zone 2 before trip is issued; prevents spurious trips due to CT saturation or wiring errors |
| 74TC      | Trip Circuit Supervision       | System-wide trip circuit monitoring                                                                                                                                                |
| 50BF      | Breaker Failure                | System-wide CBF backup                                                                                                                                                             |

### 11.4 Busbar Protection Operating Principle

```
Fault on Zone 1 Bus:
  │
  ├── P746 Zone 1 (F87B1): |ΣI| > threshold → Zone 1 trip signal (GOOSE)
  ├── P746 Check Zone (F87B3): |ΣI_all| > threshold → Check Zone confirms
  │
  └── Trip issued only when BOTH Zone 1 AND Check Zone operate
       → GOOSE trip to: TRF-1 HV breaker, TRF-2 HV breaker, TRF-3 HV breaker,
                        Line-1 breaker, Bus Coupler breaker
       → Selective: Zone 2 bays NOT tripped
```

**Speed:** Typical operate time < 25ms for internal busbar fault.

**Stability:** Secure against through-fault CT saturation due to low-impedance differential algorithm with stabilisation factor.

---

## 12. Common IED I/O Panel — =E00+X3

### 12.1 Overview

| Parameter         | Detail                                         |
| ----------------- | ---------------------------------------------- |
| Panel Name        | Common IED I/O Panel                           |
| Panel Designation | =E00+X3                                        |
| Function          | Station-level auxiliary digital and analog I/O |

### 12.2 Equipment

| Tag     | Model      | Function                                           |
| ------- | ---------- | -------------------------------------------------- |
| IED I/O | MiCOM C264 | Common bay-level I/O for station auxiliary signals |

**Functions:**

- Acquisition of station-level binary inputs (DC supply status, auxiliary relay status, fire alarm, security alarms, HVAC status)
- Acquisition of station-level analog inputs (battery voltage, DC bus voltage, auxiliary transformer measurements)
- Output commands for station auxiliary systems
- IEC 61850 reporting of all I/O to station servers (SVR1/SVR2)

---

## 13. Energy Meter Panel — =E00+P1

### 13.1 Overview

| Parameter         | Detail                                                       |
| ----------------- | ------------------------------------------------------------ |
| Panel Name        | 150kV Energy Meter Panel                                     |
| Panel Designation | =E00+P1                                                      |
| Function          | Revenue-grade energy metering for all 150kV and 30kV feeders |
| Meter Model       | Schneider Electric ION 8650                                  |

### 13.2 Energy Meters

| Tag  | Model    | Metering Point                      |
| ---- | -------- | ----------------------------------- |
| -P51 | ION 8650 | Feeder/transformer metering point 1 |
| -P52 | ION 8650 | Feeder/transformer metering point 2 |
| -P53 | ION 8650 | Feeder/transformer metering point 3 |
| -P54 | ION 8650 | Feeder/transformer metering point 4 |
| -P55 | ION 8650 | Feeder/transformer metering point 5 |

### 13.3 ION 8650 Capabilities

| Parameter             | Detail                                                              |
| --------------------- | ------------------------------------------------------------------- |
| Accuracy Class        | 0.1S (revenue grade, IEC 62053-22)                                  |
| Measurements          | kWh, kVArh, kVAh import/export, PF, V, I, f, harmonics (up to 63rd) |
| Communication         | IEC 61850 MMS, DNP3, Modbus TCP                                     |
| Disturbance Recording | Waveform capture on event                                           |
| Power Quality         | Sag, swell, transient detection per IEC 61000-4-30 Class A          |

---

## 14. 30kV Feeder Bays — Sheet 005

### 14.1 Overview

Sheet 005 of the architecture diagram shows the **30kV side feeder extension** connected via the three 150/30kV transformer secondaries. Each transformer feeds a set of outgoing 30kV distribution feeders.

### 14.2 Bay Structure (Sheet 005)

Each 30kV feeder group consists of:

| Bay Type                           | Ethernet Switch | IEDs                     |
| ---------------------------------- | --------------- | ------------------------ |
| Outgoing to Backbone (30kV feeder) | -SW (per bay)   | Protection Relay (MiCOM) |
| Incoming from 150/30kV Transformer | -SW (per bay)   | Protection Relay (MiCOM) |
| Coupler (30kV bus section)         | -SW (per bay)   | Protection Relay (MiCOM) |

The specific 30kV relay types (model numbers) and protection functions are partially visible in the drawing and will be detailed in the 30kV bay-specific documentation (separate drawing set).

### 14.3 Ring Connection

The 30kV bay switches connect to the same **Fiber Optical IEC 61850 ring** as the 150kV bays, with the ring segments extending from SW2 (SAS Panel 2) and returning to SW1 (SAS Panel 1).

---

## 15. SCADA & Remote Communication

### 15.1 Communication Architecture

```
                    ┌──────────────────────┐
                    │   STATION LEVEL SAS  │
                    │  SVR1 + SVR2         │
                    └──────────┬───────────┘
                               │
                    ┌──────────┴───────────┐
                    │ GATEWAY: SAITEL DP   │
                    │ (-GTW)               │
                    └──────────┬───────────┘
                               │
             ┌─────────────────┴──────────────────┐
             │                                    │
    ┌────────┴─────────┐                ┌─────────┴──────────┐
    │   IEC 60870-5-104 │                │  IEC 60870-5-101   │
    │   (TCP/IP via     │                │  (Serial via       │
    │    ROUTER)        │                │   MODEM IG202T)    │
    └────────┬──────────┘                └─────────┬──────────┘
             │                                     │
             └──────────────┬──────────────────────┘
                            │
                   ┌────────┴────────┐
                   │ CONTROL CENTRE  │
                   │     / SCADA     │
                   │  (Out of scope) │
                   └─────────────────┘
```

### 15.2 Protocol Summary

| Protocol        | Transport                 | Direction     | Application                           |
| --------------- | ------------------------- | ------------- | ------------------------------------- |
| IEC 60870-5-104 | TCP/IP (via Router)       | Bidirectional | Primary telecontrol to Control Centre |
| IEC 60870-5-101 | Serial (via Modem IG202T) | Bidirectional | Backup/redundant telecontrol          |
| IEC 61850 MMS   | TCP/IP (Ethernet)         | Station level | Bay IED to SAS Server                 |
| IEC 61850 GOOSE | Ethernet multicast        | Bay level     | Inter-bay fast signals                |
| SNTP/PTP        | UDP/IP (Ethernet)         | Time sync     | GPS to all IEDs                       |

---

## 16. IED Equipment Summary

### 16.1 Complete IED Inventory by Model

| Model          | Manufacturer       | Function                             | Bay(s) Used                                               |
| -------------- | ------------------ | ------------------------------------ | --------------------------------------------------------- |
| MiCOM C264     | Schneider Electric | Bay Control Unit (BCU)               | =E01W1, =E02W1, =E03W1, =E04WR1, =E05WR1, =E06WR1, =E00X3 |
| MiCOM P142     | Schneider Electric | Overcurrent & Earth Fault            | =E01R1, =E02R1, =E03R1, =E05WR1, =E06WR1                  |
| MiCOM P143     | Schneider Electric | Overcurrent & Earth Fault (enhanced) | =E04WR1                                                   |
| MiCOM P543     | Schneider Electric | Distance, Auto-Reclose, Directional  | =E05WR1, =E06WR1                                          |
| MiCOM P643     | Schneider Electric | Transformer Differential             | =E01R1, =E02R1, =E03R1                                    |
| MiCOM P746     | Schneider Electric | Busbar Differential                  | =E00R1 (×3)                                              |
| REG-DA         | A-Eberle           | Automatic Voltage Regulator          | =E01W1, =E02W1, =E03W1                                    |
| ION 8650       | Schneider Electric | Revenue Energy Meter                 | =E00P1 (×5)                                              |
| HOPF 8030HEPTA | HOPF               | GPS Time Reference Clock             | =E00X2 (×1)                                              |
| Kyland Switch  | Kyland             | IEC 61850 Ethernet Switch            | All panels (one per panel)                                |
| SAITEL DP      | Schneider Electric | SCADA Gateway                        | Station level                                             |
| IG202T         | DCE                | Modem                                | Station level                                             |

### 16.2 IED Count Summary

| IED Type             | Count                               |
| -------------------- | ----------------------------------- |
| MiCOM C264 (BCU)     | 7                                   |
| MiCOM P142           | 8 (2×TRF bays + 2×Line bays × 2) |
| MiCOM P143           | 1                                   |
| MiCOM P543           | 2                                   |
| MiCOM P643           | 3                                   |
| MiCOM P746           | 3                                   |
| REG-DA               | 3                                   |
| ION 8650             | 5                                   |
| HOPF 8030HEPTA       | 1                                   |
| **Total IEDs** | **33**                        |

---

## 17. ANSI Protection Function Master Reference

### 17.1 ANSI Functions by Bay

| ANSI  | Function Name                 | TRF Bay (P643) | TRF Bay (P142 HV) | TRF Bay (P142 LV) | Coupler (P143) | Line (P142) | Line (P543) | Busbar (P746) |
| ----- | ----------------------------- | :------------: | :---------------: | :---------------: | :------------: | :---------: | :---------: | :-----------: |
| 21    | Phase Distance                |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 21N   | Earth Distance                |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 24    | Overfluxing                   |       ✅       |        —        |        —        |       —       |     —     |     —     |      —      |
| 25    | Sync-Check                    |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 27    | Undervoltage (AR supervision) |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 46    | Negative Sequence             |       ✅       |        ✅        |        —        |       —       |     ✅     |     ✅     |      —      |
| 49    | Thermal Overload              |       ✅       |        ✅        |        —        |       —       |     —     |     —     |      —      |
| 50    | Inst. Phase O/C               |       —       |        ✅        |        ✅        |       ✅       |     ✅     |     ✅     |      —      |
| 50BF  | Breaker Failure               |       —       |        —        |        —        |       —       |     —     |     —     |      ✅      |
| 50N   | Inst. Earth Fault             |       —       |        ✅        |        ✅        |       ✅       |     ✅     |     ✅     |      —      |
| 51    | Time O/C (Phase)              |       —       |        ✅        |        ✅        |       ✅       |     ✅     |     ✅     |      —      |
| 51N   | Time E/F                      |       —       |        ✅        |        ✅        |       ✅       |     ✅     |     ✅     |      —      |
| 59    | Overvoltage                   |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 64REF | Restricted E/F                |       —       |        ✅        |        ✅        |       —       |     —     |     —     |      —      |
| 67    | Directional Phase O/C         |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 67N   | Directional E/F               |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 74TC  | Trip Circuit Supervision      |       —       |        —        |        —        |       —       |     —     |     —     |      ✅      |
| 79    | Auto-Reclose                  |       —       |        —        |        —        |       —       |     —     |     ✅     |      —      |
| 87B   | Busbar Differential           |       —       |        —        |        —        |       —       |     —     |     —     |      ✅      |
| 87REF | Restricted Differential (REF) |       ✅       |        —        |        —        |       —       |     —     |     —     |      —      |
| 87T   | Transformer Differential      |       ✅       |        —        |        —        |       —       |     —     |     —     |      —      |

### 17.2 Protection Coverage Summary

| Protection Level       | Primary Protection      | Backup Protection                   |
| ---------------------- | ----------------------- | ----------------------------------- |
| 150kV Transformer (HV) | MiCOM P643 (87T, 87REF) | MiCOM P142-F501 (51, 51N)           |
| 150kV Transformer (LV) | MiCOM P643 (87T)        | MiCOM P142-F502 (51, 51N)           |
| 150kV Busbar           | MiCOM P746 ×3 (87B)    | MiCOM P543 Zone 3 (21) + CBF (50BF) |
| 150kV Line             | MiCOM P543 (21, Zone 1) | MiCOM P142 (51, 51N)                |
| Bus Coupler            | MiCOM P143 (50/51)      | Busbar P746 boundary zone           |
| Tap Changer            | REG-DA (AVR control)    | P643 OLTC supervision               |

---

*End of Document*

---

**Document:** GI 150kV ANTAM POMALAA — Substation Automation System Architecture
**Source Drawing:** E2010-96317-BD-01-SAD Rev. A
**Manufacturer:** PT. Schneider Indonesia — Infrastructure Business
**Classification:** Technical Reference Documentation
