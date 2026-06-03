#!/usr/bin/env python3
"""Generate the A SAS CID file for IEC 61850 simulation."""

import xml.etree.ElementTree as ET
from xml.dom import minidom

NS = "http://www.iec.ch/61850/2003/SCL"
XSI = "http://www.w3.org/2001/XMLSchema-instance"

def E(tag, attrib=None, text=None, **kw):
    a = dict(attrib or {})
    a.update(kw)
    e = ET.Element(tag, a)
    if text: e.text = str(text)
    return e

def SE(parent, tag, attrib=None, text=None, **kw):
    a = dict(attrib or {})
    a.update(kw)
    e = ET.SubElement(parent, tag, a)
    if text: e.text = str(text)
    return e

# ─── Root ───
root = E("SCL", {"xmlns": NS, "xmlns:xsi": XSI})

# ─── Header ───
hdr = SE(root, "Header", id="ANTAM_POMALAA", version="1", revision="0",
         toolID="SAS_Generator", nameStructure="IEDName")
SE(hdr, "Text", text="GI 150kV A SAS Simulator")

# ─── Substation ───
sub = SE(root, "Substation", name="GI_ANTAM_POMALAA", desc="GI 150kV A")
vl = SE(sub, "VoltageLevel", name="VL150kV", desc="150 kV Voltage Level")
SE(vl, "Voltage", {"unit": "V", "multiplier": "k"}, text="150")

bay_defs = [
    ("E01", "Transformer-1", [("CBR","QA1","XCBR","E01BCU"),("DIS","QB1","CSWI","E01BCU"),("CTR","T1","MMXU","E01P643")]),
    ("E02", "Transformer-2", [("CBR","QA1","XCBR","E02BCU"),("DIS","QB1","CSWI","E02BCU"),("CTR","T1","MMXU","E02P643")]),
    ("E03", "Transformer-3", [("CBR","QA1","XCBR","E03BCU"),("DIS","QB1","CSWI","E03BCU"),("CTR","T1","MMXU","E03P643")]),
    ("E04", "Coupler",       [("CBR","QA1","XCBR","E04BCU"),("DIS","QB1","CSWI","E04BCU")]),
    ("E05", "Line-1",        [("CBR","QA1","XCBR","E05BCU"),("DIS","QB1","CSWI","E05BCU"),("CTR","T1","MMXU","E05P543")]),
    ("E06", "Line-2",        [("CBR","QA1","XCBR","E06BCU"),("DIS","QB1","CSWI","E06BCU"),("CTR","T1","MMXU","E06P543")]),
]

for bid, bdesc, equips in bay_defs:
    bay = SE(vl, "Bay", name=bid, desc=bdesc)
    for etype, ename, lnclass, ldinst in equips:
        ce = SE(bay, "ConductingEquipment", type=etype, name=ename)
        SE(ce, "LNode", iedName="SASSIM", ldInst=ldinst, lnClass=lnclass, lnInst="1")

# ─── Communication ───
comm = SE(root, "Communication")

# MMS subnet
sn1 = SE(comm, "SubNetwork", name="MMS_Net", type="8-MMS", desc="MMS over TCP/IP")
SE(sn1, "BitRate", {"unit": "b/s", "multiplier": "M"}, text="100")
cap = SE(sn1, "ConnectedAP", iedName="SASSIM", apName="AP1")
addr = SE(cap, "Address")
for pt, pv in [("IP","10.0.0.100"),("IP-SUBNET","255.255.255.0"),("IP-GATEWAY","10.0.0.1"),
               ("OSI-TSEL","0001"),("OSI-PSEL","00000001"),("OSI-SSEL","0001")]:
    SE(addr, "P", {"type": pt}, text=pv)

# GOOSE setup uses the same AP (cap) under Station_Bus

goose_defs = [
    # (ldInst, cbName, mac_last, appid, vlan_prio, desc)
    ("E01BCU",   "gcbE01BCU",   "01", "1001", "4"),
    ("E02BCU",   "gcbE02BCU",   "02", "1002", "4"),
    ("E03BCU",   "gcbE03BCU",   "03", "1003", "4"),
    ("E04BCU",   "gcbE04BCU",   "04", "1004", "4"),
    ("E05BCU",   "gcbE05BCU",   "05", "1005", "7"),
    ("E06BCU",   "gcbE06BCU",   "06", "1006", "7"),
    ("E00P746Z1","gcbE00P746Z1","10", "2001", "7"),
    ("E00P746Z2","gcbE00P746Z2","11", "2002", "7"),
    ("E00P746CZ","gcbE00P746CZ","12", "2003", "7"),
]

