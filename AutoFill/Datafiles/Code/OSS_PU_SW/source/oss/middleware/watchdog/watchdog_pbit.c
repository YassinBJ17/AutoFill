/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Watchdog PBIT function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/reset/reset_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/watchdog/watchdog_private.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0010 */
/* Perform the PBIT on the watchdog */
void watchdog_pbit(void)
{
   /* Local Variable Declaration */
   ts_watchdog_reg volatile *        pt_WD_reg;
   tu_watchdog_pbit_fail             u_pbit_fail_cr;

   /* Initialization Variable */
   pt_WD_reg                         = (ts_watchdog_reg volatile *)K_WATCHDOG_REG_ADDR;
   u_pbit_fail_cr.u_datafail         = WD_NOFAIL_REPPORT;

   /* Source code start */

   /* 1. Check the register WD_MAX_INIT_TIME_START_REG : expected value 0x0578. */
   if( pt_WD_reg->s_MAX_INIT_TIME_START != WD_MAX_INIT_TIME_START_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_maxinittimestart_fail = WD_FAIL_BIT1;
   }

   /* 2. Check the register WD_MAX_INIT_TIME_OPER_REG : expected value 0x0FA0. */
   if( pt_WD_reg->s_MAX_INIT_TIME_OPER != WD_MAX_INIT_TIME_OPER_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_maxinittimeoper_fail = WD_FAIL_BIT1;
   }

   /* 3. Check the register WD_MAX_FAILURE_START_REG : expected value 0xFF. */
   if( pt_WD_reg->s_MAX_FAILURE_START != WD_MAX_FAILURE_START_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_maxfailurestart_fail = WD_FAIL_BIT1;
   }

   /* 4. Check the register WD_MAX_FAILURE_OPER_REG : expected value 0xFF. */
   if( pt_WD_reg->s_MAX_FAILURE_OPER != WD_MAX_FAILURE_OPER_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_maxfailureoper_fail = WD_FAIL_BIT1;
   }

   /* 5. Check the register WD_MAX_ARM_COUNTER_REG : expected value 0xFF. */
   if( pt_WD_reg->s_MAX_ARM_COUNTER != WD_MAX_ARM_COUNTER_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_maxarmcounter_fail = WD_FAIL_BIT1;
   }

   /* 6. Check the register WD_MIN_WINDOW_TIME_REG : expected value 0x264A. */
   if( pt_WD_reg->s_MIN_WINDOW_TIME != WD_MIN_WINDOW_TIME_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_windowslimitmin_fail = WD_FAIL_BIT1;
   }

   /* 7. Check the register WD_MAX_WINDOW_TIME_REG : expected value 0x27D6. */
   if( pt_WD_reg->s_MAX_WINDOW_TIME != WD_MAX_WINDOW_TIME_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_windowslimitmax_fail = WD_FAIL_BIT1;
   }

   /* 8. Check the register WD_HRESET_DELAY_REG : expected value 0x0000. */
   if( pt_WD_reg->s_RESET_OUT_DELAY != WD_HRESET_DELAY_32VALUE)
   {
      u_pbit_fail_cr.u_bit_pbit_fail.s_hresetdelay_fail = WD_FAIL_BIT1;
   }

   /* If there is a watchdog failure then critical failure: */
   /* - set the bit "watchdog fail" of Platform_PBIT_status to failure */
   /* - log fault */
   /* - command a critical reset  */

   if ( u_pbit_fail_cr.u_datafail != WD_NOFAIL_REPPORT )
   {
      c_watchdog_pbit_report = u_pbit_fail_cr.u_datafail ;

      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      reset_critical();
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
