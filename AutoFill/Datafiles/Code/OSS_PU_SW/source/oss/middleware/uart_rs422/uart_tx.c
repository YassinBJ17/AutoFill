/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : uart_tx function which allows UART Tx management
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/uart_rs422/uart_public.h"
#include "middleware/uart_rs422/uart_private.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "driver/uart/UART_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */
ts_CMN_IOSP_BUFFER context_tx;
int8_t is_currently_sending;

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-UART-0030 */
/* Manage UART Tx */
void uart_tx(void)
{
   /* Reset RS422 fault word */
   tu_rs422_tx_fault_word * fault_word = &shmem.s_rs422_tx.s_tx_status;
   fault_word->u_word = 0;

   /* Check if last Tx is over */
   if(TX_IN_PROGRESS == is_currently_sending)
   {
      /* Return status for UART DMA driver calls */
      ts_UART_STATS_TRANSFERT uart_write_status;

      /* Retrieve driver status */
      FDX_UART_DMA_GET_WRITE_STATUS(0 , &uart_write_status);

      /* If transmission is done, reset to idle state */
      if(uart_write_status.s_done_nb == context_tx.s_buffer_size)
      {
         /* Reset internal state */
         is_currently_sending = TX_IDLE;
      }
      else
      {
         fault_word->u_bit.s_busy = 1;
      }
   }

   /* Manage new Tx if needed */
   if(TX_IDLE == is_currently_sending)
   {
      /* Manage UART Tx if required */
      if(shmem.s_rs422_tx.s_tx_count > 0)
      {
         if(shmem.s_rs422_tx.s_tx_count > UART_RS422_CAPABILITY_SIZE)
         {
            fault_word->u_bit.s_range_err_tx_count = 1;
            fault_word->u_bit.s_invalid            = 1;
         }
         else
         {
            /* Set internal state to Txs in progress */
            is_currently_sending = TX_IN_PROGRESS;

            /* Data size to send coming from the CSS_PU using shared memory */
            context_tx.s_buffer_size = shmem.s_rs422_tx.s_tx_count;

            /* Start the transmission of the data on RS422 */
            {
               uint32_t nb_of_bytes_written_previously;
               FDX_UART_DMA_START_WRITE(0, &context_tx, &nb_of_bytes_written_previously);
            }

            /* Acknowledge tx for CSS */
            shmem.s_rs422_tx.s_tx_count = 0;
         }
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
