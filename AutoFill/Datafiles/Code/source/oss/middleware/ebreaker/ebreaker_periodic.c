/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Perform periodic function for ebreaker
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ebreaker/ebreaker_public.h"
#include "middleware/ebreaker/ebreaker_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/rtc/rtc_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */
void ebreaker_periodic(void)
{
   /* Local Variable Declaration        */
   te_ebreaker_rx_state   e_rx_state;
   uint32_t               v_ebreaker_cmd;

   /* Initialized value                 */
   v_ebreaker_cmd         = EBREACKER_INIT_VALUE;

   /* Acquire e-breaker status from FPGA and share memory */
   ebreaker_get(
      &e_rx_state,
      &v_ebreaker_cmd);

   /* Monitoring e-breaker state */
   ebreaker_monitor(
      e_rx_state,
      v_ebreaker_cmd);

   return;
}
