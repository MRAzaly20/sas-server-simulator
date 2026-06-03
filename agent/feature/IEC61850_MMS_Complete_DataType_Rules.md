# IEC 61850 MMS – Complete Data Type & MmsType Rules

_IEC 61850-7-2 / 7-3 / 7-4 | MMS ISO 9506 | Ed. 2.1_


## Table of Contents

- **01** – MMS Primitive Data Types: Complete list of all MMS primitive types with bit-width, range and IEC 61850 mapping
- **02** – BasicType → MmsType Mapping: Rules for mapping IEC 61850 BasicType to MMS VISIBLE STRING, INTEGER, etc.
- **03** – Common Data Classes (CDC): All CDCs defined in IEC 61850-7-3 with their DA names, BasicType, MmsType, FC and Presence
- **04** – DA Attribute Rules: Mandatory/Optional/Conditional rules for DA per CDC per functional constraint
- **05** – Functional Constraints (FC): All FC codes, scope, allowed services and MMS object class
- **06** – Quality Bit-String Rules: Full definition of the 13-bit Quality (q) attribute bit layout
- **07** – Timestamp (t) Rules: 8-byte UTC timestamp structure and encoding rules per IEC 61850-7-2
- **08** – Control Model Rules: ctlModel values 0-6, control sequences, Oper/SBO/Cancel structure per CDC
- **09** – Trigger Options (TrgOps): dchg/qchg/dupd/period/gi bits and their effect on reporting
- **10** – Report Control Block (RCB): All BrRCB and UnBrRCB attributes, types and rules
- **11** – GOOSE Control Block (GoCB): GoCB dataset, APPID, minTime, maxTime, encoding rules
- **12** – Sampled Value (SV/SVCB): SvCB attributes, SmpRate, SmpSynch, SmpMod and ASDU structure
- **13** – Log Control Block (LCB): LCB attributes, log size, entry ID, ReasonCode rules
- **14** – Setting Group Control (SGCB): SGCB attributes, ActSG, EditSG, CnfEdit rules
- **15** – Enumeration Definitions: All standard enumerations: BehaviourModeKind, HealthKind, CtlModels, etc.

---

## 01 – MMS Primitive Data Types (ISO 9506 / IEC 61850-7-2)

_These are the fundamental MMS data types that IEC 61850 BasicTypes map onto. Every DA ultimately resolves to one of these._

| MMS Type Name | ISO 9506 Tag | Bit Width | Value Range / Format | IEC 61850 BasicType(s) | Description / Rules | Example DA Usage |
| --- | --- | --- | --- | --- | --- | --- |
| MmsBoolean | BOOLEAN | 1 | TRUE / FALSE | BOOLEAN | Two-valued logic. Encoded as 1 byte in BER (0x00=false, 0xFF=true). Used for all binary status and control values. | stVal (SPS/DPS/SPC/DPC), Test |
| MmsInteger | INTEGER | 8–128 | Variable-length signed integer | INT8, INT16, INT32, INT64 | BER long-form. Length-prefixed. IEC 61850 restricts to INT8/16/32/64 subtypes. Negative values via 2's-complement. | stVal (ENS/ENC), orCat, ctlModel, smpRate |
| MmsUnsigned | UNSIGNED | 8–128 | Variable-length unsigned integer | INT8U, INT16U, INT32U, INT64U | BER long-form. Always non-negative. Length-prefixed. ctlNum, SmpRate, and counter DAs use this. | ctlNum, Oper.ctlNum, numOfSmpPer |
| MmsFloat | FLOATING POINT | 32/64 | IEEE 754 single (32b) / double (64b) | FLOAT32, FLOAT64 | Exponent byte + mantissa bytes. FLOAT32 = 4 bytes, FLOAT64 = 8 bytes. Used for all analogue magnitudes. | mag.f (MV), setMag.f (APC/ASG), instMag.f |
| MmsBitString | BIT STRING | 1–255b | Packed bit array, MSB first | Quality, Check, TriggerConditions,
OptFlds, RptEna | Pad bits appended. First byte = unused-bit count. Quality=13 bits, Check=2 bits, OptFlds=10 bits. | q (all CDCs), Check, OptFlds, TrgOps |
| MmsOctetString | OCTET STRING | 0–255B | Raw byte array | OCTET_STRING_n | Length-prefixed arbitrary bytes. Used for orIdent, entryID, GoCBRef, SvID where opaque bytes needed. | orIdent, entryID, DatSet (GoCB) |
| MmsVisibleString | VISIBLE STRING | 0–255B | ISO 646 (ASCII printable) characters | VisibleString_n | Length-prefixed ASCII. Max 255 bytes. Used for names, references, descriptions. Case-sensitive. | Descrip, dchgTrgOp, RptID, DatSet |
| MmsUtcTime | UTC TIME | 64 bits | 8 bytes: 4B epoch + 3B frac + 1B quality | Timestamp | Seconds since 1970-01-01 UTC (32b) + 24-bit sub-second fraction (≈60ns res) + 8-bit time quality flags. | t (all CDCs), T (Oper), EntryTm |
| MmsStructure | STRUCTURE |  | Sequence of named member types | Struct (CDC-defined) | BER SEQUENCE. Recursive. CDC defines each member and its BasicType. Top-level DO = one MmsStructure. | AnalogueValue (mag), Quality (q), Originator |
| MmsArray | ARRAY |  | Ordered list of identical-type elements | ARRAY OF <BasicType> | BER SEQUENCE OF. Used in BSTR arrays, SV ASDU multi-sample buffers. Element count in schema. | SV ASDU samples, setVal arrays |
| MmsEnum | ENUMERATED | varies | Named integer; fits in INTEGER encoding | Enumerated | Integer encoding but validated against enumeration definition (IEC 61850-7-3 Table). Out-of-range = invalid. | BehaviourModeKind, HealthKind, CtlModels |
| MmsObjId | OBJ ID | varies | ASN.1 OID dot-notation | ObjID (rare) | Used rarely; mainly for ACSI object identification in some SCL attributes. | N/A in most implementations |

