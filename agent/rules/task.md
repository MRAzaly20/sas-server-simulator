> **Role:** You are a Senior Systems Architect and C/GTK4 Developer.
>
> **Objective:** Refactor the existing monolithic simulator into a **Distributed IED Simulation Suite** where each physical IED from the GI 150kV ANTAM POMALAA architecture is a standalone, independent executable.
>
> **1. Multi-Executable Architecture (.exe):**
>
> - Every IED (e.g., MiCOM P543, P643, C264, P746) must be compiled into its own independent executable.
> - Each `.exe` must be a self-contained **IEC 61850 Server** .
> - On startup, the executable must load its unique **CID file** to define its specific Logical Devices (LD) and Logical Nodes (LN).
>
> **2. Networking & Port Management:**
>
> - Implement a configuration mechanism (via JSON) so each executable can bind to a specific **Virtual IP address** or a unique MMS port to prevent port 102 conflicts during local simulation.
> - Use the `libiec61850` server API to handle MMS Read/Write requests for its internal data model.
>
> **3. GOOSE Peer-to-Peer Transmission:**
>
> - **Publishers:** Implement logic where a protection IED (like P543) publishes a GOOSE message immediately upon a fault/trip event (e.g., `PDIS.Op.general`).
> - **Subscribers:** Implement real-time GOOSE listeners. For example, the **Busbar Protection P746** must subscribe to the `CBF_Initiate` GOOSE signal from bay relays to initiate backup tripping.
> - **Interlocking:** The **C264 BCU** must subscribe to GOOSE status signals from other bays to validate interlocking logic before executing an `Operate` command.
>
> **4. Autonomous Behavioral Logic:**
>
> - Each IED must run its own internal "Protection Loop." For instance, a P142 executable should monitor a simulated current value; if current > `setMag` (from CID), it must update its `stVal` and trigger a GOOSE trip independently.
>
> **5. Build System:**
>
> - Provide a `CMakeLists.txt` or `Makefile` capable of building all 33+ individual IED executables from a modular codebase.
>
> _Important_: IED must have its own code that acts as an IEC 61850 server while also running GOOSE pub/sub for data transmission between IEDs in the event of a fault, inter-trip, or control signal to another IED, and each IED must have an executable file (.exe) serving as an IEC 61850 server. Create a structured folder for each IED in the 6 Line Bay
>
> **Deliverable:** Start by providing the code structure for a single `ied_server_base.c` template that handles CID loading and GOOSE initialization, then show the specific logic for the **Line-1 P543 Distance Relay** executable.
