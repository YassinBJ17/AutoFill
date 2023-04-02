/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToComputeCamCmdx_H_
#define _ToComputeCamCmdx_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ToComputeCamCmdx/ */
extern void ToComputeCamCmdx(
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
  TE_Cmd_Status *V_CAM_Cmd2);



#endif /* _ToComputeCamCmdx_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeCamCmdx.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

