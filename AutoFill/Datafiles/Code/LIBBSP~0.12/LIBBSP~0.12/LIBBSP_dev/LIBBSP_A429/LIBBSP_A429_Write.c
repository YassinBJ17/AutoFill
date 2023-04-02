/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_Write.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_Write(const TE_LIBBSP_A429_TxLine devID, const uint32_t size, const uint32_t * const buffer, uint32_t * const count, TU_LIBBSP_A429_TxState * const ErrorState)
{
	TE_LIBBSP_A429_TxErrorCode v_rc;
	uint32_t v_index;

    *count = 0ul;

	/* Verify resource type */
    if ((devID < E_LIBBSP_A429_TX_1) || (devID > E_LIBBSP_A429_TX_8))
	{
		v_rc = E_LIBBSP_A429_TX_INVALID_ID;
	}
	else
	{
		ErrorState->R = V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txStatus.R;
		if ( (ErrorState->TXSTAT.TXOVFFIFO == (uint32_t)1ul)  || (((uint32_t)C_A429_FIFO_ROLLOVER_COEFF - ErrorState->TXSTAT.TXWORDCNT)<size) )
		{

			v_rc =  E_LIBBSP_A429_TX_OVERFLOW_FIFO;
		}
		else if (ErrorState->TXSTAT.TXOVFCMD == 1ul)
		{
			v_rc =  E_LIBBSP_A429_TX_OVERFLOW_CMD;
		}
		else
		{
            /* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

			for (  v_index = 0ul; v_index < size ; v_index ++ )
			{
				V_A429Regs->ALLCTL.a429Controller[devID].TXA429.txFIFO.R =  buffer[v_index];

			}
			/* }} RELAX<SYNCHRONe_C_Code_17.4> */
			*count = size;

			v_rc = E_LIBBSP_A429_TX_OK;


		}
	}

    return v_rc; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
