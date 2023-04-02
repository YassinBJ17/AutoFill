/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Messages reception on A429 datalink
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
/* Implements REQ_FADEX_OS_SRD-A429-0030 */
/* Read A429 message(s) */
void a429_rx(const uint32_t a429_words_max, ts_a429_rx_reg* const fpga_a429_rx, ts_a429_rx* const shmem_a429_rx, const uint16_t* const a429_rx_sdi_label)
{
   /* A429 RX fault word from the FPGA */
   ts_a429_rx_fault_word fault_word;

   /* Number of words received on A429 */
   uint32_t msg_nb;

   /* Received messages iterator */
   uint32_t i;

   /* SDI+label configured iterator */
   uint32_t j;

   /* Shared memory A429 words iterator */
   uint32_t k;

   /* Is a newer word has been found in the FIFO bufferized */
   boolean_t newer_word_found;

   /* Buffer for the received messages */
   ts_a429_word rx_words[A429_MAX_WORD_PROCESSED_IN_HS_NB];

   /* Initialize the cbit word to no fault */
   shmem_a429_rx->s_rx_status.u_word = (uint32_t)0;

   /* Read the A429 RX fault word from the FPGA */
   fault_word.u_word = fpga_a429_rx->fault_word.u_word;

   /* Read the number of words received on A429 */
   msg_nb = (uint32_t)fpga_a429_rx->fault_word.u_bit.s_ram_word_count;

   /* If the number of words is greater than the maximum number of words the software can process */
   if (msg_nb > a429_words_max)
   {
      /* Set the number of words to processed to the maximum which can be processed */
      msg_nb = a429_words_max;
   }

   /* For each message received (within the limit of a429_words_max included) */
   for (i = (uint32_t)0; i < msg_nb; i++)
   {
      /* Bufferize the received words */
      rx_words[i].u_word = fpga_a429_rx->rx[0].u_word;
   }

   /* If the status does not reflect a sram parity error */
   if ((uint32_t)0 == fault_word.u_bit.s_err_ram_parity)
   {
      /* Initialize the iterator of final buffer of words to no message */
      k = (uint32_t)0;

      /* For each message received (within the limit of a429_words_max included) */
      for (i = (uint32_t)0; i < msg_nb; i++)
      {
         /* Initialize the indicator newer_word_found to no newer word found */
         newer_word_found = FALSE;

         /* For each message received in the continuation of the table */
         for (j = (uint32_t)(i + 1); j < msg_nb; j++)
         {
            /* If another message (newer) with the same SDI-label is found */
            if (rx_words[i].u_bit.s_sdi_label == rx_words[j].u_bit.s_sdi_label)
            {
               /* Discard the word by indicating for the next lines it must be discarded */
               newer_word_found = TRUE;

               /* Stop the second loop (j) */
               j = msg_nb;
            }
         }

         /* If the word is the newest word for a specific sdi+label (=> no newer word has been found) */
         if (FALSE == newer_word_found)
         {
            /* For each received word */
            for (j = 0; j < SDI_LABEL_FILTERING_CONFIGURABLE_NB; j++)
            {
               /* If the word has a SDI+label which is defined in configuration table (to store in shared memory) */
               if ((uint16_t)rx_words[i].u_bit.s_sdi_label == a429_rx_sdi_label[j])
               {
                  /* Save the word in the shared memory */
                  shmem_a429_rx->s_rx_word[k] = rx_words[i].u_word;

                  /* Increment the number of sdi_label found */
                  k++;

                  /* Stop the second loop (j) */
                  j = SDI_LABEL_FILTERING_CONFIGURABLE_NB;
               }
            }
         }
      }

      /* Save the number of obtained word (k + 1) in the shared memory */
      shmem_a429_rx->s_rx_count = k;
   }

   /* Save the fault word in the shared memory */
   shmem_a429_rx->s_rx_status.u_bit.s_sram_parity_err = fault_word.u_bit.s_err_ram_parity;
   shmem_a429_rx->s_rx_status.u_bit.s_invalid = fault_word.u_bit.s_err_ram_parity;
   shmem_a429_rx->s_rx_status.u_bit.s_frame_parity_err = fault_word.u_bit.s_err_parity;
   shmem_a429_rx->s_rx_status.u_bit.s_frame_integrity_err = fault_word.u_bit.s_err_level |
      fault_word.u_bit.s_err_time_hbit_min |
      fault_word.u_bit.s_err_time_hbit_max |
      fault_word.u_bit.s_err_time_bit_min |
      fault_word.u_bit.s_err_time_bit_max |
      fault_word.u_bit.s_err_time_gap_min;

   return;
}

/* ---------- internal operations: ------------------------------------------ */
