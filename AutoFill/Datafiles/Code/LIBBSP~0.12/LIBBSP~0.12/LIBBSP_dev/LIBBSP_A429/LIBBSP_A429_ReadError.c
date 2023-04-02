/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_ReadError.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_ReadError(

	const TE_LIBBSP_A429_RxLine devID,
	const uint32_t NbLabToRead,
	uint32_t * const buffer,
	uint32_t * const timetags,
	uint32_t * const NbLabRead,
	const TU_LIBBSP_A429_RxState * const ErrorState,
	uint32_t  * const v_fifoPointerFirst,
    const uint32_t  * const v_fifoPointerLast,
    boolean_t  * const v_gap,
    boolean_t  * const v_par,
    boolean_t  * const v_format    
)
{
	uint32_t  v_index;
    uint32_t  v_value;
	
	TE_LIBBSP_A429_RxErrorCode v_rc = E_LIBBSP_A429_RX_OK;
   
	if (ErrorState->RXSTAT.RXERRGAP == (uint32_t)1)
	{
		*v_gap = TRUE;
	}
	else if (ErrorState->RXSTAT.RXERRPARITY == (uint32_t)1)
	{
		*v_par = TRUE;
	}
	else if (ErrorState->RXSTAT.RXERRFORMAT == (uint32_t)1)
	{
		*v_format = TRUE;
	}


	/* Read Fifo */
	v_index = (uint32_t)0;
	while (*v_fifoPointerFirst != *v_fifoPointerLast)
	{
		if ( v_index >=  NbLabToRead )
		{
			/* pas assez de place dans le buffer donné en paramètre pour stocker les mots reçus */
			V_A429ReceivePointers[devID] = *v_fifoPointerLast;
			*NbLabRead = (uint32_t)0;
			v_rc =  E_LIBBSP_A429_RX_TOO_MANY_LABELS;
			break;
		}
		v_value = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxBuffer[*v_fifoPointerFirst].SPRXREG.u32;
		buffer[v_index] = v_value; /* %RELAX<SYNCHRONe_C_Code_17.4> pointer used for array indexing beause we don't kno buffer size */
		v_value = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxTimetags[*v_fifoPointerFirst].SPRXREG.u32;
		timetags[v_index] = v_value; /* %RELAX<SYNCHRONe_C_Code_17.4> pointer used for array indexing beause we don't kno table size */
		v_index++;
		*NbLabRead = *NbLabRead + (uint32_t)1;

		*v_fifoPointerFirst = (*v_fifoPointerFirst+(uint32_t)1)%(uint32_t)64;
	};  

    /* Memorize FIFO pointer */
	V_A429ReceivePointers[devID] = *v_fifoPointerLast;

	if ( v_rc == E_LIBBSP_A429_RX_OK )
	{
		if ( *v_gap != FALSE )
		{
			v_rc = E_LIBBSP_A429_RX_GAP_ERROR;
		}
		else if ( *v_par != FALSE)
		{
			v_rc = E_LIBBSP_A429_RX_PARITY_ERROR;
		}
		else if ( *v_format != FALSE)
		{
			v_rc = E_LIBBSP_A429_RX_FORMAT_ERROR;
		}
	}	
        
    return v_rc; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}


/*==== END =============================================================================*/
