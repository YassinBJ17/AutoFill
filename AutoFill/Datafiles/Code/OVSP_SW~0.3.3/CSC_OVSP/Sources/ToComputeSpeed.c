/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeSpeed.h"

/* ToComputeSpeed/ */
void ToComputeSpeed(
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
  outC_ToComputeSpeed *outC)
{
  kcg_uint32 tmp;
  kcg_uint32 tmp1;
  /* _L185/ */
  kcg_bool _L185;
  /* _L144/ */
  kcg_int32 _L144;
  /* _L141/ */
  kcg_int32 _L141;
  /* _L132/ */
  kcg_bool _L132;
  /* _L124/ */
  kcg_uint32 _L124;
  /* _L117/ */
  kcg_float32 _L117;
  /* _L44/ */
  kcg_float32 _L44;
  /* _L43/ */
  kcg_uint32 _L43;

  /* _L150= */
  if ((!outC->init) & outC->_L138) {
    tmp = C_ONE;
  }
  else /* _L123= */
  if (outC->init) {
    tmp = kcg_lit_uint32(0);
  }
  else {
    tmp = outC->_L130;
  }
  _L124 = tmp + nb_of_acquired_edges;
  _L141 = /* _L139= */(kcg_int32) lastFallingEdgeArrayIndex -
    /* _L140= */(kcg_int32) K_NTLOS_NGOS_NH_NL;
  /* _L144= */
  if (_L141 >= C_ZERO_INT) {
    _L144 = _L141;
  }
  else {
    _L144 = _L141 + kcg_lit_int32(101);
  }
  if (lastFallingEdgeArrayIndex < kcg_lit_uint32(101)) {
    tmp = (*arrayOfFallingEdgesTimeStamps)[lastFallingEdgeArrayIndex];
  }
  else {
    tmp = kcg_lit_uint32(0);
  }
  if ((kcg_lit_int32(0) <= _L144) & (_L144 < kcg_lit_int32(101))) {
    tmp1 = (*arrayOfFallingEdgesTimeStamps)[_L144];
  }
  else {
    tmp1 = kcg_lit_uint32(0);
  }
  _L43 = tmp - tmp1;
  /* _L249= */
  if (_L43 != kcg_lit_uint32(0)) {
    tmp = _L43;
  }
  else {
    tmp = kcg_lit_uint32(1);
  }
  _L44 = C_FLEX_TIMER_FREQ_HZ * /* _L67= */(kcg_float32) K_NTLOS_NGOS_NH_NL /
    /* _L66= */(kcg_float32) tmp;
  _L117 = timeout_ms * C_RATIO_MS_TO_S;
  /* _L130= */
  if (_L124 > C_NH_NL_MAX) {
    outC->_L130 = C_NH_NL_MAX;
  }
  else {
    outC->_L130 = _L124;
  }
  _L132 = (outC->_L130 <= K_NTLOS_NGOS_NH_NL) | (_L117 < kcg_lit_float32(1.) /
      _L44);
  outC->_L138 = !_L132;
  /* _L229=(ToCheckStatusSent#Updated)/ */
  ToCheckStatusSent(
    isStatusSent,
    outC->_L138,
    kcg_true,
    &outC->Context_ToCheckStatusSent_Updated);
  outC->Updated = outC->Context_ToCheckStatusSent_Updated.status;
  /* _L188= */
  if (outC->_L138) {
    outC->_L188 = kcg_lit_uint32(0);
  }
  else /* _L183= */
  if (outC->init) {
    outC->_L188 = kcg_lit_uint32(0) + kcg_lit_uint32(1);
  }
  else {
    outC->_L188 = outC->_L188 + kcg_lit_uint32(1);
  }
  _L185 = /* _L194= */(kcg_float32) outC->_L188 > _L117 / C_RTC_PERIOD;
  /* _L225=(ToCheckStatusSent#OutOfTime)/ */
  ToCheckStatusSent(
    isStatusSent,
    _L185,
    _L132,
    &outC->_1_Context_ToCheckStatusSent_OutOfTime);
  outC->OutOfTime = outC->_1_Context_ToCheckStatusSent_OutOfTime.status;
  /* _L80= */
  if (_L185) {
    outC->NTLOS_NGOS_Measure = C_FREQUENCY_ZERO;
  }
  else /* _L233= */
  if (outC->_L138) {
    outC->NTLOS_NGOS_Measure = _L44;
  }
  else /* _L230= */
  if (outC->init) {
    outC->NTLOS_NGOS_Measure = C_FREQUENCY_ZERO;
  }
  outC->init = kcg_false;
  /* _L223=(ToCheckStatusSent#OutOfHigh)/ */
  ToCheckStatusSent(
    isStatusSent,
    (kcg_bool) (outC->_L138 & (outC->NTLOS_NGOS_Measure > C_FREQUENCY_HIGH_HZ)),
    kcg_true,
    &outC->Context_ToCheckStatusSent_OutOfHigh);
  outC->OutOfHigh = outC->Context_ToCheckStatusSent_OutOfHigh.status;
}

#ifndef KCG_USER_DEFINED_INIT
void ToComputeSpeed_init(outC_ToComputeSpeed *outC)
{
  outC->_L138 = kcg_true;
  outC->init = kcg_true;
  outC->_L130 = kcg_lit_uint32(0);
  outC->_L188 = kcg_lit_uint32(0);
  outC->Updated = E_No;
  outC->OutOfHigh = E_No;
  outC->OutOfTime = E_No;
  outC->NTLOS_NGOS_Measure = kcg_lit_float32(0.0);
  /* _L223=(ToCheckStatusSent#OutOfHigh)/ */
  ToCheckStatusSent_init(&outC->Context_ToCheckStatusSent_OutOfHigh);
  /* _L225=(ToCheckStatusSent#OutOfTime)/ */
  ToCheckStatusSent_init(&outC->_1_Context_ToCheckStatusSent_OutOfTime);
  /* _L229=(ToCheckStatusSent#Updated)/ */
  ToCheckStatusSent_init(&outC->Context_ToCheckStatusSent_Updated);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToComputeSpeed_reset(outC_ToComputeSpeed *outC)
{
  outC->init = kcg_true;
  /* _L223=(ToCheckStatusSent#OutOfHigh)/ */
  ToCheckStatusSent_reset(&outC->Context_ToCheckStatusSent_OutOfHigh);
  /* _L225=(ToCheckStatusSent#OutOfTime)/ */
  ToCheckStatusSent_reset(&outC->_1_Context_ToCheckStatusSent_OutOfTime);
  /* _L229=(ToCheckStatusSent#Updated)/ */
  ToCheckStatusSent_reset(&outC->Context_ToCheckStatusSent_Updated);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeSpeed.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

