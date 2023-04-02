/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef POWERSUP_PUBLIC_H
#define POWERSUP_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#define K_OFFSET_ADC_CONVERT_VALUE     (float32_t)(1.000/0.048)

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Measured voltage */
extern float32_t c_voltage_measure;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Powersup initialization function */
extern void powersup_init(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0020 */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0030 */
/* Powersup periodic function (CBIT) */
extern void powersup_periodic(const boolean_t channel_is_a);

#endif /* POWERSUP_PUBLIC_H */
