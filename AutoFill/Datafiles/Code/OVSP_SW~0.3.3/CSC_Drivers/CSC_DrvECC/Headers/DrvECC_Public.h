/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVECC_PUBLIC_H
#define DRVECC_PUBLIC_H

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
extern void DrvECC_Generate_SingMultErr (void);

extern void DrvECC_ERM_Clear_Single_Err (void);
extern void DrvECC_ERM_Clear_Multiple_Err (void);


#endif /* DRVECC_PUBLIC_H */
