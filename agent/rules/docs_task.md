**Role:** You are a Senior Technical Writer and IEC 61850 Systems Architect.

**Objective:** Generate comprehensive, developer-ready documentation for the `sas_server` project (The Distributed IED Simulation Suite for the GI 150kV ANTAM POMALAA architecture).

**Format Requirements:** > Write the documentation in clean, well-structured Markdown. Use Mermaid.js syntax to generate architecture diagrams where applicable.

**Please generate a master `README.md` that strictly includes the following sections:**

**1. Project Overview & Scope**

* Explain the concept of this simulator (multiple independent `.exe` files acting as standalone IEC 61850 servers).
* Briefly summarize the supported bays (Line, Transformer, Coupler) and the primary IED models simulated (MiCOM P543, P643, P746, C264).

**2. System Architecture**

* Describe the separation of the `libiec61850` backend network logic
* Explain the GOOSE peer-to-peer communication strategy (e.g., how the P746 listens to CBF signals, and how the C264 handles interlocking).
* **[Action]:** Include a Mermaid.js block diagram showing the relationship between the Orchestrator Script, the IED Executables, and the virtual network.

**3. Repository Structure**

* Document the directory layout (`/src`, `/config`, `/build`, `/scripts`) and explain what developers will find in each folder.

**4. Prerequisites & Build Instructions**

* List all required C libraries (`libiec61850`, etc).
* Note the requirement for Npcap/WinPcap for raw Ethernet GOOSE transmission.
* Provide the exact CMake or Make commands required to compile the suite.

**5. Configuration Guide**

* Explain how the simulator uses CID files (`/config/cid`) to build the MMS data model.
* Explain the JSON configuration schema used to assign Virtual IPs and ports to prevent conflicts between the executables.

**6. Running the Simulation**

* Provide step-by-step instructions on how to use the launcher scripts in the `/scripts` directory to boot up the entire substation or just a single bay.
