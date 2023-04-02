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
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data is not internal as shared within the CSC. */
TE_PBIT_Test_Result V_PBIT_Test_Result;

TE_PBIT_Test_Result V_PBIT_OVSP_Side_Id_Test_Result;
TE_PBIT_Test_Result V_PBIT_OVSP_Cfg_Integrity;
TE_PBIT_Test_Result V_PBIT_OVSP_EOC_Integrity;
TE_PBIT_Test_Result V_PBIT_RAM_Test_Result;

TS_PBIT_ECC_Test_Result V_PBIT_ECC_Test_Result;
TS_PBIT_FPU_Test_Result V_PBIT_FPU_Test_Result;
TS_PBIT_Drv_Test_Result V_PBIT_Test_Drivers_Result;

uint32_t V_PBIT_ECC_Cpt_FTFC;
uint32_t V_PBIT_FPU_Generated_FIOC_Faults;
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
