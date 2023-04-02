/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CAN frames reception management function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
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
/* CAN_Manage_Reception : To manage the CAN frames reception
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Manage_Reception (void)
{
   if (CAN_CAM_CMD_TIMEOUT <= V_CAN_CAM_Timing)
   {
      V_CAN_CAM_Timing = CAN_CAM_CMD_TIMEOUT;
   }
   else
   {
      V_CAN_CAM_Timing++;
   }

   if (CAN_REARM_RQST_TIMEOUT <= V_CAN_REARM_Timing)
   {
      V_CAN_REARM_Rqst = E_OVSP_SW_NotRequested;
      V_CAN_REARM_Timing = CAN_REARM_RQST_TIMEOUT;
   }
   else
   {
      V_CAN_REARM_Timing++;
   }

   CAN_Manage_Command_Frames ();

   CAN_Manage_SET_PARAM_Frames ();
}
