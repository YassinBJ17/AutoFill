/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the GET_SW_INFO Command frame decoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvCAN_Public.h"

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
/* CAN_Decode_GET_SW_INFO_Frame : To decode the GET_SW_INFO Command frame
 *   Inputs:
 *     - p_pt_RxFrame: Buffer of the received frame
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Decode_GET_SW_INFO_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame)
{
   TU_OVSP_SW_Uint32_Uint8 v_OSS_PU_CAN_CompatNb;

   v_OSS_PU_CAN_CompatNb.U_Value_32BitUint = p_pt_RxFrame->S_RxData [OVSP_SW_LONG_1];

   if (C_OVSP_SW_Cartridge.S_SW_CAN_CompatNb == v_OSS_PU_CAN_CompatNb.U_Array_8BitUint [OVSP_SW_BYTE_0])
   {
      V_CAN_Compatibility_Status = TRUE;
   }
   else
   {
      V_CAN_Compatibility_Status = FALSE;
   }
}
