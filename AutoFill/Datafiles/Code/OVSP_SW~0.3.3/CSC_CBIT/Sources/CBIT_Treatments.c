/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CBIT Treatments function
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
/* CBIT_Treatments_RTC : To perform the CBIT Treatments in RTC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
 */
void CBIT_Treatments_RTC (void)
{
   CBIT_Test_OVSP_Side_Id ();

   CBIT_Test_Drivers ();

   CBIT_Test_OVSP_Cfg_Integrity ();

   CBIT_Treatments_Synthesis ();
}


/* CBIT_Treatments_BckGrnd : To perform the CBIT Treatments in Background
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
 */
void CBIT_Treatments_BckGrnd (void)
{
   CBIT_Test_EOC_Integrity ();
}
