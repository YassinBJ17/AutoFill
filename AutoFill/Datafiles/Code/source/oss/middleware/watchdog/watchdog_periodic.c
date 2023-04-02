/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Watchdog periodic function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/watchdog/watchdog_public.h"
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
/* Perform the periodic on the watchdog */
void watchdog_periodic(void)
{
   /* Local Variable Declaration        */
   ts_watchdog_reg volatile *           pt_WD_reg;
   tu_watchdog_cmd                      u_fpga_cmd;

   /* Initialization Variable           */
   pt_WD_reg                            = (ts_watchdog_reg volatile *)K_WATCHDOG_REG_ADDR;

   /* Source code start */

   /* First starting watchdog trip */
   /* Return Status value */
   u_fpga_cmd.u_register                = (uint32_t)(pt_WD_reg->s_STATUS);

   if( u_fpga_cmd.u_bit_status.s_Init_mode == WD_INIT_UINT_VALUE32 )
   {
      /* Perform ARM function at the first time cycle */
      watchdog_arm();
   }else
   {
      /* Perform a REFRESH command at each RTC */
      watchdog_refresh();
   }

   /* Perform CBIT */
   watchdog_cbit();

   return;
}

/* ---------- internal operations: ------------------------------------------ */
