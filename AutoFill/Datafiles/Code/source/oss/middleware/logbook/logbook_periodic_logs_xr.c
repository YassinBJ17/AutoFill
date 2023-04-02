/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_xr function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"
#include "middleware/resolver/resolver_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_xr(const boolean_t p_channel_is_a)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_1;
   tu_raw_data    raw_data_2;
   tu_raw_data    raw_data_3;
   tu_raw_data    raw_data_4;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      /* XR log */
      raw_data_1.u_float = xr_exc;
      raw_data_2.u_float = shmem.s_xr.s_vsin_measure;
      raw_data_3.u_float = shmem.s_xr.s_vcos_measure;
      raw_data_4.u_float = shmem.s_xr.s_measure;
      logbook_fill_event_block(&log, FCT_ID_XR, shmem.s_xr.s_fault_word.u_word, exception_context,
                              raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
   /* When the channel is B */
   else
   {
      /* XR log */
      raw_data_1.u_float = xrb_exc;
      raw_data_2.u_float = shmem.s_xr_b.s_vsin_measure;
      raw_data_3.u_float = shmem.s_xr_b.s_vcos_measure;
      raw_data_4.u_float = shmem.s_xr_b.s_measure;
      logbook_fill_event_block(&log, FCT_ID_XRB, shmem.s_xr_b.s_fault_word.u_word, exception_context,
                              raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
}

/* ---------- internal operations: ------------------------------------------ */
