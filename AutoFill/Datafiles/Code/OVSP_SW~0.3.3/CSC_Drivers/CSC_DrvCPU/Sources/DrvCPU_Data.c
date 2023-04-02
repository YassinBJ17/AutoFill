/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : DrvCPU_Initialize : To initialize the Cortex M4f CPU
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
/* None */

/* ---------- include external interface: ----------------------------------- */
/* None */

/* ---------- include required interface: ----------------------------------- */
#include "DrvCPU_Public.h"

/* ---------- provided define constants: ------------------------------------ */
/* None */

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- provided data: ------------------------------------------------ */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
const TPTF_DrvCPU_VectorsTable C_PtF_DrvCPU_Enter_Crit_Sect = &DrvCPU_Enter_Crit_Sect;
const TPTF_DrvCPU_VectorsTable C_PtF_DrvCPU_Exit_Crit_Sect = &DrvCPU_Exit_Crit_Sect;
/* }} RELAX<SYNCHRONe_C_Code_24.5> */

/* ---------- provided operation bodies: ------------------------------------ */
/* None */
