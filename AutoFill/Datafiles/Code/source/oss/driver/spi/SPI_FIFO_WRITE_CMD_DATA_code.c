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
#include "driver/spi/SPI_REG_common.h"
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Used to transmit data */
void SPI_FIFO_WRITE_CMD_DATA( CMN_IOSP_ID_t       const p_spi_conf_id,
                              CMN_SYSTEM_ADDR_t   const p_buff_addr,
                              CMN_SYSTEM_SIZE_t   const p_buff_size,
                              CMN_SYSTEM_SIZE_t * const p_written_size)
{
   /* Local variable declaration */
   ts_SPI_REG volatile * pt_spi_reg_descr;
   /* */
   uint32_t       v_i;
   uint32_t       v_data_nb;
   uint32_t *     pt_data_write;

   /* Local variable initialization */
   /* */

   /* Initialize the write size */
   *p_written_size = 0ul;

   /* Get the SPI register descriptor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_SPI_REG' is tailor-made for the registers starting at this address.  */
   pt_spi_reg_descr = (ts_SPI_REG volatile *)SPI_CFEX_descriptor_tab[p_spi_conf_id].s_address;

   /* Compute number of data */
   v_data_nb = (p_buff_size / SPI_CFEX_CMD_DATA_SIZE);

   /* */
   if ( (v_data_nb <= SPI_CFEX_FIFO_SIZE) && (p_buff_size >= (v_data_nb*SPI_CFEX_CMD_DATA_SIZE)) )
   {
      /* */
      /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast is safe. There is no loss of precision from (void*) to (uint32_t*). */
      pt_data_write = (uint32_t*)p_buff_addr;
      /* */
      for ( v_i=0ul; v_i<v_data_nb; v_i++ )
      {
         /* */
         if ( pt_spi_reg_descr->s_SR.u_B.s_TXCTR < (reg32_t)SPI_CFEX_FIFO_SIZE )
         {
            /* Write -  CMD : 16b DATA : 16b */
            pt_spi_reg_descr->s_PUSHR.u_PUSHR.u_R = (reg32_t)*pt_data_write;
            /* */
            *p_written_size += SPI_CFEX_CMD_DATA_SIZE;
            /* Pointer next Data */
            /* p_buff_size is the size of p_buff_addr in bytes. Therefore 'v_data_nb' is the number of 32 bit words in p_buff_addr.
             * The number of 'for' loops is 'v_data_nb'   */
            /* >RELAX<SYNCHRONe_C_Code_17.4> The pointer increment is controlled by the 'for' instruction. */
            pt_data_write++;
         }
         else
         {
            /* */
            v_i = v_data_nb;
         }
      }
   }
   /* else       */
   /* Size error */
}

/* ---------- internal operation bodies: ------------------------------------ */
