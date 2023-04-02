/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvADC CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvADC_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
/* {{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
/* converted to pointers which are also an 32-bit Unsigned Long. */
TS_DrvADC_Registers * const C_DrvADC_Registers [DRVADC_MAX_CTRL_NB] =
{
   (TS_DrvADC_Registers *) DRVADC_ADC0_ADDRESS,
   (TS_DrvADC_Registers *) DRVADC_ADC1_ADDRESS
};
/* }} RELAX<SYNCHRONe_C_Code_10.7> */

/* {{RELAX<SYNCHRONe_C_Code_23.2> CR lem#11175: Braces and comma have not to be on next line for "Initializer list" */
const TS_DrvADC_Port_Definition C_DrvADC_Port_Def [DRVADC_ANALOG_MAX_NB] =
{
   {DRVADC_ADC0_ID, DRVADC_SC1A_CAM_HS_CURRENT, DRVADC_CAM_HS_CURRENT_GAIN, 0.0f},
   {DRVADC_ADC0_ID, DRVADC_SC1A_CAM_LS_CURRENT, DRVADC_CAM_LS_CURRENT_GAIN, 0.0f},
   {DRVADC_ADC0_ID, DRVADC_SC1A_CAM_VLOAD,      DRVADC_CAM_VLOAD_GAIN,      0.0f},
   {DRVADC_ADC1_ID, DRVADC_SC1A_TEMPERATURE,    DRVADC_TEMPERATURE_GAIN,    DRVADC_TEMPERATURE_OFFSET}
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
