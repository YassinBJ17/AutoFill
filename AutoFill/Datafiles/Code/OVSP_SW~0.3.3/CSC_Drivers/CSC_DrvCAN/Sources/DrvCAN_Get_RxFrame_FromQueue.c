/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function allowing to get a Rx frame
 *               from the queue
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
/* DrvCAN_Get_RxFrame_FromQueue : To get a Rx frame from the queue
 *   Inputs:
 *     - p_RxQueue_Id: The queue identifier
 *   Outputs:
 *     - p_pt_RxFrame: The got frame
 *   Function return: None
 *   Pre-condition: None
*/
void DrvCAN_Get_RxFrame_FromQueue (TS_DrvCAN_RxFrame * const p_pt_RxFrame, const uint32_t p_RxQueue_Id)
{
   uint32_t v_RxFrame_Index;
   TS_DrvCAN_RxFrame * v_pt_CAN_RxFrame;

   v_RxFrame_Index = V_DrvCAN_RxQueues [p_RxQueue_Id].S_LastMsg_Idx;

   /* >RELAX<SYNCHRONe_C_Code_10.7> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The address of a data is set to a pointer on the same type. */
   v_pt_CAN_RxFrame = &(V_DrvCAN_RxQueues [p_RxQueue_Id].S_RxMsgQueue [v_RxFrame_Index]);

   p_pt_RxFrame->S_RxId = v_pt_CAN_RxFrame->S_RxId;
   p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0] = v_pt_CAN_RxFrame->S_RxData [OVSP_SW_LONG_0];
   p_pt_RxFrame->S_RxData [OVSP_SW_LONG_1] = v_pt_CAN_RxFrame->S_RxData [OVSP_SW_LONG_1];


   if (OVSP_SW_LONG_MAX != p_pt_RxFrame->S_RxId)
   {
      if ((DRVCAN_RXFRAME_MAX_NB - 1UL) <= V_DrvCAN_RxQueues [p_RxQueue_Id].S_LastMsg_Idx)
      {
         V_DrvCAN_RxQueues [p_RxQueue_Id].S_LastMsg_Idx = 0UL;
      }
      else
      {
         V_DrvCAN_RxQueues [p_RxQueue_Id].S_LastMsg_Idx++;
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   v_pt_CAN_RxFrame->S_RxId = OVSP_SW_LONG_MAX;
   v_pt_CAN_RxFrame->S_RxData [OVSP_SW_LONG_0] = OVSP_SW_LONG_MAX;
   v_pt_CAN_RxFrame->S_RxData [OVSP_SW_LONG_1] = OVSP_SW_LONG_MAX;
}
