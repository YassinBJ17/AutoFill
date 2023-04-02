/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToComputeSpeed_H_
#define _ToComputeSpeed_H_

#include "kcg_types.h"
#include "ToCheckStatusSent.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* NTLOS_NGOS_Measure/, _L80/ */ NTLOS_NGOS_Measure;
  TE_Answer /* OutOfTime/, _L225/ */ OutOfTime;
  TE_Answer /* OutOfHigh/, _L223/ */ OutOfHigh;
  TE_Answer /* Updated/, _L229/ */ Updated;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_uint32 /* _L188/, _L195/, _L196/, _cycleCountNoCompute/ */ _L188;
  kcg_bool /* _L138/, _L245/ */ _L138;
  kcg_uint32 /* _L130/,
     _L197/,
     _nb_of_available_edges_for_current_cycle/ */ _L130;
  kcg_bool init;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_ToCheckStatusSent /* _L223=(ToCheckStatusSent#OutOfHigh)/ */ Context_ToCheckStatusSent_OutOfHigh;
  outC_ToCheckStatusSent /* _L225=(ToCheckStatusSent#OutOfTime)/ */ _1_Context_ToCheckStatusSent_OutOfTime;
  outC_ToCheckStatusSent /* _L229=(ToCheckStatusSent#Updated)/ */ Context_ToCheckStatusSent_Updated;
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToComputeSpeed;

/* ===========  node initialization and cycle functions  =========== */
/* ToComputeSpeed/ */
extern void ToComputeSpeed(
  /* _L84/, nb_of_acquired_edges/ */
  kcg_uint32 nb_of_acquired_edges,
  /* _L2/, lastFallingEdgeArrayIndex/ */
  kcg_uint32 lastFallingEdgeArrayIndex,
  /* _L169/, _L170/, _L27/, _timeStamps/, arrayOfFallingEdgesTimeStamps/ */
  array_uint32_101 *arrayOfFallingEdgesTimeStamps,
  /* K_NTLOS_NGOS_NH_NL/, _L4/ */
  kcg_uint32 K_NTLOS_NGOS_NH_NL,
  /* _L50/, timeout_ms/ */
  kcg_float32 timeout_ms,
  /* _L199/, _L217/, _L224/, _L228/, _isStatusSent_loc/, isStatusSent/ */
  kcg_bool isStatusSent,
  outC_ToComputeSpeed *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToComputeSpeed_reset(outC_ToComputeSpeed *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToComputeSpeed_init(outC_ToComputeSpeed *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToComputeSpeed_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeSpeed.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

