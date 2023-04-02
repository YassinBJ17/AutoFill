/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvSCG CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvSCG_Public.h"
#include "DrvSCG_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvSCG_Initialize : To initialize the DrvSCG CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvSCG_Initialize (void)
{
   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
   /* converted to pointers which are also an 32-bit Unsigned Long. */
   TS_DrvSCG_Registers * const c_DrvSCG_Registers = (TS_DrvSCG_Registers *) (DRVSCG_SCG_ADDRESS);

   c_DrvSCG_Registers->S_SOSCCSR = DRVADC_SOSCCSR_CONFIG;
   c_DrvSCG_Registers->S_SOSCDIV = DRVADC_SOSCDIV_CONFIG;
   c_DrvSCG_Registers->S_SOSCCFG = DRVADC_SOSCCFG_CONFIG;

   while ((c_DrvSCG_Registers->S_SOSCCSR & DRVSCG_SOSCCSR_LOCK_MASK) == DRVSCG_SOSCCSR_LOCK_MASK)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Wait for SOSCCSR unlocked state */
   }

   c_DrvSCG_Registers->S_SOSCCSR = DRVSCG_SOSCCSR_SOSCLPEN_MASK | DRVSCG_SOSCCSR_SOSCEN_MASK;

   c_DrvSCG_Registers->S_CLKOUTCNFG = DRVADC_CLKOUTCNFG_CONFIG;

   while ((c_DrvSCG_Registers->S_SOSCCSR & DRVSCG_SOSCCSR_SOSCVLD_MASK) != DRVSCG_SOSCCSR_SOSCVLD_MASK)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Wait for OSC enabling and valid output */
   }

   c_DrvSCG_Registers->S_SPLLCSR = DRVADC_SPLLCSR_CONFIG;
   c_DrvSCG_Registers->S_SPLLDIV = DRVADC_SPLLDIV_CONFIG;
   c_DrvSCG_Registers->S_SPLLCFG = DRVADC_SPLLCFG_CONFIG;

   while ((c_DrvSCG_Registers->S_SPLLCSR & DRVSCG_SPLLCSR_LOCK_MASK) == DRVSCG_SPLLCSR_LOCK_MASK)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Wait for SPLLCSR unlocked state */
   }

   c_DrvSCG_Registers->S_SPLLCSR = DRVSCG_SPLLCSR_SPLLEN_MASK;

   while ((c_DrvSCG_Registers->S_SPLLCSR & DRVSCG_SPLLCSR_SPLLVLD_MASK) != DRVSCG_SPLLCSR_SPLLVLD_MASK)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Wait for PLL enabling and valid output */
   }

   c_DrvSCG_Registers->S_RCCR = DRVADC_RCCR_CONFIG;
}
