/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_Read.h"
#include "LIBBSP_A429_ReadError.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_Read(const TE_LIBBSP_A429_RxLine devID, const uint32_t NbLabToRead,
                                            uint32_t * const buffer,  uint32_t * const timetags, uint32_t * const NbLabRead, TU_LIBBSP_A429_RxState * const ErrorState) /* %RELAX<SYNCHRONe_C_Code_8.18> Output used only as parameter for subfunction are not detected as output */
{
   TE_LIBBSP_A429_RxErrorCode v_rc;
   
   uint32_t v_fifoPointerFirst;
   uint32_t v_fifoPointerLast;
   uint32_t v_fifoRollover;

   boolean_t v_gap;
   boolean_t v_par;
   boolean_t v_format;

   v_gap = FALSE;
   v_par = FALSE;
   v_format = FALSE;

    /* Verify resource type */
    if (devID > E_LIBBSP_A429_RX_9)
    {
        v_rc = E_LIBBSP_A429_RX_INVALID_ID;
    }
    else
    {

        ErrorState->R = V_A429Regs->ALLCTL.a429Controller[devID].RXA429.rxStatus.R;

        *NbLabRead = (uint32_t)0;

        v_fifoPointerLast = ErrorState->RXSTAT.RXWORDADDR / (uint32_t)4; /* on divise par 4 pour indexer le tableau des memoires d'entrees */


        /* Test rollover */
        v_fifoPointerFirst = V_A429ReceivePointers[devID];
        v_fifoRollover = ErrorState->RXSTAT.RXBUFROLLOVER;
        if (v_fifoRollover > (uint32_t)1)
        {
            v_rc =  E_LIBBSP_A429_RX_ROLLOVER;
            V_A429ReceivePointers[devID] = v_fifoPointerLast;
        }
        else if ((v_fifoRollover == (uint32_t)1) && (v_fifoPointerLast >= v_fifoPointerFirst))
        {
            v_rc = E_LIBBSP_A429_RX_ROLLOVER;
            V_A429ReceivePointers[devID] = v_fifoPointerLast;
        }
        else if ((v_fifoRollover == (uint32_t)0) && (v_fifoPointerLast < v_fifoPointerFirst))
        {
        	v_rc = E_LIBBSP_A429_RX_INCONSISTENT_ROLLOVER;
        	V_A429ReceivePointers[devID] = v_fifoPointerLast;
        }
        else
        {	
			v_rc = LIBBSP_A429_ReadError(devID,NbLabToRead,buffer,timetags,NbLabRead,ErrorState,&v_fifoPointerFirst,&v_fifoPointerLast,&v_gap,&v_par,&v_format);
            
        }
    }

    return v_rc; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
