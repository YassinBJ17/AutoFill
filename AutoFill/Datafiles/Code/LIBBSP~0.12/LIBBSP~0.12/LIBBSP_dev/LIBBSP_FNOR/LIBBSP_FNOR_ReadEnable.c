/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_ReadEnable.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_FNOR_ReadEnable(const TE_LIBBSP_SPI_Device devID, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash)
{
    TE_LIBBSP_SPI_ErrorCode v_Rc;

	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		/* Enable Write */
		v_Rc = LIBBSP_FNOR_EnableWrite(devID);
		if (v_Rc != E_LIBBSP_SPI_OK)
		{
			*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x55*/;
		}
	}
	if(*v_StatusFlash == E_LIBBSP_FNOR_OK)
	{
		/* Exit 4 bytes addressing mode */
		v_Rc = LIBBSP_FNOR_Exit4B(devID);
		if (v_Rc != E_LIBBSP_SPI_OK)
		{
			*v_StatusFlash = E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR /*+0x56*/;
		}
	}

}
/*==== END =============================================================================*/
