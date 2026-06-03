/*
 * E06_P543.c
 *
 * automatically generated from E06_P543.cid
 */
#include "E06_P543.h"

static void initializeValues();

extern DataSet model_E06_P543ds_E06P543_LLN0_DistTrip;


extern DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda0;
extern DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda1;
extern DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda2;
extern DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda3;
extern DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda4;
extern DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda5;

DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda0 = {
  "E06P543",
  false,
  "PTRC1$ST$Tr$general", 
  -1,
  NULL,
  NULL,
  &model_E06_P543ds_E06P543_LLN0_DistTrip_fcda1
};

DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda1 = {
  "E06P543",
  false,
  "PDIS1$ST$Op$general", 
  -1,
  NULL,
  NULL,
  &model_E06_P543ds_E06P543_LLN0_DistTrip_fcda2
};

DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda2 = {
  "E06P543",
  false,
  "PDIS2$ST$Op$general", 
  -1,
  NULL,
  NULL,
  &model_E06_P543ds_E06P543_LLN0_DistTrip_fcda3
};

DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda3 = {
  "E06P543",
  false,
  "PDIS3$ST$Op$general", 
  -1,
  NULL,
  NULL,
  &model_E06_P543ds_E06P543_LLN0_DistTrip_fcda4
};

DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda4 = {
  "E06P543",
  false,
  "PDIS4$ST$Op$general", 
  -1,
  NULL,
  NULL,
  &model_E06_P543ds_E06P543_LLN0_DistTrip_fcda5
};

DataSetEntry model_E06_P543ds_E06P543_LLN0_DistTrip_fcda5 = {
  "E06P543",
  false,
  "RREC1$ST$Op$general", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet model_E06_P543ds_E06P543_LLN0_DistTrip = {
  "E06P543",
  "LLN0$DistTrip",
  6,
  &model_E06_P543ds_E06P543_LLN0_DistTrip_fcda0,
  NULL
};

LogicalDevice model_E06_P543_E06P543 = {
    LogicalDeviceModelType,
    "E06P543",
    (ModelNode*) &model_E06_P543,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_LLN0,
    NULL
};

LogicalNode model_E06_P543_E06P543_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod,
};

DataObject model_E06_P543_E06P543_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_LLN0,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Beh,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_LLN0,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Health,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Beh,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Beh,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_LLN0,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Health,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Health,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_LLN0,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam,
};

