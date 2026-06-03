/*
 * static_model.c
 *
 * automatically generated from C:\goose\sas_server\ieds\E06_BCU.cid
 */
#include "E06_BCU.h"

static void initializeValues();

extern DataSet model_E06_BCUds_E06BCU_LLN0_SwitchStatus;


extern DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda0;
extern DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda1;
extern DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda2;
extern DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda3;
extern DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda4;
extern DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda5;
extern DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda6;

DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda0 = {
  "E06BCU",
  false,
  "XCBR1$ST$Pos$stVal", 
  -1,
  NULL,
  NULL,
  &model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda1
};

DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda1 = {
  "E06BCU",
  false,
  "XCBR1$ST$Pos$q", 
  -1,
  NULL,
  NULL,
  &model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda2
};

DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda2 = {
  "E06BCU",
  false,
  "CSWI1$ST$Pos$stVal", 
  -1,
  NULL,
  NULL,
  &model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda3
};

DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda3 = {
  "E06BCU",
  false,
  "XSWI1$ST$Pos$stVal", 
  -1,
  NULL,
  NULL,
  &model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda4
};

DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda4 = {
  "E06BCU",
  false,
  "XSWI2$ST$Pos$stVal", 
  -1,
  NULL,
  NULL,
  &model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda5
};

DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda5 = {
  "E06BCU",
  false,
  "XSWI3$ST$Pos$stVal", 
  -1,
  NULL,
  NULL,
  &model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda6
};

DataSetEntry model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda6 = {
  "E06BCU",
  false,
  "XSWI4$ST$Pos$stVal", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet model_E06_BCUds_E06BCU_LLN0_SwitchStatus = {
  "E06BCU",
  "LLN0$SwitchStatus",
  7,
  &model_E06_BCUds_E06BCU_LLN0_SwitchStatus_fcda0,
  NULL
};

LogicalDevice model_E06_BCU_E06BCU = {
    LogicalDeviceModelType,
    "E06BCU",
    (ModelNode*) &model_E06_BCU,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0,
    NULL
};

LogicalNode model_E06_BCU_E06BCU_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod,
};

DataObject model_E06_BCU_E06BCU_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam,
};

