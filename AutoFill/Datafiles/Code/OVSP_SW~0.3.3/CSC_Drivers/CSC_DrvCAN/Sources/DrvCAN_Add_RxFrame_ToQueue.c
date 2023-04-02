/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function allowing to add a Rx frame
 *               to the queue
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
/* DrvCAN_Add_RxFrame_ToQueue : To add a Rx frame to the queue
 *   Inputs:
 *     - p_pt_RxFrame: The frame to be added
 *     - p_RxQueue_Id: The queue identifier
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvCAN_Add_RxFrame_ToQueue (const TS_DrvCAN_RxFrame * const p_pt_RxFrame, const uint32_t p_RxQueue_Id)
{
   uint32_t v_RxFrame_Index;
   TS_DrvCAN_RxFrame * v_pt_CAN_RxFrame;

   v_RxFrame_Index = V_DrvCAN_RxQueues [p_RxQueue_Id].S_NxtMsg_Idx;

   /* >RELAX<SYNCHRONe_C_Code_10.7> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The address of a data is set to a pointer on the same type. */
   v_pt_CAN_RxFrame = &(V_DrvCAN_RxQueues [p_RxQueue_Id].S_RxMsgQueue [v_RxFrame_Index]);

   v_pt_CAN_RxFrame->S_RxId = p_pt_RxFrame->S_RxId;
   v_pt_CAN_RxFrame->S_RxData [OVSP_SW_LONG_0] = p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0];
   v_pt_CAN_RxFrame->S_RxData [OVSP_SW_LONG_1] = p_pt_RxFrame->S_RxData [OVSP_SW_LONG_1];

   if ((DRVCAN_RXFRAME_MAX_NB - 1UL) <= v_RxFrame_Index)
   {
      V_DrvCAN_RxQueues [p_RxQueue_Id].S_NxtMsg_Idx = 0UL;
   }
   else
   {
      V_DrvCAN_RxQueues [p_RxQueue_Id].S_NxtMsg_Idx++;
   }
}
