/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Monitor e-breaker function
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
void ebreaker_monitor(
   /* INPUT */
   const te_ebreaker_rx_state    e_rx_state,
   const uint32_t                c_ebreaker_cmd)
{
   /* Local Variable Declaration        */
   void(*ebreaker1)(uint32_t) = ((void*)(EBREAKER_tab[e_rx_state].add_function_cmd_1));
   void(*ebreaker2)(uint32_t) = ((void*)(EBREAKER_tab[e_rx_state].add_function_cmd_2));

   /* Initialized value                 */

   /* Acquire e-breaker status from FPGA*/
   if( ebreaker_previous_cmd == EBREAKER_tab[e_rx_state].s_cmd_flow.s_ebreaker_cmd_1
      && c_ebreaker_cmd == EBREAKER_tab[e_rx_state].s_cmd_flow.s_ebreaker_cmd_2 )
   {
      /* In case of RX enable, state set to ENABLE */
      (*ebreaker1)((uint32_t)0);
      (*ebreaker2)((uint32_t)0);
   }

   /* Update global value */
   ebreaker_previous_cmd = c_ebreaker_cmd;

   /* WRITE in share memory the command value for e-breaker */
   shmem.s_ebreaker_enable = (uint32_t)0;

   return;
}
