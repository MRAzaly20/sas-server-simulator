# IEC 61850 MMS Protocol: Rules for Reading and Writing to IEC Addresses

**Document Type:** Technical Reference — Substation Automation Systems
**Standard Reference:** IEC 61850-7-1, 7-2, 7-3, 7-4, 8-1
**Revision:** 1.0
**Audience:** SAS Engineers, System Architects, SCADA Integrators

---

## Table of Contents

1. [Overview and Scope](#1-overview-and-scope)
2. [IEC 61850 Information Model Hierarchy](#2-iec-61850-information-model-hierarchy)
3. [Complete Address Structure](#3-complete-address-structure)
4. [MMS Address Encoding on the Wire](#4-mms-address-encoding-on-the-wire)
5. [Functional Constraints (FC) — The Access Control Mechanism](#5-functional-constraints-fc--the-access-control-mechanism)
6. [Rules for Reading IEC 61850 Addresses](#6-rules-for-reading-iec-61850-addresses)
7. [Rules for Writing IEC 61850 Addresses](#7-rules-for-writing-iec-61850-addresses)
8. [What Cannot Be Written — Hard Restrictions](#8-what-cannot-be-written--hard-restrictions)
9. [Control Model (FC=CO) — Detailed Write Rules](#9-control-model-fcco--detailed-write-rules)
10. [Setting Group Services (FC=SE) — Write Rules](#10-setting-group-services-fcse--write-rules)
11. [Common Data Classes (CDC) and Their FC Decomposition](#11-common-data-classes-cdc-and-their-fc-decomposition)
12. [MMS Service Primitives Mapping](#12-mms-service-primitives-mapping)
13. [Access Control and Security Considerations](#13-access-control-and-security-considerations)
14. [Engineering Reference: Address Construction Examples](#14-engineering-reference-address-construction-examples)
15. [Architectural Rules and Best Practices](#15-architectural-rules-and-best-practices)
16. [Quick Reference Summary Tables](#16-quick-reference-summary-tables)

---

## 1. Overview and Scope

### 1.1 Purpose

This document provides a complete, authoritative reference for all rules governing the **reading and writing of IEC 61850 addresses** via the **MMS (Manufacturing Message Specification, ISO 9506)** protocol, as mapped by IEC 61850-8-1.

IEC 61850 defines an abstract communication service interface (ACSI) that is mapped to MMS for client-server communication. Understanding how ACSI object references translate to MMS variable specifications — and which operations are permitted — is fundamental to correct integration of Intelligent Electronic Devices (IEDs), SCADA systems, gateways, and engineering tools.

### 1.2 Scope

This document covers:

- The complete IEC 61850 information model object hierarchy
- Full address structure syntax and MMS wire encoding
- All Functional Constraint (FC) categories and their access rules
- Read rules: permitted services, reference formats, and subscription patterns
- Write rules: three distinct write mechanisms (SetDataValues, Control, Setting Group)
- Hard restrictions on non-writable attributes
- Control model state machines (Direct, SBO, Enhanced Security)
- Common Data Class (CDC) decomposition by FC
- MMS service primitive mapping
- Access control and security model
- Practical engineering examples for all scenarios

### 1.3 Normative References

| Standard      | Title                                                   |
| ------------- | ------------------------------------------------------- |
| IEC 61850-7-1 | Basic communication structure — Principles and models   |
| IEC 61850-7-2 | Abstract communication service interface (ACSI)         |
| IEC 61850-7-3 | Common data classes (CDC)                               |
| IEC 61850-7-4 | Compatible logical node classes and data object classes |
| IEC 61850-8-1 | MMS mapping (SCSM)                                      |
| ISO 9506-1/2  | Manufacturing Message Specification (MMS)               |

---

## 2. IEC 61850 Information Model Hierarchy

The IEC 61850 information model is a strict four-level hierarchy. Every addressable element sits at a defined level, and the level determines the MMS construct it maps to.

```
┌─────────────────────────────────────────────────────────────────────────┐
│  Level 1: IED (Intelligent Electronic Device)                           │
│           └── MMS Server                                                │
│                                                                         │
│  ┌───────────────────────────────────────────────────────────────────┐  │
│  │  Level 2: Logical Device (LD)                                     │  │
│  │           └── MMS Domain                                          │  │
│  │                                                                   │  │
│  │  ┌─────────────────────────────────────────────────────────────┐  │  │
│  │  │  Level 3: Logical Node (LN)                                 │  │  │
│  │  │           └── MMS Named Variable (structured)               │  │  │
│  │  │                                                             │  │  │
│  │  │  ┌───────────────────────────────────────────────────────┐  │  │  │
│  │  │  │  Level 4: Data Object (DO) → Data Attribute (DA)      │  │  │  │
│  │  │  │           └── MMS Named Variable (leaf)               │  │  │  │
│  │  │  │           └── Governed by Functional Constraint (FC)  │  │  │  │
│  │  │  └───────────────────────────────────────────────────────┘  │  │  │
│  │  └─────────────────────────────────────────────────────────────┘  │  │
│  └───────────────────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────────────────┘
```

### 2.1 Level Descriptions

| Level | Object                                 | Standard Reference | MMS Construct           | Example     |
| ----- | -------------------------------------- | ------------------ | ----------------------- | ----------- |
| 1     | IED                                    | IEC 61850-7-1 §5   | MMS Server              | `IED1`      |
| 2     | Logical Device (LD)                    | IEC 61850-7-1 §5.5 | MMS Domain              | `IED1CTRL`  |
| 3     | Logical Node (LN)                      | IEC 61850-7-4      | MMS Named Variable      | `XCBR1`     |
| 4     | Data Object (DO) / Data Attribute (DA) | IEC 61850-7-3, 7-4 | MMS Named Variable leaf | `Pos.stVal` |

### 2.2 Logical Node Classes (Selected)

Logical Node classes are defined in IEC 61850-7-4 and grouped by function domain:

| LN Group           | Prefix | Function                        | Example LNs            |
| ------------------ | ------ | ------------------------------- | ---------------------- |
| System             | L      | System-level LNs                | `LLN0`, `LPHD`         |
| Protection         | P      | Protection functions            | `PTOC`, `PDIF`, `PDIR` |
| Protection-related | R      | Auto-reclose, interlocking      | `RREC`, `RDIR`         |
| Control            | C      | Control functions               | `CSWI`, `CALH`         |
| Measurement        | M      | Analog measurements             | `MMXU`, `MMTR`         |
| Switchgear         | X      | Circuit breakers, disconnectors | `XCBR`, `XSWI`         |
| Instrument Xfmr    | T      | Transformers                    | `TCTR`, `TVTR`         |
| General            | G      | Generic functions               | `GGIO`, `GAPC`         |

---

## 3. Complete Address Structure

### 3.1 ACSI Object Reference Syntax

The canonical IEC 61850 ACSI address has the following structure:

```
<IED_Name> / <LD_Inst> / <LN_Prefix><LN_Class><LN_Inst> . <DO_Name> . <DA_Name> [FC]
```

**Field Definitions:**

| Field       | Description                                      | Constraints                | Example                |
| ----------- | ------------------------------------------------ | -------------------------- | ---------------------- |
| `IED_Name`  | IED identifier from SCL `IED name=` attribute    | Max 64 chars, alphanumeric | `IED1`, `PROT_A`       |
| `LD_Inst`   | Logical Device instance from SCL `LDevice inst=` | Max 64 chars               | `CTRL`, `MEAS`, `PROT` |
| `LN_Prefix` | Optional prefix to distinguish LN instances      | 0–11 chars                 | `" "`, `MAIN`          |
| `LN_Class`  | Logical Node class (IEC 61850-7-4)               | Exactly 4 chars            | `XCBR`, `MMXU`, `PTOC` |
| `LN_Inst`   | Instance number                                  | Numeric string             | `1`, `2`, `01`         |
| `DO_Name`   | Data Object name (from CDC definition)           | IEC 61850-7-4 defined      | `Pos`, `Hz`, `Op`      |
| `DA_Name`   | Data Attribute name (may be nested)              | IEC 61850-7-3 defined      | `stVal`, `mag.f`, `q`  |
| `[FC]`      | Functional Constraint (implicit in context)      | One of 11 valid FCs        | `[ST]`, `[MX]`, `[CO]` |

### 3.2 Address Examples — Full Decomposition

#### Example 1: Circuit Breaker Status

```
IED1CTRL / XCBR1 . Pos . stVal  [FC=ST]
│          │       │     │
│          │       │     └── DA: Status value (boolean CODED_ENUM)
│          │       └──────── DO: Position (CDC: DPC - Double Point Controllable)
│          └──────────────── LN: XCBR (Circuit Breaker), instance 1
│                            LD: IED1CTRL (IED1, Control logical device)
└─────────────────────────── IED: IED1
```

#### Example 2: Frequency Measurement

```
IED1MEAS / MMXU1 . Hz . mag . f  [FC=MX]
│          │       │    │     │
│          │       │    │     └── DA leaf: floating-point value
│          │       │    └──────── DA structure: magnitude component
│          │       └───────────── DO: Frequency (CDC: MV - Measured Value)
│          └───────────────────── LN: MMXU (Measurement Unit), instance 1
└──────────────────────────────── LD: IED1MEAS (Measurement logical device)
```

#### Example 3: Overcurrent Protection Setpoint

```
IED1PROT / PTOC1 . StrVal . setMag . f  [FC=SP]
│          │       │         │        │
│          │       │         │        └── DA leaf: float setpoint value
│          │       │         └─────────── DA: setpoint magnitude
│          │       └───────────────────── DO: Start value (CDC: ASG)
│          └───────────────────────────── LN: PTOC (Overcurrent protection)
└──────────────────────────────────────── LD: IED1PROT
```

#### Example 4: Control Operation

```
IED1CTRL / XCBR1 . Pos . Oper . ctlVal  [FC=CO]
│          │       │     │       │
│          │       │     │       └── DA: Control value (CODED_ENUM)
│          │       │     └────────── DA structure: Operate struct
│          │       └──────────────── DO: Position (DPC CDC)
│          └──────────────────────── LN: XCBR1
└──────────────────────────────────── LD: IED1CTRL
```

### 3.3 Nested Data Attribute Paths

Data Attributes may be nested structures. The path uses `.` separators in ACSI notation:

```
MMXU1.PhV.phsA.cVal.mag.f   [FC=MX]
│     │   │    │    │   │
│     │   │    │    │   └── float32 value
│     │   │    │    └────── magnitude component of complex
│     │   │    └─────────── complex value (CMV structure)
│     │   └──────────────── Phase A component
│     └──────────────────── Phase Voltage DO (WYE CDC)
└────────────────────────── LN: MMXU
```

### 3.4 Special Logical Nodes

Every Logical Device must contain two mandatory LNs:

| LN     | Name              | Purpose                              | Key DOs                          |
| ------ | ----------------- | ------------------------------------ | -------------------------------- |
| `LLN0` | Logical Node Zero | LD-level management, RCB, GoCB, SGCB | `Mod`, `Beh`, `Health`, `NamPlt` |
| `LPHD` | Physical Device   | Hardware information and health      | `PhyNam`, `PhyHealth`, `Proxy`   |

---

## 4. MMS Address Encoding on the Wire

### 4.1 ACSI-to-MMS Translation Rules

When IEC 61850 ACSI references are encoded as MMS variable specifications (IEC 61850-8-1 §12), the following rules apply:

| ACSI Element            | MMS Encoding                  | Separator        |
| ----------------------- | ----------------------------- | ---------------- |
| Logical Device          | MMS Domain name               | (domain context) |
| Logical Node            | First segment of MMS item ID  | `$`              |
| Functional Constraint   | Second segment of MMS item ID | `$`              |
| Data Object             | Third segment of MMS item ID  | `$`              |
| Data Attribute (nested) | Subsequent segments           | `$`              |

**Transformation Rule:**

```
ACSI:  <LD> / <LN> . <FC_group> . <DO> . <DA>
MMS:   Domain=<IED_Name><LD_Inst>  ItemID=<LN>$<FC>$<DO>$<DA>
```

### 4.2 Wire Encoding Examples

| ACSI Reference                        | MMS Domain | MMS Item ID                |
| ------------------------------------- | ---------- | -------------------------- |
| `IED1CTRL/XCBR1.Pos.stVal [ST]`       | `IED1CTRL` | `XCBR1$ST$Pos$stVal`       |
| `IED1CTRL/XCBR1.Pos.Oper.ctlVal [CO]` | `IED1CTRL` | `XCBR1$CO$Pos$Oper$ctlVal` |
| `IED1MEAS/MMXU1.Hz.mag.f [MX]`        | `IED1MEAS` | `MMXU1$MX$Hz$mag$f`        |
| `IED1PROT/PTOC1.StrVal.setMag.f [SP]` | `IED1PROT` | `PTOC1$SP$StrVal$setMag$f` |
| `IED1CTRL/LLN0.BRCB01.RptID [BR]`     | `IED1CTRL` | `LLN0$BR$BRCB01$RptID`     |

### 4.3 MMS Variable Access Specification Structure

In MMS PDU encoding (BER/ASN.1), an IEC 61850 variable is referenced as:

```
VariableAccessSpecification ::= CHOICE {
  listOfVariable  [0] SEQUENCE OF VariableSpecification,
  variableListName [1] ObjectName
}

VariableSpecification ::= CHOICE {
  name [0] ObjectName   -- domain-specific: domain + item
}

ObjectName ::= CHOICE {
  domain-specific [1] SEQUENCE {
    domainId    Identifier,    -- e.g. "IED1CTRL"
    itemId      Identifier     -- e.g. "XCBR1$ST$Pos$stVal"
  }
}
```

### 4.4 Reading an Entire Data Object (All FCs)

To read all DAs of a DO across all FCs, the MMS client must issue **separate ReadRequests per FC**. There is no single MMS read that retrieves all FC partitions simultaneously.

```
Read Request 1: Domain=IED1CTRL  ItemID=XCBR1$ST$Pos     (ST partition)
Read Request 2: Domain=IED1CTRL  ItemID=XCBR1$CF$Pos     (CF partition)
Read Request 3: Domain=IED1CTRL  ItemID=XCBR1$CO$Pos     (CO partition)
```

---

## 5. Functional Constraints (FC) — The Access Control Mechanism

### 5.1 Principle

The **Functional Constraint (FC)** is the primary access control mechanism in IEC 61850. Every Data Attribute belongs to exactly one FC group. The FC determines:

- Whether the DA can be read
- Whether the DA can be written
- Which MMS service or ACSI service must be used
- Whether additional preconditions must be met before access

The FC is not optional metadata. It is a structural property of every DA defined in IEC 61850-7-3 CDCs and IEC 61850-7-4 DO definitions.

### 5.2 Complete Functional Constraint Reference

#### FC=ST — Status (IEC 61850-7-2 §6.2.2)

| Property              | Value                                                                       |
| --------------------- | --------------------------------------------------------------------------- |
| Full name             | Status                                                                      |
| Read                  | **Permitted** — `GetDataValues`                                             |
| Write (SetDataValues) | **Prohibited**                                                              |
| Write (Control)       | N/A                                                                         |
| Source of values      | Live process values updated by device firmware                              |
| Typical DAs           | `stVal`, `q` (quality), `t` (timestamp)                                     |
| Use case              | Real-time status of primary equipment (breaker open/closed)                 |
| Notes                 | Values are process-driven; client writes are rejected by conformant servers |

**Example DAs under FC=ST:**

```
XCBR1$ST$Pos$stVal     -- DPC: double-point status (intermediate/off/on/bad)
XCBR1$ST$Pos$q         -- Quality (validity, source, test, operator-blocked)
XCBR1$ST$Pos$t         -- Timestamp of last change
GGIO1$ST$Ind1$stVal    -- Boolean status input
MMXU1$ST$OpTmh$stVal   -- Operating time in hours
```

---

#### FC=MX — Measured Values (IEC 61850-7-2 §6.2.3)

| Property              | Value                                                            |
| --------------------- | ---------------------------------------------------------------- |
| Full name             | Measured Values                                                  |
| Read                  | **Permitted** — `GetDataValues`                                  |
| Write (SetDataValues) | **Prohibited**                                                   |
| Source of values      | Transducer/ADC measurements updated by device in real-time       |
| Typical DAs           | `mag.f`, `ang.f`, `instMag.f`, `q`, `t`                          |
| Use case              | Analog measurements: voltage, current, power, frequency          |
| Notes                 | Substitution of MX values must use FC=SV, not direct write to MX |

**Example DAs under FC=MX:**

```
MMXU1$MX$Hz$mag$f      -- Frequency magnitude (float32)
MMXU1$MX$A$phsA$cVal$mag$f   -- Phase A current magnitude
MMXU1$MX$W$phsA$cVal$mag$f   -- Active power phase A
TVTR1$MX$Vol$mag$f     -- Voltage transformer secondary output
```

---

#### FC=SP — Setpoints (IEC 61850-7-2 §6.2.4)

| Property              | Value                                                   |
| --------------------- | ------------------------------------------------------- |
| Full name             | Setpoints (Set Point)                                   |
| Read                  | **Permitted** — `GetDataValues`                         |
| Write (SetDataValues) | **Permitted**                                           |
| MMS Service           | `WriteRequest`                                          |
| Preconditions         | Client must have write access;`Mod` of LN must be ON    |
| Typical DAs           | `setMag.f`, `setAng.f`, `setVal`, `maxLim`, `minLim`    |
| Use case              | Protection thresholds, deadbands, limit values          |
| Notes                 | Writes take immediate effect; no state machine required |

**Example DAs under FC=SP:**

```
PTOC1$SP$StrVal$setMag$f    -- Overcurrent pickup level (float)
PTOC1$SP$TmMult$setMag$f    -- Time multiplier setting
MMXU1$SP$Hz$db$f            -- Frequency deadband
GGIO1$SP$AnIn1$db$f         -- Analog input deadband
```

---

#### FC=SV — Substituted Values (IEC 61850-7-2 §6.2.5)

| Property              | Value                                                                            |
| --------------------- | -------------------------------------------------------------------------------- |
| Full name             | Substituted Values                                                               |
| Read                  | **Permitted** — `GetDataValues`                                                  |
| Write (SetDataValues) | **Permitted**                                                                    |
| MMS Service           | `WriteRequest`                                                                   |
| Preconditions         | `subEna` must be set TRUE to activate substitution                               |
| Typical DAs           | `subVal`, `subQ`, `subID`, `subEna`                                              |
| Use case              | Maintenance mode — substitute analog or status values for testing                |
| Notes                 | When `subEna=TRUE`, the substituted value overrides the process value in reports |

**Example DAs under FC=SV:**

```
MMXU1$SV$Hz$subVal$mag$f    -- Substitute frequency value
MMXU1$SV$Hz$subQ            -- Substitute quality flags
MMXU1$SV$Hz$subID           -- Substitutor identity string
MMXU1$SV$Hz$subEna          -- Enable substitution (BOOLEAN, write TRUE to activate)
```

**Substitution Activation Sequence:**

```
Step 1: Write MMXU1$SV$Hz$subVal$mag$f = 50.0   (set substitute value)
Step 2: Write MMXU1$SV$Hz$subEna = TRUE           (activate substitution)
Step 3: Reports will now show subVal with quality source=substituted
Step 4: Write MMXU1$SV$Hz$subEna = FALSE          (deactivate, restore process value)
```

---

#### FC=CF — Configuration (IEC 61850-7-2 §6.2.6)

| Property              | Value                                                               |
| --------------------- | ------------------------------------------------------------------- |
| Full name             | Configuration                                                       |
| Read                  | **Permitted** — `GetDataValues`                                     |
| Write (SetDataValues) | **Permitted**                                                       |
| MMS Service           | `WriteRequest`                                                      |
| Preconditions         | Client write privilege; typically requires engineering access level |
| Typical DAs           | `smpRate`, `smpMod`, `range`, `rangeC`, `units`                     |
| Use case              | Device configuration parameters (sampling rate, range, units)       |
| Notes                 | Changes may require device restart; no ACSI state machine required  |

**Example DAs under FC=CF:**

```
TCTR1$CF$Amp$smpRate        -- Sampled value sampling rate
TCTR1$CF$Amp$smpMod         -- Sampling mode (SPS/DPS)
MMXU1$CF$Hz$range$rangeC$hhLim$f   -- High-high limit for frequency range
GGIO1$CF$AnIn1$units$SIUnit        -- SI Unit for analog input
```

---

#### FC=DC — Description (IEC 61850-7-2 §6.2.7)

| Property              | Value                                                            |
| --------------------- | ---------------------------------------------------------------- |
| Full name             | Description                                                      |
| Read                  | **Permitted** — `GetDataValues`                                  |
| Write (SetDataValues) | **Prohibited**                                                   |
| Source                | Loaded from SCL configuration file at engineering time           |
| Typical DAs           | `d` (description), `dU` (Unicode description)                    |
| Use case              | Human-readable labels for DOs and LNs                            |
| Notes                 | Static text set during IED configuration; not modifiable via MMS |

---

#### FC=EX — Extended Definition (IEC 61850-7-2 §6.2.8)

| Property              | Value                                                  |
| --------------------- | ------------------------------------------------------ |
| Full name             | Extended Definitions                                   |
| Read                  | **Permitted** — `GetDataValues`                        |
| Write (SetDataValues) | **Prohibited**                                         |
| Source                | Vendor-defined, static                                 |
| Use case              | Manufacturer-specific extensions to the standard model |
| Notes                 | Definitions are fixed at manufacturing time            |

---

#### FC=SE — Setting Group Edit (IEC 61850-7-2 §6.2.9)

| Property              | Value                                                           |
| --------------------- | --------------------------------------------------------------- |
| Full name             | Setting Group Edition                                           |
| Read                  | **Permitted** — `GetDataValues`                                 |
| Write (SetDataValues) | **Permitted** — but only within SGCB EDIT context               |
| MMS Service           | `WriteRequest` (after SGCB service sequence)                    |
| Preconditions         | SGCB must be in EDIT mode (`SelectEditSG` must be called first) |
| Typical DAs           | Same structure as SP DAs, but stored per setting group number   |
| Use case              | Editing protection relay setting groups (up to 8 groups per LN) |
| Notes                 | Writes outside SGCB EDIT context are rejected. See Section 10.  |

---

#### FC=CO — Control (IEC 61850-7-2 §6.2.10)

| Property              | Value                                                                        |
| --------------------- | ---------------------------------------------------------------------------- |
| Full name             | Control                                                                      |
| Read                  | **Permitted** — `GetDataValues` (status readback)                            |
| Write (SetDataValues) | **Prohibited**                                                               |
| Write (Control)       | **Permitted** — via ACSI Control Model services only                         |
| MMS Services          | `WriteRequest` to specific control DAs (`$SBO`, `$Oper`, `$SBOw`)            |
| Preconditions         | See Section 9 for full control model state machine                           |
| Typical DAs           | `ctlVal`, `operTm`, `origin`, `ctlNum`, `T`, `Test`, `Check`                 |
| Use case              | Operating primary equipment: open/close breakers, raise/lower tap changers   |
| Notes                 | Direct `SetDataValues` to CO DAs is rejected; must use control state machine |

---

#### FC=OR — Operate Received (IEC 61850-7-2 §6.2.11)

| Property              | Value                                                         |
| --------------------- | ------------------------------------------------------------- |
| Full name             | Operate Received                                              |
| Read                  | **Permitted** — `GetDataValues`                               |
| Write (SetDataValues) | **Prohibited**                                                |
| Source                | Internal device record, populated when an Operate is received |
| Typical DAs           | `operTm` (operate timestamp), `or.orIdent`, `or.orCat`        |
| Use case              | Auditing and logging of control operations                    |

---

#### FC=BL — Blocking (IEC 61850-7-2 §6.2.12)

| Property              | Value                                                                        |
| --------------------- | ---------------------------------------------------------------------------- |
| Full name             | Blocking                                                                     |
| Read                  | **Permitted** — `GetDataValues`                                              |
| Write (SetDataValues) | **Conditional** — implementation-defined                                     |
| Source                | Internal interlocking and blocking logic                                     |
| Typical DAs           | `blkOpn`, `blkCls`                                                           |
| Use case              | Interlocking — blocking open or close operations                             |
| Notes                 | Write support is implementation-defined; many servers reject external writes |

---

#### FC=BR / FC=RP — Buffered and Unbuffered Report Control Blocks

| FC   | Name           | Read | Write | Purpose                                             |
| ---- | -------------- | ---- | ----- | --------------------------------------------------- |
| `BR` | Buffered RCB   | Yes  | Yes   | Configure Buffered Report Control Block on `LLN0`   |
| `RP` | Unbuffered RCB | Yes  | Yes   | Configure Unbuffered Report Control Block on `LLN0` |

Report Control Block DAs (under `LLN0`):

```
LLN0$BR$BRCB01$RptID       -- Report identifier (VISIBLE_STRING, writable)
LLN0$BR$BRCB01$RptEna      -- Enable reporting (BOOLEAN, writable)
LLN0$BR$BRCB01$DatSet      -- Dataset reference (VISIBLE_STRING, writable)
LLN0$BR$BRCB01$ConfRev     -- Configuration revision (UINT32, read-only)
LLN0$BR$BRCB01$OptFlds     -- Optional fields bitmask (writable)
LLN0$BR$BRCB01$BufTm       -- Buffer time in ms (writable)
LLN0$BR$BRCB01$TrgOps      -- Trigger options (dchg/qchg/dupd/period) (writable)
LLN0$BR$BRCB01$IntgPd      -- Integrity period in ms (writable)
LLN0$BR$BRCB01$Resv        -- Reservation flag (BOOLEAN, writable)
LLN0$BR$BRCB01$EntryID     -- Last sent entry ID (read-only)
LLN0$BR$BRCB01$TimeOfEntry -- Timestamp of last entry (read-only)
```

---

### 5.3 FC Access Rights Summary Table

| FC  | Name                  | Read | SetDataValues | Control Services | SE Services | Notes                                 |
| --- | --------------------- | :--: | :-----------: | :--------------: | :---------: | ------------------------------------- |
| ST  | Status                |  ✅  |      ❌       |        ❌        |     ❌      | Process-driven, read-only             |
| MX  | Measured Values       |  ✅  |      ❌       |        ❌        |     ❌      | Transducer-driven, read-only          |
| SP  | Setpoints             |  ✅  |      ✅       |        ❌        |     ❌      | Direct write permitted                |
| SV  | Substituted Values    |  ✅  |      ✅       |        ❌        |     ❌      | Requires subEna=TRUE to activate      |
| CF  | Configuration         |  ✅  |      ✅       |        ❌        |     ❌      | Engineering access typically required |
| DC  | Description           |  ✅  |      ❌       |        ❌        |     ❌      | SCL-loaded, static                    |
| EX  | Extended Definition   |  ✅  |      ❌       |        ❌        |     ❌      | Vendor-static                         |
| SE  | Setting Group Edit    |  ✅  |      ✅       |        ❌        |     ✅      | Requires SGCB EDIT mode               |
| CO  | Control               |  ✅  |      ❌       |        ✅        |     ❌      | ACSI control state machine only       |
| OR  | Operate Received      |  ✅  |      ❌       |        ❌        |     ❌      | Internal record, read-only            |
| BL  | Blocking              |  ✅  |      ⚠️       |        ❌        |     ❌      | Implementation-defined                |
| BR  | Buffered RCB          |  ✅  |      ✅       |        ❌        |     ❌      | Configure via SetDataValues           |
| RP  | Unbuffered RCB        |  ✅  |      ✅       |        ❌        |     ❌      | Configure via SetDataValues           |
| GO  | GOOSE Control Block   |  ✅  |      ✅       |        ❌        |     ❌      | Configure GoCB                        |
| SG  | Setting Group Control |  ✅  |      ⚠️       |        ❌        |     ✅      | Limited writes via SGCB services      |

---

## 6. Rules for Reading IEC 61850 Addresses

### 6.1 Fundamental Reading Rule

**All Data Attributes are readable regardless of Functional Constraint**, subject to access control configuration in the SCL file and server implementation.

### 6.2 MMS Read Service

The ACSI `GetDataValues` service maps to the MMS `ReadRequest` PDU.

**MMS ReadRequest structure:**

```
ReadRequest ::= SEQUENCE {
  variableAccessSpecification  VariableAccessSpecification,
  specWithResult               [0] BOOLEAN DEFAULT FALSE
}
```

**Response — MMS ReadResponse:**

```
ReadResponse ::= SEQUENCE {
  variableAccessSpecification  [0] VariableAccessSpecification OPTIONAL,
  listOfAccessResult           SEQUENCE OF AccessResult
}
```

### 6.3 Granularity of Read Operations

IEC 61850 supports reading at multiple levels of granularity:

| Read Scope              | ACSI Service             | Description                 | Example MMS Item ID       |
| ----------------------- | ------------------------ | --------------------------- | ------------------------- |
| Single DA               | `GetDataValues`          | Leaf attribute only         | `XCBR1$ST$Pos$stVal`      |
| All DAs of DO (one FC)  | `GetDataValues`          | Entire FC partition of a DO | `XCBR1$ST$Pos`            |
| All FC partitions of LN | `GetDataObjectDirectory` | Enumerate all DOs           | `XCBR1`                   |
| Named Variable List     | `GetDataSetValues`       | Pre-defined dataset         | `IED1CTRL/LLN0$DATASET01` |

### 6.4 Quality (q) and Timestamp (t) Reading

Every measurement or status DA is accompanied by mandatory quality and timestamp DAs under the same FC:

```
Pos$stVal  [FC=ST]  -- The value
Pos$q      [FC=ST]  -- Quality descriptor (see 6.4.1)
Pos$t      [FC=ST]  -- Timestamp (UTC, with time quality)
```

#### 6.4.1 Quality Bit Field Structure (IEC 61850-7-3 §6.5)

| Bit | Name            | Meaning                                       |
| --- | --------------- | --------------------------------------------- |
| 0-1 | validity        | 0=good, 1=invalid, 2=reserved, 3=questionable |
| 2   | overflow        | Value exceeds measurement range               |
| 3   | outOfRange      | Value outside defined range                   |
| 4   | badReference    | Reference value unavailable                   |
| 5   | oscillatory     | Value oscillating abnormally                  |
| 6   | failure         | Equipment or communication failure            |
| 7   | oldData         | Value not updated in expected time            |
| 8   | inconsistent    | Inconsistency between redundant values        |
| 9   | inaccurate      | Value inaccurate                              |
| 10  | source          | 0=process, 1=substituted                      |
| 11  | test            | Value is from test mode                       |
| 12  | operatorBlocked | Operator has blocked updates                  |

### 6.5 Subscription-Based Reading — Report Control Blocks (RCB)

For real-time monitoring, polling via `GetDataValues` is not recommended for operational systems. The preferred mechanism is **event-driven reporting** via RCBs.

**Trigger Options (TrgOps):**

| Trigger  | Bit | Description                                       |
| -------- | --- | ------------------------------------------------- |
| `dchg`   | 0   | Data change — value changes                       |
| `qchg`   | 1   | Quality change — quality flags change             |
| `dupd`   | 2   | Data update — any update (even if same value)     |
| `period` | 3   | Integrity period — periodic regardless of change  |
| `gi`     | 4   | General interrogation — client-initiated snapshot |

**RCB Configuration Sequence:**

```
1. Read LLN0$BR$BRCB01$Resv         -- Check if RCB is available
2. Write LLN0$BR$BRCB01$Resv = TRUE -- Reserve RCB
3. Write LLN0$BR$BRCB01$RptID = "CLIENT_001"
4. Write LLN0$BR$BRCB01$DatSet = "IED1CTRL/LLN0$DATASET_STATUS"
5. Write LLN0$BR$BRCB01$TrgOps = dchg|qchg|period
6. Write LLN0$BR$BRCB01$IntgPd = 60000   (60-second integrity)
7. Write LLN0$BR$BRCB01$RptEna = TRUE    (enable reporting)
8. Write LLN0$BR$BRCB01$GI = TRUE        (request general interrogation)
```

### 6.6 Reading Entire Logical Node Data

To read all process data from a Logical Node, issue `GetDataValues` at the LN level per FC:

```
ReadRequest: Domain=IED1CTRL  ItemID=XCBR1$ST    -- All ST data
ReadRequest: Domain=IED1CTRL  ItemID=XCBR1$MX    -- All MX data (if applicable)
ReadRequest: Domain=IED1CTRL  ItemID=XCBR1$SP    -- All SP data
```

### 6.7 Read Access Control

Read access may be restricted by:

1. **SCL AccessControl element** in `ICD`/`CID` files — limits which clients (IP ranges, certificate subjects) can read specific DAs
2. **Server implementation policy** — some vendors restrict DC and EX access to local engineering ports
3. **Authentication/Authorization** (IEC 62351-8) — role-based access control (RBAC) with roles: Viewer, Operator, Engineer, Installer, SecurityAdministrator

---

## 7. Rules for Writing IEC 61850 Addresses

### 7.1 Overview — Three Distinct Write Mechanisms

Writing to IEC 61850 addresses uses three fundamentally different mechanisms depending on the target FC:

```
┌─────────────────────────────────────────────────────────────────┐
│                    WRITE DECISION TREE                          │
│                                                                 │
│  Target DA FC?                                                  │
│       │                                                         │
│       ├── ST / MX / DC / EX / OR ──► WRITE PROHIBITED          │
│       │                                                         │
│       ├── SP / SV / CF / BR / RP ──► SetDataValues             │
│       │   (MMS WriteRequest)         (direct, no state machine) │
│       │                                                         │
│       ├── SE ──────────────────────► Setting Group Services     │
│       │   (MMS WriteRequest          (SGCB EDIT context first)  │
│       │    within SGCB context)                                 │
│       │                                                         │
│       └── CO ──────────────────────► Control Services          │
│           (MMS WriteRequest          (SBO or Direct-Operate     │
│            to specific DAs)          state machine)             │
└─────────────────────────────────────────────────────────────────┘
```

### 7.2 Mechanism 1 — Direct SetDataValues (SP / SV / CF)

#### 7.2.1 MMS WriteRequest

The ACSI `SetDataValues` service maps to the MMS `WriteRequest` PDU.

**MMS WriteRequest structure:**

```
WriteRequest ::= SEQUENCE {
  variableAccessSpecification  VariableAccessSpecification,
  listOfData                   SEQUENCE OF Data
}
```

#### 7.2.2 Write Preconditions

Before writing to SP/SV/CF DAs, all of the following must hold:

| Condition       | Check                                      | How to Verify              |
| --------------- | ------------------------------------------ | -------------------------- |
| LN Mode         | `Mod.stVal` must be `on` (1) or `test` (3) | Read `XCBR1$ST$Mod$stVal`  |
| Write Privilege | Client must have write role                | Server authentication/ACL  |
| Data Type Match | Written data type must match DA type       | Per CDC definition         |
| Value Range     | Value must be within defined `range`       | Read `$CF$xxx$range` first |

#### 7.2.3 MMS Write Response Handling

| MMS Result                      | Meaning                                | Action                       |
| ------------------------------- | -------------------------------------- | ---------------------------- |
| `success`                       | Write accepted and applied             | Confirm with subsequent read |
| `object-access-denied`          | Insufficient privileges                | Check access role            |
| `object-value-invalid`          | Type mismatch or range error           | Check value and type         |
| `object-attribute-inconsistent` | Precondition not met (e.g. LN blocked) | Check `Mod` and `Beh`        |
| `object-non-existent`           | Address does not exist                 | Verify address in SCL        |

#### 7.2.4 Direct Write Examples

**Write a protection setpoint (SP):**

```
Target:  IED1PROT/PTOC1.StrVal.setMag.f  [FC=SP]
MMS:     Domain=IED1PROT  ItemID=PTOC1$SP$StrVal$setMag$f
Data:    FLOAT32 = 1.25
Expected response: success
```

**Activate value substitution (SV):**

```
Target:  IED1MEAS/MMXU1.Hz.subVal.mag.f  [FC=SV]
MMS:     Domain=IED1MEAS  ItemID=MMXU1$SV$Hz$subVal$mag$f
Data:    FLOAT32 = 50.00

Target:  IED1MEAS/MMXU1.Hz.subEna  [FC=SV]
MMS:     Domain=IED1MEAS  ItemID=MMXU1$SV$Hz$subEna
Data:    BOOLEAN = TRUE
```

---

## 8. What Cannot Be Written — Hard Restrictions

### 8.1 Absolutely Non-Writable FCs

The following FCs **cannot be written under any circumstances** via `SetDataValues`:

| FC   | Reason                                                   | What to Do Instead                                          |
| ---- | -------------------------------------------------------- | ----------------------------------------------------------- |
| `ST` | Reflects live process state — device firmware-maintained | Use SV substitution for testing; use CO for control actions |
| `MX` | Analog measurement from transducer — hardware-driven     | Use SV substitution for testing                             |
| `DC` | Static text from SCL engineering tool                    | Modify SCL file and re-configure the IED                    |
| `EX` | Vendor firmware static                                   | Contact vendor; not modifiable remotely                     |
| `OR` | Internal operational record of received operates         | Read-only audit log                                         |

### 8.2 FC=CO — Cannot Use SetDataValues

Writing directly to FC=CO DAs via `SetDataValues` is **explicitly prohibited** by IEC 61850-7-2. A conformant server will respond with `object-access-denied` or `type-unsupported`.

The only correct write path is through the ACSI Control Model (see Section 9).

### 8.3 Attempting to Write Quality or Timestamp

Quality (`q`) and Timestamp (`t`) DAs are process-maintained attributes. Attempting to write these will be rejected:

```
Write to XCBR1$ST$Pos$q   → REJECTED (object-access-denied)
Write to XCBR1$ST$Pos$t   → REJECTED (object-access-denied)
Write to MMXU1$MX$Hz$q    → REJECTED (object-access-denied)
```

The only mechanism to affect quality is through substitution (`FC=SV`, write `subQ`).

### 8.4 Summary: Write Rejection Causes

| Rejection Cause              | MMS Error Code                  | Root Cause                          |
| ---------------------------- | ------------------------------- | ----------------------------------- |
| Non-writable FC              | `object-access-denied`          | Attempt to write ST, MX, DC, EX, OR |
| Wrong write mechanism for CO | `object-access-denied`          | Direct SetDataValues on control DA  |
| Client has no write role     | `object-access-denied`          | IEC 62351-8 RBAC — missing role     |
| LN is blocked/offline        | `object-attribute-inconsistent` | `Mod.stVal` is not ON               |
| Type mismatch                | `object-value-invalid`          | Wrong MMS data type sent            |
| Value out of range           | `object-value-invalid`          | Value exceeds `range` definition    |
| SE write outside EDIT mode   | `object-access-denied`          | SGCB not in EDIT mode               |
| Address does not exist       | `object-non-existent`           | Incorrect address construction      |

---

## 9. Control Model (FC=CO) — Detailed Write Rules

### 9.1 Overview

FC=CO DAs represent **control of primary equipment** (circuit breakers, disconnectors, tap changers, annunciators). The IEC 61850 control model is intentionally complex to enforce safety, authorization, and interlocking.

The `ctlModel` attribute (FC=CF) of a Data Object defines which control model applies:

| ctlModel Value | Name                            | Description                              |
| -------------- | ------------------------------- | ---------------------------------------- |
| 0              | `status-only`                   | No control possible                      |
| 1              | `direct-with-normal-security`   | Direct operate, no confirmation sequence |
| 2              | `sbo-with-normal-security`      | Select-Before-Operate required           |
| 3              | `direct-with-enhanced-security` | Direct operate with additional checks    |
| 4              | `sbo-with-enhanced-security`    | SBO with additional checks               |

### 9.2 Control DA Structure (DPC CDC Example)

For a Double Point Controllable (DPC) Data Object such as `Pos`:

```
Pos [DO — DPC CDC]
├── stVal      [FC=ST] -- Current process status (double-point enum)
├── q          [FC=ST] -- Status quality
├── t          [FC=ST] -- Status timestamp
├── SBO        [FC=CO] -- Select (for SBO models): write to initiate select
├── SBOw       [FC=CO] -- Select-with-value (enhanced SBO)
├── Oper       [FC=CO] -- Operate structure
│   ├── ctlVal         -- Control value (FALSE=open, TRUE=close for DPC)
│   ├── origin
│   │   ├── orCat      -- Origin category (0=not-supported to 6=maintenance)
│   │   └── orIdent    -- Origin identifier (string)
│   ├── ctlNum         -- Control number (sequence counter)
│   ├── T              -- Timestamp of command
│   ├── Test           -- Test flag (TRUE = test, not real operation)
│   └── Check          -- Interlock check bitmask (synchrocheck, interlockcheck)
├── Cancel     [FC=CO] -- Cancel pending operation
└── ctlVal     [FC=CO] -- Last commanded value (readable)
```

### 9.3 Direct Operate — ctlModel = 1 or 3

```
┌──────────┐                              ┌──────────┐
│  CLIENT  │                              │  SERVER  │
└────┬─────┘                              └────┬─────┘
     │                                         │
     │  WriteRequest: XCBR1$CO$Pos$Oper        │
     │  ctlVal=TRUE, Test=FALSE,               │
     │  Check=interlockCheck|synchroCheck      │
     │─────────────────────────────────────────>
     │                                         │
     │              [Server checks:            │
     │               - Authorization           │
     │               - Interlock logic         │
     │               - Mode/behaviour]         │
     │                                         │
     │<─────────────────────────────────────────
     │  WriteResponse: success / AddCause      │
     │                                         │
     │  [Server executes physical operation]   │
     │                                         │
     │  Report: stVal changes (via RCB)        │
     │<─────────────────────────────────────────
```

**AddCause values on rejection:**

| AddCause | Meaning                        |
| -------- | ------------------------------ |
| 0        | Unknown                        |
| 1        | Not supported                  |
| 2        | Blocked by switching hierarchy |
| 3        | Select failed                  |
| 4        | Invalid position               |
| 5        | Position reached               |
| 6        | Parameter change in execution  |
| 7        | Step limit                     |
| 8        | Blocked by mode                |
| 9        | Blocked by process             |
| 10       | Blocked by interlocking        |
| 11       | Blocked by synchrocheck        |
| 12       | Command already in execution   |
| 13       | Blocked by health              |
| 14       | 1-of-n control                 |
| 15       | Abortion by cancel             |
| 16       | Time limit over                |
| 17       | Abortion by trip               |
| 18       | Object not selected            |
| 19       | Object already selected        |
| 20       | Blocked by object being set    |

### 9.4 Select-Before-Operate — ctlModel = 2 or 4

```
┌──────────┐                                   ┌──────────┐
│  CLIENT  │                                   │  SERVER  │
└────┬─────┘                                   └────┬─────┘
     │                                              │
     │  WriteRequest: XCBR1$CO$Pos$SBO             │
     │─────────────────────────────────────────────>
     │<─────────────────────────────────────────────
     │  WriteResponse: success (Select granted)     │
     │                                              │
     │  [Client has sboTimeout (typ. 30s) to        │
     │   send Operate — configured in SCL]          │
     │                                              │
     │  WriteRequest: XCBR1$CO$Pos$Oper             │
     │  ctlVal=TRUE, ctlNum=N+1                    │
     │─────────────────────────────────────────────>
     │<─────────────────────────────────────────────
     │  WriteResponse: success / AddCause           │
     │                                              │
     │  [If timeout expires before Oper:]           │
     │  Select is released automatically            │
     │                                              │
     │  WriteRequest: XCBR1$CO$Pos$Cancel           │
     │  [Optional: Client may cancel explicitly]    │
     │─────────────────────────────────────────────>
```

### 9.5 Enhanced Security (ctlModel 3 and 4)

Enhanced security adds:

1. **`SBOw` (Select-with-Value):** Client includes `ctlVal` in the Select, server validates the intended action
2. **Timestamp validation:** Server checks that `T` (command timestamp) is within an acceptable window (typically ±1 second of server time — requires time synchronisation)
3. **Test mode separation:** `Test=TRUE` commands are executed in test mode only, do not affect real process

### 9.6 Time-Activated Operation (operTm)

For scheduled operations, `Oper.operTm` can be set to a future UTC timestamp:

```
XCBR1$CO$Pos$Oper$operTm = 2024-06-01T14:00:00.000Z
XCBR1$CO$Pos$Oper$ctlVal = TRUE
```

The device will execute the operation at the specified time. IED time synchronisation (SNTP/PTP per IEC 61850-9-3) is mandatory for this feature.

---

## 10. Setting Group Services (FC=SE) — Write Rules

### 10.1 Overview

Protection relays maintain multiple **Setting Groups** (up to 8 groups) that can be switched adaptively based on network topology. Writing to FC=SE DAs requires a dedicated service sequence through the Setting Group Control Block (SGCB) on `LLN0`.

### 10.2 SGCB Structure

```
LLN0$SG$SGCB$NumOfSG     [FC=SG] -- Number of setting groups configured (read-only)
LLN0$SG$SGCB$ActSG       [FC=SG] -- Currently active setting group (1-N)
LLN0$SG$SGCB$EditSG      [FC=SG] -- Currently being edited (0=none)
LLN0$SG$SGCB$CnfEdit     [FC=SG] -- Confirm edit (write TRUE to commit)
LLN0$SG$SGCB$LActTm      [FC=SG] -- Last activation timestamp
```

### 10.3 Setting Group Edit Sequence

```
Step 1: Read  LLN0$SG$SGCB$NumOfSG         -- Determine available groups (e.g. 3)
Step 2: Read  LLN0$SG$SGCB$ActSG           -- Determine current active group (e.g. 1)
Step 3: Write LLN0$SG$SGCB$EditSG = 2      -- Select group 2 for editing
         → Server enters EDIT mode for SG2
Step 4: Write PTOC1$SE$StrVal$setMag$f = 1.50   -- Write new pickup value to SG2
Step 5: Write PTOC1$SE$TmMult$setMag$f = 0.50   -- Write new TMS to SG2
         [All FC=SE writes now apply to SG2]
Step 6: Write LLN0$SG$SGCB$CnfEdit = TRUE   -- Confirm and commit edits
         → Server exits EDIT mode; SG2 values saved

Step 7: [Optional] Write LLN0$SG$SGCB$ActSG = 2 -- Switch active group to SG2
```

**Critical rule:** If `CnfEdit` is not written (`TRUE`) before the MMS connection closes, the edit session is discarded and SG2 retains its previous values.

---

## 11. Common Data Classes (CDC) and Their FC Decomposition

IEC 61850-7-3 defines CDCs. The following table shows the FC decomposition for the most common CDCs used in substation automation.

### 11.1 Status CDCs

| CDC | Name                   | ST DAs                      | MX DAs | SP DAs | CO DAs | CO Structure |
| --- | ---------------------- | --------------------------- | ------ | ------ | ------ | ------------ |
| SPS | Single Point Status    | `stVal`, `q`, `t`           | —      | —      | —      | —            |
| DPS | Double Point Status    | `stVal`, `q`, `t`           | —      | —      | —      | —            |
| INS | Integer Status         | `stVal`, `q`, `t`           | —      | —      | —      | —            |
| ENS | Enumerated Status      | `stVal`, `q`, `t`           | —      | —      | —      | —            |
| BCR | Binary Counter Reading | `actVal`, `frVal`, `q`, `t` | —      | —      | —      | —            |
| HST | Histogram              | `val[]`, `q`, `t`           | —      | —      | —      | —            |

### 11.2 Controllable CDCs

| CDC | Name                      | ST DAs             | CO DAs                 | ctlModel     |
| --- | ------------------------- | ------------------ | ---------------------- | ------------ |
| SPC | Single Point Controllable | `stVal`, `q`, `t`  | `SBO/Oper/ctlVal`      | CF attribute |
| DPC | Double Point Controllable | `stVal`, `q`, `t`  | `SBO/SBOw/Oper/Cancel` | CF attribute |
| INC | Integer Controllable      | `stVal`, `q`, `t`  | `SBO/Oper/setVal`      | CF attribute |
| ENC | Enumerated Controllable   | `stVal`, `q`, `t`  | `SBO/Oper/ctlVal`      | CF attribute |
| BSC | Binary Step Controllable  | `valWTr`, `q`, `t` | `SBO/Oper/valWTr`      | CF attribute |
| ISC | Integer Step Controllable | `valWTr`, `q`, `t` | `SBO/Oper/valWTr`      | CF attribute |

### 11.3 Measurement CDCs

| CDC | Name                   | MX DAs                                       | SP DAs (deadband)       |
| --- | ---------------------- | -------------------------------------------- | ----------------------- |
| MV  | Measured Value         | `mag.f`, `instMag.f`, `q`, `t`               | `db`, `zeroDb`, `range` |
| CMV | Complex Measured Value | `cVal.mag.f`, `cVal.ang.f`, `q`, `t`         | `db`, `zeroDb`          |
| SAV | Sampled Analogue Value | `instMag.f`, `q`                             | —                       |
| WYE | AC Three-Phase Wye     | `phsA`, `phsB`, `phsC`, `neut`, `net`, `res` | —                       |
| DEL | AC Three-Phase Delta   | `phsAB`, `phsBC`, `phsCA`                    | —                       |

### 11.4 Setting CDCs

| CDC   | Name                       | SP DAs                               | SE DAs                  |
| ----- | -------------------------- | ------------------------------------ | ----------------------- |
| ASG   | Analogue Setting           | `setMag.f`, `setMag.i`               | Same, per setting group |
| CURVE | Curve Shape Setting        | `setCrv`, `numPts`, `xUnit`, `yUnit` | Same                    |
| CSG   | Curve Shape Setting (alt.) | `setCrv`, `numPts`                   | Same                    |
| SPG   | Single Point Setting       | `setVal`                             | Same                    |
| ING   | Integer Setting            | `setVal`                             | Same                    |
| ENG   | Enumerated Setting         | `setVal`                             | Same                    |

---

## 12. MMS Service Primitives Mapping

### 12.1 Complete ACSI-to-MMS Service Mapping

| ACSI Service                | MMS Service                      | PDU Type               | FC Used        |
| --------------------------- | -------------------------------- | ---------------------- | -------------- |
| `GetServerDirectory`        | `GetNameList`                    | Domain list            | —              |
| `GetLogicalDeviceDirectory` | `GetNameList`                    | Named variable list    | —              |
| `GetLogicalNodeDirectory`   | `GetNameList`                    | Named variable list    | —              |
| `GetDataDirectory`          | `GetNameList`                    | Named variable         | —              |
| `GetDataDefinition`         | `GetVariableAccessAttributes`    | Type description       | —              |
| `GetDataValues`             | `Read`                           | ReadRequest/Response   | All FCs        |
| `SetDataValues`             | `Write`                          | WriteRequest/Response  | SP/SV/CF/BR/RP |
| `GetDataSetValues`          | `Read` (named var list)          | ReadRequest/Response   | —              |
| `SetDataSetValues`          | `Write` (named var list)         | WriteRequest/Response  | —              |
| `CreateDataSet`             | `DefineNamedVariableList`        | Define request         | —              |
| `DeleteDataSet`             | `DeleteNamedVariableList`        | Delete request         | —              |
| `GetDataSetDirectory`       | `GetNamedVariableListAttributes` | Attributes request     | —              |
| `Report` (server→client)    | `InformationReport`              | Unsolicited info       | BR/RP          |
| `GetBRCBValues`             | `Read`                           | ReadRequest            | BR             |
| `SetBRCBValues`             | `Write`                          | WriteRequest           | BR             |
| `GetURCBValues`             | `Read`                           | ReadRequest            | RP             |
| `SetURCBValues`             | `Write`                          | WriteRequest           | RP             |
| `Select`                    | `Write`                          | WriteRequest to SBO    | CO             |
| `SelectWithValue`           | `Write`                          | WriteRequest to SBOw   | CO             |
| `Operate`                   | `Write`                          | WriteRequest to Oper   | CO             |
| `Cancel`                    | `Write`                          | WriteRequest to Cancel | CO             |
| `CommandTermination`        | `InformationReport`              | Unsolicited            | CO             |
| `SelectActiveSG`            | `Write`                          | WriteRequest           | SG             |
| `SelectEditSG`              | `Write`                          | WriteRequest (EditSG)  | SG             |
| `SetSGValues`               | `Write`                          | WriteRequest           | SE             |
| `ConfirmEditSGValues`       | `Write`                          | WriteRequest (CnfEdit) | SG             |
| `GetEditSGValues`           | `Read`                           | ReadRequest            | SE             |
| `GetSGCBValues`             | `Read`                           | ReadRequest            | SG             |

### 12.2 MMS Connection Establishment

Before any read or write, the MMS connection must be established with IEC 61850-specific parameters:

```
MMS Initiate Request:
  proposedMaxServOutstandingCalling: 5
  proposedMaxServOutstandingCalled:  5
  proposedDataStructureNestingLevel: 8    -- IEC 61850-8-1 requires min 8
  mmsInitRequestDetail:
    proposedVersionNumber: 1
    proposedParameterCBB:  [str1, vnam, valt, vsca, tpy, vlis, real, cei]
    servicesSupportedCalling: [status, getNameList, identify, read, write,
                               getVariableAccessAttr, defineNamedVarList,
                               getNamedVarListAttr, deleteNamedVarList,
                               obtain-file, file-rename, read-journal,
                               write-journal, initialize-journal,
                               report-journal-status, create-journal,
                               delete-journal, getCapabilityList,
                               fileOpen, fileRead, fileClose,
                               fileRename, fileDelete, fileDirectory,
                               informationReport, unsolicitedStatus,
                               eventNotification]
```

---

## 13. Access Control and Security Considerations

### 13.1 SCL-Based Access Control

The System Configuration Language (SCL) defines access control at the `AccessPoint` level in the `IED` element of the `SCD` file:

```xml
<AccessPoint name="S1">
  <Server>
    <Authentication none="true" password="false" certificate="false"/>
    <LDevice inst="CTRL">
      ...
    </LDevice>
  </Server>
</AccessPoint>
```

### 13.2 IEC 62351-8 Role-Based Access Control

IEC 62351-8 defines roles for access control in IEC 61850 systems:

| Role          | Read ST/MX | Write SP/CF | Write SV | Control (CO) | Write SE | Configure RCB |
| ------------- | :--------: | :---------: | :------: | :----------: | :------: | :-----------: |
| Viewer        |     ✅     |     ❌      |    ❌    |      ❌      |    ❌    |      ❌       |
| Operator      |     ✅     |     ❌      |    ❌    |      ✅      |    ❌    |      ❌       |
| Engineer      |     ✅     |     ✅      |    ✅    |      ✅      |    ✅    |      ✅       |
| Installer     |     ✅     |     ✅      |    ✅    |      ✅      |    ✅    |      ✅       |
| SecurityAdmin |     ✅     |     ❌      |    ❌    |      ❌      |    ❌    |      ✅       |

### 13.3 Transport Security

| Layer       | Mechanism                           | Standard    |
| ----------- | ----------------------------------- | ----------- |
| TCP         | TLS 1.2/1.3                         | IEC 62351-3 |
| MMS         | Authentication via TLS certificates | IEC 62351-4 |
| Application | Role-based access per MMS service   | IEC 62351-8 |

---

## 14. Engineering Reference: Address Construction Examples

### 14.1 Substation One-Line to IEC 61850 Address Mapping

**Scenario:** Bay1 — 110kV Circuit Breaker CB1, with overcurrent protection, connected to busbar measurement.

```
IED:  PROT_BAY1   (Protection IED for Bay 1)
LDs:  PROT_BAY1PROT   (Protection functions)
      PROT_BAY1CTRL   (Control and switching)
      PROT_BAY1MEAS   (Measurement)
```

| Physical Item   | Function              | ACSI Address                              | FC  | R/W         |
| --------------- | --------------------- | ----------------------------------------- | --- | ----------- |
| CB1 Status      | Position (open/close) | `PROT_BAY1CTRL/XCBR1.Pos.stVal`           | ST  | R           |
| CB1 Close       | Control action        | `PROT_BAY1CTRL/XCBR1.Pos.Oper`            | CO  | W (Control) |
| CB1 Open        | Control action        | `PROT_BAY1CTRL/XCBR1.Pos.Oper`            | CO  | W (Control) |
| Phase A Current | Measurement           | `PROT_BAY1MEAS/MMXU1.A.phsA.cVal.mag.f`   | MX  | R           |
| OC Pickup       | Protection setpoint   | `PROT_BAY1PROT/PTOC1.StrVal.setMag.f`     | SP  | R/W         |
| OC Time Dial    | Protection setpoint   | `PROT_BAY1PROT/PTOC1.TmMult.setMag.f`     | SP  | R/W         |
| OC Start        | Protection status     | `PROT_BAY1PROT/PTOC1.Str.general`         | ST  | R           |
| OC Trip         | Protection output     | `PROT_BAY1PROT/PTOC1.Op.general`          | ST  | R           |
| Bus Voltage     | Measurement           | `PROT_BAY1MEAS/MMXU1.PhV.phsA.cVal.mag.f` | MX  | R           |

### 14.2 MMS Wire Format Reference for Above Addresses

| ACSI Address                                 | MMS Domain      | MMS Item ID                  |
| -------------------------------------------- | --------------- | ---------------------------- |
| `PROT_BAY1CTRL/XCBR1.Pos.stVal [ST]`         | `PROT_BAY1CTRL` | `XCBR1$ST$Pos$stVal`         |
| `PROT_BAY1CTRL/XCBR1.Pos.Oper.ctlVal [CO]`   | `PROT_BAY1CTRL` | `XCBR1$CO$Pos$Oper$ctlVal`   |
| `PROT_BAY1MEAS/MMXU1.A.phsA.cVal.mag.f [MX]` | `PROT_BAY1MEAS` | `MMXU1$MX$A$phsA$cVal$mag$f` |
| `PROT_BAY1PROT/PTOC1.StrVal.setMag.f [SP]`   | `PROT_BAY1PROT` | `PTOC1$SP$StrVal$setMag$f`   |
| `PROT_BAY1PROT/PTOC1.Str.general [ST]`       | `PROT_BAY1PROT` | `PTOC1$ST$Str$general`       |

### 14.3 Complete Read/Write Operation Examples

#### Read Phase A Current (MX — polling):

```
MMS ReadRequest:
  domainId: "PROT_BAY1MEAS"
  itemId:   "MMXU1$MX$A$phsA$cVal$mag$f"

MMS ReadResponse:
  accessResult: data = FLOAT32(245.7)
```

#### Read with Quality:

```
MMS ReadRequest:
  domainId: "PROT_BAY1MEAS"
  itemId:   "MMXU1$MX$A$phsA"   (read entire phsA structure: cVal + q + t)

MMS ReadResponse:
  accessResult: data = STRUCTURE {
    cVal: STRUCTURE { mag: STRUCTURE { f: FLOAT32(245.7) }, ang: STRUCTURE { f: FLOAT32(15.3) } },
    q:    BIT-STRING(0x0000),   -- validity=good, source=process
    t:    UTCTIME(...)
  }
```

#### Write Protection Setpoint (SP — direct):

```
MMS WriteRequest:
  domainId: "PROT_BAY1PROT"
  itemId:   "PTOC1$SP$StrVal$setMag$f"
  data:     FLOAT32(1.25)

MMS WriteResponse:
  success (empty)
```

#### Control — Close CB1 (Direct Operate):

```
MMS WriteRequest:
  domainId: "PROT_BAY1CTRL"
  itemId:   "XCBR1$CO$Pos$Oper"
  data: STRUCTURE {
    ctlVal:  BOOLEAN(TRUE),         -- TRUE = close
    origin:  STRUCTURE {
      orCat:   INTEGER(3),          -- remote
      orIdent: OCTET-STRING("SCADA_01")
    },
    ctlNum:  INTEGER(42),
    T:       UTCTIME(now),
    Test:    BOOLEAN(FALSE),
    Check:   BIT-STRING(0b11)       -- interlockCheck + synchroCheck
  }

MMS WriteResponse:
  success
```

---

## 15. Architectural Rules and Best Practices

### 15.1 The Three Golden Rules

**Rule 1 — FC determines access, not the DO type.**
A Data Object has no intrinsic read/write designation. Only its Data Attributes, partitioned by FC, have access rules. The same DO (`Pos`) contains read-only (`ST`), read-write (`CO`), and configuration (`CF`) DAs.

**Rule 2 — Never write process values directly.**
`FC=ST` and `FC=MX` DAs represent the live truth of the power system as measured by transducers and IED firmware. They are never client-writable. For testing, use `FC=SV` substitution with `subEna=TRUE`. For control, use the ACSI control model.

**Rule 3 — Control is a state machine, not a write.**
Any integration that issues `SetDataValues` directly to control output DAs will be rejected by any conformant IEC 61850 server. The ACSI control model enforces interlocking, authorization, timeout, and audit trail at the protocol level.

### 15.2 Performance Considerations

| Pattern                 | Use Case                          | Recommendation                  |
| ----------------------- | --------------------------------- | ------------------------------- |
| `GetDataValues` polling | Engineering tools, one-time reads | Acceptable, max 1 req/s per IED |
| `GetDataSetValues`      | SCADA periodic scan               | Preferred over individual reads |
| RCB subscription        | Real-time monitoring (ST, MX)     | Mandatory for operational SCADA |
| GOOSE                   | Protection logic, fast tripping   | Use for <4ms response; not MMS  |
| Sampled Values (SV)     | Merging unit measurements         | IEC 61850-9-2, not MMS          |

### 15.3 Common Integration Errors

| Error                                                 | Cause                                      | Correct Approach                                      |
| ----------------------------------------------------- | ------------------------------------------ | ----------------------------------------------------- | --- | --- |
| Direct write to `$ST$Pos$stVal`                       | Misunderstanding FC=ST                     | This is read-only; use control model                  |
| Direct write to `$CO$Pos$Oper$ctlVal` (SetDataValues) | Bypassing control model                    | Write to `$CO$Pos$Oper` as STRUCTURE, not leaf ctlVal |
| Missing `$` in MMS item ID                            | Wrong separator                            | ACSI uses `.`, MMS uses `$`                           |     |     |
| Reading wrong FC                                      | Querying `$MX` instead of `$ST` for status | Check CDC definition for correct FC                   |
| SE write without SGCB EDIT                            | Writing SE DA without SelectEditSG         | Always call SelectEditSG first                        |
| No RCB reservation                                    | Multiple clients competing for RCB         | Write `Resv=TRUE` before configuring RCB              |
| Control without synchrocheck                          | Setting Check bitmask to 0                 | Set appropriate Check bits per station design         |

---

## 16. Quick Reference Summary Tables

### 16.1 FC Quick Reference

| FC  | Write via SetDataValues | Write via Control | Notes                      |
| --- | :---------------------: | :---------------: | -------------------------- |
| ST  |           ❌            |        ❌         | Process read-only          |
| MX  |           ❌            |        ❌         | Measurement read-only      |
| SP  |           ✅            |        ❌         | Direct write               |
| SV  |           ✅            |        ❌         | Enable via subEna          |
| CF  |           ✅            |        ❌         | Engineering access         |
| DC  |           ❌            |        ❌         | Static                     |
| EX  |           ❌            |        ❌         | Vendor static              |
| SE  |           ✅            |        ❌         | Requires SGCB EDIT context |
| CO  |           ❌            |        ✅         | ACSI control model only    |
| OR  |           ❌            |        ❌         | Internal audit             |
| BL  |           ⚠️            |        ❌         | Implementation-defined     |
| BR  |           ✅            |        ❌         | RCB configuration          |
| RP  |           ✅            |        ❌         | RCB configuration          |

### 16.2 Address Separator Quick Reference

| Context               | Separator                                | Example                        |
| --------------------- | ---------------------------------------- | ------------------------------ | --- |
| ACSI object reference | `/` between LD and LN; `.` between DO/DA | `IED1CTRL/XCBR1.Pos.stVal`     |
| MMS item identifier   | `$` between all segments                 | `XCBR1$ST$Pos$stVal`           |     |
| SCL/XML reference     | `/` then `$` notation                    | `IED1CTRL/XCBR1$ST$Pos$stVal`  |     |
| Dataset member        | Full ACSI reference                      | `IED1CTRL/XCBR1.Pos.stVal[ST]` |

### 16.3 Minimum Read/Write Client Checklist

**Before reading:**

- [ ] Correct MMS domain name (= IED name + LD instance)
- [ ] Correct LN class and instance
- [ ] Correct FC for the data you want (ST for status, MX for measurements)
- [ ] Correct DA path using `$` separators in MMS
- [ ] MMS connection established with correct parameters

**Before writing SP/CF/SV:**

- [ ] FC is writable (SP, SV, CF, SE)
- [ ] Client has write role (IEC 62351-8)
- [ ] LN `Mod.stVal` is ON or TEST
- [ ] Value type matches DA type (FLOAT32, BOOLEAN, INT32, etc.)
- [ ] Value within defined range (check `$CF$xxx$range`)

**Before control (CO):**

- [ ] Read `ctlModel` from `$CF$Pos$ctlModel` to determine model (1-4)
- [ ] For SBO: send `SBO` write first, wait for success
- [ ] Populate full Oper structure (ctlVal, origin, ctlNum, T, Test, Check)
- [ ] Handle AddCause in response
- [ ] Monitor ST status change via RCB after operate

**Before SE write:**

- [ ] Read `LLN0$SG$SGCB$NumOfSG` to confirm group count
- [ ] Write `LLN0$SG$SGCB$EditSG` = target group number
- [ ] Perform all SE DA writes
- [ ] Write `LLN0$SG$SGCB$CnfEdit` = TRUE to commit

---

_End of Document_

---

**Document:** IEC 61850 MMS Protocol — Rules for Reading and Writing to IEC Addresses
**Standard:** IEC 61850 Ed.2 / Ed.2.1
**Classification:** Technical Reference
