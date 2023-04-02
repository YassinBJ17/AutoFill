/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_SET_POWER_STATUS_H
#define NFREQ_SET_POWER_STATUS_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0100 */
extern void nfreq_set_power_status(const boolean_t        p_channel_is_a,
                                   te_nfreq_sensor        p_sensor_id,
                                   ts_nfreq_sensor_info * p_sensor_info);

#endif /*NFREQ_SET_POWER_STATUS_H */
