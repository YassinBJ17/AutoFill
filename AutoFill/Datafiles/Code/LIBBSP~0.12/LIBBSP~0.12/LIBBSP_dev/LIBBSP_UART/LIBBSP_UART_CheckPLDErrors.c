/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include interface: ----------------------------------- */
#include "LIBBSP_UART_CheckPLDErrors.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ.MY_REQID-LLR_001 */ //TODO trouver la REQ/LLR
void Check_PLDErrors(const TU_LIBBSP_UART_RxState * const /* IN */ pa_errorState,
                     boolean_t * const /* OUT */ par,
                     boolean_t * const /* OUT */ stop)
{
   if (pa_errorState->RXSTAT.RXERRPARITY == 1ul)
   {
      *par = TRUE;
   }
   else
   {
      if (pa_errorState->RXSTAT.RXERRSTOP == 1ul)
      {
         *stop = TRUE;
      }
   }
}

