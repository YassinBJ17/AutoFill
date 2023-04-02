/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pot/pot_private.h"
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
float32_t pot_ls_voltage_1_2_raw[POT_N_SAMPLES];

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Function to acquire the 12 measures of low-side voltage (which is the image
 *   of low-side current) via the ADC, on the appropriate pin,
 * by measuring either the signal POT1_2_EXC_MON or POT3_EXC_MON (the corres-
 *   ponding pin are respectively either the 78 or the 79 pin, and are indicated
 *   through the enum x_pot_to_read).
 * Then, compute and return the average of the 8 central values of voltage.
 */
float32_t pot_acquire_low_side_1_2_measure(void)
{
   uint16_t  i;
   float32_t result;
   int16_t pot_ls_int_1_2[POT_N_SAMPLES];

   /* Read 12 samples of the value */
   for (i = 0 ; i < POT_N_SAMPLES ; i++)
   {
      ADC_BUFFER_READ(e_CFEX_ADC_INT_AN78, (CMN_SYSTEM_ADDR_t)(&(pot_ls_int_1_2[i])) );
      pot_ls_voltage_1_2_raw[i] = ((float32_t) pot_ls_int_1_2[i]) * POT_LOW_SIDE_INT_TO_FLOAT;
   }
   /* Compute and return the mean of the central 8 values */
   result = pot_compute_mean_int(pot_ls_int_1_2);
   /* Even if the result seems to be in a float format,
    *   a gain is yet to be applied :
    *   the LSB value yelds for 1.22 mV, not 1 V. */
   result *= POT_LOW_SIDE_INT_TO_FLOAT;
   return result;
}


/* ---------- internal operations: ------------------------------------------ */
