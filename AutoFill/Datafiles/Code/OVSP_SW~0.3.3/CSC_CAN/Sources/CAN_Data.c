/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CAN CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


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
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
boolean_t V_CAN_Compatibility_Status;

TU_CAN_SET_PARAM_Frames V_CAN_SET_PARAM_Frames;
uint16_t V_CAN_OVSP_Config_16BitCRC_Recv;

TE_CAN_Frame_Cmd_State V_CAN_SET_PARAM_Frames_States [CAN_SET_PARAM_FRAMES_NB + 1UL];
TE_CAN_Frame_Cmd_State V_CAN_OVSP_Config_Recv_Status;

TE_CAN_TriggTest_Cmd V_CAN_TriggTest_cmd;
TU_OVSP_SW_Uint32_Float32 V_CAN_Test_Speed;

TE_OVSP_SW_Cmd V_CAN_TestDiscrete_Cmd;

TE_OVSP_SW_Cmd V_CAN_CAM_Cmd_1;
TE_OVSP_SW_Cmd V_CAN_CAM_Cmd_2;
uint32_t V_CAN_CAM_Timing;

TE_OVSP_SW_Request V_CAN_OSARM_Rqst;
TE_OVSP_SW_Request V_CAN_REARM_Rqst;
uint32_t V_CAN_REARM_Timing;

boolean_t V_CAN_GET_DATA_Received;
uint32_t V_CAN_GET_DATA_FC;
TS_DrvCAN_TxFrame V_CAN_DATA_Frames [CAN_DATA_FRAME_NB];
uint32_t V_CAN_DATA_FrameToSend;

uint8_t V_CAN_NG_Status;
uint8_t V_CAN_NTL_Status;

uint8_t V_CAN_NG_Status_Prev;
uint8_t V_CAN_NTL_Status_Prev;

boolean_t V_CAN_NG_NTL_Statuses_Sent;

TE_OVSP_SW_OneSensor_Auth V_CAN_NTL_OneSensor_CSSAuth;
TE_OVSP_SW_OneSensor_Auth V_CAN_NG_OneSensor_CSSAuth;
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
