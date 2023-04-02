/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : PBIT EBI test on external SRAM
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PBIT-0010 */
/* PBIT EBI test function on external SRAM */
void pbit_reset(const uint32_t err_flag, const uint32_t p_last_faulty_address, const uint32_t p_last_faulty_data)
{
   if ((uint32_t)1 == err_flag)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(p_last_faulty_address, p_last_faulty_data);

      /* WD reset */
      reset_critical();
   }

}

/* ---------- internal operations: ------------------------------------------ */
