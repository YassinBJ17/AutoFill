#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToDetectNxOverspeed.h"

 void ToDetectNxOverspeed_init(outC_ToDetectNxOverspeed *outC) {   outC->NTL_NG_OVERSPEED = kcg_true;   outC->V_NxxOS2_OVS_Conditions_Met = E_No;   outC->V_NxxOS1_OVS_Conditions_Met = E_No;   ToConfirmCondition_init(&outC->Context_ToConfirmCondition_3);   ToConfirmCondition_init(&outC->Context_ToConfirmCondition_2); }
