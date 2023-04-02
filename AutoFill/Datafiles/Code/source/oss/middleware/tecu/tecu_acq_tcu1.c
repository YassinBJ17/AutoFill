/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU input acquisitions and status management function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_private.h"
#include "middleware/tecu/tecu_public.h"
#include "driver/spi/SPI_HAL_public.h"
#include "driver/spi/SPI_CFEX_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* Command for temperature and ADT7310 ID acquisition */
const uint16_t c_SPI_0_TEMP_ACQ_COMMAND_tab[SPI_CFEX_SPI0_CS_NB*3u] =
{
      TECU_SPI_CMD_TX_ID_ACQ,      /* Get ADT7310 ID */

      TECU_SPI_CMD_TX_TEMP_ACQ,    /* Get the temperature value */

      TECU_SPI_CMD_TX_DUMMY

};

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Raw temperature value retrieved from the ADT7310 temperature register */
uint16_t tcu1_raw_temperature;

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Acquisition of the control unit temperature (tcu1) from the ADT7310  */
void tecu_acq_tcu1(uint16_t* p_sensor_id) /* out */
{

   /* Raw temperature value retrieved from the ADT7310 temperature register */
   uint16_t local_tcu1_raw_temperature;

   /* Size of the read data */
   uint32_t g_SPI_0_acq_data_size;

   /* Variables to store read values */
   uint16_t  g_SPI_0_acq_data[SPI_CFEX_SPI0_CS_NB*3];


   /* Request temperature to the sensor */
   SPI_FIFO_WRITE_DATA(TECU_SPI_CONF_IDx,&c_SPI_0_TEMP_ACQ_COMMAND_tab,SPI_CFEX_DATA_SIZE*3,&g_SPI_0_acq_data_size);

   /* Read temperature from Rx FIFO */
   SPI_FIFO_READ_DATA (TECU_SPI_CONF_IDx,&g_SPI_0_acq_data, SPI_CFEX_DATA_SIZE*3,&g_SPI_0_acq_data_size);

   /* Get the sensor ID through the SPI received frame */
   *p_sensor_id = (uint16_t)((g_SPI_0_acq_data[0] & 0xFF)>>3);

   /**** FOR IVV TEST ****/
   /* Set global tcu1_sensor ID variable to the local value of the tcu1 sensor ID */
   tcu1_sensor_id = *p_sensor_id;

   /* Get the TMP116 sensor ID */
   local_tcu1_raw_temperature = (uint16_t) (((g_SPI_0_acq_data[1] & 0xFF)<<8u)+((g_SPI_0_acq_data[2] & 0xFF00)>>8u));

   /**** FOR IVV TEST ****/
   /* Set the global raw tcu1 temperature to the local value of the tcu1 raw temperature */
   tcu1_raw_temperature = local_tcu1_raw_temperature;

   /* Convert the raw temperature to degC */
   tecu_convert_data_to_celsius(&local_tcu1_raw_temperature,&tcu1);
}

/* ---------- internal operations: ------------------------------------------ */
