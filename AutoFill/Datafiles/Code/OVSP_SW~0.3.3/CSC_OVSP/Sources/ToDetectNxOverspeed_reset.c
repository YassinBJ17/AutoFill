#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToDetectNxOverspeed.h"

 void ToDetectNxOverspeed_reset(outC_ToDetectNxOverspeed *outC) {   ToConfirmCondition_reset(&outC->Context_ToConfirmCondition_3);   ToConfirmCondition_reset(&outC->Context_ToConfirmCondition_2); }
