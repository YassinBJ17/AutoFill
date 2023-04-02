/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DATA frames encoding functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Config_Public.h"
#include "DrvCAN_Public.h"
#include "IO_Public.h"
#include "OVSP_Public.h"

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
/* CAN_Encode_DATA_Frame1 : To build the DATA frame index 1
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Encode_DATA_Frame1 (void)
{
   TU_OVSP_SW_Uint32_Uint8 v_Frame_Data_0;
   TU_OVSP_SW_Uint32_Uint8 v_Frame_Data_1;

   v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_0] = CAN_Get_DIN_Status ();
   v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_1] = V_CAN_NTL_Status;
   v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_2] = V_CAN_NG_Status;
   v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_3] = CAN_Get_OVS_Status ();

   Config_Get_LastComputed16BitCRC (&(v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_0]),
                                    &(v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_1]));

   v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_2] = CAN_UNUSED_BYTE_DATA;
   v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_3] = CAN_Get_DOUT_Status ();

   V_CAN_DATA_Frames [CAN_DATA_FRAME01_INDEX].S_TxId = CAN_DATA_FRAME01_ID | V_CAN_GET_DATA_FC;
   V_CAN_DATA_Frames [CAN_DATA_FRAME01_INDEX].S_TxData [OVSP_SW_LONG_0] = v_Frame_Data_0.U_Value_32BitUint;
   V_CAN_DATA_Frames [CAN_DATA_FRAME01_INDEX].S_TxData [OVSP_SW_LONG_1] = v_Frame_Data_1.U_Value_32BitUint;
}


/* CAN_Encode_DATA_Frame2 : To build the DATA frame index 2
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Encode_DATA_Frame2 (void)
{
   TU_OVSP_SW_Uint32_Float32 v_NGOS1_Measure;
   TU_OVSP_SW_Uint32_Float32 v_NGOS2_Measure;

   v_NGOS1_Measure.U_Value_32BitFloat = OVSP_Get_NGOS1_Measure ();
   v_NGOS2_Measure.U_Value_32BitFloat = OVSP_Get_NGOS2_Measure ();

   V_CAN_DATA_Frames [CAN_DATA_FRAME02_INDEX].S_TxId = CAN_DATA_FRAME02_ID | V_CAN_GET_DATA_FC;
   V_CAN_DATA_Frames [CAN_DATA_FRAME02_INDEX].S_TxData [OVSP_SW_LONG_0] = v_NGOS1_Measure.U_Value_32BitUint;
   V_CAN_DATA_Frames [CAN_DATA_FRAME02_INDEX].S_TxData [OVSP_SW_LONG_1] = v_NGOS2_Measure.U_Value_32BitUint;
}


/* CAN_Encode_DATA_Frame3 : To build the DATA frame index 3
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Encode_DATA_Frame3 (void)
{
   TU_OVSP_SW_Uint32_Float32 v_NTLOS1_Measure;
   TU_OVSP_SW_Uint32_Float32 v_NTLOS2_Measure;

   v_NTLOS1_Measure.U_Value_32BitFloat = OVSP_Get_NTLOS1_Measure ();
   v_NTLOS2_Measure.U_Value_32BitFloat = OVSP_Get_NTLOS2_Measure ();

   V_CAN_DATA_Frames [CAN_DATA_FRAME03_INDEX].S_TxId = CAN_DATA_FRAME03_ID | V_CAN_GET_DATA_FC;
   V_CAN_DATA_Frames [CAN_DATA_FRAME03_INDEX].S_TxData [OVSP_SW_LONG_0] = v_NTLOS1_Measure.U_Value_32BitUint;
   V_CAN_DATA_Frames [CAN_DATA_FRAME03_INDEX].S_TxData [OVSP_SW_LONG_1] = v_NTLOS2_Measure.U_Value_32BitUint;
}


/* CAN_Encode_DATA_Frame4 : To build the DATA frame index 4
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Encode_DATA_Frame4 (void)
{
   TU_OVSP_SW_Uint32_Float32 v_CAM_VLoad;
   TU_OVSP_SW_Uint32_Float32 v_CAM_HS_Current;

   v_CAM_VLoad.U_Value_32BitFloat = IO_Get_CAM_Vload ();

   v_CAM_HS_Current.U_Value_32BitFloat = IO_Get_CAM_HS_Current ();

   V_CAN_DATA_Frames [CAN_DATA_FRAME04_INDEX].S_TxId = CAN_DATA_FRAME04_ID | V_CAN_GET_DATA_FC;
   V_CAN_DATA_Frames [CAN_DATA_FRAME04_INDEX].S_TxData [OVSP_SW_LONG_0] = v_CAM_VLoad.U_Value_32BitUint;
   V_CAN_DATA_Frames [CAN_DATA_FRAME04_INDEX].S_TxData [OVSP_SW_LONG_1] = v_CAM_HS_Current.U_Value_32BitUint;
}


/* CAN_Encode_DATA_Frame5 : To build the DATA frame index 5
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Encode_DATA_Frame5 (void)
{
   TU_OVSP_SW_Uint32_Float32 v_CAM_LS_Current;
   TU_OVSP_SW_Uint32_Float32 v_Temperature;

   v_CAM_LS_Current.U_Value_32BitFloat = IO_Get_CAM_LS_Current ();

   v_Temperature.U_Value_32BitFloat = IO_Get_Temperature ();

   V_CAN_DATA_Frames [CAN_DATA_FRAME05_INDEX].S_TxId = CAN_DATA_FRAME05_ID | V_CAN_GET_DATA_FC;
   V_CAN_DATA_Frames [CAN_DATA_FRAME05_INDEX].S_TxData [OVSP_SW_LONG_0] = v_CAM_LS_Current.U_Value_32BitUint;
   V_CAN_DATA_Frames [CAN_DATA_FRAME05_INDEX].S_TxData [OVSP_SW_LONG_1] = v_Temperature.U_Value_32BitUint;
}


/* CAN_Encode_DATA_Frame6 : To build the DATA frame index 6
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Encode_DATA_Frame6 (void)
{
   TU_OVSP_SW_Uint32_Float32 v_Test_Speed_Measure;

   v_Test_Speed_Measure.U_Value_32BitFloat = OVSP_Get_Test_Speed_Measure ();

   V_CAN_DATA_Frames [CAN_DATA_FRAME06_INDEX].S_TxId = CAN_DATA_FRAME06_ID | V_CAN_GET_DATA_FC;
   V_CAN_DATA_Frames [CAN_DATA_FRAME06_INDEX].S_TxData [OVSP_SW_LONG_0] = v_Test_Speed_Measure.U_Value_32BitUint;
   V_CAN_DATA_Frames [CAN_DATA_FRAME06_INDEX].S_TxData [OVSP_SW_LONG_1] = CAN_UNUSED_LONG_DATA;
}
