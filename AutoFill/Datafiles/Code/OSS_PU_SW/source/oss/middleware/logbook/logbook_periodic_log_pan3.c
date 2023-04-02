/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_log_pan3 function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "middleware/pan3/pan3_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_pan3(const boolean_t p_channel_is_a)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* When the channel is B */
   if (FALSE == p_channel_is_a)
   {
      /* PAN3 log */
      logbook_fill_event_block(&log, FCT_ID_PAN3, v_pan3_status_word.u_word, exception_context,
                              SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, v_pan3_status_word.u_bit.s_commanded,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
}

/* ---------- internal operations: ------------------------------------------ */
