import os
import glob
import json
import sys
import xml.etree.ElementTree as ET

sys.path.append(r"c:\goose\sas_server\scripts")
import generate_per_ied_cid

def get_app_id_mapping():
    mapping = {}
    for ied_name, ip, port, bay_id, bay_desc, builder in generate_per_ied_cid.IED_TABLE:
        ip_parts = ip.split('.')
        c_octet = int(ip_parts[2])
        d_octet = int(ip_parts[3])
        
        goose_defs = []
        srv = ET.Element("Server")
        
        if "lambda" in str(builder):
            builder(srv, ied_name, goose_defs, bay_id, bay_desc)
        else:
            builder(srv, ied_name, goose_defs, bay_id, bay_desc)
            
        mac_counter = 1
        for ldi, gcbn in goose_defs:
            appid = 0x1000 + (c_octet << 8) + (d_octet << 4) + mac_counter
            # Format of gocbRef in config files: "IEDNameLdInst/LLN0$GO$cbName"
            gocbRef = f"{ied_name}{ldi}/LLN0$GO${gcbn}"
            mapping[gocbRef] = appid
            mac_counter += 1
            
    return mapping

def main():
    mapping = get_app_id_mapping()
    print("Generated APPID Mapping:")
    for k, v in mapping.items():
        print(f"  {k} -> {v} (0x{v:04X})")

    config_dir = r"c:\goose\sas_server\config"
    json_files = glob.glob(os.path.join(config_dir, "**", "*.json"), recursive=True)

    for jf in json_files:
        with open(jf, "r") as f:
            data = json.load(f)
        
        modified = False
        if "goose_subscriptions" in data:
            for sub in data["goose_subscriptions"]:
                ref = sub.get("gocbRef")
                
                # Fix typos in JSON configs
                if ref.startswith("E0") and "BCUE0" in ref:
                    # E01BCUE01BCU -> E01_BCUE01BCU
                    ref = ref.replace("BCUE0", "_BCUE0", 1)
                    sub["gocbRef"] = ref
                    modified = True
                
                if ("_P142E0" in ref or "_P142E1" in ref) and "TRF" in jf:
                    # E01_P142E01P142/ -> E01_P142E01P142HV/
                    ref = ref.replace("P142/", "P142HV/")
                    sub["gocbRef"] = ref
                    modified = True

                if ref in mapping:
                    expected = mapping[ref]
                    if sub.get("appId") != expected:
                        print(f"[{data.get('ied_name')}] Updating {ref} appId: {sub.get('appId')} -> {expected}")
                        sub["appId"] = expected
                        modified = True
                else:
                    print(f"Warning: {ref} not found in mapping!")
                    
        if modified:
            with open(jf, "w") as f:
                json.dump(data, f, indent=2)
                f.write("\n")
            print(f"Saved {jf}")

if __name__ == "__main__":
    main()