for ldi, cbn, mac_suf, appid, prio in goose_defs:
    gse = SE(cap, "GSE", ldInst=ldi, cbName=cbn)
    ga = SE(gse, "Address")
    SE(ga, "P", {"type":"VLAN-ID"}, text="1")
    SE(ga, "P", {"type":"VLAN-PRIORITY"}, text=prio)
    SE(ga, "P", {"type":"MAC-Address"}, text=f"01-0C-CD-01-00-{mac_suf}")
    SE(ga, "P", {"type":"APPID"}, text=appid)
    SE(gse, "MinTime", {"unit":"ms"}, text="4")
    SE(gse, "MaxTime", {"unit":"ms"}, text="1000")

# ─── IED ───
ied = SE(root, "IED", name="SASSIM", desc="GI 150kV A SAS Simulator",
         type="SAS_Simulator", manufacturer="ANTAM_SIM", configVersion="1.0")

svc = SE(ied, "Services")
for s in ["DynAssociation","GetDirectory","GetDataObjectDefinition","GetDataSetValue",
          "SetDataSetValue","DataSetDirectory","ReadWrite","GetCBValues"]:
    SE(svc, s)
SE(svc, "GOOSE", max="20")
SE(svc, "ConfReportControl")
SE(svc, "FileHandling")

ap = SE(ied, "AccessPoint", name="AP1", desc="Primary Access Point")
srv = SE(ap, "Server", timeout="30")
SE(srv, "Authentication", none="true")

# ─── Helper: add standard LN0 DOs ───
def add_ln0_dois(ln0, desc_text):
    doi = SE(ln0, "DOI", name="Mod")
    SE(SE(doi, "DAI", name="ctlModel"), "Val", text="status-only")
    doi2 = SE(ln0, "DOI", name="NamPlt")
    SE(SE(doi2, "DAI", name="vendor"), "Val", text="ANTAM_SIM")
    SE(SE(doi2, "DAI", name="swRev"), "Val", text="1.0.0")
    SE(SE(doi2, "DAI", name="d"), "Val", text=desc_text)

# ─── Helper: add standard breaker bay LN set ───
def add_bcu_ld(srv, ldi, desc, has_line_dis=True):
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_BCU", inst="")
    # Dataset for switch status
    ds = SE(ln0, "DataSet", name="SwitchStatus")
    SE(ds, "FCDA", ldInst=ldi, lnClass="XCBR", fc="ST", lnInst="1", doName="Pos", daName="stVal")
    SE(ds, "FCDA", ldInst=ldi, lnClass="XCBR", fc="ST", lnInst="1", doName="Pos", daName="q")
    SE(ds, "FCDA", ldInst=ldi, lnClass="CSWI", fc="ST", lnInst="1", doName="Pos", daName="stVal")
    # RCB
    rcb = SE(ln0, "ReportControl", name="SwitchRCB", confRev="1", datSet="SwitchStatus",
             rptID=f"SASSIM/{ldi}/LLN0.SwitchRCB", buffered="false", intgPd="5000", bufTime="50")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="true", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="false", configRef="true", bufOvfl="false")
    SE(rcb, "RptEnabled", max="5")
    # GOOSE
    gcb_name = f"gcb{ldi.replace('_','')}"
    SE(ln0, "GSEControl", appID=ldi, name=gcb_name, type="GOOSE", datSet="SwitchStatus", confRev="1")
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    # XCBR
    xcbr = SE(ld, "LN", lnClass="XCBR", lnType="XCBR1", inst="1", prefix="")
    doi = SE(xcbr, "DOI", name="Pos")
    SE(SE(doi, "DAI", name="ctlModel"), "Val", text="sbo-with-normal-security")
    # CSWI (bus-side disconnector)
    cswi = SE(ld, "LN", lnClass="CSWI", lnType="CSWI1", inst="1", prefix="")
    doi = SE(cswi, "DOI", name="Pos")
    SE(SE(doi, "DAI", name="ctlModel"), "Val", text="direct-with-normal-security")
    # XSWI (line-side disconnector)
    if has_line_dis:
        xswi = SE(ld, "LN", lnClass="XSWI", lnType="XSWI1", inst="1", prefix="")
        doi = SE(xswi, "DOI", name="Pos")
        SE(SE(doi, "DAI", name="ctlModel"), "Val", text="direct-with-normal-security")
    # GGIO for aux I/O
    ggio = SE(ld, "LN", lnClass="GGIO", lnType="GGIO_BCU", inst="1", prefix="")
    SE(SE(SE(ggio, "DOI", name="Mod"), "DAI", name="ctlModel"), "Val", text="status-only")
    return ld

