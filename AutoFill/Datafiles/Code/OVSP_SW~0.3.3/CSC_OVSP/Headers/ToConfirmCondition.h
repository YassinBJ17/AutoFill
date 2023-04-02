/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToConfirmCondition_H_
#define _ToConfirmCondition_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* _L14/, confirmed/ */ confirmed;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* _L1/, toBeConfirmedCountTimes/ */ mem_toBeConfirmedCountTimes;
  kcg_bool init;
  kcg_bool /* _L2/ */ _L2;
  kcg_bool /* _L5/ */ _L5;
  kcg_bool /* _L7/ */ _L7;
  kcg_bool /* _L10/ */ _L10;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToConfirmCondition;

/* ===========  node initialization and cycle functions  =========== */
/* ToConfirmCondition/ */
extern void ToConfirmCondition(
  /* _L1/, toBeConfirmedCountTimes/ */
  kcg_bool toBeConfirmedCountTimes,
  /* _L15/, count/ */
  kcg_uint32 count,
  outC_ToConfirmCondition *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToConfirmCondition_reset(outC_ToConfirmCondition *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToConfirmCondition_init(outC_ToConfirmCondition *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToConfirmCondition_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToConfirmCondition.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

