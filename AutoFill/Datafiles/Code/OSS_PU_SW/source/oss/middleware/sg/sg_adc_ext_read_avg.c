/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquire Strain Gauge sensors value and calculate average
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc_over_spi/adc_over_spi_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/sg/sg_private.h"
#include "middleware/sg/sg_adc_ext_read_avg.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Acquire SGx / SAIx / P3x sensors from external ADC value and calculate average */
/* Implements REQ_FADEX_OS_SRD-SG-0010 */
float32_t sg_adc_ext_read_avg(ts_sg_sensor_info *p_sensor,
                              int8_t             p_source)
{
   float32_t* pv_source_data;
   float32_t  v_average;
   int16_t    v_index;


   /* Get right sample array */
   switch (p_sensor->s_input_id)
   {
      case e_p3a:
      case e_p3b:
         switch (p_source)
         {
            case C_SOURCE_SIGNAL:
               pv_source_data = p3_sig;
               break;

            case C_SOURCE_GROUND:
               pv_source_data = p3_gnd;
               break;

            case C_SOURCE_EXCITATION:
               pv_source_data = p3_exc;
               break;

            default:
               pv_source_data = NULL;
               break;
         }
         break;

      case e_sg1:
      case e_sg3:
      case e_sai1:
      case e_sai3:
         switch (p_source)
         {
            case C_SOURCE_SIGNAL:
               pv_source_data = sg1_sg3_sai1_sai3_sig;
               break;

            case C_SOURCE_GROUND:
               pv_source_data = sg1_sg3_sg4_sai1_sai3_gnd;
               break;

            case C_SOURCE_EXCITATION:
               pv_source_data = sg1_sg3_sg4_sai1_sai3_exc;
               break;

            default:
               pv_source_data = NULL;
               break;
         }
         break;

      case e_sg2:
      case e_sai2:
         switch (p_source)
         {
            case C_SOURCE_SIGNAL:
               pv_source_data = sg2_sai2_sig;
               break;

            case C_SOURCE_GROUND:
               pv_source_data = sg2_sg5b_sai2_sai4_gnd;
               break;

            case C_SOURCE_EXCITATION:
               pv_source_data = sg2_sg5b_sai2_sai4_exc;
               break;

            default:
               pv_source_data = NULL;
               break;
         }
         break;

      case e_sg4:
         switch (p_source)
         {
            case C_SOURCE_SIGNAL:
               pv_source_data = sg4_sig;
               break;

            case C_SOURCE_GROUND:
               pv_source_data = sg1_sg3_sg4_sai1_sai3_gnd;
               break;

            case C_SOURCE_EXCITATION:
               pv_source_data = sg1_sg3_sg4_sai1_sai3_exc;
               break;

            default:
               pv_source_data = NULL;
               break;
         }
         break;

      case e_sg5b:
      case e_sai4:
         switch (p_source)
         {
            case C_SOURCE_SIGNAL:
               pv_source_data = sg5_sai4_sig;
               break;

            case C_SOURCE_GROUND:
               pv_source_data = sg2_sg5b_sai2_sai4_gnd;
               break;

            case C_SOURCE_EXCITATION:
               pv_source_data = sg2_sg5b_sai2_sai4_exc;
               break;

            default:
               pv_source_data = NULL;
               break;
         }
         break;

      default:
         pv_source_data = NULL;
         break;
   }

   /* Unexpected case value */
   if (NULL == pv_source_data)
      return ((float32_t)0.0);

   /* Process*/
   v_average = (float32_t)0.0f;
   for (v_index = p_sensor->s_read_start; v_index < (p_sensor->s_read_start + p_sensor->s_read_count); v_index++)
      v_average += pv_source_data[v_index];

   return (v_average / (float32_t)p_sensor->s_read_count);
}

/* ---------- internal operations: ------------------------------------------ */
