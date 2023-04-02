/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_svoi_eman function which allows logbook management at
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
void logbook_periodic_logs_svoi_eman(void)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* SVOI log */
   logbook_fill_event_block(&log, FCT_ID_SVOI, shmem.s_svoi.s_fault_word.u_word, exception_context,
                           SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, shmem.s_svoi.s_raw_measure,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* EMAN log */
   logbook_fill_event_block(&log, FCT_ID_EMAN, shmem.s_eman.s_fault_word.u_word, exception_context,
                           SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, shmem.s_eman.s_raw_measure,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
