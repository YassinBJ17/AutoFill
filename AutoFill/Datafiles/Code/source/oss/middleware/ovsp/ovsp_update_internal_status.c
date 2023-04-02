/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP update internal status
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */


/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-CANOVS-0060 */
/* OVSP update internal status */
void ovsp_update_internal_status(boolean_t is_ovsp_ls)
{
   if(is_ovsp_ls)
   {
      /* Fill the OVSP LS internal fault word */
      ovsp_ls_fault_word.u_bit.s_status_cmd1              = ls_resp_frame_format_1.s_ovs_status.s_cmd1_status;
      ovsp_ls_fault_word.u_bit.s_status_cmd2              = ls_resp_frame_format_1.s_ovs_status.s_cmd2_status;
      ovsp_ls_fault_word.u_bit.s_ovs_mode                 = ls_resp_frame_format_1.s_ovs_status.s_mode;
      ovsp_ls_fault_word.u_bit.s_ovs_config_reception     = ls_resp_frame_format_1.s_ovs_status.s_ovsp_config_reception;
      ovsp_ls_fault_word.u_bit.s_ovs_config_integrity     = ls_resp_frame_format_1.s_ovs_status.s_ovsp_config_integrity;
      ovsp_ls_fault_word.u_bit.s_dininhib_state           = ls_resp_frame_format_1.s_discrete_input.s_dininhib_val;
      ovsp_ls_fault_word.u_bit.s_osrearm_state            = ls_resp_frame_format_1.s_discrete_input.s_osrearm_val;
      ovsp_ls_fault_word.u_bit.s_time_out_ntlos1          = ls_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_time;
      ovsp_ls_fault_word.u_bit.s_time_out_ntlos2          = ls_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_time;
      ovsp_ls_fault_word.u_bit.s_meas_update_ntlos1       = ls_resp_frame_format_1.s_ntl_status.s_ntlos1_updated;
      ovsp_ls_fault_word.u_bit.s_meas_update_ntlos2       = ls_resp_frame_format_1.s_ntl_status.s_ntlos2_updated;
      ovsp_ls_fault_word.u_bit.s_out_of_range_high_ntlos1 = ls_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_range_high;
      ovsp_ls_fault_word.u_bit.s_out_of_range_high_ntlos2 = ls_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_range_high;
      ovsp_ls_fault_word.u_bit.s_time_out_ngos1           = ls_resp_frame_format_1.s_ng_status.s_ngos1_out_of_time;
      ovsp_ls_fault_word.u_bit.s_time_out_ngos2           = ls_resp_frame_format_1.s_ng_status.s_ngos2_out_of_time;
      ovsp_ls_fault_word.u_bit.s_meas_update_ngos1        = ls_resp_frame_format_1.s_ng_status.s_ngos1_updated;
      ovsp_ls_fault_word.u_bit.s_meas_update_ngos2        = ls_resp_frame_format_1.s_ng_status.s_ngos2_updated;
      ovsp_ls_fault_word.u_bit.s_out_of_range_high_ngos1  = ls_resp_frame_format_1.s_ng_status.s_ngos1_out_of_range_high;
      ovsp_ls_fault_word.u_bit.s_out_of_range_high_ngos2  = ls_resp_frame_format_1.s_ng_status.s_ngos2_out_of_range_high;

   }
   else
   {
      /* OVSP HS internal fault word */
      ovsp_hs_fault_word.u_bit.s_status_cmd1              = hs_resp_frame_format_1.s_ovs_status.s_cmd1_status;
      ovsp_hs_fault_word.u_bit.s_status_cmd2              = hs_resp_frame_format_1.s_ovs_status.s_cmd2_status;
      ovsp_hs_fault_word.u_bit.s_ovs_mode                 = hs_resp_frame_format_1.s_ovs_status.s_mode;
      ovsp_hs_fault_word.u_bit.s_ovs_config_integrity     = hs_resp_frame_format_1.s_ovs_status.s_ovsp_config_integrity;
      ovsp_hs_fault_word.u_bit.s_ovs_config_integrity     = hs_resp_frame_format_1.s_ovs_status.s_ovsp_config_integrity;
      ovsp_hs_fault_word.u_bit.s_dininhib_state           = hs_resp_frame_format_1.s_discrete_input.s_dininhib_val;
      ovsp_hs_fault_word.u_bit.s_osrearm_state            = hs_resp_frame_format_1.s_discrete_input.s_osrearm_val;
      ovsp_hs_fault_word.u_bit.s_camlow2_fb               = hs_resp_frame_format_1.s_discrete_output.s_camlow2_fb_or_unused;
      ovsp_hs_fault_word.u_bit.s_osarm_fb                 = hs_resp_frame_format_1.s_discrete_output.s_osarm_fb_or_unused;
      ovsp_hs_fault_word.u_bit.s_time_out_ntlos1          = hs_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_time;
      ovsp_hs_fault_word.u_bit.s_time_out_ntlos2          = hs_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_time;
      ovsp_hs_fault_word.u_bit.s_meas_update_ntlos1       = hs_resp_frame_format_1.s_ntl_status.s_ntlos1_updated;
      ovsp_hs_fault_word.u_bit.s_meas_update_ntlos2       = hs_resp_frame_format_1.s_ntl_status.s_ntlos2_updated;
      ovsp_hs_fault_word.u_bit.s_out_of_range_high_ntlos1 = hs_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_range_high;
      ovsp_hs_fault_word.u_bit.s_out_of_range_high_ntlos2 = hs_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_range_high;
      ovsp_hs_fault_word.u_bit.s_time_out_ngos1           = hs_resp_frame_format_1.s_ng_status.s_ngos1_out_of_time;
      ovsp_hs_fault_word.u_bit.s_time_out_ngos2           = hs_resp_frame_format_1.s_ng_status.s_ngos2_out_of_time;
      ovsp_hs_fault_word.u_bit.s_meas_update_ngos1        = hs_resp_frame_format_1.s_ng_status.s_ngos1_updated;
      ovsp_hs_fault_word.u_bit.s_meas_update_ngos2        = hs_resp_frame_format_1.s_ng_status.s_ngos2_updated;
      ovsp_hs_fault_word.u_bit.s_out_of_range_high_ngos1  = hs_resp_frame_format_1.s_ng_status.s_ngos1_out_of_range_high;
      ovsp_hs_fault_word.u_bit.s_out_of_range_high_ngos2  = hs_resp_frame_format_1.s_ng_status.s_ngos2_out_of_range_high;
   }
}
/* ---------- internal operations: ------------------------------------------ */
