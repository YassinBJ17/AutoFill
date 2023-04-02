/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_log_smot function which allows logbook management at
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
void logbook_periodic_log_smot(void)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_1;
   tu_raw_data    raw_data_3;
   tu_raw_data    raw_data_4;

   /* SMOT log */
   raw_data_1.u_signed_int = shmem.s_smot_w.s_half_step_nb;
   raw_data_3.u_float = shmem.s_smot_w.s_voltage;
   raw_data_4.u_float = shmem.s_smot_w.s_current;
   logbook_fill_event_block(&log, FCT_ID_SMOT, shmem.s_smot_w.s_fault_word.u_word, exception_context,
                            raw_data_1.u_integer, shmem.s_smot_w.s_position, raw_data_3.u_integer,
                            raw_data_4.u_integer, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
