/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVCPU_PUBLIC_H
#define DRVCPU_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
typedef void (* TPTF_DrvCPU_VectorsTable) (void);


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern const TPTF_DrvCPU_VectorsTable C_PtF_DrvCPU_Enter_Crit_Sect;
extern const TPTF_DrvCPU_VectorsTable C_PtF_DrvCPU_Exit_Crit_Sect;


/* ---------- provided operations: ------------------------------------------ */
extern void DrvCPU_Initialize (void);
extern void DrvCPU_Init_Stack (void);
extern void DrvCPU_Enter_Crit_Sect (void);
extern void DrvCPU_Exit_Crit_Sect (void);
extern void DrvCPU_Init_FPU_Sn_Reg (void);
extern void DrvCPU_Init_FPSCR_Reg (void);
extern void DrvCPU_Init_FPU_FPSCR_Reg (void);

extern void DrvCPU_Generate_FPU_FDZC (void);
extern void DrvCPU_Generate_FPU_FIDC (void);
extern uint32_t DrvCPU_Generate_FPU_FIOC (void);
extern void DrvCPU_Generate_FPU_FIXC (void);
extern void DrvCPU_Generate_FPU_FOFC (void);
extern void DrvCPU_Generate_FPU_FUFC (void);

#endif /* DRVCPU_PUBLIC_H */
