/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToComputeOSARM_H_
#define _ToComputeOSARM_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ToComputeOSARM/ */
extern TE_Cmd_Status ToComputeOSARM(
  /* V_CAN_OSARM_Request/, _L5/ */
  TE_Request V_CAN_OSARM_Request,
  /* V_CBIT_Result/, _L55/ */
  TE_Test_Result V_CBIT_Result,
  /* V_OVSP_Side_Id/ */
  TE_OVSP_Side V_OVSP_Side_Id,
  /* V_CAM_HS_Current/ */
  kcg_float32 V_CAM_HS_Current,
  /* V_CAM_LS_Current/ */
  kcg_float32 V_CAM_LS_Current,
  /* V_Engine_SpeedLevel/ */
  TE_Speed_Level V_Engine_SpeedLevel,
  /* IfBlock2:, isTriggeredTestEnabled/ */
  kcg_bool isTriggeredTestEnabled);



#endif /* _ToComputeOSARM_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeOSARM.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

