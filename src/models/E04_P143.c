/*
 * static_model.c
 *
 * automatically generated from C:\goose\sas_server\ieds\E04_P143.cid
 */
#include "E04_P143.h"

static void initializeValues();

extern DataSet model_E04_P143ds_E04P143_LLN0_TripData;


extern DataSetEntry model_E04_P143ds_E04P143_LLN0_TripData_fcda0;
extern DataSetEntry model_E04_P143ds_E04P143_LLN0_TripData_fcda1;
extern DataSetEntry model_E04_P143ds_E04P143_LLN0_TripData_fcda2;

DataSetEntry model_E04_P143ds_E04P143_LLN0_TripData_fcda0 = {
  "E04P143",
  false,
  "PTRC1$ST$Tr$general", 
  -1,
  NULL,
  NULL,
  &model_E04_P143ds_E04P143_LLN0_TripData_fcda1
};

DataSetEntry model_E04_P143ds_E04P143_LLN0_TripData_fcda1 = {
  "E04P143",
  false,
  "PTRC1$ST$Tr$q", 
  -1,
  NULL,
  NULL,
  &model_E04_P143ds_E04P143_LLN0_TripData_fcda2
};

DataSetEntry model_E04_P143ds_E04P143_LLN0_TripData_fcda2 = {
  "E04P143",
  false,
  "PTOC1$ST$Op$general", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet model_E04_P143ds_E04P143_LLN0_TripData = {
  "E04P143",
  "LLN0$TripData",
  3,
  &model_E04_P143ds_E04P143_LLN0_TripData_fcda0,
  NULL
};

LogicalDevice model_E04_P143_E04P143 = {
    LogicalDeviceModelType,
    "E04P143",
    (ModelNode*) &model_E04_P143,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_LLN0,
    NULL
};

LogicalNode model_E04_P143_E04P143_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &model_E04_P143_E04P143,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod,
};

DataObject model_E04_P143_E04P143_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E04_P143_E04P143_LLN0,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Beh,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E04_P143_E04P143_LLN0,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Health,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Beh,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Beh,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E04_P143_E04P143_LLN0,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Health,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Health,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E04_P143_E04P143_LLN0,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E04_P143_E04P143_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E04_P143_E04P143_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &model_E04_P143_E04P143,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam,
};

DataObject model_E04_P143_E04P143_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyHealth,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam_hwRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyNam_hwRev = {
    DataAttributeModelType,
    "hwRev",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyNam_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam_serNum,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyNam_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyHealth,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyHealth,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy,
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_LPHD1_Proxy_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E04_P143_E04P143_PTOC1 = {
    LogicalNodeModelType,
    "PTOC1",
    (ModelNode*) &model_E04_P143_E04P143,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod,
};

DataObject model_E04_P143_E04P143_PTOC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Health_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC1_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC1_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC1_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC1_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC1_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC1_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E04_P143_E04P143_PTOC2 = {
    LogicalNodeModelType,
    "PTOC2",
    (ModelNode*) &model_E04_P143_E04P143,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod,
};

DataObject model_E04_P143_E04P143_PTOC2_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC2_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC2_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Beh_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC2_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC2_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Health_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC2_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC2_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC2_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC2_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC2_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC2_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC2_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC2_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC2_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E04_P143_E04P143_PTOC3 = {
    LogicalNodeModelType,
    "PTOC3",
    (ModelNode*) &model_E04_P143_E04P143,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod,
};

DataObject model_E04_P143_E04P143_PTOC3_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC3_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC3_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Beh_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC3_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC3_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Health_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC3_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC3_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC3_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC3_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC3_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC3_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC3_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC3_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC3_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E04_P143_E04P143_PTOC4 = {
    LogicalNodeModelType,
    "PTOC4",
    (ModelNode*) &model_E04_P143_E04P143,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod,
};

DataObject model_E04_P143_E04P143_PTOC4_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC4_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC4_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Beh_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC4_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC4_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Health_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC4_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC4_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC4_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC4_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC4_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTOC4_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTOC4_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str,
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTOC4_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTOC4_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E04_P143_E04P143_PTRC1 = {
    LogicalNodeModelType,
    "PTRC1",
    (ModelNode*) &model_E04_P143_E04P143,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod,
};

DataObject model_E04_P143_E04P143_PTRC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTRC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTRC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTRC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Beh,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTRC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Health_stVal,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTRC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Health,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTRC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTRC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E04_P143_E04P143_PTRC1_Tr = {
    DataObjectModelType,
    "Tr",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1,
    NULL,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr_general,
    0,
    -1
};

DataAttribute model_E04_P143_E04P143_PTRC1_Tr_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Tr_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Tr_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr,
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E04_P143_E04P143_PTRC1_Tr_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E04_P143_E04P143_PTRC1_Tr,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

extern ReportControlBlock model_E04_P143_E04P143_LLN0_report0;
extern ReportControlBlock model_E04_P143_E04P143_LLN0_report1;

ReportControlBlock model_E04_P143_E04P143_LLN0_report0 = {&model_E04_P143_E04P143_LLN0, "TripBRCB01", "E04_P143/E04P143/LLN0.TripBRCB", true, "TripData", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E04_P143_E04P143_LLN0_report1};
ReportControlBlock model_E04_P143_E04P143_LLN0_report1 = {&model_E04_P143_E04P143_LLN0, "TripBRCB02", "E04_P143/E04P143/LLN0.TripBRCB", true, "TripData", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};


extern GSEControlBlock model_E04_P143_E04P143_LLN0_gse0;

static PhyComAddress model_E04_P143_E04P143_LLN0_gse0_address = {
  4,
  1,
  5153,
  {0x1, 0xc, 0xcd, 0x1, 0x4, 0x21}
};

GSEControlBlock model_E04_P143_E04P143_LLN0_gse0 = {&model_E04_P143_E04P143_LLN0, "gcbTrip", "E04P143", "TripData", 1, false, &model_E04_P143_E04P143_LLN0_gse0_address, 4, 1000, NULL};





IedModel model_E04_P143 = {
    "E04_P143",
    &model_E04_P143_E04P143,
    &model_E04_P143ds_E04P143_LLN0_TripData,
    &model_E04_P143_E04P143_LLN0_report0,
    &model_E04_P143_E04P143_LLN0_gse0,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{

model_E04_P143_E04P143_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

model_E04_P143_E04P143_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("kVSAS_SIM");

model_E04_P143_E04P143_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("1.0.0");

model_E04_P143_E04P143_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("Coupler Overcurrent Protection (P143)");
}