# ─── Helper: add overcurrent protection LD ───
def add_ptoc_ld(srv, ldi, desc):
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="TripData")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="q")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTOC", fc="ST", lnInst="1", doName="Op", daName="general")
    rcb = SE(ln0, "ReportControl", name="TripBRCB", confRev="1", datSet="TripData",
             rptID=f"SASSIM/{ldi}/LLN0.TripBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    # PTOC instances: 1=50, 2=51, 3=50N, 4=51N
    for i in range(1, 5):
        SE(ld, "LN", lnClass="PTOC", lnType="PTOC1", inst=str(i), prefix="")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")
    return ld

# ─── Helper: transformer differential LD ───
def add_pdif_ld(srv, ldi, desc):
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="DiffTrip")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PDIF", fc="ST", lnInst="1", doName="Op", daName="general")
    rcb = SE(ln0, "ReportControl", name="DiffBRCB", confRev="1", datSet="DiffTrip",
             rptID=f"SASSIM/{ldi}/LLN0.DiffBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    SE(ld, "LN", lnClass="PDIF", lnType="PDIF1", inst="1", prefix="")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")
    SE(ld, "LN", lnClass="MMXU", lnType="MMXU1", inst="1", prefix="")
    return ld

# ─── Helper: distance protection LD (P543) ───
def add_pdis_ld(srv, ldi, desc):
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="DistTrip")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="general")
    for z in range(1, 5):
        SE(ds, "FCDA", ldInst=ldi, lnClass="PDIS", fc="ST", lnInst=str(z), doName="Op", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="RREC", fc="ST", lnInst="1", doName="Op", daName="general")
    rcb = SE(ln0, "ReportControl", name="DistBRCB", confRev="1", datSet="DistTrip",
             rptID=f"SASSIM/{ldi}/LLN0.DistBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    for z in range(1, 5):
        ln = SE(ld, "LN", lnClass="PDIS", lnType="PDIS1", inst=str(z), prefix="")
        doi = SE(ln, "DOI", name="Op")
        SE(SE(doi, "DAI", name="d"), "Val", text=f"Zone {z} Distance Protection")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")
    SE(ld, "LN", lnClass="RREC", lnType="RREC1", inst="1", prefix="")
    SE(ld, "LN", lnClass="RSYN", lnType="RSYN1", inst="1", prefix="")
    SE(ld, "LN", lnClass="MMXU", lnType="MMXU1", inst="1", prefix="")
    return ld

# ─── Helper: busbar protection LD (P746) ───
def add_bbprot_ld(srv, ldi, desc, zone_name):
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="BBTrip")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PDIF", fc="ST", lnInst="1", doName="Op", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="RBRF", fc="ST", lnInst="1", doName="OpEx", daName="general")
    rcb = SE(ln0, "ReportControl", name="BBRCB", confRev="1", datSet="BBTrip",
             rptID=f"SASSIM/{ldi}/LLN0.BBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    gcbn = f"gcb{ldi.replace('_','')}"
    SE(ln0, "GSEControl", appID=ldi, name=gcbn, type="GOOSE", datSet="BBTrip", confRev="1")
    add_ln0_dois(ln0, f"Busbar Protection {zone_name}")
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    pdif = SE(ld, "LN", lnClass="PDIF", lnType="PDIF_BB", inst="1", prefix="")
    SE(SE(SE(pdif, "DOI", name="Op"), "DAI", name="d"), "Val", text=f"87B {zone_name}")
    SE(ld, "LN", lnClass="RBRF", lnType="RBRF1", inst="1", prefix="")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")
    return ld

# ═══ Build all Logical Devices ═══

# Transformer bays (E01, E02, E03) — each has BCU + P643 + P142HV + P142LV
for i in range(1, 4):
    bid = f"E0{i}"
    add_bcu_ld(srv, f"{bid}BCU", f"Transformer-{i} Bay Control Unit (C264)")
    add_pdif_ld(srv, f"{bid}P643", f"Transformer-{i} Differential Protection (P643)")
    add_ptoc_ld(srv, f"{bid}P142HV", f"Transformer-{i} HV Overcurrent (P142)")
    add_ptoc_ld(srv, f"{bid}P142LV", f"Transformer-{i} LV Overcurrent (P142)")

# Coupler bay (E04)
add_bcu_ld(srv, "E04BCU", "Coupler Bay Control Unit (C264)", has_line_dis=False)
add_ptoc_ld(srv, "E04P143", "Coupler Overcurrent Protection (P143)")

# Line bays (E05, E06) — each has BCU + P142 + P543
for i, ln in [(5,"Line-1"),(6,"Line-2")]:
    bid = f"E0{i}"
    add_bcu_ld(srv, f"{bid}BCU", f"{ln} Bay Control Unit (C264)")
    add_ptoc_ld(srv, f"{bid}P142", f"{ln} Backup Overcurrent (P142)")
    add_pdis_ld(srv, f"{bid}P543", f"{ln} Distance + Auto-Reclose (P543)")

# Busbar protection (E00)
add_bbprot_ld(srv, "E00P746Z1", "Busbar Protection Zone 1 (P746)", "Zone 1")
add_bbprot_ld(srv, "E00P746Z2", "Busbar Protection Zone 2 (P746)", "Zone 2")
add_bbprot_ld(srv, "E00P746CZ", "Busbar Protection Check Zone (P746)", "Check Zone")

# Common I/O
ld_io = SE(srv, "LDevice", inst="E00IO", desc="Common IED I/O (C264)")
ln0_io = SE(ld_io, "LN0", lnClass="LLN0", lnType="LLN0_BCU", inst="")
add_ln0_dois(ln0_io, "Common I/O Panel")
SE(ld_io, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
ggio_io = SE(ld_io, "LN", lnClass="GGIO", lnType="GGIO_IO", inst="1", prefix="")
SE(SE(SE(ggio_io, "DOI", name="Mod"), "DAI", name="ctlModel"), "Val", text="status-only")

# Energy metering
ld_meas = SE(srv, "LDevice", inst="E00MEAS", desc="Energy Metering (ION 8650)")
ln0_m = SE(ld_meas, "LN0", lnClass="LLN0", lnType="LLN0_MEAS", inst="")
ds_m = SE(ln0_m, "DataSet", name="MeasData")
SE(ds_m, "FCDA", ldInst="E00MEAS", lnClass="MMXU", fc="MX", lnInst="1", doName="TotW")
SE(ds_m, "FCDA", ldInst="E00MEAS", lnClass="MMXU", fc="MX", lnInst="1", doName="TotVAr")
SE(ds_m, "FCDA", ldInst="E00MEAS", lnClass="MMXU", fc="MX", lnInst="1", doName="Hz")
rcb_m = SE(ln0_m, "ReportControl", name="MeasRCB", confRev="1", datSet="MeasData",
           rptID="SASSIM/E00MEAS/LLN0.MeasRCB", buffered="false", intgPd="5000", bufTime="0")
SE(rcb_m, "TrgOps", dchg="true", qchg="true", dupd="false", period="true", gi="true")
SE(rcb_m, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
   dataRef="false", entryID="false", configRef="true", bufOvfl="false")
SE(rcb_m, "RptEnabled", max="5")
add_ln0_dois(ln0_m, "Energy Metering Panel")
SE(ld_meas, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
SE(ld_meas, "LN", lnClass="MMXU", lnType="MMXU1", inst="1", prefix="")

# ═══ DataTypeTemplates ═══
dtt = SE(root, "DataTypeTemplates")

# --- LNodeTypes ---
def add_lnt(dtt, lid, lnc, dos):
    lnt = SE(dtt, "LNodeType", id=lid, lnClass=lnc)
    for dn, dt in dos:
        SE(lnt, "DO", name=dn, type=dt)

add_lnt(dtt, "LLN0_BCU", "LLN0", [("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1")])
add_lnt(dtt, "LLN0_PROT", "LLN0", [("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1")])
add_lnt(dtt, "LLN0_MEAS", "LLN0", [("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1")])
add_lnt(dtt, "LPHD1", "LPHD", [("PhyNam","DPL1"),("PhyHealth","INS1"),("Proxy","SPS1")])

add_lnt(dtt, "XCBR1", "XCBR", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Pos","DPC1"),("BlkOpn","SPC1"),("BlkCls","SPC1"),("CBOpCap","INS1"),
])
add_lnt(dtt, "CSWI1", "CSWI", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),("Pos","DPC1"),
])
add_lnt(dtt, "XSWI1", "XSWI", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),("Pos","DPC1"),
])

