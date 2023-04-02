/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef PWM_PUBLIC_H
#define PWM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Initialize and configure the PWM in FPGA and shared memory */
/* Implements REQ_FADEX_OS_SRD-PWM-0010 */
extern void pwm_init(const boolean_t p_channel_is_a);

/* Command the PWM according to the CSS_PU request and perform CBIT */
/* Implements REQ_FADEX_OS_SRD-PWM-0020 */
/* Implements REQ_FADEX_OS_SRD-PWM-0030 */
extern void pwm_periodic(const boolean_t p_channel_is_a);

#endif /* PWM_PUBLIC_H */
