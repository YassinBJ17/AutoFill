/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "UART_CFEX_public.h"
#include "UART_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/dma/DMA_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void FDX_UART_DMA_GET_WRITE_STATUS ( CMN_IOSP_ID_t const p_uart_line_id ,
                                 ts_UART_STATS_TRANSFERT * const p_stats )
{
   /* Local variable declaration */
   ts_UART_CFEX_TX_ACCESS *               pt_buff_write ;
   CMN_IOSP_ID_t                          v_dma_conf ;
   ts_DMA_STATUS                          v_data ;
   ts_UART_LINFlexD_COMMON_REG volatile * pt_uart_reg ;
   te_DMA_BYTE_REQ                        v_dma_type ;
   uint32_t                               v_done_nb ;

   /* Local variable initialization */
   /*>RELAX<SYNCHRONe_C_Code_10.7> The structure ts_UART_LINFlexD_COMMON_REG is explicitly made for this address. Cast is normal. */
   pt_uart_reg = (ts_UART_LINFlexD_COMMON_REG volatile *) FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_address  ;
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. All are from same types. */
   v_dma_conf = FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_dma_conf_tx.s_conf_id ;
   pt_buff_write = & (FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_tx) ;
   v_dma_type = FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_dma_conf_rx.s_type_dma_transfert ;
   /* }}<SYNCHRONe_C_Code_10.7> */

   FDX_DMA_STATUS ( v_dma_conf , &v_data ) ;

   /*>RELAX<SYNCHRONe_C_Code_10.7> the value '1' can be coded as an unsigned short. */
   if ( v_data.s_read_done == (uint16_t)1 )
   {
      v_done_nb = (uint32_t) v_data.s_cycle_nb  ;

      if ( 0U == pt_uart_reg->s_UARTSR.u_B.s_DTFTFF )
      {
         pt_buff_write->s_nb_in_progress = 0UL ;
      }
      else
      {
         pt_buff_write->s_nb_in_progress = 1UL ;
      }
   }
   else
   {
      v_done_nb =( (uint32_t) v_data.s_cycle_nb ) - (uint32_t)v_data.s_cycle_count ;
      pt_buff_write->s_nb_in_progress = 0UL ;
   }

   if ( v_dma_type == e_DMA_REQUEST_16_BIT )
   {
      /* {{RELAX<SYNCHRONe_C_Code_7.2> : the '2' value is the size difference between 16 bits and 8 bits. The value is obvious. */
      v_done_nb *= 2UL;
      pt_buff_write->s_nb_in_progress *= 2UL ;
      /* }}<SYNCHRONe_C_Code_7.2> */
   }

   /* no information on the number of character written */
   pt_buff_write->s_nb_done = v_done_nb - pt_buff_write->s_nb_in_progress ;
   p_stats->s_done_nb = pt_buff_write->s_nb_done ;
   p_stats->s_size = pt_buff_write->s_buff_size ;
}

/* ---------- internal operation bodies: ------------------------------------ */
