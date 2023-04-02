/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_WriteCtrl_Compagnon.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_WriteCtrl_Compagnon(const uint32_t address, const uint32_t size, const uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret)
{
	TU_LIBBSP_ENVM_RegCtrl v_Cmd;
	uint32_t v_address;
	uint32_t v_index;
	uint32_t v_indexIn;
	uint8_t v_buff[C_LIBBSP_ENVM_PAGESIZE];

	v_address = address;
	v_indexIn = 0ul;
	while (v_address < (address + size))
	{
		if (v_address % C_LIBBSP_ENVM_PAGESIZE != 0ul)
		{
			v_address = v_address - (v_address % C_LIBBSP_ENVM_PAGESIZE);
			LIBBSP_ENVM_Read_Compagnon(v_address, C_LIBBSP_ENVM_PAGESIZE, v_buff, v_ret);
		}
		else if ((v_address + C_LIBBSP_ENVM_PAGESIZE) > (address + size))
		{
			LIBBSP_ENVM_Read_Compagnon(v_address, C_LIBBSP_ENVM_PAGESIZE, v_buff, v_ret);
		}
		if (*v_ret == E_LIBBSP_ENVM_OK)
		{
			v_index = 0ul;
			while (v_index < C_LIBBSP_ENVM_PAGESIZE)
			{
				if (((v_address + v_index) >= address) && ((v_address + v_index) < (address + size)))
				{
					/* >RELAX<SYNCHRONe_C_Code_17.4> Sizes of buffers are unknown at compile time */
					/* >RELAX<SYNCHRONe_C_Code_10.7> Copying buffers */
					v_buff[v_index] = buffer[v_indexIn];
					v_indexIn++;
				}
				v_index++;
			}
			ENVM_OverrideReg.p_SSI_COMP_ReqAddress->request = ENVM_OverrideReg.v_SSI_COMP_ReqValue;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_index = 0ul;
			while (v_index < 32ul)
			{
				/* >RELAX<SYNCHRONe_C_Code_17.4> Sizes of buffers are unknown at compile time */
				/* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Copying buffers as uint32_t */
				v_buffer[v_index] = ((uint32_t *) v_buff)[v_index];
				v_index++;
			}
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_Cmd.Cmd.cmd = 0x08ul;
			v_Cmd.Cmd.addr = v_address;
			v_regCmd->v_reg = v_Cmd.v_reg;
			asm("mbar");
			LIBBSP_CMN_Wait(4000ul);
			ENVM_OverrideReg.p_SSI_COMP_ReqAddress->request = C_LIBBSP_ENVM_SSI_MODE_RESET;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_address += C_LIBBSP_ENVM_PAGESIZE;
		}
	}
}
