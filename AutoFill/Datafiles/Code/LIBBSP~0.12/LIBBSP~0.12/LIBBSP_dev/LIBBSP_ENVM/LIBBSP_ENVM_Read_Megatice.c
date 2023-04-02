/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Read_Megatice.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_Read_Megatice(const uint32_t address, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret) /* %RELAX<SYNCHRONe_C_Code_8.18> buffer is output */
{
	volatile uint32_t * p_reg_acc_fifo;
	uint32_t v_index;
	uint32_t v_indexOut;
	uint32_t v_remain;
	uint32_t v_version;
	uint32_t *v_output;

	*v_ret = E_LIBBSP_ENVM_OK;
	p_reg_acc_fifo = (uint32_t *)NULL;
	if (((address % sizeof(uint32_t)) == 0ul)
		&& ((size % sizeof(uint32_t)) == 0ul))
	{
		if ((address + size) <= C_LIBBSP_ENVM_MEGATICE_MAX_SIZE)
		{
			p_reg_acc_fifo = (volatile uint32_t *)((p_ENVM_MEGA_BaseAddress) + C_LIBBSP_ENVM_ACCELERATOR_FIFO_ADDR);
			*v_ret = E_LIBBSP_ENVM_OK;
		}
		else
		{
			*v_ret = E_LIBBSP_ENVM_OVERSIZED;
		}
	}
	else
	{
		*v_ret = E_LIBBSP_ENVM_INVALID_ADDR;
	}
	if (*v_ret == E_LIBBSP_ENVM_OK)
	{
		v_indexOut = 0ul;
		v_output = (uint32_t *) buffer; /* %RELAX<SYNCHRONe_C_Code_11.1> access to buffer is done on 32 bits */
		v_remain = size / sizeof(uint32_t);
		while (v_remain > 0ul)
		{
			v_index = 0ul;
			while((v_index < v_remain) && (v_index < C_LIBBSP_ENVM_FIFO_MAX_SIZE))
			{
				/*Write the addresses to read in the REG_NVM_ACCELERATOR_FIFO*/
				*p_reg_acc_fifo = (address + ((v_indexOut + v_index) * sizeof(uint32_t))) & 0x0FFFFCul;
				asm("mbar");
				v_index++;
			}
			/*Wait at least 500ns by reading the version of the PLD*/
			LIBBSP_PLDMEG_GetVersion(&v_version);
			v_index = 0ul;
			while((v_index < v_remain) && (v_index < C_LIBBSP_ENVM_FIFO_MAX_SIZE))
			{
				/*Retrieve the values to read*/
				v_output[v_indexOut + v_index] = *p_reg_acc_fifo; /* %RELAX<SYNCHRONe_C_Code_17.4> Size of buffer is unknown at compile time */
				asm("mbar");
				v_index++;
			}
			v_indexOut += v_index;
			v_remain -= v_index;
		}
	}
}
