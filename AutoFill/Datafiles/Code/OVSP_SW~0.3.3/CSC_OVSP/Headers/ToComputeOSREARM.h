/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToComputeOSREARM_H_
#define _ToComputeOSREARM_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  TE_Cmd_Status /* V_REARM_Cmd/, _L6/ */ V_REARM_Cmd;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  TE_Cmd_Status /* V_OSREARM/, _L1/ */ mem_V_OSREARM;
  kcg_bool init;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToComputeOSREARM;

/* ===========  node initialization and cycle functions  =========== */
/* ToComputeOSREARM/ */
extern void ToComputeOSREARM(
  /* V_OSREARM/, _L1/ */
  TE_Cmd_Status V_OSREARM,
  /* V_CAN_REARM_Request/, _L10/ */
  TE_Request V_CAN_REARM_Request,
  /* IfBlock1:, isTriggeredTestEnabled/ */
  kcg_bool isTriggeredTestEnabled,
  /* V_Engine_SpeedLevel/ */
  TE_Speed_Level V_Engine_SpeedLevel,
  outC_ToComputeOSREARM *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToComputeOSREARM_reset(outC_ToComputeOSREARM *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToComputeOSREARM_init(outC_ToComputeOSREARM *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToComputeOSREARM_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeOSREARM.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

