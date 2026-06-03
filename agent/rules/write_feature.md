**Role:** You are a Lead Systems Engineer and GTK4/C Developer.

**Task:** Implement the Read and Write features in our IEC 61850 Client. The implementation must strictly follow the "IEC 61850_MMS_ReadWrite_Rules" document provided previously. The UI must dynamically enable or disable write capabilities based on the Functional Constraint (FC) of the selected Data Attribute (DA) in the `GtkColumnView`.

**1. Access Control Logic (The FC Gateway):**
Create a C function `bool is_node_writable(FunctionalConstraint fc)` that acts as the gatekeeper.

* **Read-Only (Return FALSE):** `ST`, `MX`, `DC`, `EX`, `OR`.
* **Direct Write (Return TRUE):** `SP`, `SV`, `CF`, `BR`, `RP`.
* **Control Write (Return TRUE):** `CO`.
* *Note: Ignore `SE` (Setting Groups) for this phase.*

**2. GTK4 UI Implementation:**

* Bind a selection change listener to the `GtkColumnView`'s selection model.
* When a node is selected, evaluate its FC. If `is_node_writable()` is false, disable the "Write" button in the `GtkHeaderBar` and show a "Read Only" tooltip. If true, enable it.
* When the "Write" button is clicked, open a custom `GtkDialog` or `GtkPopover`.
  * If the FC is `SP`, `SV`, or `CF`: Show a "Direct Write" dialog with an entry field corresponding to the basic type (e.g., a float spinner for `FLOAT32`, a toggle for `BOOLEAN`).
  * If the FC is `CO`: Show a "Control Actions" dialog (Execute Direct Operate or Select-Before-Operate) utilizing the `ctlModel`.

**3. libiec61850 Dispatcher (Network Layer):**
Do not use raw MMS string construction. Use the high-level ACSI object references (e.g., `IED1CTRL/XCBR1.Pos.stVal`). Create a write dispatcher function that branches based on FC:

* **For SP/SV/CF:** Use `IedConnection_writeObject()`.
* **For CO:** You MUST use the `ControlObjectClient` API (e.g., `ControlObjectClient_operate()`). Do NOT use `IedConnection_writeObject` for CO.
* **For All Reads:** Use `IedConnection_readObject()`.

**4. Strict Threading (No UI Freezes):**
IEC 61850 network calls are blocking. You must wrap the `IedConnection_readObject`, `IedConnection_writeObject`, and `ControlObjectClient` calls in a background worker thread (e.g., using `GTask` or standard pthreads). When the network call returns, use `g_idle_add` to pass the `MmsValue` or error code back to the GTK main loop to update the UI.
