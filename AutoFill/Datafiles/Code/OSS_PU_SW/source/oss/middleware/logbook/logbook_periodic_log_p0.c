/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_log_p0 function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"
#include "middleware/p0/p0_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_p0(const boolean_t p_channel_is_a)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_3;

   /* When the channel is B */
   if (FALSE == p_channel_is_a)
   {
      /* P0 log */
      raw_data_3.u_float = shmem.s_p0.s_measure;
      logbook_fill_event_block(&log, FCT_ID_P0, shmem.s_p0.s_fault_word.u_word, exception_context,
                              p0_internal_cbit, (uint32_t)p0_raw_value, raw_data_3.u_integer, SPARE_VALUE,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
}

/* ---------- internal operations: ------------------------------------------ */
