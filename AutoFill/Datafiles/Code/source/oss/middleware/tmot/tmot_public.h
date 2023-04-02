/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef TMOT_PUBLIC_H
#define TMOT_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* The maximum expected tmot current feedback value (mA) */
#define TMOT_CURRENT_MAX (float32_t)35.4

/* The minimum expected tmot current feedback value (mA) */
#define TMOT_CURRENT_MIN (float32_t)-35.4

/* The maximum expected tmot voltage feedback value (V) */
#define TMOT_VOLTAGE_MAX (float32_t)17.8

/* The minimum expected tmot voltage feedback value (V) */
#define TMOT_VOLTAGE_MIN (float32_t)-17.8

/* Value allowing the conversion from current to voltage */
#define CONV_CURR_TO_VOLT (float32_t)(4096/60)

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0030 */
/* Tmot initialization function */
extern void tmot_init(void);

/* Implements REQ_FADEX_OS_SRD-TMOT-0010 */
/* Tmot periodic function (CBIT) */
extern void tmot_periodic(const boolean_t channel_is_a);

#endif /* TMOT_PUBLIC_H */
