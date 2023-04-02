/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVCPU_PRIVATE_H
#define DRVCPU_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
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
extern void DrvCPU_Init_APSR_Reg (void);

extern void DrvCPU_Init_BASEPRI_Reg (void);

extern void DrvCPU_Init_CONTROL_Reg (void);

extern void DrvCPU_Init_CPACR_Reg (void);

extern void DrvCPU_Init_EPSR_Reg (void);

extern void DrvCPU_Init_FPCA_Reg (void);

extern void DrvCPU_Init_FPCCR_Reg (void);

extern void DrvCPU_Init_GPRs (void);

extern void DrvCPU_Init_ISCR_Reg (void);

extern void DrvCPU_Init_VTOR_InSRAM (void);

#endif /* DRVCPU_PRIVATE_H */
