/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvLPSPI registers configuration
 *               check function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvLPSPI_Public.h"
#include "DrvLPSPI_Private.h"


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
/* DrvLPSPI_Check_RegConfig : To test the DrvLPSPI registers configuration
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPSPI_Check_RegConfig (uint32_t * const p_pt_Check_Result)
{
   boolean_t v_RegConfig_OK;

   v_RegConfig_OK =
      (DRVLPSPI_IER_CONFIG == C_DrvLPSPI_Registers->S_IER) && (DRVLPSPI_DER_CONFIG == C_DrvLPSPI_Registers->S_DER) &&
      (DRVLPSPI_CFGR0_CONFIG == C_DrvLPSPI_Registers->S_CFGR0) &&
      (DRVLPSPI_CFGR1_CONFIG == C_DrvLPSPI_Registers->S_CFGR1) &&
      (DRVLPSPI_CCR_CONFIG == C_DrvLPSPI_Registers->S_CCR) && (DRVLPSPI_FCR_CONFIG == C_DrvLPSPI_Registers->S_FCR) &&
      (DRVLPSPI_TCR_CONFIG == C_DrvLPSPI_Registers->S_TCR) && (DRVLPSPI_CR_CONFIG == C_DrvLPSPI_Registers->S_CR);

   if (v_RegConfig_OK)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
}
