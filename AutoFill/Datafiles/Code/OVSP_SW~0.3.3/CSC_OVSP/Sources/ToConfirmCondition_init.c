#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToConfirmCondition.h"

 void ToConfirmCondition_init(outC_ToConfirmCondition *outC) {   outC->confirmed = kcg_true;   outC->mem_toBeConfirmedCountTimes = kcg_true;   outC->init = kcg_true;   outC->_L2 = kcg_true;   outC->_L5 = kcg_true;   outC->_L7 = kcg_true;   outC->_L10 = kcg_true; }
