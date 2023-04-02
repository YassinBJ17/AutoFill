/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Close.h"

/*==== Definitions =====================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_ENVM_ErrorCode LIBBSP_ENVM_Close(const TE_LIBBSP_ENVM_Device device)
{
	TE_LIBBSP_ENVM_ErrorCode v_ret;

	if (device == E_LIBBSP_ENVM_MEGATICE)
	{
		LIBBSP_PLDMEG_SetHpmsReset(TRUE);
		v_ret = E_LIBBSP_ENVM_OK;
	}
	else if (device == E_LIBBSP_ENVM_COMPAGNON)
	{
		
		LIBBSP_PLDCMP_SetHpmsReset(FALSE);
		v_ret = E_LIBBSP_ENVM_OK;
	}
	else
	{
		v_ret = E_LIBBSP_ENVM_INVALID_DEVICE;
	}

	return (v_ret);
}