---

## 02 – IEC 61850 BasicType → MmsType Mapping Rules (IEC 61850-7-2 Annex A)

_Every DA defined in IEC 61850-7-3/7-4 has a BasicType. This sheet maps each BasicType to its MMS wire encoding._

| BasicType | MmsType | Byte Size | Min Value | Max Value | Encoding Rule / Notes | Typical DA Examples |
| --- | --- | --- | --- | --- | --- | --- |
| BOOLEAN | MmsBoolean | 1 | FALSE | TRUE | BER 0x01 tag. Single byte: 0x00=false, 0xFF=true. Any non-zero value accepted as true on read. | stVal (SPS/DPS/SPC/DPC), Test, q.validity bits |
| INT8 | MmsInteger | 1 | -128 | 127 | Signed 8-bit. BER INTEGER. Length=1. Two's complement. | orCat (Originator Category) |
| INT16 | MmsInteger | 2 | -32,768 | 32,767 | Signed 16-bit. BER INTEGER. Length=2. | stVal (ENS/ENC short range) |
| INT32 | MmsInteger | 4 | -2,147,483,648 | 2,147,483,647 | Signed 32-bit. BER INTEGER. Length=4. Most common integer DA size. | stVal (INC/INS), ctlModel, smpRate |
| INT64 | MmsInteger | 8 | -2^63 | 2^63−1 | Signed 64-bit. BER INTEGER. Length=8. Used for large counters. | Large counter values |
| INT8U | MmsUnsigned | 1 | 0 | 255 | Unsigned 8-bit. BER UNSIGNED. Length=1. | ctlNum (Oper), numPhsA |
| INT16U | MmsUnsigned | 2 | 0 | 65,535 | Unsigned 16-bit. BER UNSIGNED. Length=2. | SmpRate, phsRef |
| INT32U | MmsUnsigned | 4 | 0 | 4,294,967,295 | Unsigned 32-bit. BER UNSIGNED. Length=4. Counter DAs. | Counter values, SmpCnt |
| INT64U | MmsUnsigned | 8 | 0 | 2^64−1 | Unsigned 64-bit. BER UNSIGNED. Length=8. | Extended counters |
| FLOAT32 | MmsFloat | 4 | ±1.18×10⁻³⁸ | ±3.40×10³⁸ | IEEE 754 single precision. Exponent byte (8) + mantissa (23b). Stored big-endian. | mag.f, instMag.f, setMag.f, smpVal |
| FLOAT64 | MmsFloat | 8 | ±2.23×10⁻³⁰⁸ | ±1.80×10³⁰⁸ | IEEE 754 double precision. 11-bit exponent + 52-bit mantissa. Big-endian. | High-precision analogue, rangC |
| Enumerated | MmsInteger | 4 | 0 | schema-defined | Stored as INT32 MMS. Value must match the enumeration table in IEC 61850-7-3. Out-of-range rejected. | stVal (ENS/ENC), BehaviourModeKind, HealthKind |
| Quality | MmsBitString | 2 | 0x0000 | 0x1FFF | 13-bit packed BitString. See Sheet 06 for full bit layout. Padded to 16 bits (3 unused bits). | q (ALL CDCs) |
| Timestamp | MmsUtcTime | 8 | 1970-01-01 | 2106-02-07 | 8-byte structure: uint32 epoch sec + uint24 fraction (1/2²⁴ s ≈ 59.6ns) + uint8 time quality. | t (ALL CDCs), T (Oper), EntryTm |
| VisibleString_64 | MmsVisibleString | ≤64 | "" | 64 ASCII chars | BER VisibleString. Length-prefixed. Max 64 printable ISO 646 chars. NUL-terminated optional. | dchgTrgOp, RptID, DatSet (short) |
| VisibleString_129 | MmsVisibleString | ≤129 | "" | 129 ASCII chars | As above but max 129 chars. Used for longer references. | Descrip, GoCBRef |
| VisibleString_255 | MmsVisibleString | ≤255 | "" | 255 ASCII chars | Maximum length VisibleString in IEC 61850. Used for free-text description fields. | d (long description) |
| OCTET_STRING_6 | MmsOctetString | 6 | — | — | 6-byte opaque array. Used for Ethernet MAC addresses in GOOSE/SV. | GoCB.GoID (short form), MAC addresses |
| OCTET_STRING_64 | MmsOctetString | ≤64 | — | — | 64-byte octet array. Used for orIdent and other opaque identifiers. | orIdent, entryID |
| Check | MmsBitString | 1 | 00 | 11 | 2-bit BitString. Bit 0 = synchroCheck, Bit 1 = interlockCheck. Padded to 8 bits. | Oper.Check (SPC/DPC/APC) |
| TriggerConditions | MmsBitString | 1 | 00000 | 11111 | 5-bit BitString for TrgOps. Bits: dchg, qchg, dupd, integrity, GI. See Sheet 09. | TrgOps (RCB/LCB) |
| OptFlds | MmsBitString | 2 | 0x000 | 0x3FF | 10-bit BitString for report optional fields. See Sheet 10. | OptFlds (BrRCB/UnBrRCB) |
| ObjID | MmsObjId | var | — | — | ASN.1 OID. Rarely used in DA layer; mainly in ACSI/SCL schema metadata. | Rare / implementation-specific |

---

## 03 – Common Data Classes (CDC) – Full DA Attribute Mapping (IEC 61850-7-3 Ed.2.1)

_All CDCs with every Data Attribute (DA), its BasicType, MmsType, Functional Constraint (FC) and Presence (M=Mandatory, O=Optional, C=Conditional)._

