/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToSelectNTLThreshold.h"

/* ToSelectNTLThreshold/ */
void ToSelectNTLThreshold(
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
  outC_ToSelectNTLThreshold *outC)
{
  /* _L21= */
  if (V_NGOSx_Updated == E_Yes) {
    outC->_L21 = /* _L7=(ToComputeNTLThreshold#2)/ */
      ToComputeNTLThreshold(
        ng_values_Ar,
        ntl_values_Ar,
        V_NGOSx_Measure * kcg_lit_float32(100.) / frequency_at_100_percent);
  }
  else /* _L19= */
  if (outC->init) {
    outC->_L21 = default_variable_threshold;
  }
  outC->init = kcg_false;
  /* _L16= */
  if (V_NTL_OVS_FUNCTION == E_NTL_Fixed_Thres) {
    outC->threshold = V_NTL_OVSTHRESD_Threshold;
  }
  else /* _L68= */
  if (V_NGOSx_OutOfTime == E_Yes) {
    outC->threshold = default_variable_threshold;
  }
  else {
    outC->threshold = outC->_L21;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void ToSelectNTLThreshold_init(outC_ToSelectNTLThreshold *outC)
{
  outC->init = kcg_true;
  outC->_L21 = kcg_lit_float32(0.0);
  outC->threshold = kcg_lit_float32(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToSelectNTLThreshold_reset(outC_ToSelectNTLThreshold *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToSelectNTLThreshold.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

