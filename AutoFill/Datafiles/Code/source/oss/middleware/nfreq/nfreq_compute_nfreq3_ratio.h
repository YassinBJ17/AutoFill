/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_COMPUTE_NFREQ3_RATIO_H
#define NFREQ_COMPUTE_NFREQ3_RATIO_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0090 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0110 */
extern float32_t nfreq_compute_nfreq3_ratio(ts_nfreq_sensor_info * p_sensor,
                                            uint32_t               p_period_count);


#endif /* NFREQ_COMPUTE_NFREQ3_RATIO_H */
