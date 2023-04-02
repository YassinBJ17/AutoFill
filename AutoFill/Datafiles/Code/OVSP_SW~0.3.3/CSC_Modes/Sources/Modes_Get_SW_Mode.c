/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Software mode getting function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Modes_Public.h"
#include "Modes_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


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
/* Modes_Get_SW_Mode : To provide the Software mode
 *   Inputs: None
 *   Outputs: None
 *   Function return: Software mode
 *   Pre-condition: None
*/
TE_Modes_SW_Mode Modes_Get_SW_Mode (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_Modes_SW_Mode);
}
