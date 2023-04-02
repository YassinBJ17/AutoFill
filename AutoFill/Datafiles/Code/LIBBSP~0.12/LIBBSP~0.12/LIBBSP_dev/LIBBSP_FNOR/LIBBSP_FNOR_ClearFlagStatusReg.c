/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNOR_ClearFlagStatusReg.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_SPI_ErrorCode LIBBSP_FNOR_ClearFlagStatusReg(const TE_LIBBSP_SPI_Device devID)
{
	TE_LIBBSP_SPI_ErrorCode v_ret;

	if ( (devID == E_LIBBSP_SPI_FLASH_PROGRAM) ||  (devID == E_LIBBSP_SPI_FLASH_BITE) )
	{
		v_ret = LIBBSP_SPI_Exchange(devID, (uint32_t)0, NULL, sizeof(C_FNOR_CFSR), &C_FNOR_CFSR, (uint32_t)0, NULL, E_LIBBSP_SPI_NORMAL_MODE); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: no cast on NULL */
	}
	else
	{
		v_ret = E_LIBBSP_SPI_INVALID_ID;
	}

	return v_ret;

}
/*==== END =============================================================================*/
