/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_ActivateRead.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_ActivateRead(const TE_LIBBSP_A429_RxLine devID, const boolean_t AuthRead)
{

	TE_LIBBSP_A429_RxErrorCode v_ret;
	TU_LIBBSP_A429_Register v_tempReg;
	if (devID > E_LIBBSP_A429_RX_9)
	{
		v_ret = E_LIBBSP_A429_RX_INVALID_ID;

	}
	else
	{
		v_tempReg.R = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxCommand.R;
		if ( AuthRead != FALSE )
		{
			v_tempReg.RXCOM.RXENABLE= C_A429_AUTHORIZED;
		}
		else
		{
			v_tempReg.RXCOM.RXENABLE = C_A429_NOT_AUTHORIZED;
		}
		V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxCommand.R = v_tempReg.R;
		/* Memorize FIFO pointer */
		v_tempReg.R = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxStatus.R;
		V_A429ReceivePointers[devID] = v_tempReg.RXSTAT.RXWORDADDR / C_A429_RX_DIVIDED_COEFF ; /* on divise par 4 pour indexer le tableau des memoires d'entrees */

		v_ret = E_LIBBSP_A429_RX_OK;

	}

	return v_ret;
}

/*==== END =============================================================================*/
