/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToDetectNxOverspeed.h"

/* ToDetectNxOverspeed/ */
void ToDetectNxOverspeed(
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
  outC_ToDetectNxOverspeed *outC)
{
  /* _L87/, _L90/ */
  kcg_float32 _L87;

  _L87 = freq_100_1 * C_RATIO_PERCENT;
  /* _L40=(ToConfirmCondition#2)/ */
  ToConfirmCondition(
    (kcg_bool)
      ((NTLOS_NGOS_Measure_1 > _L87 * threshold_1) & (NTLOS_NGOS_Measure_1 <
          _L87 * (threshold_1 + K_NTL_NG_OVSTHRESD_Window))),
    K_NTL_NG_OVSTHRESD_N,
    &outC->Context_ToConfirmCondition_2);
  /* _L100= */
  if (outC->Context_ToConfirmCondition_2.confirmed) {
    outC->V_NxxOS1_OVS_Conditions_Met = E_Yes;
  }
  else {
    outC->V_NxxOS1_OVS_Conditions_Met = E_No;
  }
  _L87 = C_RATIO_PERCENT * freq_100_2;
  /* _L15=(ToConfirmCondition#3)/ */
  ToConfirmCondition(
    (kcg_bool)
      ((NTLOS_NGOS_Measure_2 > threshold_2 * _L87) & (NTLOS_NGOS_Measure_2 <
          (K_NTL_NG_OVSTHRESD_Window + threshold_2) * _L87)),
    K_NTL_NG_OVSTHRESD_N,
    &outC->Context_ToConfirmCondition_3);
  /* _L97= */
  if (outC->Context_ToConfirmCondition_3.confirmed) {
    outC->V_NxxOS2_OVS_Conditions_Met = E_Yes;
  }
  else {
    outC->V_NxxOS2_OVS_Conditions_Met = E_No;
  }
  /* _L63= */
  if ((OneSensor_CSSauthorization == E_Authorized) &
    (OVS_OneSensor_NTL_NG_Inhib == E_Not_Inhibited)) {
    outC->NTL_NG_OVERSPEED = outC->Context_ToConfirmCondition_2.confirmed |
      outC->Context_ToConfirmCondition_3.confirmed;
  }
  else {
    outC->NTL_NG_OVERSPEED = outC->Context_ToConfirmCondition_3.confirmed &
      outC->Context_ToConfirmCondition_2.confirmed;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void ToDetectNxOverspeed_init(outC_ToDetectNxOverspeed *outC)
{
  outC->NTL_NG_OVERSPEED = kcg_true;
  outC->V_NxxOS2_OVS_Conditions_Met = E_No;
  outC->V_NxxOS1_OVS_Conditions_Met = E_No;
  /* _L15=(ToConfirmCondition#3)/ */
  ToConfirmCondition_init(&outC->Context_ToConfirmCondition_3);
  /* _L40=(ToConfirmCondition#2)/ */
  ToConfirmCondition_init(&outC->Context_ToConfirmCondition_2);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToDetectNxOverspeed_reset(outC_ToDetectNxOverspeed *outC)
{
  /* _L15=(ToConfirmCondition#3)/ */
  ToConfirmCondition_reset(&outC->Context_ToConfirmCondition_3);
  /* _L40=(ToConfirmCondition#2)/ */
  ToConfirmCondition_reset(&outC->Context_ToConfirmCondition_2);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToDetectNxOverspeed.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

