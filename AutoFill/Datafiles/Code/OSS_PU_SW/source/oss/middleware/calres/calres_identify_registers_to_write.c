/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_private.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
float32_t* p_calres_2_4_value; /* where to write the data for the sensor Calres_2 or Calres_4 */
float32_t* p_calres_1_3_value; /* where to write the data for the sensor Calres_1 or Calres_3 */
tu_calres_fault_word* p_calres_fault_word; /* where to write the fault word for both the Calres sensors. */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to find the registers corresponding to Calres_1 and Calres_2
 *   (on channel A), or to Calres_3 and Calres_4 (on channel B),
 *   to write the measures and the fault words in the appropriate places.
 */
void calres_identify_registers_to_write(const boolean_t current_channel_is_a)
{
   if (current_channel_is_a)
   {
      /* Channel A hosts Calres_2 (ADC1) and Calres_1 (ADC2). */
      p_calres_fault_word = &(shmem.s_calres_1_2.s_fault_word);
      /* Calres_2 is read by the ADC1 on the channel A (CPMB),
       *   kept into measure_2_4,
       *   and then written into the second measure slot of calres_1_2 */
      p_calres_2_4_value = &(shmem.s_calres_1_2.s_calres_measure2);
      /* Calres_1 is read by the ADC2 on on the channel A (CPMB),
       *   kept into measure_1_3,
       *   and then written into the  first measure slot of calres_1_2 */
      p_calres_1_3_value = &(shmem.s_calres_1_2.s_calres_measure1);
   }
   else /* current_channel_is_b */
   {
      /* Channel B hosts Calres_4 (ADC1) and Calres_3 (ADC2). */
      p_calres_fault_word = &(shmem.s_calres_3_4.s_fault_word);
      /* Calres_4 is read by the ADC1 on the channel B (CPB),
       *   kept into measure_2_4,
       *   and then written into the second measure slot of calres_3_4 */
      p_calres_2_4_value = &(shmem.s_calres_3_4.s_calres_measure2);
      /* Calres_3 is read by the ADC2 on the channel B (CPB),
       *   kept into measure_1_3,
       *   and then written into the  first measure slot of calres_3_4 */
      p_calres_1_3_value = &(shmem.s_calres_3_4.s_calres_measure1);
   }
}

/* ---------- internal operations: ------------------------------------------ */
