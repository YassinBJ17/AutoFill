/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pot/pot_private.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 * Find the register corresponding to either Pot_1 or Pot_2,
 *   where the measure is to be written.
 */
ts_pot* pot_identify_register_1_2_to_write(const boolean_t current_channel_is_a)
{
   if (current_channel_is_a)
   {
      if (POT_K_POTENTIOMETER == pot_conf_pot1_sensor_type)
      {
         return (ts_pot*) &(shmem.s_pot1);
      }
      else /* POT_K_DIFFERENTIAL == pot_conf_pot1_sensor_type */
      {
         /* This cast is safe, since both structures have the same size. */
         return (ts_pot*) &(shmem.s_potdiff1);
      }
   }
   else /* current_channel_is_b */
   {
      if (POT_K_POTENTIOMETER == pot_conf_pot2_sensor_type)
      {
         return (ts_pot*) &(shmem.s_pot2);
      }
      else /* POT_K_DIFFERENTIAL == pot_conf_pot2_sensor_type */
      {
         /* This cast is safe, since both structures have the same size. */
         return (ts_pot*) &(shmem.s_potdiff2);
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
