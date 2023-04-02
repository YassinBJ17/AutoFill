/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_ReadAddrs.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_ReadAddrs(const TE_LIBBSP_ENVM_Device device, const uint32_t * const v_read_add_envm, const uint32_t v_nb_word,
		              		uint32_t * const v_read_data, TE_LIBBSP_ENVM_ErrorCode * const v_ret) /* %RELAX<SYNCHRONe_C_Code_8.18> v_read_data is output */
{
	if (device == E_LIBBSP_ENVM_MEGATICE)
	{
		LIBBSP_ENVM_ReadAddrs_Megatice(v_read_add_envm, v_nb_word, v_read_data, v_ret);
	}
	else if (device == E_LIBBSP_ENVM_COMPAGNON)
	{
		LIBBSP_ENVM_ReadAddrs_Compagnon(v_read_add_envm, v_nb_word, v_read_data, v_ret);
	}
	else
	{
		*v_ret = E_LIBBSP_ENVM_INVALID_DEVICE;
	}
}