| CDC | DA Name | BasicType | MmsType | FC | Presence | Trigger | Description / Rule |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **▶  SPS  –  Common Data Class** | | | | | | | |
| SPS | stVal | BOOLEAN | MmsBoolean | ST | M | dchg/qchg | Single-point status. TRUE=on/closed. Core status value. |
| SPS | q | Quality | MmsBitString | ST | M | qchg | 13-bit quality word. See Sheet 06. |
| SPS | t | Timestamp | MmsUtcTime | ST | M |  | UTC timestamp of last stVal or q change. |
| SPS | subEna | BOOLEAN | MmsBoolean | SV | O |  | Substitution enabled flag. |
| SPS | subVal | BOOLEAN | MmsBoolean | SV | O |  | Substitute value when subEna=TRUE. |
| SPS | subQ | Quality | MmsBitString | SV | O |  | Quality associated with substitute value. |
| SPS | subID | VisibleString_64 | MmsVisibleString | SV | O |  | Identifier of substitution source. |
| SPS | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description text. |
| SPS | dU | VisibleString_255 | MmsVisibleString | DC | O |  | Description text in user language. |
| SPS | cdcNs | VisibleString_255 | MmsVisibleString | EX | O |  | CDC namespace extension. |
| SPS | cdcName | VisibleString_64 | MmsVisibleString | EX | O |  | CDC name extension. |
| **▶  DPS  –  Common Data Class** | | | | | | | |
| DPS | stVal | Enumerated | MmsInteger | ST | M | dchg/qchg | 0=intermediate,1=off,2=on,3=bad-state. |
| DPS | q | Quality | MmsBitString | ST | M | qchg | 13-bit quality. |
| DPS | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| DPS | subEna | BOOLEAN | MmsBoolean | SV | O |  | Substitution enabled. |
| DPS | subVal | Enumerated | MmsInteger | SV | O |  | Substitute value (same enum as stVal). |
| DPS | subQ | Quality | MmsBitString | SV | O |  | Substitute quality. |
| DPS | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  INS  –  Common Data Class** | | | | | | | |
| INS | stVal | INT32 | MmsInteger | ST | M | dchg/qchg | Integer status value. Range per application. |
| INS | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| INS | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| INS | subEna | BOOLEAN | MmsBoolean | SV | O |  | Substitution enabled. |
| INS | subVal | INT32 | MmsInteger | SV | O |  | Substitute integer value. |
| INS | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  ENS  –  Common Data Class** | | | | | | | |
| ENS | stVal | Enumerated | MmsInteger | ST | M | dchg/qchg | Enumerated status (read-only). Values per LN spec. |
| ENS | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| ENS | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| ENS | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  ACT  –  Common Data Class** | | | | | | | |
| ACT | general | BOOLEAN | MmsBoolean | ST | M | dchg/qchg | General alarm flag. |
| ACT | phsA | BOOLEAN | MmsBoolean | ST | O | dchg | Phase A alarm. |
| ACT | phsB | BOOLEAN | MmsBoolean | ST | O | dchg | Phase B alarm. |
| ACT | phsC | BOOLEAN | MmsBoolean | ST | O | dchg | Phase C alarm. |
| ACT | neut | BOOLEAN | MmsBoolean | ST | O | dchg | Neutral alarm. |
| ACT | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| ACT | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| **▶  SPC  –  Common Data Class** | | | | | | | |
| SPC | stVal | BOOLEAN | MmsBoolean | ST | M | dchg/qchg | Current single-point status after control. |
| SPC | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| SPC | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| SPC | Oper.ctlVal | BOOLEAN | MmsBoolean | CO | M |  | Control value to set. |
| SPC | Oper.origin.orCat | INT8 | MmsInteger | CO | M |  | Originator category 0-6. |
| SPC | Oper.origin.orIdent | OCTET_STRING_64 | MmsOctetString | CO | O |  | Originator identifier. |
| SPC | Oper.ctlNum | INT8U | MmsUnsigned | CO | M |  | Control sequence number 0-255. |
| SPC | Oper.T | Timestamp | MmsUtcTime | CO | M |  | Time of control command. |
| SPC | Oper.Test | BOOLEAN | MmsBoolean | CO | M |  | TRUE = test-mode operation. |
| SPC | Oper.Check | Check | MmsBitString | CO | M |  | 2-bit: synchroCheck | interlockCheck. |
| SPC | Cancel.ctlVal | BOOLEAN | MmsBoolean | CO | O |  | ctlVal to cancel (SBO-enhanced only). |
| SPC | Cancel.origin.orCat | INT8 | MmsInteger | CO | O |  | Originator category for cancel. |
| SPC | Cancel.ctlNum | INT8U | MmsUnsigned | CO | O |  | Sequence number of command to cancel. |
| SPC | Cancel.T | Timestamp | MmsUtcTime | CO | O |  | Time of cancel. |
| SPC | Cancel.Test | BOOLEAN | MmsBoolean | CO | O |  | Test flag of cancel. |
| SPC | ctlModel | Enumerated | MmsInteger | CF | M |  | Control model: 0=stsOnly,1=direct-normal,2=SBO-normal,3=direct-enhanced,4=SBO-enhanced. |
| SPC | sboTimeout | INT32U | MmsUnsigned | CF | O |  | SBO timeout ms. 0=no timeout. |
| SPC | sboClass | Enumerated | MmsInteger | CF | O |  | SBO class: 0=operate-once, 1=operate-many. |
| SPC | subEna | BOOLEAN | MmsBoolean | SV | O |  | Substitution enabled. |
| SPC | subVal | BOOLEAN | MmsBoolean | SV | O |  | Substitute value. |
| SPC | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  DPC  –  Common Data Class** | | | | | | | |
| DPC | stVal | Enumerated | MmsInteger | ST | M | dchg/qchg | 0=intermediate,1=off,2=on,3=bad-state. |
| DPC | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| DPC | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| DPC | Oper.ctlVal | Enumerated | MmsInteger | CO | M |  | Target state: 1=off, 2=on. |
| DPC | Oper.origin.orCat | INT8 | MmsInteger | CO | M |  | Originator category. |
| DPC | Oper.ctlNum | INT8U | MmsUnsigned | CO | M |  | Sequence number. |
| DPC | Oper.T | Timestamp | MmsUtcTime | CO | M |  | Time of command. |
| DPC | Oper.Test | BOOLEAN | MmsBoolean | CO | M |  | Test flag. |
| DPC | Oper.Check | Check | MmsBitString | CO | M |  | Check bits. |
| DPC | ctlModel | Enumerated | MmsInteger | CF | M |  | Control model. |
| DPC | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  INC  –  Common Data Class** | | | | | | | |
| INC | stVal | INT32 | MmsInteger | ST | M | dchg/qchg | Current integer value after control. |
| INC | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| INC | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| INC | Oper.ctlVal | INT32 | MmsInteger | CO | M |  | Target integer value. |
| INC | Oper.origin.orCat | INT8 | MmsInteger | CO | M |  | Originator category. |
| INC | Oper.ctlNum | INT8U | MmsUnsigned | CO | M |  | Sequence number. |
| INC | Oper.T | Timestamp | MmsUtcTime | CO | M |  | Time. |
| INC | Oper.Test | BOOLEAN | MmsBoolean | CO | M |  | Test flag. |
| INC | Oper.Check | Check | MmsBitString | CO | M |  | Check bits. |
| INC | ctlModel | Enumerated | MmsInteger | CF | M |  | Control model. |
| INC | minVal | INT32 | MmsInteger | CF | O |  | Minimum allowed setpoint value. |
| INC | maxVal | INT32 | MmsInteger | CF | O |  | Maximum allowed setpoint value. |
| INC | stepSize | INT32U | MmsUnsigned | CF | O |  | Step increment for setpoint changes. |
| INC | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  ENC  –  Common Data Class** | | | | | | | |
| ENC | stVal | Enumerated | MmsInteger | ST | M | dchg/qchg | Enumerated controllable value. |
| ENC | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| ENC | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| ENC | Oper.ctlVal | Enumerated | MmsInteger | CO | M |  | Target enumeration value. |
| ENC | Oper.origin.orCat | INT8 | MmsInteger | CO | M |  | Originator category. |
| ENC | Oper.ctlNum | INT8U | MmsUnsigned | CO | M |  | Sequence number. |
| ENC | Oper.T | Timestamp | MmsUtcTime | CO | M |  | Time. |
| ENC | Oper.Test | BOOLEAN | MmsBoolean | CO | M |  | Test flag. |
| ENC | Oper.Check | Check | MmsBitString | CO | M |  | Check bits. |
| ENC | ctlModel | Enumerated | MmsInteger | CF | M |  | Control model. |
| ENC | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  APC  –  Common Data Class** | | | | | | | |
| APC | setMag | AnalogueValue | MmsStructure | SP | M | dupd | Analogue setpoint structure (f or i subDA). |
| APC | setMag.f | FLOAT32 | MmsFloat | SP | C | dupd | Float setpoint value. Mandatory if setMag.i absent. |
| APC | setMag.i | INT32 | MmsInteger | SP | C | dupd | Integer setpoint value. Mandatory if setMag.f absent. |
| APC | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| APC | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| APC | Oper.ctlVal.f | FLOAT32 | MmsFloat | CO | C |  | Float control value. |
| APC | Oper.ctlVal.i | INT32 | MmsInteger | CO | C |  | Integer control value. |
| APC | Oper.origin.orCat | INT8 | MmsInteger | CO | M |  | Originator category. |
| APC | Oper.ctlNum | INT8U | MmsUnsigned | CO | M |  | Sequence number. |
| APC | Oper.T | Timestamp | MmsUtcTime | CO | M |  | Time. |
| APC | Oper.Test | BOOLEAN | MmsBoolean | CO | M |  | Test flag. |
| APC | Oper.Check | Check | MmsBitString | CO | M |  | Check bits. |
| APC | ctlModel | Enumerated | MmsInteger | CF | M |  | Control model. |
| APC | minVal | AnalogueValue | MmsStructure | CF | O |  | Minimum setpoint. |
| APC | maxVal | AnalogueValue | MmsStructure | CF | O |  | Maximum setpoint. |
| APC | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  BSC  –  Common Data Class** | | | | | | | |
| BSC | valWTr | BSCValW | MmsStructure | ST | M | dchg/qchg | Binary step with transient: val (INT8) + transInd (BOOLEAN). |
| BSC | valWTr.val | INT8 | MmsInteger | ST | M | dchg | Step value: -128..127. |
| BSC | valWTr.transInd | BOOLEAN | MmsBoolean | ST | M | dchg | Transient indicator. |
| BSC | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| BSC | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| BSC | Oper.ctlVal | Enumerated | MmsInteger | CO | M |  | 0=stop,1=lower,2=higher,3=reserved. |
| BSC | Oper.origin.orCat | INT8 | MmsInteger | CO | M |  | Originator category. |
| BSC | Oper.ctlNum | INT8U | MmsUnsigned | CO | M |  | Sequence number. |
| BSC | Oper.T | Timestamp | MmsUtcTime | CO | M |  | Time. |
| BSC | Oper.Test | BOOLEAN | MmsBoolean | CO | M |  | Test flag. |
| BSC | Oper.Check | Check | MmsBitString | CO | M |  | Check bits. |
| BSC | ctlModel | Enumerated | MmsInteger | CF | M |  | Control model. |
| **▶  MV  –  Common Data Class** | | | | | | | |
| MV | instMag | AnalogueValue | MmsStructure | MX | O | dupd | Instantaneous (non-deadbanded) analogue value. |
| MV | instMag.f | FLOAT32 | MmsFloat | MX | C | dupd | Float instantaneous value. Mandatory if instMag.i absent. |
| MV | instMag.i | INT32 | MmsInteger | MX | C | dupd | Integer instantaneous value. Mandatory if instMag.f absent. |
| MV | mag | AnalogueValue | MmsStructure | MX | M | dchg | Deadbanded measured value (triggers on deadband crossing). |
| MV | mag.f | FLOAT32 | MmsFloat | MX | C | dchg | Float deadbanded value. |
| MV | mag.i | INT32 | MmsInteger | MX | C | dchg | Integer deadbanded value. |
| MV | q | Quality | MmsBitString | MX | M | qchg | Quality flags. |
| MV | t | Timestamp | MmsUtcTime | MX | M |  | Timestamp. |
| MV | range | Enumerated | MmsInteger | MX | O | dchg | 0=normal,1=high,2=low,3=high-high,4=low-low. |
| MV | rangeC | RangeConfig | MmsStructure | CF | O |  | Range config: hhLim, hLim, lLim, llLim, min, max (all FLOAT64). |
| MV | db | INT32U | MmsUnsigned | CF | O |  | Deadband value in 0.001% of range. |
| MV | zeroDb | INT32U | MmsUnsigned | CF | O |  | Zero-suppression deadband. |
| MV | sVC | ScaledValueConfig | MmsStructure | CF | O |  | Scaled value config: scaleFactor (FLOAT32) + offset (FLOAT32). |
| MV | units | Unit | MmsStructure | CF | O |  | Unit: SIUnit (INT8) + multiplier (INT8). |
| MV | subEna | BOOLEAN | MmsBoolean | SV | O |  | Substitution enabled. |
| MV | subMag | AnalogueValue | MmsStructure | SV | O |  | Substitute analogue value. |
| MV | subQ | Quality | MmsBitString | SV | O |  | Substitute quality. |
| MV | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  CMV  –  Common Data Class** | | | | | | | |
| CMV | instCVal | Vector | MmsStructure | MX | O | dupd | Instantaneous complex value: mag + ang (both AnalogueValue). |
| CMV | cVal | Vector | MmsStructure | MX | M | dchg | Deadbanded complex value: mag + ang. |
| CMV | cVal.mag.f | FLOAT32 | MmsFloat | MX | M | dchg | Magnitude float. |
| CMV | cVal.ang.f | FLOAT32 | MmsFloat | MX | M | dchg | Angle float (degrees). |
| CMV | q | Quality | MmsBitString | MX | M | qchg | Quality. |
| CMV | t | Timestamp | MmsUtcTime | MX | M |  | Timestamp. |
| CMV | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  SAV  –  Common Data Class** | | | | | | | |
| SAV | instMag | AnalogueValue | MmsStructure | MX | M | dupd | Instantaneous sampled analogue value. No deadband. |
| SAV | instMag.f | FLOAT32 | MmsFloat | MX | C | dupd | Float sampled value. |
| SAV | instMag.i | INT32 | MmsInteger | MX | C | dupd | Integer sampled value. |
| SAV | q | Quality | MmsBitString | MX | M | qchg | Quality. |
| SAV | t | Timestamp | MmsUtcTime | MX | O |  | Timestamp (optional; SV ASDU carries its own). |
| SAV | sVC | ScaledValueConfig | MmsStructure | CF | O |  | Scaling configuration. |
| SAV | units | Unit | MmsStructure | CF | O |  | Engineering unit. |
| **▶  WYE  –  Common Data Class** | | | | | | | |
| WYE | phsA | CMV | MmsStructure | MX | M | dchg | Phase A complex value. |
| WYE | phsB | CMV | MmsStructure | MX | M | dchg | Phase B complex value. |
| WYE | phsC | CMV | MmsStructure | MX | M | dchg | Phase C complex value. |
| WYE | neut | CMV | MmsStructure | MX | O | dchg | Neutral complex value. |
| WYE | net | CMV | MmsStructure | MX | O | dchg | Net (sum) complex value. |
| WYE | res | CMV | MmsStructure | MX | O | dchg | Residual complex value. |
| WYE | q | Quality | MmsBitString | MX | M | qchg | Overall quality. |
| WYE | t | Timestamp | MmsUtcTime | MX | M |  | Timestamp. |
| WYE | angRef | Enumerated | MmsInteger | CF | O |  | Angle reference: 0=Va,1=Vb,2=Vc,3=Aa,4=Ab,5=Ac,6=Vab,7=Vbc,8=Vca. |
| **▶  DEL  –  Common Data Class** | | | | | | | |
| DEL | phsAB | CMV | MmsStructure | MX | M | dchg | Phase AB delta complex value. |
| DEL | phsBC | CMV | MmsStructure | MX | M | dchg | Phase BC. |
| DEL | phsCA | CMV | MmsStructure | MX | M | dchg | Phase CA. |
| DEL | q | Quality | MmsBitString | MX | M | qchg | Quality. |
| DEL | t | Timestamp | MmsUtcTime | MX | M |  | Timestamp. |
| **▶  ASG  –  Common Data Class** | | | | | | | |
| ASG | setMag | AnalogueValue | MmsStructure | SP | M | dupd | Analogue setting value (float or integer). |
| ASG | setMag.f | FLOAT32 | MmsFloat | SP | C | dupd | Float setting value. |
| ASG | setMag.i | INT32 | MmsInteger | SP | C | dupd | Integer setting value. |
| ASG | units | Unit | MmsStructure | CF | O |  | Engineering unit. |
| ASG | minVal | AnalogueValue | MmsStructure | CF | O |  | Minimum allowed setting. |
| ASG | maxVal | AnalogueValue | MmsStructure | CF | O |  | Maximum allowed setting. |
| ASG | sVC | ScaledValueConfig | MmsStructure | CF | O |  | Scaling config. |
| ASG | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| **▶  DPL  –  Common Data Class** | | | | | | | |
| DPL | vendor | VisibleString_255 | MmsVisibleString | DC | O |  | Vendor name. |
| DPL | hwRev | VisibleString_255 | MmsVisibleString | DC | O |  | Hardware revision. |
| DPL | swRev | VisibleString_255 | MmsVisibleString | DC | O |  | Software revision. |
| DPL | serNum | VisibleString_255 | MmsVisibleString | DC | O |  | Serial number. |
| DPL | model | VisibleString_255 | MmsVisibleString | DC | O |  | Model. |
| DPL | location | VisibleString_255 | MmsVisibleString | DC | O |  | Physical location. |
| **▶  LPL  –  Common Data Class** | | | | | | | |
| LPL | vendor | VisibleString_255 | MmsVisibleString | DC | M |  | Vendor name (mandatory for LLN0). |
| LPL | swRev | VisibleString_255 | MmsVisibleString | DC | M |  | SW revision. |
| LPL | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |
| LPL | configRev | VisibleString_255 | MmsVisibleString | DC | O |  | Configuration revision. |
| LPL | ldNs | VisibleString_255 | MmsVisibleString | EX | O |  | Namespace of the LD. |
| **▶  BCR  –  Common Data Class** | | | | | | | |
| BCR | actVal | INT64 | MmsInteger | ST | M | dupd | Actual counter value. |
| BCR | frEna | BOOLEAN | MmsBoolean | ST | M | dchg | Freeze enable. |
| BCR | frVal | INT64 | MmsInteger | ST | O |  | Frozen counter value. |
| BCR | frTm | Timestamp | MmsUtcTime | ST | O |  | Timestamp of last freeze. |
| BCR | q | Quality | MmsBitString | ST | M | qchg | Quality. |
| BCR | t | Timestamp | MmsUtcTime | ST | M |  | Timestamp. |
| BCR | pulsQty | FLOAT32 | MmsFloat | CF | O |  | Pulse quantity (engineering value per count). |
| BCR | units | Unit | MmsStructure | CF | O |  | Engineering unit. |
| BCR | d | VisibleString_255 | MmsVisibleString | DC | O |  | Description. |

