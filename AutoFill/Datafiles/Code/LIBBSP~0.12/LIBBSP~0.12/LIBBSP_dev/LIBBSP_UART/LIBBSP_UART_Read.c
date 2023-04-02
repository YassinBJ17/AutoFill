/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_Read.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_UART_Read(const                              TE_LIBBSP_UART_Dev v_DevID,
                      const uint32_t                     v_ToRead,
                      uint8_t *                    const pa_Buffer,
                      uint32_t *                   const pa_Read,
                      TU_LIBBSP_UART_RxState *     const pa_ErrorState,
                      TE_LIBBSP_UART_RxErrorCode * const pa_Status)
{
   uint32_t v_index;
   uint32_t v_fifoPointerFirst;
   uint32_t v_fifoPointerLast;
   uint32_t v_fifoRollover;
   uint32_t v_validBytes;
   uint32_t v_lastValidBytes;
   boolean_t v_pointerMoved;
   boolean_t v_par;
   boolean_t v_stop;
   TU_LIBBSP_UART_Register * pt_rxBuffer;
   TU_LIBBSP_UART_Register v_tempReg;
   uint8_t v_BufferTemp[4] = { 0 };
   uint32_t v_temporary_value; /* used to force a 32 bits access to the pld */
   *pa_Status = E_LIBBSP_UART_RX_OK;
   *pa_Read = 0ul;
   v_par = FALSE;
   v_stop = FALSE;

   if (v_DevID >= E_LIBBSP_UART_DEV_MAX)
   {
      *pa_Status = E_LIBBSP_UART_DEV_INVALID_ID;
   }
   else
   {
   
      /* read the current position of the reception pointer */
      v_tempReg.R = V_UARTRegs->ALLCTL.uartController[v_DevID].RXUART.rxBuffercount.R;
      v_fifoPointerLast = v_tempReg.RXFIFOCNT.RXWRDCNT;
   
      pa_ErrorState->R = V_UARTRegs->ALLCTL.uartController[v_DevID].RXUART.rxStatus.R;
      v_validBytes = pa_ErrorState->RXSTAT.RXVLDBYTES;
   
      /* check the errors from the PLD macro */
      Check_PLDErrors(pa_ErrorState, &v_par, &v_stop);

//   if (pa_ErrorState->RXSTAT.RXERRPARITY == 1ul)
//   {
//      v_par = TRUE;
//   }
//   else
//   {
//      if (pa_ErrorState->RXSTAT.RXERRSTOP == 1ul)
//      {
//         v_stop = TRUE;
//      }
//   }
   
      v_fifoRollover = pa_ErrorState->RXSTAT.RXBUFROLLOVER;
      if ( (v_fifoPointerLast != V_UARTPointers[v_DevID]) || (v_fifoRollover > 0ul) )
      {
         v_pointerMoved = TRUE;
      }
      else
      {
         v_pointerMoved = FALSE;
      }
   
   /* Test rollover */
   
   /* the rollover is made only with the pointer */
      v_fifoPointerFirst = V_UARTPointers[v_DevID];
      v_lastValidBytes = V_UARTSubPointers[v_DevID];
   
   
      Check_RollOver(v_fifoRollover, v_fifoPointerFirst, v_fifoPointerLast, pa_Status);

//   if (v_fifoRollover > 1ul)
//   {
//      /* several rollover -> KO */
//      *pa_Status = E_LIBBSP_UART_RX_ROLLOVER_ERROR;
//   }
//   else
//   {
//      if ((v_fifoRollover == 1ul) && (v_fifoPointerLast > v_fifoPointerFirst))
//      {
//         /* rollover but the new pointer is still greater than the last -> ko*/
//         *pa_Status = E_LIBBSP_UART_RX_ROLLOVER_ERROR;
//      }
//      else
//      {
//         if ((v_fifoRollover == 0ul) && (v_fifoPointerLast < v_fifoPointerFirst))
//         {
//            /* no roll over but the pointer seems to have a roll over */
//            *pa_Status = E_LIBBSP_UART_RX_INCONSISTENT_ERROR;
//         }
//      }
//   }

      if ( (*pa_Status) != E_LIBBSP_UART_RX_OK )
      {
         V_UARTPointers[v_DevID] = v_fifoPointerLast;
         V_UARTSubPointers[v_DevID] = v_validBytes;
      }
      else
      {
         /* nominal case, *pa_Status == E_LIBBSP_UART_RX_OK */
         /* Read Fifo */
         v_index = 0ul;
         pt_rxBuffer = V_UARTReceiveBuffers[v_DevID]; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: same type */
   
         /* first, we have to check if the last word reading was a complete reading */
         if ( v_lastValidBytes != 4ul && v_lastValidBytes != 0ul)
         {
            v_index = read_LastValidBytes(v_pointerMoved, v_lastValidBytes, v_validBytes, pt_rxBuffer, v_BufferTemp, &v_fifoPointerFirst, pa_Read);
//      uint32_t read_LastValidBytes(const boolean_t /* IN */ pointerMoved,
//                                   const uint32_t /* IN */ lastValidBytes,
//                                   const uint32_t /* IN */ validBytes,
//                                   const TU_LIBBSP_UART_Register * /* IN */ rxBuffer,
//                                   uint8_t * /* OUT */ bufferTemp,
//                                   uint32_t * /* INOUT */ fifoPointerFirst,
//                                   uint32_t * const /* OUT */ pa_read);
//      /* verification if the pointers has moved */
//      if ( v_pointerMoved )
//      {
//
//
//         /* read all the word */
//         switch (v_lastValidBytes)
//         {
//            case 1:
//               v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
//               v_BufferTemp[v_index++] = ((uint8_t*)&v_temporary_value) [2];
//               v_BufferTemp[v_index++] = ((uint8_t*)&v_temporary_value) [1];
//               v_BufferTemp[v_index++] = ((uint8_t*)&v_temporary_value) [0];
//               *pa_Read += 3ul;
//               break;
//            case 2:
//               v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
//               v_BufferTemp[v_index++] = ((uint8_t*)&v_temporary_value) [1];
//               v_BufferTemp[v_index++] = ((uint8_t*)&v_temporary_value) [0];
//               *pa_Read += 2ul;
//               break;
//            case 3:
//               v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
//               v_BufferTemp[v_index++] = ((uint8_t*)&v_temporary_value) [0];
//               *pa_Read += 1ul;
//               break;
//            default:
//               break;
//         }
//         v_fifoPointerFirst = (v_fifoPointerFirst + 1ul) % 512ul;
//      }
//      else
//      {
//         v_i_max = v_validBytes-v_lastValidBytes;
//         v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
//         for ( v_i = 0ul; v_i < v_i_max; v_i ++ )
//         {
//            v_j = 3ul - v_lastValidBytes - v_i;
//            v_BufferTemp[v_index++] = ((uint8_t*)&v_temporary_value) [v_j];
//            *pa_Read += 1ul;
//         }
//      } // FIN Fct

            Check_Index(v_index, v_ToRead, v_BufferTemp, pa_Status, pa_Buffer);

//      if ( v_index > v_ToRead)
//      {
//         *pa_Status = E_LIBBSP_UART_RX_OVERFLOW_ERROR;
//      }
//      else
//      {
//         for ( v_i = 0ul; v_i < v_index ; v_i ++ )
//         {
//            pa_Buffer[v_i] = v_BufferTemp[v_i];
//         }
//      }
         }
   
         while (v_fifoPointerFirst != v_fifoPointerLast)
         {
            if ((v_index+4ul) > v_ToRead)
            {
               /* pas assez de place dans le buffer donné en paramétre pour stocker les mots reçus */
               *pa_Status = E_LIBBSP_UART_RX_OVERFLOW_ERROR;
               break;
            }
            /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> */
            /* use pointer for array indexing and convert it, because we dont know buffer size and the value is fractionned into a tab of uint8 */
            v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
            pa_Buffer[v_index++] = ((uint8_t*)&v_temporary_value) [3];
            pa_Buffer[v_index++] = ((uint8_t*)&v_temporary_value) [2];
            pa_Buffer[v_index++] = ((uint8_t*)&v_temporary_value) [1];
            pa_Buffer[v_index++] = ((uint8_t*)&v_temporary_value) [0];
            /* }} RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> */
            *pa_Read = *pa_Read + 4ul;
            v_fifoPointerFirst = (v_fifoPointerFirst + 1ul) % 512ul;
         }

         if ( (v_validBytes != 0ul)
               && (v_validBytes != 4ul)
               && ( (v_pointerMoved) || (v_lastValidBytes == 0ul) || (v_lastValidBytes == 4ul) ))
         {
            if ( (v_index + v_validBytes) > v_ToRead)
            {
               *pa_Status = E_LIBBSP_UART_RX_OVERFLOW_ERROR;
            }
            else
            {
               read_ValidBytes(v_validBytes, &(pt_rxBuffer[v_fifoPointerFirst]), &v_index, pa_Buffer, pa_Read); /* %RELAX<SYNCHRONe_C_Code_17.4> use pointer for array indexing because its a buffer and we can't guess its size */

//         switch (v_validBytes)
//         {
//            case 1:
//               v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
//               pa_Buffer[v_index] = ((uint8_t*)&v_temporary_value) [3];
//               *pa_Read = *pa_Read + 1ul;
//               break;
//            case 2:
//               v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
//               pa_Buffer[v_index++] = ((uint8_t*)&v_temporary_value) [3];
//               pa_Buffer[v_index] = ((uint8_t*)&v_temporary_value) [2];
//               *pa_Read = *pa_Read + 2ul;
//               break;
//            case 3:
//               v_temporary_value = pt_rxBuffer[v_fifoPointerFirst].R;
//               pa_Buffer[v_index++] = ((uint8_t*)&v_temporary_value) [3];
//               pa_Buffer[v_index++] = ((uint8_t*)&v_temporary_value) [2];
//               pa_Buffer[v_index] = ((uint8_t*)&v_temporary_value) [1];
//               *pa_Read = *pa_Read + 3ul;
//               break;
//            default:
//               break;
//         }
            }
         }
      }
      /* Memorize FIFO pointer */
      V_UARTPointers[v_DevID] = /*v_fifoPointerFirst*/v_fifoPointerLast; // TODO ces 2 affectations sont aussi presentes dans la fct qui suit mais uniquement quand UART Rx OK
      V_UARTSubPointers[v_DevID] = v_validBytes;
   
      Check_UART(v_DevID, v_fifoPointerLast, v_validBytes, v_par, v_stop, pa_Status, pa_Read);

//   if ( (*pa_Status) != E_LIBBSP_UART_RX_OK )
//   {
//      V_UARTPointers[v_DevID] = v_fifoPointerLast;
//      V_UARTSubPointers[v_DevID] = v_validBytes;
//      *pa_Read = 0ul;
//   }
//   else
//   {
//      if ( v_par )
//      {
//         (*pa_Status) = E_LIBBSP_UART_RX_PARITY_ERROR;
//      }
//      else
//      {
//         if ( v_stop )
//         {
//            (*pa_Status) = E_LIBBSP_UART_RX_STOP_ERROR;
//         }
//      }
//   }
   }
}


/*==== END =============================================================================*/
