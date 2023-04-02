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
#define SWT_CR_INIT_VALUE (0xFF000102)
#define SWT_CR_MASK (0x00FFF800)
/* ---------- internal types: ----------------------------------------------- */


/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_054 */
void BOOT_WDG_INIT( void )
{

   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from address (uint32_t) to pointer (on volatile struct) */
   /* {{RELAX<SYNCHRONe_C_Code_7.2> Write keys to clear soft lock bit and Clear watchdog enable (s_WEN) */
   /* {{RELAX<SYNCHRONe_C_Code_10.2> SWT_0_SR is reg32_t type */
   SWT_0_SR = SWT_KEYS_1;               /* Write keys to clear soft lock bit */
   SWT_0_SR = SWT_KEYS_2;
   SWT_0_CR = (SWT_0_CR & SWT_CR_MASK) | SWT_CR_INIT_VALUE;               /* Clear watchdog enable (s_WEN) */
   SWT_1_SR = SWT_KEYS_1;               /* Write keys to clear soft lock bit */
   SWT_1_SR = SWT_KEYS_2;
   SWT_1_CR = (SWT_1_CR & SWT_CR_MASK) | SWT_CR_INIT_VALUE;               /* Clear watchdog enable (s_WEN) */
   SWT_2_SR = SWT_KEYS_1;               /* Write keys to clear soft lock bit */
   SWT_2_SR = SWT_KEYS_2;
   SWT_2_CR = (SWT_2_CR & SWT_CR_MASK) | SWT_CR_INIT_VALUE;               /* Clear watchdog enable (s_WEN) */
   SWT_3_SR = SWT_KEYS_1;               /* Write keys to clear soft lock bit */
   SWT_3_SR = SWT_KEYS_2;
   SWT_3_CR = (SWT_3_CR & SWT_CR_MASK) | SWT_CR_INIT_VALUE;               /* Clear watchdog enable (s_WEN) */
   /* }}<SYNCHRONe_C_Code_10.7> */
   /* }}<SYNCHRONe_C_Code_7.2> */
   /* }}<SYNCHRONe_C_Code_10.2> */

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
