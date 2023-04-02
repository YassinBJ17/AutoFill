/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PLDCMP_GetCompErrorStatus.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_PLDCMP_GetCompErrorStatus(boolean_t * const v_overload_error,
                                      boolean_t * const v_parity_error,
                                      boolean_t * const v_addr_error,
                                      boolean_t * const v_acc_error,
                                      boolean_t * const v_timeout_error,
                                      uint32_t *  const v_CompErrorStatus)
{
   TU_LIBBSP_PLDCMP_RegValue v_RegValue;

   LIBBSP_PLDCMP_GetCmpErrors(&v_RegValue);
   /*{{RELAX<SYNCHRONe_C_Code_10.7> overload_error, parity_error, addr_error, acc_error and timeout_error are equal to 0 or 1. */
   /* So there is no loss of precision on the conversion to boolean_t.*/
   *v_overload_error = (boolean_t)(v_RegValue.CompErrStatus.overload_error);
   *v_parity_error = (boolean_t)(v_RegValue.CompErrStatus.parity_error);
   *v_addr_error = (boolean_t)(v_RegValue.CompErrStatus.addr_error);
   *v_acc_error = (boolean_t)(v_RegValue.CompErrStatus.acc_error);
   *v_timeout_error = (boolean_t)(v_RegValue.CompErrStatus.timeout_error);
   /*}}RELAX<SYNCHRONe_C_Code_10.7> */
   *v_CompErrorStatus = v_RegValue.v_reg;
}

/*==== END =============================================================================*/
