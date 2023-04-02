/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall provide the CSS_PU and MCSS_PU with these
 *    critical services, which should both execute in less than 1.3 ms from the
 *    call by the CSS_PU (or MCSS_PU) until return of service.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/accom/accom_fpga_common.h"
#include "middleware/accom/accom_public.h"


/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0040 */
/**
 * Function to set the channel non-prefered state in the FPGA to K_TRUE.
 */
void accom_preferential_channel_refuse_write_set(void)
{
   accom_fpga_reg->s_conf_reg.s_local_pref_key = ACCOM_CST_PREF_KEY_SET;
}

/* ---------- internal operations: ------------------------------------------ */
