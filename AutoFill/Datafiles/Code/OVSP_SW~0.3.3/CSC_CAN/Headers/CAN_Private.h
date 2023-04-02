/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef CAN_PRIVATE_H
#define CAN_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "CAN_Public.h"
#include "DrvCAN_Public.h"

#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define CAN_GET_SW_INFO_ID          0x00000000UL
#define CAN_SW_INFO_ID              0x00000020UL

#define CAN_SET_PARAM_FRAME00_ID    0x00000001UL
#define CAN_SET_PARAM_FRAME01_ID    0x00000021UL
#define CAN_SET_PARAM_FRAME02_ID    0x00000041UL
#define CAN_SET_PARAM_FRAME03_ID    0x00000061UL
#define CAN_SET_PARAM_FRAME04_ID    0x00000081UL
#define CAN_SET_PARAM_FRAME05_ID    0x000000A1UL
#define CAN_SET_PARAM_FRAME06_ID    0x000000C1UL
#define CAN_SET_PARAM_FRAME07_ID    0x000000E1UL
#define CAN_SET_PARAM_FRAME08_ID    0x00000101UL
#define CAN_SET_PARAM_FRAME09_ID    0x00000121UL
#define CAN_SET_PARAM_FRAME10_ID    0x00000141UL
#define CAN_SET_PARAM_FRAME11_ID    0x00000161UL

#define CAN_TRIGGERED_TEST_ID       0x00000002UL
#define CAN_TEST_DISCRETE_ID        0x00000003UL
#define CAN_CAM_CMD_ID              0x00000004UL
#define CAN_OSARM_CMD_ID            0x00000005UL
#define CAN_REARM_CMD_ID            0x00000006UL

#define CAN_GET_DATA_FC0_ID         0x00000007UL
#define CAN_GET_DATA_FC1_ID         0x00000207UL
#define CAN_GET_DATA_FC2_ID         0x00000407UL
#define CAN_GET_DATA_FC3_ID         0x00000607UL

#define CAN_DATA_FRAME01_ID         0x00000027UL
#define CAN_DATA_FRAME02_ID         0x00000047UL
#define CAN_DATA_FRAME03_ID         0x00000067UL
#define CAN_DATA_FRAME04_ID         0x00000087UL
#define CAN_DATA_FRAME05_ID         0x000000A7UL
#define CAN_DATA_FRAME06_ID         0x000000C7UL

#define CAN_GET_DATA_FC_MASK        0x00000600UL

#define CAN_ONE_SENSOR_CMD_ID       0x00000008UL


#define CAN_SET_PARAM_KEY           0xABCDEF01UL

#define CAN_TRIG_TEST_ON            0x12345678UL
#define CAN_TRIG_TEST_OFF           0x87654321UL

#define CAN_DISCRETE_TEST_ON        0xA0A1A2A3UL

#define CAN_CAM_OS_KEY_CMD1_OFF     0x0A0A0A0AUL
#define CAN_CAM_OS_KEY_CMD1_ON      0xA1A1A1A1UL
#define CAN_CAM_OS_KEY_CMD2_OFF     0x0B0B0B0BUL
#define CAN_CAM_OS_KEY_CMD2_ON      0xB1B1B1B1UL
#define CAN_CAM_AS_KEY_CMD1_OFF     0x0C0C0C0CUL
#define CAN_CAM_AS_KEY_CMD1_ON      0xC1C1C1C1UL
#define CAN_CAM_AS_KEY_CMD2_OFF     0x0D0D0D0DUL
#define CAN_CAM_AS_KEY_CMD2_ON      0xD1D1D1D1UL

#define CAN_OSARM_OS_KEY_ON         0xE1E2E3E4UL

#define CAN_REARM_OS_KEY_ON         0xF1F2F3F4UL

#define CAN_NTL_ONE_SENSOR          0xEEEE1111UL
#define CAN_NTL_TWO_SENSOR          0xEEEE2222UL
#define CAN_NG_ONE_SENSOR           0xFFFF1111UL
#define CAN_NG_TWO_SENSOR           0xFFFF2222UL

#define CAN_SET_PARAM_FRAMES_NB     11UL

