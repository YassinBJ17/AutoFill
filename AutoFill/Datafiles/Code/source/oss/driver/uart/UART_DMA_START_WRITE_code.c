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
void FDX_UART_DMA_START_WRITE (CMN_IOSP_ID_t const p_uart_line_id ,
                           const ts_CMN_IOSP_BUFFER * const p_buffer,
                           uint32_t * const p_old_index)
{
   /* Local variable declaration */
   ts_UART_CFEX_TX_ACCESS *  pt_buff_write;
   ts_DMA_PROG               v_dma_prog;
   CMN_IOSP_ID_t             v_dma_id;
   te_DMA_BYTE_REQ           v_dma_type;
   ts_UART_STATS_TRANSFERT   v_stats;

   /* Local variable initialization */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. All are from same types. */
   pt_buff_write = & (FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_tx );
   v_dma_id = FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_dma_conf_tx.s_conf_id;
   v_dma_type = FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_dma_conf_tx.s_type_dma_transfert;
   /* }}<SYNCHRONe_C_Code_10.7> */

   pt_buff_write->s_nb_done = 0UL;
   pt_buff_write->s_buff_current = (int8_t*)p_buffer->s_buffer;
   pt_buff_write->s_buff_size = p_buffer->s_buffer_size;
   pt_buff_write->s_nb_in_progress = 0UL;

   FDX_DMA_REQUEST (v_dma_id , e_CMN_FLAG_NOT_ACTIVATE);

   /* get the DMA status */
   FDX_UART_DMA_GET_WRITE_STATUS (p_uart_line_id , &v_stats);

   *p_old_index = v_stats.s_done_nb;

   /* reconfigure DMA with new buffer */
   FDX_UART_DMA_SET_TX_CFG (p_uart_line_id , & v_dma_prog);

   /*>RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> the cast is wanted and under control where as it is the address that is given here. */
   v_dma_prog.s_src_addr = (uint32_t) pt_buff_write->s_buff_current;
   v_dma_prog.s_src_last_addr = v_dma_prog.s_src_addr + (uint32_t) pt_buff_write->s_buff_size;

   if (v_dma_type == e_DMA_REQUEST_16_BIT)
   {
      /*the buffer size is divided by 2 to convert a size of a 8 bits array into a size of a 16 bits array */
      /* >RELAX<SYNCHRONe_C_Code_10.7> the buffer size is coded in a uint16 as it range is limit to {0;2^16] (see LLR restriction on the New Buffer Size parameter) */
      v_dma_prog.s_nb_cycle = (uint16_t)(pt_buff_write->s_buff_size / (uint32_t)(c_16_BIT_DMA_REQUEST_SIZE));
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7> the buffer size can be coded in a uint16 as it range is limit to {0;2^15] (see LLR restriction on the New Buffer Size parameter) */
      v_dma_prog.s_nb_cycle = (uint16_t)(pt_buff_write->s_buff_size);
   }
   FDX_DMA_CFG (v_dma_id , &v_dma_prog);
   FDX_DMA_REQUEST (v_dma_id , e_CMN_FLAG_ACTIVATE);
}

/* ---------- internal operation bodies: ------------------------------------ */
