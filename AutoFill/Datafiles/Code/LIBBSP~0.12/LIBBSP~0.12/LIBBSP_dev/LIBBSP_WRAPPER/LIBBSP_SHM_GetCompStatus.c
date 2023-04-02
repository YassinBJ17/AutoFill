/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SHM_GetCompStatus.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SHM_GetCompStatus(TS_LIBBSP_SHM_CompStatus * const CompStatus, uint32_t * const v_regValue)
{
   TU_LIBBSP_SHM_RegValue v_RegValue;
   
   LIBBSP_SHM_GetStatus(E_LIBBSP_SHM_COMP_STATUS, &v_RegValue);
   
   CompStatus->wd_failure_cnt =
      (kcg_uint8) LIBBSPP_WRAPPER_ConvertUint32ToUint8(v_RegValue.v_CompBitField.wd_failure_cnt);
   CompStatus->sw_reset_request_cnt =
      (kcg_uint8) LIBBSPP_WRAPPER_ConvertUint32ToUint8(v_RegValue.v_CompBitField.sw_reset_request_cnt);
   CompStatus->hw_reset_request_cnt =
      (kcg_uint8) LIBBSPP_WRAPPER_ConvertUint32ToUint8(v_RegValue.v_CompBitField.hw_reset_request_cnt);
   CompStatus->critical_uvd_cnt =
      (kcg_uint8) LIBBSPP_WRAPPER_ConvertUint32ToUint8(v_RegValue.v_CompBitField.critical_uvd_cnt);
   
   *v_regValue = v_RegValue.v_data;
}

/*==== END =============================================================================*/
