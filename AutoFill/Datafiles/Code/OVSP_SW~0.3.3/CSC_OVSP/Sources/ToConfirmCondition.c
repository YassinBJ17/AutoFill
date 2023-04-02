/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToConfirmCondition.h"

/* ToConfirmCondition/ */
void ToConfirmCondition(
  /* _L1/, toBeConfirmedCountTimes/ */
  kcg_bool toBeConfirmedCountTimes,
  /* _L15/, count/ */
  kcg_uint32 count,
  outC_ToConfirmCondition *outC)
{
  /* _L16/, _L2/ */
  kcg_bool _L16;
  /* _L17/ */
  kcg_bool _L17;
  /* _L18/ */
  kcg_bool _L18;
  /* _L21/ */
  kcg_bool _L21;
  /* _L10/ */
  kcg_bool _L10;

  _L10 = outC->_L10;
  _L16 = outC->_L2;
  outC->_L2 = (!outC->init) & outC->mem_toBeConfirmedCountTimes;
  outC->mem_toBeConfirmedCountTimes = toBeConfirmedCountTimes;
  _L21 = toBeConfirmedCountTimes & outC->_L2;
  outC->_L10 = (!outC->init) & outC->_L7;
  outC->_L7 = (!outC->init) & outC->_L5;
  outC->_L5 = (!outC->init) & _L16;
  _L16 = _L21 & outC->_L5;
  _L17 = _L16 & outC->_L7;
  _L18 = _L17 & outC->_L10;
  /* _L14= */
  switch (count) {
    case kcg_lit_uint32(1) :
      outC->confirmed = _L21;
      break;
    case kcg_lit_uint32(2) :
      outC->confirmed = _L16;
      break;
    case kcg_lit_uint32(3) :
      outC->confirmed = _L17;
      break;
    case kcg_lit_uint32(4) :
      outC->confirmed = _L18;
      break;
    default :
      outC->confirmed = _L18 & ((!outC->init) & _L10);
      break;
  }
  outC->init = kcg_false;
}

#ifndef KCG_USER_DEFINED_INIT
void ToConfirmCondition_init(outC_ToConfirmCondition *outC)
{
  outC->confirmed = kcg_true;
  outC->mem_toBeConfirmedCountTimes = kcg_true;
  outC->init = kcg_true;
  outC->_L2 = kcg_true;
  outC->_L5 = kcg_true;
  outC->_L7 = kcg_true;
  outC->_L10 = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToConfirmCondition_reset(outC_ToConfirmCondition *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToConfirmCondition.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