#define CAN_SET_PARAM_FRAME01_INDEX  0UL
#define CAN_SET_PARAM_FRAME02_INDEX  1UL
#define CAN_SET_PARAM_FRAME03_INDEX  2UL
#define CAN_SET_PARAM_FRAME04_INDEX  3UL
#define CAN_SET_PARAM_FRAME05_INDEX  4UL
#define CAN_SET_PARAM_FRAME06_INDEX  5UL
#define CAN_SET_PARAM_FRAME07_INDEX  6UL
#define CAN_SET_PARAM_FRAME08_INDEX  7UL
#define CAN_SET_PARAM_FRAME09_INDEX  8UL
#define CAN_SET_PARAM_FRAME10_INDEX  9UL
#define CAN_SET_PARAM_FRAME11_INDEX 10UL

#define CAN_DATA_FRAME_NB            6UL

#define CAN_DATA_FRAME01_INDEX       0UL
#define CAN_DATA_FRAME02_INDEX       1UL
#define CAN_DATA_FRAME03_INDEX       2UL
#define CAN_DATA_FRAME04_INDEX       3UL
#define CAN_DATA_FRAME05_INDEX       4UL
#define CAN_DATA_FRAME06_INDEX       5UL

#define CAN_UNUSED_BYTE_DATA        ((uint8_t) 0x00)
#define CAN_UNUSED_LONG_DATA        0x00000000UL

#define CAN_CAM_CMD_TIMEOUT         18UL
#define CAN_REARM_RQST_TIMEOUT      20UL


/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   E_CAN_Frame_Cmd_Idle = 0,
   E_CAN_Frame_Cmd_Start = 1,
   E_CAN_Frame_Cmd_Recv_OK = 2,
   E_CAN_Frame_Cmd_Recv_KO = 3,
   E_CAN_Frame_Cmd_End = 4
} TE_CAN_Frame_Cmd_State;


typedef union
{
   uint8_t U_Value;

   struct
   {
      uint8_t S_OVS_Status_Unused :3;
      uint8_t S_OVSP_Config_Integrity :1;
      uint8_t S_OVSP_Config_Reception :1;
      uint8_t S_Mode :1;
      uint8_t S_CMD2_Status :1;
      uint8_t S_CMD1_Status :1;
   } U_Fields;

} TU_CAN_OVS_Status;


typedef union
{
   uint8_t U_Value;

   struct
   {
      uint8_t S_NG_Status_Unused :2;
      uint8_t S_NGOS2_OutOfRangeHigh :1;
      uint8_t S_NGOS1_OutOfRangeHigh :1;
      uint8_t S_NGOS2_Updated :1;
      uint8_t S_NGOS1_Updated :1;
      uint8_t S_NGOS2_OutOfTime :1;
      uint8_t S_NGOS1_OutOfTime :1;
   } U_Fields;

} TU_CAN_NG_Status;


typedef union
{
   uint8_t U_Value;

   struct
   {
      uint8_t S_NTL_Status_Unused :2;
      uint8_t S_NTLOS2_OutOfRangeHigh :1;
      uint8_t S_NTLOS1_OutOfRangeHigh :1;
      uint8_t S_NTLOS2_Updated :1;
      uint8_t S_NTLOS1_Updated :1;
      uint8_t S_NTLOS2_OutOfTime :1;
      uint8_t S_NTLOS1_OutOfTime :1;
   } U_Fields;

} TU_CAN_NTL_Status;


typedef union
{
   uint8_t U_Value;

   struct
   {
      uint8_t S_DIN_Status_Unused :5;
      uint8_t S_NTLOSTEST :1;
      uint8_t S_OSREARM :1;
      uint8_t S_DININHIB :1;
   } U_Fields;

} TU_CAN_DIN_Status;


typedef union
{
   uint8_t U_Value;

   struct
   {
      uint8_t S_DOUT_Status_Unused :5;
      uint8_t S_OSARM_FB :1;
      uint8_t S_CAMLOW2_FB :1;
      uint8_t S_DOUTINHIB_FB :1;
   } U_Fields;

} TU_CAN_DOUT_Status;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern boolean_t V_CAN_Compatibility_Status;

