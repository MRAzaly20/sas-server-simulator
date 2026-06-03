The `stVal` attribute is a **Mandatory (M)** attribute in every CDC where it appears and is primarily used for current process status.

### **Data Type & Encoding Rules for stVal**

The encoding of `stVal` changes based on the type of data it represents:

* **SPS (Single Point Status):** Maps to **BOOLEAN** (`MmsBoolean`). TRUE indicates on/closed.
* **DPS (Double Point Status):** Maps to **Enumerated** (`MmsInteger`). It uses four states: 0=intermediate, 1=off, 2=on, 3=bad-state.
* **INS (Integer Status):** Maps to **INT32** (`MmsInteger`).
* **ENS (Enumerated Status):** Maps to **Enumerated** (`MmsInteger`). The values are read-only and defined by the specific Logical Node (LN) specification.
* **ACT (Protection Activation):** Maps to **BOOLEAN** (`MmsBoolean`) for general or phase-specific alarms.
* **Controllable CDCs (SPC, DPC, INC, ENC):** The `stVal` reflects the current status *after* a control action has been executed.

### **Functional Constraints & Services**

* **Functional Constraint (FC):** `stVal` always carries the **ST** (Status) functional constraint.
* **Services:** It is readable via `GetDataValues` and can be reported or logged via `Report`, `GOOSE`, and `Log` services.
* **Trigger Options:** Changes to `stVal` are governed by the **dchg** (Data Change) and **qchg** (Quality Change) triggers.

### **Substitution Rules**

For several CDCs (SPS, DPS, INS, MV, SPC), `stVal` can be overridden using substitution attributes:

* **subEna:** A boolean flag to enable substitution.
* **subVal:** The value to be used as the status when `subEna` is TRUE.
* **q.source:** When substitution is active, the Quality bit for "source" (Bit 10) must be set to 1.
