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
#include "middleware/nfreq/nfreq_parse_samples.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Parse samples according to provided conditions */
void nfreq_parse_samples(int32_t       * p_index,
                         uint32_t      * p_count,
                         boolean_t     * p_is_consistent,
                         uint32_t        p_max_count,
                         boolean_t       p_valid_consistency,
                         te_nfreq_sensor p_sensor_ndx,
                         ts_nfreq_data   p_rx_data[])
{
   /* Reset sample count */
   *p_count = (uint32_t)0;

   /* Do not parse if no sample available */
   if (*p_index < (int32_t)0)
      return;

   /* Start parsing */
   *p_is_consistent =  (p_sensor_ndx != e_nfreq_3 && p_rx_data[*p_index].s_inconsistency_1 == C_UNSET)
                    || (p_sensor_ndx == e_nfreq_3 && p_rx_data[*p_index].s_inconsistency_2 == C_UNSET);

   while (*p_index >= (int32_t)0 &&  *p_count < p_max_count &&  *p_is_consistent == p_valid_consistency)
   {
      (*p_count)++;
      /* prepare next test */
      (*p_index)--;
      *p_is_consistent =  (p_sensor_ndx != e_nfreq_3 && p_rx_data[*p_index].s_inconsistency_1 == C_UNSET)
                       || (p_sensor_ndx == e_nfreq_3 && p_rx_data[*p_index].s_inconsistency_2 == C_UNSET);
   }
}

/* ---------- internal operations: ------------------------------------------ */
