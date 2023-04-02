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

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* OVSP function for OVS_DETECT service */
void ovsp_ovs_detect_check_css_cmd( uint32_t * const css_cmd_erroneous)
{
   /* If cmd1_on check that only cmd2 is on (no off cmd)  */
   if((uint32_t)0 != shmem.s_ovs.s_ovs_cmd1_on && (uint32_t)0 != shmem.s_ovs.s_ovs_cmd2_on && (uint32_t)0 == shmem.s_ovs.s_ovs_cmd1_off && (uint32_t)0 == shmem.s_ovs.s_ovs_cmd2_off)
   {
      /* OK */
      *css_cmd_erroneous = (uint32_t)0;
   }
   else if ((uint32_t)0 != shmem.s_ovs.s_ovs_cmd1_off && (uint32_t)0 != shmem.s_ovs.s_ovs_cmd2_off && (uint32_t)0 == shmem.s_ovs.s_ovs_cmd1_on && (uint32_t)0 == shmem.s_ovs.s_ovs_cmd2_on)
   {
      /* OK */
      *css_cmd_erroneous = (uint32_t)0;
   }
   /* else no command all = 0*/
   else if ((uint32_t)0 == shmem.s_ovs.s_ovs_cmd1_off && (uint32_t)0 == shmem.s_ovs.s_ovs_cmd2_off && (uint32_t)0 == shmem.s_ovs.s_ovs_cmd1_on && (uint32_t)0 == shmem.s_ovs.s_ovs_cmd2_on)
   {
      /* OK */
      *css_cmd_erroneous = (uint32_t)0;
   }
   else
   {
      /* NOK */
      *css_cmd_erroneous = (uint32_t)1;
      shmem.s_ovs.s_ovs_state.u_bit.s_err_css_command = 1;
   }
}

/* ---------- internal operations: ------------------------------------------ */
