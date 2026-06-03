#!/usr/bin/env python3
"""Generate individual CID files per IED for GI 150kV A.

Each IED gets its own CID with:
  - Unique IED name and IP address
  - Only the LDs belonging to that physical device
  - GSE definitions for GOOSE pub/sub
  - Shared DataTypeTemplates (identical across all CIDs)
"""

import os, xml.etree.ElementTree as ET
from xml.dom import minidom

NS  = "http://www.iec.ch/61850/2003/SCL"
XSI = "http://www.w3.org/2001/XMLSchema-instance"
OUT_DIR = r"c:\goose\sas_server\ieds"

# ═══════════════════════════════════════════════════════════
#  XML helpers
# ═══════════════════════════════════════════════════════════
def E(tag, attrib=None, text=None, **kw):
    a = dict(attrib or {}); a.update(kw)
    e = ET.Element(tag, a)
    if text: e.text = str(text)
    return e

def SE(parent, tag, attrib=None, text=None, **kw):
    a = dict(attrib or {}); a.update(kw)
    e = ET.SubElement(parent, tag, a)
    if text: e.text = str(text)
    return e


# ═══════════════════════════════════════════════════════════
#  DataTypeTemplates (shared across all CIDs)
# ═══════════════════════════════════════════════════════════
def build_data_type_templates(root):
    dtt = SE(root, "DataTypeTemplates")

    def add_lnt(lid, lnc, dos):
        lnt = SE(dtt, "LNodeType", id=lid, lnClass=lnc)
        for dn, dt in dos:
            SE(lnt, "DO", name=dn, type=dt)

    def add_dot(did, cdc, das):
        dot = SE(dtt, "DOType", id=did, cdc=cdc)
        for dn, btype, fc, *extra in das:
            a = {"name": dn, "bType": btype, "fc": fc}
            if extra: a["type"] = extra[0]
            da = SE(dot, "DA", **a)
            if len(extra) > 1:
                SE(da, "Val", text=extra[1])

    def add_dat(did, bdas):
        dat = SE(dtt, "DAType", id=did)
        for bn, bt, *extra in bdas:
            a = {"name": bn, "bType": bt}
            if extra: a["type"] = extra[0]
            SE(dat, "BDA", **a)

    def add_enum(eid, vals):
        et = SE(dtt, "EnumType", id=eid)
        for i, v in enumerate(vals):
            SE(et, "EnumVal", ord=str(i), text=v)

    # LNodeTypes
    add_lnt("LLN0_BCU","LLN0",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1")])
    add_lnt("LLN0_PROT","LLN0",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1")])
    add_lnt("LLN0_MEAS","LLN0",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1")])
    add_lnt("LPHD1","LPHD",[("PhyNam","DPL1"),("PhyHealth","INS1"),("Proxy","SPS1")])
    add_lnt("XCBR1","XCBR",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Pos","DPC1"),("BlkOpn","SPC1"),("BlkCls","SPC1"),("CBOpCap","INS1")])
    add_lnt("CSWI1","CSWI",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),("Pos","DPC1")])
    add_lnt("XSWI1","XSWI",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),("Pos","DPC1")])
    add_lnt("CILO1","CILO",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("EnaCls","SPS1"),("EnaOpn","SPS1")])
    add_lnt("GGIO_BCU","GGIO",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Ind1","SPS1"),("Ind2","SPS1"),("Ind3","SPS1"),("Ind4","SPS1"),
        ("SPCSO1","SPC1"),("SPCSO2","SPC1")])
    add_lnt("PTOC1","PTOC",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Op","ACT1"),("Str","ACD1")])
    add_lnt("PDIS1","PDIS",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Op","ACT1"),("Str","ACD1")])
    add_lnt("PDIF1","PDIF",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Op","ACT1"),("Str","ACD1")])
    add_lnt("PDIF_BB","PDIF",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Op","ACT1")])
    add_lnt("PTRC1","PTRC",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Tr","ACT1")])
    add_lnt("RREC1","RREC",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("Op","ACT1"),("AutoRecSt","INS1")])
    add_lnt("RSYN1","RSYN",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("RsSyn","SPS1")])
    add_lnt("RBRF1","RBRF",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("OpEx","ACT1"),("FailMod","INS1")])
    add_lnt("MMXU1","MMXU",[("Mod","INC1"),("Beh","INS1"),("Health","INS1"),("NamPlt","LPL1"),
        ("TotW","MV1"),("TotVAr","MV1"),("TotVA","MV1"),("Hz","MV1"),
        ("PhV","WYE1"),("A","WYE1")])

    # DOTypes
    add_dot("INC1","INC",[("stVal","INT32","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
        ("ctlModel","Enum","CF","CtlModels")])
    add_dot("INS1","INS",[("stVal","INT32","ST"),("q","Quality","ST"),("t","Timestamp","ST")])
    add_dot("SPS1","SPS",[("stVal","BOOLEAN","ST"),("q","Quality","ST"),("t","Timestamp","ST"),("d","VisString255","DC")])
    add_dot("SPC1","SPC",[("stVal","BOOLEAN","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
        ("ctlModel","Enum","CF","CtlModels","sbo-with-normal-security"),("SBO","VisString129","CO"),("SBOw","Struct","CO","SPCOperate"),("Oper","Struct","CO","SPCOperate"),("Cancel","Struct","CO","SPCOperate"),("d","VisString255","DC")])
    add_dot("DPC1","DPC",[("stVal","Dbpos","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
        ("ctlModel","Enum","CF","CtlModels","sbo-with-normal-security"),("SBO","VisString129","CO"),("SBOw","Struct","CO","DPCOperate"),("Oper","Struct","CO","DPCOperate"),("Cancel","Struct","CO","DPCOperate"),("d","VisString255","DC")])
    add_dot("MV1","MV",[("mag","Struct","MX","AnalogueValue"),("q","Quality","MX"),("t","Timestamp","MX"),
        ("d","VisString255","DC")])
    add_dot("WYE1","WYE",[("phsA","Struct","MX","CMV1"),("phsB","Struct","MX","CMV1"),("phsC","Struct","MX","CMV1"),
        ("d","VisString255","DC")])
    add_dot("ACT1","ACT",[("general","BOOLEAN","ST"),("q","Quality","ST"),("t","Timestamp","ST"),
        ("d","VisString255","DC")])
    add_dot("ACD1","ACD",[("general","BOOLEAN","ST"),("dirGeneral","Enum","ST","FaultDirection"),
        ("q","Quality","ST"),("t","Timestamp","ST"),("d","VisString255","DC")])
    add_dot("LPL1","LPL",[("vendor","VisString255","DC"),("swRev","VisString255","DC"),
        ("d","VisString255","DC"),("configRev","VisString255","DC"),("ldNs","VisString255","EX")])
    add_dot("DPL1","DPL",[("vendor","VisString255","DC"),("hwRev","VisString255","DC"),
        ("swRev","VisString255","DC"),("serNum","VisString255","DC"),("model","VisString255","DC")])

    # DATypes
    add_dat("AnalogueValue",[("f","FLOAT32")])
    add_dat("CMV1",[("cVal","Struct","Vector1"),("q","Quality"),("t","Timestamp")])
    add_dat("Vector1",[("mag","Struct","AnalogueValue"),("ang","Struct","AnalogueValue")])
    add_dat("SPCOperate",[("ctlVal","BOOLEAN"),("origin","Struct","Originator1"),
        ("ctlNum","INT8U"),("T","Timestamp"),("Test","BOOLEAN"),("Check","Check")])
    add_dat("DPCOperate",[("ctlVal","BOOLEAN"),("origin","Struct","Originator1"),
        ("ctlNum","INT8U"),("T","Timestamp"),("Test","BOOLEAN"),("Check","Check")])
    add_dat("Originator1",[("orCat","Enum","OrCat"),("orIdent","Octet64")])

    # EnumTypes
    add_enum("CtlModels",["status-only","direct-with-normal-security",
        "sbo-with-normal-security","direct-with-enhanced-security","sbo-with-enhanced-security"])
    add_enum("BehaviourMode",["on","blocked","test","test/blocked","off"])
    add_enum("HealthKind",["ok","warning","alarm"])
    add_enum("FaultDirection",["unknown","forward","backward","both"])
    add_enum("OrCat",["not-supported","bay-control","station-control","remote-control",
        "automatic-bay","automatic-station","automatic-remote","maintenance","process"])

    return dtt


# ═══════════════════════════════════════════════════════════
#  LD builder functions (same logic as monolithic generator)
# ═══════════════════════════════════════════════════════════
def add_ln0_dois(ln0, desc_text):
    doi = SE(ln0, "DOI", name="Mod")
    SE(SE(doi, "DAI", name="ctlModel"), "Val", text="status-only")
    doi2 = SE(ln0, "DOI", name="NamPlt")
    SE(SE(doi2, "DAI", name="vendor"), "Val", text="ANTAM_SIM")
    SE(SE(doi2, "DAI", name="swRev"), "Val", text="1.0.0")
    SE(SE(doi2, "DAI", name="d"), "Val", text=desc_text)

def add_bcu_ld(srv, ied_name, ldi, desc, goose_defs, has_line_dis=True, has_earth_sw=True):
    """BCU LD: XCBR, CSWI, XSWI, CILO, GGIO."""
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_BCU", inst="")
    ds = SE(ln0, "DataSet", name="SwitchStatus")
    SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="XCBR", fc="ST", lnInst="1", doName="Pos", daName="stVal")
    SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="XCBR", fc="ST", lnInst="1", doName="Pos", daName="q")
    SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="CSWI", fc="ST", lnInst="1", doName="Pos", daName="stVal")
    SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="XSWI", fc="ST", lnInst="1", doName="Pos", daName="stVal")
    SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="XSWI", fc="ST", lnInst="2", doName="Pos", daName="stVal")
    if has_line_dis:
        SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="XSWI", fc="ST", lnInst="3", doName="Pos", daName="stVal")
    if has_earth_sw:
        SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="XSWI", fc="ST", lnInst="4", doName="Pos", daName="stVal")
    if not has_line_dis and not has_earth_sw:
        # For the coupler, we publish CouplerReady status as GGIO.Ind1
        SE(ds, "FCDA", ldInst=ldi, prefix="", lnClass="GGIO", fc="ST", lnInst="1", doName="Ind1", daName="stVal")
    rcb = SE(ln0, "ReportControl", name="SwitchRCB", confRev="1", datSet="SwitchStatus",
             rptID=f"{ied_name}/{ldi}/LLN0.SwitchRCB", buffered="false", intgPd="5000", bufTime="50")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="true", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="false", configRef="true", bufOvfl="false")
    SE(rcb, "RptEnabled", max="5")
    gcb_name = f"gcb{ldi}"
    SE(ln0, "GSEControl", appID=ldi, name=gcb_name, type="GOOSE", datSet="SwitchStatus", confRev="1")
    goose_defs.append((ldi, gcb_name))
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    xcbr = SE(ld, "LN", lnClass="XCBR", lnType="XCBR1", inst="1", prefix="")
    cswi = SE(ld, "LN", lnClass="CSWI", lnType="CSWI1", inst="1", prefix="")
    # DS-A (XSWI1)
    xswi1 = SE(ld, "LN", lnClass="XSWI", lnType="XSWI1", inst="1", prefix="")
    # DS-B (XSWI2): self-closing, NO DOI — genmodel.jar skips secondary instances with DOI overrides
    SE(ld, "LN", lnClass="XSWI", lnType="XSWI1", inst="2", prefix="")
    if has_line_dis:
        # Line DS (XSWI3)
        SE(ld, "LN", lnClass="XSWI", lnType="XSWI1", inst="3", prefix="")
    if has_earth_sw:
        # Earth Switch (XSWI4)
        SE(ld, "LN", lnClass="XSWI", lnType="XSWI1", inst="4", prefix="")
    SE(ld, "LN", lnClass="CILO", lnType="CILO1", inst="1", prefix="")
    ggio = SE(ld, "LN", lnClass="GGIO", lnType="GGIO_BCU", inst="1", prefix="")
    SE(SE(SE(ggio, "DOI", name="Mod"), "DAI", name="ctlModel"), "Val", text="status-only")

