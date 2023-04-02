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
#include "middleware/accom/accom_gpio_common.h"
#include "middleware/accom/accom_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
/* Mask for channel health word (bits 00 to 15) */
#define CHANNEL_HEALTH_WORD_MASK ((uint32_t)0x0000FFFF)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
tu_accom_info accom_info;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0090 */
/**
 * Function to provide the logbook capability with the accommodation data.
 */
void accom_info_for_logbook(void)
{
   /* Local channel health word (bits 00 to 15) */
   accom_info.u_word = shmem.s_health_wd_status.u_word & CHANNEL_HEALTH_WORD_MASK;
   /* Channel identifier */
   accom_info.u_bit.s_ch_id_on_one_bit = accom_ch_bit_fault_word.u_bit.s_ch_id;
   /* Channel decision */
   accom_info.u_bit.s_ch_decision      = *accom_gpi_161;
   /* Channel selection */
   accom_info.u_bit.s_ch_selection     = *accom_gpi_122;
}


/* ---------- internal operations: ------------------------------------------ */
