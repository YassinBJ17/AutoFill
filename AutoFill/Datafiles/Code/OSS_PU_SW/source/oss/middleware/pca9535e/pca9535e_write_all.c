/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Write to all devices locally stored IO state
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pca9535e/pca9535e_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pca9535e/pca9535e_private.h"

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Write to all devices locally stored IO state */
uint8_t pca9535e_write_all(void)
{
   uint8_t v_result;


   /* Init error report variable */
   v_result = (uint8_t)0;

   /*==================*/
   /* IO Expander 0x42 */
   if ((uint8_t)0 == v_pca9535e_devices[e_device_42].s_status.u_bit.s_i2c_rd_error)
   {
      v_result |= pca9535e_write_one(C_I2C_ADDRESS_42,
                                     e_device_42,
                                     C_PCA9535E_ERROR_DEVICE_42);
   }

   /*==================*/
   /* IO Expander 0x44 */
   if ((uint8_t)0 == v_pca9535e_devices[e_device_44].s_status.u_bit.s_i2c_rd_error)
   {
      v_result |= pca9535e_write_one(C_I2C_ADDRESS_44,
                                     e_device_44,
                                     C_PCA9535E_ERROR_DEVICE_44);
   }

   /*==================*/
   /* IO Expander 0x48 */
   if ((uint8_t)0 == v_pca9535e_devices[e_device_48].s_status.u_bit.s_i2c_rd_error)
   {
      v_result |= pca9535e_write_one(C_I2C_ADDRESS_48,
                                     e_device_48,
                                     C_PCA9535E_ERROR_DEVICE_48);
   }

   /*==================*/
   /* IO Expander 0x4A */
   if ((uint8_t)0 == v_pca9535e_devices[e_device_4A].s_status.u_bit.s_i2c_rd_error)
   {
      v_result |= pca9535e_write_one(C_I2C_ADDRESS_4A,
                                     e_device_4A,
                                     C_PCA9535E_ERROR_DEVICE_4A);
   }

   /*==================*/
   /* IO Expander 0x4A */
   if ((uint8_t)0 == v_pca9535e_devices[e_device_4C].s_status.u_bit.s_i2c_rd_error)
   {
      v_result |= pca9535e_write_one(C_I2C_ADDRESS_4C,
                                     e_device_4C,
                                     C_PCA9535E_ERROR_DEVICE_4C);
   }

   return v_result;
}

/* ---------- internal operations: ------------------------------------------ */
