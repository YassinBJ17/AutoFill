/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvPCC CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvPCC_Public.h"
#include "DrvPCC_Private.h"


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
/* DrvPCC_Initialize : To initialize the DrvPCC CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvPCC_Initialize (void)
{
   uint32_t v_Iter_PCC;
   uint32_t v_PCC_Index;

   for (v_Iter_PCC = 0UL; v_Iter_PCC < DRVPCC_PCC_USED_NB ; v_Iter_PCC++)
   {
      v_PCC_Index = C_DrvPCC_PCS_Config [v_Iter_PCC].S_Index;

      C_DrvPCC_Registers->S_PCC [v_PCC_Index] &= DRVPCC_CGC_CLEAR_MASK;

      if (DRVPCC_PCS_CLOCK_NONE != C_DrvPCC_PCS_Config [v_Iter_PCC].S_PCS_Value)
      {
         C_DrvPCC_Registers->S_PCC [v_PCC_Index] =
            C_DrvPCC_PCS_Config [v_Iter_PCC].S_PCS_Value | DRVPCC_CGC_ENABLE_MASK;
      }
      else
      {
         C_DrvPCC_Registers->S_PCC [v_PCC_Index] = DRVPCC_CGC_ENABLE_MASK;
      }
   }
}
