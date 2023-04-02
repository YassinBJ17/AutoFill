/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_PrepareWritePage.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/*==== Services ========================================================================*/

void LIBBSP_FNOR_PrepareWritePage(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, const uint8_t * const buffer, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
	TE_LIBBSP_SPI_ErrorCode v_Rc;
	uint32_t v_Timeout;
	TU_LIBBSP_FNOR_FlashRegister v_Reg;

	v_Reg.R = (uint8_t)0;


	/* Prepare block program command */
	LIBBSP_FNOR_PrepareCommand((uint8_t)E_LIBBSP_FNOR_PAGEP, flashAddress); /* %RELAX<SYNCHRONe_C_Code_10.7> enum field on 8 bits , no loss of precision */

	/* Send program command */
	v_Rc = LIBBSP_SPI_Exchange(devID, 0ul, (uint8_t*)0, C_FNOR_EXCHANGE_SIZE_OUT, (uint8_t*)V_FNOR_WriteBuffer, size, buffer, E_LIBBSP_SPI_NORMAL_MODE);
	if (v_Rc != E_LIBBSP_SPI_OK)
	{
		*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x64;*/
	}

	/* Wait end of program */
	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		v_Timeout = C_FNOR_TIMEOUT; /* 10 ms */
		do {
			/* Read Status Register  */
			V_FNOR_WriteBuffer[0] = (uint8_t)E_LIBBSP_FNOR_RDSR; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum max value in range of uint8 */
			v_Rc = LIBBSP_SPI_Exchange(devID, 1ul, (uint8_t*)&v_Reg.R, 1ul, (uint8_t*)V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.2> possible lose of precision */
			if (v_Rc != E_LIBBSP_SPI_OK)
			{
				*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x65;*/
				break;
			}
			if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
			{
				*v_StatusFlash = E_LIBBSP_FNOR_TIMEOUT_ERROR;
				break;
			}
		} while (v_Reg.STATUS.WIP != (uint8_t)0);
	}

}
/*==== END =============================================================================*/
