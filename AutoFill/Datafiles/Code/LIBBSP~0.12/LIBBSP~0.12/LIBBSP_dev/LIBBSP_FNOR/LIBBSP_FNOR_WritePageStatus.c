/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_WritePageStatus.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/* const uint32_t C_FNOR_TIMEOUT = 1000; */
/*==== Services ========================================================================*/

void LIBBSP_FNOR_WritePageStatus(const TE_LIBBSP_SPI_Device devID, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
	TE_LIBBSP_SPI_ErrorCode v_Rc;
	TU_LIBBSP_FNOR_FlashRegister v_Reg;

	v_Reg.R = (uint8_t)0;

	/* Read Flag Status Register  */
	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		V_FNOR_WriteBuffer[0] = (uint8_t)E_LIBBSP_FNOR_RFSR; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum max value in range of uint8 */
		v_Rc = LIBBSP_SPI_Exchange(devID, 1ul, (uint8_t*)&v_Reg.R, 1ul, (uint8_t*)V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.2> possible lose of precision */
		if (v_Rc != E_LIBBSP_SPI_OK)
		{
			*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x66;*/
		}
	}

	/* Verify program command */
	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		if (v_Reg.FLAGSTATUS.PG == (uint8_t)1)
		{
			*v_StatusFlash = E_LIBBSP_FNOR_WRITE_ERROR;
		}
	}
	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		if (v_Reg.FLAGSTATUS.PROT == (uint8_t)1)
		{
			*v_StatusFlash = E_LIBBSP_FNOR_PROTECTION_ERROR;
		}
	}


	/* Exit 4 bytes addressing mode */
	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		v_Rc = LIBBSP_FNOR_Exit4B(devID);
		if (v_Rc != E_LIBBSP_SPI_OK)
		{
			*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR/*+0x67*/;
		}
	}


}
/*==== END =============================================================================*/
