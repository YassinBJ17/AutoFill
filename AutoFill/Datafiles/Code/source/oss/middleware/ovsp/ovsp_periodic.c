/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP periodic function and CBIT
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "conf/oss_conf_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/uod_bypass/uod_bypass_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* OVSP LS get_data response frame format */
ts_ovsp_data_resp_frame1 ls_resp_frame_format_1;   /* Response data frame format 1 */
ts_ovsp_data_resp_frame2 ls_resp_frame_format_2;   /* Response data frame format 2 */
ts_ovsp_data_resp_frame3 ls_resp_frame_format_3;   /* Response data frame format 3 */
ts_ovsp_data_resp_frame4 ls_resp_frame_format_4;   /* Response data frame format 4 */
ts_ovsp_data_resp_frame5 ls_resp_frame_format_5;   /* Response data frame format 5 */
ts_ovsp_data_resp_frame6 ls_resp_frame_format_6;   /* Response data frame format 6 */

/* OVSP HS get_data response frame format */
ts_ovsp_data_resp_frame1 hs_resp_frame_format_1;   /* Response data frame format 1 */
ts_ovsp_data_resp_frame2 hs_resp_frame_format_2;   /* Response data frame format 2 */
ts_ovsp_data_resp_frame3 hs_resp_frame_format_3;   /* Response data frame format 3 */
ts_ovsp_data_resp_frame4 hs_resp_frame_format_4;   /* Response data frame format 4 */
ts_ovsp_data_resp_frame5 hs_resp_frame_format_5;   /* Response data frame format 5 */
ts_ovsp_data_resp_frame6 hs_resp_frame_format_6;   /* Response data frame format 6 */

/* OVSP LS internal fault word */
tu_ovs_hs_ls_intern_fault_word ovsp_ls_fault_word;

/* OVSP HS internal fault word */
tu_ovs_hs_ls_intern_fault_word ovsp_hs_fault_word;



