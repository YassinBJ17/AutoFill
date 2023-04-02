/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTFC registers configuration
 *               check function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
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
/* DrvFTFC_Check_RegConfig : To test the DrvFTFC registers configuration
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTFC_Check_RegConfig (uint32_t * const p_pt_Check_Result)
{
   if (DRVFTFC_FSTAT_NO_ERROR == (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_ERRORS_MASK))
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
}
