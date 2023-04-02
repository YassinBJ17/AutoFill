/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToDetectNxOverspeed_H_
#define _ToDetectNxOverspeed_H_

#include "kcg_types.h"
#include "ToConfirmCondition.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* NTL_NG_OVERSPEED/, _L63/ */ NTL_NG_OVERSPEED;
  TE_Answer /* V_NxxOS1_OVS_Conditions_Met/,
     _L100/ */ V_NxxOS1_OVS_Conditions_Met;
  TE_Answer /* V_NxxOS2_OVS_Conditions_Met/,
     _L97/ */ V_NxxOS2_OVS_Conditions_Met;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_ToConfirmCondition /* _L15=(ToConfirmCondition#3)/ */ Context_ToConfirmCondition_3;
  outC_ToConfirmCondition /* _L40=(ToConfirmCondition#2)/ */ Context_ToConfirmCondition_2;
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToDetectNxOverspeed;

/* ===========  node initialization and cycle functions  =========== */
/* ToDetectNxOverspeed/ */
extern void ToDetectNxOverspeed(
  /* NTLOS_NGOS_Measure_1/, _L54/ */
  kcg_float32 NTLOS_NGOS_Measure_1,
  /* NTLOS_NGOS_Measure_2/, _L55/ */
  kcg_float32 NTLOS_NGOS_Measure_2,
  /* K_NTL_NG_OVSTHRESD_N/, _L10/, _L21/, _L22/, _cycle_count/ */
  kcg_uint32 K_NTL_NG_OVSTHRESD_N,
  /* _L25/, threshold_1/ */
  kcg_float32 threshold_1,
  /* _L56/, threshold_2/ */
  kcg_float32 threshold_2,
  /* K_NTL_NG_OVSTHRESD_Window/, _L19/ */
  kcg_float32 K_NTL_NG_OVSTHRESD_Window,
  /* OVS_OneSensor_NTL_NG_Inhib/, _L8/ */
  TE_Inhibition OVS_OneSensor_NTL_NG_Inhib,
  /* OneSensor_CSSauthorization/, _L58/ */
  TE_OneSensor_Authorization OneSensor_CSSauthorization,
  /* _L66/, freq_100_1/ */
  kcg_float32 freq_100_1,
  /* _L67/, freq_100_2/ */
  kcg_float32 freq_100_2,
  outC_ToDetectNxOverspeed *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToDetectNxOverspeed_reset(outC_ToDetectNxOverspeed *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToDetectNxOverspeed_init(outC_ToDetectNxOverspeed *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToDetectNxOverspeed_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToDetectNxOverspeed.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

