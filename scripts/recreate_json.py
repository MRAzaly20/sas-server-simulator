import os
import json
import sys

sys.path.append(r"c:\goose\sas_server\scripts")
from generate_per_ied_cid import IED_TABLE
from fix_goose_subs import get_app_id_mapping

def main():
    mapping = get_app_id_mapping()
    base_dir = r"c:\goose\sas_server\config"
    
    # Define bay folders
    bay_folders = {
        "E00": "E00_BUSBAR",
        "E01": "E01_TRF1",
        "E02": "E02_TRF2",
        "E03": "E03_TRF3",
        "E04": "E04_COUPLER",
        "E05": "E05_LINE1",
        "E06": "E06_LINE2",
    }
    
    for ied_name, ip, port, bay_id, bay_desc, _ in IED_TABLE:
        bay_folder = bay_folders.get(bay_id, f"{bay_id}_BAY")
        config_dir = os.path.join(base_dir, bay_folder, "config")
        os.makedirs(config_dir, exist_ok=True)
        
        file_path = os.path.join(config_dir, f"{ied_name}.json")
        
        data = {
            "ied_name": ied_name,
            "ip_address": ip,
            "port": port
        }
        
        if "P142" in ied_name or "P143" in ied_name or "P543" in ied_name or "P643" in ied_name or "P746" in ied_name:
            data["protection_settings"] = {
                "ptoc_50_pickup": 2000,
                "ptoc_51_pickup": 800,
                "ptoc_51_time_dial": 0.5,
                "ptoc_50N_pickup": 1500,
                "ptoc_51N_pickup": 400,
                "ptoc_51N_time_dial": 0.5,
                "pdif_pickup": 0.3,
                "nominal_voltage": 150000,
                "nominal_current": 1000
            }
        
        subs = []
        if "BCU" in ied_name:
            # Busbar Z1
            ref_z1 = "E00_P746E00P746Z1/LLN0$GO$gcbE00P746Z1"
            if ref_z1 in mapping:
                subs.append({"gocbRef": ref_z1, "appId": mapping[ref_z1], "action": "intertrip_open_cb"})
            # Busbar Z2
            ref_z2 = "E00_P746E00P746Z2/LLN0$GO$gcbE00P746Z2"
            if ref_z2 in mapping:
                subs.append({"gocbRef": ref_z2, "appId": mapping[ref_z2], "action": "intertrip_open_cb"})
            
            # Local protections
            if bay_id in ["E01", "E02", "E03"]:
                ref_p643 = f"{bay_id}_P643{bay_id}P643/LLN0$GO$gcbTrip"
                ref_p142 = f"{bay_id}_P142{bay_id}P142HV/LLN0$GO$gcbTrip"
                if ref_p643 in mapping: subs.append({"gocbRef": ref_p643, "appId": mapping[ref_p643], "action": "intertrip_open_cb"})
                if ref_p142 in mapping: subs.append({"gocbRef": ref_p142, "appId": mapping[ref_p142], "action": "intertrip_open_cb"})
            elif bay_id == "E04":
                ref_p143 = f"E04_P143E04P143/LLN0$GO$gcbTrip"
                if ref_p143 in mapping: subs.append({"gocbRef": ref_p143, "appId": mapping[ref_p143], "action": "intertrip_open_cb"})
            elif bay_id in ["E05", "E06"]:
                ref_p543 = f"{bay_id}_P543{bay_id}P543/LLN0$GO$gcbTrip"
                ref_p142 = f"{bay_id}_P142{bay_id}P142/LLN0$GO$gcbTrip"
                if ref_p543 in mapping: subs.append({"gocbRef": ref_p543, "appId": mapping[ref_p543], "action": "intertrip_open_cb"})
                if ref_p142 in mapping: subs.append({"gocbRef": ref_p142, "appId": mapping[ref_p142], "action": "intertrip_open_cb"})
            
            # Coupler status
            if bay_id != "E04":
                ref_e04 = "E04_BCUE04BCU/LLN0$GO$gcbE04BCU"
                if ref_e04 in mapping: subs.append({"gocbRef": ref_e04, "appId": mapping[ref_e04], "action": "coupler_status"})

        data["goose_subscriptions"] = subs
        
        with open(file_path, "w") as f:
            json.dump(data, f, indent=2)
            f.write("\n")
        print(f"Recreated {file_path}")

if __name__ == "__main__":
    main()
