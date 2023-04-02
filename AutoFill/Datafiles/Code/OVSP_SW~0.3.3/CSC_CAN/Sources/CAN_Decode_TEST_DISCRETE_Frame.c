/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the TEST_DISCRETE Command frame decoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvCAN_Public.h"
#include "Modes_Public.h"

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
/* CAN_Decode_TEST_DISCRETE_Frame : To decode the TEST_DISCRETE Command frame
 *   Inputs:
 *     - p_pt_RxFrame: Buffer of the received frame
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Decode_TEST_DISCRETE_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame)
{
   TE_Modes_SW_Mode v_SW_Mode;

   v_SW_Mode = Modes_Get_SW_Mode ();

   if ((CAN_DISCRETE_TEST_ON == p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0]) && (E_Modes_TriggeredTest == v_SW_Mode))
   {
      V_CAN_TestDiscrete_Cmd = E_OVSP_SW_Cmd_On;
   }
   else
   {
      V_CAN_TestDiscrete_Cmd = E_OVSP_SW_Cmd_Off;
   }
}
