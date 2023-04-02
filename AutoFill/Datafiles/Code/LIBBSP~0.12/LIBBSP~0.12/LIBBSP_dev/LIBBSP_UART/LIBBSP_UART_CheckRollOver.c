/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include interface: ----------------------------------- */
#include "LIBBSP_UART_CheckRollOver.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ.MY_REQID-LLR_001 */ //TODO trouver la REQ/LLR
void Check_RollOver(const uint32_t /* IN */ fifoRollover,
                    const uint32_t /* IN */ fifoPointerFirst,
                    const uint32_t /* IN */ fifoPointerLast,
                    TE_LIBBSP_UART_RxErrorCode * const /* OUT */ pa_status)
{
   if (fifoRollover > 1ul)
   {
      /* several rollover -> KO */
      *pa_status = E_LIBBSP_UART_RX_ROLLOVER_ERROR;
   }
   else
   {
      if ((fifoRollover == 1ul) && (fifoPointerLast > fifoPointerFirst))
      {
         /* rollover but the new pointer is still greater than the last -> ko*/
         *pa_status = E_LIBBSP_UART_RX_ROLLOVER_ERROR;
      }
      else
      {
         if ((fifoRollover == 0ul) && (fifoPointerLast < fifoPointerFirst))
         {
            /* no roll over but the pointer seems to have a roll over */
            *pa_status = E_LIBBSP_UART_RX_INCONSISTENT_ERROR;
         }
      }
   }
}

