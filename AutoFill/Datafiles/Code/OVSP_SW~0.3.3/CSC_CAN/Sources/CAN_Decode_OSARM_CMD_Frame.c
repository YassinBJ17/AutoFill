/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the OSARM_CMD Command frame decoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvCAN_Public.h"
#include "Modes_Public.h"
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
/* CAN_Decode_OSARM_CMD_Frame : To decode the OSARM_CMD Command frame
 *   Inputs:
 *     - p_pt_RxFrame: Buffer of the received frame
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Decode_OSARM_CMD_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame)
{
   TE_Modes_SW_Mode       v_SW_Mode;
   TE_OVSP_SW_Speed_Level v_Engine_SpeedLevel;

   v_SW_Mode = Modes_Get_SW_Mode ();
   v_Engine_SpeedLevel = OVSP_Get_Engine_SpeedLevel ();

   if (((E_Modes_Operational == v_SW_Mode) && (E_OVSP_SW_Low_Speed == v_Engine_SpeedLevel)) ||
       (E_Modes_TriggeredTest == v_SW_Mode))
   {
      if (CAN_OSARM_OS_KEY_ON == p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0])
      {
         V_CAN_OSARM_Rqst = E_OVSP_SW_Requested;
      }
      else
      {
         V_CAN_OSARM_Rqst = E_OVSP_SW_NotRequested;
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
