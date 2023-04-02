/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CBIT CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CBIT_Public.h"
#include "CBIT_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data is not internal as shared within the CSC. */
TE_CBIT_Test_Result V_CBIT_Test_Result;

TE_CBIT_Test_Result V_CBIT_OVSP_Side_Id_Test_Result;
TE_CBIT_Test_Result V_CBIT_OVSP_Cfg_Integrity;
TE_CBIT_Test_Result V_CBIT_OVSP_EOC_Integrity;

TS_CBIT_ECC_Test_Result V_CBIT_ECC_Test_Result;
TS_CBIT_FPU_Test_Result V_CBIT_FPU_Test_Result;
TS_CBIT_DRV_Test_Result V_CBIT_Test_Drivers_Result;
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* CBIT_Initialize : To initialize the CBIT CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CBIT_Initialize (void)
{
   /* Initialize the synthetized CBIT Test Result */
   V_CBIT_Test_Result = E_CBIT_Passed;

   /* Initialize the OVSP Side ID test result */
   V_CBIT_OVSP_Side_Id_Test_Result = E_CBIT_Passed;

   /* Initialize the OVSP Cfg Table test result */
   V_CBIT_OVSP_Cfg_Integrity = E_CBIT_Passed;

   /* Initialize the OVSP EOC Integrity test result */
   V_CBIT_OVSP_EOC_Integrity = E_CBIT_Passed;

   /* Initialize the ECC CBIT test result */
   V_CBIT_ECC_Test_Result.S_ECC_Single_Test = E_CBIT_Passed;
   V_CBIT_ECC_Test_Result.S_ECC_Mult_Test   = E_CBIT_Passed;

   V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_PFlash = E_CBIT_Passed;
   V_CBIT_ECC_Test_Result.S_ECC_FTFC_Double_Test_NVM    = E_CBIT_Passed;

   /* Initialize the FPU CBIT test result */
   V_CBIT_FPU_Test_Result.S_FPU_FIOC_Test = E_CBIT_Passed;
   V_CBIT_FPU_Test_Result.S_FPU_FDZC_Test = E_CBIT_Passed;
   V_CBIT_FPU_Test_Result.S_FPU_FOFC_Test = E_CBIT_Passed;
   V_CBIT_FPU_Test_Result.S_FPU_FUFC_Test = E_CBIT_Passed;

   /* Inexact is not tested in run */
   V_CBIT_FPU_Test_Result.S_FPU_FIXC_Test = E_CBIT_Passed;
   V_CBIT_FPU_Test_Result.S_FPU_FIDC_Test = E_CBIT_Passed;

   /* Initialize the DRV CBIT test result */
   V_CBIT_Test_Drivers_Result.S_DrvMCM_Test        = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvCAN_Test        = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvLPSPI_Test      = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvGPIO_Test       = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvFTM_Test        = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvFTFC_Test       = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvFTM_CAM_Test    = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvADC_Test        = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvLPIT_Test       = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvPCC_Test        = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvPAD_Test        = E_CBIT_Passed;
   V_CBIT_Test_Drivers_Result.S_DrvFTM_TSpeed_Test = E_CBIT_Passed;
}
