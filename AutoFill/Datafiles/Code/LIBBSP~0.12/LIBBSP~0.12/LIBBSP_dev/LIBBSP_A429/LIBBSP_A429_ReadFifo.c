/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_ReadFifo.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/


/*==== Services ========================================================================*/

void LIBBSP_A429_ReadFifo(const TE_LIBBSP_A429_RxLine devID, const uint32_t NbLabToRead,uint32_t * const buffer,  uint32_t * const timetags,
		                  uint32_t v_fifoPointerFirst, const uint32_t v_fifoPointerLast, const uint32_t v_fifoRollover, uint32_t * const NbLabRead, TE_LIBBSP_A429_RxErrorCode * const v_rc)
{
	uint32_t v_index;
    uint32_t v_value;

	/* Read Fifo */

	if (v_fifoRollover > 1ul)
	{
		*v_rc =  E_LIBBSP_A429_RX_ROLLOVER;
		V_A429ReceivePointers[devID] = v_fifoPointerLast;
	}
	else if ((v_fifoRollover == 1ul) && (v_fifoPointerLast >= v_fifoPointerFirst))
	{
		*v_rc = E_LIBBSP_A429_RX_ROLLOVER;
		V_A429ReceivePointers[devID] = v_fifoPointerLast;
	}
	else
	{
		/* Read Fifo */
		v_index = 0ul;
		while (v_fifoPointerFirst != v_fifoPointerLast)
		{
			if ( v_index >=  NbLabToRead )
			{
				/* pas assez de place dans le buffer donn� en param�tre pour stocker les mots re�us */
				V_A429ReceivePointers[devID] = v_fifoPointerLast;
				*NbLabRead = 0ul;
				*v_rc =  E_LIBBSP_A429_RX_TOO_MANY_LABELS;
				break;
			}
			/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */
			v_value = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxBuffer[v_fifoPointerFirst].SPRXREG.u32;
			buffer[v_index] = v_value;
			v_value = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxTimetags[v_fifoPointerFirst].SPRXREG.u32;
			timetags[v_index] = v_value;
			v_index++;
			/* }} RELAX<SYNCHRONe_C_Code_17.4> */

			*NbLabRead = *NbLabRead + 1ul;
			v_fifoPointerFirst = (v_fifoPointerFirst+1ul)%C_A429_FIFO_ROLLOVER_COEFF;
		};

		/* Memorize FIFO pointer */
		V_A429ReceivePointers[devID] = v_fifoPointerFirst;
	}
}


/*==== END =============================================================================*/
