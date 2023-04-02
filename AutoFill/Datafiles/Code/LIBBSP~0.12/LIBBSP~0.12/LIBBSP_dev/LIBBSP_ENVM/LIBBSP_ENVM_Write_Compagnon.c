/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Write_Compagnon.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_Write_Compagnon(const uint32_t address, const uint32_t size, const uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret)
{
	uint32_t v_base;
	TU_LIBBSP_ENVM_RegCtrl v_Cmd;
	uint32_t v_index;
	uint32_t v_Timeout;
	uint32_t v_cmdStatus;
	uint32_t v_cmdReqAccess;

	v_base = p_ENVM_COMP_BaseAddress + C_LIBBSP_ENVM_NVM0_BASE;
	*v_ret = E_LIBBSP_ENVM_INVALID_ADDR;
	for (v_index=0ul;v_index<ENVM_Compagnon_Map_Size;v_index++)
	{
		if (ENVM_Compagnon_Map[v_index].write != 0ul
		&& 	ENVM_Compagnon_Map[v_index].start <= address
		&&	ENVM_Compagnon_Map[v_index].end > address
		&& 	ENVM_Compagnon_Map[v_index].start < (address + size)
		&&	ENVM_Compagnon_Map[v_index].end >= (address + size))
		{
			ENVM_OverrideReg.p_SSI_COMP_ReqAddress = (TS_LIBBSP_ENVM_SSI_Mode *)(p_SSI_COMP_BaseAddress + C_LIBBSP_ENVM_SSI_MODEWRITE); /* %RELAX<SYNCHRONe_C_Code_10.7> Access to registers */
			ENVM_OverrideReg.v_SSI_COMP_ReqValue = ENVM_Compagnon_Map[v_index].write;
			*v_ret = E_LIBBSP_ENVM_OK;
			break;
		}
	}
	if (*v_ret == E_LIBBSP_ENVM_OK)
	{
		v_buffer = ((uint32_t *) (v_base + C_LIBBSP_ENVM_CTRL_WDBUFF));
		v_cmdStatus = (v_base + C_LIBBSP_ENVM_CTRL_STATUS) & 0x000FFFFFul;
/* {{RELAX<SYNCHRONe_C_Code_10.7> Access to registers */
		v_regCmd = ((TU_LIBBSP_ENVM_RegCtrl *) (v_base + C_LIBBSP_ENVM_CTRL_CMD));
		v_regReqAccess = ((TU_LIBBSP_ENVM_RegCtrl *) (v_base + C_LIBBSP_ENVM_CTRL_REQACCESS));
/* }} RELAX<SYNCHRONe_C_Code_10.7> */
		v_cmdReqAccess = (v_base + C_LIBBSP_ENVM_CTRL_REQACCESS) & 0x000FFFFFul;
		v_Timeout = 10ul;
		v_Cmd.v_reg = 0ul;
		while ((*v_ret == E_LIBBSP_ENVM_OK)
			&& (v_Cmd.Status.busy != 1ul))
		{
			LIBBSP_ENVM_ReadAddrs_Compagnon(&v_cmdStatus, 1ul, &v_Cmd.v_reg, v_ret);
			if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul) && (*v_ret == E_LIBBSP_ENVM_OK))
			{
				*v_ret = E_LIBBSP_ENVM_TIMEOUT;
				break;
			}
		}
		if (*v_ret == E_LIBBSP_ENVM_OK)
		{
			ENVM_OverrideReg.p_SSI_COMP_ReqAddress->request = ENVM_OverrideReg.v_SSI_COMP_ReqValue;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_regReqAccess->ReqAccess.reqaccess = 1ul;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			ENVM_OverrideReg.p_SSI_COMP_ReqAddress->request = C_LIBBSP_ENVM_SSI_MODE_RESET;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_Timeout = 10ul;
			v_Cmd.v_reg = 0ul;
			while ((*v_ret == E_LIBBSP_ENVM_OK)
				&& (v_Cmd.ReqAccess.reqaccess != 0x6ul))
			{
				LIBBSP_ENVM_ReadAddrs_Compagnon(&v_cmdReqAccess, 1ul, &v_Cmd.v_reg, v_ret);
				if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul) && (*v_ret == E_LIBBSP_ENVM_OK))
				{
					*v_ret = E_LIBBSP_ENVM_TIMEOUT;
					break;
				}
			}
			if (*v_ret == E_LIBBSP_ENVM_OK)
			{
				LIBBSP_ENVM_WriteCtrl_Compagnon(address, size, buffer, v_ret);
			}
			ENVM_OverrideReg.p_SSI_COMP_ReqAddress->request = ENVM_OverrideReg.v_SSI_COMP_ReqValue;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			v_regReqAccess->ReqAccess.reqaccess = 0ul;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
			ENVM_OverrideReg.p_SSI_COMP_ReqAddress->request = C_LIBBSP_ENVM_SSI_MODE_RESET;
			asm("mbar");
			LIBBSP_CMN_Wait(10ul);
		}
		ENVM_OverrideReg.p_SSI_COMP_ReqAddress = (TS_LIBBSP_ENVM_SSI_Mode*)NULL; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: cast on NULL */
		ENVM_OverrideReg.v_SSI_COMP_ReqValue = 0ul;
	}
}