/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* OVSP periodic function and CBIT */
void ovsp_periodic(const boolean_t channel_is_a)
{
   /* OVSP_LS selected (#K_TRUE#) or OVSP_HS selected (#K_FALSE) */
   boolean_t can_is_3;

   /* declaration of the struc to retrieve conf in MRAM */
   ts_oss_conf_table * oss_conf;

   /* retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table *)(OSS_CONF_START_ADDR);
   uod_bypass.uod_can_ovsp_tx_lvl_monitor_ls = (uint32_t)0;
   uod_bypass.uod_can_ovsp_tx_lvl_monitor_hs = (uint32_t)0;

   /*ovsp_reset_rxs_buffer_monitor();*/
   /*ovsp_reset_txs_buffer_monitor();*/

   if (0 == uod_bypass.enable_bypass_can_ovsp)
   {
      if((uint32_t)1 == shmem.s_ovs.s_one_ng_sensor_auth || (uint32_t)1 == shmem.s_ovs.s_one_ntl_sensor_auth)
      {
         ovsp_one_sensor_cmd_send(CAN3_REG_ADDR, CAN3_RAM_ADDR, e_one_ng_sensor_auth);
         ovsp_one_sensor_cmd_send(CAN4_REG_ADDR, CAN4_RAM_ADDR, e_one_ng_sensor_auth);
         /* Acknowledgment for CSS*/
         shmem.s_ovs.s_one_ng_sensor_auth = (uint32_t)0 ;
         /* Acknowledgment for CSS*/
         shmem.s_ovs.s_one_ntl_sensor_auth = (uint32_t)0 ;
      }

      ovsp_get_data_send(CAN3_REG_ADDR, CAN3_RAM_ADDR);
      ovsp_get_data_send(CAN4_REG_ADDR, CAN4_RAM_ADDR);

      if(1 == shmem.s_ovs.s_rearm)
      {
         ovsp_rearm_cmd_send(CAN3_REG_ADDR, CAN3_RAM_ADDR,(boolean_t)1);
         ovsp_rearm_cmd_send(CAN4_REG_ADDR, CAN4_RAM_ADDR,(boolean_t)1);
         /* Acknowledgment for CSS*/
         shmem.s_ovs.s_rearm = (uint32_t)0 ;
      }

      /* Call OVS_detect service (check if as request CAM command sending )*/
      ovsp_ovs_detect(channel_is_a);
   }
   else if (1 == uod_bypass.enable_bypass_can_ovsp)
   {
      ovsp_uod_send(CAN3_REG_ADDR, CAN3_RAM_ADDR);
      ovsp_uod_send(CAN4_REG_ADDR, CAN4_RAM_ADDR);
   }

   /* Reset OVS status word */
   shmem.s_ovs.s_ovs_state.u_word = (uint32_t)0;
   /* Set can_is_3 to #K_TRUE# (OVSP_LS_selected) */
   can_is_3 = (boolean_t)1;
   /* Read 6 Rx get_data response frame from OVSP_LS */
   ovsp_get_data_read(CAN3_REG_ADDR,CAN3_RAM_ADDR,can_is_3);
   /* Update the OVSP_LS internal status */
   ovsp_update_internal_status(can_is_3);

   /* Set can_is_3 to #K_FALSE# (OVSP_HS selected) */
   can_is_3 = (boolean_t)0;
   /* Read 6 Rx get_data response frame from OVSP_HS */
   ovsp_get_data_read(CAN4_REG_ADDR,CAN4_RAM_ADDR,can_is_3);
   /* Update the OVSP_HS internal status */
   ovsp_update_internal_status(can_is_3);

   if (0 == uod_bypass.enable_bypass_can_ovsp)
   {
      if((ls_resp_frame_format_3.s_ntlos1_measure.float32_val < ((0.25 * oss_conf->s_ntl_ovsthresd_threshold * oss_conf->s_ntlos1_100)/100)) && (ls_resp_frame_format_3.s_ntlos2_measure.float32_val < ((0.25 * oss_conf->s_ntl_ovsthresd_threshold * oss_conf->s_ntlos2_100)/100)))
      {
         ovsp_osarm_cmd_send(CAN3_REG_ADDR, CAN3_RAM_ADDR, 1);
      }

      if((hs_resp_frame_format_3.s_ntlos1_measure.float32_val < ((0.25 * oss_conf->s_ntl_ovsthresd_threshold * oss_conf->s_ntlos1_100)/100)) && (hs_resp_frame_format_3.s_ntlos2_measure.float32_val < ((0.25 * oss_conf->s_ntl_ovsthresd_threshold * oss_conf->s_ntlos2_100)/100)))
      {
         ovsp_osarm_cmd_send(CAN4_REG_ADDR, CAN4_RAM_ADDR, 1);
      }
   }


   if(get_data_count_id < 3)
   {
      get_data_count_id++;
   }
   else
   {
      get_data_count_id = (uint32_t)0;
   }

   /* Update the OVSP shared memory data and status */
   ovsp_update_ls_shmem_status();
   ovsp_update_hs_shmem_status();


   /* Make the ngos 1 measure (returned by the OVSP_HS GET_DATA response frame) available to the CSS_PU */
   shmem.s_ngos1.s_measure = hs_resp_frame_format_2.s_ngos1_measure.float32_val;
   /* Make the ngos 2 measure (returned by the OVSP_HS GET_DATA response frame) available to the CSS_PU */
   shmem.s_ngos2.s_measure = hs_resp_frame_format_2.s_ngos2_measure.float32_val;
   /* Make the ntlos 1 measure (returned by the OVSP_HS GET_DATA response frame) available to the CSS_PU */
   shmem.s_ntlos1.s_measure = hs_resp_frame_format_3.s_ntlos1_measure.float32_val;
   /* Make the ntlos 2 measure (returned by the OVSP_HS GET_DATA response frame) available to the CSS_PU */
   shmem.s_ntlos2.s_measure = hs_resp_frame_format_3.s_ntlos2_measure.float32_val;



   ovsp_update_ngosx_status(CAN3_REG_ADDR);

   ovsp_update_ntlosx_status(CAN3_REG_ADDR);

}

/* ---------- internal operations: ------------------------------------------ */
