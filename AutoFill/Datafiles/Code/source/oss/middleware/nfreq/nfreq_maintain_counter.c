/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_private.h"
#include "middleware/nfreq/nfreq_maintain_counter.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void nfreq_maintain_counter(ts_nfreq_sensor_info * p_sensor_info)
{
   if (p_sensor_info->s_maintain_counter > (uint32_t)0)
   {
      p_sensor_info->s_maintain_counter--;
   }
   else
   {
      p_sensor_info->s_measure_freq  = (float32_t)0.0;
      p_sensor_info->s_measure_ratio = (float32_t)0.0;

      p_sensor_info->s_status_word.u_bit.s_freq_time_out = C_SET;

      if ((uint32_t)0 == p_sensor_info->s_status_word.u_bit.s_freq_inconsistency)
         p_sensor_info->s_status_word.u_bit.s_unavailable = C_UNSET;
   }
}

/* ---------- internal operations: ------------------------------------------ */
