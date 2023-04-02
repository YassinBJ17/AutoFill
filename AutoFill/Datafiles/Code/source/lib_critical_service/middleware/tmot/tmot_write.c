/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Transmit the CSS_PU command to FPGA when the command is valid
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "middleware/tmot/tmot_write_public.h"
#include "middleware/tmot/tmot_fpga_reg_common.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0001 */
/* Transmit the CSS_PU command to FPGA when the command is valid */
void tmot_write(void)
{

   float32_t current_to_volt;

   /* If the CSS_PU command is out of range */
   if (shmem.s_tmot_w.s_current < TMOT_CURRENT_CMD_MIN || shmem.s_tmot_w.s_current > TMOT_CURRENT_CMD_MAX)
   {
      /* Indicate the CSS_PU command is out of range to CSS_PU */
      shmem.s_tmot_w.s_fault_word.u_bit.s_out_of_range = (uint32_t)1;
   }
   else
   {
      /* Indicate the CSS_PU command is in the expected range to CSS_PU */
      shmem.s_tmot_w.s_fault_word.u_bit.s_out_of_range = (uint32_t)0;

      current_to_volt = ((shmem.s_tmot_w.s_current + CURR_OFFSET) * CONV_CURR_TO_VOLT);

      /* Transmit the CSS_PU command to the FPGA (current command is converted in voltage for FPGA) */
      tmot_fpga_reg->u_field.s_voltage_cmd = (uint32_t)current_to_volt;

      /* Ack command for CSS */
      shmem.s_tmot_w.s_current = 0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
