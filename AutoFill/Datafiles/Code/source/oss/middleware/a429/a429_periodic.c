/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : A429 RX & TX calls
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/a429/a429_private.h"
#include "middleware/a429/a429_public.h"
#include "middleware/ccdl/ccdl_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-A429-0020 */
/* Implements REQ_FADEX_OS_SRD-A429-0030 */
/* Read and transmit A429 message(s) (Input : Is it the channel A?) */
void a429_periodic(const boolean_t ch_is_a)
{
   /* A429 2AB messages to be transmitted and their number */
   ts_a429_tx* a429_2ab_tx_msg;

   /* If the channel identifier is A (=> CPMB) */
   if (TRUE == ch_is_a)
   {
      /* Send messages for A429 1A link */
      a429_tx(a429_1a_words_max, fpga_a429_1a_tx, (ts_a429_tx *)&(shmem.s_a429_1a_tx));

      /* Receive messages for A429 1A link */
      a429_rx(a429_1a_words_max, fpga_a429_1a_rx, (ts_a429_rx *)&(shmem.s_a429_1a_rx), a429_1a_rx_sdi_label);
   }
   /* If the channel identifier is B (=> CPB) */
   else
   {
      /* If the message to send is from channel A */
      if ((uint32_t)0 == a429_2ab_tx_conf)
      {
         /* Obtain the number of messages and the messages from CCDL */
         a429_2ab_tx_msg = &ccdl_a429_2ab_tx_from_ch_a;
      }
      /* If the message to send is from channel B */
      else if ((uint32_t)1 == a429_2ab_tx_conf)
      {
         /* Obtain the number of messages and the messages from the local shared memory */
         a429_2ab_tx_msg = (ts_a429_tx *)&(shmem.s_a429_2ab_tx);
      }
      /* If the message to send is from the channel in control */
      else
      {
         /* If the channel is in control */
         if ((uint32_t)1 == shmem.s_channel_state.s_channel_state || (uint32_t)2 == shmem.s_channel_state.s_channel_state)
         {
            /* Obtain the number of messages and the messages from the local shared memory */
            a429_2ab_tx_msg = (ts_a429_tx *)&(shmem.s_a429_2ab_tx);
         }
         /* Else if the channel is not in control */
         else
         {
            /* Obtain the number of messages and the messages from CCDL */
            a429_2ab_tx_msg = &ccdl_a429_2ab_tx_from_ch_a;
         }
      }

      /* Send messages for A429 2AB link */
      a429_tx(a429_2ab_words_max, fpga_a429_2ab_tx, a429_2ab_tx_msg);
   }

   /* Receive messages for A429 2AB link */
   a429_rx(a429_2ab_words_max, fpga_a429_2ab_rx, (ts_a429_rx *)&(shmem.s_a429_2ab_rx), a429_2ab_rx_sdi_label);

   return;
}

/* ---------- internal operations: ------------------------------------------ */
