/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToInterpolate.h"

/* ToInterpolate/ */
kcg_float32 ToInterpolate(
  /* _L1/, _L19/, _L20/, _x1/, x1/ */
  kcg_float32 x1,
  /* _L2/, x2/ */
  kcg_float32 x2,
  /* _L3/, y1/ */
  kcg_float32 y1,
  /* _L4/, y2/ */
  kcg_float32 y2,
  /* _L5/, x/ */
  kcg_float32 x)
{
  /* _L9/, y_interp/ */
  kcg_float32 y_interp;

  y_interp = (x - x1) / (x2 - x1) * (y2 - y1) + y1;
  return y_interp;
}



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToInterpolate.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

