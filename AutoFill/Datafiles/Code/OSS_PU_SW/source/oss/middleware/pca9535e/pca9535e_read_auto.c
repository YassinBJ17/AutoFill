/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Read and store automatically same device written by write_auto()
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/rtc/rtc_public.h"
#include "middleware/pca9535e/pca9535e_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pca9535e/pca9535e_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Read and store automatically same device written by write_auto() */
uint8_t pca9535e_read_auto(void)
{
   uint8_t  v_result;

   /* Init error report variable */
   v_result = (uint8_t)0;

   /* Process one read only */
   switch (rtc_counter % (uint32_t)e_device_max)
   {
      case e_device_42:
         v_result = pca9535e_read_one(C_I2C_ADDRESS_42,
                                      e_device_42,
                                      C_PCA9535E_ERROR_DEVICE_42);
         break;

      case e_device_44:
         v_result = pca9535e_read_one(C_I2C_ADDRESS_44,
                                      e_device_44,
                                      C_PCA9535E_ERROR_DEVICE_44);
         break;

      case e_device_48:
         v_result = pca9535e_read_one(C_I2C_ADDRESS_48,
                                      e_device_48,
                                      C_PCA9535E_ERROR_DEVICE_48);
         break;

      case e_device_4A:
         v_result = pca9535e_read_one(C_I2C_ADDRESS_4A,
                                      e_device_4A,
                                      C_PCA9535E_ERROR_DEVICE_4A);
         break;

      case e_device_4C:
         v_result = pca9535e_read_one(C_I2C_ADDRESS_4C,
                                      e_device_4C,
                                      C_PCA9535E_ERROR_DEVICE_4C);
         break;

      default:
         /* Avoid warning */
         break;
   }

   return v_result;
}

/* ---------- internal operations: ------------------------------------------ */