---

## 05 – Functional Constraints (FC) – IEC 61850-7-2 Table 22

_FC determines which service class can read/write a DA and how it is grouped in MMS named variable subtrees._

| FC Code | Full Name | MMS FC Class | Allowed Services | Description & Rules |
| --- | --- | --- | --- | --- |
| ST | Status | Status | GetDataValues, Report, GOOSE, Log | Current process status. All status DAs (stVal, q, t). Readable by any client. Reportable via RCB/LCB/GOOSE. |
| MX | Measurement | Measurement | GetDataValues, Report, GOOSE, Log | Measured analogue values (mag, instMag, cVal). Reportable. Updated at measurement rate. |
| SP | Setpoint | SetPoint | GetDataValues, SetDataValues | Process setpoints (setMag, setVal). Writable by authorized clients only. |
| SV | Substitution | Substitution | GetDataValues, SetDataValues | Substitution DAs (subEna, subVal, subQ, subID). Written to override process value. |
| CF | Configuration | Config | GetDataValues, SetDataValues | Configuration parameters (ctlModel, db, sVC, units). Changed only during commissioning. |
| DC | Description | Description | GetDataValues | Text descriptions (d, dU). Read-only in run-time. Written at engineering time via SCL. |
| EX | Extension | Extension | GetDataValues, SetDataValues | Non-standard vendor extensions. cdcNs, cdcName, or proprietary DAs. Treated as opaque by interoperable clients. |
| SE | Setting (Editable) | SettingEdit | GetDataValues, SetDataValues (edit SG) | Setting group values while edit session is active (EditSG service). Only when SGCB.EditSG ≠ 0. |
| SG | Setting Group | SettingGroup | GetDataValues | Active setting group values. Read-only in run-time. Written via SE during edit session. |
| CO | Control | Control | Operate, TimeActivatedOperate, SBOSelect | Control service DAs (Oper, SBO, Cancel structs). Written only via control services, NOT SetDataValues. |
| BL | Blocking | Blocking | GetDataValues, SetDataValues | Blocking attributes. Prevent automatic reporting while blocked. Used in substitution workflows. |
| RP | Unbuffered Report | Report | GetBRCBValues, SetRCBValues, Report | Unbuffered RCB attributes (RptID, RptEna, DatSet, ConfRev, OptFlds, BufTm, SqNum, TrgOps, IntgPd, GI). |
| BR | Buffered Report | BufReport | GetBRCBValues, SetBRCBValues, Report | Buffered RCB attributes (same as RP plus BufOvfl, EntryID, TimeOfEntry, PurgeBuf). |
| LG | Log | Log | GetLCBValues, SetLCBValues, QueryLog | Log control block attributes (LogEna, LogRef, TrgOps, IntgPd). |
| GO | GOOSE | Goose | GetGoCBValues, SetGoCBValues, SendGOOSE | GOOSE control block attributes (GoEna, GoID, DatSet, ConfRev, NdsCom, DstAddress). |
| GS | GSSE (deprecated) | Goose | Legacy only | Generic Substation Status Event (deprecated in Ed.2). Use GO instead. |
| MS | Multicast SV | MSV | GetMSVCBValues, SetMSVCBValues, SendSV | Multicast sampled value control block (SvEna, MsvID, DatSet, SmpRate, SmpMod, ConfRev, SmpSynch, DstAddress). |
| US | Unicast SV | USV | GetUSVCBValues, SetUSVCBValues, SendSV | Unicast sampled value control block (same as MS but unicast DstAddress). |

