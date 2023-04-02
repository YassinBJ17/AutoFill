/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef MODES_PUBLIC_H
#define MODES_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
/* None */


/* ---------- provided types: ----------------------------------------------- */
typedef enum
{
   E_Modes_Init          = 0,
   E_Modes_Degraded      = 1,
   E_Modes_Operational   = 2,
   E_Modes_TriggeredTest = 3,
   E_Modes_Fail          = 4
} TE_Modes_SW_Mode;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
extern void Modes_Initialize (void);
extern void Modes_Treatments (void);

extern TE_Modes_SW_Mode Modes_Get_SW_Mode (void);


#endif /* MODES_PUBLIC_H */
