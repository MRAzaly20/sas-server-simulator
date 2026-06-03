/*
 * E00_P746.c
 *
 * automatically generated from E00_P746.cid
 */
#include "E00_P746.h"

static void initializeValues();

extern DataSet model_E00_P746ds_E00P746Z1_LLN0_BBTrip;
extern DataSet model_E00_P746ds_E00P746Z2_LLN0_BBTrip;
extern DataSet model_E00_P746ds_E00P746CZ_LLN0_BBTrip;


extern DataSetEntry model_E00_P746ds_E00P746Z1_LLN0_BBTrip_fcda0;
extern DataSetEntry model_E00_P746ds_E00P746Z1_LLN0_BBTrip_fcda1;

DataSetEntry model_E00_P746ds_E00P746Z1_LLN0_BBTrip_fcda0 = {
  "E00P746Z1",
  false,
  "PDIF1$ST$Op$general", 
  -1,
  NULL,
  NULL,
  &model_E00_P746ds_E00P746Z1_LLN0_BBTrip_fcda1
};

DataSetEntry model_E00_P746ds_E00P746Z1_LLN0_BBTrip_fcda1 = {
  "E00P746Z1",
  false,
  "RBRF1$ST$OpEx$general", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet model_E00_P746ds_E00P746Z1_LLN0_BBTrip = {
  "E00P746Z1",
  "LLN0$BBTrip",
  2,
  &model_E00_P746ds_E00P746Z1_LLN0_BBTrip_fcda0,
  &model_E00_P746ds_E00P746Z2_LLN0_BBTrip
};

extern DataSetEntry model_E00_P746ds_E00P746Z2_LLN0_BBTrip_fcda0;
extern DataSetEntry model_E00_P746ds_E00P746Z2_LLN0_BBTrip_fcda1;

DataSetEntry model_E00_P746ds_E00P746Z2_LLN0_BBTrip_fcda0 = {
  "E00P746Z2",
  false,
  "PDIF1$ST$Op$general", 
  -1,
  NULL,
  NULL,
  &model_E00_P746ds_E00P746Z2_LLN0_BBTrip_fcda1
};

DataSetEntry model_E00_P746ds_E00P746Z2_LLN0_BBTrip_fcda1 = {
  "E00P746Z2",
  false,
  "RBRF1$ST$OpEx$general", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet model_E00_P746ds_E00P746Z2_LLN0_BBTrip = {
  "E00P746Z2",
  "LLN0$BBTrip",
  2,
  &model_E00_P746ds_E00P746Z2_LLN0_BBTrip_fcda0,
  &model_E00_P746ds_E00P746CZ_LLN0_BBTrip
};

extern DataSetEntry model_E00_P746ds_E00P746CZ_LLN0_BBTrip_fcda0;
extern DataSetEntry model_E00_P746ds_E00P746CZ_LLN0_BBTrip_fcda1;

DataSetEntry model_E00_P746ds_E00P746CZ_LLN0_BBTrip_fcda0 = {
  "E00P746CZ",
  false,
  "PDIF1$ST$Op$general", 
  -1,
  NULL,
  NULL,
  &model_E00_P746ds_E00P746CZ_LLN0_BBTrip_fcda1
};

DataSetEntry model_E00_P746ds_E00P746CZ_LLN0_BBTrip_fcda1 = {
  "E00P746CZ",
  false,
  "RBRF1$ST$OpEx$general", 
  -1,
  NULL,
  NULL,
  NULL
};

DataSet model_E00_P746ds_E00P746CZ_LLN0_BBTrip = {
  "E00P746CZ",
  "LLN0$BBTrip",
  2,
  &model_E00_P746ds_E00P746CZ_LLN0_BBTrip_fcda0,
  NULL
};

LogicalDevice model_E00_P746_E00P746Z1 = {
    LogicalDeviceModelType,
    "E00P746Z1",
    (ModelNode*) &model_E00_P746,
    (ModelNode*) &model_E00_P746_E00P746Z2,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0,
    NULL
};

LogicalNode model_E00_P746_E00P746Z1_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &model_E00_P746_E00P746Z1,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod,
};

DataObject model_E00_P746_E00P746Z1_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z1_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z1_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &model_E00_P746_E00P746Z1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam,
};

DataObject model_E00_P746_E00P746Z1_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam_hwRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyNam_hwRev = {
    DataAttributeModelType,
    "hwRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyNam_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam_serNum,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyNam_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_LPHD1_Proxy_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z1_PDIF1 = {
    LogicalNodeModelType,
    "PDIF1",
    (ModelNode*) &model_E00_P746_E00P746Z1,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod,
};