DataObject model_E06_BCU_E06BCU_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyHealth,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam_hwRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyNam_hwRev = {
    DataAttributeModelType,
    "hwRev",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyNam_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam_serNum,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyNam_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyHealth,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyHealth,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy,
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_LPHD1_Proxy_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_XCBR1 = {
    LogicalNodeModelType,
    "XCBR1",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod,
};

DataObject model_E06_BCU_E06BCU_XCBR1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XCBR1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XCBR1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XCBR1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XCBR1_Pos = {
    DataObjectModelType,
    "Pos",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_CODEDENUM,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_d,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_Pos_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_Pos,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XCBR1_BlkOpn = {
    DataObjectModelType,
    "BlkOpn",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_d,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkOpn_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkOpn,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XCBR1_BlkCls = {
    DataObjectModelType,
    "BlkCls",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_CBOpCap,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_d,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_BlkCls_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_BlkCls,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XCBR1_CBOpCap = {
    DataObjectModelType,
    "CBOpCap",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_CBOpCap_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XCBR1_CBOpCap_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_CBOpCap,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_CBOpCap_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_CBOpCap_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_CBOpCap,
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_CBOpCap_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XCBR1_CBOpCap_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XCBR1_CBOpCap,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_CSWI1 = {
    LogicalNodeModelType,
    "CSWI1",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod,
};

DataObject model_E06_BCU_E06BCU_CSWI1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CSWI1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CSWI1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CSWI1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CSWI1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CSWI1_Pos = {
    DataObjectModelType,
    "Pos",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_CODEDENUM,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_d,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CSWI1_Pos_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_CSWI1_Pos,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_XSWI1 = {
    LogicalNodeModelType,
    "XSWI1",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod,
};

DataObject model_E06_BCU_E06BCU_XSWI1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI1_Pos = {
    DataObjectModelType,
    "Pos",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_CODEDENUM,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_d,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI1_Pos_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI1_Pos,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_XSWI2 = {
    LogicalNodeModelType,
    "XSWI2",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod,
};

DataObject model_E06_BCU_E06BCU_XSWI2_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI2_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI2_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI2_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI2_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI2_Pos = {
    DataObjectModelType,
    "Pos",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_CODEDENUM,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_d,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI2_Pos_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI2_Pos,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_XSWI3 = {
    LogicalNodeModelType,
    "XSWI3",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod,
};

DataObject model_E06_BCU_E06BCU_XSWI3_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI3_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI3_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI3_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI3_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI3_Pos = {
    DataObjectModelType,
    "Pos",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_CODEDENUM,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_d,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI3_Pos_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI3_Pos,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_XSWI4 = {
    LogicalNodeModelType,
    "XSWI4",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod,
};

DataObject model_E06_BCU_E06BCU_XSWI4_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI4_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI4_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI4_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI4_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_XSWI4_Pos = {
    DataObjectModelType,
    "Pos",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_CODEDENUM,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_d,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_XSWI4_Pos_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_XSWI4_Pos,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_CILO1 = {
    LogicalNodeModelType,
    "CILO1",
    (ModelNode*) &model_E06_BCU_E06BCU,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod,
};

DataObject model_E06_BCU_E06BCU_CILO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CILO1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CILO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CILO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CILO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CILO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CILO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CILO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CILO1_EnaCls = {
    DataObjectModelType,
    "EnaCls",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaCls_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaCls_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaCls_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaCls_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaCls,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_CILO1_EnaOpn = {
    DataObjectModelType,
    "EnaOpn",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaOpn_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaOpn_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaOpn_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn,
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_CILO1_EnaOpn_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_CILO1_EnaOpn,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_BCU_E06BCU_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &model_E06_BCU_E06BCU,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod,
};

DataObject model_E06_BCU_E06BCU_GGIO1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Beh,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Health,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_Ind1 = {
    DataObjectModelType,
    "Ind1",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind1_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_Ind2 = {
    DataObjectModelType,
    "Ind2",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind2_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_Ind3 = {
    DataObjectModelType,
    "Ind3",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind3_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind3_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind3_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind3_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind3,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_Ind4 = {
    DataObjectModelType,
    "Ind4",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind4_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind4_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind4_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_Ind4_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_Ind4,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_SPCSO1 = {
    DataObjectModelType,
    "SPCSO1",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_d,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO1_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO1,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_BCU_E06BCU_GGIO1_SPCSO2 = {
    DataObjectModelType,
    "SPCSO2",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1,
    NULL,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_stVal,
    0,
    -1
};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBO,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBO = {
    DataAttributeModelType,
    "SBO",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_VISIBLE_STRING_129,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw = {
    DataAttributeModelType,
    "SBOw",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_SBOw,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper = {
    DataAttributeModelType,
    "Oper",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Oper,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel = {
    DataAttributeModelType,
    "Cancel",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_d,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_ctlVal,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_ctlVal = {
    DataAttributeModelType,
    "ctlVal",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin = {
    DataAttributeModelType,
    "origin",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_ctlNum,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin_orCat,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin_orCat = {
    DataAttributeModelType,
    "orCat",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin_orIdent,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin_orIdent = {
    DataAttributeModelType,
    "orIdent",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_origin,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_OCTET_STRING_64,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_ctlNum = {
    DataAttributeModelType,
    "ctlNum",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_T,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_INT8U,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_T = {
    DataAttributeModelType,
    "T",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_Test,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_Test = {
    DataAttributeModelType,
    "Test",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel,
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_Check,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel_Check = {
    DataAttributeModelType,
    "Check",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2_Cancel,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CO,
    IEC61850_CHECK,
    0,
    NULL,
    0};

DataAttribute model_E06_BCU_E06BCU_GGIO1_SPCSO2_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_BCU_E06BCU_GGIO1_SPCSO2,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

extern ReportControlBlock model_E06_BCU_E06BCU_LLN0_report0;
extern ReportControlBlock model_E06_BCU_E06BCU_LLN0_report1;
extern ReportControlBlock model_E06_BCU_E06BCU_LLN0_report2;
extern ReportControlBlock model_E06_BCU_E06BCU_LLN0_report3;
extern ReportControlBlock model_E06_BCU_E06BCU_LLN0_report4;

ReportControlBlock model_E06_BCU_E06BCU_LLN0_report0 = {&model_E06_BCU_E06BCU_LLN0, "SwitchRCB01", "E06_BCU/E06BCU/LLN0.SwitchRCB", false, "SwitchStatus", 1, 27, 159, 50, 5000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E06_BCU_E06BCU_LLN0_report1};
ReportControlBlock model_E06_BCU_E06BCU_LLN0_report1 = {&model_E06_BCU_E06BCU_LLN0, "SwitchRCB02", "E06_BCU/E06BCU/LLN0.SwitchRCB", false, "SwitchStatus", 1, 27, 159, 50, 5000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E06_BCU_E06BCU_LLN0_report2};
ReportControlBlock model_E06_BCU_E06BCU_LLN0_report2 = {&model_E06_BCU_E06BCU_LLN0, "SwitchRCB03", "E06_BCU/E06BCU/LLN0.SwitchRCB", false, "SwitchStatus", 1, 27, 159, 50, 5000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E06_BCU_E06BCU_LLN0_report3};
ReportControlBlock model_E06_BCU_E06BCU_LLN0_report3 = {&model_E06_BCU_E06BCU_LLN0, "SwitchRCB04", "E06_BCU/E06BCU/LLN0.SwitchRCB", false, "SwitchStatus", 1, 27, 159, 50, 5000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E06_BCU_E06BCU_LLN0_report4};
ReportControlBlock model_E06_BCU_E06BCU_LLN0_report4 = {&model_E06_BCU_E06BCU_LLN0, "SwitchRCB05", "E06_BCU/E06BCU/LLN0.SwitchRCB", false, "SwitchStatus", 1, 27, 159, 50, 5000, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};


extern GSEControlBlock model_E06_BCU_E06BCU_LLN0_gse0;

static PhyComAddress model_E06_BCU_E06BCU_LLN0_gse0_address = {
  4,
  1,
  5649,
  {0x1, 0xc, 0xcd, 0x1, 0x6, 0x11}
};

GSEControlBlock model_E06_BCU_E06BCU_LLN0_gse0 = {&model_E06_BCU_E06BCU_LLN0, "gcbE06BCU", "E06BCU", "SwitchStatus", 1, false, &model_E06_BCU_E06BCU_LLN0_gse0_address, 4, 1000, NULL};





IedModel model_E06_BCU = {
    "E06_BCU",
    &model_E06_BCU_E06BCU,
    &model_E06_BCUds_E06BCU_LLN0_SwitchStatus,
    &model_E06_BCU_E06BCU_LLN0_report0,
    &model_E06_BCU_E06BCU_LLN0_gse0,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{

model_E06_BCU_E06BCU_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

model_E06_BCU_E06BCU_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("kVSAS_SIM");

model_E06_BCU_E06BCU_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("1.0.0");

model_E06_BCU_E06BCU_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("Line-2 Bay Control Unit (C264)");

model_E06_BCU_E06BCU_XCBR1_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_XCBR1_BlkOpn_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_XCBR1_BlkCls_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_CSWI1_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_XSWI1_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_XSWI2_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_XSWI3_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_XSWI4_Pos_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_GGIO1_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

model_E06_BCU_E06BCU_GGIO1_SPCSO1_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);

model_E06_BCU_E06BCU_GGIO1_SPCSO2_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(2);
}
