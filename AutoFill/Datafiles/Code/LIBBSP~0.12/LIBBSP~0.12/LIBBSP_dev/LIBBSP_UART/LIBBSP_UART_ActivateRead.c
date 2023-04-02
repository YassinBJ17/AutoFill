/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_ActivateRead.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/


TE_LIBBSP_UART_RxErrorCode LIBBSP_UART_ActivateRead(const TE_LIBBSP_UART_Dev p_DevID,
                                                    const boolean_t          p_Enable)
{
   TE_LIBBSP_UART_RxErrorCode v_ret = E_LIBBSP_UART_DEV_INVALID_ID;
   TU_LIBBSP_UART_Register v_tempCmd;
   
   if (p_DevID < E_LIBBSP_UART_DEV_MAX)
   {
      v_tempCmd.R = V_UARTRegs->ALLCTL.uartController[p_DevID].RXUART.rxCommand.R;
      if (p_Enable)
      {
         v_tempCmd.RXCOM.RXENABLE = 0x1ul;
      }
      else
      {
         /* RX is disabled */
         v_tempCmd.RXCOM.RXENABLE = 0x0ul;
      }
      V_UARTRegs->ALLCTL.uartController[p_DevID].RXUART.rxCommand.R = v_tempCmd.R;
      
      v_ret = E_LIBBSP_UART_RX_OK;
   }
   
   return v_ret;
}

/*==== END =============================================================================*/
