/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : T4 initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/t4/t4_public.h"
#include "middleware/t4/t4_private.h"
#include "driver/i2c/drv_I2C_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* To store TCJ so it can be use in the next rtc */
float32_t previous_tcj_value;
/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* TEMPORARY PATCH FOR I2C 1 DRIVER : WAITING FOR BOOT REVISION / TO BE REMOVED*/
/* Registers for I2C driver */
#define SIUL2_MSCR_IO_237_REG (uint32_t *)0xFFFC05F4
#define SIUL2_MSCR_IO_239_REG (uint32_t *)0xFFFC05FC
#define SIUL2_MSCR_MUX_810    (uint32_t *)0xFFFC0EE8
#define SIUL2_MSCR_MUX_811    (uint32_t *)0xFFFC0EEC

/* Keys for accomodation */
#define I2C_1_SERIAL_CLOCK       (uint32_t)0x32190004
#define I2C_1_SERIAL_DATA        (uint32_t)0x31190001
#define I2C_1_MUX_VALUE          (uint32_t)0x00000002
/* TEMPORARY PATCH FOR I2C DRIVER : WAITING FOR BOOT REVISION / TO BE REMOVED*/

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-T4-0010 */
/* Implements REQ_FADEX_OS_SRD-T4-0030 */
/* T4 initialization function */
void t4_init(void)
{
   /* TEMPORARY PATCH TO AVOID UNREADABLE I2C REQUEST IN INITIALIZATION AND TASK */
   /* TODO - TO REMOVE */

   /* Key registers settings  */
   uint32_t * siul2_mscr_io_237_reg = SIUL2_MSCR_IO_237_REG;
   uint32_t * siul2_mscr_io_239_reg = SIUL2_MSCR_IO_239_REG;
   uint32_t * siul2_mscr_mux_810_reg = SIUL2_MSCR_MUX_810;
   uint32_t * siul2_mscr_mux_811_reg = SIUL2_MSCR_MUX_811;

   /* Write key values */
   *siul2_mscr_mux_810_reg = I2C_1_MUX_VALUE;
   *siul2_mscr_mux_811_reg = I2C_1_MUX_VALUE;
   *siul2_mscr_io_237_reg = I2C_1_SERIAL_CLOCK;
   *siul2_mscr_io_239_reg = I2C_1_SERIAL_DATA;


   /* TEMPORARY PATCH TO AVOID UNREADABLE I2C REQUEST IN INITIALIZATION AND TASK */
   /* TODO - TO REMOVE */

   /* Initialization of previous tcj value */
   previous_tcj_value = (float32_t)0.0;

   /* Initialization of I2C1 */
   drv_I2C_INIT (e_I2C_LINE_1, 0x5B);

}

/* ---------- internal operations: ------------------------------------------ */
