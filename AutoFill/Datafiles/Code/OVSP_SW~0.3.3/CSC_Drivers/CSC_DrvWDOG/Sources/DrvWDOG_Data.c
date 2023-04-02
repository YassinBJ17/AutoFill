/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvWDOG CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvWDOG_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* >RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
/* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
/* converted to pointers which are also an 32-bit Unsigned Long. */
TS_DrvWDOG_Registers * const C_DrvWDOG_Registers = (TS_DrvWDOG_Registers *) (DRVWDOG_WDOG_ADDRESS);


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
