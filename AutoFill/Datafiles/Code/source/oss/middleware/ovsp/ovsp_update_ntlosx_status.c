/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Update ntlosx shared memory status
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "conf/oss_conf_public.h"
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
/* Update ntlosx shared memory status */
void ovsp_update_ntlosx_status(uint32_t const can_x_reg_addr)
{

   /* Local variables */
   ts_can_reg_t* p_can_reg_descr;

   /* declaration of the struc to retrieve conf in MRAM */
   ts_oss_conf_table * oss_conf;

   /* Get the driver registers in local variable */
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table *)(OSS_CONF_START_ADDR);

   shmem.s_ntlos1.s_fault_word.u_word = 0;
   shmem.s_ntlos2.s_fault_word.u_word = 0;


   /******************************* Out Of Time Measure detection **********************************/

   if((uint32_t)1 == hs_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_time && (uint32_t)1 == ls_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_time)
   {
      shmem.s_ntlos1.s_fault_word.u_bit.s_time_out = (uint32_t)1;

      shmem.s_ntlos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   if((uint32_t)1 == hs_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_time && (uint32_t)1 == ls_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_time)
   {
      shmem.s_ntlos2.s_fault_word.u_bit.s_time_out = (uint32_t)1;

      shmem.s_ntlos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /******************************* Out Of Range Measure detection **********************************/

   if((uint32_t)1 == hs_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_range_high &&  (uint32_t)1 == ls_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_range_high)
   {
      shmem.s_ntlos1.s_fault_word.u_bit.s_out_of_range = (uint32_t)1;

      shmem.s_ntlos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   if((uint32_t)1 == hs_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_range_high && (uint32_t)1 == ls_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_range_high)
   {
      shmem.s_ntlos2.s_fault_word.u_bit.s_out_of_range = (uint32_t)1;

      shmem.s_ntlos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /************************* MPC REGISTER VALUE *********************************/

   if((uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_crce || (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf0f ||
      (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf1f || (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf1l ||
      (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_rf0l || (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_ste  ||
      (uint32_t)1 == p_can_reg_descr->s_ir.u_bit.s_foe)
   {
      shmem.s_ntlos1.s_fault_word.u_bit.s_transfer_err = (uint32_t)1;

      shmem.s_ntlos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;

      shmem.s_ntlos2.s_fault_word.u_bit.s_transfer_err = (uint32_t)1;

      shmem.s_ntlos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /*********************** Inconsistency freq ***********************************/

   if((uint32_t)0 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ntlos_lss && (uint32_t)0 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ntlos_hs
      && ((((((shmem.s_nfreq2_a.s_measure*oss_conf->s_ovs_ntlos1ntlaratio) - hs_resp_frame_format_3.s_ntlos1_measure.float32_val)/hs_resp_frame_format_3.s_ntlos1_measure.float32_val) * 100) > (float32_t)10)
      || (((((shmem.s_nfreq2_b.s_measure*oss_conf->s_ovs_ntlos1ntlbratio) - hs_resp_frame_format_3.s_ntlos1_measure.float32_val)/hs_resp_frame_format_3.s_ntlos1_measure.float32_val) * 100) > (float32_t)10)))
   {
      shmem.s_ntlos1.s_fault_word.u_bit.s_incons_NTLOS1_NFREQ2 = (uint32_t)1;

      shmem.s_ntlos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }


   /************************ NTLOSx inconsistency *******************************/

   if((uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ntlos_hs || (uint32_t) 1==  shmem.s_ovs.s_ovs_state.u_bit.s_incons_ntlos_lss ||
      (uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_incons_ntlos_hs_ls)
   {
      shmem.s_ntlos1.s_fault_word.u_bit.s_intern_failure = (uint32_t)1;

      shmem.s_ntlos1.s_fault_word.u_bit.s_invalid = (uint32_t)1;

      shmem.s_ntlos2.s_fault_word.u_bit.s_intern_failure = (uint32_t)1;

      shmem.s_ntlos2.s_fault_word.u_bit.s_invalid = (uint32_t)1;

   }

   /************************** NREQ 2 measure inconsistency ********************************/

   if((uint32_t)1 == shmem.s_ntlos1.s_fault_word.u_bit.s_time_out && (((LIB_MATH_FABS((shmem.s_nfreq2_a.s_measure - oss_conf->s_nfreq2_th_frequency)/oss_conf->s_nfreq2_th_frequency)) > (float32_t)10) ||
                                                                     ((LIB_MATH_FABS((shmem.s_nfreq2_b.s_measure - oss_conf->s_nfreq2_th_frequency)/oss_conf->s_nfreq2_th_frequency)) > (float32_t)10)) )
   {
      shmem.s_ntlos1.s_fault_word.u_bit.s_open_circuit = (uint32_t)1;

      shmem.s_ntlos1.s_fault_word.u_bit.s_short_diff = (uint32_t)1;
   }

   if((uint32_t)1 == shmem.s_ntlos2.s_fault_word.u_bit.s_time_out && (((LIB_MATH_FABS((shmem.s_nfreq2_a.s_measure - oss_conf->s_nfreq2_th_frequency)/oss_conf->s_nfreq2_th_frequency)) > (float32_t)10) ||
                                                                     ((LIB_MATH_FABS((shmem.s_nfreq2_b.s_measure - oss_conf->s_nfreq2_th_frequency)/oss_conf->s_nfreq2_th_frequency)) > (float32_t)10)) )
   {
      shmem.s_ntlos2.s_fault_word.u_bit.s_open_circuit = (uint32_t)1;

      shmem.s_ntlos2.s_fault_word.u_bit.s_short_diff = (uint32_t)1;
   }




}
/* ---------- internal operations: ------------------------------------------ */
