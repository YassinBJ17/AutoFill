/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef T4_PUBLIC_H
#define T4_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
extern float32_t tcj_conv;

/* Final TCJ value */
extern float32_t t4_tcj;

/* Average of the 8 T4 signal voltage acquisition */
extern float32_t t4_sig_voltage_avg;

/* T4 computed voltage */
extern float32_t t4_voltage_cmp_value;

/* ---------- provided operations: ------------------------------------------ */
/* T4 initialization function */
extern void t4_init(void);

/* Implements REQ_FADEX_OS_SRD- */
/* T4 periodic function acquisition and CBIT */
extern void t4_periodic(const boolean_t channel_is_a);

#endif /* T4_PUBLIC_H */
