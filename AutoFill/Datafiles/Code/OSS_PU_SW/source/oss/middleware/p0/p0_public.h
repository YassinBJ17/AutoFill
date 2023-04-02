/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef P0_PUBLIC_H
#define P0_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* P0 device BIT status */
extern uint32_t    p0_internal_cbit;

/* P0 raw value */
extern uint16_t    p0_raw_value;

/* ---------- provided operations: ------------------------------------------ */
/* Initialize data needed by p0 */
/* Implements REQ_FADEX_OS_SRD-P0-0010 */
void p0_init(const boolean_t p_is_channel_a);

/* P0 CBIT, measure and reset management */
/* Implements REQ_FADEX_OS_SRD-P0-0010 */
/* Implements REQ_FADEX_OS_SRD-P0-0020 */
void p0_periodic(const boolean_t p_is_channel_a);

#endif /* P0_PUBLIC_H */
