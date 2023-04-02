/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef TMOT_WRITE_PUBLIC_H
#define TMOT_WRITE_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Value allowing the conversion from current to voltage */
#define CONV_CURR_TO_VOLT (float32_t)(4096./100)

/* The internal ADC offset value (mA) */
#define CURR_OFFSET (float32_t)50

/* The maximum expected tmot current command value (mA) */
#define TMOT_CURRENT_CMD_MAX (float32_t)30

/* The minimum expected tmot current command value (mA) */
#define TMOT_CURRENT_CMD_MIN (float32_t)-30

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0001 */
/* Transmit the CSS_PU command to FPGA when the command is valid */
extern void tmot_write(void);

#endif /* TMOT_WRITE_PUBLIC_H */
