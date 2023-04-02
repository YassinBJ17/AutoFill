/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToSelectNTLThreshold_H_
#define _ToSelectNTLThreshold_H_

#include "kcg_types.h"
#include "ToComputeNTLThreshold.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_float32 /* _L16/, threshold/ */ threshold;
  /* -----------------------  no local probes  ----------------------- */
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  kcg_float32 /* _L21/ */ _L21;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToSelectNTLThreshold;

/* ===========  node initialization and cycle functions  =========== */
/* ToSelectNTLThreshold/ */
extern void ToSelectNTLThreshold(
  /* _L1/, ng_values_Ar/ */
  array_float32_6 *ng_values_Ar,
  /* _L2/, ntl_values_Ar/ */
  array_float32_6 *ntl_values_Ar,
  /* V_NTL_OVS_FUNCTION/, _L3/ */
  TE_NTL_Threshold_Type V_NTL_OVS_FUNCTION,
  /* V_NTL_OVSTHRESD_Threshold/, _L13/ */
  kcg_float32 V_NTL_OVSTHRESD_Threshold,
  /* V_NGOSx_Measure/, _L8/ */
  kcg_float32 V_NGOSx_Measure,
  /* V_NGOSx_Updated/, _L18/ */
  TE_Answer V_NGOSx_Updated,
  /* V_NGOSx_OutOfTime/, _L27/ */
  TE_Answer V_NGOSx_OutOfTime,
  /* _L23/, _L72/, _default_variable_threshold/, default_variable_threshold/ */
  kcg_float32 default_variable_threshold,
  /* _L73/, frequency_at_100_percent/ */
  kcg_float32 frequency_at_100_percent,
  outC_ToSelectNTLThreshold *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToSelectNTLThreshold_reset(outC_ToSelectNTLThreshold *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToSelectNTLThreshold_init(outC_ToSelectNTLThreshold *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToSelectNTLThreshold_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToSelectNTLThreshold.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

