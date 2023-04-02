/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_WriteFirstBlock.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_FNOR_WriteFirstBlock( const TE_LIBBSP_SPI_Device devID, uint32_t * const v_SizeRemaining, uint32_t * const v_CurrentFlashAddress,
		                           uint32_t * const v_SizeInFirstBlock, const uint8_t * const buffer, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
	TE_LIBBSP_FNOR_ErrorCode v_Rc_fnor;

	/* Process first block */
	/* Size remaining into a page */

	// v_SizeInFirstBlock is assumed to be upper than 0
	*v_SizeInFirstBlock = C_FNOR_PAGE_SIZE - (*v_CurrentFlashAddress&C_FNOR_MASK_FIRST_MSB_BYTE) ;

	/* Total data to write also finishes in the 1st page */
	if (*v_SizeInFirstBlock > *v_SizeRemaining)
	{
		*v_SizeInFirstBlock = *v_SizeRemaining;
	}

	if (*v_SizeInFirstBlock > 0ul)
	{
		v_Rc_fnor = LIBBSP_FNOR_WritePage(devID, *v_CurrentFlashAddress, *v_SizeInFirstBlock, buffer);
		if (v_Rc_fnor != E_LIBBSP_FNOR_OK)
		{
			*v_StatusFlash = v_Rc_fnor;
		}
	}

	*v_CurrentFlashAddress += *v_SizeInFirstBlock;
	*v_SizeRemaining -= *v_SizeInFirstBlock;

}
/*==== END =============================================================================*/
