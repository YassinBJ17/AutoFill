/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP function for OVS_DETECT service
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
/* 0 = last command -> cdmOn */
/* 1 = last command -> cdmOff */
/* 2 = last command -> init */


/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* OVSP function for OVS_DETECT service */
void ovsp_ovs_detect_faulty_mode(const boolean_t channel_is_a)
{
   /* binding shmem ptrs for sending right commands on right channel*/
   uint32_t * shmem_ch_cmd_on;
   uint32_t * shmem_ch_cmd_off;
   uint32_t * shmem_opp_ch_cmd_off;
   /* no need for ptr to shmem opp channel because of consistency check of cmd*/

   /* binding enums for sending right commands on right channel*/
   te_ovsp_cam_cmd_t ch_cam_cmd_on;
   te_ovsp_cam_cmd_t ch_cam_cmd_off;
   te_ovsp_cam_cmd_t opp_ch_cam_cmd_on;
   te_ovsp_cam_cmd_t opp_ch_cam_cmd_off;

   /* If channel A*/
   if(channel_is_a)
   {
      /* Bind to cmd2 first for channel A*/
      shmem_ch_cmd_on = &shmem.s_ovs.s_ovs_cmd2_on;
      shmem_ch_cmd_off = &shmem.s_ovs.s_ovs_cmd2_off;
      shmem_opp_ch_cmd_off = &shmem.s_ovs.s_ovs_cmd1_off;

      /* Bind enums to cmd2 first for channel A*/
      ch_cam_cmd_on = e_ovsp_cam_cmd2_on;
      ch_cam_cmd_off = e_ovsp_cam_cmd2_off;
      opp_ch_cam_cmd_on = e_ovsp_cam_cmd1_on;
      opp_ch_cam_cmd_off = e_ovsp_cam_cmd1_off;

   }
   else
   {
      /* Bind to cmd1 first for channel B*/
      shmem_ch_cmd_on = &shmem.s_ovs.s_ovs_cmd1_on;
      shmem_ch_cmd_off = &shmem.s_ovs.s_ovs_cmd1_off;
      shmem_opp_ch_cmd_off = &shmem.s_ovs.s_ovs_cmd2_off;

      /* Bind enums to cmd1 first for channel B*/
      ch_cam_cmd_on = e_ovsp_cam_cmd1_on;
      ch_cam_cmd_off = e_ovsp_cam_cmd1_off;
      opp_ch_cam_cmd_on = e_ovsp_cam_cmd2_on;
      opp_ch_cam_cmd_off = e_ovsp_cam_cmd2_off;
   }


   /* Init value (starting mode) */
   if(css_ovs_detect_cmd_state == (uint32_t)2)
   {
      /* if cmd_off asked */
      if(*shmem_ch_cmd_off != (uint32_t)0)
      {
         /* Invalid command*/
         shmem.s_ovs.s_ovs_state.u_bit.s_err_css_command = (uint32_t)1;
         /* return to starting point */
         css_ovs_detect_cmd_state = 2;
      }
      /* if cmd_on asked */
      else if(*shmem_ch_cmd_on != (uint32_t)0)
      {
         /* Valid command */
         ovsp_cam_cmd_send(CAN3_REG_ADDR,CAN3_RAM_ADDR,ch_cam_cmd_on);
         ovsp_cam_cmd_send(CAN4_REG_ADDR,CAN4_RAM_ADDR,ch_cam_cmd_on);
         css_ovs_detect_cmd_state = 0;
         consec_rtc_cam_cmd_on++;
      }
      /* else no command (can be removed)*/
      else
      {
         css_ovs_detect_cmd_state = 2;
      }
   }
   /* CMD ON last cmd and only 1 cmd_on consecutive */
   else if(css_ovs_detect_cmd_state == (uint32_t)0 && consec_rtc_cam_cmd_on == (uint32_t)1)
   {
      /* if cmd_off asked */
      if(*shmem_ch_cmd_off != (uint32_t)0)
      {
         /* Valid command */
         /* Switching to off last ON command sent */
         ovsp_cam_cmd_send(CAN3_REG_ADDR,CAN3_RAM_ADDR,ch_cam_cmd_off);
         ovsp_cam_cmd_send(CAN4_REG_ADDR,CAN4_RAM_ADDR,ch_cam_cmd_off);
         /* return to starting point */
         css_ovs_detect_cmd_state = 2;
         consec_rtc_cam_cmd_on = 0;
      }
      /* if cmd_on asked */
      else if(*shmem_ch_cmd_on != (uint32_t)0)
      {
         /* Valid command - send cmd_on on other channel */
         ovsp_cam_cmd_send(CAN3_REG_ADDR,CAN3_RAM_ADDR,opp_ch_cam_cmd_on);
         ovsp_cam_cmd_send(CAN4_REG_ADDR,CAN4_RAM_ADDR,opp_ch_cam_cmd_on);
         css_ovs_detect_cmd_state = 0;
         consec_rtc_cam_cmd_on++;
      }
      /* else no command */
      else
      {
         /* Invalid command*/
         shmem.s_ovs.s_ovs_state.u_bit.s_err_css_command = (uint32_t)1;
         /* return to starting point */
         css_ovs_detect_cmd_state = 2;
         /* reset consecutive on counter */
         consec_rtc_cam_cmd_on = 0;
      }
   }
   /* CMD ON last cmd and only 2 or more cmd_on consecutive */
   else if(css_ovs_detect_cmd_state == (uint32_t)0 && consec_rtc_cam_cmd_on >= (uint32_t)2)
   {
      /* if cmd_off asked */
      if(*shmem_ch_cmd_off != (uint32_t)0)
      {
         /* Valid command */
         /* Sending cam_cmd_off */
         ovsp_cam_cmd_send(CAN3_REG_ADDR,CAN3_RAM_ADDR,ch_cam_cmd_off);
         ovsp_cam_cmd_send(CAN4_REG_ADDR,CAN4_RAM_ADDR,ch_cam_cmd_off);
         css_ovs_detect_cmd_state = 1;
         consec_rtc_cam_cmd_on = 0;
         /* Remember AS key for other channel */
         as_key_off_to_send_opp_channel = *shmem_opp_ch_cmd_off;
      }
      /* if cmd_on asked */
      else if(*shmem_ch_cmd_on != (uint32_t)0)
      {
         /* Invalid command*/
         shmem.s_ovs.s_ovs_state.u_bit.s_err_css_command = (uint32_t)1;
         css_ovs_detect_cmd_state = 0;
         /* Increment consecutive on counter */
         consec_rtc_cam_cmd_on++;
      }
      /* else no command */
      else
      {
         /* Valid command*/
         /* return to starting point */
         css_ovs_detect_cmd_state = 2;
         /* reset consecutive on counter */
         consec_rtc_cam_cmd_on = 0;
      }
   }
   /* case the 2nd cam_cmd_off has to be sent */
   else if (css_ovs_detect_cmd_state == (uint32_t)1)
   {
      /* Valid command (no matter the command OS send the 2nd cam_cmd_off) */
      /* Used stored value */
      *shmem_opp_ch_cmd_off = as_key_off_to_send_opp_channel;
      /* Sending cam_cmd_off  */
      ovsp_cam_cmd_send(CAN3_REG_ADDR,CAN3_RAM_ADDR,opp_ch_cam_cmd_off);
      ovsp_cam_cmd_send(CAN4_REG_ADDR,CAN4_RAM_ADDR,opp_ch_cam_cmd_off);
      /* return to starting point */
      css_ovs_detect_cmd_state = 2;
      consec_rtc_cam_cmd_on = 0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