DataObject model_E00_P746_E00P746Z1_PDIF1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PDIF1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PDIF1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PDIF1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PDIF1_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PDIF1_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_PDIF1_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z1_RBRF1 = {
    LogicalNodeModelType,
    "RBRF1",
    (ModelNode*) &model_E00_P746_E00P746Z1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod,
};

DataObject model_E00_P746_E00P746Z1_RBRF1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_RBRF1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_RBRF1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_RBRF1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_RBRF1_OpEx = {
    DataObjectModelType,
    "OpEx",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_OpEx_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_OpEx_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_OpEx_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_OpEx_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_OpEx,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_RBRF1_FailMod = {
    DataObjectModelType,
    "FailMod",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_FailMod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_FailMod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_FailMod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_FailMod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_FailMod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_RBRF1_FailMod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_RBRF1_FailMod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z1_PTRC1 = {
    LogicalNodeModelType,
    "PTRC1",
    (ModelNode*) &model_E00_P746_E00P746Z1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod,
};

DataObject model_E00_P746_E00P746Z1_PTRC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PTRC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PTRC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PTRC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z1_PTRC1_Tr = {
    DataObjectModelType,
    "Tr",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Tr_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Tr_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Tr_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z1_PTRC1_Tr_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z1_PTRC1_Tr,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};


LogicalDevice model_E00_P746_E00P746Z2 = {
    LogicalDeviceModelType,
    "E00P746Z2",
    (ModelNode*) &model_E00_P746,
    (ModelNode*) &model_E00_P746_E00P746CZ,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0,
    NULL
};

LogicalNode model_E00_P746_E00P746Z2_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &model_E00_P746_E00P746Z2,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod,
};

DataObject model_E00_P746_E00P746Z2_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z2_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z2_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &model_E00_P746_E00P746Z2,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam,
};

DataObject model_E00_P746_E00P746Z2_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam_hwRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyNam_hwRev = {
    DataAttributeModelType,
    "hwRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyNam_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam_serNum,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyNam_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_LPHD1_Proxy_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z2_PDIF1 = {
    LogicalNodeModelType,
    "PDIF1",
    (ModelNode*) &model_E00_P746_E00P746Z2,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod,
};

DataObject model_E00_P746_E00P746Z2_PDIF1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PDIF1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PDIF1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PDIF1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PDIF1_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PDIF1_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_PDIF1_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z2_RBRF1 = {
    LogicalNodeModelType,
    "RBRF1",
    (ModelNode*) &model_E00_P746_E00P746Z2,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod,
};

DataObject model_E00_P746_E00P746Z2_RBRF1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_RBRF1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_RBRF1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_RBRF1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_RBRF1_OpEx = {
    DataObjectModelType,
    "OpEx",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_OpEx_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_OpEx_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_OpEx_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_OpEx_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_OpEx,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_RBRF1_FailMod = {
    DataObjectModelType,
    "FailMod",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_FailMod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_FailMod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_FailMod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_FailMod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_FailMod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_RBRF1_FailMod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_RBRF1_FailMod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746Z2_PTRC1 = {
    LogicalNodeModelType,
    "PTRC1",
    (ModelNode*) &model_E00_P746_E00P746Z2,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod,
};

DataObject model_E00_P746_E00P746Z2_PTRC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PTRC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PTRC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PTRC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746Z2_PTRC1_Tr = {
    DataObjectModelType,
    "Tr",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Tr_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Tr_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Tr_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746Z2_PTRC1_Tr_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746Z2_PTRC1_Tr,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};


LogicalDevice model_E00_P746_E00P746CZ = {
    LogicalDeviceModelType,
    "E00P746CZ",
    (ModelNode*) &model_E00_P746,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0,
    NULL
};

LogicalNode model_E00_P746_E00P746CZ_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &model_E00_P746_E00P746CZ,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod,
};

DataObject model_E00_P746_E00P746CZ_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LLN0_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746CZ_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746CZ_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &model_E00_P746_E00P746CZ,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam,
};

