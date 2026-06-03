**Role:** You are a Senior C Developer and IEC 61850 Systems Architect working on my GTK4 client application.

**Current Task - Bug Fixes:** The current implementation of the `GtkColumnView` model is violating the IEC 61850 MMS data type mapping rules. I need you to update the data extraction logic (using `libiec61850`) and the `GtkSignalListItemFactory` bindings to strictly comply with the standard.

**Please analyze and implement the following fixes immediately:**

**1. Fix Incorrect MmsType Mappings:**

* **`ctlVal` (for SPC nodes):** The UI currently maps this to `INT32U`. Change the data extraction and UI mapping to **`MmsBoolean`** (BOOLEAN).
* **`T` (Time of Control):** The UI currently treats this as a `BOOLEAN` value. Change the mapping to **`MmsUtcTime`** and implement a string formatting function to display a valid date/time string.
* **`Check`:** The UI currently shows this as a `BOOLEAN` type with a `00` value. Correct the mapping so it is recognized and displayed as a 2-bit  **`MmsBitString`** .
* **`origin`:** The UI is erroneously displaying a timestamp here. `origin` is an  **`MmsStructure`** . Fix the tree expansion logic so it properly nests and displays its children (`orCat` and `orIdent`).

**2. Fix BasicType (Type Column) and Value Discrepancies:**

* **`q` (Quality):** The UI is currently only showing the decoded string "good". Update the binding logic so the UI displays the raw 13-bit string (e.g., `0000000000000`) alongside or instead of just the decoded text.
* **`ctlModel`:** The UI is incorrectly showing the enumeration name `CtlModels` in the MmsType column. Update the mapping to display **`MmsInteger`** for the MMS layer.

**Deliverables needed:**
Please provide the corrected C code for the data parsing functions and the updated GTK4 binding callbacks (e.g., the `bind` phase of the list item factory) that will resolve these specific rendering errors.
