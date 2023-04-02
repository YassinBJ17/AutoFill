/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_PUBLIC_H
#define NFREQ_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Index of all known sensors */
typedef enum
{
   e_nfreq_2 = 0,
   e_nfreq_3,
   e_nfreq_4,
   e_ngalt,
   e_SensorMax
}
te_nfreq_sensor;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Index of first inconsistent period (with 1 the most recent sample) */
extern int32_t nfreq_inconsistent_index[e_SensorMax];

/* ---------- provided operations: ------------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0020 */
extern void nfreq_init(void);

/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0010 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0030 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0040 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0050 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0060 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0070 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0080 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0090 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0100 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0110 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0120 */
extern void nfreq_periodic(const boolean_t channel_is_a);


#endif /* NFREQ_PUBLIC_H */
