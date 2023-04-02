/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_Launch.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/* const uint32_t C_UART_LAUNCH = 1; */
/*==== Services ========================================================================*/
void LIBBSP_UART_Launch(const TE_LIBBSP_UART_Dev           v_DevID,
                        TU_LIBBSP_UART_TxState *     const pa_ErrorState,
                        TE_LIBBSP_UART_TxErrorCode * const pa_Status)
{
   TU_LIBBSP_UART_Register v_tempReg;
   if (v_DevID >= E_LIBBSP_UART_DEV_MAX)
   {
      *pa_Status = E_LIBBSP_UART_TX_INVALID_ID;
   }
   else
   {
      pa_ErrorState->R = V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txStatus.R;
      if (pa_ErrorState->TXSTAT.TXOVFFIFO == 1ul)
      {
         *pa_Status = E_LIBBSP_UART_TX_OVERFLOW_FIFO;
      }
      else
      {
         v_tempReg.R = V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R;
         v_tempReg.TXCOM.TXCOMMAND = 1ul;
         V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R = v_tempReg.R,
         
         *pa_Status = E_LIBBSP_UART_TX_OK;
      }
   }
}
/*==== END =============================================================================*/
