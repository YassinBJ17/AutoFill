/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the OVSP Config table check function
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
/* Config_Check_OVSP_Cfg : To check the integrity of an OVSP Config table
 *   Inputs:
 *     - p_OVSP_Cfg_Type: Type of the checked OVSP Config table
 *   Outputs:
 *     - p_pt_Cfg_Integrity: Integrity of the checked OVSP Config table
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Check_OVSP_Cfg (const TE_Config_OVSP_Cfg_Type            p_OVSP_Cfg_Type,
                                  TE_Config_Integrity_Status * const p_pt_Cfg_Integrity)
{
   TU_Config_OVSP_Cfg * pt_Config;

   uint16_t v_Computed_16BitCRC;

   TU_OVSP_SW_Uint16_Uint8 v_Expected_16BitCRC;


   switch (p_OVSP_Cfg_Type)
   {
      case E_Config_OVSP_Cfg_Used:
      case E_Config_OVSP_Cfg_New:
      {
         if (E_Config_OVSP_Cfg_Used == p_OVSP_Cfg_Type)
         {
            /* >RELAX<SYNCHRONe_C_Code_10.7> Waiting for SYNCHONe analyze, it seems to be a false violation. */
            /* The address of a data is set to a pointer on the same type. */
            pt_Config = &V_Config_OVSP_Cfg_Used;
         }
         else
         {
            /* >RELAX<SYNCHRONe_C_Code_10.7> Waiting for SYNCHONe analyze, it seems to be a false violation. */
            /* The address of a data is set to a pointer on the same type. */
            pt_Config = &V_Config_OVSP_Cfg_New;
         }

         Config_Copy_Cfg_With_Swap (pt_Config, &V_Config_OVSP_Cfg_Buffer);

         v_Computed_16BitCRC = OVSP_SW_WORD_MAX;

         /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long data address */
         /* converted to a pointer which is also an 32-bit Unsigned Long. */
         /* >RELAX<SYNCHRONe_C_Code_11.1> The conversion is done to compute the 16-bit CRC byte per byte. */
         /* This is controlled by the provided data size. */
         Config_Compute_16BitCRC ((uint8_t *) &V_Config_OVSP_Cfg_Buffer,
                                  (DRVFTFC_CONFIG_SIZE - OVSP_SW_NB_BYTE_IN_WORD),
                                  &v_Computed_16BitCRC);

         v_Expected_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_0] = (pt_Config->U_Fields).S_16BitCRC_LSB;
         v_Expected_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_1] = (pt_Config->U_Fields).S_16BitCRC_MSB;

         if (v_Computed_16BitCRC == v_Expected_16BitCRC.U_Value_16BitUint)
         {
            *p_pt_Cfg_Integrity = E_Config_Integrity_OK;
         }
         else
         {
            *p_pt_Cfg_Integrity = E_Config_Integrity_KO;
         }

         if (E_Config_OVSP_Cfg_Used == p_OVSP_Cfg_Type)
         {
            V_Last_Computed_16BitCRC.U_Value_16BitUint = v_Computed_16BitCRC;
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }
}
