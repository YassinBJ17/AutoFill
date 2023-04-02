/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to write the used
 *               OVSP Config table in the FlexNVM
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Config_Public.h"
#include "Config_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvFTFC_Public.h"

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
/* Config_Write_In_FlexNVM : To write the used OVSP Config table in the FlexNVM
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Write_In_FlexNVM (void)
{
   uint32_t v_FlexNVM_Erase_Status;
   uint32_t v_FlexNVM_Write_Status;

   C_PtF_DrvFTFC_Erase (DRVFTFC_CONFIG_START_ADDR, &v_FlexNVM_Erase_Status);

   if (OVSP_SW_RESULT_OK == v_FlexNVM_Erase_Status)
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long address */
      /* converted to a pointer which is also an 32-bit Unsigned Long. */
      /* >RELAX<SYNCHRONe_C_Code_11.1> The conversion is done to optimize the memory copy. */
      /* This is controlled by DRVFTFC_CONFIG_SIZE which defines the memory size to copy. */
      C_PtF_DrvFTFC_Write ((uint8_t *) &V_Config_OVSP_Cfg_Used,
                           DRVFTFC_CONFIG_START_ADDR,
                           DRVFTFC_CONFIG_SIZE,
                           &v_FlexNVM_Write_Status);

      if (OVSP_SW_RESULT_OK == v_FlexNVM_Write_Status)
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      else
      {
         V_Config_OVSP_Cfg_Integrity = E_Config_Integrity_KO;
      }
   }
   else
   {
      V_Config_OVSP_Cfg_Integrity = E_Config_Integrity_KO;
   }
}
