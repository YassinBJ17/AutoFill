/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_fill_temp_stream_log function which allows to get a
 *               temperature stream log
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/mram/mram_public.h"
#include "middleware/rtc/rtc_public.h"
#include "middleware/tecu/tecu_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* Maximum temperature value */
#define TEMP_MAX          ((float32_t)256.0)       /* TBD */

/* Resolution of the temperature : Max temperature (256) * 2 / Max int16_t (32767) */
#define TEMP_RESOLUTION   ((float32_t)0.015625)

/* Shift for the 1st value in the temperature fields */
#define TEMP_SHIFT        ((uint32_t)16)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Create a temperature stream log */
void logbook_fill_temp_stream_log(ts_temp_stream_log * const p_temp_stream_log, const boolean_t p_channel_is_a)
{
   /* Temporary variable to store converted temperatures */
   uint16_t tmp_temp1;
   uint16_t tmp_temp2;

   /* TECU measure */
   float32_t tecu_measure;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      /* Get the TECU measure of channel A */
      tecu_measure = shmem.s_tecua.s_measure;
   }
   /* When the channel is B */
   else
   {
      /* Get the TECU measure of channel B */
      tecu_measure = shmem.s_tecub.s_measure;
   }

   p_temp_stream_log->s_mission_id = mram_oss_critical_data->s_mission_id;

   p_temp_stream_log->s_timestamp = rtc_counter;
   p_temp_stream_log->s_pwr_up_counter = power_up_counter;

   /* To put two float32_t in one uint32_t, we use a method which allow to save a float32_t in a uint16_t, */
   /* with a bit of precision loss. */
   /* To do that, we use the following formula (which inherits from fixed-point arithmetic) : */
   /* y = (x + max(x)) / resolution */
   /* With : - y the integer value on 16 bits */
   /*        - x the float value on 32 bits   */
   /*        - max(x) the maximal value of x  */
   /*        - resolution the precisien level */

   /* Filtered control unit temperature on bits 31 to 16 */
   tmp_temp1 = (uint16_t)((filt_tcu1 + TEMP_MAX) / TEMP_RESOLUTION);
   /* Filtered processing core die temperature on bits 15 to 00 */
   tmp_temp2 = (uint16_t)((filt_tcu2 + TEMP_MAX) / TEMP_RESOLUTION);
   p_temp_stream_log->s_t1t2 = ((uint32_t)tmp_temp1 << TEMP_SHIFT) | (uint32_t)tmp_temp2;

   /* Filtered accommodation temperature on bits 31 to 16 */
   tmp_temp1 = (uint16_t)((filt_taccom + TEMP_MAX) / TEMP_RESOLUTION);
   /* Filtered primary power supply temperature on bits 15 to 00 */
   tmp_temp2 = (uint16_t)((filt_tpsf   + TEMP_MAX) / TEMP_RESOLUTION);
   p_temp_stream_log->s_t3t4 = ((uint32_t)tmp_temp1 << TEMP_SHIFT) | (uint32_t)tmp_temp2;

   /* Filtered over speed high side temperature on bits 31 to 16 */
   tmp_temp1 = (uint16_t)((filt_tohs   + TEMP_MAX) / TEMP_RESOLUTION);
   /* Filtered over speed low side temperature on bits 15 to 00 */
   tmp_temp2 = (uint16_t)((filt_tols   + TEMP_MAX) / TEMP_RESOLUTION);
   p_temp_stream_log->s_t5t6 = ((uint32_t)tmp_temp1 << TEMP_SHIFT) | (uint32_t)tmp_temp2;

   /* Filtered cold junction temperature on bits 31 to 16 */
   tmp_temp1 = (uint16_t)((filt_tcj     + TEMP_MAX) / TEMP_RESOLUTION);
   /* Filtered engine control unit average temperature on bits 15 to 00 */
   tmp_temp2 = (uint16_t)((tecu_measure + TEMP_MAX) / TEMP_RESOLUTION);
   p_temp_stream_log->s_t7t8 = ((uint32_t)tmp_temp1 << TEMP_SHIFT) | (uint32_t)tmp_temp2;

   p_temp_stream_log->s_spare_1 = (uint32_t)0;
   p_temp_stream_log->s_spare_2 = (uint32_t)0;
   p_temp_stream_log->s_spare_3 = (uint32_t)0;
   p_temp_stream_log->s_spare_4 = (uint32_t)0;
}

/* ---------- internal operations: ------------------------------------------ */
