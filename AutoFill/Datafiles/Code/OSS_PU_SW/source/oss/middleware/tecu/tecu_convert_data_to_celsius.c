/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU input acquisitions and status management function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
/* #include "tecu_private.h" */
#include "type/mcp_types.h"
#include "middleware/tecu/tecu_public.h"

/* ---------- internal define constants: ------------------------------------ */
/*
temperature value register 0x02
masque signe 0b1000 0000 0000 0000 = 0x8000
masque tlow  0x1
masque thigh 0x2
masque tcrit 0x4
masque data avec signe  0b1111 1111 1111 1000 = 0xFFF8
masque signe sur data extraite = 0x1000
*/
#define RAW_VALUE(data) ((data) >> 3)
#define RAW_VALUE_SIGN(raw)  ((raw & 0x1000) >> 12)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Conversion of the data acquired from the ADT7310 sensor to Celsius */
void tecu_convert_data_to_celsius(uint16_t* p_sensor_raw_temp,    /* in */
                                 float32_t* p_converted_temp)    /* out */
{

   /* Formula to apply for 13 bits temperature data format:
   - Positive Temperature = ADC Code(dec)/16
   - Negative Temperature = (ADC Code(dec) - 4096)/16
   where ADC Code uses all 13 bits of the data byte, including the sign bit */

   /* Local variables */
   uint16_t   raw_temperature;

   /* Shift TECU temperature data to keep temperature (ignore flags for temperature conversion for 13 bits) */
   raw_temperature = RAW_VALUE(*p_sensor_raw_temp);

   /* If the data is negative */
   if (1 == RAW_VALUE_SIGN(raw_temperature))
   {
      /* Convert the data acquired from the ADT7310 sensor */
      *p_converted_temp = ((float32_t) (raw_temperature) - (float32_t )8192) / ((float32_t)16);
   }
   else
   {
      /* Convert the data acquired from the ADT7310 sensor */
      *p_converted_temp = ((float32_t) (raw_temperature)) / ((float32_t)16);
   }
   return;

}

/* ---------- internal operations: ------------------------------------------ */
