/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : pwm_init function which allows pwm command initialization.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pwm/pwm_public.h"
#include "middleware/pwm/pwm_private.h"

/* Access to shared memory */
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#define PWM_GPIO_087  ((reg8_t *)0xFFFC1357)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* GPIO manipulation */
reg8_t      *pwm_gpio_enable;

/* FPGA registers for PWM */
ts_pwm      *pwm_fpga;

/* FPGA registers for PWM IMON */
ts_pwm_imon *pwm_imon_fpga;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialize and configure the PWM in FPGA and shared memory */
/* Implements REQ_FADEX_OS_SRD-PWM-0010 */
void pwm_init(const boolean_t p_channel_is_a)
{
   /* Init pointers */
   pwm_gpio_enable = PWM_GPIO_087;
   pwm_fpga = PWM_FPGA_ADDR;
   pwm_imon_fpga = PWM_IMON_FPGA_ADDR;

   /* If the current channel is A */
   if (p_channel_is_a)
   {
      /* Configure the PWM period in the FPGA */
      pwm_fpga->s_period.u_bit.s_pwm_period = PWM_CONVERTED_PERIOD;

      /* Initialize the PWM ratio into shared memory */
      shmem.s_pwm_w.s_pwm_ratio = PWM_RATIO_MIN;

      /* Enable the PWM module */
      *pwm_gpio_enable = PWM_ENABLE_VALUE;
      pwm_fpga->s_command.u_bit.s_pwm_en = PWM_ENABLE_VALUE;

      /* Command the PWM : fpga_pwm_cmd_high_time = K_PWM_PERIOD * K_PWM_MIN_RATIO * K_PWM_CONVERTER */
      pwm_fpga->s_high_time.u_bit.s_pwm_high_time = PWM_CONVERTED_HIGH_TIME_INIT;
   }
}

/* ---------- internal operations: ------------------------------------------ */