DataObject model_E00_P746_E00P746CZ_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam_hwRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyNam_hwRev = {
    DataAttributeModelType,
    "hwRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyNam_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam_serNum,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyNam_serNum = {
    DataAttributeModelType,
    "serNum",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam_model,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyNam_model = {
    DataAttributeModelType,
    "model",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyHealth_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyHealth_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyHealth,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyHealth_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy,
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_LPHD1_Proxy_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746CZ_PDIF1 = {
    LogicalNodeModelType,
    "PDIF1",
    (ModelNode*) &model_E00_P746_E00P746CZ,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod,
};

DataObject model_E00_P746_E00P746CZ_PDIF1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PDIF1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PDIF1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PDIF1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PDIF1_Op = {
    DataObjectModelType,
    "Op",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Op_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Op_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Op_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op,
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PDIF1_Op_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_PDIF1_Op,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746CZ_RBRF1 = {
    LogicalNodeModelType,
    "RBRF1",
    (ModelNode*) &model_E00_P746_E00P746CZ,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod,
};

DataObject model_E00_P746_E00P746CZ_RBRF1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_RBRF1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_RBRF1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_RBRF1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_RBRF1_OpEx = {
    DataObjectModelType,
    "OpEx",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_OpEx_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_OpEx_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_OpEx_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_OpEx_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_OpEx,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_RBRF1_FailMod = {
    DataObjectModelType,
    "FailMod",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_FailMod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_FailMod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_FailMod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_FailMod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_FailMod,
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_FailMod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_RBRF1_FailMod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_RBRF1_FailMod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode model_E00_P746_E00P746CZ_PTRC1 = {
    LogicalNodeModelType,
    "PTRC1",
    (ModelNode*) &model_E00_P746_E00P746CZ,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod,
};

DataObject model_E00_P746_E00P746CZ_PTRC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod_ctlModel,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Mod_ctlModel = {
    DataAttributeModelType,
    "ctlModel",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Mod,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_CF,
    IEC61850_ENUMERATED,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PTRC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Beh_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Beh_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Beh,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Beh_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Beh,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PTRC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Health_stVal,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Health_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_INT32,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Health,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Health_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Health,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PTRC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt_vendor,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt_swRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt_d,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt_configRev,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_NamPlt_configRev = {
    DataAttributeModelType,
    "configRev",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt_ldNs,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_NamPlt_ldNs = {
    DataAttributeModelType,
    "ldNs",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_NamPlt,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_EX,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject model_E00_P746_E00P746CZ_PTRC1_Tr = {
    DataObjectModelType,
    "Tr",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1,
    NULL,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr_general,
    0,
    -1
};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Tr_general = {
    DataAttributeModelType,
    "general",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr_q,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_BOOLEAN,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Tr_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr_t,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_QUALITY,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Tr_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr,
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr_d,
    NULL,
    0,
    -1,
    IEC61850_FC_ST,
    IEC61850_TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute model_E00_P746_E00P746CZ_PTRC1_Tr_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &model_E00_P746_E00P746CZ_PTRC1_Tr,
    NULL,
    NULL,
    0,
    -1,
    IEC61850_FC_DC,
    IEC61850_VISIBLE_STRING_255,
    0,
    NULL,
    0};

extern ReportControlBlock model_E00_P746_E00P746Z1_LLN0_report0;
extern ReportControlBlock model_E00_P746_E00P746Z1_LLN0_report1;
extern ReportControlBlock model_E00_P746_E00P746Z2_LLN0_report0;
extern ReportControlBlock model_E00_P746_E00P746Z2_LLN0_report1;
extern ReportControlBlock model_E00_P746_E00P746CZ_LLN0_report0;
extern ReportControlBlock model_E00_P746_E00P746CZ_LLN0_report1;

ReportControlBlock model_E00_P746_E00P746Z1_LLN0_report0 = {&model_E00_P746_E00P746Z1_LLN0, "BBRCB01", "E00_P746/E00P746Z1/LLN0.BBRCB", true, "BBTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E00_P746_E00P746Z1_LLN0_report1};
ReportControlBlock model_E00_P746_E00P746Z1_LLN0_report1 = {&model_E00_P746_E00P746Z1_LLN0, "BBRCB02", "E00_P746/E00P746Z1/LLN0.BBRCB", true, "BBTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E00_P746_E00P746Z2_LLN0_report0};
ReportControlBlock model_E00_P746_E00P746Z2_LLN0_report0 = {&model_E00_P746_E00P746Z2_LLN0, "BBRCB01", "E00_P746/E00P746Z2/LLN0.BBRCB", true, "BBTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E00_P746_E00P746Z2_LLN0_report1};
ReportControlBlock model_E00_P746_E00P746Z2_LLN0_report1 = {&model_E00_P746_E00P746Z2_LLN0, "BBRCB02", "E00_P746/E00P746Z2/LLN0.BBRCB", true, "BBTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E00_P746_E00P746CZ_LLN0_report0};
ReportControlBlock model_E00_P746_E00P746CZ_LLN0_report0 = {&model_E00_P746_E00P746CZ_LLN0, "BBRCB01", "E00_P746/E00P746CZ/LLN0.BBRCB", true, "BBTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, &model_E00_P746_E00P746CZ_LLN0_report1};
ReportControlBlock model_E00_P746_E00P746CZ_LLN0_report1 = {&model_E00_P746_E00P746CZ_LLN0, "BBRCB02", "E00_P746/E00P746CZ/LLN0.BBRCB", true, "BBTrip", 1, 19, 255, 0, 0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}, NULL};



/* --- GSEControlBlock for E00P746Z1 (gcbE00P746Z1) --- */
static PhyComAddress model_E00_P746_E00P746Z1_LLN0_gse0_address = {4, 0x000, 4097, {0x01, 0x0C, 0xCD, 0x01, 0x00, 0x01}};
GSEControlBlock model_E00_P746_E00P746Z1_LLN0_gse0 = {&model_E00_P746_E00P746Z1_LLN0, "gcbE00P746Z1", "gcbE00P746Z1", "BBTrip", 1, false, &model_E00_P746_E00P746Z1_LLN0_gse0_address, 1, 1000, NULL};
extern GSEControlBlock model_E00_P746_E00P746Z1_LLN0_gse0;

/* --- GSEControlBlock for E00P746Z2 (gcbE00P746Z2) --- */
static PhyComAddress model_E00_P746_E00P746Z2_LLN0_gse0_address = {4, 0x000, 4098, {0x01, 0x0C, 0xCD, 0x01, 0x00, 0x02}};
GSEControlBlock model_E00_P746_E00P746Z2_LLN0_gse0 = {&model_E00_P746_E00P746Z2_LLN0, "gcbE00P746Z2", "gcbE00P746Z2", "BBTrip", 1, false, &model_E00_P746_E00P746Z2_LLN0_gse0_address, 1, 1000, NULL};
extern GSEControlBlock model_E00_P746_E00P746Z2_LLN0_gse0;

/* --- GSEControlBlock for E00P746CZ (gcbE00P746CZ) --- */
static PhyComAddress model_E00_P746_E00P746CZ_LLN0_gse0_address = {4, 0x000, 4099, {0x01, 0x0C, 0xCD, 0x01, 0x00, 0x03}};
GSEControlBlock model_E00_P746_E00P746CZ_LLN0_gse0 = {&model_E00_P746_E00P746CZ_LLN0, "gcbE00P746CZ", "gcbE00P746CZ", "BBTrip", 1, false, &model_E00_P746_E00P746CZ_LLN0_gse0_address, 1, 1000, NULL};
extern GSEControlBlock model_E00_P746_E00P746CZ_LLN0_gse0;





IedModel model_E00_P746 = {
    "E00_P746",
    &model_E00_P746_E00P746Z1,
    &model_E00_P746ds_E00P746Z1_LLN0_BBTrip,
    &model_E00_P746_E00P746Z1_LLN0_report0,
    &model_E00_P746_E00P746Z1_LLN0_gse0,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{

model_E00_P746_E00P746Z1_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

model_E00_P746_E00P746Z1_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("ANTAM_SIM");

model_E00_P746_E00P746Z1_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("1.0.0");

model_E00_P746_E00P746Z1_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("Busbar Protection Zone 1");

model_E00_P746_E00P746Z1_PDIF1_Op_d.mmsValue = MmsValue_newVisibleString("87B Zone 1");

model_E00_P746_E00P746Z2_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

model_E00_P746_E00P746Z2_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("ANTAM_SIM");

model_E00_P746_E00P746Z2_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("1.0.0");

model_E00_P746_E00P746Z2_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("Busbar Protection Zone 2");

model_E00_P746_E00P746Z2_PDIF1_Op_d.mmsValue = MmsValue_newVisibleString("87B Zone 2");

model_E00_P746_E00P746CZ_LLN0_Mod_ctlModel.mmsValue = MmsValue_newIntegerFromInt32(0);

model_E00_P746_E00P746CZ_LLN0_NamPlt_vendor.mmsValue = MmsValue_newVisibleString("ANTAM_SIM");

model_E00_P746_E00P746CZ_LLN0_NamPlt_swRev.mmsValue = MmsValue_newVisibleString("1.0.0");

model_E00_P746_E00P746CZ_LLN0_NamPlt_d.mmsValue = MmsValue_newVisibleString("Busbar Protection Check Zone");

model_E00_P746_E00P746CZ_PDIF1_Op_d.mmsValue = MmsValue_newVisibleString("87B Check Zone");
}
