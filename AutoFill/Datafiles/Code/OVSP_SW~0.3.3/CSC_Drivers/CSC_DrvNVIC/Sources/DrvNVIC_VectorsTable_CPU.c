/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvNVIC CPU Vectors Table definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvNVIC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* >RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
const TPTF_DrvNVIC_VectorsTable C_DrvNVIC_VectorsTable_CPU [DRVNVIC_CPU_VECTORS_NB] =
{
   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long address */
   /* converted to a pointer which is also an 32-bit Unsigned Long. */
   /* >RELAX<SYNCHRONe_C_Code_11.1> The conversion is mandatory for addresses provided by */
   /* identifiers defined in the linker command file. */
   (TPTF_DrvNVIC_VectorsTable) &__Linker_Stack_Main,
   &Boot_Initialize,
   &Boot_Handle_NMI,
   &Boot_Handle_HardFault,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ,
   &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ, &DrvNVIC_Unmapped_IRQ
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
