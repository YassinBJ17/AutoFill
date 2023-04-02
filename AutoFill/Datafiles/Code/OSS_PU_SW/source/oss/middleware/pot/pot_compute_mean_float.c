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

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Function to compute the average of the eight middle samples
 *   (already in float32_t).
 */
float32_t pot_compute_mean_float(const float32_t p_val[POT_N_SAMPLES])
{
   float32_t v_sum;
   v_sum  = p_val[4];
   v_sum += p_val[5];
   v_sum += p_val[6];
   v_sum += p_val[7];
   v_sum += p_val[8];
   v_sum += p_val[9];
   v_sum += p_val[10];
   v_sum += p_val[11];
   /** Compensation from a voltage diviser bridge,
     *   affecting any POT measure (but the low-side current).*/
   v_sum *= POT_DIVIDER_BRIDGE;
   v_sum /= 8.0f;
   return v_sum;
}
