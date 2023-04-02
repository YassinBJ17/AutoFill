/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The FPGA torque motor initialization
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/accom/accom_fccu_private.h"
#include "type/common_type.h"
#include "middleware/accom/accom_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-RESET-0010 */
/**
 * Function to set the FCCU in failure state.
 */
void accom_fccu_failure_set(void)
{
   tu_accom_fccu_cfg wanted_config;
   /* Prepare the settings to be written in the fccu_cfg register */
   wanted_config.u_word                    = (uint32_t)  0x00;
   wanted_config.u_field.s_set_after_reset = (uint32_t)   0b1;
   wanted_config.u_field.s_set_clear       = (uint32_t)  0b00;
   wanted_config.u_field.s_od              = (uint32_t)   0b1;
   wanted_config.u_field.s_ps              = (uint32_t)   0b0;
   wanted_config.u_field.s_fom             = (uint32_t) 0b010;
   /* Unlock the fccu registers and go to CONFIG mode */
   accom_fccu_cfg_unlock();
   /* Write the prepared settings in the FCCU_CFG register */
   FCCU.s_CFG.u_word = wanted_config.u_word;
   /*     Set up the following registers to manage the fault.     */
   /* Set the chosen bit to 1 (while the other bits remain untouched)
    *  to precise to the FCCU this bit of these registers will mean a Software Faults */
   FCCU.s_RF_CFG[1] |=   ACCOM_FCCU_FAULT_BIT_MASK;
   /* Set the chosen bit to 0 (while the other bits remain untouched)
    *  so that no timeout is applied before switching to the FAULT state */
   FCCU.s_RF_TOE[1] &= ~ ACCOM_FCCU_FAULT_BIT_MASK;
   /* Set the chosen bit to 1 (while the other bits remain untouched)
    *  to precise to the FCCU the alarm for this bit of this register will be enabled */
   FCCU.s_RF_E[1]   |=   ACCOM_FCCU_FAULT_BIT_MASK;
   /* Finally, set to 1 the Flag for this fault */
   FCCU.s_RF_S[1]   |=   ACCOM_FCCU_FAULT_BIT_MASK;
   /* Go back to NORMAL mode and apply the changes */
   accom_fccu_cfg_validate();
}

/* ---------- internal operations: ------------------------------------------ */
