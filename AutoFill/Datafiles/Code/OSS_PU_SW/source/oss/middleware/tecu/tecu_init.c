/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "middleware/tecu/tecu_private.h"
#include "driver/i2c/drv_I2C_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/spi/SPI_HAL_public.h"
#include "driver/spi/SPI_CFEX_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
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


/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU_0020 */
/* TECU initialization function */
void tecu_init(void)
{

   /* Size of the written data to the ADT7310 registers */
   uint32_t written_size;

   /* Received data after the configuration of the ADT7310 (using to clear the Rx FIFO) */
   uint16_t read_data_cfg;

   uint32_t read_data_cfg_size;

   /* ADT7310 Configuration Command */
   uint16_t adt7310_cfg_cmd;

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

   /* Set the ADT7310 configuration command to the expected value */
   adt7310_cfg_cmd = TECU_SPI_CMD_TX_13B_CONT_CFG;

   /* Initialize the TECU computed temperature on the shared memory */
   shmem.s_tecua.s_measure = (float32_t)0;

   /* Intialization of the last valid weighted average temperature */
   last_valid_tecu_avg = (float32_t)0;

   /* Initializtion of the maximum computed TECU value */
   max_tecu = (float32_t)0;

   /* Initializtion of the time that indicates when the maximum TECU value is computed */
   max_tecu_time = (float32_t)0;

   /** Initialize the previous temperatures variables **/
   prev_taccom = (float32_t)0;
   prev_tcu1 = (float32_t)0;
   prev_tpsf = (float32_t)0;
   prev_tcu2 = (float32_t)0;
   prev_tohs = (float32_t)0;
   prev_tols = (float32_t)0;
   prev_tcj = (float32_t)0;


   /* Read calibrated temperatures for ADC_INT */
   TECU_tcsa = *((int16_t*)TCSA_ADDR);
   TECU_tcsb = *((int16_t*)TCSB_ADDR);

   /* Initialize internal and external temperature */
   int_ext_temp = (uint32_t)0;

   /* Initialization of I2C1 */
   drv_I2C_INIT (e_I2C_LINE_1,I2C_BAUD_RATE);

   /* Configure the ADT7310 to the 13bits continuous mode conversion */
   SPI_FIFO_WRITE_DATA(TECU_SPI_CONF_IDx,&adt7310_cfg_cmd,SPI_CFEX_DATA_SIZE,&written_size);

   /* Read the data to clear the SPI Rx FIFO */
   SPI_FIFO_READ_DATA(TECU_SPI_CONF_IDx,&read_data_cfg,SPI_CFEX_DATA_SIZE,&read_data_cfg_size);

}

/* ---------- internal operations: ------------------------------------------ */
