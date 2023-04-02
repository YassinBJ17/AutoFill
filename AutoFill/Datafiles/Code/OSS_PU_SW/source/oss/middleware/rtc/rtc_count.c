/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Incrementation of RTC counter
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/rtc/rtc_public.h"
#include "middleware/rtc/rtc_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Elapsed RTC counter */
uint32_t rtc_counter;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0070 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0090 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0100 */
/* Increment the counter of elapsed RTC */
void rtc_count(void)
{
   /* Local Variable Declaration */
   uint32_t            v_cmd_rst;

   /* Initialization Variable */
   v_cmd_rst           = (uint32_t)0;

   /* Source code start */
   /* If overflow */
   /* >RELAX<SYNCHRONe_C_Code_10.7> justification */
   if (RTC_COUNTER_MAX == rtc_counter)
   {
      /* Reset the counter of elapsed RTC */
      rtc_counter = (uint32_t)0;
   }
   /* If no overflow */
   else
   {
      /* Increment the counter of elapsed RTC */
      rtc_counter++;
   }

   /* STEP READ_COUNTER for CSS function */
   rtc_counter_read(&v_cmd_rst);

   /* STEP RESET CMD from CSS function */
   if( v_cmd_rst == K_RESET_UINT_32VALUE)
   {
      rtc_counter_reset();
   }

   /* STEP MRAM SAVE -- RTC counters saved in MRAM */
   /* rtc_counter_write(); */

   return;
}

/* ---------- internal operations: ------------------------------------------ */
