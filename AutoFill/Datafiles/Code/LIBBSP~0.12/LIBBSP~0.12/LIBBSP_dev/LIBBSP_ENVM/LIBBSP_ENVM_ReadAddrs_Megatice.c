/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_ReadAddrs_Megatice.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_ReadAddrs_Megatice(const uint32_t * const v_read_add_envm, const uint32_t v_nb_word,
							uint32_t * const v_read_data, TE_LIBBSP_ENVM_ErrorCode * const v_ret)
{
	volatile uint32_t * p_reg_acc_fifo;
	uint32_t v_index;
	uint32_t v_version;

	v_index = 0ul;
	*v_ret = E_LIBBSP_ENVM_OK;

	p_reg_acc_fifo = (volatile uint32_t *)(p_ENVM_MEGA_BaseAddress + C_LIBBSP_ENVM_ACCELERATOR_FIFO_ADDR);

	if(v_nb_word > C_ENVM_NB_READ_MAX)
	{
		*v_ret = E_LIBBSP_ENVM_OVERSIZED;
	}
	else
	{
/* {{RELAX<SYNCHRONe_C_Code_17.4> Sizes of v_read_add_envm and v_read_data are unknown at compile time */
		while((v_index < v_nb_word) && (v_read_add_envm[v_index] <= C_ENVM_END_ADDR))
		{
			/*Write the addresses to read in the REG_NVM_ACCELERATOR_FIFO*/
			*p_reg_acc_fifo = v_read_add_envm[v_index];
			asm("mbar");

			v_index++;
		}

		if((v_index < v_nb_word) && (v_read_add_envm[v_index] > C_ENVM_END_ADDR))
		{
			*v_ret = E_LIBBSP_ENVM_INVALID_ADDR;
		}
		else
		{
			asm("mbar");
			/*Wait at least 500ns by reading the version of the PLD*/
			LIBBSP_PLDMEG_GetVersion(&v_version);

			for(v_index=0ul;v_index < v_nb_word;v_index++ )
			{
				/*Retrieve the values to read*/
				v_read_data[v_index] = *p_reg_acc_fifo;
				asm("mbar");
			}
		}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
	}
}
