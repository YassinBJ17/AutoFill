/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Watchdog PBIT function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/watchdog/watchdog_public.h"
#include "middleware/watchdog/watchdog_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/*-- PBIT global failure --*/
uint32_t   c_watchdog_pbit_report;

/*-- INIT a CBIT global failure --*/
uint32_t   c_watchdog_cbit_error;

/* ---------- internal data: ------------------------------------------------ */
/* Internal Data used to read the incremented Activity value and also for test purpose */
/* On 16 bits to conform to refresh counter register in the FPGA */
uint16_t               V_CBIT_WDG_ActivityValue;
/* Flag used for switch between the 2 values at each check of activity */
te_CMN_FLAG_QUESTION   V_CBIT_WDG_IsValue1ActivityCheck;

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0010 */
/* Initialization of the watchdog */
void watchdog_init(void)
{
   /* Local Variable Declaration */
   ts_watchdog_reg volatile *        pt_WD_reg;

   /* Initialization Variable */
   pt_WD_reg                         = (ts_watchdog_reg volatile *)K_WATCHDOG_REG_ADDR;
   c_watchdog_cbit_error             = WD_INIT_UINT_VALUE32;
   V_CBIT_WDG_ActivityValue          = WD_INIT_UINT_VALUE16;
   V_CBIT_WDG_IsValue1ActivityCheck  = e_CMN_FLAG_NO;

   /* Source code start */

   /* TODO - TBC */
   /* At the start of PBIT Watchdog, activate IRQ watchdog */
   pt_WD_reg->s_IRQ_CONF_CMD         = WD_IRQ_ENABLE_CMD_VALUE;

   /* Perform PBIT for watchdog */
   watchdog_pbit();

   return;
}

/* ---------- internal operations: ------------------------------------------ */
