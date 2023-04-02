/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef MODES_PRIVATE_H
#define MODES_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "Modes_Public.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
extern TE_Modes_SW_Mode V_Modes_SW_Mode;


/* ---------- provided operations: ------------------------------------------ */
extern void Modes_Manage_Init_Tr (void);

extern void Modes_Manage_Operational_Tr (void);

extern void Modes_Manage_Degraded_Tr (void);

extern void Modes_Manage_TriggTest_Tr (void);


#endif /* MODES_PRIVATE_H */
