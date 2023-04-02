/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the EOC 32-bit CRC check function
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
/* DrvFTFC_Check_EOC_32Bit_CRC : To test the EOC 32-bit CRC
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTFC_Check_EOC_32Bit_CRC (uint32_t * const p_pt_Check_Result)
{
   uint32_t v_Computed_32Bit_CRC;
   uint32_t v_EOC_Size;

   v_Computed_32Bit_CRC = DRVFTFC_32BIT_CRC_INIT_VALUE;

   /* >RELAX<SYNCHRONe_C_Code_11.1> The conversion is mandatory to get the value of the address */
   v_EOC_Size = (uint32_t) &__Linker_Code_End + ((uint32_t) &__Linker_Data_End - (uint32_t) &__Linker_Data_Start);

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long data address */
   /* converted to a pointer which is also an 32-bit Unsigned Long. */
   DrvFTFC_Compute_32Bit_CRC ((uint8_t*) DRVFTFC_PFLASH_START_ADDR,
                              DRVFTFC_FIELD_KEY_START_ADDR,
                              &v_Computed_32Bit_CRC);

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long data address */
   /* converted to a pointer which is also an 32-bit Unsigned Long. */
   DrvFTFC_Compute_32Bit_CRC ((uint8_t*) DRVFTFC_CARTRIDGE_START_ADDR,
                              (v_EOC_Size - DRVFTFC_CARTRIDGE_START_ADDR),
                              &v_Computed_32Bit_CRC);

   v_Computed_32Bit_CRC ^= OVSP_SW_LONG_MAX;

   if (C_DrvFTFC_EOC_32Bit_CRC == v_Computed_32Bit_CRC)
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
}
