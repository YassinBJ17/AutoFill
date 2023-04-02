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
#include "middleware/accom/accom_private.h"
#include "middleware/accom/accom_gpio_common.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* -- Accommodation data transmission to CSS_PU and MCSS_PU -- */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0060 */
/* Implements REQ_FADEX_OS_SRD-ACCOM-0090 */
/**
 * Function to get the channel_state data from the FPGA and GPIO.
 */
uint32_t accom_channel_state_read(void)
{
   uint32_t selection     = *accom_gpi_122;
   /* uint32_t decision      = *accom_gpi_161; */
   uint32_t frozen        = accom_fpga_reg->s_status_reg.u_field.s_freeze_sm_n;
   uint32_t channel_state = 0ul;

   /* Basic verifications : selection and frozen can either be 0 or 1. */
   if (1ul == selection && (1ul == frozen || 0ul == frozen))
   {
      /** If Selection is 1 and frozen is 0, channel state is 1.
       *  If Selection is 1 and frozen is 1, channel_state is 2.  */
      channel_state = selection+frozen;
   }
   /* If selection == 0, channel_state is also 0. */

   return channel_state;
}


/* ---------- internal operations: ------------------------------------------ */
