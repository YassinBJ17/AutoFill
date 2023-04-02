/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToComputeDOUTINHIB_H_
#define _ToComputeDOUTINHIB_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  TE_Cmd_Status /* DOUTINHIB/, _L29/ */ DOUTINHIB;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToComputeDOUTINHIB;

/* ===========  node initialization and cycle functions  =========== */
/* ToComputeDOUTINHIB/ */
extern void ToComputeDOUTINHIB(
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
  outC_ToComputeDOUTINHIB *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToComputeDOUTINHIB_reset(outC_ToComputeDOUTINHIB *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToComputeDOUTINHIB_init(outC_ToComputeDOUTINHIB *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToComputeDOUTINHIB_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeDOUTINHIB.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

