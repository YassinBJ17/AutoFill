/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvGPIO Discrete output write function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvGPIO_Public.h"
#include "DrvGPIO_Private.h"


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
/* DrvGPIO_Write : To write a Discrete output
 *   Inputs:
 *     - p_GPIO_Name: Name of the Discrete output to write
 *   Outputs:
 *     - p_Cmd_To_Write: Command to write on the Discrete output
 *   Function return: None
 *   Pre-condition: None
*/
void DrvGPIO_Write (const uint32_t p_GPIO_Name, const TE_OVSP_SW_Cmd p_Cmd_To_Write)
{
   uint32_t v_Pin_Mask;
   uint32_t v_Pin_State;

   if ((DRVGPIO_FIRST_OUTPUT <= p_GPIO_Name) && (DRVGPIO_LAST_OUTPUT >= p_GPIO_Name))
   {
      v_Pin_Mask = C_DrvGPIO_IO_Config [p_GPIO_Name].S_Pin_Mask;

      if (E_OVSP_SW_Cmd_On == p_Cmd_To_Write)
      {
         v_Pin_State = C_DrvGPIO_IO_Config [p_GPIO_Name].S_Active_State;
      }
      else
      {
         v_Pin_State = C_DrvGPIO_IO_Config [p_GPIO_Name].S_Idle_State;
      }

      if (DRVGPIO_STATE_LOW == v_Pin_State)
      {
         C_DrvGPIO_Registers [C_DrvGPIO_IO_Config [p_GPIO_Name].S_Port_Id]->S_PCOR = v_Pin_Mask;
      }
      else
      {
         C_DrvGPIO_Registers [C_DrvGPIO_IO_Config [p_GPIO_Name].S_Port_Id]->S_PSOR = v_Pin_Mask;
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
