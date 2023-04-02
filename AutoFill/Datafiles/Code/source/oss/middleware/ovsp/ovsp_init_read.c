/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP initialization read frame function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "driver/can/can_private.h"
#include "driver/can/can_critical_private.h"
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "conf/oss_conf_public.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "memory/memory_address_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
#define OVSP_LS_ID (uint8_t)0x5A

#define OVSP_HS_ID (uint8_t)0xA5

/* ---------- provided data: ------------------------------------------------ */
/* SW_INFO response frame */
ts_ovsp_sw_info_response_frame sw_info_response_frame;


/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-CANOVS-0030 */
/* OVSP initialization read frame function  */
void ovsp_init_read(void)
{

   /* declaration of the struc to retrieve conf in MRAM */
   ts_oss_conf_table * oss_conf;

   /* CAN 3 (OVSP_LS) or CAN 4 (OVSP_HS) */
   boolean_t can_is_3;

   /* retrieve conf in MRAM */
   oss_conf = (ts_oss_conf_table *)(OSS_CONF_START_ADDR);


   /****************************************** OVSP_LS *****************************************/

   /* Read the GET_SW_INFO response frame sent by the OVSP_LS */
   ovsp_get_sw_info_read(CAN3_REG_ADDR, CAN3_RAM_ADDR);

   /* If the compatibilty number is different between the GET_SW_INFO command frame and the SW_INFO response frame on OVSP_LS */
   if(get_sw_info_frame.s_oss_pu_comp_number != sw_info_response_frame.s_oss_pu_comp_number)
   {
      /* Set the communication error fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_com_error = (uint32_t)1;
      /* Set the fault detection on LS fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_ls = (uint32_t)1;
      /* Set the invalid fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the compatibilty number is different between the GET_SW_INFO command frame and the SW_INFO response frame on OVSP_LS */
   if(sw_info_response_frame.s_ovsp_side != (uint8_t)OVSP_LS_ID)
   {
      /* Set the fault detection on LS fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_ls = (uint32_t)1;
      /* Set the invalid fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the OVSP_LS 16bit CRC configuration is different from the 16bit CRC configuration on the OSS_CONF  */
   if(oss_conf->s_ovsp_config_16bitcrc != sw_info_response_frame.s_ovsp_config_crc)
   {
      /* Set the fault detection on LS fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_ls = (uint32_t)1;

      /* Set the fault detection on OVSP CRC configuration integrity in the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_ovsp_config_integ = (uint32_t)1;
   }

   /* If the OVSP 16bit CRC configuration is erroned on the OVSP_LS */
   if((uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_ovsp_config_integ && (uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_ls)
   {
      /* Set the OSS_CONF parameter on the OVSP_LS */
      ovsp_set_param_send(CAN3_REG_ADDR, CAN3_RAM_ADDR);

      /* Wait TBD ms */

      /* Send a GET_DATA command frame to the OVSP_LS */
      ovsp_get_data_send(CAN3_REG_ADDR, CAN3_RAM_ADDR);

      /* Set can_is_3 to #K_TRUE# (OVSP_LS_selected) */
      can_is_3 = (boolean_t)1;
      /* Read a GET_DATA response frame of the OVSP_HS */
      ovsp_get_data_read(CAN3_REG_ADDR, CAN3_RAM_ADDR, can_is_3);

      /* If the GET_DATA response frame returns an OVSP_LS 16bit CRC configuration different from the OSS_CONF 16bit CRC conf */
      if((uint32_t)1 == ls_resp_frame_format_1.s_ovs_status.s_ovsp_config_integrity || oss_conf->s_ovsp_config_16bitcrc != ls_resp_frame_format_1.s_ovsp_config_crc)
      {
         /* Set the invalid fault bit on the OVSP status */
         shmem.s_ovs.s_ovs_state.u_bit.s_invalid = (uint32_t)1;
      }
   }



   /****************************************** OVSP_HS *****************************************/

   /* Read the GET_SW_INFO response frame sent by the OVSP_HS */
   ovsp_get_sw_info_read(CAN4_REG_ADDR, CAN4_RAM_ADDR);

   /* If the compatibilty number is different between the GET_SW_INFO command frame and the SW_INFO response frame on OVSP_LS */
   if(sw_info_response_frame.s_ovsp_side != (uint8_t)OVSP_HS_ID)
   {
      /* Set the fault detection on LS fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_hs = (uint32_t)1;
      /* Set the invalid fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the compatibilty number is different between the GET_SW_INFO command frame and the SW_INFO response frame on OVSP_HS */
   if(get_sw_info_frame.s_oss_pu_comp_number != sw_info_response_frame.s_oss_pu_comp_number)
   {
      /* Set the communication error fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_com_error = (uint32_t)1;
      /* Set the fault detection on HS fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_hs = (uint32_t)1;
      /* Set the invalid fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the OVSP_HS 16bit CRC configuration is different from the 16bit CRC configuration on the OSS_CONF  */
   if(oss_conf->s_ovsp_config_16bitcrc != sw_info_response_frame.s_ovsp_config_crc)
   {
      /* Set the fault detection on HS fault bit on the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_hs = (uint32_t)1;
      /* Set the fault detection on OVSP CRC configuration integrity in the OVSP status */
      shmem.s_ovs.s_ovs_state.u_bit.s_ovsp_config_integ = (uint32_t)1;
   }

   /* If the OVSP 16bit CRC configuration is erroned on the OVSP_HS */
   if((uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_ovsp_config_integ && (uint32_t)1 == shmem.s_ovs.s_ovs_state.u_bit.s_fault_detected_hs)
   {
      /* Set the OSS_CONF parameter on the OVSP_HS */
      ovsp_set_param_send(CAN4_REG_ADDR, CAN4_RAM_ADDR);

      /* Wait TBD ms */

      /* Send a GET_DATA command frame to the OVSP_HS */
      ovsp_get_data_send(CAN4_REG_ADDR, CAN4_RAM_ADDR);

      /* Set can_is_3 to #K_FALSE# (OVSP_HS_selected) */
      can_is_3 = (boolean_t)0;
      /* Read a GET_DATA response frame of the OVSP_HS */
      ovsp_get_data_read(CAN4_REG_ADDR, CAN4_RAM_ADDR, can_is_3);

      /* If the GET_DATA response frame returns an OVSP_HS 16bit CRC configuration different from the OSS_CONF 16bit CRC conf */
      if((uint32_t)1 == hs_resp_frame_format_1.s_ovs_status.s_ovsp_config_integrity || oss_conf->s_ovsp_config_16bitcrc != hs_resp_frame_format_1.s_ovsp_config_crc)
      {
         /* Set the invalid fault bit on the OVSP status */
         shmem.s_ovs.s_ovs_state.u_bit.s_invalid = (uint32_t)1;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
