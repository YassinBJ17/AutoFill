/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Read.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_Read(const TE_LIBBSP_ENVM_Device device, const uint32_t address, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret) /* %RELAX<SYNCHRONe_C_Code_8.18> buffer is output */
{
	if (device == E_LIBBSP_ENVM_MEGATICE)
	{
		LIBBSP_ENVM_Read_Megatice(address, size, buffer, v_ret);
	}
	else if (device == E_LIBBSP_ENVM_COMPAGNON)
	{
		LIBBSP_ENVM_Read_Compagnon(address, size, buffer, v_ret);
	}
	else
	{
		*v_ret = E_LIBBSP_ENVM_INVALID_DEVICE;
	}
}
