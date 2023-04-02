/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_a429 function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_a429(const boolean_t p_channel_is_a)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      /* A429 1A TX log */
      logbook_fill_event_block(&log, FCT_ID_A429_1A_TX, shmem.s_a429_1a_tx.s_tx_status.u_word,
                              exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);

      /* A429 1A RX log */
      logbook_fill_event_block(&log, FCT_ID_A429_1A_RX, shmem.s_a429_1a_rx.s_rx_status.u_word,
                              exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
   /* When the channel is B */
   else
   {
      /* A429 2AB TX log */
      logbook_fill_event_block(&log, FCT_ID_A429_2AB_TX, shmem.s_a429_2ab_tx.s_tx_status.u_word,
                              exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }

   /* A429 2AB RX log */
   logbook_fill_event_block(&log, FCT_ID_A429_2AB_RX, shmem.s_a429_2ab_rx.s_rx_status.u_word,
                           exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
