/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Perform filter for voltage level fault word
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/powersup/powersup_private.h"
#include "middleware/powersup/powersup_public.h"
#include "middleware/pca9535e/pca9535e_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/oss_section_def_public.h"
#include "driver/adc/ADC_HAL_public.h"
#include "driver/i2c/drv_I2C_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Global fault error value */
/* XX XX  XXXX  => Value in HEX on 8 octet          */
/*  ^  ^     ^                                      */
/*  |  |     |---> NB of RTC in voltage level error */
/*  |  |                                            */
/*  |  |---------> Active low voltage level error   */
/*  |------------> Active high voltage level error  */
tu_powersup_err V_POWERSUP_ERROR_RTC;


/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Acquire 28V A/C measure and perform CBIT */
void powersup_monitor(
      /* INPUT */
      const uint16_t *    const p_voltage)
{
   /* */
   uint32_t             v_volt_delta;

   /* Initialize internal value */
   v_volt_delta  = ( (V_POWERSUP_ERROR_RTC.u_word & (uint32_t)0xFFFF0000) >> (uint32_t)16 )
                 + (V_POWERSUP_ERROR_RTC.u_word & (uint32_t)0x0000FFFF);

   /* Detection of voltage in range to restart counter */
   if( (*p_voltage <= HEX_VOLTAGE_MAX) &&
       (*p_voltage >= HEX_VOLTAGE_MIN) )
   {
      V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_ls_er = (uint32_t)0;
      V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_hs_er = (uint32_t)0;
   }

   /* Detection of high level of voltage for POWERSUP */
   if( (*p_voltage > HEX_VOLTAGE_MAX) &&
       (v_volt_delta < CONST_RTC_LIMIT) )
   {
      V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_hs_er++;
      V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_ls_er = (uint32_t)0;
   }

   /* Detection of low level of voltage for POWERSUP */
   if( (*p_voltage < HEX_VOLTAGE_MIN) &&
       (v_volt_delta < CONST_RTC_LIMIT) )
   {
      V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_ls_er++;
      V_POWERSUP_ERROR_RTC.u_bit.s_nb_rtc_hs_er = (uint32_t)0;
   }

   /* Convert voltage measurement in Volt */
   c_voltage_measure  = (float32_t)(*p_voltage) * ADC_CONVERT_VALUE * K_OFFSET_ADC_CONVERT_VALUE ;

   return;
}

/* ---------- internal operations: ------------------------------------------ */
