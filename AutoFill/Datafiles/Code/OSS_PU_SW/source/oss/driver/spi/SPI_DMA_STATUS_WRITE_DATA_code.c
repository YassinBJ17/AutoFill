/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */


/* ---------- include provided interface: ----------------------------------- */
#include "driver/spi/SPI_CFEX_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/dma/DMA_HAL_public.h"
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Used to received data */
void SPI_DMA_STATUS_WRITE_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                                 CMN_SYSTEM_SIZE_t * const p_write_size)
{
   /* Local variable definition */
   /* */

   /* Local DMA variable definition */
   CMN_IOSP_ID_t         v_spi_dma_conf_id;
   ts_DMA_STATUS         v_spi_dma_status;
   uint32_t              v_spi_dma_nb;

   /* */
   *p_write_size = 0ul;

   /* */
   v_spi_dma_conf_id = SPI_CFEX_descriptor_tab[p_spi_conf_id].s_dma_conf_tx_nb;

   /* */
   FDX_DMA_STATUS ( v_spi_dma_conf_id, &v_spi_dma_status );

   /* */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. Casting from (uint32_t)0 to (uint16_t)0. */
   if ( v_spi_dma_status.s_read_done != (uint16_t)0ul )
   {
      /* */
      /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (uint16_t) to (uint32_t). */
      v_spi_dma_nb = (uint32_t)v_spi_dma_status.s_cycle_nb;
   }
   else
   {
      /* */
      /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (uint16_t) to (uint32_t). */
      v_spi_dma_nb = (uint32_t)v_spi_dma_status.s_cycle_nb - (uint32_t)v_spi_dma_status.s_cycle_count;
   }

   /* */
   *p_write_size = v_spi_dma_nb * SPI_CFEX_DATA_SIZE;
}

/* ---------- internal operation bodies: ------------------------------------ */
