/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_ReadPageSeg.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

void LIBBSP_FNOR_ReadPageSeg(const TE_LIBBSP_SPI_Device devID,
                             const uint32_t flashAddress,
                             const uint32_t size,
                             uint8_t * const buffer,  /* %RELAX<SYNCHRONe_C_Code_8.18> Output only used by subfunction not detected as subfunction */
                             TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash,
                             const boolean_t fastRead)
{
    uint32_t v_CurrentFlashAddress;
    uint32_t v_SizeRemaining;
    uint32_t v_NumberOfBlocks;
    uint32_t v_BlockIndex;
    TE_LIBBSP_SPI_ErrorCode v_Rc;

/* Process according page segmentation */
	v_SizeRemaining = size;
	v_CurrentFlashAddress = flashAddress;
	v_BlockIndex = 0ul;

	/* Process beginning blocks */
	if (v_SizeRemaining > (uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE)
	{
		v_NumberOfBlocks = v_SizeRemaining / (uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE;
		v_SizeRemaining = v_SizeRemaining % (uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE;
		for (v_BlockIndex = 0ul; v_BlockIndex < v_NumberOfBlocks; v_BlockIndex++)
		{
		   /* {{RELAX<SYNCHRONe_C_Code_10.7> possible lose of precision */
			if (fastRead)
			{
				/* Prepare block read command */
				LIBBSP_FNOR_PrepareCommand((uint8_t)E_LIBBSP_FNOR_DUALREAD, v_CurrentFlashAddress);
				/* Send read command */
				v_Rc = LIBBSP_SPI_Exchange(devID, (uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE, (uint8_t*)&buffer[v_BlockIndex*(uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE],
						C_FNOR_EXCHANGE_SIZE_OUT, (uint8_t*)V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_DUAL_MODE);
			}
			else
			{
				/* Prepare block read command */
				LIBBSP_FNOR_PrepareCommand((uint8_t)E_LIBBSP_FNOR_READ, v_CurrentFlashAddress);
				/* Send read command */
				v_Rc = LIBBSP_SPI_Exchange(devID, (uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE, (uint8_t*)&buffer[v_BlockIndex*(uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE],
						C_FNOR_EXCHANGE_SIZE_OUT, (uint8_t*)V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE);
			}
			 /* }} RELAX<SYNCHRONe_C_Code_10.7> */
			if (v_Rc != E_LIBBSP_SPI_OK)
			{
				*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x52;*/
				break;
			}
			v_CurrentFlashAddress += (uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE;
		}
	}

	/* Process last block */
	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		if (v_SizeRemaining > 0ul)
		{
		   /* {{RELAX<SYNCHRONe_C_Code_10.7> possible lose of precision */
			if (fastRead)
			{
				/* Prepare block read comand */
				LIBBSP_FNOR_PrepareCommand((uint8_t)E_LIBBSP_FNOR_DUALREAD, v_CurrentFlashAddress);

				/* Send read command */
				v_Rc = LIBBSP_SPI_Exchange(devID, v_SizeRemaining, (uint8_t*)(&buffer[v_BlockIndex*(uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE]),
						C_FNOR_EXCHANGE_SIZE_OUT, (uint8_t*)V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_DUAL_MODE);
			}
			else
			{
				/* Prepare block read comand */
				LIBBSP_FNOR_PrepareCommand((uint8_t)E_LIBBSP_FNOR_READ, v_CurrentFlashAddress);

				/* Send read command */
				v_Rc = LIBBSP_SPI_Exchange(devID, v_SizeRemaining, (uint8_t*)(&buffer[v_BlockIndex*(uint32_t)C_FNOR_SPI_TRANSMISSION_MAXSIZE]),
						C_FNOR_EXCHANGE_SIZE_OUT, (uint8_t*)V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE);
			}
			/* }} RELAX<SYNCHRONe_C_Code_10.7> */
			if (v_Rc != E_LIBBSP_SPI_OK)
			{
				*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x54;*/
			}
		}
	}
}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