extern TU_CAN_SET_PARAM_Frames V_CAN_SET_PARAM_Frames;
extern uint16_t V_CAN_OVSP_Config_16BitCRC_Recv;

extern TE_CAN_Frame_Cmd_State V_CAN_SET_PARAM_Frames_States [CAN_SET_PARAM_FRAMES_NB + 1UL];
extern TE_CAN_Frame_Cmd_State V_CAN_OVSP_Config_Recv_Status;

extern TE_CAN_TriggTest_Cmd V_CAN_TriggTest_cmd;
extern TU_OVSP_SW_Uint32_Float32 V_CAN_Test_Speed;

extern TE_OVSP_SW_Cmd V_CAN_TestDiscrete_Cmd;

extern TE_OVSP_SW_Cmd V_CAN_CAM_Cmd_1;
extern TE_OVSP_SW_Cmd V_CAN_CAM_Cmd_2;
extern uint32_t V_CAN_CAM_Timing;

extern TE_OVSP_SW_Request V_CAN_OSARM_Rqst;
extern TE_OVSP_SW_Request V_CAN_REARM_Rqst;
extern uint32_t V_CAN_REARM_Timing;

extern boolean_t V_CAN_GET_DATA_Received;
extern uint32_t V_CAN_GET_DATA_FC;
extern TS_DrvCAN_TxFrame V_CAN_DATA_Frames [CAN_DATA_FRAME_NB];
extern uint32_t V_CAN_DATA_FrameToSend;

extern uint8_t V_CAN_NG_Status;
extern uint8_t V_CAN_NTL_Status;

extern uint8_t V_CAN_NG_Status_Prev;
extern uint8_t V_CAN_NTL_Status_Prev;

extern boolean_t V_CAN_NG_NTL_Statuses_Sent;

extern TE_OVSP_SW_OneSensor_Auth V_CAN_NTL_OneSensor_CSSAuth;
extern TE_OVSP_SW_OneSensor_Auth V_CAN_NG_OneSensor_CSSAuth;


/* ---------- provided operations: ------------------------------------------ */
extern void CAN_Init_SET_PARAM_Data (void);
extern void CAN_Init_SET_PARAM_Frames_States (void);

extern void CAN_Init_DATA_Frames (void);

extern void CAN_Manage_Reception (void);
extern void CAN_Manage_Command_Frames (void);
extern void CAN_Manage_SET_PARAM_Frames (void);

extern void CAN_Decode_GET_SW_INFO_Frame    (const TS_DrvCAN_RxFrame * const p_pt_RxFrame);

extern void CAN_Decode_SET_PARAM_Frame      (const TS_DrvCAN_RxFrame * const p_pt_RxFrame, const uint32_t p_Index);

extern void CAN_Decode_TRIGGERED_TEST_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame);
extern void CAN_Decode_TEST_DISCRETE_Frame  (const TS_DrvCAN_RxFrame * const p_pt_RxFrame);
extern void CAN_Decode_CAM_CMD_Frame        (const TS_DrvCAN_RxFrame * const p_pt_RxFrame);
extern void CAN_Decode_OSARM_CMD_Frame      (const TS_DrvCAN_RxFrame * const p_pt_RxFrame);
extern void CAN_Decode_REARM_CMD_Frame      (const TS_DrvCAN_RxFrame * const p_pt_RxFrame);
extern void CAN_Decode_ONE_SENSOR_CMD_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame);

extern void CAN_Encode_SW_INFO_Frame (TS_DrvCAN_TxFrame * const p_pt_TxFrame);

extern void CAN_Encode_DATA_Frame1 (void);
extern void CAN_Encode_DATA_Frame2 (void);
extern void CAN_Encode_DATA_Frame3 (void);
extern void CAN_Encode_DATA_Frame4 (void);
extern void CAN_Encode_DATA_Frame5 (void);
extern void CAN_Encode_DATA_Frame6 (void);

extern uint8_t CAN_Get_OVS_Status (void);
extern uint8_t CAN_Get_NG_Status (void);
extern uint8_t CAN_Get_NTL_Status (void);
extern uint8_t CAN_Get_DIN_Status (void);
extern uint8_t CAN_Get_DOUT_Status (void);


#endif /* CAN_PRIVATE_H */
