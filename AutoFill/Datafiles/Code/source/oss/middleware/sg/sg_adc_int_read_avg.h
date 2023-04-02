/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SG_ADC_INT_READ_AVG_H
#define SG_ADC_INT_READ_AVG_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Acquire MON signal from internal ADC value and calculate average */
/* Implements REQ_FADEX_OS_SRD-SG-0010 */
extern float32_t sg_adc_int_read_avg(ts_sg_sensor_info *p_sensor);


#endif /* SG_ADC_INT_READ_AVG_H */
