/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Discretes inputs acquisition function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "IO_Public.h"
#include "IO_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "DrvGPIO_Public.h"

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
/* IO_Acquire_Discretes : To acquire the Discretes inputs
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void IO_Acquire_Discretes (void)
{
   uint8_t v_OVSP_Side_Id;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   DrvGPIO_Read (DRVGPIO_IN_DININHIB,  &V_IO_DININHIB_Cmd);
   DrvGPIO_Read (DRVGPIO_IN_OSREARM,   &V_IO_OSREARM_Cmd);
   DrvGPIO_Read (DRVGPIO_IN_NTLOSTEST, &V_IO_NTLOSTEST_Cmd);

   DrvGPIO_Read (DRVGPIO_IN_DOUTINHIB_FB, &V_IO_DOUTINHIB_FB);

   if (BOOT_SIDE_ID_HS == v_OVSP_Side_Id)
   {
      DrvGPIO_Read (DRVGPIO_IN_CAMLOW2_FB, &V_IO_CAMLOW2_FB);
      DrvGPIO_Read (DRVGPIO_IN_OSARM_FB, &V_IO_OSARM_FB);
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
