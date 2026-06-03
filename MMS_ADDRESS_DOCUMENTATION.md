# GI 150kV A — IEC 61850 MMS Addressing & Codebase Analysis

**Line Bay Protection & Control Integration Guide**

---

## 1. Executive Summary & System Context

This document provides a comprehensive technical audit of the **GI 150kV a Substation Simulator Suite**, focusing specifically on the **MMS (Manufacturing Message Specification)** addressing schema and control models for the **Line-1 (Bay E05)** and **Line-2 (Bay E06)** IEDs (Intelligent Electronic Devices).

The simulation suite runs as a fully distributed system on local or station networks. Each IED operates as an independent compiled process containing:

- A dedicated **MMS Server** (TCP port per IED) for SCADA HMI client telemetry and remote control.
- A **GOOSE Publisher/Subscriber** engine executing over Layer 2 raw Ethernet frames for sub-4ms protection trips and interlocking.

---

## 2. Line Bay Network Mapping

In both local simulation and physical/station networks, the line bays are divided into three distinct physical IEDs per bay: the **Bay Control Unit (BCU)**, the **Distance Protection Relay (Main)**, and the **Overcurrent Protection Relay (Backup)**.

### Bay Network & Port Allocations

| Bay              | IED Name   | Role                                  | Local Loop IP | Local Port | Station Network IP     |
| :--------------- | :--------- | :------------------------------------ | :------------ | :--------- | :--------------------- |
| **E05 (Line-1)** | `E05_BCU`  | Bay Control & Switch Interlocking     | `127.0.0.1`   | **10205**  | `10.0.5.1` (Port 102)  |
|                  | `E05_P543` | Main Distance Protection (21)         | `127.0.0.1`   | **10251**  | `10.0.5.11` (Port 102) |
|                  | `E05_P142` | Backup Overcurrent Protection (50/51) | `127.0.0.1`   | **10252**  | `10.0.5.12` (Port 102) |
| **E06 (Line-2)** | `E06_BCU`  | Bay Control & Switch Interlocking     | `127.0.0.1`   | **10206**  | `10.0.6.1` (Port 102)  |
|                  | `E06_P543` | Main Distance Protection (21)         | `127.0.0.1`   | **10261**  | `10.0.6.11` (Port 102) |
|                  | `E06_P142` | Backup Overcurrent Protection (50/51) | `127.0.0.1`   | **10262**  | `10.0.6.12` (Port 102) |

---

## 3. MMS Address Mapping Directory

The following tables present the precise ACSI (Abstract Communication Service Interface) paths and MMS addresses for reading telemetry and executing control operations.

> [!NOTE]
> All telemetry, switch control, and interlocking are hosted on the **BCU IEDs** (`E05_BCU` / `E06_BCU`). The protection relays (`P543` and `P142`) do not host control points; instead, they trigger the BCUs via Layer 2 GOOSE multicast trips.

### 3.1. Line-1 Bay (E05) MMS Address Book

- **IED Prefix**: `E05_BCU`
- **Logical Device**: `E05BCU`

