/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToSelectInterpolation.h"

/* ToSelectInterpolation/ */
kcg_bool ToSelectInterpolation(
  /* _L14/, x1/ */
  kcg_float32 x1,
  /* _L15/, x2/ */
  kcg_float32 x2,
  /* _L10/, _L11/, x/ */
  kcg_float32 x)
{
  /* _L12/, test/ */
  kcg_bool test;

  test = (x >= x1) & (x < x2);
  return test;
}



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToSelectInterpolation.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

