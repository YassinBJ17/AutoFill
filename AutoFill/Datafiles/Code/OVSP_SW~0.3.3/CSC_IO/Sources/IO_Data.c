/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the IO CSC data definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "IO_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* {{RELAX<SYNCHRONe_C_Code_24.5> Waiting for SYNCHONe analyze, it seems to be a false violation. */
/* The data are not internal as shared within the CSC. */
TE_OVSP_SW_Cmd V_IO_DININHIB_Cmd;
TE_OVSP_SW_Cmd V_IO_OSREARM_Cmd;
TE_OVSP_SW_Cmd V_IO_NTLOSTEST_Cmd;

TE_OVSP_SW_Cmd V_IO_DOUTINHIB_FB;
TE_OVSP_SW_Cmd V_IO_CAMLOW2_FB;
TE_OVSP_SW_Cmd V_IO_OSARM_FB;

float32_t V_IO_Temperature;
float32_t V_IO_CAM_Vload;
float32_t V_IO_CAM_HS_Current;
float32_t V_IO_CAM_LS_Current;
/* }} RELAX<SYNCHRONe_C_Code_24.5> */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* None */
