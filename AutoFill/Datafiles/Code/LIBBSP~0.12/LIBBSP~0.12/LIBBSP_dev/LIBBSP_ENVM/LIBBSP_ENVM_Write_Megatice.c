/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ENVM_Write_Megatice.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ENVM_Write_Megatice(const uint32_t address, const uint32_t size, const uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret)
{
	uint32_t v_base;
	TU_LIBBSP_ENVM_RegCtrl v_Cmd;
	uint32_t v_Timeout;
	uint32_t v_cmdStatus;
	uint32_t v_cmdReqAccess;

	*v_ret = E_LIBBSP_ENVM_OK;
	v_base = p_ENVM_MEGA_BaseAddress;
	if ((address < C_ENVM_NVM0_SIZE) && (size <= C_ENVM_NVM0_SIZE))
	{
		v_base += C_LIBBSP_ENVM_NVM0_BASE;
	}
	else if ((address >= C_ENVM_NVM0_SIZE) && (size <= C_ENVM_NVM1_SIZE))
	{
		v_base += C_LIBBSP_ENVM_NVM1_BASE;
	}
	else
	{
		*v_ret = E_LIBBSP_ENVM_OVERSIZED;
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
			LIBBSP_ENVM_ReadAddrs_Megatice(&v_cmdStatus, 1ul, &v_Cmd.v_reg, v_ret);
			if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul) && (*v_ret == E_LIBBSP_ENVM_OK))
			{
				*v_ret = E_LIBBSP_ENVM_TIMEOUT;
				break;
			}
		}
		if (*v_ret == E_LIBBSP_ENVM_OK)
		{
			v_regReqAccess->ReqAccess.reqaccess = 1ul;
			asm("mbar");
			v_Timeout = 10ul;
			v_Cmd.v_reg = 0ul;
			while ((*v_ret == E_LIBBSP_ENVM_OK)
				&& (v_Cmd.ReqAccess.reqaccess != 0x6ul))
			{
				LIBBSP_ENVM_ReadAddrs_Megatice(&v_cmdReqAccess, 1ul, &v_Cmd.v_reg, v_ret);
				if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul) && (*v_ret == E_LIBBSP_ENVM_OK))
				{
					*v_ret = E_LIBBSP_ENVM_TIMEOUT;
					break;
				}
			}
			if (*v_ret == E_LIBBSP_ENVM_OK)
			{
				LIBBSP_ENVM_WriteCtrl_Megatice(address, size, buffer, v_ret);
			}
			v_regReqAccess->ReqAccess.reqaccess = 0ul;
			asm("mbar");
		}
	}
}
