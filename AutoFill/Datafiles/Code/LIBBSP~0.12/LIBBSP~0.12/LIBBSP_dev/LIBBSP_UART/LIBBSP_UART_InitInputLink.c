/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_InitInputLink.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/



/*==== Services ========================================================================*/

TE_LIBBSP_UART_RxErrorCode LIBBSP_UART_InitInputLink(const TE_LIBBSP_UART_Dev    v_DevID,
                                                     const uint32_t *      const v_RxBuffer,
                                                     const TE_LIBBSP_UART_Speed  v_BaudRate,
                                                     const TE_LIBBSP_UART_Parity v_Parity)
{
   TE_LIBBSP_UART_RxErrorCode v_ret;
   TU_LIBBSP_UART_Register v_tempReg;
   uint32_t v_index;
   
   if ( v_DevID >= E_LIBBSP_UART_DEV_MAX )
   {
      v_ret = E_LIBBSP_UART_DEV_INVALID_ID;
   }
   else
   {
      for ( v_index = 0ul; v_index < (uint32_t)C_UART_DEVICES_COUNT; v_index++)
      {
         V_UARTPointers[v_index] = 0ul;
         V_UARTSubPointers[v_index] = 0ul;
      }

      V_UARTRegs->ALLCTL.uartController[v_DevID].RXUART.rxCommand.R = 0x00000000ul;
      v_tempReg.R = 0x00000000ul;
      asm("sync");

      v_tempReg.RXCOM.RXBAUDRATE = switch_BaudRate(v_BaudRate);

      v_tempReg.RXCOM.RXPARITYTYPE = 0x0ul;
      if ( v_Parity == E_LIBBSP_UART_PARITY_ODD )
      {
         v_tempReg.RXCOM.RXPARITYTYPE = 0x1ul;
      }
      else
      {
         if ( v_Parity == E_LIBBSP_UART_PARITY_EVEN )
         {
            v_tempReg.RXCOM.RXPARITYTYPE = 0x2ul;
         }
      }

      V_UARTRegs->ALLCTL.uartController[v_DevID].RXUART.rxCommand.R = v_tempReg.R;

      v_tempReg.R = V_UARTRegs->ALLCTL.uartController[v_DevID].RXUART.rxBuffercount.R;
      V_UARTPointers[v_DevID] = v_tempReg.RXFIFOCNT.RXWRDCNT;
      v_tempReg.R = V_UARTRegs->ALLCTL.uartController[v_DevID].RXUART.rxStatus.R;
      V_UARTSubPointers[v_DevID] = v_tempReg.RXSTAT.RXVLDBYTES;
      V_UARTReceiveBuffers[v_DevID] = (TU_LIBBSP_UART_Register *)v_RxBuffer; /* %RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> Conversion from generic pointer to ptr to specific structure */
      v_ret = E_LIBBSP_UART_RX_OK;
   }
   
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}


/*--------------------------------------------------------------------------------------------------------------------*/
uint32_t switch_BaudRate(const TE_LIBBSP_UART_Speed baudrate)
{
   uint32_t RxBaudRate;

   switch ( baudrate )
   {
   case E_LIBBSP_UART_BAUDS_9600:
      RxBaudRate = 0x1047ul;
      break;
   case E_LIBBSP_UART_BAUDS_19200:
      RxBaudRate = 0x0823ul;
      break;
   case E_LIBBSP_UART_BAUDS_38400:
      RxBaudRate = 0x0412ul;
      break;
   case E_LIBBSP_UART_BAUDS_115200:
      RxBaudRate = 0x015Cul;
      break;
   case E_LIBBSP_UART_BAUDS_460800:
      RxBaudRate = 0x0057ul;
      break;
   case E_LIBBSP_UART_BAUDS_921600:
      RxBaudRate = 0x002Cul;
      break;
   default: /* 115200 */
      RxBaudRate = 0x015Cul ;
      break;
   }

   return RxBaudRate;
}
/*==== END =============================================================================*/
