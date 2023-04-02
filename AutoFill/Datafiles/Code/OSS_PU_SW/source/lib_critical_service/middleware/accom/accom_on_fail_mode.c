/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall provide the CSS_PU and MCSS_PU with these
 *    critical services, which should both execute in less than 1.3 ms from the
 *    call by the CSS_PU (or MCSS_PU) until return of service.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/accom/accom_fccu_private.h"
#include "middleware/accom/accom_fpga_common.h"
#include "middleware/accom/accom_gpio_common.h"
#include "middleware/accom/accom_public.h"


/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#define ACCOM_DEACTIVATED ((uint8_t) 0u) /* Enables FORCE_DISCONNECTION signal */
#define ACCOM_ACTIVATED ((uint8_t) 1u) /* Disables FORCE_DISCONNECTION signal */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements NO REQUIREMENT */
/**
 * Function to tell the FPGA to take the control from the local channel, and
 *   set the local FCCU to failure state, which will eventually cause a reset.
 */
void accom_on_fail_mode(void)
{
   /* Set the "non-ability to control the channel" state to TRUE in the FPGA */
   accom_fpga_reg->s_conf_reg.s_local_refusal_key = ACCOM_CST_REFUSAL_KEY_SET;
   /* Set the "channel refusal to control" state to TRUE in the FPGA */
   accom_fpga_reg->s_conf_reg.s_local_unable_key  = ACCOM_CST_UNABLE_KEY_SET;
   /* Set the "force disconnection requested" state to TRUE in the GPIO */
   *accom_gpo_179 = ACCOM_DEACTIVATED;
   /* Set the local FCCU to failure state,
    *   which will eventually cause a reset */
   accom_fccu_failure_set();
}

/* ---------- internal operations: ------------------------------------------ */
