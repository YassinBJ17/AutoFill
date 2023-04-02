/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_WriteLastBlock.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

void LIBBSP_FNOR_WriteLastBlock(const TE_LIBBSP_SPI_Device devID, const uint32_t v_SizeRemaining, const uint32_t v_CurrentFlashAddress,
		                        const uint32_t v_SizeInFirstBlock, const uint32_t v_BlockIndex, const uint8_t * const buffer, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
	TE_LIBBSP_FNOR_ErrorCode v_Rc_fnor;

    /* Process last block */
	if (v_SizeRemaining > 0ul)
	{
		v_Rc_fnor = LIBBSP_FNOR_WritePage(devID, v_CurrentFlashAddress, v_SizeRemaining, &buffer[v_SizeInFirstBlock+(v_BlockIndex*C_FNOR_PAGE_SIZE)]);
		if (v_Rc_fnor != E_LIBBSP_FNOR_OK)
		{
			*v_StatusFlash = v_Rc_fnor;
		}

	}

}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
