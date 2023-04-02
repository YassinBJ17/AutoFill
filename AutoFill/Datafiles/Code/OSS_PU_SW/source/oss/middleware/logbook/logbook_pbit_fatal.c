/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_pbit_fatal function which manages PBIT logs
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

/* ---------- internal define constants: ------------------------------------ */
/* ID of PBIT fatal logs */
#define FCT_ID_PBIT_FATAL  ((uint32_t)0x00000006)

/* Spare value */
#define SPARE_VALUE        ((uint32_t)0)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PBIT-0010 */
void logbook_pbit_fatal(const uint32_t p_last_addr, const uint32_t p_last_data)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* PBIT Fatal Log */
   logbook_fill_event_block(&log, FCT_ID_PBIT_FATAL, shmem.s_pbit_fault_word.u_word, exception_context,
                            p_last_addr, p_last_data, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
