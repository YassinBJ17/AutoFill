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
void FDX_UART_DMA_START_READ (CMN_IOSP_ID_t const p_uart_line_id ,
                           const ts_CMN_IOSP_BUFFER * const p_buffer ,
                           uint32_t * const p_old_index)
{
   /* Local variable declaration */
   ts_UART_CFEX_RX_ACCESS *  pt_buff_read;
   CMN_IOSP_ID_t             v_dma_id;
   ts_DMA_PROG               v_dma_prog;
   te_DMA_BYTE_REQ           v_dma_type;
   ts_UART_STATS_TRANSFERT   v_stats ;

   /* Local variable initialization */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. All are from same types. */
   pt_buff_read = &(FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_rx) ;
   v_dma_id = FDX_UART_CFEX_descriptor_tab[p_uart_line_id].s_dma_conf_rx.s_conf_id ;
   v_dma_type = FDX_UART_CFEX_descriptor_tab[p_uart_line_id].s_dma_conf_rx.s_type_dma_transfert ;
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* init output structure */
   pt_buff_read->s_buff_current = (int8_t*)p_buffer->s_buffer ;
   pt_buff_read->s_buff_size = p_buffer->s_buffer_size ;
   pt_buff_read->s_nb_done = 0UL ;

   /* 1/ Stop dma :  */
   FDX_DMA_REQUEST ( v_dma_id , e_CMN_FLAG_NOT_ACTIVATE  ) ;

   /* 2/ get the DMA status */
   FDX_UART_DMA_GET_READ_STATUS ( p_uart_line_id , &v_stats ) ;

   *p_old_index = v_stats.s_done_nb ;

   /* change the DMA buffer */
   FDX_UART_DMA_SET_RX_CFG( p_uart_line_id , &v_dma_prog ) ;

   if ( v_dma_type == e_DMA_REQUEST_16_BIT )
   {
      /* the buffer size is divided by 2 to convert a size of a 8 bits array into a size of a 16 bits array. */
      /* >RELAX<SYNCHRONe_C_Code_10.7> the buffer size is coded in a uint16 as it range is limit to {0;2^16] (see LLR restriction on the New Buffer Size parameter) */
      v_dma_prog.s_nb_cycle = ( uint16_t )( p_buffer->s_buffer_size / (uint32_t)(c_16_BIT_DMA_REQUEST_SIZE) ) ;
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7> the buffer size can be coded in a uint16 as it range is limit to {0;2^15] (see LLR restriction on the New Buffer Size parameter) */
      v_dma_prog.s_nb_cycle = ( uint16_t )( p_buffer->s_buffer_size ) ;
   }

   /*>RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> the cast is intended: it is the "buffer" address that is given. */
   v_dma_prog.s_dest_addr = (uint32_t) ( p_buffer->s_buffer ) ;
   v_dma_prog.s_dest_last_addr = v_dma_prog.s_dest_addr + (uint32_t) p_buffer->s_buffer_size ;
   FDX_DMA_CFG ( v_dma_id , &v_dma_prog ) ;

   /* 4/ relaunch DMA */
   FDX_DMA_REQUEST ( v_dma_id , e_CMN_FLAG_ACTIVATE ) ;
}

/* ---------- internal operation bodies: ------------------------------------ */
