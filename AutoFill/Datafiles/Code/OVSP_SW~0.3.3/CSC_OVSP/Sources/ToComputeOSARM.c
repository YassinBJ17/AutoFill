/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeOSARM.h"

/* ToComputeOSARM/ */
TE_Cmd_Status ToComputeOSARM(
  /* V_CAN_OSARM_Request/, _L5/ */
  TE_Request V_CAN_OSARM_Request,
  /* V_CBIT_Result/, _L55/ */
  TE_Test_Result V_CBIT_Result,
  /* V_OVSP_Side_Id/ */
  TE_OVSP_Side V_OVSP_Side_Id,
  /* V_CAM_HS_Current/ */
  kcg_float32 V_CAM_HS_Current,
  /* V_CAM_LS_Current/ */
  kcg_float32 V_CAM_LS_Current,
  /* V_Engine_SpeedLevel/ */
  TE_Speed_Level V_Engine_SpeedLevel,
  /* IfBlock2:, isTriggeredTestEnabled/ */
  kcg_bool isTriggeredTestEnabled)
{
  kcg_bool tmp;
  kcg_bool tmp1;
  kcg_bool tmp2;
  /* V_OSARM_Cmd/, _L8/ */
  TE_Cmd_Status V_OSARM_Cmd;

  /* IfBlock2: */
  if (isTriggeredTestEnabled) {
    tmp = kcg_true;
  }
  else {
    tmp = V_Engine_SpeedLevel == E_Low_Speed;
  }
  /* _L8= */
  if ((V_CAN_OSARM_Request == E_Requested) & tmp) {
    V_OSARM_Cmd = E_Cmd_On;
  }
  else {
    /* IfBlock2: */
    if (isTriggeredTestEnabled) {
      tmp2 = kcg_false;
      tmp1 = kcg_true;
    }
    else {
      tmp1 = (V_Engine_SpeedLevel == E_Running_Speed) | (V_Engine_SpeedLevel ==
          E_Overspeed);
      tmp2 = (V_OVSP_Side_Id == E_OVSP_HS) & ((V_CAM_HS_Current >=
            C_CAM_CURRENT_THRESH) & (V_CAM_LS_Current >= C_CAM_CURRENT_THRESH));
    }
    /* _L13= */
    if (tmp1 & ((V_CBIT_Result == E_Test_Failed) | tmp2)) {
      V_OSARM_Cmd = E_Cmd_On;
    }
    else {
      V_OSARM_Cmd = E_Cmd_Off;
    }
  }
  return V_OSARM_Cmd;
}



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeOSARM.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

