/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_InitInputLink.h"
#include "Mask_Bit.h"

/*==== Definitions =====================================================================*/
const uint32_t C_A429_TAB_ELEMENT_MAX = 7;
const uint32_t C_A429_NUMBER_BIT = 32;
const uint32_t C_A429_FILTER_TABLE_INIT = 0xFFFFFFFF;

uint32_t V_A429ReceivePointers[RX_CONTROLLERS_COUNT];

/*==== Variables =======================================================================*/


/*==== Services ========================================================================*/

TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_InitInputLink(const TE_LIBBSP_A429_RxLine devID, const TE_LIBBSP_A429_Speed baudRate,const uint32_t NbAuthLabel, const uint8_t * const AuthLabel)
{

	TE_LIBBSP_A429_RxErrorCode v_ret;
	uint32_t v_index;
	uint32_t v_TabElement;
	uint32_t v_Element;
	TU_LIBBSP_A429_Register v_tempReg;

	V_A429ReceivePointers[devID] = 0ul;

	if (devID > E_LIBBSP_A429_RX_9)
	{
		v_ret = E_LIBBSP_A429_RX_INVALID_ID;

	}
	else
	{

		for (v_index=0ul; v_index <= C_A429_TAB_ELEMENT_MAX; v_index++)
		{
			V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxLabelFilterTable[v_index].R = C_A429_FILTER_TABLE_INIT;
		}

		v_index = 0ul;

		while (v_index < NbAuthLabel)
		{

			/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

			v_TabElement = (((uint32_t)AuthLabel[v_index] - ((uint32_t)AuthLabel[v_index] % C_A429_NUMBER_BIT))/C_A429_NUMBER_BIT);
			v_Element = ((uint32_t)AuthLabel[v_index] % C_A429_NUMBER_BIT);
			V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxLabelFilterTable[v_TabElement].R &= (uint32_t)(~(Mask_Bit(v_Element)));
			
			/* }} RELAX<SYNCHRONe_C_Code_17.4> */

			v_index++;
		}

		V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxCommand.R = 0x00000000ul;
		asm("sync");
		v_tempReg.R = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxCommand.R;
		if ( baudRate == E_LIBBSP_A429_BAUDS_100 )
		{
			v_tempReg.RXCOM.RXBAUDRATE = 0x1ul;
		}
		else
		{
			v_tempReg.RXCOM.RXBAUDRATE = 0x0ul;
		}
		V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxCommand.R = v_tempReg.R;
		/* Memorize FIFO pointer */
		v_tempReg.R = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxStatus.R;
		V_A429ReceivePointers[devID] = v_tempReg.RXSTAT.RXWORDADDR / C_A429_RX_DIVIDED_COEFF ; /* on divise par 4 pour indexer le tableau des memoires d'entrees */

		v_ret = E_LIBBSP_A429_RX_OK;

	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
