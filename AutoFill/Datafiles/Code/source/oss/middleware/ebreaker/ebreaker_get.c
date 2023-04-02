/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Get the state of e-breaker function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ebreaker/ebreaker_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */
void ebreaker_get(
   /* OUTPUT */
   te_ebreaker_rx_state*  const p_rx_state,
   uint32_t *             const p_ebreaker_cmd)
{
   /* Local Variable Declaration        */
   reg32_t          v_fpga_state;

   /* Initialized value                 */
   v_fpga_state     = ( ( (*FPGA_RX_STATUS) & MASK_FPGA_RX_ENABLE ) >> OFFSET_FPGA_RX_ENABLE );

   /* Acquire e-breaker status from FPGA*/
   if( v_fpga_state == FPGA_EBREACKER_OPER_VALUE)
   {
      /* In case of RX enable, state set to ENABLE */
      *p_rx_state = e_ebreaker_rx_enable;
   }
   else
   {
      /* Otherwise set to disengage */
      *p_rx_state = e_ebreaker_rx_disable;
   }

   /* READ in share memory the command value for e-breaker */
   *p_ebreaker_cmd = shmem.s_ebreaker_enable ;

   return;
}