| Component              | Equipment Name | Logical Node | Functional Constraint (FC) | Telemetry / Control Path    | MMS Type / Description                                | Control Model                                       |
| :--------------------- | :------------- | :----------- | :------------------------- | :-------------------------- | :---------------------------------------------------- | :-------------------------------------------------- |
| **Circuit Breaker**    | **CB1**        | `XCBR1`      | **ST** (Status)            | `E05BCU/XCBR1.Pos.stVal`    | `Dbpos` (0: Intermediate, 1: Open, 2: Closed, 3: Bad) | **Select-Before-Operate (SBO)** ``_Normal Security_ |
|                        |                |              | **ST** (Status)            | `E05BCU/XCBR1.Pos.q`        | `Quality` (13-bit BitString)                          |                                                     |
|                        |                |              | **ST** (Status)            | `E05BCU/XCBR1.Pos.t`        | `TimeStamp` (UTC time)                                |                                                     |
|                        |                |              | **CF** (Config)            | `E05BCU/XCBR1.Pos.ctlModel` | `Enum` (returns `2` = `sbo-with-normal-security`)     |                                                     |
|                        |                |              | **CO** (Control)           | `E05BCU/XCBR1.Pos.SBOw`     | `Structure` (Select Struct for enhanced operation)    |                                                     |
|                        |                |              | **CO** (Control)           | `E05BCU/XCBR1.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Bus-A Disconnector** | **DS-A**       | `XSWI1`      | **ST** (Status)            | `E05BCU/XSWI1.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** ``_Normal Security_              |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI1.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI1.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E05BCU/XSWI1.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E05BCU/XSWI1.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Bus-B Disconnector** | **DS-B**       | `XSWI2`      | **ST** (Status)            | `E05BCU/XSWI2.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** `*Normal Security*`              |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI2.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI2.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E05BCU/XSWI2.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E05BCU/XSWI2.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Line Disconnector**  | **Line DS**    | `XSWI3`      | **ST** (Status)            | `E05BCU/XSWI3.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** `*Normal Security*`              |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI3.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI3.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E05BCU/XSWI3.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E05BCU/XSWI3.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Earthing Switch**    | **ES**         | `XSWI4`      | **ST** (Status)            | `E05BCU/XSWI4.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** `*Normal Security*`              |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI4.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E05BCU/XSWI4.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E05BCU/XSWI4.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E05BCU/XSWI4.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |

---

### 3.2. Line-2 Bay (E06) MMS Address Book

- **IED Prefix**: `E06_BCU`
- **Logical Device**: `E06BCU`

| Component              | Equipment Name | Logical Node | Functional Constraint (FC) | Telemetry / Control Path    | MMS Type / Description                                | Control Model                                       |
| :--------------------- | :------------- | :----------- | :------------------------- | :-------------------------- | :---------------------------------------------------- | :-------------------------------------------------- |
| **Circuit Breaker**    | **CB1**        | `XCBR1`      | **ST** (Status)            | `E06BCU/XCBR1.Pos.stVal`    | `Dbpos` (0: Intermediate, 1: Open, 2: Closed, 3: Bad) | **Select-Before-Operate (SBO)** ``_Normal Security_ |
|                        |                |              | **ST** (Status)            | `E06BCU/XCBR1.Pos.q`        | `Quality` (13-bit BitString)                          |                                                     |
|                        |                |              | **ST** (Status)            | `E06BCU/XCBR1.Pos.t`        | `TimeStamp` (UTC time)                                |                                                     |
|                        |                |              | **CF** (Config)            | `E06BCU/XCBR1.Pos.ctlModel` | `Enum` (returns `2` = `sbo-with-normal-security`)     |                                                     |
|                        |                |              | **CO** (Control)           | `E06BCU/XCBR1.Pos.SBOw`     | `Structure` (Select Struct for enhanced operation)    |                                                     |
|                        |                |              | **CO** (Control)           | `E06BCU/XCBR1.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Bus-A Disconnector** | **DS-A**       | `XSWI1`      | **ST** (Status)            | `E06BCU/XSWI1.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** ``_Normal Security_              |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI1.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI1.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E06BCU/XSWI1.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E06BCU/XSWI1.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Bus-B Disconnector** | **DS-B**       | `XSWI2`      | **ST** (Status)            | `E06BCU/XSWI2.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** `*Normal Security*`              |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI2.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI2.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E06BCU/XSWI2.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E06BCU/XSWI2.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Line Disconnector**  | **Line DS**    | `XSWI3`      | **ST** (Status)            | `E06BCU/XSWI3.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** `*Normal Security*`              |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI3.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI3.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E06BCU/XSWI3.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E06BCU/XSWI3.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |
| **Earthing Switch**    | **ES**         | `XSWI4`      | **ST** (Status)            | `E06BCU/XSWI4.Pos.stVal`    | `Dbpos` (1: Open, 2: Closed)                          | **Direct Control** `*Normal Security*`              |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI4.Pos.q`        | `Quality`                                             |                                                     |
|                        |                |              | **ST** (Status)            | `E06BCU/XSWI4.Pos.t`        | `TimeStamp`                                           |                                                     |
|                        |                |              | **CF** (Config)            | `E06BCU/XSWI4.Pos.ctlModel` | `Enum` (returns `1` = `direct-with-normal-security`)  |                                                     |
|                        |                |              | **CO** (Control)           | `E06BCU/XSWI4.Pos.Oper`     | `Structure` (Operate command struct)                  |                                                     |

---

## 4. ACSI Command Structure (MMS Control Payload)

Operating switches via MMS requires writing to a complex structure containing control qualifiers. For `libiec61850` servers, both **Select (`SBOw`)** and **Operate (`Oper`)** commands must supply the following leaf attributes:

