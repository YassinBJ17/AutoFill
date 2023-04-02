/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CAN Treatments function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Public.h"
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


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
/* CAN_Treatments : To perform the CAN Treatments
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Treatments (void)
{
   V_CAN_NG_Status = CAN_Get_NG_Status ();
   V_CAN_NTL_Status = CAN_Get_NTL_Status ();

   if ((V_CAN_NG_Status != V_CAN_NG_Status_Prev) || (V_CAN_NTL_Status != V_CAN_NTL_Status_Prev))
   {
      V_CAN_NG_NTL_Statuses_Sent = FALSE;

      V_CAN_NG_Status_Prev = V_CAN_NG_Status;
      V_CAN_NTL_Status_Prev = V_CAN_NTL_Status;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (V_CAN_Compatibility_Status)
   {
      CAN_Manage_Reception ();

      if (V_CAN_GET_DATA_Received && (CAN_DATA_FRAME_NB > V_CAN_DATA_FrameToSend))
      {
         DrvCAN_Write (DRVCAN_TX_DATA_MB_ID, &(V_CAN_DATA_Frames [V_CAN_DATA_FrameToSend]));

         switch (V_CAN_DATA_FrameToSend)
         {
            case CAN_DATA_FRAME01_INDEX:
            {
               V_CAN_NG_NTL_Statuses_Sent = TRUE;
            }
            break;

            case CAN_DATA_FRAME06_INDEX:
            {
               V_CAN_GET_DATA_Received = FALSE;
            }
            break;

            default:
            { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
               /* Nothing to do */
            }
            break;

         }

         V_CAN_DATA_FrameToSend++;
      }
      else
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
