/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the ...
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "DrvSBC_Private.h"

/* ---------- include provided interface: ----------------------------------- */
#include "DrvLPSPI_Public.h"

#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */

/* ---------- internal types: ----------------------------------------------- */
/* None */

/* ---------- internal operations: ------------------------------------------ */
/* None */

/* ---------- internal constants: ------------------------------------------- */
/* None */

/* ---------- internal data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */
/* DrvSBC_Get_Current_Mode : To retrieve the current mode of the SBC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
TE_DrvSBC_States DrvSBC_Get_Current_Mode (void)
{
   TE_DrvSBC_States v_Current_Mode;

   uint32_t v_Status;
   uint32_t v_Read_Value;
   uint32_t v_Read_Mode;

   DrvLPSPI_Write (DRVSBC_INIT_SAFE_REG_READ, &v_Status);

   DrvLPSPI_Read (&v_Read_Value, &v_Status);

   v_Read_Mode = (v_Read_Value & DRVSBC_MODE_STATE_MASK) >> DRVSBC_MODE_STATE_SHIFT;

   switch (v_Read_Mode)
   {
      case DRVSBC_MODE_INIT_VAL:
      {
         v_Current_Mode = E_DrvSBC_Mode_Init;
      }
      break;

      case DRVSBC_MODE_FLASH_VAL:
      {
         v_Current_Mode = E_DrvSBC_Mode_Flash;
      }
      break;

      case DRVSBC_MODE_NORMAL_REQUEST_VAL:
      {
         v_Current_Mode = E_DrvSBC_Mode_Normal_Request;
      }
      break;

      case DRVSBC_MODE_NORMAL_VAL:
      {
         v_Current_Mode = E_DrvSBC_Mode_Normal;
      }
      break;

      default:
      {
         if (DRVSBC_MODE_LP_STATE_MASK == (v_Read_Mode & DRVSBC_MODE_LP_STATE_MASK))
         {
            v_Current_Mode = E_DrvSBC_Mode_Low_Power;
         }
         else
         {
            v_Current_Mode = E_DrvSBC_Mode_Init_Reset;
         }
      }
      break;

   }

   return (v_Current_Mode);
}
