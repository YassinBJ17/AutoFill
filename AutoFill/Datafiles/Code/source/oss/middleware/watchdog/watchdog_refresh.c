/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Watchdog refresh function
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
/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0020 */
/* Refresh the watchdog */
void watchdog_refresh(void)
{
   /* Local Variable Declaration        */
   ts_watchdog_reg volatile *           pt_WD_reg;

   /* Initialization Variable           */
   pt_WD_reg                            = (ts_watchdog_reg volatile *)K_WATCHDOG_REG_ADDR;

   /* Source code start */

   pt_WD_reg->s_SW_REFRESH_CMD      = WD_REFRESH_CMD_VALUE;

   V_CBIT_WDG_ActivityValue++;

   return;
}

/* ---------- internal operations: ------------------------------------------ */
