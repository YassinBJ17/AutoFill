/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the new OVSP Config table management
 *               function for HTR
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Config_Public.h"
#include "Config_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "CAN_Public.h"
#include "Seq_Public.h"

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
/* Config_Manage_NewConfig_HTR : To manage a new OVSP Config table in HTR
 *   Inputs:
 *     - pt_New_Config: New OVSP Config table parameters received by CAN
 *     - p_16BitCRC: 16-bit CRC of the new OVSP Config table
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Manage_NewConfig_HTR (const TU_CAN_SET_PARAM_Frames * const p_pt_New_Config, const uint16_t p_16BitCRC)
{
   uint32_t v_Iter_32BitWord;

   TU_OVSP_SW_Uint16_Uint8 v_16BitCRC;
   TU_OVSP_SW_Uint32_Uint8 v_32Bit_Source;
   TU_OVSP_SW_Uint32_Uint8 v_32Bit_Swapped;

   Config_Reset_OVSP_Cfg (&V_Config_OVSP_Cfg_New);

   for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < CAN_SET_PARAM_FIRST_FLOAT_INDEX ; v_Iter_32BitWord++)
   {
      v_32Bit_Source.U_Value_32BitUint = p_pt_New_Config->U_Array_32BitUint [v_Iter_32BitWord];

      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_0] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_3];
      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_1] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_2];
      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_2] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_1];
      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_3] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_0];

      V_Config_OVSP_Cfg_New.U_Array_32BitUint [v_Iter_32BitWord] = v_32Bit_Swapped.U_Value_32BitUint;
   }

   for (v_Iter_32BitWord = CAN_SET_PARAM_FIRST_FLOAT_INDEX;
        v_Iter_32BitWord < CAN_SET_PARAM_32BIT_NB ;
        v_Iter_32BitWord++)
   {
      V_Config_OVSP_Cfg_New.U_Array_32BitUint [v_Iter_32BitWord] =
         p_pt_New_Config->U_Array_32BitUint [v_Iter_32BitWord];
   }

   v_16BitCRC.U_Value_16BitUint = p_16BitCRC;

   (V_Config_OVSP_Cfg_New.U_Fields).S_16BitCRC_LSB = v_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_0];
   (V_Config_OVSP_Cfg_New.U_Fields).S_16BitCRC_MSB = v_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_1];

   Seq_Set_NewConfig_Status ();
}
