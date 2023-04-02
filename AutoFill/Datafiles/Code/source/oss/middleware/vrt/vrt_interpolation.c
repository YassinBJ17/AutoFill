/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : VRT linear interpoliation function (conversion from Ohm to Degree)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/vrt/vrt_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* VRT linear interpoliation function (conversion from Ohm to Degree) */
void vrt_interpolation(uint32_t  const p_vrtx_oss_config,         /* in */
                      float32_t *      p_vrtx_cal_resistor,       /* in */
                      float32_t *      p_vrtx_deg_thermal_temp)   /* out */
{

   /* Coefficient for the linear interpolation */
   float32_t i;

   /* If we are in the PT1000 configuration */
   if((uint32_t)1 == p_vrtx_oss_config)
   {

      /* Compute the coefficiant for the linear interpolation */
      i = (*p_vrtx_cal_resistor - VRT_PT1000_RESISTOR_MIN)/VRT_PT1000_STEP;

      if((VRT_PT1000_RESISTOR_MIN + VRT_PT1000_STEP*(i+1.00)) <= 1000.00)
      {
         /* Compute the thermal temperature (in degC) according to the value of the calibrated resistor */
         *p_vrtx_deg_thermal_temp = (THERM_TEMP_MIN_PT1000 + i) +
         (*p_vrtx_cal_resistor - (VRT_PT1000_RESISTOR_MIN + (VRT_PT1000_STEP*i))) *
         (((THERM_TEMP_MIN_PT1000 + (i+1.00)) - (THERM_TEMP_MIN_PT1000 + i))/
         ((VRT_PT1000_RESISTOR_MIN + VRT_PT1000_STEP*i) - (VRT_PT1000_RESISTOR_MIN + VRT_PT1000_STEP*(i+1.00))));
      }
      /* if VRT_PT1000_RESISTOR_MIN + VRT_PT1000_STEP*(i+1) > 1000 */
      else
      {
         /* Compute the thermal temperature (in degC) according to the value of the calibrated resistor */
         *p_vrtx_deg_thermal_temp = (THERM_TEMP_NULL + (i-66.00)) +
         (*p_vrtx_cal_resistor - (VRT_PT1000_RESISTOR_MIN + (VRT_PT1000_STEP*i))) *
         (((THERM_TEMP_NULL + ((i+1.00)-66.00)) - (THERM_TEMP_NULL + (i-66.00)))/
         ((VRT_PT1000_RESISTOR_MIN + VRT_PT1000_STEP*i) - (VRT_PT1000_RESISTOR_MIN + VRT_PT1000_STEP*(i+1.00))));
      }

   }
   /* If we are in the PT100 configuration */
   else
   {
      /* Iteration of the interpolation table that corresponds to the calibrated resistor */
      i = (*p_vrtx_cal_resistor - VRT_PT100_RESISTOR_MIN)/VRT_PT100_STEP;

      /* if VRT_PT100_RESISTOR_MIN + VRT_PT100_STEP*(i+1) <= 100 */
      if((VRT_PT100_RESISTOR_MIN + VRT_PT100_STEP*(i+1.00)) <= 100.00)
      {
         /* Compute the thermal temperature (in degC) according to the value of the calibrated resistor */
         *p_vrtx_deg_thermal_temp = (THERM_TEMP_MIN_PT100 + i) +
         (*p_vrtx_cal_resistor - (VRT_PT100_RESISTOR_MIN + (VRT_PT100_STEP*i))) *
         (((THERM_TEMP_MIN_PT100 + (i+1.00)) - (THERM_TEMP_MIN_PT100 + i))/
         ((VRT_PT100_RESISTOR_MIN + VRT_PT100_STEP*i) - (VRT_PT100_RESISTOR_MIN + VRT_PT100_STEP*(i+1.00))));
      }
      /* if VRT_PT100_RESISTOR_MIN + VRT_PT100_STEP*(i+1) > 100 */
      else
      {
         /* Compute the thermal temperature (in degC) according to the value of the calibrated resistor */

         *p_vrtx_deg_thermal_temp = (THERM_TEMP_NULL + (i-85.00)) +
         (*p_vrtx_cal_resistor - (VRT_PT100_RESISTOR_MIN + (VRT_PT100_STEP*i))) *
         (((THERM_TEMP_NULL + ((i+1.00)-85.00)) - (THERM_TEMP_NULL + (i-85.00)))/
         ((VRT_PT100_RESISTOR_MIN + VRT_PT100_STEP*i) - (VRT_PT100_RESISTOR_MIN + VRT_PT100_STEP*(i+1.00))));
      }


   }

}

/* ---------- internal operations: ------------------------------------------ */
