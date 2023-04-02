/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvCAN frame write function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvCAN_Public.h"
#include "DrvCAN_Private.h"


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
/* DrvCAN_Write : To write a CAN frame on FlexCAN
 *   Inputs:
 *     - p_TxMB_Id: The Transmission Message Buffer Identifier
 *     - p_pt_TxFrame: The frame to be written
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvCAN_Write (const uint32_t p_TxMB_Id, const TS_DrvCAN_TxFrame * const p_pt_TxFrame)
{
   uint32_t v_TxMB_Pos;

   v_TxMB_Pos = p_TxMB_Id * DRVCAN_MSG_BUF_SIZE;

   C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_TxMB_Pos + DRVCAN_MB_ID_OFFSET] = p_pt_TxFrame->S_TxId << DRVCAN_ID_SHIFT;

   C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_TxMB_Pos + DRVCAN_MB_DATA1_OFFSET] = p_pt_TxFrame->S_TxData [OVSP_SW_LONG_0];

   C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_TxMB_Pos + DRVCAN_MB_DATA2_OFFSET] = p_pt_TxFrame->S_TxData [OVSP_SW_LONG_1];

   C_DrvCAN_FlexCAN1_Registers->S_RAMn [v_TxMB_Pos] = DRVCAN_TXCMD_VALUE;

   C_DrvCAN_FlexCAN1_Registers->S_IFLAG1 = (DRVCAN_MB_RX_BIT0_MASK << (p_TxMB_Id));
}
