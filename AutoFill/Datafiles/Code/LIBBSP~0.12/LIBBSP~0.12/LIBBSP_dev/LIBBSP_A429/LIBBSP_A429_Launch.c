/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_Launch.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
const uint32_t C_A429_LAUNCH = 1;
/*==== Services ========================================================================*/
TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_Launch(const TE_LIBBSP_A429_TxLine devID, TU_LIBBSP_A429_TxState * const ErrorState)
{

	TE_LIBBSP_A429_TxErrorCode v_ret;
	TU_LIBBSP_A429_Register v_tempReg;

	if ((devID < E_LIBBSP_A429_TX_1) || (devID > E_LIBBSP_A429_TX_8))
	{
		v_ret = E_LIBBSP_A429_TX_INVALID_ID;

	}
	else
	{
		ErrorState->R = V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txStatus.R;
		if ( ErrorState->TXSTAT.TXOVFFIFO == 1ul )
		{
			v_ret =  E_LIBBSP_A429_TX_OVERFLOW_FIFO;
		}
		else if (ErrorState->TXSTAT.TXOVFCMD == 1ul)
		{
			v_ret =  E_LIBBSP_A429_TX_OVERFLOW_CMD;
		}
		else
		{
			v_tempReg.R = V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txCommand.R;
			v_tempReg.TXCOM.TXCOMMAND = C_A429_LAUNCH;
			V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txCommand.R = v_tempReg.R;
			v_ret = E_LIBBSP_A429_TX_OK;
		}

	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
