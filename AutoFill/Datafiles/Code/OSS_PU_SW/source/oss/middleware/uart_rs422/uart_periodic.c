/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : uart_periodic function which allows UART Rx and Tx management
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/uart_rs422/uart_public.h"
#include "middleware/uart_rs422/uart_private.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-UART-0020 */
/* Implements REQ_FADEX_OS_SRD-UART-0030 */
void uart_periodic(void)
{
   /* Perform UART activity when not in UOD mode */
   if(disable_uart_for_uod == 0)
   {
      /* Manage UART Rx */
      uart_rx();

      /* Manage UART Tx */
      uart_tx();
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
