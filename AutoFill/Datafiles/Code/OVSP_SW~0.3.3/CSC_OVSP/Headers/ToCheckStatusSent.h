/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToCheckStatusSent_H_
#define _ToCheckStatusSent_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  TE_Answer /* _L6/, status/ */ status;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  kcg_bool /* _L13/ */ _L13;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToCheckStatusSent;

/* ===========  node initialization and cycle functions  =========== */
/* ToCheckStatusSent/ */
extern void ToCheckStatusSent(
  /* _L11/, conditionSent/ */
  kcg_bool conditionSent,
  /* _L10/, conditionCurrent/ */
  kcg_bool conditionCurrent,
  /* _L18/, extra_param/ */
  kcg_bool extra_param,
  outC_ToCheckStatusSent *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToCheckStatusSent_reset(outC_ToCheckStatusSent *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToCheckStatusSent_init(outC_ToCheckStatusSent *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToCheckStatusSent_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToCheckStatusSent.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

