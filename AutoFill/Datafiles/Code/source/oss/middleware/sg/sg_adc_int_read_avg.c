/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquire monitor sensors value and calculate average
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/sg/sg_private.h"
#include "middleware/sg/sg_adc_int_read_avg.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
#define C_UNKNOWN_CHANNEL_ID  ((uint32_t)0xFFFFFFFF)

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Global variables holding internals ADC average value */
float32_t   sgp3_exc_mon;
float32_t   sg1_34_exc_mon;
float32_t   sg2_5b_exc_mon;

/* ---------- provided operation bodies: ------------------------------------ */
/* Acquire MON signal from internal ADC value and calculate average */
/* Implements REQ_FADEX_OS_SRD-SG-0010 */
float32_t sg_adc_int_read_avg(ts_sg_sensor_info *p_sensor)
{
   float32_t    * v_average;
   CMN_IOSP_ID_t  v_channel_id;
   uint16_t       v_value;
   int16_t        v_index;


   /* Get right ADC line id */
   switch (p_sensor->s_input_id)
   {
      case e_p3a:
      case e_p3b:
         v_channel_id = e_CFEX_ADC_INT_AN66;
         v_average    = &sgp3_exc_mon;
         break;

      case e_sg1:
      case e_sg3:
      case e_sg4:
      case e_sai1:
      case e_sai3:
         v_channel_id = e_CFEX_ADC_INT_AN67;
         v_average    = &sg1_34_exc_mon;
         break;

      case e_sg2:
      case e_sg5b:
      case e_sai2:
      case e_sai4:
         v_channel_id = e_CFEX_ADC_INT_AN74;
         v_average    = &sg2_5b_exc_mon;
         break;

      default:
         v_channel_id = C_UNKNOWN_CHANNEL_ID;
         v_average    = NULL;
         break;
   }

   /* Unexpected case value */
   if (C_UNKNOWN_CHANNEL_ID == v_channel_id)
      return ((float32_t)0.0);

   /* Process */
   *v_average = (float32_t)0.0f;
   for (v_index = (int16_t)0; v_index < p_sensor->s_mon_count; v_index++)
   {
      ADC_BUFFER_READ(v_channel_id, (CMN_SYSTEM_ADDR_t)&v_value);
      *v_average += (float32_t)v_value;
   }

   *v_average = (*v_average / (float32_t)p_sensor->s_mon_count);
   return *v_average;
}

/* ---------- internal operations: ------------------------------------------ */
