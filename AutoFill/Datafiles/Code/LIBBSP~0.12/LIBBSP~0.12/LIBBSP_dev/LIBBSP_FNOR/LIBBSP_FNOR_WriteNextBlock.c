/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_WriteNextBlock.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */
void LIBBSP_FNOR_WriteNextBlock(const TE_LIBBSP_SPI_Device devID, uint32_t * const v_SizeRemaining, uint32_t * const v_CurrentFlashAddress,
		                        const uint32_t v_SizeInFirstBlock, uint32_t *const v_BlockIndForLast, const uint8_t * const buffer, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
	uint32_t v_NumberOfBlocks;
	uint32_t v_BlockIndex;
	uint32_t v_SizeInSpiBlock;
	TE_LIBBSP_FNOR_ErrorCode v_Rc_fnor;

    if (*v_SizeRemaining > C_FNOR_PAGE_SIZE)
    {
        v_NumberOfBlocks = *v_SizeRemaining / C_FNOR_PAGE_SIZE;
        *v_SizeRemaining = *v_SizeRemaining % C_FNOR_PAGE_SIZE;

        for (v_BlockIndex=0ul; v_BlockIndex < v_NumberOfBlocks; v_BlockIndex++)
        {
            v_SizeInSpiBlock = C_FNOR_PAGE_SIZE;

            v_Rc_fnor = LIBBSP_FNOR_WritePage(devID, *v_CurrentFlashAddress, v_SizeInSpiBlock, &buffer[v_SizeInFirstBlock+(v_BlockIndex*C_FNOR_PAGE_SIZE)]);
            if (v_Rc_fnor != E_LIBBSP_FNOR_OK)
            {
                *v_StatusFlash = v_Rc_fnor;
            }

            *v_CurrentFlashAddress += C_FNOR_PAGE_SIZE;
        }

        *v_BlockIndForLast = v_BlockIndex;
    }

}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
