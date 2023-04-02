/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef IO_PUBLIC_H
#define IO_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
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
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void IO_Initialize (void);

extern void IO_Acquire_Discretes (void);
extern void IO_Acquire_Analogs (void);

extern void IO_Generate_Discretes (void);

extern TE_OVSP_SW_Cmd IO_Get_DININHIB_Cmd (void);
extern TE_OVSP_SW_Cmd IO_Get_OSREARM_Cmd (void);
extern TE_OVSP_SW_Cmd IO_Get_NTLOSTEST_Cmd (void);

extern float32_t IO_Get_Temperature (void);

extern float32_t IO_Get_CAM_Vload (void);
extern float32_t IO_Get_CAM_HS_Current (void);
extern float32_t IO_Get_CAM_LS_Current (void);

extern TE_OVSP_SW_Cmd IO_Get_DOUTINHIB_FB (void);
extern TE_OVSP_SW_Cmd IO_Get_CAMLOW2_FB (void);
extern TE_OVSP_SW_Cmd IO_Get_OSARM_FB (void);


#endif /* IO_PUBLIC_H */
