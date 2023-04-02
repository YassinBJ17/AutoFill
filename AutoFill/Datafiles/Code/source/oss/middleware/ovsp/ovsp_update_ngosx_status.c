/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Update ngosx shared memory status
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "conf/oss_conf_public.h"
#include "memory/lib_critical_service_section_def_data.h"


/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */


/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-CANOVS-0060 */
/* Update ngosx shared memory status */
void ovsp_update_ngosx_status(uint32_t const can_x_reg_addr)
{
   /* Local variables */
   ts_can_reg_t* p_can_reg_descr;

   /* declaration of the struc to retrieve conf in MRAM */
   ts_oss_conf_table * oss_conf;

   /* Get the driver registers in local variable */
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table *)(OSS_CONF_START_ADDR);

   shmem.s_ngos1.s_fault_word.u_word = 0;
   shmem.s_ngos2.s_fault_word.u_word = 0;

   /******************************* Out Of Time Measure detection **********************************/

   if((uint32_t)1 == hs_resp_frame_format_1.s_ng_status.s_ngos1_out_of_time && (uint32_t)1 == ls_resp_frame_format_1.s_ng_status.s_ngos1_out_of_time)
   {
      shmem.s_ngos1.s_fault_word.u_bit.s_time_out = (uint32_t)1;

      shmem.s_ngos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   if((uint32_t)1 == hs_resp_frame_format_1.s_ng_status.s_ngos2_out_of_time && (uint32_t)1 == ls_resp_frame_format_1.s_ng_status.s_ngos2_out_of_time)
   {
      shmem.s_ngos2.s_fault_word.u_bit.s_time_out = (uint32_t)1;

      shmem.s_ngos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /******************************* Out Of Range Measure detection **********************************/

   if((uint32_t)1 == hs_resp_frame_format_1.s_ng_status.s_ngos1_out_of_range_high && (uint32_t)1 == ls_resp_frame_format_1.s_ng_status.s_ngos1_out_of_range_high)
   {
      shmem.s_ngos1.s_fault_word.u_bit.s_out_of_range = (uint32_t)1;

      shmem.s_ngos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   if((uint32_t)1 == hs_resp_frame_format_1.s_ng_status.s_ngos2_out_of_range_high && (uint32_t)1 == ls_resp_frame_format_1.s_ng_status.s_ngos2_out_of_range_high)
   {
      shmem.s_ngos2.s_fault_word.u_bit.s_out_of_range = (uint32_t)1;

      shmem.s_ngos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /************************* MPC REGISTER VALUE *********************************/

   if((uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_crce || (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf0f ||
      (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf1f || (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf1l ||
      (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf0l || (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_ste  ||
      (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_foe)
   {
      shmem.s_ngos1.s_fault_word.u_bit.s_transfer_err = (uint32_t)1;

      shmem.s_ngos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;

      shmem.s_ngos2.s_fault_word.u_bit.s_transfer_err = (uint32_t)1;

      shmem.s_ngos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /*********************** Inconsistency freq ***********************************/

   if((uint32_t)0 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ngos_ls && (uint32_t)0 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ngos_hs
      && ((((((shmem.s_ngalt_a.s_measure*oss_conf->s_ovs_ngos1ngaltaratio) - hs_resp_frame_format_2.s_ngos1_measure.float32_val)/hs_resp_frame_format_2.s_ngos1_measure.float32_val) * 100) > (float32_t)10)
      || (((((shmem.s_ngalt_b.s_measure*oss_conf->s_ovs_ngos1ngaltbratio) - hs_resp_frame_format_2.s_ngos1_measure.float32_val)/hs_resp_frame_format_2.s_ngos1_measure.float32_val) * 100) > (float32_t)10)))
   {
      shmem.s_ngos1.s_fault_word.u_bit.s_incons_NGOS1_NGALT = (uint32_t)1;

      shmem.s_ngos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /************************ NGOSx inconsistency *******************************/

   if((uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ngos_hs || (uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ngos_ls ||
      (uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ngos_hs_ls)
   {
      shmem.s_ngos1.s_fault_word.u_bit.s_intern_failure = (uint32_t)1;

      shmem.s_ngos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;

      shmem.s_ngos2.s_fault_word.u_bit.s_intern_failure = (uint32_t)1;

      shmem.s_ngos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;

   }

   /************************** NGALT measure inconsistency ********************************/

   if((uint32_t)1 == shmem.s_ngos1.s_fault_word.u_bit.s_time_out && ((shmem.s_ngalt_a.s_measure > 0.1 * oss_conf->s_ngalt_th_frequency)  ||
                                                                     (shmem.s_ngalt_b.s_measure > 0.1 * oss_conf->s_ngalt_th_frequency)))
   {
      shmem.s_ngos1.s_fault_word.u_bit.s_open_circuit = (uint32_t)1;

      shmem.s_ngos1.s_fault_word.u_bit.s_short_diff = (uint32_t)1;
   }

   if((uint32_t)1 == shmem.s_ngos2.s_fault_word.u_bit.s_time_out && ((shmem.s_ngalt_a.s_measure > 0.1 * oss_conf->s_ngalt_th_frequency)  ||
                                                                     (shmem.s_ngalt_b.s_measure > 0.1 * oss_conf->s_ngalt_th_frequency)))
   {
      shmem.s_ngos2.s_fault_word.u_bit.s_open_circuit = (uint32_t)1;

      shmem.s_ngos2.s_fault_word.u_bit.s_short_diff = (uint32_t)1;
   }


}
/* ---------- internal operations: ------------------------------------------ */
