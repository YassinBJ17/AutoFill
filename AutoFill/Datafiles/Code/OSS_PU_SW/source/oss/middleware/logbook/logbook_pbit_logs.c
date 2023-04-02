/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_pbit_logs function which manages PBIT logs
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/pbit/pbit_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* ID of PBIT logs */
#define FCT_ID_PBIT_MRAM_BUS ((uint32_t)0x00000007)
#define FCT_ID_PBIT_OVS_COM  ((uint32_t)0x00000008)

/* Spare value */
#define SPARE_VALUE     ((uint32_t)0)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void logbook_pbit_logs(void)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* MRAM parallel bus test log */
   logbook_fill_event_block(&log, FCT_ID_PBIT_MRAM_BUS, shmem.s_pbit_fault_word.u_word, exception_context,
                            pbit_mram_faulty_addr, pbit_mram_faulty_data, SPARE_VALUE, SPARE_VALUE,
                            SPARE_VALUE, SPARE_VALUE);
   logbook_save_log(&log);

   /* OVS communication test log */
   logbook_fill_event_block(&log, FCT_ID_PBIT_OVS_COM, shmem.s_pbit_fault_word.u_word, exception_context,
                            SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
