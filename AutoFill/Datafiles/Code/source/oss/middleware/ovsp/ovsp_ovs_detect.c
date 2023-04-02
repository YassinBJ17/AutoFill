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
void ovsp_ovs_detect(const boolean_t channel_is_a)
{
   /* variable to check */
   uint32_t css_err_cmd ;
   /* init at faulty by default*/
   css_err_cmd = 1;
   /* First check if no erroneous combinaisons */
   ovsp_ovs_detect_check_css_cmd(&css_err_cmd);
   /* if command not erroneous (=0)*/
   if((uint32_t)0 == css_err_cmd)
   {
      /* If opposit channel health ok */
      if(shmem.s_o_health_wd_status_fpga.u_word < (uint32_t)4)
      {
         /* Process ovs_detect command normal mode */
         ovsp_ovs_detect_normal_mode(channel_is_a);
      }
      /* If opposit channel health is nok */
      else if(shmem.s_o_health_wd_status_fpga.u_word >= (uint32_t)4 )
      {
         /* Process ovs_detect command deteriorated mode */
         ovsp_ovs_detect_faulty_mode(channel_is_a);

      }
   }

   shmem.s_ovs.s_ovs_cmd1_on  = 0;
   shmem.s_ovs.s_ovs_cmd1_off = 0;
   shmem.s_ovs.s_ovs_cmd2_on  = 0;
   shmem.s_ovs.s_ovs_cmd2_off = 0;
}

/* ---------- internal operations: ------------------------------------------ */
