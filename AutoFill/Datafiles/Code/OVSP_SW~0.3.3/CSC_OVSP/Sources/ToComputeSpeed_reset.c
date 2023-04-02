#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeSpeed.h"

 void ToComputeSpeed_reset(outC_ToComputeSpeed *outC) {   outC->init = kcg_true;   ToCheckStatusSent_reset(&outC->Context_ToCheckStatusSent_OutOfHigh);   ToCheckStatusSent_reset(&outC->_1_Context_ToCheckStatusSent_OutOfTime);   ToCheckStatusSent_reset(&outC->Context_ToCheckStatusSent_Updated); }
