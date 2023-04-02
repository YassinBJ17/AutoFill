/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Discretes outputs generation function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "IO_Public.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "CAN_Public.h"
#include "DrvFTM_Public.h"
#include "DrvGPIO_Public.h"
#include "OVSP_Public.h"

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
/* IO_Generate_Discretes : To generate the Discretes outputs
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void IO_Generate_Discretes (void)
{
   uint8_t v_OVSP_Side_Id;

   TE_OVSP_SW_Cmd v_CAM_Cmd1;
   TE_OVSP_SW_Cmd v_CAM_Cmd2;
   TE_OVSP_SW_Cmd v_DOUTINHIB_Cmd;
   TE_OVSP_SW_Cmd v_OSARM_Cmd;
   TE_OVSP_SW_Cmd v_REARM_Cmd;
   TE_OVSP_SW_Cmd v_DiscreteTest_Cmd;

   v_DOUTINHIB_Cmd = OVSP_Get_DOUTINHIB ();
   DrvGPIO_Write (DRVGPIO_OUT_DOUTINHIB, v_DOUTINHIB_Cmd);

   v_OSARM_Cmd = OVSP_Get_OSARM_Cmd ();
   DrvGPIO_Write (DRVGPIO_OUT_OSARM_CMD, v_OSARM_Cmd);

   v_REARM_Cmd = OVSP_Get_REARM_Cmd ();
   DrvGPIO_Write (DRVGPIO_OUT_REARM_CMD, v_REARM_Cmd);

   v_CAM_Cmd1 = OVSP_Get_CAM_Cmd1 ();

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   if (BOOT_SIDE_ID_HS == v_OVSP_Side_Id)
   {
      if (E_OVSP_SW_Cmd_On == v_CAM_Cmd1)
      {
         DrvFTM_Start_CAM_Generation ();
      }
      else
      {
         DrvFTM_Stop_CAM_Generation ();
      }

      v_DiscreteTest_Cmd = CAN_Get_TestDiscrete_Cmd ();
      DrvGPIO_Write (DRVGPIO_OUT_DISCRETE_TEST, v_DiscreteTest_Cmd);
   }
   else
   {
      DrvGPIO_Write (DRVGPIO_OUT_CAM_CMD1, v_CAM_Cmd1);
   }

   v_CAM_Cmd2 = OVSP_Get_CAM_Cmd2 ();
   DrvGPIO_Write (DRVGPIO_OUT_CAM_CMD2, v_CAM_Cmd2);
}
