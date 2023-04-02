/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_COMPUTE_FREQUENCY_H
#define NFREQ_COMPUTE_FREQUENCY_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0030 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0090 */
extern float32_t nfreq_compute_frequency(ts_nfreq_sensor_info * p_sensor,
                                         te_nfreq_sensor        p_sensor_id);


#endif /* NFREQ_COMPUTE_FREQUENCY_H */
