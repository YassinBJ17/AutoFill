/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the IO CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "IO_Public.h"
#include "IO_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "DrvFTM_Public.h"
#include "DrvGPIO_Public.h"

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
/* IO_Initialize : To initialize the IO CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void IO_Initialize (void)
{
   uint8_t v_OVSP_Side_Id;

   V_IO_DININHIB_Cmd = E_OVSP_SW_Cmd_Off;
   V_IO_OSREARM_Cmd = E_OVSP_SW_Cmd_Off;
   V_IO_NTLOSTEST_Cmd = E_OVSP_SW_Cmd_Off;

   V_IO_DOUTINHIB_FB = E_OVSP_SW_Cmd_Off;
   V_IO_CAMLOW2_FB = E_OVSP_SW_Cmd_Off;
   V_IO_OSARM_FB = E_OVSP_SW_Cmd_Off;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   if (BOOT_SIDE_ID_HS == v_OVSP_Side_Id)
   {
      DrvFTM_Stop_CAM_Generation ();
   }
   else
   {
      DrvGPIO_Write (DRVGPIO_OUT_CAM_CMD1, E_OVSP_SW_Cmd_Off);
   }

   DrvGPIO_Write (DRVGPIO_OUT_CAM_CMD2, E_OVSP_SW_Cmd_Off);

   DrvGPIO_Write (DRVGPIO_OUT_DOUTINHIB, E_OVSP_SW_Cmd_Off);
   DrvGPIO_Write (DRVGPIO_OUT_OSARM_CMD, E_OVSP_SW_Cmd_Off);
   DrvGPIO_Write (DRVGPIO_OUT_DISCRETE_TEST, E_OVSP_SW_Cmd_Off);

   V_IO_Temperature = 0.0f;
   V_IO_CAM_Vload = 0.0f;
   V_IO_CAM_HS_Current = 0.0f;
   V_IO_CAM_LS_Current = 0.0f;
}
