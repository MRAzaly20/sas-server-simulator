**Role:** Senior Embedded Systems Engineer and IEC 61850 Protocol Expert.

**Context:** There is a critical architectural mismatch between our GTK4 HMI Client and the `sas_server` backend for the GI 150kV ANTAM Pomalaa simulation suite. The Client UI models a double-busbar topology utilizing the `E04` Bus Coupler, while the IED server background processes (`ied_c264_bcu.c`, `.cid` files, and static C headers) are artificially restricted to a single-bus topology with only one disconnector.

**Objective:** Refactor the `sas_server` backend to fully upgrade all bays (E01 to E06) from a single-bus architecture to a **Double-Bus Configuration** to match the HMI client's expectations.

**Execute the refactoring strictly across the following four layers:**

#### 1. SCL Data Model Modifications (.cid Files)

- Modify the SCL XML structures for all 6 bays (E01 through E06) within `/config/cid/`.
- Inside the Bay Control Unit (BCU) logical device (`LD0` or `CTRL`), expand the `LN` instances to contain four distinct switches under the `XSWI` and `XCBR` classes:
  - **`XSWI1`** : Bus-A Disconnector (DS-A)
  - **`XSWI2`** : Bus-B Disconnector (DS-B)
  - **`XSWI3`** : Line / Transformer Disconnector (DS-L / DS-T)
  - **`XSWI4`** : Earthing Switch (ES)
  - **`XCBR1`** : Circuit Breaker (CB)
- Ensure each new `XSWI` node exposes its complete Common Data Class (CDC) attributes for position tracking: `Pos.stVal` `[ST]`, `Pos.q` `[ST]`, `Pos.t` `[ST]`, and the control structure `Pos.Oper` `[CO]`.

#### 2. Static Memory Mapping & C Header Generation

- Re-generate or manually update the static configuration structs (e.g., `E05_BCU.h`, `E06_BCU.h`) to align with the new CID structures.
- Replace the legacy, singular `dis_bus_closed` variable in your model state structs with explicit tracking members:
  **C**

  ```
  typedef struct {
      int xswi1_pos; // Bus-A Disconnector Status (0: Inter, 1: Open, 2: Closed, 3: Fault)
      int xswi2_pos; // Bus-B Disconnector Status
      int xswi3_pos; // Line/Transformer Disconnector Status
      int xswi4_pos; // Earthing Switch Status
      int xcbr1_pos; // Circuit Breaker Status
  } BaySwitchState;
  ```

#### 3. Backend Control Logic Expansion (`ied_c264_bcu.c`)

- Expand the MMS server callback handlers to parse and route `Write` and `Operate` commands for `XSWI1`, `XSWI2`, `XSWI3`, and `XSWI4`.
- Update the `IedServer_updateInt32AttributeValue` routine loops so that when a switch changes state locally (via background physical simulation or manual injection), it pushes the update to the correct object reference pointer.

#### 4. Double-Bus Interlocking & Bus-Coupler Integration

- Rewrite the safety interlocking state-machine within the server logic to enforce double-bus switching constraints:
  - **Isolator under Load Prevention:** Block any operation (`Operate` request returns `AddCause: Position-Inoperable`) on `XSWI1` or `XSWI2` if `XCBR1` is CLOSED, _unless_ a safe bus-transfer condition is met.
  - **Bus Transfer (Parallel Switching) Rule:** Allow both `XSWI1` and `XSWI2` to be CLOSED simultaneously if and only if **Bay E04 (Bus Coupler)** reports its Circuit Breaker and both its bus disconnectors are CLOSED (`stVal == 2`), indicating Busbar A and Busbar B are securely synchronized at the same electrical potential.
  - **Grounding Safety:** Permanently block closing the Earthing Switch (`XSWI4`) if `XCBR1`, `XSWI1`, `XSWI2`, or `XSWI3` are closed.
