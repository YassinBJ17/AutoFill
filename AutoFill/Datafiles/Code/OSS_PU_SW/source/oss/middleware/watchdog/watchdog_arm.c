/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Watchdog arm function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/watchdog/watchdog_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0010 */
/* Arm the watchdog */
void watchdog_arm(void)
{
   /* Local Variable Declaration        */
   ts_watchdog_reg volatile *           pt_WD_reg;

   /* Initialization Variable           */
   pt_WD_reg                            = (ts_watchdog_reg volatile *)K_WATCHDOG_REG_ADDR;

   /* Source code start */

   /* First time cycle life */
   /* Set FPGA mode to operational mode and arm the watchdog for the first step */
   pt_WD_reg->s_INIT_MODE_CMD       = WD_INIT_MODE_CMD_VALUE;

   /* TODO - Waiting time */
   /* LIBT_TIME_Wait(delay); */

   /* State of {init_timer} is set inhibited.*/
   pt_WD_reg->s_INIT_TIMER_INHIBIT_1 = WD_INIT_TIMER_INHIBIT_1_CMD_VALUE;
   pt_WD_reg->s_INIT_TIMER_INHIBIT_2 = WD_INIT_TIMER_INHIBIT_2_CMD_VALUE;

   /* Initialize the  */
   V_CBIT_WDG_ActivityValue         = WD_INIT_UINT_VALUE16;
   /* Begin by the value 1 to check */
   V_CBIT_WDG_IsValue1ActivityCheck = e_CMN_FLAG_YES;

   /* ARM command for the first time */
   pt_WD_reg->s_SW_ARM_CMD          = WD_ARM_CMD_VALUE;

   return;
}

/* ---------- internal operations: ------------------------------------------ */
