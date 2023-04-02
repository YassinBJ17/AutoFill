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
 * Function to provide the CSS_PU and MCSS_PU the accommodation data, using the
 *   shared memory.
 */
void accom_periodic(void)
{
   /* Local channel health word, as per the FPGA */
   shmem.s_health_wd_status.u_word =
               accom_fpga_reg->s_status_reg.u_field.s_loc_health_word;
   /* Cross-channel health word, as per the FPGA */
   shmem.s_o_health_wd_status_fpga.u_word =
               accom_fpga_reg->s_status_reg.u_field.s_opp_health_word;
   /** An other version of the cross channel health word,
    *    called s_o_health_wd_status_ccdl, is acquired via CCDL. */

   /* Channel_state data */
   shmem.s_channel_state.s_channel_state = accom_channel_state_read();

   /* Channel Pref status */
   shmem.s_channel_state.s_channel_pref =
               accom_fpga_reg->s_conf_reg.s_loc_param.u_field.s_pref;

   /* Channel Sync status */
   shmem.s_channel_state.s_channel_sync = sync_sts_reg->s_bit.s_sync_ok;

   /* Channel ID (full-word) */
   shmem.s_channel_id = ch_id;

   /****    LOCAL MCSS INCONSISTENCY    ****/
   /* Opposite channel inconsistency */
   shmem.s_local_mcss_inconsistency.u_bit.s_opp_inconsistent =
               accom_fpga_reg->s_status_reg.u_field.s_opp_inconsistent;
   /* Opposite channel inconsistency (complemented) */
   shmem.s_local_mcss_inconsistency.u_bit.s_opp_inconsistent_n =
               accom_fpga_reg->s_status_reg.u_field.s_opp_inconsistent_n;
   /* Fault bit for the coherence between both previous values */
   shmem.s_local_mcss_inconsistency.u_bit.s_inconsistency_status =
               accom_fpga_reg->s_status_reg.u_field.s_inconsistent_fault;

   accom_info_for_logbook();
}


/* ---------- internal operations: ------------------------------------------ */
