/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : resolver_periodic function which allows resolver acquisition
 *               and transmission to CSS at each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/resolver/resolver_public.h"
#include "middleware/resolver/resolver_private.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"
#include "memory/shared_memory_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Variables for demodulation result */
float32_t xr_exc;
float32_t xrb_exc;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* Variables for voltages acquisition in V */
static float32_t voltage_xr_dc_raw;
static float32_t voltage_xrb_dc_raw;

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-RESOLVER-xxxx */
void resolver_periodic (const boolean_t channel_is_a)
{
   /* Retrieve configuration data */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;
   ts_xr * shmem_local_ts_xr;

   /* Choose correct shmem variables */
   if(channel_is_a)
   {
      shmem_local_ts_xr = &(shmem.s_xr);
   }
   else
   {
      shmem_local_ts_xr = &(shmem.s_xr_b);
   }

   /* Do we have to compute XR ? */
   if(channel_is_a
      ||
      (
        (FALSE == channel_is_a)
        &&
        (XRB_IS_ENABLED == pt_oss_conf->s_xrb_calres_select))
     )
   {

      /* Compute values */
     if(TRUE == channel_is_a)
     {
      resolver_compute_values(&xr_exc);
     }
     else
     {
      resolver_compute_values(&xrb_exc);
     }

      /* Compute fault word */
     if(TRUE == channel_is_a)
     {
         resolver_compute_fault_word(channel_is_a , &voltage_xr_dc_raw , xr_exc);
         voltage_xrb_dc_raw = 0;
     }
     else
     {
         resolver_compute_fault_word(channel_is_a , &voltage_xrb_dc_raw , xrb_exc);
         voltage_xr_dc_raw = 0;
     }

      /* Update shared mem */
      shmem_local_ts_xr->s_measure           = xr_measure;
      shmem_local_ts_xr->s_vsin_measure      = xr_vsin_measure;
      shmem_local_ts_xr->s_vcos_measure      = xr_vcos_measure;
      shmem_local_ts_xr->s_fault_word        = xr_fault_word;
   }
   else
   {
      /* Update shared mem */
      shmem_local_ts_xr->s_measure           = 0;
      shmem_local_ts_xr->s_vsin_measure      = 0;
      shmem_local_ts_xr->s_vcos_measure      = 0;
      shmem_local_ts_xr->s_fault_word.u_word = (uint32_t) 0;

      /* Set globals to "unset" state */
      voltage_xr_dc_raw                      = 0;
      voltage_xrb_dc_raw                     = 0;
      xr_exc                                 = 0;
      xrb_exc                                = 0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
