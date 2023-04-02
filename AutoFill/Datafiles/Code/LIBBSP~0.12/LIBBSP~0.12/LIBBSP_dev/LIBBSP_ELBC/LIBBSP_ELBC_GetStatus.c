/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ELBC_GetStatus.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

boolean_t LIBBSP_ELBC_GetStatus(void)
{
	boolean_t v_ParityEccError;
	volatile uint32_t* pt_reg_LTESR;

	/* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> Operation on adress */
	pt_reg_LTESR = (volatile uint32_t *)(V_ELBC_Interface);
	/* }} RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> */

	/*Get the parity ecc error bit*/
	v_ParityEccError = (boolean_t)(((*pt_reg_LTESR) & C_ELBC_MASK_LTESR_PAR) >> C_ELBC_SHIFT_LTESR_PAR);

	/* Clear the parity ecc error bit*/
	*pt_reg_LTESR = (*pt_reg_LTESR) | C_ELBC_MASK_LTESR_PAR;

	return v_ParityEccError;
}

/*==== END =============================================================================*/