---

## 06 – Quality (q) Attribute – 13-bit BitString Definition (IEC 61850-7-3 Table 22)

_The 'q' DA is mandatory for every CDC. It is encoded as MmsBitString (13 significant bits, MSB=bit 0 = Validity MSB)._

| Bit Position | Bit Name | Group | Value Range | Meaning / Rule | Affected By |
| --- | --- | --- | --- | --- | --- |
| 0 | validity[0] MSB | Validity | 0 or 1 | Bit 0..1 encode validity: 00=good, 01=invalid, 10=reserved, 11=questionable. This is the MSB of the 2-bit validity field. | Bad sensor, comms failure, substitution |
| 1 | validity[1] LSB | Validity | 0 or 1 | LSB of validity. Combined with bit 0: good(00), invalid(01), rsvd(10), questionable(11). 'questionable' = process value may be incorrect. | Overrange, out-of-range, test mode |
| 2 | overflow | Detail Qual | 0 or 1 | 1 = value has exceeded the measurement range of the sensor or processing step. Set by IED automatically. | Sensor overrange |
| 3 | outOfRange | Detail Qual | 0 or 1 | 1 = value is outside the range defined by rangeC configuration. Does not imply sensor failure. | rangeC threshold crossed |
| 4 | badReference | Detail Qual | 0 or 1 | 1 = reference value is unreliable (e.g., VT/CT broken). Affects angle-referenced measurements (CMV, WYE). | Reference lost |
| 5 | oscillatory | Detail Qual | 0 or 1 | 1 = value is changing at a rate inconsistent with the process (chattering). May indicate wiring issue. | Rapid toggling detected |
| 6 | failure | Detail Qual | 0 or 1 | 1 = equipment or source failure detected (hardware watchdog, IED self-test fail). Implies data is invalid. | Hardware fault, watchdog |
| 7 | oldData | Detail Qual | 0 or 1 | 1 = value has not been refreshed within the expected update interval. Stale data. | Comms timeout, scan failure |
| 8 | inconsistent | Detail Qual | 0 or 1 | 1 = value is logically inconsistent with other related values (e.g., all three phases zero simultaneously). | Cross-check failure |
| 9 | inaccurate | Detail Qual | 0 or 1 | 1 = value is within range but reduced accuracy (e.g., low-grade ADC, thermal drift). | Degraded sensor |
| 10 | source | Source | 0 or 1 | 0 = process (real sensor reading), 1 = substituted (subEna=TRUE, subVal in effect). | Substitution service |
| 11 | test | Test | 0 or 1 | 1 = value originates from a test or simulation. Must NOT be used for protection-tripping decisions. | Test mode, simulation |
| 12 | operatorBlocked | Operator | 0 or 1 | 1 = update of process value blocked by operator command. Value may be stale. | Blocking service |

