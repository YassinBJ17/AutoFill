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
 * Function to initialize the FCCU in Bi-stable mode.
 */
void accom_fccu_init(void)
{
   tu_accom_fccu_cfg wanted_config;
   /* Prepare the settings to be written in the fccu_cfg register */
   wanted_config.u_word                    = (uint32_t)  0x00;
   wanted_config.u_field.s_set_after_reset = (uint32_t)   0b1;
   wanted_config.u_field.s_set_clear       = (uint32_t)  0b00;
   wanted_config.u_field.s_od              = (uint32_t)   0b0;
   wanted_config.u_field.s_ps              = (uint32_t)   0b0;
   wanted_config.u_field.s_fom             = (uint32_t) 0b010;

   /* Unlock the fccu registers and go to CONFIG mode */
   accom_fccu_cfg_unlock();
   /* Write the prepared settings in the FCCU_CFG register */
   FCCU.s_CFG.u_word = wanted_config.u_word;
   /* Go back to NORMAL mode and apply the changes */
   accom_fccu_cfg_validate();
}

/* ---------- internal operations: ------------------------------------------ */
