/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Analogs inputs acquisition function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "IO_Public.h"
#include "IO_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "DrvADC_Public.h"

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
/* IO_Acquire_Analogs : To acquire the Analogs inputs
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void IO_Acquire_Analogs (void)
{
   uint8_t v_OVSP_Side_Id;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   DrvADC_Read (DRVADC_TEMPERATURE, &V_IO_Temperature);

   if (BOOT_SIDE_ID_HS == v_OVSP_Side_Id)
   {
      DrvADC_Read (DRVADC_CAM_VLOAD, &V_IO_CAM_Vload);

      DrvADC_Read (DRVADC_CAM_HS_CURRENT, &V_IO_CAM_HS_Current);
      DrvADC_Read (DRVADC_CAM_LS_CURRENT, &V_IO_CAM_LS_Current);
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
