/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_InitOutputLink.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_UART_TxErrorCode LIBBSP_UART_InitOutputLink(const TE_LIBBSP_UART_Dev      v_DevID,
                                                      const TE_LIBBSP_UART_Speed    v_BaudRate,
                                                      const TE_LIBBSP_UART_Parity   v_Parity,
                                                      const TE_LIBBSP_UART_StopBits v_StopBits)
{
   TE_LIBBSP_UART_TxErrorCode v_ret = E_LIBBSP_UART_TX_INVALID_ID;
   TU_LIBBSP_UART_Register v_tempReg;
   
   if (v_DevID < E_LIBBSP_UART_DEV_MAX)
   {
      V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R = 0x00000000ul;
      v_tempReg.R = 0x00000000ul;
      asm("sync");
      
      switch(v_BaudRate)
      {
         case E_LIBBSP_UART_BAUDS_9600:
            v_tempReg.TXCOM.TXBAUDRATE = 0x1047ul;
            break;
         case E_LIBBSP_UART_BAUDS_19200:
            v_tempReg.TXCOM.TXBAUDRATE = 0x0823ul;
            break;
         case E_LIBBSP_UART_BAUDS_38400:
            v_tempReg.TXCOM.TXBAUDRATE = 0x0412ul;
            break;
         case E_LIBBSP_UART_BAUDS_460800:
            v_tempReg.TXCOM.TXBAUDRATE = 0x0057ul;
            break;  
         case E_LIBBSP_UART_BAUDS_921600:
            v_tempReg.TXCOM.TXBAUDRATE = 0x002Cul;
            break;
         default: /* 115200, E_LIBBSP_UART_BAUDS_115200 */
            v_tempReg.TXCOM.TXBAUDRATE = 0x015Cul;
            break;
      }
      
      v_tempReg.TXCOM.TXPARITYTYPE = 0x0ul;
      if ( v_Parity == E_LIBBSP_UART_PARITY_ODD )
      {
         v_tempReg.TXCOM.TXPARITYTYPE = 0x1ul;
      }
      else if ( v_Parity == E_LIBBSP_UART_PARITY_EVEN )
      {
        v_tempReg.TXCOM.TXPARITYTYPE = 0x2ul;
      }
      
      /* Two stop bits */
      v_tempReg.TXCOM.TXNBBITSTOP = 0x0ul;
      if ( v_StopBits == E_LIBBSP_UART_STOPBITS_ONE )
      {
         v_tempReg.TXCOM.TXNBBITSTOP = 0x1ul;
      }
      
      V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R =v_tempReg.R;
      v_ret = E_LIBBSP_UART_TX_OK;
   }
   
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
