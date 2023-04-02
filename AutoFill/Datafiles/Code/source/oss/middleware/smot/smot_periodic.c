/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Smot periodic function (CBIT)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "middleware/smot/smot_write_public.h"
#include "middleware/smot/smot_public.h"
#include "middleware/smot/smot_private.h"
#include "middleware/smot/smot_gpio_common.h"
#include "middleware/smot/smot_fpga_reg_common.h"
#include "memory/oss_section_def_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SMOT-0010 */
/* smot periodic function (CBIT) */
void smot_periodic(void)
{
   /* Smot phase state index */
   uint32_t smot_ph_state_idx;

   /* Smot monitoring voltage (acquired from SARADC_B) */
   float32_t smot_mon_voltage;

   /* Smot monitoring current (acquired from SARADC_B) */
   float32_t smot_mon_current;

   /* Set the smot write status to no fault */
   shmem.s_smot_w.s_fault_word.u_word = SMOT_STATUS_NO_FAULT;

   /* Acquire the smot monitoring data  */
   smot_acquire_samples(&smot_mon_voltage, &smot_mon_current);

   /* Acquire the smot phases state and affect it an index */
   smot_ph_state_acq(&smot_ph_state_idx);

   /* Update the smot CBIT fault word */
   smot_cbit(&smot_ph_state_idx,&smot_mon_voltage,&smot_mon_current);

   /* Transmit the smot monitoring voltage to the CSS_PU */
   shmem.s_smot_w.s_voltage = smot_mon_voltage;

   /* Transmit the smot monitoring current to the CSS_PU */
   shmem.s_smot_w.s_current = smot_mon_current;

   /* Transmit the smot phases state to the CSS_PU */
   shmem.s_smot_w.s_position = smot_ph_state_idx;
}

/* ---------- internal operations: ------------------------------------------ */
