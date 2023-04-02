/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include interface: ----------------------------------- */
#include "LIBBSP_UART_CheckUART.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ.MY_REQID-LLR_001 */ //TODO trouver la REQ/LLR
void Check_UART(const TE_LIBBSP_UART_Dev /* IN */ devID,
                const uint32_t /* IN */ fifoPointerLast,
                const uint32_t /* IN */ validBytes,
                const boolean_t /* IN */ par,
                const boolean_t /* IN */ stop,
                TE_LIBBSP_UART_RxErrorCode * const /* INOUT */ pa_status,
                uint32_t * const /* OUT */ pa_read)
{
   if ( (*pa_status) != E_LIBBSP_UART_RX_OK )
   {
      V_UARTPointers[devID] = fifoPointerLast;
      V_UARTSubPointers[devID] = validBytes;
      *pa_read = 0ul;
   }
   else
   {
      if ( par )
      {
         (*pa_status) = E_LIBBSP_UART_RX_PARITY_ERROR;
      }
      else
      {
         if ( stop )
         {
            (*pa_status) = E_LIBBSP_UART_RX_STOP_ERROR;
         }
      }
   }
}