add_lnt(dtt, "GGIO_BCU", "GGIO", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Ind1","SPS1"),("Ind2","SPS1"),("Ind3","SPS1"),("Ind4","SPS1"),
    ("SPCSO1","SPC1"),("SPCSO2","SPC1"),
])
add_lnt(dtt, "GGIO_IO", "GGIO", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Ind1","SPS1"),("Ind2","SPS1"),("Ind3","SPS1"),("Ind4","SPS1"),
    ("AnIn1","MV1"),("AnIn2","MV1"),("AnIn3","MV1"),("AnIn4","MV1"),
])

add_lnt(dtt, "PTOC1", "PTOC", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Op","ACT1"),("Str","ACD1"),
])
add_lnt(dtt, "PDIS1", "PDIS", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Op","ACT1"),("Str","ACD1"),
])
add_lnt(dtt, "PDIF1", "PDIF", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Op","ACT1"),("Str","ACD1"),
])
add_lnt(dtt, "PDIF_BB", "PDIF", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Op","ACT1"),
])
add_lnt(dtt, "PTRC1", "PTRC", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Tr","ACT1"),
])
add_lnt(dtt, "RREC1", "RREC", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("Op","ACT1"),("AutoRecSt","INS1"),
])
add_lnt(dtt, "RSYN1", "RSYN", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("RsSyn","SPS1"),
])
add_lnt(dtt, "RBRF1", "RBRF", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("OpEx","ACT1"),("FailMod","INS1"),
])
add_lnt(dtt, "MMXU1", "MMXU", [
    ("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
    ("TotW","MV1"),("TotVAr","MV1"),("TotVA","MV1"),("Hz","MV1"),
    ("PhV","WYE1"),("A","WYE1"),
])

# --- DOTypes ---
def add_dot(dtt, did, cdc, das):
    dot = SE(dtt, "DOType", id=did, cdc=cdc)
    for dn, btype, fc, *extra in das:
        a = {"name": dn, "bType": btype, "fc": fc}
        if extra: a["type"] = extra[0]
        SE(dot, "DA", **a)

add_dot(dtt, "INC1", "INC", [
    ("stVal","INT32","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
    ("ctlModel","Enum","CF","CtlModels"),
])
add_dot(dtt, "INS1", "INS", [
    ("stVal","INT32","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
])
add_dot(dtt, "SPS1", "SPS", [
    ("stVal","BOOLEAN","ST"),("q","Quality","ST"),("t","Timestamp","ST"),("d","VisString255","DC"),
])
add_dot(dtt, "SPC1", "SPC", [
    ("stVal","BOOLEAN","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
    ("ctlModel","Enum","CF","CtlModels"),("Oper","Struct","CO","SPCOperate"),
    ("d","VisString255","DC"),
])
add_dot(dtt, "DPC1", "DPC", [
    ("stVal","Dbpos","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
    ("ctlModel","Enum","CF","CtlModels"),("Oper","Struct","CO","DPCOperate"),
    ("d","VisString255","DC"),
])
add_dot(dtt, "MV1", "MV", [
    ("mag","Struct","MX","AnalogueValue"),("q","Quality","MX"),("t","Timestamp","MX"),
    ("d","VisString255","DC"),
])
add_dot(dtt, "WYE1", "WYE", [
    ("phsA","Struct","MX","CMV1"),("phsB","Struct","MX","CMV1"),("phsC","Struct","MX","CMV1"),
    ("d","VisString255","DC"),
])
add_dot(dtt, "ACT1", "ACT", [
    ("general","BOOLEAN","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
    ("d","VisString255","DC"),
])
add_dot(dtt, "ACD1", "ACD", [
    ("general","BOOLEAN","ST"),("dirGeneral","Enum","ST","FaultDirection"),
    ("q","Quality","ST"),("t","Timestamp","ST"),("d","VisString255","DC"),
])
add_dot(dtt, "LPL1", "LPL", [
    ("vendor","VisString255","DC"),("swRev","VisString255","DC"),
    ("d","VisString255","DC"),("configRev","VisString255","DC"),("ldNs","VisString255","EX"),
])
add_dot(dtt, "DPL1", "DPL", [
    ("vendor","VisString255","DC"),("hwRev","VisString255","DC"),
    ("swRev","VisString255","DC"),("serNum","VisString255","DC"),
    ("model","VisString255","DC"),
])

# --- DATypes ---
def add_dat(dtt, did, bdas):
    dat = SE(dtt, "DAType", id=did)
    for bn, bt, *extra in bdas:
        a = {"name": bn, "bType": bt}
        if extra: a["type"] = extra[0]
        SE(dat, "BDA", **a)

add_dat(dtt, "AnalogueValue", [("f","FLOAT32")])
add_dat(dtt, "CMV1", [("cVal","Struct","Vector1"),("q","Quality"),("t","Timestamp")])
add_dat(dtt, "Vector1", [("mag","Struct","AnalogueValue"),("ang","Struct","AnalogueValue")])
add_dat(dtt, "SPCOperate", [("ctlVal","BOOLEAN"),("origin","Struct","Originator1"),
                             ("ctlNum","INT8U"),("T","Timestamp"),("Test","BOOLEAN"),("Check","Check")])
add_dat(dtt, "DPCOperate", [("ctlVal","BOOLEAN"),("origin","Struct","Originator1"),
                             ("ctlNum","INT8U"),("T","Timestamp"),("Test","BOOLEAN"),("Check","Check")])
add_dat(dtt, "Originator1", [("orCat","Enum","OrCat"),("orIdent","Octet64")])

# --- EnumTypes ---
def add_enum(dtt, eid, vals):
    et = SE(dtt, "EnumType", id=eid)
    for i, v in enumerate(vals):
        SE(et, "EnumVal", ord=str(i), text=v)

add_enum(dtt, "CtlModels", ["status-only","direct-with-normal-security",
    "sbo-with-normal-security","direct-with-enhanced-security","sbo-with-enhanced-security"])
add_enum(dtt, "BehaviourMode", ["on","blocked","test","test/blocked","off"])
add_enum(dtt, "HealthKind", ["ok","warning","alarm"])
add_enum(dtt, "FaultDirection", ["unknown","forward","backward","both"])
add_enum(dtt, "OrCat", ["not-supported","bay-control","station-control","remote-control",
    "automatic-bay","automatic-station","automatic-remote","maintenance","process"])

# ═══ Write output ═══
tree = ET.ElementTree(root)
raw = ET.tostring(root, encoding="unicode")
pretty = minidom.parseString(raw).toprettyxml(indent="  ", encoding=None)
# Remove extra xml declaration
lines = pretty.split("\n")
if lines[0].startswith("<?xml"):
    lines[0] = '<?xml version="1.0" encoding="UTF-8"?>'

out_path = r"c:\goose\iec61850-client\config\antam_pomalaa.cid"
with open(out_path, "w", encoding="utf-8") as f:
    f.write("\n".join(lines))

print(f"Generated CID file: {out_path}")
print(f"  Logical Devices: 25")
print(f"  LNodeTypes: {len(dtt.findall('LNodeType'))}")
print(f"  DOTypes:    {len(dtt.findall('DOType'))}")
print(f"  DATypes:    {len(dtt.findall('DAType'))}")
print(f"  EnumTypes:  {len(dtt.findall('EnumType'))}")
