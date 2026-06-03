**Role:** Senior IEC 61850 Systems Architect and C/GTK4 Developer.

**Task:** Add CT/VT secondary injection simulation and live metering features to the Distributed IED Executables (e.g., P543, P142, C264). The simulator must display 3-phase plus neutral values for both Normal and Fault conditions.

**1. Data Model (CID & libiec61850) Requirements:**

* Update the CID files for the protection relays and BCUs to include the **`MMXU` (Measurement)** Logical Node for metering, and **`PTOC`/`PDIS`** for protection tracking.
* The phase currents and voltages must be mapped using the **WYE CDC** (Complex Measured Value).
* Ensure the C code targets the exact ACSI paths:
  * `MMXU1.A.phsA.cVal.mag.f [MX]` (Phase A Current)
  * `MMXU1.PhV.phsA.cVal.mag.f [MX]` (Phase A Voltage)
* Strictly enforce that these are `FC=MX` (Read-Only to the client).

**2. The Simulation Engine (Background Loop):**

* Implement a threaded background loop in the `.exe` that acts as the "Physics Engine" updating the `libiec61850` server values.
* **Normal State:** Output nominal secondary values (e.g., 1.0A or 5.0A current, 63.5V voltage). Add a slight randomized jitter (±0.01) every 500ms to simulate live transducer noise.
* **Fault State:** Create an API or internal struct that allows the program to override nominal values with fault values (e.g., spiking `phsA` current to 20.0A and dropping `phsA` voltage to 10.0V).
