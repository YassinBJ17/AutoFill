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
/* Implements REQ_FADEX_OS_SRD-CANOVS-0030 */
/* OVSP_HS decode get_data response frame thanks to the ID */
void ovsp_get_sw_info_decode(uint32_t const total_nb_frame_received)
{
   /* Index for loop */
   uint32_t i;

   /* Check the received response frame after GET_DATA command */
   for(i=0; i<total_nb_frame_received;i++)
   {
      /* Cast to SW_INFO response frame format */
      if(ovsp_received_frames_tab[i].s_identifier == (uint32_t)0x20)
      {

         /* Fill the s_identifier of the SW_INFO response frame */
         sw_info_response_frame.s_identifier = (uint32_t)ovsp_received_frames_tab[i].s_identifier;

         /* Fill the OVSP_Side byte of the SW_INFO response frame */
         sw_info_response_frame.s_ovsp_side = (uint8_t)ovsp_received_frames_tab[i].s_data[0];

         /* Fill the OVSP_Side byte of the SW_INFO response frame */
         sw_info_response_frame.s_sw_version_major = (uint8_t)ovsp_received_frames_tab[i].s_data[1];

         /* Fill the SW_Version Major byte of the SW_INFO response frame */
         sw_info_response_frame.s_sw_version_minor = (uint8_t)ovsp_received_frames_tab[i].s_data[2];

         /* Fill the SW_Version Minor byte of the SW_INFO response frame */
         sw_info_response_frame.s_sw_version_fix_id = (uint8_t)ovsp_received_frames_tab[i].s_data[3];

         /* Fill the SW_Version Major byte of the SW_INFO response frame */
         sw_info_response_frame.s_ovsp_config_crc = (uint16_t)((ovsp_received_frames_tab[i].s_data[4] <<8) +
                                                               (ovsp_received_frames_tab[i].s_data[5]));

         /* Fill the unused byte of the SW_INFO response frame */
         sw_info_response_frame.s_unused = (uint8_t)ovsp_received_frames_tab[i].s_data[6];

         /* Fill the SW_Version Fix ID byte of the SW_INFO response frame */
         sw_info_response_frame.s_oss_pu_comp_number = (uint8_t)ovsp_received_frames_tab[i].s_data[7];

         /* Fill the SW_Version Fix ID byte of the SW_INFO response frame */
         sw_info_response_frame.s_length = (uint8_t)ovsp_received_frames_tab[i].s_length;


      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
