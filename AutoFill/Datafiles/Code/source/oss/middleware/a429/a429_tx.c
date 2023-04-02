/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Messages transmission on A429 datalink
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/a429/a429_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-A429-0040 */
/* Transmit messages in the serial link given in parameter */
void a429_tx(const uint32_t a429_words_max, ts_a429_tx_reg* const fpga_a429_tx, ts_a429_tx* const shmem_a429_tx)
{
   /* Number of messages to be transmitted */
   uint32_t msg_nb;

   /* Fault word */
   ts_a429_tx_fault_word fault_word;

   /* Iterator for messages to be transmitted */
   uint32_t i;

   /* Acquire the current status from FPGA */
   fault_word.u_word = fpga_a429_tx->fault_word.u_word;

   /* Initialize the cbit word to no fault */
   shmem_a429_tx->s_tx_status.u_word = (uint32_t)0;

   /* Make available the fault(s) to the CSS_PU/MCSS_PU using shared memory */
   shmem_a429_tx->s_tx_status.u_bit.s_busy = fault_word.u_bit.s_busy;
   shmem_a429_tx->s_tx_status.u_bit.s_parity_err = fault_word.u_bit.s_err_fifo_parity;
   shmem_a429_tx->s_tx_status.u_bit.s_nb_word_fifo = fault_word.u_bit.s_fifo_word_count;
   shmem_a429_tx->s_tx_status.u_bit.s_invalid = fault_word.u_bit.s_busy | fault_word.u_bit.s_err_fifo_parity;

   /* If the FPGA is not already busy with A429 messages */
   if ((uint32_t)0 == fault_word.u_bit.s_busy)
   {
      /* Read the number of messages to be transmitted requested by the CSS_PU */
      msg_nb = shmem_a429_tx->s_tx_count;

      /* If the number of messages is greater than the maximum number of messages the serial link can send */
      if (msg_nb > a429_words_max)
      {
         /* Prepare the algorithm to only send the maximum the serial link can process */
         msg_nb = a429_words_max;
      }

      /* For each word transmitted by the CSS_PU via the shared memory */
      for (i = (uint32_t)0; i < msg_nb; i++)
      {
         /* Send the word into the A429 serial link via the FPGA */
         fpga_a429_tx->tx[i].u_word = shmem_a429_tx->s_tx_word[i];
      }

      /* Decrement the number of words to send in shared memory (minus the number of words sent) */
      shmem_a429_tx->s_tx_count -= msg_nb;
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
