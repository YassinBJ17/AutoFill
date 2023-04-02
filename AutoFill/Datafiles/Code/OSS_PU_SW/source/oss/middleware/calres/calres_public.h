/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CALRES_PUBLIC_H
#define CALRES_PUBLIC_H

#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* CALRES calibrated voltages */
extern float32_t calres_signal_1_3;
extern float32_t calres_signal_2_4;

/* ---------- provided operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0010 */
/**
 * Function to initialize the calres data in shared memory,
 *   and the sensor types from the OSS_CONF table.
 */
void calres_init(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Periodic function to orchestrate the CALRES acquisitions, the computations,
 *   and the storage of either the results or the fault word in the shared memory.
 */
void calres_periodic(const boolean_t current_channel_is_a);


#endif /* CALRES_PUBLIC_H */
