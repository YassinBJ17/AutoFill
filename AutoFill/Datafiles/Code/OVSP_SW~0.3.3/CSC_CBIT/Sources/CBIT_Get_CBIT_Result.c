/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CBIT Test Result getting function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CBIT_Public.h"
#include "CBIT_Private.h"


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
/* CBIT_Get_Test_Result : To provide the CBIT Test Result
 *   Inputs: None
 *   Outputs: None
 *   Function return: CBIT Test Result
 *   Pre-condition: None
*/
TE_CBIT_Test_Result CBIT_Get_Test_Result (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CBIT_Test_Result);
}
