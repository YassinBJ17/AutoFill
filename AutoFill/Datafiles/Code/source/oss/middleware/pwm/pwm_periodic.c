/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : pwm_periodic function which allows pwm command at each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pwm/pwm_public.h"
#include "middleware/pwm/pwm_private.h"

/* Access to shared memory */
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Command the PWM according to the CSS_PU request and perform CBIT */
/* Implements REQ_FADEX_OS_SRD-PWM-0020 */
/* Implements REQ_FADEX_OS_SRD-PWM-0030 */
void pwm_periodic(const boolean_t p_channel_is_a)
{
   /* Feedback period and high time temporary stored */
   uint32_t fbk_period;
   uint32_t fbk_high_time;

   /* If the current channel is A */
   if (p_channel_is_a)
   {
      /* If desactivation of PWM is requested (the requested ratio is out of range) */
      if ((PWM_RATIO_MIN > shmem.s_pwm_w.s_pwm_ratio) || (PWM_RATIO_MAX < shmem.s_pwm_w.s_pwm_ratio))
      {
         /* Disable the PWM module */
         *pwm_gpio_enable = PWM_DISABLE_VALUE;
         pwm_fpga->s_command.u_bit.s_pwm_en = PWM_DISABLE_VALUE;

         /* Acknowledge CSS request */
         shmem.s_pwm_w.s_last_commanded_ratio = (uint32_t)0.0f;
      }
      else
      {
         /* When the previous request of the CSS_PU was to disable the PWM */
         if (PWM_DISABLE_VALUE == pwm_fpga->s_command.u_bit.s_pwm_en)
         {
            /* Enable the PWM module */
            *pwm_gpio_enable = PWM_ENABLE_VALUE;
            pwm_fpga->s_command.u_bit.s_pwm_en = PWM_ENABLE_VALUE;
         }

         /* Command the PWM */
         pwm_fpga->s_high_time.u_bit.s_pwm_high_time = (uint32_t)(shmem.s_pwm_w.s_pwm_ratio
                                                                  * ((float32_t)PWM_CONVERTED_PERIOD));

         /* Get feedback period and high time from FPGA */
         fbk_period = pwm_imon_fpga->s_imon_period.u_bit.s_pwm_imon_period;
         fbk_high_time = pwm_imon_fpga->s_imon_high_time.u_bit.s_pwm_imon_high_time;

         /* If feedback period is out of expected range */
         if ((PWM_CONVERTED_FBK_PERIOD_MIN > fbk_period) || (PWM_CONVERTED_FBK_PERIOD_MAX < fbk_period))
         {
            /* Indicate error to the CSS_PU */
            shmem.s_pwm_w.s_pwm_status.u_bit.s_open_circuit = (uint32_t)1;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_hs_short_to_gnd = (uint32_t)1;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_ls_short_to_gnd = (uint32_t)1;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_stuck_high = (uint32_t)1;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_invalid = (uint32_t)1;
         }
         /* If feedback period is in expected range */
         else
         {
            /* Indicate to CSS_PU there is no error */
            shmem.s_pwm_w.s_pwm_status.u_bit.s_open_circuit = (uint32_t)0;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_hs_short_to_gnd = (uint32_t)0;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_ls_short_to_gnd = (uint32_t)0;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_stuck_high = (uint32_t)0;
            shmem.s_pwm_w.s_pwm_status.u_bit.s_invalid = (uint32_t)0;
         }

         /* Indicate the measured PWM feedback high time and period from FPGA to the CSS_PU/MCSS_PU */
         shmem.s_pwm_w.s_pwm_fbk_period = ((float32_t)fbk_period) / PWM_CONVERTER;
         shmem.s_pwm_w.s_pwm_fbk_high_time = ((float32_t)fbk_high_time) / PWM_CONVERTER;

         /* Acknowledge CSS request */
         shmem.s_pwm_w.s_last_commanded_ratio = shmem.s_pwm_w.s_pwm_ratio;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
