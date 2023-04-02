/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToCheckStatusSent.h"

/* ToCheckStatusSent/ */
void ToCheckStatusSent(
  /* _L11/, conditionSent/ */
  kcg_bool conditionSent,
  /* _L10/, conditionCurrent/ */
  kcg_bool conditionCurrent,
  /* _L18/, extra_param/ */
  kcg_bool extra_param,
  outC_ToCheckStatusSent *outC)
{
  /* _L13= */
  if (conditionSent) {
    outC->_L13 = conditionCurrent;
  }
  else {
    outC->_L13 = conditionCurrent | (extra_param & ((!outC->init) & outC->_L13));
  }
  outC->init = kcg_false;
  /* _L6= */
  if (outC->_L13) {
    outC->status = E_Yes;
  }
  else {
    outC->status = E_No;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void ToCheckStatusSent_init(outC_ToCheckStatusSent *outC)
{
  outC->init = kcg_true;
  outC->_L13 = kcg_true;
  outC->status = E_No;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToCheckStatusSent_reset(outC_ToCheckStatusSent *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToCheckStatusSent.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

