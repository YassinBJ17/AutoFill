/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SG_ADC_EXT_READ_AVG_H
#define SG_ADC_EXT_READ_AVG_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* ADC source to read */
#define C_SOURCE_SIGNAL      ((int8_t)'S')
#define C_SOURCE_GROUND      ((int8_t)'G')
#define C_SOURCE_EXCITATION  ((int8_t)'E')

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Acquire SGx / SAIx / P3x sensors from external ADC value and calculate average */
/* Implements REQ_FADEX_OS_SRD-SG-0010 */
extern float32_t sg_adc_ext_read_avg(ts_sg_sensor_info *p_sensor,
                                     int8_t             p_source);


#endif /* SG_ADC_EXT_READ_AVG_H */
