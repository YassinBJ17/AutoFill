/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef UART_HAL_PUBLIC_H
#define UART_HAL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

#include "type/mcp_types.h"
#include "driver/dma/DMA_HAL_public.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
    /* Transfer size  */
    uint32_t s_size;
    /* Transfer done  */
    uint32_t s_done_nb;
}
ts_UART_STATS_TRANSFERT;

/* ---------- provided operations: ------------------------------------------ */

extern void FDX_UART_INIT( tu_CMN_RC * const p_return_code );

extern void FDX_UART_DMA_GET_WRITE_STATUS ( CMN_IOSP_ID_t const p_uart_line_id ,
                                        ts_UART_STATS_TRANSFERT * const p_stats ) ;

/* */
extern void FDX_UART_DMA_START_WRITE ( CMN_IOSP_ID_t const p_uart_line_id ,
                                  const ts_CMN_IOSP_BUFFER * const p_buffer,
                                  uint32_t * const p_old_index) ;

/* */
extern void FDX_UART_DMA_START_READ ( CMN_IOSP_ID_t const p_uart_line_id ,
                                  const ts_CMN_IOSP_BUFFER * const p_buffer ,
                                  uint32_t * const p_old_index ) ;

/* */
extern void FDX_UART_DMA_GET_READ_STATUS ( CMN_IOSP_ID_t const p_uart_line_id ,
                                       ts_UART_STATS_TRANSFERT * const p_stats ) ;

extern void FDX_UART_DMA_SET_RX_CFG ( CMN_IOSP_ID_t const p_uart_line_id ,
                                  ts_DMA_PROG * const p_dma_prog ) ;
/* */
extern void FDX_UART_DMA_SET_TX_CFG ( CMN_IOSP_ID_t const p_uart_line_id ,
                                  ts_DMA_PROG * const p_dma_prog ) ;

/* */
extern void FDX_UART_FIFO_READ_UPDATE ( CMN_IOSP_ID_t const p_uart_line_id,
                                        ts_UART_STATS_TRANSFERT * const p_stats );

/* compliant with interface  UART_HALEX_FUNC_READ_TYPE */
extern void FDX_UART_FIFO_SET_READ_MEM ( CMN_IOSP_ID_t const p_uart_line_id,
                                     const ts_CMN_IOSP_BUFFER * const p_buffer );

extern void FDX_UART_FIFO_SET_WRITE_MEM ( CMN_IOSP_ID_t const p_uart_line_id,
                                      const ts_CMN_IOSP_BUFFER * const p_buffer );

/* */
extern void FDX_UART_FIFO_WRITE_UPDATE ( CMN_IOSP_ID_t const p_uart_line_id,
                                     ts_UART_STATS_TRANSFERT * const p_stats );

extern void FDX_UART_BUFFER_READ_UPDATE ( CMN_IOSP_ID_t const p_uart_line_id,
                                      ts_UART_STATS_TRANSFERT * const p_stats );

extern void FDX_UART_BUFFER_SET_READ_MEM (  CMN_IOSP_ID_t const p_uart_line_id,
                                        const ts_CMN_IOSP_BUFFER * const p_buffer );

extern void FDX_UART_BUFFER_SET_WRITE_MEM (  CMN_IOSP_ID_t const p_uart_line_id,
                                         const ts_CMN_IOSP_BUFFER * const p_buffer );

extern void FDX_UART_BUFFER_WRITE_UPDATE ( CMN_IOSP_ID_t const p_uart_line_id,
                                       ts_UART_STATS_TRANSFERT * const p_stats );

#endif /* UART_HAL_PUBLIC_H */
