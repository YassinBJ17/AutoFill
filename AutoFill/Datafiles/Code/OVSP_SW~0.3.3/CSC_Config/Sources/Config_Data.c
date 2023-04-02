/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Config CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Config_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
TU_Config_OVSP_Cfg V_Config_OVSP_Cfg_Used;
TU_Config_OVSP_Cfg V_Config_OVSP_Cfg_New;
TU_Config_OVSP_Cfg V_Config_OVSP_Cfg_Buffer;

TU_OVSP_SW_Uint16_Uint8 V_Last_Computed_16BitCRC;

TE_Config_Integrity_Status V_Config_OVSP_Cfg_Integrity;
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
