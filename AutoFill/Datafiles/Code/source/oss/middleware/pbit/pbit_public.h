/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef PBIT_PUBLIC_H
#define PBIT_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Last faulty address and data */
extern uint32_t pbit_mram_faulty_addr;
extern uint32_t pbit_mram_faulty_data;

/* ---------- provided operations: ------------------------------------------ */

/* PBIT function */
extern void pbit(const boolean_t ch_is_a);

#endif /* PBIT_PUBLIC_H */
