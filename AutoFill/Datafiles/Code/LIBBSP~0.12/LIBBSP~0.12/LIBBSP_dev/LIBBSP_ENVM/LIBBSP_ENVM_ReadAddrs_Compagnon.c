/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_ReadAddrs_Compagnon.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_ReadAddrs_Compagnon(const uint32_t * const v_read_add_envm, const uint32_t v_nb_word,
		              		uint32_t * const v_read_data, TE_LIBBSP_ENVM_ErrorCode * const v_ret)
{
	volatile uint32_t * p_reg_acc_fifo;
	volatile TS_LIBBSP_ENVM_SSI_Mode * p_cmp_reg_mode;
	volatile uint32_t * p_cmp_buffer;
	uint32_t v_reg_req_value;
	uint32_t v_index;

	v_index = 0ul;
	*v_ret = E_LIBBSP_ENVM_OK;

	p_reg_acc_fifo = (volatile uint32_t *)(p_ENVM_COMP_BaseAddress + C_LIBBSP_ENVM_ACCELERATOR_FIFO_ADDR);
	p_cmp_buffer = (uint32_t*)p_LCS0_COMP_BaseAddress;
	if (ENVM_OverrideReg.p_SSI_COMP_ReqAddress != (TS_LIBBSP_ENVM_SSI_Mode*)NULL) /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: cast on NULL */
	{
		p_cmp_reg_mode = ENVM_OverrideReg.p_SSI_COMP_ReqAddress;
		v_reg_req_value = ENVM_OverrideReg.v_SSI_COMP_ReqValue;
	}
	else
	{
		p_cmp_reg_mode = (TS_LIBBSP_ENVM_SSI_Mode *)(p_SSI_COMP_BaseAddress + C_LIBBSP_ENVM_SSI_MODEREAD); /* %RELAX<SYNCHRONe_C_Code_10.7> Access to registers */
		v_reg_req_value = 0ul;
	}

	if(v_nb_word > C_ENVM_NB_READ_MAX)
	{
		*v_ret = E_LIBBSP_ENVM_OVERSIZED;
	}
	else
	{
/* {{RELAX<SYNCHRONe_C_Code_17.4> Sizes of v_read_add_envm and v_read_data are unknown at compile time */
		while((v_index < v_nb_word) && (v_read_add_envm[v_index] <= C_ENVM_END_ADDR))
		{
			if (ENVM_OverrideReg.p_SSI_COMP_ReqAddress == (TS_LIBBSP_ENVM_SSI_Mode*)NULL) /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: cast on NULL */
			{
				*v_ret = E_LIBBSP_ENVM_INVALID_ADDR;
				for (v_index=0ul;v_index<ENVM_Compagnon_Map_Size;v_index++)
				{
					if (ENVM_Compagnon_Map[v_index].read != 0ul
					&& 	ENVM_Compagnon_Map[v_index].start <= v_read_add_envm[v_index]
					&&	ENVM_Compagnon_Map[v_index].end > v_read_add_envm[v_index])
					{
						v_reg_req_value = ENVM_Compagnon_Map[v_index].read;
						*v_ret = E_LIBBSP_ENVM_OK;
						break;
					}
				}
			}
			p_cmp_reg_mode->request = v_reg_req_value;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			*p_reg_acc_fifo = v_read_add_envm[v_index];
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			p_cmp_reg_mode->request = C_LIBBSP_ENVM_SSI_MODE_RESET;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_read_data[v_index] = p_cmp_buffer[0];
			asm("mbar");
			v_index++;
		}

		if((v_index < v_nb_word) && (v_read_add_envm[v_index] > C_ENVM_END_ADDR))
		{
			*v_ret = E_LIBBSP_ENVM_INVALID_ADDR;
		}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
	}
}
