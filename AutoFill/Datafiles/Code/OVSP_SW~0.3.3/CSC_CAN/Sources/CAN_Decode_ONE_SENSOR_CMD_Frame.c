/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the ONE_SENSOR_CMD Command frame decoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
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
/* CAN_Decode_ONE_SENSOR_CMD_Frame : To decode the ONE_SENSOR_CMD Command frame
 *   Inputs:
 *     - p_pt_RxFrame: Buffer of the received frame
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Decode_ONE_SENSOR_CMD_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame)
{
   switch (p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0])
   {
      case CAN_NTL_ONE_SENSOR:
      {
         V_CAN_NTL_OneSensor_CSSAuth = E_OVSP_SW_Authorized;
      }
      break;

      case CAN_NTL_TWO_SENSOR:
      {
         V_CAN_NTL_OneSensor_CSSAuth = E_OVSP_SW_NotAuthorized;
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }

   switch (p_pt_RxFrame->S_RxData [OVSP_SW_LONG_1])
   {
      case CAN_NG_ONE_SENSOR:
      {
         V_CAN_NG_OneSensor_CSSAuth = E_OVSP_SW_Authorized;
      }
      break;

      case CAN_NG_TWO_SENSOR:
      {
         V_CAN_NG_OneSensor_CSSAuth = E_OVSP_SW_NotAuthorized;
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }
}
