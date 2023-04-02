/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SEQ_PUBLIC_H
#define SEQ_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
/* None */


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
extern void Seq_Initialize (void);

extern void Seq_Task_Main (void);

extern void Seq_Task_BckGrnd (void);

extern void Seq_Set_NewConfig_Status (void);
extern void Seq_Set_NewConfig_toUse (void);


#endif /* SEQ_PUBLIC_H */
