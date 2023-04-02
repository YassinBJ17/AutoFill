/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToComputeSpeedLevel_H_
#define _ToComputeSpeedLevel_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ToComputeSpeedLevel/ */
extern TE_Speed_Level ToComputeSpeedLevel(
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
  kcg_bool NG_overspeed);



#endif /* _ToComputeSpeedLevel_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeSpeedLevel.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

