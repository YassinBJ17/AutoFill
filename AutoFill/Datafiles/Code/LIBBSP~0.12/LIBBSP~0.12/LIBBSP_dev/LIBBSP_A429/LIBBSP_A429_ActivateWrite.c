/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_ActivateWrite.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_ActivateWrite(const TE_LIBBSP_A429_TxLine devID, const boolean_t AuthWrite)
{

	TE_LIBBSP_A429_TxErrorCode v_ret;
	TU_LIBBSP_A429_Register v_tempReg;

	if ((devID < E_LIBBSP_A429_TX_1) || (devID > E_LIBBSP_A429_TX_8))
	{
		v_ret = E_LIBBSP_A429_TX_INVALID_ID;

	}
	else
	{
		v_tempReg.R = V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txCommand.R;
		if ( AuthWrite != FALSE )
		{
			v_tempReg.TXCOM.TXENABLE = C_A429_AUTHORIZED;
		}
		else
		{
			v_tempReg.TXCOM.TXENABLE = C_A429_NOT_AUTHORIZED;
		}
		V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txCommand.R = v_tempReg.R;
		v_ret = E_LIBBSP_A429_TX_OK;

	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
