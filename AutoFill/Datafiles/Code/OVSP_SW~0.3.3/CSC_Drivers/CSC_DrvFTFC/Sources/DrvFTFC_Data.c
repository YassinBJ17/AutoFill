/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTFC CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
/* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
/* converted to pointers which are also an 32-bit Unsigned Long. */
TS_DrvFTFC_Registers * const C_DrvFTFC_Registers = (TS_DrvFTFC_Registers *) (DRVFTFC_FTCF_ADDRESS);

const TPF_DrvFTFC_Configure_ECC_Test C_PtF_DrvFTFC_Config_ECC_Test = &DrvFTFC_Configure_ECC_Test;

const TPF_DrvFTFC_Erase C_PtF_DrvFTFC_Erase = &DrvFTFC_Erase;
const TPF_DrvFTFC_Write C_PtF_DrvFTFC_Write = &DrvFTFC_Write;
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


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
