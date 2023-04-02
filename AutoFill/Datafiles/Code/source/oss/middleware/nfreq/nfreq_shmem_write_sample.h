/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_SHMEM_WRITE_SAMPLE_H
#define NFREQ_SHMEM_WRITE_SAMPLE_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
extern void nfreq_shmem_write_sample(ts_nfreq_sensor_info * p_sensor_info,
                                     te_nfreq_sensor        p_sensor_id,
                                     float32_t            * p_dest,
                                     float32_t            * p_dest_pn,
                                     uint32_t             * p_dest_count);


#endif /* NFREQ_SHMEM_WRITE_SAMPLE_H */