---

## 07 – Timestamp (t) Attribute – 8-byte UTC Time Structure (IEC 61850-7-2 Annex E)

_The Timestamp is MmsUtcTime = 8 bytes total: 4B seconds + 3B sub-second + 1B time quality. Epoch = 1970-01-01 00:00:00 UTC._

| Byte(s) | Field Name | Bits | Type | Rule / Description |
| --- | --- | --- | --- | --- |
| 0–3 | SecondSinceEpoch | 32 | UINT32 big-endian | Seconds since Unix epoch (1970-01-01 00:00:00 UTC). Rolls over in 2106. Mandatory. Value 0 = epoch (not 'unknown'). |
| 4–6 | FractionOfSecond | 24 | UINT24 big-endian | Sub-second fraction. Unit = 1/2²⁴ second ≈ 59.6 ns. Maximum time resolution = 59.6 ns. Value 0 = whole second. |
| 7 | TimeQuality | 8 | UINT8 bitfield | 8-bit time quality byte. See bit definitions below. |
| 7 b0 | LeapSecondsKnown | 1 | BIT | 1 = IED knows current leap-second offset. 0 = unknown (time may be inaccurate by up to 37s as of 2024). |
| 7 b1 | ClockFailure | 1 | BIT | 1 = clock source has failed. Timestamp unreliable. Must set validity=invalid in q if ClockFailure=1. |
| 7 b2 | ClockNotSynchronized | 1 | BIT | 1 = clock is running but has not been synchronized to a reference recently. Accuracy may degrade. |
| 7 b3–7 | TimeAccuracy | 5 | UINT5 | Log₂ of max error in seconds. 0=unspecified, 1=1s, 7=7.8ms, 10=1ms, 18=4μs, 20=1μs, 25=30ns, 31=clock failure. |