def add_ptoc_ld(srv, ied_name, ldi, desc, goose_defs):
    """Overcurrent protection LD."""
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="TripData")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="q")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTOC", fc="ST", lnInst="1", doName="Op", daName="general")
    rcb = SE(ln0, "ReportControl", name="TripBRCB", confRev="1", datSet="TripData",
             rptID=f"{ied_name}/{ldi}/LLN0.TripBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    gcbn = "gcbTrip"
    SE(ln0, "GSEControl", appID=ldi, name=gcbn, type="GOOSE", datSet="TripData", confRev="1")
    goose_defs.append((ldi, gcbn))
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    for i in range(1, 5):
        SE(ld, "LN", lnClass="PTOC", lnType="PTOC1", inst=str(i), prefix="")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")

def add_pdif_ld(srv, ied_name, ldi, desc, goose_defs):
    """Transformer differential LD."""
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="DiffTrip")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PDIF", fc="ST", lnInst="1", doName="Op", daName="general")
    rcb = SE(ln0, "ReportControl", name="DiffBRCB", confRev="1", datSet="DiffTrip",
             rptID=f"{ied_name}/{ldi}/LLN0.DiffBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    gcbn = "gcbTrip"
    SE(ln0, "GSEControl", appID=ldi, name=gcbn, type="GOOSE", datSet="DiffTrip", confRev="1")
    goose_defs.append((ldi, gcbn))
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    SE(ld, "LN", lnClass="PDIF", lnType="PDIF1", inst="1", prefix="")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")
    SE(ld, "LN", lnClass="MMXU", lnType="MMXU1", inst="1", prefix="")

def add_pdis_ld(srv, ied_name, ldi, desc, goose_defs):
    """Distance protection LD (P543)."""
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="DistTrip")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PTRC", fc="ST", lnInst="1", doName="Tr", daName="general")
    for z in range(1, 5):
        SE(ds, "FCDA", ldInst=ldi, lnClass="PDIS", fc="ST", lnInst=str(z), doName="Op", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="RREC", fc="ST", lnInst="1", doName="Op", daName="general")
    rcb = SE(ln0, "ReportControl", name="DistBRCB", confRev="1", datSet="DistTrip",
             rptID=f"{ied_name}/{ldi}/LLN0.DistBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    gcbn = "gcbTrip"
    SE(ln0, "GSEControl", appID=ldi, name=gcbn, type="GOOSE", datSet="DistTrip", confRev="1")
    goose_defs.append((ldi, gcbn))
    add_ln0_dois(ln0, desc)
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    for z in range(1, 5):
        ln = SE(ld, "LN", lnClass="PDIS", lnType="PDIS1", inst=str(z), prefix="")
        SE(SE(SE(ln, "DOI", name="Op"), "DAI", name="d"), "Val", text=f"Zone {z} Distance Protection")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")
    SE(ld, "LN", lnClass="RREC", lnType="RREC1", inst="1", prefix="")
    SE(ld, "LN", lnClass="RSYN", lnType="RSYN1", inst="1", prefix="")
    SE(ld, "LN", lnClass="MMXU", lnType="MMXU1", inst="1", prefix="")

def add_bbprot_ld(srv, ied_name, ldi, desc, zone_name, goose_defs):
    """Busbar protection LD (P746)."""
    ld = SE(srv, "LDevice", inst=ldi, desc=desc)
    ln0 = SE(ld, "LN0", lnClass="LLN0", lnType="LLN0_PROT", inst="")
    ds = SE(ln0, "DataSet", name="BBTrip")
    SE(ds, "FCDA", ldInst=ldi, lnClass="PDIF", fc="ST", lnInst="1", doName="Op", daName="general")
    SE(ds, "FCDA", ldInst=ldi, lnClass="RBRF", fc="ST", lnInst="1", doName="OpEx", daName="general")
    rcb = SE(ln0, "ReportControl", name="BBRCB", confRev="1", datSet="BBTrip",
             rptID=f"{ied_name}/{ldi}/LLN0.BBRCB", buffered="true", intgPd="0", bufTime="0")
    SE(rcb, "TrgOps", dchg="true", qchg="true", dupd="false", period="false", gi="true")
    SE(rcb, "OptFields", seqNum="true", timeStamp="true", dataSet="true", reasonCode="true",
       dataRef="true", entryID="true", configRef="true", bufOvfl="true")
    SE(rcb, "RptEnabled", max="2")
    gcbn = f"gcb{ldi}"
    SE(ln0, "GSEControl", appID=ldi, name=gcbn, type="GOOSE", datSet="BBTrip", confRev="1")
    goose_defs.append((ldi, gcbn))
    add_ln0_dois(ln0, f"Busbar Protection {zone_name}")
    SE(ld, "LN", lnClass="LPHD", lnType="LPHD1", inst="1", prefix="")
    pdif = SE(ld, "LN", lnClass="PDIF", lnType="PDIF_BB", inst="1", prefix="")
    SE(SE(SE(pdif, "DOI", name="Op"), "DAI", name="d"), "Val", text=f"87B {zone_name}")
    SE(ld, "LN", lnClass="RBRF", lnType="RBRF1", inst="1", prefix="")
    SE(ld, "LN", lnClass="PTRC", lnType="PTRC1", inst="1", prefix="")


# ═══════════════════════════════════════════════════════════
#  IED definitions table
# ═══════════════════════════════════════════════════════════
# Each entry: (ied_name, ip, port, bay_desc, ld_builder_func)
# ld_builder_func(srv, ied_name, goose_defs) -> adds LDs to the server element

def build_bcu(srv, ied_name, goose_defs, bay_id, desc, has_line_dis=True, has_earth_sw=True):
    add_bcu_ld(srv, ied_name, f"{bay_id}BCU", f"{desc} Bay Control Unit (C264)", goose_defs, has_line_dis, has_earth_sw)

def build_p643(srv, ied_name, goose_defs, bay_id, desc):
    add_pdif_ld(srv, ied_name, f"{bay_id}P643", f"{desc} Differential Protection (P643)", goose_defs)

def build_p142hv(srv, ied_name, goose_defs, bay_id, desc):
    add_ptoc_ld(srv, ied_name, f"{bay_id}P142HV", f"{desc} HV Overcurrent (P142)", goose_defs)

def build_p142(srv, ied_name, goose_defs, bay_id, desc):
    add_ptoc_ld(srv, ied_name, f"{bay_id}P142", f"{desc} Backup Overcurrent (P142)", goose_defs)

def build_p143(srv, ied_name, goose_defs, bay_id, desc):
    add_ptoc_ld(srv, ied_name, f"{bay_id}P143", f"{desc} Overcurrent Protection (P143)", goose_defs)

def build_p543(srv, ied_name, goose_defs, bay_id, desc):
    add_pdis_ld(srv, ied_name, f"{bay_id}P543", f"{desc} Distance + Auto-Reclose (P543)", goose_defs)

def build_p746(srv, ied_name, goose_defs, bay_id, desc):
    add_bbprot_ld(srv, ied_name, "E00P746Z1", "Busbar Protection Zone 1 (P746)", "Zone 1", goose_defs)
    add_bbprot_ld(srv, ied_name, "E00P746Z2", "Busbar Protection Zone 2 (P746)", "Zone 2", goose_defs)
    add_bbprot_ld(srv, ied_name, "E00P746CZ", "Busbar Protection Check Zone (P746)", "Check Zone", goose_defs)


IED_TABLE = [
    # Transformer bays E01-E03 (Has Line DS, No Earth Switch)
    ("E01_BCU",   "10.0.1.1", 102, "E01", "Transformer-1", lambda s,n,g,b,d: build_bcu(s,n,g,b,d,True,False)),
    ("E01_P643",  "10.0.1.2", 102, "E01", "Transformer-1", build_p643),
    ("E01_P142",  "10.0.1.3", 102, "E01", "Transformer-1", build_p142hv),
    ("E02_BCU",   "10.0.2.1", 102, "E02", "Transformer-2", lambda s,n,g,b,d: build_bcu(s,n,g,b,d,True,False)),
    ("E02_P643",  "10.0.2.2", 102, "E02", "Transformer-2", build_p643),
    ("E02_P142",  "10.0.2.3", 102, "E02", "Transformer-2", build_p142hv),
    ("E03_BCU",   "10.0.3.1", 102, "E03", "Transformer-3", lambda s,n,g,b,d: build_bcu(s,n,g,b,d,True,False)),
    ("E03_P643",  "10.0.3.2", 102, "E03", "Transformer-3", build_p643),
    ("E03_P142",  "10.0.3.3", 102, "E03", "Transformer-3", build_p142hv),
    # Coupler bay E04 (No Line DS, No Earth Switch)
    ("E04_BCU",   "10.0.4.1", 102, "E04", "Coupler", lambda s,n,g,b,d: build_bcu(s,n,g,b,d,False,False)),
    ("E04_P143",  "10.0.4.2", 102, "E04", "Coupler", build_p143),
    # Line bays E05-E06
    ("E05_BCU",   "10.0.5.1", 102, "E05", "Line-1", build_bcu),
    ("E05_P543",  "10.0.5.2", 102, "E05", "Line-1", build_p543),
    ("E05_P142",  "10.0.5.3", 102, "E05", "Line-1", build_p142),
    ("E06_BCU",   "10.0.6.1", 102, "E06", "Line-2", build_bcu),
    ("E06_P543",  "10.0.6.2", 102, "E06", "Line-2", build_p543),
    ("E06_P142",  "10.0.6.3", 102, "E06", "Line-2", build_p142),
    # Busbar protection E00
    ("E00_P746",  "10.0.0.1", 102, "E00", "Busbar", build_p746),
]


# ═══════════════════════════════════════════════════════════
#  Build one CID file per IED
# ═══════════════════════════════════════════════════════════
def build_ied_cid(ied_name, ip, port, bay_id, bay_desc, ld_builder):
    root = E("SCL", {"xmlns": NS, "xmlns:xsi": XSI})

    # Header
    hdr = SE(root, "Header", id=f"CID_{ied_name}", version="1", revision="0",
             toolID="SAS_Generator", nameStructure="IEDName")
    SE(hdr, "Text", text=f"GI 150kV A — {ied_name}")

    # Communication
    comm = SE(root, "Communication")
    sn = SE(comm, "SubNetwork", name="StationBus", type="8-MMS", desc="Station Bus")
    SE(sn, "BitRate", {"unit": "b/s", "multiplier": "M"}, text="100")
    cap = SE(sn, "ConnectedAP", iedName=ied_name, apName="AP1")
    addr = SE(cap, "Address")
    for pt, pv in [("IP", ip), ("IP-SUBNET", "255.255.255.0"), ("IP-GATEWAY", "10.0.0.254"),
                   ("OSI-TSEL", "0001"), ("OSI-PSEL", "00000001"), ("OSI-SSEL", "0001")]:
        SE(addr, "P", type=pt, text=pv)

    # IED
    ied = SE(root, "IED", name=ied_name, desc=f"{bay_desc} {ied_name}",
             type="SAS_Simulator", manufacturer="ANTAM_SIM", configVersion="1.0")
    svc = SE(ied, "Services")
    for s in ["DynAssociation","GetDirectory","GetDataObjectDefinition","GetDataSetValue",
              "SetDataSetValue","DataSetDirectory","ReadWrite","GetCBValues"]:
        SE(svc, s)
    SE(svc, "GOOSE", max="10")
    SE(svc, "ConfReportControl")
    SE(svc, "FileHandling")

    ap = SE(ied, "AccessPoint", name="AP1", desc="Primary Access Point")
    srv = SE(ap, "Server", timeout="30")
    SE(srv, "Authentication", none="true")

    # Build LDs
    goose_defs = []
    ld_builder(srv, ied_name, goose_defs, bay_id, bay_desc)

    # Add GSE entries to ConnectedAP
    mac_counter = 1
    ip_parts = ip.split('.')
    c_octet = int(ip_parts[2])
    d_octet = int(ip_parts[3])
    
    for ldi, gcbn in goose_defs:
        gse = SE(cap, "GSE", ldInst=ldi, cbName=gcbn)
        ga = SE(gse, "Address")
        SE(ga, "P", type="VLAN-ID", text="1")
        SE(ga, "P", type="VLAN-PRIORITY", text="4")
        mac_last = (d_octet << 4) + mac_counter
        SE(ga, "P", type="MAC-Address", text=f"01-0C-CD-01-{c_octet:02X}-{mac_last:02X}")
        appid = 0x1000 + (c_octet << 8) + (d_octet << 4) + mac_counter
        SE(ga, "P", type="APPID", text=f"{appid:04X}")
        SE(gse, "MinTime", {"unit": "ms"}, text="4")
        SE(gse, "MaxTime", {"unit": "ms"}, text="1000")
        mac_counter += 1

    # DataTypeTemplates
    build_data_type_templates(root)

    return root


# ═══════════════════════════════════════════════════════════
#  Main: generate all CIDs
# ═══════════════════════════════════════════════════════════
def write_cid(root, filepath):
    raw = ET.tostring(root, encoding="unicode")
    pretty = minidom.parseString(raw).toprettyxml(indent="  ", encoding=None)
    lines = pretty.split("\n")
    if lines[0].startswith("<?xml"):
        lines[0] = '<?xml version="1.0" encoding="UTF-8"?>'
    with open(filepath, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))

def main():
    os.makedirs(OUT_DIR, exist_ok=True)
    print(f"Generating per-IED CID files in {OUT_DIR}")
    print(f"{'IED Name':<16} {'IP':<14} {'File'}")
    print("-" * 60)

    for ied_name, ip, port, bay_id, bay_desc, builder in IED_TABLE:
        root = build_ied_cid(ied_name, ip, port, bay_id, bay_desc, builder)
        filename = f"{ied_name}.cid"
        filepath = os.path.join(OUT_DIR, filename)
        write_cid(root, filepath)
        n_lds = sum(1 for _ in root.iter("LDevice"))
        print(f"  {ied_name:<14} {ip:<14} {filename} ({n_lds} LDs)")

    # Also regenerate the monolithic CID for backward compatibility
    print(f"\n{'='*60}")
    print(f"Generated {len(IED_TABLE)} CID files in {OUT_DIR}/")

if __name__ == "__main__":
    main()
