#include "UART_CFEX_public.h"
#include "UART_HAL_public.h"
#include "driver/dma/DMA_HAL_public.h"
#include "libtools/time/LIB_TIME_public.h"

       if (c_conf->s_tranfer_mode == e_UART_CFEX_TRANSFER_MODE_DMA)       {           FDX_UART_DMA_SET_RX_CFG( (CMN_IOSP_ID_t) v_i , &v_dma_prog);           FDX_DMA_CFG(c_conf->s_dma_conf_rx.s_conf_id , &v_dma_prog );           FDX_UART_DMA_SET_TX_CFG((CMN_IOSP_ID_t) v_i , &v_dma_prog);           FDX_DMA_CFG (c_conf->s_dma_conf_tx.s_conf_id , &v_dma_prog );           c_uart_reg.s_uart_master_reg->s_DMARXE.u_R = 0x0001U ;           c_uart_reg.s_uart_master_reg->s_DMATXE.u_R = 0x0001U ;       }
