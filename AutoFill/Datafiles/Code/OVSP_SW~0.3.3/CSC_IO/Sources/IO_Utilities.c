/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the IO CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "IO_Public.h"
#include "IO_Private.h"


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
/* IO_Get_DININHIB_Cmd : To provide the DININHIB Command
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - DININHIB Command
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd IO_Get_DININHIB_Cmd (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_IO_DININHIB_Cmd);
}


/* IO_Get_OSREARM_Cmd : To provide the OSREARM Command
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - OSREARM Command
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd IO_Get_OSREARM_Cmd (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_IO_OSREARM_Cmd);
}


/* IO_Get_NTLOSTEST_Cmd : To provide the NTLOSTEST Command
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - NTLOSTEST Command
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd IO_Get_NTLOSTEST_Cmd (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_IO_NTLOSTEST_Cmd);
}


/* IO_Get_DOUTINHIB_FB : To provide the DOUTINHIB FeedBack
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - DOUTINHIB FeedBack
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd IO_Get_DOUTINHIB_FB (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_IO_DOUTINHIB_FB);
}


/* IO_Get_CAMLOW2_FB : To provide the CAMLOW2 FeedBack
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - CAMLOW2 FeedBack
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd IO_Get_CAMLOW2_FB (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_IO_CAMLOW2_FB);
}


/* IO_Get_OSARM_FB : To provide the OSARM FeedBack
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - OSARM FeedBack
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd IO_Get_OSARM_FB (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_IO_OSARM_FB);
}


/* IO_Get_Temperature : To provide the Temperature
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - Temperature
 *   Pre-condition: None
*/
float32_t IO_Get_Temperature (void)
{
   return (V_IO_Temperature);
}


/* IO_Get_CAM_Vload : To provide the CAM Vload
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - CAM Vload
 *   Pre-condition: None
*/
float32_t IO_Get_CAM_Vload (void)
{
   return (V_IO_CAM_Vload);
}


/* IO_Get_CAM_HS_Current : To provide the CAM HS Current
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - CAM HS Current
 *   Pre-condition: None
*/
float32_t IO_Get_CAM_HS_Current (void)
{
   return (V_IO_CAM_HS_Current);
}


/* IO_Get_CAM_LS_Current : To provide the CAM LS Current
 *   Inputs: None
 *   Outputs: None
 *   Function return:
 *     - CAM LS Current
 *   Pre-condition: None
*/
float32_t IO_Get_CAM_LS_Current (void)
{
   return (V_IO_CAM_LS_Current);
}
