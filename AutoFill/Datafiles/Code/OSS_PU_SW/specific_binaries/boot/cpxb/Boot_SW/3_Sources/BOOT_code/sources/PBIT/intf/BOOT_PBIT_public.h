#ifndef BOOT_PBIT_public_H
#define BOOT_PBIT_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */

/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal datas: ----------------------------------------------- */
extern uint32_t V_BOOT_PBIT_INTC;

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */

extern void BOOT_PBIT_SW_MAIN(void);

extern void BOOT_PBIT_CMPU (uint32_t const p_numcore);
#endif /* BOOT_PBIT_public_H */
