/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvMCM CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvMCM_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* >RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
/* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
/* converted to pointers which are also an 32-bit Unsigned Long. */
TS_DrvMCM_Registers * const C_DrvMCM_Registers = (TS_DrvMCM_Registers *) DRVMCM_MCM_ADDRESS;


/* ---------- provided data: ------------------------------------------------ */
volatile uint32_t V_DrvMCM_PBIT_FPU_FIOC_Cnt;
uint32_t V_DrvMCM_PBIT_FPU_FIOC_status;
uint32_t V_DrvMCM_PBIT_FPU_FDZC_status;
uint32_t V_DrvMCM_PBIT_FPU_FOFC_status;
uint32_t V_DrvMCM_PBIT_FPU_FUFC_status;
uint32_t V_DrvMCM_PBIT_FPU_FIXC_status;
uint32_t V_DrvMCM_PBIT_FPU_FIDC_status;

uint32_t V_DrvMCM_CBIT_FPU_FIOC_status;
uint32_t V_DrvMCM_CBIT_FPU_FDZC_status;
uint32_t V_DrvMCM_CBIT_FPU_FOFC_status;
uint32_t V_DrvMCM_CBIT_FPU_FUFC_status;
uint32_t V_DrvMCM_CBIT_FPU_FIDC_status;
/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
