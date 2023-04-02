/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_Write.h"
/*==== Definitions =====================================================================*/












/*==== Variables =======================================================================*/
/* uint32_t V_LIBBSP_UART_forceReading; */

/*==== Services ========================================================================*/
void LIBBSP_UART_Write(const TE_LIBBSP_UART_Dev           v_DevID,
                       const uint32_t                     v_Size,
                       const uint8_t *              const p_Buffer,
                       uint32_t *                   const pa_Written,
                       TU_LIBBSP_UART_TxState *     const pa_ErrorState,
                       TE_LIBBSP_UART_TxErrorCode * const pa_Status)
{
   uint32_t v_index;
   uint32_t v_buff;
   uint32_t v_aligned;
   uint32_t v_unaligned;
   uint32_t v_txCount;
   TU_LIBBSP_UART_Register v_tempReg;
   *pa_Written = 0ul;
   
   if (v_DevID >= E_LIBBSP_UART_DEV_MAX)
   {
      *pa_Status = E_LIBBSP_UART_TX_INVALID_ID;
      return;
   }
   
   v_tempReg.R = V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txFIFOcount.R;
   /* v_txCount is V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txFIFOcount.TXFIFOCNT.TXWRDCNT*/
   v_txCount = v_tempReg.TXFIFOCNT.TXWRDCNT;
   pa_ErrorState->R = V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txStatus.R;
   if ((pa_ErrorState->TXSTAT.TXOVFFIFO == 1ul)
       || (((uint32_t)(C_UART_FIFO_SIZE) - v_txCount) <= v_Size))
   {
      *pa_Status = E_LIBBSP_UART_TX_OVERFLOW_FIFO;
      return;
   }
   
   v_unaligned = v_Size % 4ul;
   v_aligned = v_Size - v_unaligned;
   
   if (v_aligned > 0ul)
   {
      v_tempReg.R = V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R ;
      v_tempReg.TXCOM.TXVLDBYTES =  0x3ul;
      v_tempReg.TXCOM.TXCOMMAND = 0ul;
      V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R = v_tempReg.R;
      for (v_index = 0ul; v_index < v_aligned; v_index += 4ul)
      {
		/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing on p_Buffer because its a buffer*/
		/* Can't use array because can't guess the size of the buffer*/		
         V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txFIFO.R = ((uint32_t)(p_Buffer[v_index]) |
               ((uint32_t)(((uint32_t)p_Buffer[v_index + (uint32_t)1]) << 8)) |
               ((uint32_t)(((uint32_t)p_Buffer[v_index + (uint32_t)2]) << 16)) |
               ((uint32_t)(((uint32_t)p_Buffer[v_index + (uint32_t)3]) << 24)));
		/*}}RELAX<SYNCHRONe_C_Code_17.4> */
         *pa_Written += 4ul;
      }
   }
   
   if (v_unaligned > 0ul)
   {
      v_buff = 0ul;
      v_tempReg.R = V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R ;
      v_tempReg.TXCOM.TXVLDBYTES = v_unaligned - 1ul;
      v_tempReg.TXCOM.TXCOMMAND = 0ul;
      V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txCommand.R = v_tempReg.R;
      
      for (v_index = 0ul; v_index < v_unaligned; v_index++)
      {
         v_buff |= ((uint32_t)(((uint32_t)(p_Buffer[(v_Size - v_unaligned) + v_index])) << (v_index * (uint32_t)8))); /* %RELAX<SYNCHRONe_C_Code_17.4> Array indexing on p_Buffer because its a buffer*/
         *pa_Written += 1ul;
      }
      
      V_UARTRegs->ALLCTL.uartController[v_DevID].TXUART.txFIFO.R = v_buff;
   }
   *pa_Status = E_LIBBSP_UART_TX_OK;
}

/*==== END =============================================================================*/
