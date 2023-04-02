/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef RESOLVER_PUBLIC_H
#define RESOLVER_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Variables for demodulation result */
extern float32_t xr_exc;
extern float32_t xrb_exc;

/* ---------- provided operations: ------------------------------------------ */

/* Initialize resolver acquisition */
extern void resolver_init    (const boolean_t channel_is_avoid);

/* Performs resolver acquisition and provides CSS with results */
extern void resolver_periodic(const boolean_t channel_is_a);

#endif /* RESOLVER_PUBLIC_H */
