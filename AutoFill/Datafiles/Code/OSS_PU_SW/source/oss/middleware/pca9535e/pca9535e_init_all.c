/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Initialize PCA9535 common interface
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pca9535e/pca9535e_public.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "driver/i2c/drv_I2C_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pca9535e/pca9535e_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Array of all to access all IO of alll PCA9535 */
ts_pca9535a_device v_pca9535e_devices[e_device_max];

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialize PCA9535 common interface */

void pca9535e_init_all(void)
{

   tu_CMN_RC v_i2c_write_err_42;
   tu_CMN_RC v_i2c_write_err_44;
   tu_CMN_RC v_i2c_write_err_48;
   tu_CMN_RC v_i2c_write_err_4A;
   tu_CMN_RC v_i2c_write_err_4C;
   tu_CMN_RC v_i2c_busy_err;

   /*=====================*/
   /* Devices array setup */
   LIB_MEM_SET((void *)v_pca9535e_devices,
               (int8_t)0,
               (uint32_t)sizeof (v_pca9535e_devices));

   /* Initialize I2C0 */
   drv_I2C_INIT(e_I2C_LINE_0,
                I2C0_BAUD);

   drv_I2C_BUSY_CHECK(e_I2C_LINE_0,
                      &v_i2c_busy_err);

   /*==================*/
   /* I2C0 Configuration IO Expanders at address 0x42 (PIB A) */
   drv_I2C_WRITE_WORD16(e_I2C_LINE_0,                /* I2C line     */
                        C_I2C_ADDRESS_42,            /* I2C Address  */
                        C_PCA9535E_CONFIG_REGISTER,  /* I2C Register */
                        C_IOEXP_42_CONF,             /* I2C Message  */
                        &v_i2c_write_err_42);

   drv_I2C_BUSY_CHECK(e_I2C_LINE_0,
                      &v_i2c_busy_err);

   /*==================*/
   /* I2C0 Configuration IO Expanders at address 0x44 (PIB A) */
   drv_I2C_WRITE_WORD16(e_I2C_LINE_0,                /* I2C line     */
                        C_I2C_ADDRESS_44,            /* I2C Address  */
                        C_PCA9535E_CONFIG_REGISTER,  /* I2C Register */
                        C_IOEXP_44_CONF,             /* I2C Message  */
                        &v_i2c_write_err_44);

   drv_I2C_BUSY_CHECK(e_I2C_LINE_0,
                      &v_i2c_busy_err);

   /*==================*/
   /* I2C0 Configuration IO Expanders at address 0x48 (PIB A & PIB B) */
   drv_I2C_WRITE_WORD16(e_I2C_LINE_0,                /* I2C line     */
                        C_I2C_ADDRESS_48,            /* I2C Address  */
                        C_PCA9535E_CONFIG_REGISTER,  /* I2C Register */
                        C_IOEXP_48_CONF,             /* I2C Message  */
                        &v_i2c_write_err_48);

   drv_I2C_BUSY_CHECK(e_I2C_LINE_0,
                      &v_i2c_busy_err);

   /*==================*/
   /* I2C0 Configuration IO Expanders at address 0x4A (PIB B) */
   drv_I2C_WRITE_WORD16(e_I2C_LINE_0,                /* I2C line     */
                        C_I2C_ADDRESS_4A,            /* I2C Address  */
                        C_PCA9535E_CONFIG_REGISTER,  /* I2C Register */
                        C_IOEXP_4A_CONF,             /* I2C Message  */
                        &v_i2c_write_err_4A);

   drv_I2C_BUSY_CHECK(e_I2C_LINE_0,
                      &v_i2c_busy_err);

   /*==================*/
   /* I2C0 Configuration IO Expanders at address 0x4C (PIB B) */
   drv_I2C_WRITE_WORD16(e_I2C_LINE_0,                /* I2C line     */
                        C_I2C_ADDRESS_4C,            /* I2C Address  */
                        C_PCA9535E_CONFIG_REGISTER,  /* I2C Register */
                        C_IOEXP_4C_CONF,             /* I2C Message  */
                        &v_i2c_write_err_4C);

   drv_I2C_BUSY_CHECK(e_I2C_LINE_0,
                      &v_i2c_busy_err);
}

/* ---------- internal operations: ------------------------------------------ */
