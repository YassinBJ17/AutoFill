/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */


/* ---------- internal operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to compute the mean of the eight middle samples
 *   (already in float32_t).
 */
float32_t calres_compute_mean_float(const float32_t p_val[CALRES_N_SAMPLES])
{
   float32_t v_sum;
   v_sum  = p_val[ 2];
   v_sum += p_val[ 3];
   v_sum += p_val[ 4];
   v_sum += p_val[ 5];
   v_sum += p_val[ 6];
   v_sum += p_val[ 7];
   v_sum += p_val[ 8];
   v_sum += p_val[ 9];
   v_sum += p_val[10];
   v_sum += p_val[11];
   v_sum += p_val[12];
   v_sum += p_val[13];
   return v_sum / 12.0f;
}
