/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Read and store locally one devices IO state
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pca9535e/pca9535e_public.h"
#include "driver/i2c/drv_I2C_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pca9535e/pca9535e_private.h"

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Read and store locally one devices IO state */
uint8_t pca9535e_write_one(uint8_t const      p_i2c_address,
                           te_pca9535e_device p_device_id,
                           uint8_t const      p_error_bit)
{
   uint8_t     v_result;
   tu_CMN_RC   v_i2c_cmd_err;
   tu_CMN_RC   v_i2c_chk_err;


   /* Init error report variable */
   v_result = (uint8_t)0;

   /* I2C0 write IO in IO Expanders at address p_i2c_address */
   drv_I2C_WRITE_WORD16(e_I2C_LINE_0,                                      /* I2C line     */
                        p_i2c_address,                                     /* I2C Address  */
                        C_PCA9535E_OUTPUT_REGISTER,                        /* I2C Register */
                        v_pca9535e_devices[p_device_id].s_io_state.u_word, /* I2C Message  */
                        &v_i2c_cmd_err);

   drv_I2C_BUSY_CHECK(e_I2C_LINE_0,
                      &v_i2c_chk_err);

   if ((uint32_t)0 != v_i2c_cmd_err.u_r || (uint32_t)0 != v_i2c_chk_err.u_r)
      v_result = p_error_bit;

   /* Update status word */
   if ((uint8_t)0 == v_result)
      v_pca9535e_devices[p_device_id].s_status.u_bit.s_i2c_wr_error = (uint8_t)C_PCA9535E_IO_UNSET;
   else
      v_pca9535e_devices[p_device_id].s_status.u_bit.s_i2c_wr_error = (uint8_t)C_PCA9535E_IO_SET;

   return v_result;
}

/* ---------- internal operations: ------------------------------------------ */
