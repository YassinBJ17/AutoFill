/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Perform the periodic functions of SVOI, EMAN and DIN1 at DIN16
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/discrete/discrete_private.h"
#include "middleware/discrete/discrete_public.h"


/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/adc/ADC_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */


/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SVOIEMAN-0010 */
/* Implements REQ_FADEX_OS_SRD-DIN-0010 */
/* Periodic task of SVOI and EMAN discrete */
void discrete_periodic(void)
{
   /* Local Variable Declaration        */
   uint32_t                     v_conf_ind;
   /* COMEMANSVOI_MON voltage of the internal ADC */
   uint16_t                     ac_comemansvoi_mon;
   uint32_t                     v_discrete_data;
   uint32_t                     v_discrete_prevdata;
   uint32_t                     v_discrete_filtred;

   /* Initialization Variable           */
   ac_comemansvoi_mon          = INIT_VALUE_16;
   v_discrete_data             = INIT_VALUE_32;
   v_discrete_prevdata         = INIT_VALUE_32;
   v_discrete_filtred          = INIT_VALUE_32;

   /* Source code start */
   /* Acquire COMEMANSVOI_MON voltage on the line AN[16] of the internal ADC (SARADC_B) */
   ADC_BUFFER_READ (
      (uint32_t)e_CFEX_ADC_INT_AN16,
      &ac_comemansvoi_mon);

   /* Loop on each discrete signal */
   for( v_conf_ind = INIT_VALUE_32 ; v_conf_ind < DISCRETE_DATA_NB ; v_conf_ind++ )
   {
      /* Read discrete value in local parameter */
      /* Set parameters from GPIO to DIN1 to DIN16, SVOI, EMAN and MDIN from FPGA */
      discrete_read(
         /* INPUT */
         v_conf_ind,
         /* OUTPUT */
         &v_discrete_filtred,
         &v_discrete_prevdata,
         &v_discrete_data);

      /* Filter discrete signal with specific parameters from OSS_CONF to generate a stable signal */
      discrete_monitor(
         /* INPUT */
         v_conf_ind,
         &v_discrete_prevdata,
         &v_discrete_data,
         /* INPUT and OUTPUT */
         &v_discrete_filtred);

      /* Write uploaded discrete value */
      discrete_write(
         /* INPUT */
         v_conf_ind,
         &v_discrete_data,
         &v_discrete_filtred);
   }
   /* At the end of the loop, EMAN and SVOI are updated and can be used for compute the fault word */

   /*--- Perform the CBIT function for discrete ---*/
   discrete_cbit(
      &ac_comemansvoi_mon);

   /* Perform enable bypass for UOD with CSS_STUB */
   if(shmem.s_din_uod_bypass_enable > INIT_VALUE_32)
   {
      *GPDO_81_DIN_UOD = DIN_UOD_ENABLE;
   }
   else
   {
      *GPDO_81_DIN_UOD = DIN_UOD_DISABLE;
   }

   /* CDM STATE functionality */
   shmem.s_cdm_state.s_mu_overtemp_status  = (uint32_t)(*GPDI_169_OVERTEMP);
   shmem.s_cdm_state.s_mu_security_alert   = (uint32_t)(*GPDI_167_SECUR_ALERT);
   shmem.s_cdm_state.s_mu_status           = (uint32_t)(*GPDI_170_STATUS);

   /* FLS pending state */
   shmem.s_pending_fls_available           = (uint32_t)(*GPDI_168_SPARE_OUT);

   return ;
}

/* ---------- internal operations: ------------------------------------------ */
