/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeCamCmdx.h"

/* ToComputeCamCmdx/ */
void ToComputeCamCmdx(
  /* V_CAN_CAM_Cmd1/ */
  TE_Cmd_Status V_CAN_CAM_Cmd1,
  /* V_CAN_CAM_Cmd2/ */
  TE_Cmd_Status V_CAN_CAM_Cmd2,
  /* NTL_Overspeed_Detected/ */
  kcg_bool NTL_Overspeed_Detected,
  /* NG_Overspeed_Detected/ */
  kcg_bool NG_Overspeed_Detected,
  /* V_DININHIB/, _L9/ */
  TE_Cmd_Status V_DININHIB,
  /* V_OVS_CSSInhib/ */
  TE_Inhibition V_OVS_CSSInhib,
  /* V_OVS_NGInhib/ */
  TE_Inhibition V_OVS_NGInhib,
  /* V_OVS_NTLThresholdInhib/ */
  TE_Inhibition V_OVS_NTLThresholdInhib,
  /* IfBlock1:, isTriggeredTestEnabled/ */
  kcg_bool isTriggeredTestEnabled,
  /* V_TriggTest_Overspeed_Detected/ */
  TE_Answer V_TriggTest_Overspeed_Detected,
  /* V_CAM_Cmd1/, _L2/ */
  TE_Cmd_Status *V_CAM_Cmd1,
  /* V_CAM_Cmd2/, _L3/ */
  TE_Cmd_Status *V_CAM_Cmd2)
{
  kcg_bool tmp;
  kcg_bool tmp1;
  /* IfBlock1:then:_L50/ */
  kcg_bool _L50_then_IfBlock1;
  /* IfBlock1:else:_L4/ */
  kcg_bool _L4_else_IfBlock1;
  /* IfBlock1:else:_L15/ */
  kcg_bool _L15_else_IfBlock1;
  /* IfBlock1:else:_L21/ */
  kcg_bool _L21_else_IfBlock1;
  /* _L7/ */
  kcg_bool _L7;

  if (isTriggeredTestEnabled) {
    _L50_then_IfBlock1 = V_TriggTest_Overspeed_Detected == E_Yes;
  }
  else {
    _L21_else_IfBlock1 = NG_Overspeed_Detected & (V_OVS_NGInhib == E_Not_Inhibited);
    _L15_else_IfBlock1 = V_OVS_CSSInhib == E_Not_Inhibited;
    _L4_else_IfBlock1 = NTL_Overspeed_Detected & (V_OVS_NTLThresholdInhib ==
        E_Not_Inhibited);
  }
  _L7 = V_DININHIB == E_Cmd_On;
  /* _L2=, _L3= */
  if (_L7) {
    *V_CAM_Cmd2 = E_Cmd_Off;
    *V_CAM_Cmd1 = E_Cmd_Off;
  }
  else {
    /* IfBlock1: */
    if (isTriggeredTestEnabled) {
      tmp = _L50_then_IfBlock1 | (V_CAN_CAM_Cmd2 == E_Cmd_On);
      tmp1 = (V_CAN_CAM_Cmd1 == E_Cmd_On) | _L50_then_IfBlock1;
    }
    else {
      tmp = _L21_else_IfBlock1 | (_L15_else_IfBlock1 & (V_CAN_CAM_Cmd2 ==
            E_Cmd_On)) | _L4_else_IfBlock1;
      tmp1 = _L21_else_IfBlock1 | ((V_CAN_CAM_Cmd1 == E_Cmd_On) &
          _L15_else_IfBlock1) | _L4_else_IfBlock1;
    }
    /* _L13= */
    if (tmp) {
      *V_CAM_Cmd2 = E_Cmd_On;
    }
    else {
      *V_CAM_Cmd2 = E_Cmd_Off;
    }
    /* _L12= */
    if (tmp1) {
      *V_CAM_Cmd1 = E_Cmd_On;
    }
    else {
      *V_CAM_Cmd1 = E_Cmd_Off;
    }
  }
}



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeCamCmdx.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

