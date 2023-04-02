/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_InitOutputLink.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_InitOutputLink(const TE_LIBBSP_A429_TxLine devID, const TE_LIBBSP_A429_Speed baudRate)
{

	TE_LIBBSP_A429_TxErrorCode v_ret;
	TU_LIBBSP_A429_Register v_tempReg;

	if ((devID < E_LIBBSP_A429_TX_1) || (devID > E_LIBBSP_A429_TX_8))
	{
		v_ret = E_LIBBSP_A429_TX_INVALID_ID;
	}
	else
	{
		V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txCommand.R = 0x00000000ul;
		asm("sync");
		v_tempReg.R = V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txCommand.R;
		if ( baudRate == E_LIBBSP_A429_BAUDS_100 )
		{
			v_tempReg.TXCOM.TXBAUDRATE = 0x1ul;
		}
		else
		{
			v_tempReg.TXCOM.TXBAUDRATE = 0x0ul;
		}
		V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txCommand.R = v_tempReg.R;
		v_ret = E_LIBBSP_A429_TX_OK;

	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