DataObject model_E06_P543_E06P543_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyHealth,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam_hwRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyNam_hwRev = {
    DataAttributeModelType,
    "hwRev",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyNam_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam_serNum,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyNam_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyHealth,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyHealth,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy,
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_LPHD1_Proxy_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_PDIS1 = {
    LogicalNodeModelType,
    "PDIS1",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod,
};

DataObject model_E06_P543_E06P543_PDIS1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS1_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS1_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS1_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS1_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS1_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS1_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_PDIS2 = {
    LogicalNodeModelType,
    "PDIS2",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod,
};

DataObject model_E06_P543_E06P543_PDIS2_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS2_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS2_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS2_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS2_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS2_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS2_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS2_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS2_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS2_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS2_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS2_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS2_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS2_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_PDIS3 = {
    LogicalNodeModelType,
    "PDIS3",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod,
};

DataObject model_E06_P543_E06P543_PDIS3_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS3_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS3_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS3_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS3_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS3_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS3_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS3_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS3_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS3_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS3_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS3_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS3_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS3_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_PDIS4 = {
    LogicalNodeModelType,
    "PDIS4",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod,
};

DataObject model_E06_P543_E06P543_PDIS4_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS4_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS4_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS4_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS4_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS4_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Health,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS4_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS4_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS4_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS4_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PDIS4_Str = {
    DataObjectModelType,
    "Str",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PDIS4_Str_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str_dirGeneral,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Str_dirGeneral = {
    DataAttributeModelType,
    "dirGeneral",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Str_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Str_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str,
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PDIS4_Str_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PDIS4_Str,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_PTRC1 = {
    LogicalNodeModelType,
    "PTRC1",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_RREC1,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod,
};

DataObject model_E06_P543_E06P543_PTRC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PTRC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PTRC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Health,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PTRC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PTRC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PTRC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Health,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Health,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PTRC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PTRC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_PTRC1_Tr = {
    DataObjectModelType,
    "Tr",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_PTRC1_Tr_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Tr_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Tr_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr,
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_PTRC1_Tr_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_PTRC1_Tr,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_RREC1 = {
    LogicalNodeModelType,
    "RREC1",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod,
};

DataObject model_E06_P543_E06P543_RREC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_RREC1,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RREC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RREC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_RREC1,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Health,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RREC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RREC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_RREC1,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RREC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Health,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Health,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RREC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_RREC1,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RREC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RREC1_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E06_P543_E06P543_RREC1,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_AutoRecSt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op_general,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RREC1_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RREC1_AutoRecSt = {
    DataObjectModelType,
    "AutoRecSt",
    (ModelNode*) &model_E06_P543_E06P543_RREC1,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_AutoRecSt_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RREC1_AutoRecSt_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_AutoRecSt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_AutoRecSt_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_AutoRecSt_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_AutoRecSt,
    (ModelNode*) &model_E06_P543_E06P543_RREC1_AutoRecSt_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RREC1_AutoRecSt_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RREC1_AutoRecSt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_RSYN1 = {
    LogicalNodeModelType,
    "RSYN1",
    (ModelNode*) &model_E06_P543_E06P543,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod,
};

DataObject model_E06_P543_E06P543_RSYN1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RSYN1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RSYN1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Health,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RSYN1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RSYN1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RSYN1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Health,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Health,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RSYN1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RSYN1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_RSYN1_RsSyn = {
    DataObjectModelType,
    "RsSyn",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_RSYN1_RsSyn_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_RsSyn_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_RsSyn_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn,
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_RSYN1_RsSyn_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_RSYN1_RsSyn,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E06_P543_E06P543_MMXU1 = {
    LogicalNodeModelType,
    "MMXU1",
    (ModelNode*) &model_E06_P543_E06P543,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod,
};

DataObject model_E06_P543_E06P543_MMXU1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Health,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Beh,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Health_stVal,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Health,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Health,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_TotW = {
    DataObjectModelType,
    "TotW",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW_mag,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_TotW_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotW_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotW_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotW_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW_d,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotW_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotW,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_TotVAr = {
    DataObjectModelType,
    "TotVAr",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr_mag,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVAr_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVAr_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVAr_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVAr_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr_d,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVAr_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVAr,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_TotVA = {
    DataObjectModelType,
    "TotVA",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA_mag,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVA_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVA_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA_d,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_TotVA_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_TotVA,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_Hz = {
    DataObjectModelType,
    "Hz",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz_mag,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_Hz_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Hz_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Hz_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Hz_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz_d,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_Hz_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_Hz,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_PhV = {
    DataObjectModelType,
    "PhV",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA = {
    DataAttributeModelType,
    "phsA",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_ang,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_ang = {
    DataAttributeModelType,
    "ang",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_ang_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_ang_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_cVal_ang,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsA,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB = {
    DataAttributeModelType,
    "phsB",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_ang,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_ang = {
    DataAttributeModelType,
    "ang",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_ang_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_ang_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_cVal_ang,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsB_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsB,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC = {
    DataAttributeModelType,
    "phsC",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_d,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_ang,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_ang = {
    DataAttributeModelType,
    "ang",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_ang_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_ang_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_cVal_ang,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_phsC_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV_phsC,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_PhV_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_PhV,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E06_P543_E06P543_MMXU1_A = {
    DataObjectModelType,
    "A",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA,
    0,
    -1
};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA = {
    DataAttributeModelType,
    "phsA",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal_ang,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA_cVal_ang = {
    DataAttributeModelType,
    "ang",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal_ang_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA_cVal_ang_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_cVal_ang,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsA,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB = {
    DataAttributeModelType,
    "phsB",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal_ang,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB_cVal_ang = {
    DataAttributeModelType,
    "ang",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal_ang_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB_cVal_ang_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_cVal_ang,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsB_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsB,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC = {
    DataAttributeModelType,
    "phsC",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_d,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_q,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal_mag,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal_ang,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal_mag_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal_mag,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC_cVal_ang = {
    DataAttributeModelType,
    "ang",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal,
    NULL,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal_ang_f,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC_cVal_ang_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_cVal_ang,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_FLOAT32,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC,
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC_t,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_phsC_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A_phsC,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_MX,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E06_P543_E06P543_MMXU1_A_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E06_P543_E06P543_MMXU1_A,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

extern ReportControlBlock model_E06_P543_E06P543_LLN0_report0;
extern ReportControlBlock model_E06_P543_E06P543_LLN0_report1;

ReportControlBlock model_E06_P543_E06P543_LLN0_report0 = {&model_E06_P543_E06P543_LLN0, "DistBRCB01", "E06_P543/E06P543/LLN0.DistBRCB", true, "DistTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E06_P543_E06P543_LLN0_report1};
ReportControlBlock model_E06_P543_E06P543_LLN0_report1 = {&model_E06_P543_E06P543_LLN0, "DistBRCB02", "E06_P543/E06P543/LLN0.DistBRCB", true, "DistTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};








/* --- INJECTED GOOSE CONTROL BLOCK --- */
static PhyComAddress model_E06_P543_E06P543_LLN0_gse0_address = {4, 0x000, 4103, {0x01, 0x0C, 0xCD, 0x02, 0x01, 0x06}};
GSEControlBlock model_E06_P543_E06P543_LLN0_gse0 = {&model_E06_P543_E06P543_LLN0, "gcbTrip", "gcbTrip", "DistTrip", 1, false, &model_E06_P543_E06P543_LLN0_gse0_address, 1, 1000, NULL};

IedModel model_E06_P543 = {
    "E06_P543",
    &model_E06_P543_E06P543,
    &model_E06_P543ds_E06P543_LLN0_DistTrip,
    &model_E06_P543_E06P543_LLN0_report0,
    &model_E06_P543_E06P543_LLN0_gse0,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{

model_E06_P543_E06P543_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

model_E06_P543_E06P543_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("ANTAM_SIM");

model_E06_P543_E06P543_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("1.0.0");

model_E06_P543_E06P543_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("Line-2 Distance + Auto-Reclose (P543)");

model_E06_P543_E06P543_PDIS1_Op_d.mmsValue = MmsValue_newVisibleString("Zone 1 Distance Protection");

model_E06_P543_E06P543_PDIS2_Op_d.mmsValue = MmsValue_newVisibleString("Zone 2 Distance Protection");

model_E06_P543_E06P543_PDIS3_Op_d.mmsValue = MmsValue_newVisibleString("Zone 3 Distance Protection");

model_E06_P543_E06P543_PDIS4_Op_d.mmsValue = MmsValue_newVisibleString("Zone 4 Distance Protection");
}
