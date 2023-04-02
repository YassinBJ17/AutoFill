/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pot/pot_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */


/* ---------- internal operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Function to compute the average of the eight middle 12-bit samples,
 *   returned as a float.
 */
float32_t pot_compute_mean_int(const int16_t p_val[POT_N_SAMPLES])
{
   int32_t v_sum = 0;
   v_sum += (int32_t) p_val[4];
   v_sum += (int32_t) p_val[5];
   v_sum += (int32_t) p_val[6];
   v_sum += (int32_t) p_val[7];
   v_sum += (int32_t) p_val[8];
   v_sum += (int32_t) p_val[9];
   v_sum += (int32_t) p_val[10];
   v_sum += (int32_t) p_val[11];
   return (((float32_t) v_sum) / 8.0f);
}
