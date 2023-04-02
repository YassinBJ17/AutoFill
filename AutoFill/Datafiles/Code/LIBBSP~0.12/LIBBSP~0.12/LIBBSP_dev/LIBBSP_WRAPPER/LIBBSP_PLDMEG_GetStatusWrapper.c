/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PLDMEG_GetStatusWrapper.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_PLDMEG_GetStatusWrapper(boolean_t * const seu_mbu_err,
                                    TS_LIBBSP_PLDMEG_IfCpuStatus * const cpu_if_err,
                                    boolean_t * const elbc_parity_error,
                                    uint32_t * const p_global_status,
                                    uint32_t * const p_if_cpu_status,
                                    uint32_t * const p_envm_status,
                                    uint32_t * const p_ida_status,
                                    uint32_t * const p_cnt_correctable_error)
{
   TU_LIBBSP_PLDMEG_RegValue v_RegValue_global_status;
   TU_LIBBSP_PLDMEG_RegValue v_RegValue_if_cpu_status;
   TU_LIBBSP_PLDMEG_RegValue v_RegValue_reg_envm_status;
   TU_LIBBSP_PLDMEG_RegValue v_RegValue_ida_status;
   TU_LIBBSP_PLDMEG_RegValue v_RegValue_cnt_correctable_error;
   
   
   LIBBSP_PLDMEG_GetStatus(E_LIBBSP_PLDMEG_GLOBAL_STATUS, &v_RegValue_global_status);
   LIBBSP_PLDMEG_GetStatus(E_LIBBSP_PLDMEG_IF_CPU_STATUS, &v_RegValue_if_cpu_status);
   LIBBSP_PLDMEG_GetStatus(E_LIBBSP_PLDMEG_ENVM_STATUS, &v_RegValue_reg_envm_status);
   LIBBSP_PLDMEG_GetStatus(E_LIBBSP_PLDMEG_IDA_STATUS, &v_RegValue_ida_status);
   LIBBSP_PLDMEG_GetStatus(E_LIBBSP_PLDMEG_CNT_CORRECTABLE_ERROR, &v_RegValue_cnt_correctable_error);
   *seu_mbu_err = (boolean_t) 0ul;
   if ( v_RegValue_global_status.GlobalStatus.seu_mbu_err != 0ul )
   {
      *seu_mbu_err = (boolean_t) 1ul;
   }
   *p_cnt_correctable_error = v_RegValue_cnt_correctable_error.CNT_CORRECTABLE_ERROR.cnt_correctable_error;

   /* >RELAX<SYNCHRONe_C_Code_10.7> parity_error is equal to 0 or 1 so there is no loss of precision on the conversion to boolean_t. */
   *elbc_parity_error = (boolean_t)(v_RegValue_if_cpu_status.IfCpuStatus.parity_error);
   
   *p_global_status = v_RegValue_global_status.v_reg;
   *p_if_cpu_status = v_RegValue_if_cpu_status.v_reg;
   *p_envm_status = v_RegValue_reg_envm_status.v_reg;
   *p_ida_status = v_RegValue_ida_status.v_reg;
   /* {{RELAX<SYNCHRONe_C_Code_10.2, SYNCHRONe_C_Code_10.7> No precision lost: boolean values*/
   cpu_if_err->parity_error = v_RegValue_if_cpu_status.IfCpuStatus.parity_error;
   cpu_if_err->addr_error = v_RegValue_if_cpu_status.IfCpuStatus.addr_error;
   cpu_if_err->acc_error = v_RegValue_if_cpu_status.IfCpuStatus.acc_error;
   cpu_if_err->timeout_error = v_RegValue_if_cpu_status.IfCpuStatus.timeout_error;
   cpu_if_err->overload_error = v_RegValue_if_cpu_status.IfCpuStatus.overload_error;
   /* }} RELAX<SYNCHRONe_C_Code_10.2, SYNCHRONe_C_Code_10.7> */
   cpu_if_err->error_counter =
      (kcg_uint8) LIBBSPP_WRAPPER_ConvertUint32ToUint8(v_RegValue_if_cpu_status.IfCpuStatus.error_counter);
}

/*==== END =============================================================================*/