```
[ACSI Path].Oper
  ├── ctlVal     : Boolean  (FALSE = Open / Trip, TRUE = Close)
  ├── origin     : Struct   (Command Source info)
  │     ├── orCat   : Integer  (1 = Station Control, 2 = Remote/SCADA, 3 = Local)
  │     └── orIdent : String   (Identifier string of client, e.g., "SCADA_HMI_01")
  ├── ctlNum     : Integer  (Command sequence/counter identifier, 0 - 255)
  ├── T          : UtcTime  (Command timestamp)
  ├── Test       : Boolean  (FALSE = Normal command execution, TRUE = Test mode)
  └── Check      : BitString (Synchrocheck/Interlocking override: Bit 0=Synchro, Bit 1=Interlock)
```

---

## 5. Critical Codebase Findings & SCADA Discrepancies

During our comprehensive architectural audit of the `SAS_Server` and `iec61850-client` codebases, we discovered a vital integration detail that SCADA gateway integrators must be aware of:

> [!WARNING]
> **Switch Instantiation Dynamics Based on Bay Type:**
>
> Following the recent CID generation updates, switchgear nodes (`XSWI1`, `XSWI2`, `XSWI3`, `XSWI4`) are now **dynamically compiled** depending on the specific bay requirements:
>
> - **Line Bays (E05, E06)**: Fully instantiated with CB (`XCBR1`), Bus-A DS (`XSWI1`), Bus-B DS (`XSWI2`), Line DS (`XSWI3`), and Earth Switch (`XSWI4`).
> - **Transformer Bays (E01, E02, E03)**: Instantiated with CB (`XCBR1`), Bus-A DS (`XSWI1`), Bus-B DS (`XSWI2`), and Line DS (`XSWI3`). **No Earth Switch (`XSWI4`)** is present.
> - **Coupler Bay (E04)**: Instantiated with CB (`XCBR1`), Bus-A DS (`XSWI1`), and Bus-B DS (`XSWI2`). **No Line DS (`XSWI3`) or Earth Switch (`XSWI4`)** is present.
> - **Behavioral Impact**: Any SCADA MMS read/write requests targeting a non-existent node (e.g. `XSWI4` in E01) will correctly fail with an MMS **Object-Non-Existent** error.

### Why is this the case?

The simulator's `generate_per_ied_cid.py` script and `ied_c264_bcu.c` backend application logic were recently updated to accurately reflect the real-world physical switchgear configurations, ensuring exact parity with a double-busbar layout. Switchgear nodes that do not physically exist in a bay are deliberately excluded from the generated CID schema and data model to prevent unauthorized operations and maintain interlocking integrity.

---

## 6. Protection & Interlocking Logic Details

The `BCU` execution loop (`ied_c264_bcu.c`) enforces a strict, hardware-accurate interlocking sequence to protect the substation equipment:

1. **Active Protection Trip Lockout**:
   If a GOOSE trip signal is received from the main distance protection relay (`P543` via dataset `E05_P543E05P543/LLN0$GO$gcbTrip`) or the overcurrent protection relay (`P142`), the BCU opens the breaker (`XCBR1.Pos` -> `1` / Open) and **blocks all manual closing commands** until the fault is cleared and the relay is reset.
   - _Interlocking block error_: `INTERLOCKING BLOCKED — external GOOSE trip active (lockout)`

2. **Safety Earthing Switch Interlock**:
   - A manual breaker closing command is strictly **blocked** if the earthing switch (`earth_closed`) is active.
   - Closing the earthing switch is strictly **blocked** if the breaker (`cb_closed`) is in the closed position (`stVal = 2`).
   - _Interloc king block error_: `INTERLOCKING BLOCKED — earth switch closed` / `INTERLOCKING BLOCKED — CB closed`

---

## 7. Recommended Client Verification Commands

To verify reading and operating breaker and disconnector status from a command-line client, you can use the standard `libiec61850` utility tools or compile the local client process:

### Read Breaker Status (MMS Read)

```bash
# E05_BCU CB1 Status
mms_client_read -h 127.0.0.1 -p 10205 E05BCU/XCBR1.Pos.stVal

# E06_BCU CB1 Status
mms_client_read -h 127.0.0.1 -p 10206 E06BCU/XCBR1.Pos.stVal
```

### Direct Switch Control Operation (MMS Operate)

```bash
# Close DS-A on Line-1 BCU (Direct Control)
mms_client_write -h 127.0.0.1 -p 10205 E05BCU/XSWI1.Pos.Oper.ctlVal=true
```