---

## 08 – Control Model (ctlModel) Values & Rules (IEC 61850-7-2 Table 29)

_ctlModel is a CF DA present in every controllable CDC (SPC, DPC, INC, ENC, APC, BSC). Encoded as MmsInteger (Enumerated)._

| ctlModel Value | Name | Oper Struct | SBO Required | Select Timeout | Rules & Description |
| --- | --- | --- | --- | --- | --- |
| 0 | status-only |  | No |  | DO is read-only status. No Operate service permitted. Oper struct absent from CO FC. Use for monitoring only. |
| 1 | direct-with-normal-security | Oper | No |  | Single-step direct control. Client sends Operate; IED executes immediately without select. No SBO handshake. Lowest security. |
| 2 | SBO-with-normal-security | Oper + SBO | Yes | sboTimeout ms | Two-step: client first sends Select (SBOw service), IED confirms, then client sends Operate within sboTimeout window. If timeout expires, IED auto-releases. |
| 3 | direct-with-enhanced-security | Oper | No |  | Direct control with AddCause feedback. IED returns AddCause in OperateResp. Client must check cause code. Enhanced = mandatory AddCause checking. |
| 4 | SBO-with-enhanced-security | Oper + SBO | Yes | sboTimeout ms | SBO with AddCause. Most secure: Select → OperateResp with AddCause. IED may reject if conditions not met. Default for protection trip outputs. |
| 5 | time-activated-operation | Oper + time | No |  | Client specifies future execution time in Oper.T. IED queues and executes at that time. Requires IEC 61850 time-activated services. |
| 6 | SBO-time-activated | Oper + SBO + time | Yes | sboTimeout ms | SBO plus time-activated. Select first, then time-activated Operate. Most complex. Used for scheduled switching. |

---

## 09 – TriggerConditions (TrgOps) BitString – IEC 61850-7-2 Table 25

_TrgOps is a 5-bit MmsBitString in RCB and LCB. Determines which DA changes cause a report or log entry to be generated._

