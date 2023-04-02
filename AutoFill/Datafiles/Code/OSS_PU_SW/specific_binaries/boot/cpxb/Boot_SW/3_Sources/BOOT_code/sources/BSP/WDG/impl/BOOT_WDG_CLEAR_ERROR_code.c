/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function disables the all Software Watchdog Timers.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_WDG_REG_private.h"
#include "BOOT_WDG_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */
/* ---------- internal types: ----------------------------------------------- */


/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_054 */
void BOOT_WDG_CLEAR_ERROR( void )
{
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from address (uint32_t) to pointer (on volatile struct) */
   SWT_0_IR= SWT_IR_CLEAR_VAL;
   SWT_1_IR= SWT_IR_CLEAR_VAL;
   SWT_2_IR= SWT_IR_CLEAR_VAL;
   SWT_3_IR= SWT_IR_CLEAR_VAL;
   /* }}<SYNCHRONe_C_Code_10.7> */
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
