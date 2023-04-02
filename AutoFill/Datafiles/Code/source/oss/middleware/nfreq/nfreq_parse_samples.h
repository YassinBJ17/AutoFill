/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_PARSE_SAMPLES_H
#define NFREQ_PARSE_SAMPLES_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Parse samples according to provided conditions */
extern void nfreq_parse_samples(int32_t       * p_index,
                                uint32_t      * p_count,
                                boolean_t     * p_is_consistent,
                                uint32_t        p_max_count,
                                boolean_t       p_valid_consistency,
                                te_nfreq_sensor p_sensor_ndx,
                                ts_nfreq_data   p_rx_data[]);


#endif /* NFREQ_PARSE_SAMPLES_H */
