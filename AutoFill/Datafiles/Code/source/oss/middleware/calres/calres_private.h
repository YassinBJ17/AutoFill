/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CALRES_PRIVATE_H
#define CALRES_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

#define CALRES_N_SAMPLES    ((uint8_t) 16u)

/* Calres modes */
#define CALRES_MODE         ((boolean_t) 1)
#define CALRES_ACTIVATE     ((boolean_t) 0)
#define CALRES_DEACTIVATE   ((boolean_t) 1)

/* Calres Gains, constants and Reference voltages : */
#define CALRES_REF          ((float32_t)   2.500f) /* Ideal reference voltage, in V */

#define CALRES_A1           ((float32_t) 1.782E10f) /* Constant, in Ohm^2 */
#define CALRES_A2           ((float32_t) 4.160E6f)  /* Constant, in Ohm*Volt */
#define CALRES_A3           ((float32_t) 4.473E5f)  /* Constant, in Ohm */

#define CALRES_GAIN_SIGNAL  ((float32_t) 1.220852E-3f)  /* Signal gain, in Volt */
#define CALRES_GAIN_REF     ((float32_t) 1.220852E-3f)  /* REF gain, in Volt */
#define CALRES_GAIN_GND     ((float32_t)  6.10501E-4f)  /* GND gain, in Volt */

#define CALRES_PIB_COMPENSATION ((float32_t)  0.047f) /* Value of the PIB impedance to compensate, in kOhm */

#define CALRES_OHM_TO_KOHM  ((float32_t)  1.0E-3f)  /* Resistance conversion factor from Ohm to kOhm */

/* Ranges checks for failure detection capability: */
/* TODO VERIFY IF WE NEED REF CHECKS !!!*/
/*#define CALRES_EXPECTED_REF_RANGE_MIN     ((float32_t)  9.075f) -> Minimum Ref expected voltage, in V */
/*#define CALRES_EXPECTED_REF_RANGE_MAX     ((float32_t)  9.275f) -> Maximum Ref expected voltage, in V */
/* TODO VERIFY IF WE NEED REF CHECKS !!!*/

#define CALRES_EXPECTED_GROUND_RANGE_MIN  ((float32_t)  -0.050f) /* Minimum Ground expected voltage, in V */
#define CALRES_EXPECTED_GROUND_RANGE_MAX  ((float32_t)   0.050f) /* Maximum Ground expected voltage, in V */

#define CALRES_EXPECTED_VOLTAGE_RANGE_MIN ((float32_t)   0.070f) /* Minimum signal expected voltage, in V */
#define CALRES_EXPECTED_VOLTAGE_RANGE_MAX ((float32_t)   2.200f) /* Maximum signal expected voltage, in V */

#define CALRES_EXPECTED_RESIST_RANGE_MIN  ((float32_t)   0.050f) /* Minimum expected resistance value, in KiloOhm */
#define CALRES_EXPECTED_RESIST_RANGE_MAX  ((float32_t)  10.950f) /* Maximum expected resistance value, in KiloOhm */



/* ---------- provided types: ----------------------------------------------- */

/* Data measured from a Calres sensor */
typedef struct
{
   float32_t v_signal;  /* Signal voltage, in V. */
   float32_t v_ref;     /* Reference voltage, in V. */
   float32_t v_gnd;     /* Ground voltage, in V. */
   float32_t r_measure; /* Calibrated resistance value, in Ohm. */
} ts_calres_measures;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
extern boolean_t  is_calres_sensor_enabled; /* Whether the calres sensors (or the XRB sensor) are in use, according to the OSS_CONF table. */
extern float32_t* p_calres_2_4_value;    /* where to write the data for the sensor Calres_2 or Calres_4 */
extern float32_t* p_calres_1_3_value;    /* where to write the data for the sensor Calres_1 or Calres_3 */
extern tu_calres_fault_word* p_calres_fault_word; /* where to write the fault word for both the Calres sensors. */


/* ---------- provided operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Perform range checks on the acquired Calres signals.
 */
tu_calres_fault_word calres_check_all_samples(
                                     const ts_calres_measures* const measures);

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Perform a minimal set of range checks on the acquired Calres signals,
 *   So that the compensation can be done with knowledge of the OC faults.
 */
boolean_t calres_check_before_compensation(
                                   const ts_calres_measures * const s_measures);

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to perform relevant checks on all signals range :
 *   - If a signal is out of range, its last valid value is kept,
 *      and the fault word is written accordingly;
 *   - Otherwise, the signal is updated in shared memory.
 */
void calres_checks_handler(tu_calres_fault_word* const p_calres_fault_word,
                           const boolean_t             current_channel_is_a,
                           float32_t * const           p_calres_2_4_value,
                           ts_calres_measures * const  p_calres_measures_2_4,
                           float32_t * const           p_calres_1_3_value,
                           ts_calres_measures * const  p_calres_measures_1_3);

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/** Calibrate the measured voltage, using the GND and REF values ;
 *    then convert it into a resistance value,
 *    using the already calculated constants. */
void calres_compute_calibrated_resistance(ts_calres_measures * const p_measures);

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to compute the mean of the eight middle samples
 *   (already in float32_t).
 */
float32_t calres_compute_mean_float(const float32_t val[CALRES_N_SAMPLES]);

/* Implements REQ_FADEX_OS_SRD-CALRES-0010 */
/**
 * Function to initialize GPIO inputs/outputs.
 */
void calres_gpio_init(const boolean_t is_calres_sensor_enabled,
                      const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to find the registers corresponding to Calres_1 and Calres_2
 *   (on channel A), or to Calres_3 and Calres_4 (on channel B),
 *   to write the measures and the fault words in the appropriate places.
 */
void calres_identify_registers_to_write(const boolean_t current_channel_is_a);


/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to merge two fault words' data, into their respective place.
 */
tu_calres_fault_word calres_merge_fault_words(
                            const tu_calres_fault_word* const p_fault_word_2_4,
                            const tu_calres_fault_word* const p_fault_word_1_3);

#endif /* CALRES_PRIVATE_H */
