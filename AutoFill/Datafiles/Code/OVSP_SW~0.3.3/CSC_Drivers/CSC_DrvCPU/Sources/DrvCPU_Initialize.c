/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : DrvCPU_Initialize : To initialize the Cortex M4f CPU
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
/* None */

/* ---------- include external interface: ----------------------------------- */
/* None */

/* ---------- include required interface: ----------------------------------- */
#include "DrvCPU_Public.h"
#include "DrvCPU_Private.h"

/* ---------- provided define constants: ------------------------------------ */
/* None */

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */
/* DrvCPU_Initialize: To initialize Cortex M4f CPU
 *  Inputs: None
 *  Outputs: None
 *  Function return: None
 *  Pre-condition: None
*/
void DrvCPU_Initialize (void)
{
   /* Initialize SYSTEM CONTROL */
   /* CONTROL = (CONTROL_current & ~CONTROL_mask) | CONTROL_val */
   DrvCPU_Init_CONTROL_Reg ();

   asm("ISB");

   /* Enter Critical Section */
   DrvCPU_Enter_Crit_Sect ();

   /* BASEPRI = (BASEPRI_current & ~BASEPRI_mask) | BASEPRI_val */
   DrvCPU_Init_BASEPRI_Reg ();

   /* APSR = (APSR_current & ~APSR_mask) | APSR_val */
   DrvCPU_Init_APSR_Reg ();

   /* EPSR = (EPSR_current & ~EPSR_mask) | EPSR_val */
   DrvCPU_Init_EPSR_Reg ();

   /* Initialize FPU */
   /* Enable FPU by enabling CP11 and CP10 */
   /* CAPCR = (CAPCR_current & ~CAPCR_mask) | CAPCR_val */
   DrvCPU_Init_CPACR_Reg ();

   asm("DSB");
   asm("ISB");


   /* AHP = 0 ,IEEE half-precision format selected */
   /* DN = 1, Any operation involving one or more NaNs returns the Default NaN */
   /* FZ = 0, Flush-to-zero mode disabled. */
   /* Behavior of the floating-point system is fully compliant with the IEEE 754 standard */
   /* RMode = 0b00, Round to Nearest (RN) mode */
   /* IXC=UFC=OFC=DZC=IOC=1, clear Cumulative exception bits for floating-point exceptions */
   DrvCPU_Init_FPSCR_Reg ();

   /* Enable floating point exception context save on exception */
   DrvCPU_Init_FPCA_Reg ();

   /* ASPEN : Enable Enable CONTROL<2> setting on execution of a floating-point instruction */
   /* LSPEN : Enable automatic lazy state preservation for floating-point context */
   DrvCPU_Init_FPCCR_Reg ();

   /* Disable FPU input denormal interrupt */
   /* Disable FPU inexact interrupt */
   /* Disable FPU underflow interrupt */
   /* Enable FPU overflow interrupt */
   /* Enable FPU divide-by-zero interrupt */
   /* Enable FPU invalid operation interrupt */
   DrvCPU_Init_ISCR_Reg ();

   /* Initialize the GPRs */
   DrvCPU_Init_GPRs ();

   /* Relocate vector table to RAM */
   DrvCPU_Init_VTOR_InSRAM ();

   return;
}