| Bit | Abbr | Bit Value | FC Scope | Applies To | Rule / Description |
| --- | --- | --- | --- | --- | --- |
| 0 | dchg | 0x01 | ST, MX, SP, SV | stVal, mag, cVal, setMag | Data change trigger. Report sent when any DA with dchg trigger changes its value by more than the deadband (for MV) or any change (for ST/SP). |
| 1 | qchg | 0x02 | ST, MX | q | Quality change trigger. Report sent when the 'q' DA changes, even if the process value stVal/mag has not changed. Essential for invalid→valid transitions. |
| 2 | dupd | 0x04 | MX | instMag, instCVal | Data update trigger. Report sent every time instMag is updated by the scan cycle, regardless of deadband. Can generate very high traffic. Use carefully. |
| 3 | period | 0x08 | All | All DAs in dataset | Integrity period trigger. Report sent at the IntgPd interval (ms) with a snapshot of ALL dataset members, regardless of change. Ensures periodic heartbeat. |
| 4 | gi | 0x10 | All | All DAs in dataset | General Interrogation trigger. Report sent once when client sets RCB.GI=TRUE. Used for initial synchronization. GI bit auto-clears after report sent. |

---

## 15 – Standard Enumeration Definitions (IEC 61850-7-3 Annex B)

_All standard enumerations. Encoded as MmsInteger. Values outside defined range are rejected by conformant IEDs._

| Enumeration Name | Integer Value | Label / Name | Description / Rules |
| --- | --- | --- | --- |
| **▶  BehaviourModeKind** | | | |
| BehaviourModeKind | 1 | on | Normal operation. All outputs active. |
| BehaviourModeKind | 2 | blocked | Outputs blocked. Inputs monitored. Used for maintenance. |
| BehaviourModeKind | 3 | test | Test mode. Outputs may be driven by test values. q.test=1 set automatically. |
| BehaviourModeKind | 4 | test/blocked | Test mode with outputs blocked. |
| BehaviourModeKind | 5 | off | Function disabled. No outputs, no monitoring. |
| **▶  HealthKind** | | | |
| HealthKind | 1 | ok | No alarms. Function operating normally. |
| HealthKind | 2 | warning | Minor issue detected; function still operative. |
| HealthKind | 3 | alarm | Major fault; function may be inoperative. |
| **▶  CtlModels** | | | |
| CtlModels | 0 | status-only | Read-only; no control allowed. |
| CtlModels | 1 | direct-normal | Direct with normal security. |
| CtlModels | 2 | SBO-normal | SBO with normal security. |
| CtlModels | 3 | direct-enhanced | Direct with enhanced security (AddCause). |
| CtlModels | 4 | SBO-enhanced | SBO with enhanced security (AddCause). |
| **▶  OriginatorCategoryKind** | | | |
| OriginatorCategoryKind | 0 | not-supported | Originator category not supported. |
| OriginatorCategoryKind | 1 | bay-control | Control from bay control unit. |
| OriginatorCategoryKind | 2 | station-control | Control from station HMI/SCADA. |
| OriginatorCategoryKind | 3 | remote-control | Control from remote (telecontrol/SCADA). |
| OriginatorCategoryKind | 4 | automatic-bay | Automatic function at bay level. |
| OriginatorCategoryKind | 5 | automatic-station | Automatic at station level. |
| OriginatorCategoryKind | 6 | automatic-remote | Automatic remote. |
| OriginatorCategoryKind | 7 | maintenance | Maintenance/test operation. |
| OriginatorCategoryKind | 8 | process | Originator is a process (no human). |
| **▶  DPStatusKind** | | | |
| DPStatusKind | 0 | intermediate-state | Transient/moving state. Not stable. |
| DPStatusKind | 1 | off | Device is open/off. |
| DPStatusKind | 2 | on | Device is closed/on. |
| DPStatusKind | 3 | bad-state | Contradictory or unknown position. |
| **▶  BSCKind** | | | |
| BSCKind | 0 | stop | Maintain current tap position. |
| BSCKind | 1 | lower | Decrease tap by one step. |
| BSCKind | 2 | higher | Increase tap by one step. |
| BSCKind | 3 | reserved | Reserved. Do not use. |
| **▶  RangeKind** | | | |
| RangeKind | 0 | normal | Value within normal operating range. |
| RangeKind | 1 | high | Value above high limit (hLim). |
| RangeKind | 2 | low | Value below low limit (lLim). |
| RangeKind | 3 | high-high | Value above high-high limit (hhLim). Critical. |
| RangeKind | 4 | low-low | Value below low-low limit (llLim). Critical. |
| **▶  SmpMod** | | | |
| SmpMod | 0 | samples-per-period | SmpRate = samples per power cycle. |
| SmpMod | 1 | samples-per-second | SmpRate = samples per second. |
| SmpMod | 2 | seconds-per-sample | SmpRate = seconds between samples. |
| **▶  SmpSynch** | | | |
| SmpSynch | 0 | none | No external synchronisation. |
| SmpSynch | 1 | local | Synchronised to local clock. |
| SmpSynch | 2 | global | Synchronised to global reference (GPS/IEEE 1588). |
| **▶  AngleReferenceKind** | | | |
| AngleReferenceKind | 0 | Va | Phase A voltage reference. |
| AngleReferenceKind | 1 | Vb | Phase B voltage reference. |
| AngleReferenceKind | 2 | Vc | Phase C voltage reference. |
| AngleReferenceKind | 3 | Aa | Phase A current reference. |
| AngleReferenceKind | 4 | Ab | Phase B current reference. |
| AngleReferenceKind | 5 | Ac | Phase C current reference. |
| AngleReferenceKind | 6 | Vab | Phase AB voltage reference. |
| AngleReferenceKind | 7 | Vbc | Phase BC voltage reference. |
| AngleReferenceKind | 8 | Vca | Phase CA voltage reference. |