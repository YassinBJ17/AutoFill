#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeSpeed.h"

 void ToComputeSpeed_init(outC_ToComputeSpeed *outC) {   outC->_L138 = kcg_true;   outC->init = kcg_true;   outC->_L130 = kcg_lit_uint32(0);   outC->_L188 = kcg_lit_uint32(0);   outC->Updated = E_No;   outC->OutOfHigh = E_No;   outC->OutOfTime = E_No;   outC->NTLOS_NGOS_Measure = kcg_lit_float32(0.0);   ToCheckStatusSent_init(&outC->Context_ToCheckStatusSent_OutOfHigh);   ToCheckStatusSent_init(&outC->_1_Context_ToCheckStatusSent_OutOfTime);   ToCheckStatusSent_init(&outC->Context_ToCheckStatusSent_Updated); }
