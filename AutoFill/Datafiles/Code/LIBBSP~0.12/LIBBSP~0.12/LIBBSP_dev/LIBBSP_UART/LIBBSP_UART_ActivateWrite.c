/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_ActivateWrite.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_UART_TxErrorCode LIBBSP_UART_ActivateWrite(const TE_LIBBSP_UART_Dev p_DevID,
                                                     const boolean_t          p_Enable)
{
   TE_LIBBSP_UART_TxErrorCode v_ret;
   TU_LIBBSP_UART_Register v_tempCmd;
   
   v_ret = E_LIBBSP_UART_TX_INVALID_ID;
   if (p_DevID < E_LIBBSP_UART_DEV_MAX)
   {
      v_tempCmd.R = V_UARTRegs->ALLCTL.uartController[p_DevID].TXUART.txCommand.R;
      if (p_Enable)
      {
         v_tempCmd.TXCOM.TXENABLE = 0x1ul;
      } 
      else
      {
         /* TX is disabled */
         v_tempCmd.TXCOM.TXENABLE = 0x0ul;
      }
      V_UARTRegs->ALLCTL.uartController[p_DevID].TXUART.txCommand.R = v_tempCmd.R;
      
      v_ret = E_LIBBSP_UART_TX_OK;
   }
   
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
