/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "middleware/pwm/pwm_private.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void pbit_pld_pwm(void)
{
   /* FPGA registers for PWM */
   ts_pwm     *pwm_fpga;
   pwm_fpga = PWM_FPGA_ADDR;

   if(pwm_fpga->s_period.u_bit.s_pwm_period != PWM_CONVERTED_PERIOD)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }
   if( pwm_fpga->s_command.u_bit.s_pwm_en != PWM_ENABLE_VALUE)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }
   if(pwm_fpga->s_high_time.u_bit.s_pwm_high_time != PWM_CONVERTED_HIGH_TIME_INIT)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }


}

/* ---------- internal operations: ------------------------------------------ */
