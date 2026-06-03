**Task:** Implement the `genmodel.jar` workaround for multi-instance `XSWI` nodes across all CID profiles and add dynamic runtime configuration to match the double-bus scheme.

**Target Files:** `/config/cid/E01_BCU.cid` through `E06_BCU.cid`, and the core server initialization loop in `ied_c264_bcu.c` (or equivalent bootstrap source file).

Ensure that all modifications adhere strictly to the following 4 engineering guidelines:

#### 1. Standardize SCL Layout (`.cid` Files)

* For every single bay template file (`E01_BCU.cid` to `E06_BCU.cid`), rewrite the `XSWI` instances to match this self-closing structurally valid syntax:
  **XML**

  ```
  <LN lnClass="XSWI" lnType="XSWI1" inst="1">
    <DOI name="Mod">
      <DAI name="ctlModel">
        <Val>sbo-with-enhanced-security</Val>
      </DAI>
    </DOI>
  </LN>
  <LN lnClass="XSWI" lnType="XSWI1" inst="2" />
  <LN lnClass="XSWI" lnType="XSWI1" inst="3" />
  <LN lnClass="XSWI" lnType="XSWI1" inst="4" />
  ```
* Ensure **NO** `<DOI>` or `<DAI>` tags are nested inside instances 2, 3, or 4 to avoid triggering the generator bug.

#### 2. Clean DataTypeTemplates

* Navigate down to the `<DataTypeTemplates>` segment of the CID files.
* Locate and completely remove redundant `LNodeType` tags created for secondary switches (e.g., `id="XSWI2_Type"`, `id="XSWI3_Type"`, etc.).
* Verify that only a single, solid `LNodeType` block for `id="XSWI1"` exists, containing the correct data object mappings for `Pos` (Common Data Class: `DPC`).

#### 3. Secure Dataset Bindings

* Verify that the `<DataSet name="SwitchStatus">` block inside `<LN0>` retains all mandatory Functional Constraint Data Attributes (`FCDA`) for tracking all 4 elements:
  **XML**

  ```
  <FCDA ldInst="E06BCU" prefix="" lnClass="XSWI" fc="ST" lnInst="1" doName="Pos" daName="stVal"/>
  <FCDA ldInst="E06BCU" prefix="" lnClass="XSWI" fc="ST" lnInst="2" doName="Pos" daName="stVal"/>
  <FCDA ldInst="E06BCU" prefix="" lnClass="XSWI" fc="ST" lnInst="3" doName="Pos" daName="stVal"/>
  <FCDA ldInst="E06BCU" prefix="" lnClass="XSWI" fc="ST" lnInst="4" doName="Pos" daName="stVal"/>
  ```

#### 4. Implement Dynamic Runtime Bootstrap (C Backend Configuration)

* Because instances 2, 3, and 4 will automatically fall back to the default `ctlModel` defined in your base `DOType` block, write an initialization loop inside your main C runtime setup code to configure them dynamically on server boot.
* Provide the implementation using the standard model access API:
  **C**

  ```
  void init_double_bus_switch_control_models(IedModel* model) {
      const char* bays[] = {"E01BCU", "E02BCU", "E03BCU", "E04BCU", "E05BCU", "E06BCU"};
      char path[128];

      for(int i = 0; i < 6; i++) {
          for(int inst = 2; inst <= 4; inst++) {
              // Map the exact ACSI configuration path for the compiled MMS stack
              snprintf(path, sizeof(path), "%s/XSWI%d$CF$Pos$ctlModel", bays[i], inst);
              IedObject* ctlModelObj = IedModel_getModelNodeByObjectReference(model, path);
              if (ctlModelObj) {
                  // Force to Control Model 4 (SBO with Enhanced Security) or 1 (Direct)
                  // based on substation specification
                  ((DataAttribute*)ctlModelObj)->typeValue.enumVal = 4; 
              }
          }
      }
  }
  ```

**Deliverables Needed:**

1. Complete updated `.cid` block for `LN0` and the `XSWI` declarations for a single bay demonstrating this fix.
2. The explicit startup C snippet ensuring the internal model attributes are bound correctly at runtime after `IedServer_create()` execution.
