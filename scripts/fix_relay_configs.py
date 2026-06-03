#!/usr/bin/env python3
"""
fix_relay_configs.py — Regenerate all protection relay JSON configs.

Root cause: recreate_json.py generated configs with:
  - "protection_settings" key  → parser expects "protection"
  - Wrong field names inside   → "ptoc_51_pickup" vs "i_pickup_a"

This script writes the correct schema matching ied_config.c's expectations.
"""
import json, os

BASE = r"c:\goose\sas_server\config"

def write(path, data):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as f:
        json.dump(data, f, indent=2)
        f.write("\n")
    print(f"  [OK] {os.path.relpath(path, BASE)}")

# ─── GOOSE subscriptions (already correct in BCU configs, left unchanged) ───
# These are the subscriptions for BCUs — NOT modified here.
# We only fix protection relay configs (P142, P143, P543, P643, P746).

# ─── P643 Differential Relay defaults ───────────────────────────────────────
def p643(ied_name, ip, port):
    return {
        "ied_name": ied_name,
        "ip": ip,
        "port": port,
        "goose_interface": "4",
        "protection": {
            "type": "differential",
            "diff_threshold": 0.2,
            "nominal_v_kv": 86.6,
            "nominal_i_a": 200.0,
            "nominal_freq": 50.0
        },
        "goose_subscriptions": []
    }

# ─── P142/P143 Overcurrent Relay defaults ───────────────────────────────────
def oc(ied_name, ip, port, prot_type="overcurrent"):
    return {
        "ied_name": ied_name,
        "ip": ip,
        "port": port,
        "goose_interface": "4",
        "protection": {
            "type": prot_type,
            "i_pickup_a": 800.0,
            "curve_type": 1,         # 1 = IDMT
            "time_dial": 0.1,
            "nominal_v_kv": 86.6,
            "nominal_i_a": 200.0,
            "nominal_freq": 50.0
        },
        "goose_subscriptions": []
    }

# ─── P543 Distance Relay defaults ───────────────────────────────────────────
def p543(ied_name, ip, port):
    return {
        "ied_name": ied_name,
        "ip": ip,
        "port": port,
        "goose_interface": "4",
        "protection": {
            "type": "distance",
            "zone1_reach_ohm": 12.5,
            "zone1_delay_ms": 0,
            "zone2_reach_ohm": 25.0,
            "zone2_delay_ms": 400,
            "zone3_reach_ohm": 50.0,
            "zone3_delay_ms": 1000,
            "zone4_reach_ohm": 10.0,
            "zone4_delay_ms": 500,
            "ar_enabled": True,
            "ar_max_attempts": 1,
            "ar_dead_time_ms": 800,
            "nominal_v_kv": 86.6,
            "nominal_i_a": 200.0,
            "nominal_freq": 50.0
        },
        "goose_subscriptions": []
    }

# ─── P746 Busbar Relay defaults ──────────────────────────────────────────────
def p746(ied_name, ip, port):
    return {
        "ied_name": ied_name,
        "ip": ip,
        "port": port,
        "goose_interface": "4",
        "protection": {
            "type": "busbar",
            "nominal_v_kv": 86.6,
            "nominal_i_a": 200.0,
            "nominal_freq": 50.0
        },
        "goose_subscriptions": []
    }

# ─── Generate all 12 protection relay configs ────────────────────────────────
configs = [
    # E00 Busbar Protection
    (f"{BASE}/E00_BUSBAR/config/E00_P746.json", p746("E00_P746", "127.0.0.1", 10200)),

    # E01 Transformer-1
    (f"{BASE}/E01_TRF1/config/E01_P643.json",  p643("E01_P643",  "127.0.0.1", 10211)),
    (f"{BASE}/E01_TRF1/config/E01_P142.json",  oc  ("E01_P142",  "127.0.0.1", 10221)),

    # E02 Transformer-2
    (f"{BASE}/E02_TRF2/config/E02_P643.json",  p643("E02_P643",  "127.0.0.1", 10212)),
    (f"{BASE}/E02_TRF2/config/E02_P142.json",  oc  ("E02_P142",  "127.0.0.1", 10222)),

    # E03 Transformer-3
    (f"{BASE}/E03_TRF3/config/E03_P643.json",  p643("E03_P643",  "127.0.0.1", 10213)),
    (f"{BASE}/E03_TRF3/config/E03_P142.json",  oc  ("E03_P142",  "127.0.0.1", 10223)),

    # E04 Coupler (P143 = overcurrent, no AR)
    (f"{BASE}/E04_COUPLER/config/E04_P143.json", oc("E04_P143",  "127.0.0.1", 10243, "overcurrent")),

    # E05 Line-1
    (f"{BASE}/E05_LINE1/config/E05_P543.json", p543("E05_P543",  "127.0.0.1", 10251)),
    (f"{BASE}/E05_LINE1/config/E05_P142.json", oc  ("E05_P142",  "127.0.0.1", 10252)),

    # E06 Line-2
    (f"{BASE}/E06_LINE2/config/E06_P543.json", p543("E06_P543",  "127.0.0.1", 10261)),
    (f"{BASE}/E06_LINE2/config/E06_P142.json", oc  ("E06_P142",  "127.0.0.1", 10262)),
]

print(f"Fixing {len(configs)} protection relay config files...\n")
for path, data in configs:
    write(path, data)

print(f"\nDone. All configs now use the 'protection' key with correct field names.")
print("BCU configs were NOT modified (they were already correct).")
