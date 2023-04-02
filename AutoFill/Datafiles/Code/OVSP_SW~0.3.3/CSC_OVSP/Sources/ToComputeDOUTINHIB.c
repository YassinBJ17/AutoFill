/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeDOUTINHIB.h"

/* ToComputeDOUTINHIB/ */
void ToComputeDOUTINHIB(
  /* V_Engine_SpeedLevel/ */
  TE_Speed_Level V_Engine_SpeedLevel,
  /* V_CAN_CAM_Cmd1/, _L68/ */
  TE_Cmd_Status V_CAN_CAM_Cmd1,
  /* V_CAN_CAM_Cmd2/, _L20/ */
  TE_Cmd_Status V_CAN_CAM_Cmd2,
  /* V_OVS_CSSInhib/ */
  TE_Inhibition V_OVS_CSSInhib,
  /* V_Interlock_Inhib/ */
  TE_Inhibition V_Interlock_Inhib,
  /* V_REARM_Cmd/, _L35/ */
  TE_Cmd_Status V_REARM_Cmd,
  /* IfBlock2:, isTriggeredTestEnabled/ */
  kcg_bool isTriggeredTestEnabled,
  /* V_TriggTest_Overspeed_Detected/ */
  TE_Answer V_TriggTest_Overspeed_Detected,
  /* V_DININHIB/, _L127/ */
  TE_Cmd_Status V_DININHIB,
  outC_ToComputeDOUTINHIB *outC)
{
  kcg_bool tmp;
  kcg_bool tmp1;
  /* _CAN_CAM_Cmd2_is_on/, _L1/ */
  kcg_bool _L1;
  /* _CAN_CAM_Cmd1_is_on/, _L67/ */
  kcg_bool _L67;

  _L67 = E_Cmd_On == V_CAN_CAM_Cmd1;
  _L1 = E_Cmd_On == V_CAN_CAM_Cmd2;
  /* IfBlock2: */
  if (isTriggeredTestEnabled) {
    tmp = kcg_false;
  }
  else {
    tmp = V_Interlock_Inhib == E_Inhibited;
  }
  /* _L29= */
  if ((V_DININHIB == E_Cmd_On) | (V_REARM_Cmd == E_Cmd_On) | tmp) {
    outC->DOUTINHIB = E_Cmd_Off;
  }
  else {
    /* IfBlock2: */
    if (isTriggeredTestEnabled) {
      tmp1 = (E_Yes == V_TriggTest_Overspeed_Detected) | _L67 | _L1;
    }
    else {
      tmp1 = (V_Engine_SpeedLevel == E_Overspeed) | ((_L67 | _L1) &
          (E_Not_Inhibited == V_OVS_CSSInhib));
    }
    /* _L8= */
    if (tmp1) {
      outC->DOUTINHIB = E_Cmd_On;
    }
    else /* _L10= */
    if (outC->init) {
      outC->DOUTINHIB = E_Cmd_Off;
    }
  }
  outC->init = kcg_false;
}

#ifndef KCG_USER_DEFINED_INIT
void ToComputeDOUTINHIB_init(outC_ToComputeDOUTINHIB *outC)
{
  outC->init = kcg_true;
  outC->DOUTINHIB = E_Cmd_Off;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToComputeDOUTINHIB_reset(outC_ToComputeDOUTINHIB *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeDOUTINHIB.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

