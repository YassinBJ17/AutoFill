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
void ovsp_ovs_detect_normal_mode(const boolean_t channel_is_a)
{
   uint32_t * shmem_ch_cmd_on;
   uint32_t * shmem_ch_cmd_off;
   te_ovsp_cam_cmd_t ch_cam_cmd_on;
   te_ovsp_cam_cmd_t ch_cam_cmd_off;


   /* If channel A*/
   if(channel_is_a)
   {
      /* Bind to cmd1 first for channel A*/
      shmem_ch_cmd_on = &shmem.s_ovs.s_ovs_cmd1_on;
      shmem_ch_cmd_off = &shmem.s_ovs.s_ovs_cmd1_off;
      ch_cam_cmd_on = e_ovsp_cam_cmd1_on;
      ch_cam_cmd_off = e_ovsp_cam_cmd1_off;
   }
   else
   {
      /* Bind to cmd2 first for channel B*/
      shmem_ch_cmd_on = &shmem.s_ovs.s_ovs_cmd2_on;
      shmem_ch_cmd_off = &shmem.s_ovs.s_ovs_cmd2_off;
      ch_cam_cmd_on = e_ovsp_cam_cmd2_on;
      ch_cam_cmd_off = e_ovsp_cam_cmd2_off;
   }


   /* If value = init value */
   if(css_ovs_detect_cmd_state == (uint32_t)2)
   {
      /* if cmd_off asked */
      if(*shmem_ch_cmd_off != (uint32_t)0)
      {
         /* Invalid command*/
         shmem.s_ovs.s_ovs_state.u_bit.s_err_css_command = (uint32_t)1;
         /* return in starting state */
         css_ovs_detect_cmd_state = 2;
      }
      /* if cmd_on asked */
      else if(*shmem_ch_cmd_on != (uint32_t)0)
      {
         /* Valid command */
         ovsp_cam_cmd_send(CAN3_REG_ADDR,CAN3_RAM_ADDR,ch_cam_cmd_on);
         ovsp_cam_cmd_send(CAN4_REG_ADDR,CAN4_RAM_ADDR,ch_cam_cmd_on);
         css_ovs_detect_cmd_state = 0;
      }
      /* else no command (can be removed)*/
      else
      {
         css_ovs_detect_cmd_state = 2;
      }
   }
   /* Else last command = cmd_ON*/
   else if(css_ovs_detect_cmd_state == (uint32_t)0)
   {
      /* if cmd_off asked */
      if(*shmem_ch_cmd_off != (uint32_t)0)
      {
         /* Valid command */
         ovsp_cam_cmd_send(CAN3_REG_ADDR,CAN3_RAM_ADDR,ch_cam_cmd_off);
         ovsp_cam_cmd_send(CAN4_REG_ADDR,CAN4_RAM_ADDR,ch_cam_cmd_off);
         /* return in starting state */
         css_ovs_detect_cmd_state = 2;
      }
      /* if cmd_on asked */
      else if(*shmem_ch_cmd_on != (uint32_t)0)
      {
         /* Invalid command */
         shmem.s_ovs.s_ovs_state.u_bit.s_err_css_command = (uint32_t)1;
         css_ovs_detect_cmd_state = 0;
      }
      /* else no command */
      else
      {
         /* return in starting state */
         css_ovs_detect_cmd_state = 2;
      }
   }
}
/* ---------- internal operations: ------------------------------------------ */
