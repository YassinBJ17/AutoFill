/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_lp function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"
#include "middleware/lpdisc/lpdisc_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* Number of LP devices */
#define LP_DEVICE_NB    ((uint32_t)10)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_lp(void)
{
   /* Iterators */
   uint32_t i;

   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* LP 01 to 10 logs */
   for (i = (uint32_t)0; i < LP_DEVICE_NB; i++)
   {
      logbook_fill_event_block(&log, (FCT_ID_LP01 + i), shmem.s_lp_w.s_lp_status[i].u_word, exception_context,
                              shmem.s_lp_w.s_lp_command[i], SPARE_VALUE, SPARE_VALUE, (uint32_t)lpdisc_mon_state[i],
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
}

/* ---------- internal operations: ------------------------------------------ */
