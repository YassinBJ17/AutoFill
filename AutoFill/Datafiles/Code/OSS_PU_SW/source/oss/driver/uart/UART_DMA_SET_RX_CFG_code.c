/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/dma/DMA_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "UART_CFEX_public.h"
#include "UART_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void FDX_UART_DMA_SET_RX_CFG ( CMN_IOSP_ID_t const p_uart_line_id,
                           ts_DMA_PROG * const p_dma_prog )
{
   /* Local variable declaration */
   ts_UART_LINFlexD_COMMON_REG volatile *  pt_uart_reg;
   const ts_UART_DMA_CFEX_CONFIG *         c_uart_dma_conf;

   /* Local variable initialization */
   /*>RELAX<SYNCHRONe_C_Code_10.7> The structure ts_UART_LINFlexD_COMMON_REG is explicitly made for this address. Cast is normal. */
   pt_uart_reg = (ts_UART_LINFlexD_COMMON_REG volatile *) FDX_UART_CFEX_descriptor_tab[p_uart_line_id].s_address;
   /*>RELAX<SYNCHRONe_C_Code_10.7> The cast is safe, from ts_UART_DMA_CFEX_CONFIG* to ts_UART_DMA_CFEX_CONFIG* */
   c_uart_dma_conf = &(FDX_UART_CFEX_descriptor_tab[p_uart_line_id].s_dma_conf_rx);

   p_dma_prog->s_buff_type = c_uart_dma_conf->s_type_fill;
   p_dma_prog->s_nb_byte_req = c_uart_dma_conf->s_type_dma_transfert;

   switch (c_uart_dma_conf->s_type_dma_transfert)
   {
      case e_DMA_REQUEST_16_BIT :
      {
         /*>RELAX<SYNCHRONe_C_Code_17.----4> the value '2' is the byte number in the register. It is not a magic number. */
         /*>RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> the cast is intended as it is the address of the register that is wanted. */
         p_dma_prog->s_src_addr = ((uint32_t) & (pt_uart_reg->s_BDRM.u_R)) + (uint32_t)c_16_BIT_DMA_REQUEST_SIZE ;
         p_dma_prog->s_src_last_addr = p_dma_prog->s_src_addr ;

         /* >RELAX<SYNCHRONe_C_Code_10.7>  literal value can be coded in a signed short */
         p_dma_prog->s_src_off = (uint16_t)(0) ;

         /* >RELAX<SYNCHRONe_C_Code_10.7>  literal value can be coded in a signed short */
         p_dma_prog->s_dest_off = (uint16_t)(c_16_BIT_DMA_REQUEST_SIZE) ;
      }
      break ;
      default :
      {
         /*>RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> the cast is intended as it is the address of the register that is wanted. */
         /*>RELAX<SYNCHRONe_C_Code_7.2, SYNCHRONe_C_Code_17.4> the value '3' is the byte number in the register. It is not a magic number. */
         p_dma_prog->s_src_addr = ((uint32_t) & (pt_uart_reg->s_BDRM.u_R))  + 3UL ;
         p_dma_prog->s_src_last_addr = p_dma_prog->s_src_addr ;

         /*>RELAX<SYNCHRONe_C_Code_10.7> literal value can be coded in a signed short */
         p_dma_prog->s_src_off = (uint16_t)(0) ;

         /*>RELAX<SYNCHRONe_C_Code_10.7> literal value can be coded in a signed short */
         p_dma_prog->s_dest_off = (uint16_t)(1) ;
      }
      break ;
   }

   /* following values to be determinated by caller */
   /* >RELAX<SYNCHRONe_C_Code_10.7> literal value can be coded in a signed short */
   p_dma_prog->s_nb_cycle = (uint16_t)(0) ;
   p_dma_prog->s_dest_addr = 0UL ;
   p_dma_prog->s_dest_last_addr = 0UL ;
}

/* ---------- internal operation bodies: ------------------------------------ */
