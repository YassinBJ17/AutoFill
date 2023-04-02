/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_SHMEM_WRITE_MEASURE_H
#define NFREQ_SHMEM_WRITE_MEASURE_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Copy designated nFreq information to shared memory */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0010 */
extern void nfreq_shmem_write_measure(const boolean_t        p_channel_is_a,
                                      te_nfreq_sensor        p_sensor_id,
                                      ts_nfreq_sensor_info * p_sensor_info);


#endif /* NFREQ_SHMEM_WRITE_MEASURE_H */
