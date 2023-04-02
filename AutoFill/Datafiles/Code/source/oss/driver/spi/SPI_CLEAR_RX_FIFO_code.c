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
void SPI_CLEAR_RX_FIFO( CMN_IOSP_ID_t  const p_spi_conf_id)
{
   /* Local variable declaration */
   ts_SPI_REG volatile * pt_spi_reg_descr;
   /* */
   /* Get the SPI register descriptor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_SPI_REG' is tailor-made for the registers starting at this address.  */
   pt_spi_reg_descr = (ts_SPI_REG volatile *)SPI_CFEX_descriptor_tab[p_spi_conf_id].s_address;

   /* Clear RX Fifo */
   pt_spi_reg_descr->s_MCR.u_B.s_CLR_RXF = 1;
}

/* ---------- internal operation bodies: ------------------------------------ */
