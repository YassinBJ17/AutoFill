/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the PBIT CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "PBIT_Public.h"
#include "PBIT_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


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
/* PBIT_Initialize : To initialize the PBIT CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void PBIT_Initialize (void)
{
   /* Initialize the synthetized PBIT Test Result */
   V_PBIT_Test_Result = E_PBIT_Passed;

   /* Initialize the OVSP Side ID test result */
   V_PBIT_OVSP_Side_Id_Test_Result = E_PBIT_Failed;

   /* Initialize the OVSP Cfg Table test result */
   V_PBIT_OVSP_Cfg_Integrity = E_PBIT_Failed;

   /* Initialize the OVSP EOC Integrity test result */
   V_PBIT_OVSP_EOC_Integrity = E_PBIT_Failed;

   /* Initialize the ECC PBIT test result */
   V_PBIT_ECC_Test_Result.S_ECC_Single_Test = E_PBIT_Failed;
   V_PBIT_ECC_Test_Result.S_ECC_Mult_Test = E_PBIT_Failed;
   V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_PBIT_Failed;
   V_PBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM = E_PBIT_Failed;

   /* Initialize the FPU PBIT test result */
   V_PBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_PBIT_Failed;
   V_PBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_PBIT_Failed;
   V_PBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_PBIT_Failed;
   V_PBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_PBIT_Failed;
   V_PBIT_FPU_Test_Result.S_FPU_FIXC_Test = E_PBIT_Failed;
   V_PBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_PBIT_Failed;

   /* Initialize the Drivers PBIT test result */
   V_PBIT_Test_Drivers_Result.S_DrvMCM_Test   = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvCAN_Test   = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvLPSPI_Test = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvGPIO_Test  = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvFTM_Test   = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvFTFC_Test  = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvADC_Test   = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvLPIT_Test  = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvPCC_Test   = E_PBIT_Failed;
   V_PBIT_Test_Drivers_Result.S_DrvPAD_Test   = E_PBIT_Failed;

   V_PBIT_ECC_Cpt_FTFC = 0UL;
   V_PBIT_FPU_Generated_FIOC_Faults = 0UL;
}
