/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SEQ_PRIVATE_H
#define SEQ_PRIVATE_H

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
extern boolean_t V_Seq_NewConfig_To_Use;
extern boolean_t V_Seq_NewConfig_To_Manage;


/* ---------- provided operations: ------------------------------------------ */
extern void Seq_Start_Sequencer (void);


#endif /* SEQ_PRIVATE_H */
