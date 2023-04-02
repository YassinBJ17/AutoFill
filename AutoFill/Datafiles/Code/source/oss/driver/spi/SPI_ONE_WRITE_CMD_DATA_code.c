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
#include "driver/spi/SPI_HAL_public.h"
#include "driver/spi/SPI_REG_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Used to transmit data */
void SPI_ONE_WRITE_CMD_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                              CMN_SYSTEM_ADDR_t   const p_buff_addr,
                              CMN_SYSTEM_SIZE_t   const p_buff_size,
                              CMN_SYSTEM_SIZE_t * const p_written_size)
{
   /* Local variable declaration */
   ts_SPI_REG volatile * pt_spi_reg_descr;
   /* */
   uint32_t * pt_data_write;

   /* Local variable initialization */
   /* */

   /* Initialize the write size */
   *p_written_size = 0ul;

   /* Get the SPI register descriptor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_SPI_REG' is tailor-made for the registers starting at this address.  */
   pt_spi_reg_descr = (ts_SPI_REG volatile *)SPI_CFEX_descriptor_tab[p_spi_conf_id].s_address;

   /* */
   if ( p_buff_size == SPI_CFEX_CMD_DATA_SIZE )
   {
      /* */
      /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast is safe. There is no loss of precision from (void*) to (uint32_t*). */
      pt_data_write = (uint32_t*)p_buff_addr;
      /* */
      if ( pt_spi_reg_descr->s_SR.u_B.s_TXCTR == (reg32_t)0ul )
      {
         /* Write -  CMD : 16b DATA : 16b */
         pt_spi_reg_descr->s_PUSHR.u_PUSHR.u_R = (reg32_t)*pt_data_write;
         /* */
         *p_written_size += SPI_CFEX_CMD_DATA_SIZE;
      }
   }
   /* else       */
   /* Size error */
}

/* ---------- internal operation bodies: ------------------------------------ */
