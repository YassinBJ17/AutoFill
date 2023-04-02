/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the SW_INFO Response frame encoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "Config_Public.h"
#include "DrvCAN_Public.h"

#include "OVSP_SW_Public.h"


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
/* CAN_Encode_SW_INFO_Frame : To encode the SW_INFO Response frame
 *   Inputs: None
 *   Outputs:
 *     - p_pt_TxFrame: Buffer of the frame to send
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Encode_SW_INFO_Frame (TS_DrvCAN_TxFrame * const p_pt_TxFrame)
{
   TU_OVSP_SW_Uint32_Uint8 v_Frame_Data0;
   TU_OVSP_SW_Uint32_Uint8 v_Frame_Data1;

   v_Frame_Data0.U_Array_8BitUint [OVSP_SW_BYTE_0] = C_OVSP_SW_Cartridge.S_SW_Version_Z;
   v_Frame_Data0.U_Array_8BitUint [OVSP_SW_BYTE_1] = C_OVSP_SW_Cartridge.S_SW_Version_Y;
   v_Frame_Data0.U_Array_8BitUint [OVSP_SW_BYTE_2] = C_OVSP_SW_Cartridge.S_SW_Version_X;
   v_Frame_Data0.U_Array_8BitUint [OVSP_SW_BYTE_3] = Boot_Get_Side_Id ();

   v_Frame_Data1.U_Array_8BitUint [OVSP_SW_BYTE_0] = C_OVSP_SW_Cartridge.S_SW_CAN_CompatNb;
   v_Frame_Data1.U_Array_8BitUint [OVSP_SW_BYTE_1] = CAN_UNUSED_BYTE_DATA;

   Config_Get_16BitCRC (&(v_Frame_Data1.U_Array_8BitUint [OVSP_SW_BYTE_3]),
                        &(v_Frame_Data1.U_Array_8BitUint [OVSP_SW_BYTE_2]));

   p_pt_TxFrame->S_TxId = CAN_SW_INFO_ID;
   p_pt_TxFrame->S_TxData [OVSP_SW_LONG_0] = v_Frame_Data0.U_Value_32BitUint;

   p_pt_TxFrame->S_TxData [OVSP_SW_LONG_1] = v_Frame_Data1.U_Value_32BitUint;
}
