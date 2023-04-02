/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP_LS update shared memory status
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "memory/lib_critical_service_section_def_data.h"

extern float32_t LIB_MATH_FABS(const float32_t p_input);

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */


/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-CANOVS-0060 */
/* OVSP_LS update shared memory status */
void ovsp_update_ls_shmem_status(void)
{
   if((float32_t)(LIB_MATH_FABS((ls_resp_frame_format_3.s_ntlos1_measure.float32_val - ls_resp_frame_format_3.s_ntlos2_measure.float32_val)/ls_resp_frame_format_3.s_ntlos2_measure.float32_val)*100)>(float32_t)10)
   {
      shmem.s_ovs.s_ovs_state.u_bit.s_incons_ntlos_lss = (uint32_t)1;
   }

   if((float32_t)(LIB_MATH_FABS((ls_resp_frame_format_2.s_ngos1_measure.float32_val - ls_resp_frame_format_2.s_ngos2_measure.float32_val)/ls_resp_frame_format_2.s_ngos2_measure.float32_val)*100)>(float32_t)10)
   {
      shmem.s_ovs.s_ovs_state.u_bit.s_incons_ngos_ls = (uint32_t)1;
   }

   if((float32_t)(LIB_MATH_FABS(hs_resp_frame_format_3.s_ntlos1_measure.float32_val-ls_resp_frame_format_3.s_ntlos1_measure.float32_val)/100)>(float32_t)10)
   {
      shmem.s_ovs.s_ovs_state.u_bit.s_incons_ntlos_hs_ls = (uint32_t)1;
   }

   if((float32_t)(LIB_MATH_FABS(hs_resp_frame_format_2.s_ngos1_measure.float32_val-ls_resp_frame_format_2.s_ngos1_measure.float32_val)/100)>(float32_t)10)
   {
      shmem.s_ovs.s_ovs_state.u_bit.s_incons_ngos_hs_ls = (uint32_t)1;
   }

   if((uint32_t)0 == ls_resp_frame_format_1.s_ovs_status.s_cmd1_status && (uint32_t)0 == ls_resp_frame_format_1.s_ovs_status.s_cmd2_status ||
      (uint32_t)0 == hs_resp_frame_format_1.s_ovs_status.s_cmd1_status && (uint32_t)0 == hs_resp_frame_format_1.s_ovs_status.s_cmd2_status)
   {
      /* Erronemous LS command detection */
      if(hs_resp_frame_format_4.s_ovs_hs_cam_vload.float32_val < OVSP_CAM_VOLT_THOLD_MIN_LS_CMD)
      {
         shmem.s_ovs.s_ovs_state.u_bit.s_cam_err_cmd_ls = (uint32_t)1;
      }
      /* Open circuit detection */
      if(OVSP_CAM_VOLT_THOLD_MIN < (float32_t)hs_resp_frame_format_4.s_ovs_hs_cam_vload.float32_val < OVSP_CAM_VOLT_THOLD_MAX)
      {
         shmem.s_ovs.s_ovs_state.u_bit.s_cam_out_open_circuit = (uint32_t)1;
      }

      if(hs_resp_frame_format_4.s_ovs_hs_cam_vload.float32_val > OVSP_CAM_VOLT_THOLD_MAX)
      {
         shmem.s_ovs.s_ovs_state.u_bit.s_cam_err_cmd_hs = (uint32_t)1;
      }
   }


   if((uint32_t)1 == hs_resp_frame_format_1.s_ovs_status.s_ovsp_config_integrity)
   {
      shmem.s_ovs.s_ovs_state.u_bit.s_ovsp_config_integ = (uint32_t)1;

      shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_hs = (uint32_t)1;
   }
}
/* ---------- internal operations: ------------------------------------------ */
