/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeOSREARM.h"

/* ToComputeOSREARM/ */
void ToComputeOSREARM(
  /* V_OSREARM/, _L1/ */
  TE_Cmd_Status V_OSREARM,
  /* V_CAN_REARM_Request/, _L10/ */
  TE_Request V_CAN_REARM_Request,
  /* IfBlock1:, isTriggeredTestEnabled/ */
  kcg_bool isTriggeredTestEnabled,
  /* V_Engine_SpeedLevel/ */
  TE_Speed_Level V_Engine_SpeedLevel,
  outC_ToComputeOSREARM *outC)
{
  kcg_bool tmp;
  TE_Cmd_Status tmp1;

  /* IfBlock1: */
  if (isTriggeredTestEnabled) {
    tmp = kcg_true;
  }
  else {
    tmp = V_Engine_SpeedLevel == E_Low_Speed;
  }
  /* _L12= */
  if (outC->init) {
    outC->init = kcg_false;
    tmp1 = E_Cmd_On;
  }
  else {
    tmp1 = outC->mem_V_OSREARM;
  }
  /* _L6= */
  if (tmp & ((V_CAN_REARM_Request == E_Requested) | ((V_OSREARM == E_Cmd_On) &
        (tmp1 == E_Cmd_Off)))) {
    outC->V_REARM_Cmd = E_Cmd_On;
  }
  else {
    outC->V_REARM_Cmd = E_Cmd_Off;
  }
  outC->mem_V_OSREARM = V_OSREARM;
}

#ifndef KCG_USER_DEFINED_INIT
void ToComputeOSREARM_init(outC_ToComputeOSREARM *outC)
{
  outC->init = kcg_true;
  outC->mem_V_OSREARM = E_Cmd_Off;
  outC->V_REARM_Cmd = E_Cmd_Off;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToComputeOSREARM_reset(outC_ToComputeOSREARM *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeOSREARM.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

