/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvCAN registers configuration
 *               check function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvCAN_Public.h"
#include "DrvCAN_Private.h"


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
/* DrvCAN_Check_RegConfig : To test the DrvCAN registers configuration
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvCAN_Check_RegConfig (uint32_t * const p_pt_Check_Result)
{
   if ((DRVCAN_MCR_CONFIG != C_DrvCAN_FlexCAN1_Registers->S_MCR) ||
       (DRVCAN_CTRL1_1MBPS_CONFIG != C_DrvCAN_FlexCAN1_Registers->S_CTRL1) ||
       (DRVCAN_IMASK1_CONFIG != C_DrvCAN_FlexCAN1_Registers->S_IMASK1))
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
}
