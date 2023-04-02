/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvLPIT CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvLPIT_Public.h"
#include "DrvLPIT_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "OVSP_SW_Public.h"
#include "OVSP_Public.h"
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
/* DrvLPIT_Check_Init_RegConfig : To test the DrvLPIT registers configuration for
 * Seq RTC generation at initialization
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPIT_Check_Init_RegConfig (uint32_t * p_pt_Check_Result)
{
   uint32_t v_MCR;
   uint32_t v_TVAL2, v_TVAL3;
   uint32_t v_TCTRL0, v_TCTRL1, v_TCTRL2, v_TCTRL3;
   boolean_t v_LPIT_Registers_OK;

   v_MCR = DrvLPIT_LPIT_Registers->S_MCR;
   v_TCTRL0 = DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [DRV_LPIT_CHANNEL_0].S_TCTRL;
   v_TCTRL1 = DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [DRV_LPIT_CHANNEL_1].S_TCTRL;
   v_TCTRL2 = DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [DRV_LPIT_CHANNEL_2].S_TCTRL;
   v_TCTRL3 = DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [DRV_LPIT_CHANNEL_3].S_TCTRL;
   
   v_TVAL2 = DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [DRV_LPIT_CHANNEL_2].S_TVAL;
   v_TVAL3 = DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [DRV_LPIT_CHANNEL_3].S_TVAL;

   v_LPIT_Registers_OK =
      (DRVLPIT_MCR_CONFIG == v_MCR) && (DRVLPIT_TCTRL0_CONFIG == v_TCTRL0) &&
      (DRVLPIT_TCTRL1_CONFIG == v_TCTRL1) && (DRVLPIT_TCTRL2_CONFIG == v_TCTRL2) &&
      (DRVLPIT_TCTRL3_CONFIG == v_TCTRL3) && (DRVLPIT_TVAL2_CONFIG == v_TVAL2) &&
      (DRVLPIT_TVAL3_CONFIG == v_TVAL3);

   if (v_LPIT_Registers_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
}
