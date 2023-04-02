/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the OVSP Config table copy function
 *               including a swap of the bytes within the floats
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
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
/* Config_Copy_Cfg_With_Swap : To copy an OVSP Config table with a swap of the bytes within the floats
 *   Inputs:
 *     - p_pt_Config_Src: OVSP Config table to be copied
 *   Outputs:
 *     - p_pt_Config_Dest: OVSP Config table to be set
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Copy_Cfg_With_Swap (const TU_Config_OVSP_Cfg * const p_pt_Config_Src,
                                      TU_Config_OVSP_Cfg * const p_pt_Config_Dest)
{
   uint32_t v_Iter_32BitWord;

   TU_OVSP_SW_Uint32_Uint8 v_32Bit_Source;
   TU_OVSP_SW_Uint32_Uint8 v_32Bit_Swapped;

   for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < CONFIG_FIRST_FLOAT_INDEX ; v_Iter_32BitWord++)
   {
      p_pt_Config_Dest->U_Array_32BitUint [v_Iter_32BitWord] = p_pt_Config_Src->U_Array_32BitUint [v_Iter_32BitWord];
   }

   for (v_Iter_32BitWord = CONFIG_FIRST_FLOAT_INDEX;
        v_Iter_32BitWord < CONFIG_FIRST_RESERVED_INDEX ;
        v_Iter_32BitWord++)
   {
      v_32Bit_Source.U_Value_32BitUint = p_pt_Config_Src->U_Array_32BitUint [v_Iter_32BitWord];

      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_0] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_3];
      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_1] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_2];
      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_2] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_1];
      v_32Bit_Swapped.U_Array_8BitUint [OVSP_SW_BYTE_3] = v_32Bit_Source.U_Array_8BitUint [OVSP_SW_BYTE_0];

      p_pt_Config_Dest->U_Array_32BitUint [v_Iter_32BitWord] = v_32Bit_Swapped.U_Value_32BitUint;
   }

   for (v_Iter_32BitWord = CONFIG_FIRST_RESERVED_INDEX; v_Iter_32BitWord < DRVFTFC_CONFIG_32BIT_NB ; v_Iter_32BitWord++)
   {
      p_pt_Config_Dest->U_Array_32BitUint [v_Iter_32BitWord] = p_pt_Config_Src->U_Array_32BitUint [v_Iter_32BitWord];
   }
}
