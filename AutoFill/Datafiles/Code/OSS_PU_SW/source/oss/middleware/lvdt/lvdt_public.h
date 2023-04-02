/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LVDT_PUBLIC_H
#define LVDT_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
extern float32_t lvdt_vs1_measure;
extern float32_t lvdt_vs2_measure;
extern float32_t lvdt_ratio_measure;

/* Variables for demodulation result */
extern float32_t lvdt_exc_a;
extern float32_t lvdt_exc_b;
extern float32_t lvdt_exc_c;

/* ---------- provided operations: ------------------------------------------ */

/* Initialize lvdt acquisition */
extern void lvdt_init    (const boolean_t channel_is_a);

/* Performs lvdt acquisition and provides CSS with results */
extern void lvdt_periodic(const boolean_t channel_is_a);

#endif /* LVDT_PUBLIC_H */
