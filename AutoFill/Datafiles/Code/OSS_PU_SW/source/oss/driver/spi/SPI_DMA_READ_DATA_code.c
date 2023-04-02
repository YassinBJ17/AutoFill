/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */


/* ---------- include provided interface: ----------------------------------- */
/*  */
#include "driver/spi/SPI_CFEX_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/spi/SPI_HAL_public.h"
#include "driver/dma/DMA_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Used to received data */
void SPI_DMA_READ_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                         CMN_SYSTEM_ADDR_t   const p_buff_addr,
                         CMN_SYSTEM_SIZE_t   const p_buff_size,
                         CMN_SYSTEM_SIZE_t * const p_read_size)
{
   /* Local variable definition */
   uint32_t       v_spi_buff_data_nb;
   uint32_t       v_spi_data_nb;
   uint32_t *     pt_spi_read;
   uint32_t       v_spi_src_addr;

   /* Local DMA variable definition */
   CMN_IOSP_ID_t          v_spi_dma_conf_id;
   ts_DMA_STATUS          v_spi_dma_status;
   ts_DMA_PROG            v_spi_dma_prog;

   /* */
   *p_read_size = 0ul;

   /* */
   v_spi_buff_data_nb = (p_buff_size / SPI_CFEX_DATA_SIZE);

   /* */
   v_spi_dma_conf_id = SPI_CFEX_descriptor_tab[p_spi_conf_id].s_dma_conf_rx_nb;

   /* */
   if ( v_spi_buff_data_nb > 0ul )
   {
      /* */
      FDX_DMA_REQUEST ( v_spi_dma_conf_id, e_CMN_FLAG_NOT_ACTIVATE);
      /* */
      FDX_DMA_STATUS ( v_spi_dma_conf_id, &v_spi_dma_status );

      /* */
      /* >RELAX<SYNCHRONe_C_Code_10.7> (uint32_t)0 to (uint16_t)0 is a safe cast. */
      if ( v_spi_dma_status.s_read_done != (uint16_t)0ul )
      {
         /* */
         /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (uint16_t) to (uint32_t). */
         v_spi_data_nb = (uint32_t)v_spi_dma_status.s_cycle_nb;
      }
      else
      {
         /* */
         /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. There is no loss of precision from (uint16_t) to (uint32_t). */
         v_spi_data_nb = (uint32_t)v_spi_dma_status.s_cycle_nb - (uint32_t)v_spi_dma_status.s_cycle_count;
      }

      /* */
      *p_read_size = v_spi_data_nb * SPI_CFEX_DATA_SIZE;
      /* */
      /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast is safe. There is no loss of precision from (void*) to (uint32_t*). */
      pt_spi_read = (uint32_t *)p_buff_addr;
      /* */
      v_spi_src_addr = SPI_CFEX_descriptor_tab[p_spi_conf_id].s_address + SPI_REG_RX_OFFSET + SPI_CFEX_CMD_SIZE;

      /* Transfer 16 bit (16 bit of data ONLY) */
      v_spi_dma_prog.s_nb_byte_req    = e_DMA_REQUEST_16_BIT;
      v_spi_dma_prog.s_src_addr       = v_spi_src_addr;
      v_spi_dma_prog.s_src_last_addr  = v_spi_src_addr;
      /* >RELAX<SYNCHRONe_C_Code_10.7> (uint32_t)0 to (uint16_t)0 is a safe cast. */
      v_spi_dma_prog.s_src_off        = (uint16_t)0ul;
      /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast from (uint32_t *) to (uint32_t) is used to retrieve the value of the address itself. */
      v_spi_dma_prog.s_dest_addr      = (uint32_t)pt_spi_read;
      v_spi_dma_prog.s_dest_last_addr = (uint32_t)pt_spi_read + (uint32_t)p_buff_size;
      /* }}<SYNCHRONe_C_Code_10.7,11.1> */
      v_spi_dma_prog.s_dest_off       = (uint16_t)SPI_CFEX_DATA_SIZE;
      v_spi_dma_prog.s_nb_cycle       = ( (uint16_t)p_buff_size / (uint16_t)SPI_CFEX_DATA_SIZE);
      v_spi_dma_prog.s_buff_type      = e_DMA_BUFFER_ONE_SHOT; /* One shot by default */

      /* */
      FDX_DMA_CFG ( v_spi_dma_conf_id, &v_spi_dma_prog);
      /* */
      FDX_DMA_REQUEST ( v_spi_dma_conf_id, e_CMN_FLAG_ACTIVATE);
   }
   /* else             */
   /* data number is 0 */
}

/* ---------- internal operation bodies: ------------------------------------ */
