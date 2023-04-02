/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"

/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "OVSP_Public.h"
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
/* DrvFTM_Initialize_Freq_Acq_Data : To initialize the NGOS1, NGOS2, NTLOS1 and NTLOS2 data
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Initialize_TSpeed_Data (void)
{
   V_DrvFTM_TSpeed_Applied_Speed = 0.0f;
   V_DrvFTM_TSpeed_Test_Speed_Prev = 0.0f;
   V_DrvFTM_New_Test_Speed_Recv = FALSE;
   V_DrvFTM_TSpeed_Activation_Status = FALSE;
   V_DrvFTM_TSpeed_Signal_Mod = (uint16_t)0x0000;
}
