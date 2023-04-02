/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvGPIO Discrete input read function
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
/* DrvGPIO_Read : To read a Discrete input
 *   Inputs:
 *     - p_GPIO_Name: Name of the Discrete input to read
 *   Outputs:
 *     - p_pt_Read_Cmd: Read command on the Discrete input
 *   Function return: None
 *   Pre-condition: None
*/
void DrvGPIO_Read (const uint32_t p_GPIO_Name, TE_OVSP_SW_Cmd * const p_pt_Read_Cmd)
{
   uint32_t v_PDIR_Value;
   uint32_t v_PIN_Value;

   if (DRVGPIO_LAST_INPUT >= p_GPIO_Name)
   {
      v_PDIR_Value = C_DrvGPIO_Registers [C_DrvGPIO_IO_Config [p_GPIO_Name].S_Port_Id]->S_PDIR;

      v_PIN_Value = (v_PDIR_Value >> C_DrvGPIO_IO_Config [p_GPIO_Name].S_Pin_Number) & DRVGPIO_BIT_0_MASK;
   }
   else
   {
      v_PIN_Value = OVSP_SW_LONG_MAX;
   }

   if (C_DrvGPIO_IO_Config [p_GPIO_Name].S_Active_State == v_PIN_Value)
   {
      *p_pt_Read_Cmd = E_OVSP_SW_Cmd_On;
   }
   else
   {
      *p_pt_Read_Cmd = E_OVSP_SW_Cmd_Off;
   }
}
