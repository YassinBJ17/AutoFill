/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvGPIO CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvGPIO_Public.h"
#include "DrvGPIO_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"

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
/* DrvGPIO_Initialize : To initialize the DrvGPIO CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvGPIO_Initialize (void)
{
   uint8_t  v_OVSP_Side_Id;
   uint32_t v_GPIO_Side_Id;
   uint32_t v_Iter_Port;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   if (BOOT_SIDE_ID_LS == v_OVSP_Side_Id)
   {
      v_GPIO_Side_Id = DRVGPIO_OVSP_LS_ID;
   }
   else
   {
      v_GPIO_Side_Id = DRVGPIO_OVSP_HS_ID;
   }

   for (v_Iter_Port = 0UL; v_Iter_Port < DRVGPIO_MAX_PORTS_NB ; v_Iter_Port++)
   {
      C_DrvGPIO_Registers [v_Iter_Port]->S_PDDR = C_DrvGPIO_Port_Config [v_GPIO_Side_Id] [v_Iter_Port].S_PDDR_Config;
      C_DrvGPIO_Registers [v_Iter_Port]->S_PIDR = C_DrvGPIO_Port_Config [v_GPIO_Side_Id] [v_Iter_Port].S_PIDR_Config;
   }
}
