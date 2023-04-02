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

void FDX_UART_DMA_GET_READ_STATUS ( CMN_IOSP_ID_t const p_uart_line_id ,
                                ts_UART_STATS_TRANSFERT * const p_stats )
{
   /* Local variable declaration */
   CMN_IOSP_ID_t           v_dma_conf;
   ts_UART_CFEX_RX_ACCESS* pt_buff_read;
   ts_DMA_STATUS           v_data;
   te_DMA_BYTE_REQ         v_dma_type;

   /* Local variable initialization */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe. All are from same types. */
   v_dma_conf = FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_dma_conf_rx.s_conf_id;
   pt_buff_read = & (FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_desc_rx);
   v_dma_type = FDX_UART_CFEX_descriptor_tab[ p_uart_line_id ].s_dma_conf_rx.s_type_dma_transfert;
   /* }}<SYNCHRONe_C_Code_10.7>} */

   /* 1/ get the DMA status */
   FDX_DMA_STATUS ( v_dma_conf ,  & v_data );

   /*>RELAX<SYNCHRONe_C_Code_10.7> The cast is correct. the value 1 can be coded as a unsigned short. */
   if ( v_data.s_read_done == (uint16_t)1 )
   {
      pt_buff_read->s_nb_done = (uint32_t) v_data.s_cycle_nb;
   }
   else
   {
      pt_buff_read->s_nb_done = ( (uint32_t) v_data.s_cycle_nb ) - (uint32_t)v_data.s_cycle_count;
   }

   if ( v_dma_type == e_DMA_REQUEST_16_BIT )
   {
      /* >RELAX<SYNCHRONe_C_Code_7.2> Obvious literal value: 16 bit is twice than 8 bits */
      pt_buff_read->s_nb_done *= 2ul ;
   }
   p_stats->s_done_nb = pt_buff_read->s_nb_done ;
   p_stats->s_size = pt_buff_read->s_buff_size ;
}


/* ---------- internal operation bodies: ------------------------------------ */
