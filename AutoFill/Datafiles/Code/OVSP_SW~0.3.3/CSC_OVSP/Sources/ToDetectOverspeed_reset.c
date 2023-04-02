#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToDetectOverspeed.h"

 void ToDetectOverspeed_reset(outC_ToDetectOverspeed *outC) {   outC->init = kcg_true;   outC->init1 = kcg_true;   ToComputeDOUTINHIB_reset(&outC->Context_ToComputeDOUTINHIB_1);   ToComputeOSREARM_reset(&outC->Context_ToComputeOSREARM_1);   ToDetectNxOverspeed_reset(&outC->Context_ToDetectNxOverspeed_NG);   ToDetectNxOverspeed_reset(&outC->Context_ToDetectNxOverspeed_NTL);   ToSelectNTLThreshold_reset(&outC->Context_ToSelectNTLThreshold_NTLOS2);   ToSelectNTLThreshold_reset(&outC->_2_Context_ToSelectNTLThreshold_NTLOS1);   ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_Test_Speed);   ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NGOS1);   ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NGOS2);   ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NTLOS2);   ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NTLOS1); }
