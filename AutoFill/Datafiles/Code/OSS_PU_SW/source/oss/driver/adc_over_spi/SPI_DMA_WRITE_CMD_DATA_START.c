#include "driver/spi/SPI_CFEX_public.h"
#include "type/common_type.h"
#include "driver/dma/DMA_HAL_public.h"
#include "driver/spi/SPI_REG_common.h"
#include "driver/spi/SPI_HAL_public.h"

 void SPI_DMA_WRITE_CMD_DATA_START( CMN_IOSP_ID_t    const spi_conf_id) {    CMN_IOSP_ID_t       spi_dma_conf_id;    spi_dma_conf_id = SPI_CFEX_descriptor_tab[spi_conf_id].s_dma_conf_tx_nb;    FDX_DMA_REQUEST (spi_dma_conf_id,                 e_CMN_FLAG_ACTIVATE); }
