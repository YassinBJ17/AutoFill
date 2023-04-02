/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_ccdl function which allows logbook management at
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
void logbook_periodic_logs_ccdl(void)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* CCDL TX log */
   logbook_fill_event_block(&log, FCT_ID_CCDL_TX, shmem.s_ccdl_tx.s_fault_word.u_word,
                           exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* CCDL RX log */
   logbook_fill_event_block(&log, FCT_ID_CCDL_RX, shmem.s_ccdl_rx.s_fault_word.u_word,
                           exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
