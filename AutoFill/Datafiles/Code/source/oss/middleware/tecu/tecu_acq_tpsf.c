/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquisition of the primary power supply temperature function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_private.h"
#include "middleware/tecu/tecu_public.h"
#include "driver/i2c/drv_I2C_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* The primary power supply temperature sensor address */
#define I2C1_TPSF_ADD (uint8_t)0b10010010

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Raw value retrieved from the sensor (TMP116) (TPSF) */
uint16_t tpsf_raw_temperature;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Acquisition of the primary power supply temperature */
extern void tecu_acq_tpsf(void) /* out */
{
   /* Error word when reading through I2C */
   tu_CMN_RC i2c1_tpsf_read_err;

   /* Error word when writing through I2C */
   tu_CMN_RC i2c1_tpsf_write_err;

   /* Error word when waiting through I2C */
   tu_CMN_RC i2c1_tpsf_wait_err;

   /* Raw value retrieved from the sensor (TMP116) */
   uint16_t local_tpsf_read;

   /* Use I2C driver to acquire the primary power supply temperature raw value (tpsf_read) in one 16bit word */
   drv_I2C_WRITE_CMD(e_I2C_LINE_1,I2C1_TPSF_ADD,(uint8_t)0x00,&i2c1_tpsf_write_err);

   /* Check the availability of the I2C driver */
   drv_I2C_BUSY_CHECK(e_I2C_LINE_1,&i2c1_tpsf_wait_err);

   /* Use I2C driver to acquire the primary power supply temperature raw value (TPSF_read) in one 16bit word */
   drv_I2C_READ_WORD16(e_I2C_LINE_1,I2C1_TPSF_ADD, &local_tpsf_read ,&i2c1_tpsf_read_err);

   /**** FOR IVV TEST ****/
   /* Set global tspf_read to the value of the local_tpsf_read */
   tpsf_raw_temperature = local_tpsf_read;

   /* Convertion of primary supply function temperature (tpsf) value */
   /* If primary power supply temperature raw value (TPSF_read) is positive -> TPSF_read in [0;32767] */
   if (local_tpsf_read < RAW_TPSF_LIMIT_VAL)
   {
      /* Converstion with 0.0078125 resolution, see BSIS table */
      tpsf = TMP116_CONV_TO_CELSIUS * (float32_t)local_tpsf_read;
   }
   /* Else TPSF_read is positive -> TPSF_read in [32768;65535] */
   else
   {
      /* Converstion with 0.0078125 resolution, see BSIS table */
      tpsf = (TMP116_CONV_TO_CELSIUS * (float32_t)local_tpsf_read) - TMP116_CONV_OFFSET;
   }
}

/* ---------- internal operations: ------------------------------------------ */
