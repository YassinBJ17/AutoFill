/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeSpeedLevel.h"

/* ToComputeSpeedLevel/ */
TE_Speed_Level ToComputeSpeedLevel(
  /* V_NTLOS1_Measure/, _L1/ */
  kcg_float32 V_NTLOS1_Measure,
  /* V_NTLOS2_Measure/, _L2/ */
  kcg_float32 V_NTLOS2_Measure,
  /* V_NTLOS1_100/, _L11/ */
  kcg_float32 V_NTLOS1_100,
  /* V_NTLOS2_100/, _L12/ */
  kcg_float32 V_NTLOS2_100,
  /* NTL_overspeed/, _L10/ */
  kcg_bool NTL_overspeed,
  /* NG_overspeed/, _L9/ */
  kcg_bool NG_overspeed)
{
  /* _L7/, level/ */
  TE_Speed_Level level;

  /* _L7= */
  if (NG_overspeed | NTL_overspeed) {
    level = E_Overspeed;
  }
  else /* _L8= */
  if ((V_NTLOS1_Measure < V_NTLOS1_100 * C_RATIO_SPEED_LEVEL) &
    (V_NTLOS2_Measure < V_NTLOS2_100 * C_RATIO_SPEED_LEVEL)) {
    level = E_Low_Speed;
  }
  else {
    level = E_Running_Speed;
  }
  return level;
}



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeSpeedLevel.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

