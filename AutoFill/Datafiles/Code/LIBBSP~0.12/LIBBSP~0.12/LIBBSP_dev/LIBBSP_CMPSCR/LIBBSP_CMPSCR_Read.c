/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_CMPSCR_Read.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_CMPSCR_Read(const TE_LIBBSP_CMPSCR_Register v_CMPSCR_reg, uint32_t * const v_ReadValue)
{


	*v_ReadValue = V_CmpScratchRegs->REG_SCRATCH[v_CMPSCR_reg];

}

/*==== END =============================================================================*/
