/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef POT_PRIVATE_H
#define POT_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pot/pot_public.h"
#include "type/common_type.h"
#include "memory/shared_memory_public.h"
#include "driver/adc/ADC_CFEX_common.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

#define POT_N_SAMPLES           ((uint8_t) 12) /* Number of samples acquired for each signal. */

/* Potentiometer types */
#define POT_K_POTENTIOMETER ((boolean_t) 0) /* The sensor is of potentiometer type, according to OSS_CONF table */
#define POT_K_DIFFERENTIAL  ((boolean_t) 1) /* The sensor is of  differential type, according to OSS_CONF table */

/* Analog constants and gains to apply on measures */
#define POT_REF            ((float32_t) 9.175f) /* Ideal reference voltage, in V */
#define POT_DIVIDER_BRIDGE ((float32_t) 4.160f) /* Gain to compensate the ADC divider bridge, applied on all signals.*/
#define POT_EXC_CONST      ((float32_t) 2.0f)   /* Gain to apply on Excitation signal*/
#define POT_LOW_SIDE_VOLTAGE_TO_CURRENT ((float32_t) 3.31785E-3f) /* Conversion gain to apply on Low-side signal */
#define POT_LOW_SIDE_INT_TO_FLOAT       ((float32_t) 0.00122f)    /* Conversion gain to apply on Low-side signal */

/* Ranges checks for failure detection capability: */

/* Ranges checks on common voltages */
#define POT_REF_EXPECTED_RANGE_MIN ((float32_t)  8.850f) /* Minimum Ref expected voltage, in V */
#define POT_REF_EXPECTED_RANGE_MAX ((float32_t)  9.275f) /* Maximum Ref expected voltage, in V */

#define POT_GROUND_EXPECTED_RANGE_MIN ((float32_t) -0.050f) /* Minimum Ground expected voltage, in V */
#define POT_GROUND_EXPECTED_RANGE_MAX ((float32_t)  0.050f) /* Maximum Ground expected voltage, in V */


/* Range checks on POTENTIOMETER measures */
#define POT_SIGNAL_EXPECTED_RANGE_MIN ((float32_t)  0.120f) /* Minimum signal expected voltage, in V */
#define POT_SIGNAL_EXPECTED_RANGE_MAX ((float32_t)  9.950f) /* Maximum signal expected voltage, in V */

#define POT_EXC_EXPECTED_RANGE_MIN ((float32_t)  9.300f) /* Minimum Exc. expected voltage, in V */
#define POT_EXC_EXPECTED_RANGE_MAX ((float32_t) 10.700f) /* Maximum Exc. expected voltage, in V */

#define POT_LOW_SIDE_EXPECTED_RANGE_MIN ((float32_t) 3.0E-3f) /* Minimum low side expected current, in A */
#define POT_LOW_SIDE_EXPECTED_RANGE_MAX ((float32_t) 8.0E-3f) /* Maximum low side expected current, in A */

#define POT_MEASURE_EXPECTED_FRACTION_RANGE_MIN ((float32_t)  0.017f) /* Minimum expected measure voltage, in V */
#define POT_MEASURE_EXPECTED_FRACTION_RANGE_MAX ((float32_t)  0.983f) /* Maximum expected measure voltage, in V */


/* Range checks on DIFFERENTIAL measures */
#define POT_DIFF_OPEN_CIRCUIT ((float32_t) -0.500f) /* Maximum expected voltage under open-circuit conditions, in V */

#define POT_DIFF_MEASURE_EXPECTED_RANGE_MIN ((float32_t) -0.130f) /* Minimum measure expected voltage, in V */
#define POT_DIFF_MEASURE_EXPECTED_RANGE_MAX ((float32_t)  5.630f) /* Maximum measure expected voltage, in V */



/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/** Type of sensor for Pot_1, according to the OSS_CONF table. */
extern uint32_t pot_conf_pot1_sensor_type;
/** Type of sensor for Pot_2, according to the OSS_CONF table. */
extern uint32_t pot_conf_pot2_sensor_type;
/** Whether the local sensor is of type POTENTIOMETER or DIFFERENTIAL */
extern boolean_t is_sensor_type_diff;
/** Pointer to the appropriate (either Pot_1, Pot_2, Potdiff_1 or Potdiff_2)
 *    register in shared memory */
extern ts_pot* p_1_2_register;
/* Pointer to the Pot_3 register in shared memory */
extern ts_pot* p_3_register;

/* TODO delete this when unused */
extern float32_t pot_ls_voltage_1_2_raw[POT_N_SAMPLES];
extern float32_t pot_ls_voltage_3_raw[POT_N_SAMPLES];


/* ---------- provided operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Get the ADC to measure the 12 measures of low-side, on the appropriate pin,
 *   by measuring either the signal POT1_2_EXC_MON or POT3_EXC_MON (the corres-
 *   ponding pin is respectively either the 78 or the 79 pin, and is indicated
 *   through the enum x_pot_to_read).
 * Then, compute and return the average of the 8 central values.
 */
float32_t pot_acquire_low_side_x_measure(const te_CFEX_ADC_INT_ANx_CONF_ID x_pot_to_read);

float32_t pot_acquire_low_side_1_2_measure(void);
float32_t pot_acquire_low_side_3_measure(void);

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 * Perform range checks on the acquired DIFFERENTIAL pot signals.
 */
tu_potdiff_fault_word pot_check_all_samples_diff(
                                        const ts_pot_measures * const measures);

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Perform range checks on the acquired POTENTIOMETERS signals.
 */
tu_pot_fault_word pot_check_all_samples_pot(
                                        const ts_pot_measures * const measures);

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 * Function to perform relevant checks on all signals range :
 *   - If a signal is out of range, its last valid value is kept,
 *      and the fault word is written accordingly;
 *   - Otherwise, the signal is updated in shared memory.
 */
void pot_checks_handler(ts_pot* const p_pot_register,
                        const ts_pot_measures * const measures);

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Function to compute the Excitation and Signal measures,
 *   according to the Reference and Ground signals,
 *   multiplying by the appropriate gain. */
void pot_compute_calibrated_measures(ts_pot_measures * const s_measure);

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Function to compute the average of the eight middle samples
 *   (already in float32_t).
 */
float32_t pot_compute_mean_float(const float32_t p_val[POT_N_SAMPLES]);

/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Function to compute the average of the eight middle 12-bit samples,
 *   returned as a float.
 */
float32_t pot_compute_mean_int(const int16_t p_val[POT_N_SAMPLES]);

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 * Find the register corresponding to either Pot_1 or Pot_2
 *   (and corresponding to either the DIFF or POT sensor type),
 *   where the measure is to be written.
 */
ts_pot* pot_identify_register_1_2_to_write(const boolean_t current_channel_is_a);

/**
 * Find the register corresponding to Pot_3, where the measure is to be written.
 */
ts_pot* pot_identify_register_3_to_write(void);

#endif /* POT_PRIVATE_H */
