/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef POT_PUBLIC_H
#define POT_PUBLIC_H

#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Structure to keep the measured data. */
typedef struct
{
   float32_t v_signal;
   float32_t v_measure;
   float32_t v_ref;
   float32_t v_gnd;
   float32_t v_exc;
   float32_t v_low_side;
   boolean_t is_sensor_type_diff;
}ts_pot_measures;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Signals to be measured */
extern ts_pot_measures s_measures_1_2;
extern ts_pot_measures s_measures_3;

/* ---------- provided operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 *  Initialize the pot data in shared memory,
 *   and the sensor types from the OSS_CONF table.
 */
void pot_init(const boolean_t current_channel_is_a);

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 *  Function to orchestrate signals' measurement, calculations and checks.
 */
void pot_periodic(const boolean_t current_channel_is_a);


#endif /* POT_PUBLIC_H */
