/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall provide the CSS_PU and MCSS_PU with these
 *    critical services, which should both execute in less than 1.3 ms from the
 *    call by the CSS_PU (or MCSS_PU) until return of service.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/accom/accom_gpio_common.h"
#include "middleware/accom/accom_public.h"


/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0050 */
/**
 * Function to set cross-channel inconsistency state in the GPIO to K_FALSE.
 */
void accom_mcss_inconsistent_write_clear(void)
{
   *accom_gpo_208 = (uint8_t) 0x0;
   *accom_gpo_209 = (uint8_t) 0x1;
}

/* ---------- internal operations: ------------------------------------------ */
