#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeOSREARM.h"

 void ToComputeOSREARM_init(outC_ToComputeOSREARM *outC) {   outC->init = kcg_true;   outC->mem_V_OSREARM = E_Cmd_Off;   outC->V_REARM_Cmd = E_Cmd_Off; }
