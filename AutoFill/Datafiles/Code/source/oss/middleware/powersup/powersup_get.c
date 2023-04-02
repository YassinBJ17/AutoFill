/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Read parameters from shmem and I2C
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

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Acquire 28V A/C measure and I2C power status  */
void powersup_get(
         /* INPUT */
         const boolean_t           channel_is_a,
         /* OUTPUT */
         tu_i2c0 *           const pu_i2c0,
         uint32_t*           const p_i2c0_err,
         uint16_t*           const p_voltage,
         float32_t*          const p_alt_freq_meas,
         te_powersup_rearm*  const p_rearm_mode)
{
   /* TODO - for testing the read and the write IO Expanders */
   /* Get I2C IO Expanders */

   /* Read in channel A or B - 0x48 */
   /* 1 - Transmit the write command for the register 0x00 */
   /* Use global data from PCA9535e to read values by expender on addr 0x48 (PIB A & B) */
   pu_i2c0->u_word = v_pca9535e_devices[e_device_48].s_io_state.u_word ;
   /* I2C read error from PCA9535e fonction */
   *p_i2c0_err     = (uint32_t)v_pca9535e_devices[e_device_48].s_status.u_bit.s_i2c_rd_error;

   /*Configure adc conversion */
   ADC_START((uint32_t)e_CFEX_ADC_INT_AN69);

   /* Acquire 28V A/C raw measure voltage on the line AN69 of the internal ADC (SARADC_B) */
   ADC_BUFFER_READ ((uint32_t)e_CFEX_ADC_INT_AN69, p_voltage);

   /* Get the alternator frequency */
   if(channel_is_a == TRUE )
   {
      *p_alt_freq_meas = shmem.s_ngalt_a.s_measure;
   }
   else
   {
      *p_alt_freq_meas = shmem.s_ngalt_b.s_measure;
   }

   /* Convert raw 28V A/C measure voltage with ADC convert gain with an offset correction value */
   /* TODO - TBD this offset correction */

   /* Acquire rearm command from share memory */
   if((uint32_t)1 == shmem.s_alt_rearm)
   {
      *p_rearm_mode = e_rearm_yes;
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
