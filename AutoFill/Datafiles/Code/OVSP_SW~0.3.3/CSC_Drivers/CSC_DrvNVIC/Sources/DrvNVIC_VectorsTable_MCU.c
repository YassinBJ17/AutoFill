/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvNVIC MCU Vectors Table definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvNVIC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "PBIT_Public.h"
#include "DrvMCM_Public.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* >RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
const TPTF_DrvNVIC_VectorsTable C_DrvNVIC_VectorsTable_MCU [DRVNVIC_MCU_VECTORS_NB] =
{
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvMCM_Check_PBIT_FPU_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &PBIT_ECC_FTFC_Int_Double_Bit_Err,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &PBIT_Test_ECC_Int_Single_Error,
   &PBIT_Test_ECC_Int_Multiple_Error,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
};


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
