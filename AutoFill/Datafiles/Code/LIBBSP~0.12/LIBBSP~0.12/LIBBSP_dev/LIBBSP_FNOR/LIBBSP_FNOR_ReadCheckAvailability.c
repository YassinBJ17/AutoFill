/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_ReadCheckAvailability.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_FNOR_ReadCheckAvailability(const TE_LIBBSP_SPI_Device devID, TE_LIBBSP_SPI_ErrorCode * const v_Rc, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
    TU_LIBBSP_FNOR_FlashRegister v_Reg;
	uint32_t v_Timeout;


	v_Timeout = 1ul; /* us ms */
	do {
		/* Read Status Register  */
		V_FNOR_WriteBuffer[0] = (uint8_t)E_LIBBSP_FNOR_RDSR; /* %RELAX<SYNCHRONe_C_Code_10.7> Enum max value in range of uint8 */
		*v_Rc = LIBBSP_SPI_Exchange(devID, 1ul, (uint8_t*)&v_Reg.R, 1ul, (uint8_t*)V_FNOR_WriteBuffer, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.2> posible lose of precision */
		if (*v_Rc != E_LIBBSP_SPI_OK)
		{
			*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR;/*+0x65;*/
			break;
		}
		if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
		{
			*v_StatusFlash = E_LIBBSP_FNOR_NOT_AVAILABLE_FOR_READ;
			break;
		}
	} while (v_Reg.STATUS.WIP != (uint8_t)0);

}
/*==== END =============================================================================*/
