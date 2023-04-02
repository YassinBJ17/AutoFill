/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_log_sync function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/memory_address_public.h"

#include "middleware/tecu/tecu_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* Address of Synchronization status register in FPGA */
#define FPGA_SYNC_STS_REG     ((uint32_t *)0x2402001C)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_sync(void)
{
   /* Synchronization status register in FPGA */
   const uint32_t *fpga_sync_sts_reg = FPGA_SYNC_STS_REG;

   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Sync log */
   logbook_fill_event_block(&log, FCT_ID_SYNC, *fpga_sync_sts_reg, exception_context,
                           SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
