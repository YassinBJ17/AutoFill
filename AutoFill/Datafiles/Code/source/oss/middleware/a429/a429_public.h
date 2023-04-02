/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef A429_PUBLIC_H
#define A429_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-A429-0010 */
/* Implements REQ_FADEX_OS_SRD-A429-0020 */
/* Initialize the A429 (Input : Is it the channel A?) */
extern void a429_init(const boolean_t ch_is_a);

/* Implements REQ_FADEX_OS_SRD-A429-0030 */
/* Implements REQ_FADEX_OS_SRD-A429-0040 */
/* Read and transmit A429 message(s) (Input : Is it the channel A?) */
extern void a429_periodic(const boolean_t ch_is_a);

#endif /* A429_PUBLIC_H  */
