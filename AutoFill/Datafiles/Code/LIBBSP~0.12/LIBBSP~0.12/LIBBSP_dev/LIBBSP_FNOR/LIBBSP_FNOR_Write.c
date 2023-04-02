/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_Write.h"



/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Write(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, const uint8_t * const buffer)
{
	/*TE_LIBBSP_SPI_ErrorCode v_Rc;*/
	/*TE_LIBBSP_FNOR_ErrorCode v_Rc_fnor;*/
    TE_LIBBSP_FNOR_ErrorCode v_StatusFlash;
    /*TU_LIBBSP_FNOR_FlashRegister v_Reg;*/
	/*uint32_t v_Timeout;*/
    uint32_t v_CurrentFlashAddress;
    /*uint32_t v_CurrentSpiFlashAddress;*/
    uint32_t v_SizeRemaining;
    /*uint32_t v_NumberOfBlocks;*/
    /*uint32_t v_NumberOfSpiBlocks;*/
    uint32_t v_BlockIndex;
    /*uint32_t v_BlockSpiIndex;*/
    uint32_t v_SizeInFirstBlock;
    /*uint32_t v_SizeInSpiBlock;*/


    v_StatusFlash = E_LIBBSP_FNOR_OK;

	if (flashAddress < C_FNOR_ADDRESS_MIN && flashAddress + size > C_FNOR_ADDRESS_MAX)
	{
		v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;
		return (v_StatusFlash);
	}

	/* Process according page segmentation */
    v_SizeRemaining = size;
    v_CurrentFlashAddress = flashAddress;
    v_BlockIndex = 0ul;
    //v_BlockSpiIndex = 0;
    v_SizeInFirstBlock = 0ul;
    //v_NumberOfBlocks = 0;

	if ( (devID == E_LIBBSP_SPI_FLASH_PROGRAM) ||  (devID == E_LIBBSP_SPI_FLASH_BITE) )
	{

		LIBBSP_FNOR_WriteCheckAvailability(devID, &v_StatusFlash);

		if(v_StatusFlash == E_LIBBSP_FNOR_OK)
		{
			LIBBSP_FNOR_WriteFirstBlock(devID, &v_SizeRemaining, &v_CurrentFlashAddress,
										&v_SizeInFirstBlock, buffer, &v_StatusFlash);
		}

		if(v_StatusFlash == E_LIBBSP_FNOR_OK)
		{
			LIBBSP_FNOR_WriteNextBlock(devID, &v_SizeRemaining, &v_CurrentFlashAddress,
									v_SizeInFirstBlock, &v_BlockIndex, buffer, &v_StatusFlash);
		}

		if(v_StatusFlash == E_LIBBSP_FNOR_OK)
		{
			LIBBSP_FNOR_WriteLastBlock(devID, v_SizeRemaining, v_CurrentFlashAddress,
									v_SizeInFirstBlock, v_BlockIndex, buffer, &v_StatusFlash);
		}
    }
    else
	{
		v_StatusFlash = E_LIBBSP_FNOR_INVALID_ID;
	}

    return v_StatusFlash; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
