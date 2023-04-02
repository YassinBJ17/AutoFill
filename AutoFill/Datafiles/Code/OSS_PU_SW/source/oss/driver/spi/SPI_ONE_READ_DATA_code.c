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
/* Used to received data */
void SPI_ONE_READ_DATA ( CMN_IOSP_ID_t       const p_spi_conf_id,
                         CMN_SYSTEM_ADDR_t   const p_buff_addr,
                         CMN_SYSTEM_SIZE_t   const p_buff_size,
                         CMN_SYSTEM_SIZE_t * const p_read_size )
{
   /* Local variable declaration */
   ts_SPI_REG volatile *    pt_spi_reg_descr;
   /* */
   uint16_t * pt_data_read;

   /* Local variable initialization */
   /* */

   /* Initialize the read size */
   *p_read_size = 0ul;

   /* Get the SPI register descriptor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_SPI_REG' is tailor-made for the registers starting at this address.  */
   pt_spi_reg_descr = (ts_SPI_REG volatile *)SPI_CFEX_descriptor_tab[p_spi_conf_id].s_address;

   /* */
   if ( p_buff_size >= SPI_CFEX_DATA_SIZE )
   {
      /* */
      /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> The cast is safe. There is no loss of precision from (void*) to (uint16_t*). */
      pt_data_read = (uint16_t*)p_buff_addr;
      /* */
      if ( pt_spi_reg_descr->s_SR.u_B.s_RXCTR != (reg32_t)0ul )
      {
         /* Read */
         /* >RELAX<SYNCHRONe_C_Code_10.7> 16-bit read accesses to the POPR has the same effect on the RX FIFO as 32-bit read accesses */
         *pt_data_read = (uint16_t)(pt_spi_reg_descr->s_POPR.u_R);
         /* */
         *p_read_size += SPI_CFEX_DATA_SIZE;
      }
      /* else         */
      /* No reception */
   }
   /* else       */
   /* Size error */
}

/* ---------- internal operation bodies: ------------------------------------ */
