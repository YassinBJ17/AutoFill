/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :  OVSP_HS decode get_data response frame thanks to the ID
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "middleware/ovsp/ovsp_frame.h"
#include "driver/can/can_critical_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
extern ts_can_frame ovsp_received_frames_tab[OVSP_GET_DATA_MAX_FRAME];

/* ---------- provided operation bodies: ------------------------------------ */
/* OVSP_HS decode get_data response frame thanks to the ID */
void ovsp_get_data_hs_decode(uint32_t const total_nb_frame_received)
{
   /* Index for loop */
   uint32_t i;


   /* Check the received response frame after GET_DATA command */
   for(i=0; i<total_nb_frame_received;i++)
   {
      /* Cast to ts_ovsp_data_resp_frame1 structure (ID.<CMD> = 7 , ID.<Index> = 1) */
      if((ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME1_0) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME1_1) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME1_2) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME1_3) )
      {
         /* Fill the s_identifier of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_identifier = (uint32_t)ovsp_received_frames_tab[i].s_identifier;

         /* Fill the s_ovs_status fields of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_ovs_status.s_cmd1_status           = (uint8_t)((ovsp_received_frames_tab[i].s_data[0] >>7) & 0x1);
         hs_resp_frame_format_1.s_ovs_status.s_cmd2_status           = (uint8_t)((ovsp_received_frames_tab[i].s_data[0] >>6) & 0x1);
         hs_resp_frame_format_1.s_ovs_status.s_mode                  = (uint8_t)((ovsp_received_frames_tab[i].s_data[0] >>5) & 0x1);
         hs_resp_frame_format_1.s_ovs_status.s_ovsp_config_reception = (uint8_t)((ovsp_received_frames_tab[i].s_data[0] >>4) & 0x1);
         hs_resp_frame_format_1.s_ovs_status.s_ovsp_config_integrity = (uint8_t)((ovsp_received_frames_tab[i].s_data[0] >>3) & 0x1);

         /* Fill the s_ng_status of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_ng_status.s_ngos1_out_of_time       = (uint8_t)((ovsp_received_frames_tab[i].s_data[1] >>7) & 0x1);
         hs_resp_frame_format_1.s_ng_status.s_ngos2_out_of_time       = (uint8_t)((ovsp_received_frames_tab[i].s_data[1] >>6) & 0x1);
         hs_resp_frame_format_1.s_ng_status.s_ngos1_updated           = (uint8_t)((ovsp_received_frames_tab[i].s_data[1] >>5) & 0x1);
         hs_resp_frame_format_1.s_ng_status.s_ngos2_updated           = (uint8_t)((ovsp_received_frames_tab[i].s_data[1] >>4) & 0x1);
         hs_resp_frame_format_1.s_ng_status.s_ngos1_out_of_range_high = (uint8_t)((ovsp_received_frames_tab[i].s_data[1] >>3) & 0x1);
         hs_resp_frame_format_1.s_ng_status.s_ngos2_out_of_range_high = (uint8_t)((ovsp_received_frames_tab[i].s_data[1] >>2) & 0x1);

         /* Fill the s_ntl_status of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_time       = (uint8_t)((ovsp_received_frames_tab[i].s_data[2] >>7) & 0x1);
         hs_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_time       = (uint8_t)((ovsp_received_frames_tab[i].s_data[2] >>6) & 0x1);
         hs_resp_frame_format_1.s_ntl_status.s_ntlos1_updated           = (uint8_t)((ovsp_received_frames_tab[i].s_data[2] >>5) & 0x1);
         hs_resp_frame_format_1.s_ntl_status.s_ntlos2_updated           = (uint8_t)((ovsp_received_frames_tab[i].s_data[2] >>4) & 0x1);
         hs_resp_frame_format_1.s_ntl_status.s_ntlos1_out_of_range_high = (uint8_t)((ovsp_received_frames_tab[i].s_data[2] >>3) & 0x1);
         hs_resp_frame_format_1.s_ntl_status.s_ntlos2_out_of_range_high = (uint8_t)((ovsp_received_frames_tab[i].s_data[2] >>2) & 0x1);

         /* Fill the s_discrete_input of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_discrete_input.s_dininhib_val = (uint8_t)((ovsp_received_frames_tab[i].s_data[3] >>7) & 0x1);
         hs_resp_frame_format_1.s_discrete_input.s_osrearm_val  = (uint8_t)((ovsp_received_frames_tab[i].s_data[3] >>6) & 0x1);
         hs_resp_frame_format_1.s_discrete_input.s_ntlostest    = (uint8_t)((ovsp_received_frames_tab[i].s_data[3] >>5) & 0x1);

         /* Fill the s_discrete_output of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_discrete_output.s_doutinhib_fb         = (uint8_t)((ovsp_received_frames_tab[i].s_data[4] >>7) & 0x1);
         hs_resp_frame_format_1.s_discrete_output.s_camlow2_fb_or_unused = (uint8_t)((ovsp_received_frames_tab[i].s_data[4] >>6) & 0x1);
         hs_resp_frame_format_1.s_discrete_output.s_osarm_fb_or_unused   = (uint8_t)((ovsp_received_frames_tab[i].s_data[4] >>5) & 0x1);

         /* Fill the s_ovsp_config_crc of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_ovsp_config_crc = (uint16_t)(((ovsp_received_frames_tab[i].s_data[6] & 0xFF) <<8) +
                                                                (ovsp_received_frames_tab[i].s_data[7] & 0xFF));

         /* Fill the s_lenght of the response data frame format 1 structure */
         hs_resp_frame_format_1.s_length = (uint32_t)ovsp_received_frames_tab[i].s_length;
      }

      /* Cast to ts_ovsp_data_resp_frame2 structure (ID.<CMD> = 7 , ID.<Index> = 2) */
      if((ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME2_0) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME2_1) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME2_2) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME2_3) )
      {
         /* Fill the s_identifier of the response data frame format 2 structure */
         hs_resp_frame_format_2.s_identifier = ovsp_received_frames_tab[i].s_identifier;

         /* Fill the s_ngos1_measure of the response data frame format 2 structure */
         hs_resp_frame_format_2.s_ngos1_measure.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[0] <<24) +
                                                                (ovsp_received_frames_tab[i].s_data[1] <<16) +
                                                                (ovsp_received_frames_tab[i].s_data[2] <<8) +
                                                                ovsp_received_frames_tab[i].s_data[3]);

         /* Fill the s_ngos2_measure of the response data frame format 2 structure */
         hs_resp_frame_format_2.s_ngos2_measure.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[4] <<24) +
                                                            (ovsp_received_frames_tab[i].s_data[5] <<16) +
                                                            (ovsp_received_frames_tab[i].s_data[6] <<8) +
                                                             ovsp_received_frames_tab[i].s_data[7]);

         /* Fill the s_lenght of the response data frame format 2 structure */
         hs_resp_frame_format_2.s_length = (uint32_t)ovsp_received_frames_tab[i].s_length;
      }

      /* Cast to ts_ovsp_data_resp_frame3 structure (ID.<CMD> = 7 , ID.<Index> = 3) */
      if((ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME3_0) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME3_1) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME3_2) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME3_3) )
      {
         /* Fill the s_identifier of the response data frame format 3 structure */
         hs_resp_frame_format_3.s_identifier = ovsp_received_frames_tab[i].s_identifier;

         /* Fill the s_ntlos1_measure of the response data frame format 3 structure */
         hs_resp_frame_format_3.s_ntlos1_measure.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[0] <<24) +
                                                                (ovsp_received_frames_tab[i].s_data[1] <<16) +
                                                                (ovsp_received_frames_tab[i].s_data[2] <<8) +
                                                                ovsp_received_frames_tab[i].s_data[3]);

         /* Fill the s_ntlos2_measure of the response data frame format 3 structure */
         hs_resp_frame_format_3.s_ntlos2_measure.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[4] <<24) +
                                                                     (ovsp_received_frames_tab[i].s_data[5] <<16) +
                                                                     (ovsp_received_frames_tab[i].s_data[6] <<8) +
                                                                     ovsp_received_frames_tab[i].s_data[7]);

         /* Fill the s_lenght of the response data frame format 3 structure */
         hs_resp_frame_format_3.s_length = (uint32_t)ovsp_received_frames_tab[i].s_length;
      }

      /* Cast to ts_ovsp_data_resp_frame4 structure (ID.<CMD> = 7 , ID.<Index> = 4) */
      if((ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME4_0) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME4_1) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME4_2) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME4_3) )
      {
         /* Fill the s_identifier of the response data frame format 4 structure */
         hs_resp_frame_format_4.s_identifier = ovsp_received_frames_tab[i].s_identifier;

         /* Fill the s_ovs_hs_cam_vload of the response data frame format 4 structure */
         hs_resp_frame_format_4.s_ovs_hs_cam_vload.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[0] <<24) +
                                                                (ovsp_received_frames_tab[i].s_data[1] <<16) +
                                                                (ovsp_received_frames_tab[i].s_data[2] <<8) +
                                                                ovsp_received_frames_tab[i].s_data[3]);

         /* Fill the s_ovs_hs_cam_hs_current of the response data frame format 4 structure */
         hs_resp_frame_format_4.s_ovs_hs_cam_hs_current.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[4] <<24) +
                                                                     (ovsp_received_frames_tab[i].s_data[5] <<16) +
                                                                     (ovsp_received_frames_tab[i].s_data[6] <<8) +
                                                                     ovsp_received_frames_tab[i].s_data[7]);

         /* Fill the s_lenght of the response data frame format 4 structure */
         hs_resp_frame_format_4.s_length = (uint32_t)ovsp_received_frames_tab[i].s_length;
      }

      /* Cast to ts_ovsp_data_resp_frame5 structure (ID.<CMD> = 7 , ID.<Index> = 5) */
      if((ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME5_0) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME5_1) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME5_2) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME5_3) )
      {
         /* Fill the s_identifier of the response data frame format 5 structure */
         hs_resp_frame_format_5.s_identifier = ovsp_received_frames_tab[i].s_identifier;

         /* Fill the s_ovs_ls_cam_ls_current of the response data frame format 5 structure */
         hs_resp_frame_format_5.s_ovs_ls_cam_ls_current.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[0] <<24) +
                                                                (ovsp_received_frames_tab[i].s_data[1] <<16) +
                                                                (ovsp_received_frames_tab[i].s_data[2] <<8) +
                                                                ovsp_received_frames_tab[i].s_data[3]);

         /* Fill the s_ovs_temperature of the response data frame format 5 structure */
         hs_resp_frame_format_5.s_ovs_temperature.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[4] <<24) +
                                                                     (ovsp_received_frames_tab[i].s_data[5] <<16) +
                                                                     (ovsp_received_frames_tab[i].s_data[6] <<8) +
                                                                     ovsp_received_frames_tab[i].s_data[7]);

         /* Fill the s_lenght of the response data frame format 5 structure */
         hs_resp_frame_format_5.s_length = (uint32_t)ovsp_received_frames_tab[i].s_length;
      }

      /* Cast to ts_ovsp_data_resp_frame6 structure (ID.<CMD> = 7 , ID.<Index> = 6) */
      if((ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME6_0) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME6_1) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME6_2) ||
         (ovsp_received_frames_tab[i].s_identifier == OVSP_DATA_RESP_ID_FRAME6_3) )
      {
         /* Fill the s_identifier of the response data frame format 6 structure */
         hs_resp_frame_format_6.s_identifier = ovsp_received_frames_tab[i].s_identifier;

         /* Fill the s_test_speed_measure of the response data frame format 6 structure */
         hs_resp_frame_format_6.s_test_speed_measure.int32_val = (uint32_t)((ovsp_received_frames_tab[i].s_data[0] <<24) +
                                                                (ovsp_received_frames_tab[i].s_data[1] <<16) +
                                                                (ovsp_received_frames_tab[i].s_data[2] <<8) +
                                                                ovsp_received_frames_tab[i].s_data[3]);

         /* Fill the s_lenght of the response data frame format 5 structure */
         hs_resp_frame_format_6.s_length = (uint32_t)ovsp_received_frames_tab[i].s_length;
      }



   }
}

/* ---------- internal operations: ------------------------------------------ */
