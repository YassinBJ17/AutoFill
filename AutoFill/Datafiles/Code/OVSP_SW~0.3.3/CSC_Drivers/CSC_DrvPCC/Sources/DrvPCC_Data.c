/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvPCC CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvPCC_Private.h"


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
TS_DrvPCC_Registers * const C_DrvPCC_Registers = (TS_DrvPCC_Registers *) (DRVPCC_PCC_ADDRESS);

/* {{RELAX<SYNCHRONe_C_Code_23.2> CR lem#11175: Braces and comma have not to be on next line for "Initializer list" */
const TS_DrvPCC_PCS_Config C_DrvPCC_PCS_Config [DRVPCC_PCC_USED_NB] =
{
   {DRVPCC_ADC0_INDEX,     DRVPCC_PCS_CLOCK_SOSC},
   {DRVPCC_ADC1_INDEX,     DRVPCC_PCS_CLOCK_SOSC},
   {DRVPCC_FLEXCAN1_INDEX, DRVPCC_PCS_CLOCK_NONE},
   {DRVPCC_FTM0_INDEX,     DRVPCC_PCS_CLOCK_SPLL},
   {DRVPCC_FTM1_INDEX,     DRVPCC_PCS_CLOCK_SPLL},
   {DRVPCC_FTM2_INDEX,     DRVPCC_PCS_CLOCK_OFF},
   {DRVPCC_FTM3_INDEX,     DRVPCC_PCS_CLOCK_SPLL},
   {DRVPCC_LPIT_INDEX,     DRVPCC_PCS_CLOCK_SPLL},
   {DRVPCC_LPSPI2_INDEX,   DRVPCC_PCS_CLOCK_SPLL},
   {DRVPCC_PORTA_INDEX,    DRVPCC_PCS_CLOCK_NONE},
   {DRVPCC_PORTB_INDEX,    DRVPCC_PCS_CLOCK_SOSC},
   {DRVPCC_PORTC_INDEX,    DRVPCC_PCS_CLOCK_NONE},
   {DRVPCC_PORTD_INDEX,    DRVPCC_PCS_CLOCK_SOSC},
   {DRVPCC_PORTE_INDEX,    DRVPCC_PCS_CLOCK_NONE}
};
/* }} RELAX<SYNCHRONe_C_Code_23.2> */
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
