/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "driver/spi/SPI_HAL_public.h"

/* TODO REMOVE WHEN _HOLD function has been understood*/
void SPI_DMA_WRITE_CMD_DATA_START( CMN_IOSP_ID_t    const spi_conf_id);
void SPI_DMA_WRITE_CMD_DATA_HOLD(CMN_IOSP_ID_t         const p_spi_conf_id,
                                 CMN_SYSTEM_ADDR_t     const p_buff_addr,
                                 CMN_SYSTEM_SIZE_t     const p_buff_size,
                                 CMN_SYSTEM_SIZE_t *   const p_written_size);
/* TODO REMOVE WHEN _HOLD function has been understood*/

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Used to transmit data */
void ADC_AD7327_MULTIPLE_WRITE_FRAME ( const uint32_t            adc_conf_id,
                                       const CMN_SYSTEM_ADDR_t   buff_addr,
                                       const uint32_t   buff_size,
                                       uint32_t * written_size_pt)
{
   SPI_DMA_WRITE_CMD_DATA(ADC_AD7327_CFEX_descriptor_tab[adc_conf_id].spi_conf_id,
                          buff_addr,
                          buff_size,
                          written_size_pt);
}

/* */
void ADC_AD7327_MULTIPLE_WRITE_FRAME_HOLD ( const uint32_t             adc_conf_id,
                                            const CMN_SYSTEM_ADDR_t buff_addr,
                                            const uint32_t buff_size,
                                            uint32_t * written_size_pt)
{
   /* Write SPI Line */
   SPI_DMA_WRITE_CMD_DATA_HOLD(ADC_AD7327_CFEX_descriptor_tab[adc_conf_id].spi_conf_id,
                               buff_addr,
                               buff_size,
                               written_size_pt);
}

/* */
void ADC_AD7327_MULTIPLE_WRITE_FRAME_START (const uint32_t adc_conf_id)
{
   /* Write SPI Line */
   SPI_DMA_WRITE_CMD_DATA_START(ADC_AD7327_CFEX_descriptor_tab[adc_conf_id].spi_conf_id);
}
/* ---------- internal operation bodies: ------------------------------------ */
