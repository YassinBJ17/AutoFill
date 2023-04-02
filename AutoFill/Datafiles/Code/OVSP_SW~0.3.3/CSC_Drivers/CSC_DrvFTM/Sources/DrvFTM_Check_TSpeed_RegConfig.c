/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"

#include "Boot_Public.h"
#include "MCP_Types.h"

/* ---------- include provided interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
/* None */

/* ---------- internal types: ----------------------------------------------- */
/* None */

/* ---------- internal operations: ------------------------------------------ */
/* None */

/* ---------- internal constants: ------------------------------------------- */
/* None */

/* ---------- internal data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */

/* DrvFTM_Check_TSpeed_RegConfig : To test the DrvFTM registers configuration
 *                                 for TSpeed acquisition and generation
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Check_TSpeed_RegConfig (uint32_t * const p_pt_Check_Result)
{
   uint8_t v_OVSP_Side_Id;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   if (v_OVSP_Side_Id == BOOT_SIDE_ID_HS)
   {
      DrvFTM_Check_TSpeed_HS_RegConfig(p_pt_Check_Result);
   }
   else
   {
      DrvFTM_Check_TSpeed_LS_RegConfig(p_pt_Check_Result);
   }
}
