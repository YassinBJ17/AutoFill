/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Read_Compagnon.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_Read_Compagnon(const uint32_t address, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret) /* %RELAX<SYNCHRONe_C_Code_8.18> buffer is output */
{
	volatile uint32_t * p_reg_acc_fifo;
	volatile TS_LIBBSP_ENVM_SSI_Mode * p_cmp_reg_mode;
	volatile TS_LIBBSP_ENVM_SSI_Mode * p_cmp_reg_erase;
	volatile uint32_t * p_cmp_buffer;
	uint32_t v_reg_erase_value;
	uint32_t v_reg_read_value;
	uint32_t v_index;
	uint32_t v_indexOut;
	uint32_t v_remain;
	uint32_t *v_output;

	*v_ret = E_LIBBSP_ENVM_OK;
	p_reg_acc_fifo = (uint32_t *)NULL;
	p_cmp_reg_mode = (TS_LIBBSP_ENVM_SSI_Mode *)NULL; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: cast on NULL */
	p_cmp_reg_erase = (TS_LIBBSP_ENVM_SSI_Mode *)NULL; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: cast on NULL */
	p_cmp_buffer = (uint32_t *)NULL;
	v_reg_read_value = 0ul;
	v_reg_erase_value = 0ul;
	if (((address % sizeof(uint32_t)) == 0ul)
		&& ((size % sizeof(uint32_t)) == 0ul))
	{
		p_reg_acc_fifo = (volatile uint32_t *)(p_ENVM_COMP_BaseAddress + C_LIBBSP_ENVM_ACCELERATOR_FIFO_ADDR);
/* {{RELAX<SYNCHRONe_C_Code_10.7> Access to registers */
		p_cmp_reg_mode = (TS_LIBBSP_ENVM_SSI_Mode *)(p_SSI_COMP_BaseAddress + C_LIBBSP_ENVM_SSI_MODEREAD);
		p_cmp_reg_erase = (TS_LIBBSP_ENVM_SSI_Mode *)(p_SSI_COMP_BaseAddress + C_LIBBSP_ENVM_SSI_MODEERASE);
/* }} RELAX<SYNCHRONe_C_Code_10.7> */
		p_cmp_buffer = (uint32_t*)p_LCS0_COMP_BaseAddress;
		*v_ret = E_LIBBSP_ENVM_INVALID_ADDR;
		for (v_index=0ul;v_index<ENVM_Compagnon_Map_Size;v_index++)
		{
			if (ENVM_Compagnon_Map[v_index].read != 0ul
			&& 	ENVM_Compagnon_Map[v_index].start <= address
			&&	ENVM_Compagnon_Map[v_index].end > address
			&& 	ENVM_Compagnon_Map[v_index].start < (address + size)
			&&	ENVM_Compagnon_Map[v_index].end >= (address + size))
			{
				v_reg_read_value = ENVM_Compagnon_Map[v_index].read;
				v_reg_erase_value = ENVM_Compagnon_Map[v_index].erase;
				*v_ret = E_LIBBSP_ENVM_OK;
				break;
			}
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
			p_cmp_reg_mode->request = v_reg_read_value;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_index = 0ul;
			while((v_index < v_remain) && (v_index < C_LIBBSP_ENVM_FIFO_MAX_SIZE))
			{
				/*Write the addresses to read in the REG_NVM_ACCELERATOR_FIFO*/
				*p_reg_acc_fifo = (address + ((v_indexOut + v_index) * sizeof(uint32_t))) & 0x0FFFFCul;
				asm("mbar");
				LIBBSP_CMN_Wait(10ul);
				v_index++;
			}
			p_cmp_reg_mode->request = C_LIBBSP_ENVM_SSI_MODE_RESET;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_index = 0ul;
			while((v_index < v_remain) && (v_index < C_LIBBSP_ENVM_FIFO_MAX_SIZE))
			{
				/*Retrieve the values to read*/
				v_output[v_indexOut + v_index] = p_cmp_buffer[v_index]; /* %RELAX<SYNCHRONe_C_Code_17.4> Size of buffer is unknown at compile time */
				v_index++;
			}
			v_indexOut += v_index;
			v_remain -= v_index;
		}
		if(v_reg_erase_value != 0ul)
		{
			p_cmp_reg_erase->request = v_reg_erase_value;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			p_cmp_reg_erase->request = C_LIBBSP_ENVM_SSI_MODE_RESET;
			asm("mbar");
		}
	}
}
