/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_mram function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_mram(void)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* MRAM bus log */
   logbook_fill_event_block(&log, FCT_ID_MRAM_BUS, SPARE_VALUE, exception_context,
                           (uint32_t)0, (uint32_t)0, SPARE_VALUE, SPARE_VALUE, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* MRAM log */
   logbook_fill_event_block(&log, FCT_ID_MRAM, SPARE_VALUE, exception_context,
                           (uint32_t)0, (uint32_t)0, SPARE_VALUE, SPARE_VALUE, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
