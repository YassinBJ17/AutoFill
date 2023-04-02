/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_private.h"
#include "middleware/nfreq/nfreq_set_power_status.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0100 */
void nfreq_set_power_status(const boolean_t        p_channel_is_a,
                            te_nfreq_sensor        p_sensor_id,
                            ts_nfreq_sensor_info * p_sensor_info)
{
   int8_t * pv_gpio_nfreq_x_mon;
   int8_t * pv_gpio_por_opp_n;


   if (e_ngalt == p_sensor_id)
   {
      /* Set circuit fault for NGALT */
      p_sensor_info->s_status_word.u_bit.s_meas_oc_fault   = shmem.s_pw_srce.s_pw_alt_fault.u_bit.s_open_phase;
      p_sensor_info->s_status_word.u_bit.s_meas_short_diff = shmem.s_pw_srce.s_pw_alt_fault.u_bit.s_short_circuit;
   }
   else
   {
      p_sensor_info->s_status_word.u_bit.s_meas_short_diff = (uint32_t)0;

      /* Set circuit fault for NFREQx */
      pv_gpio_nfreq_x_mon = (int8_t *)p_sensor_info->s_gpio_input;   /* NFREQ*_MON GPDI */
      pv_gpio_por_opp_n   = (int8_t *)C_POR_OPP_N;                   /* OC_POWER_STATUS */

      if (e_nfreq_4 == p_sensor_id && TRUE == p_channel_is_a && (int8_t)0 == *pv_gpio_por_opp_n)
      {
         p_sensor_info->s_status_word.u_bit.s_meas_oc_fault  = (uint32_t)0;
         p_sensor_info->s_status_word.u_bit.s_meas_short_gnd = (uint32_t)0;
      }
      else
      {
         if (e_nfreq_2 != p_sensor_id && e_nfreq_4 != p_sensor_id)
            p_sensor_info->s_status_word.u_bit.s_meas_oc_fault = (uint32_t)(*pv_gpio_nfreq_x_mon);
         else
            p_sensor_info->s_status_word.u_bit.s_meas_oc_fault = (uint32_t)0;

         p_sensor_info->s_status_word.u_bit.s_meas_short_gnd = (uint32_t)(*pv_gpio_nfreq_x_mon);
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
