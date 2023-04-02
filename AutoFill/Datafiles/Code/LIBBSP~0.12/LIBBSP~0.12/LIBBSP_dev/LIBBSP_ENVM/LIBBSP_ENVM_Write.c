/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Write.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_Write(const TE_LIBBSP_ENVM_Device device, const uint32_t address, const uint32_t size, const uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret)
{
	uint32_t v_size0;
	uint32_t v_size1;
	uint32_t v_start;

	*v_ret = E_LIBBSP_ENVM_OK;

	if (device == E_LIBBSP_ENVM_MEGATICE)
	{
		if ((address + size) <= C_LIBBSP_ENVM_MEGATICE_MAX_SIZE)
		{
			if (address < C_ENVM_NVM_PIVOT)
			{
				v_start = C_ENVM_NVM_PIVOT;
				v_size0 = C_ENVM_NVM_PIVOT - address;
				if (size < v_size0)
				{
					v_size0 = size;
					v_size1 = 0ul;
				}
				else
				{
					v_size1 = size - v_size0;
				}
				LIBBSP_ENVM_Write_Megatice(address, v_size0, buffer, v_ret);
			}
			else
			{
				v_start = address;
				v_size0 = 0ul;
				v_size1 = size;
			}
			
			if ((*v_ret == E_LIBBSP_ENVM_OK) && (v_size1 > 0ul))
			{
				LIBBSP_ENVM_Write_Megatice(v_start, v_size1, &buffer[v_size0], v_ret); /* %RELAX<SYNCHRONe_C_Code_17.4> Size of buffer is unkonwn at compile time */
			}
		}
		else
		{
			*v_ret = E_LIBBSP_ENVM_OVERSIZED;
		}
	}
	else if (device == E_LIBBSP_ENVM_COMPAGNON)
	{
		LIBBSP_ENVM_Write_Compagnon(address, size, buffer, v_ret);
	}
	else
	{
		*v_ret = E_LIBBSP_ENVM_INVALID_DEVICE;
	}
}
