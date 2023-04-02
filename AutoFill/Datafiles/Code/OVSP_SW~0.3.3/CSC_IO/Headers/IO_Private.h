/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef IO_PRIVATE_H
#define IO_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "DrvFTM_Public.h"

#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern TE_OVSP_SW_Cmd V_IO_DININHIB_Cmd;
extern TE_OVSP_SW_Cmd V_IO_OSREARM_Cmd;
extern TE_OVSP_SW_Cmd V_IO_NTLOSTEST_Cmd;

extern TE_OVSP_SW_Cmd V_IO_DOUTINHIB_FB;
extern TE_OVSP_SW_Cmd V_IO_CAMLOW2_FB;
extern TE_OVSP_SW_Cmd V_IO_OSARM_FB;

extern float32_t V_IO_Temperature;
extern float32_t V_IO_CAM_Vload;
extern float32_t V_IO_CAM_HS_Current;
extern float32_t V_IO_CAM_LS_Current;


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* IO_PRIVATE_H */
