/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef UART_CFEX_PUBLIC_H
#define UART_CFEX_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "UART_REG_public.h"
#include "driver/dma/DMA_HAL_public.h"

/* ---------- provided define constants: ------------------------------------ */
/* Bytes number in BDRL register for a 16 bits DMA request */
#define c_16_BIT_DMA_REQUEST_SIZE 2

/* Constant to get last byte on 32 bits */
#define LAST_BYTE_32_BITS_OFFSET (reg32_t)3

#define  CFEX_UART_CONF_NB 1

/* ------------------------------------------------------------------------------------------- */
/* --------------------------------------- UART COMMON --------------------------------------- */
/* ------------------------------------------------------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* */
typedef enum
{
   /* */
   e_UART_CFEX_TRANSFER_MODE_BUFFER  = 0,
   /* */
   e_UART_CFEX_TRANSFER_MODE_FIFO = 1,
   /* */
   e_UART_CFEX_TRANSFER_MODE_DMA  = 2
}
te_UART_CFEX_TRANSFER_MODE;

typedef struct
{
   reg32_t s_MIS        :1 ; /* Monitor Idle State */
   reg32_t s_CSP        :3 ; /* Configurable Sample point */
   reg32_t s_OSR        :4 ; /* Over Sampling Rate */
   reg32_t s_ROSE       :1 ; /* Reduced Over Sampling Enable */
   reg32_t s_NEF        :3 ; /* Number of expected frame */
   reg32_t s_DTU_PCETX  :1 ; /* Disable Timeout in UART mode/Parity transmission and checking */
   reg32_t s_SBUR       :2 ; /* Stop bits in UART reception mode */
   reg32_t s_WLS        :1 ; /* Special Word Length in UART mode */
   reg32_t s_TDFL_TFC   :3 ; /* Transmitter Data Field Length/TX FIFO Counter */
   reg32_t s_RDFL_RFC   :3 ; /* Reception Data Field Length /RX FIFO Counter */
   reg32_t s_RFBM       :1 ; /* RFBM Rx Fifo/Buffer mode */
   reg32_t s_TFBM       :1 ; /* Tx Fifo/Buffer mode */
   reg32_t s_WL1        :1 ; /* Word Length in UART mode */
   reg32_t s_PC1        :1 ; /* Parity Control */
   reg32_t s_RxEn       :1 ; /* Receiver Enable */
   reg32_t s_TxEn       :1 ; /* Transmitter Enable */
   reg32_t s_PC0        :1 ; /* Parity Control */
   reg32_t s_PCE        :1 ; /* Parity Control Enable */
   reg32_t s_WL0        :1 ; /* Word Length in UART mode */
   reg32_t s_UART       :1 ; /* UART Mode */
}
ts_UART_CFEX_UART_CR;

typedef union
{
   reg32_t              u_R;
   ts_UART_CFEX_UART_CR u_B;
}
tu_UART_CFEX_UART_CR;

typedef struct
{
   /* configure baudrate */
   /* exemple ; configuration baudrate of 19200 with a 80 MHz baud clock (LIN_clk below)*/

   /* LFDIV = LIN_clk / (16 * desired baudrate)
      LINIBRR = integer part of LFDIV
      LINFBRR = 16 * fractional part of LFDIV (after decimal point)
      for instance:
      LFDIV = 80e6/(16*19200) = 260,4166667
      LINIBRR = 260
      LINFBRR = 16*0,4166667 = 6,666  ~ 6
   */
   reg32_t s_int_part_LFDIV;
   reg32_t s_frac_part_LFDIV;

   /* UART CR configuration register (see LINFlexD_UARTCR_tag ) */
   tu_UART_CFEX_UART_CR s_UARTCR_conf;
}
ts_UART_CFEX_HW_CONF ;


typedef struct
{
   int8_t*  s_buff_current;
   /* size in bytes of the buffer */
   uint32_t s_buff_size;
   uint32_t s_nb_done;
}
ts_UART_CFEX_RX_ACCESS ;

typedef struct
{
   int8_t*   s_buff_current;
   /* size in bytes of the buffer */
   uint32_t s_buff_size;
   uint32_t s_nb_done;
   uint32_t s_nb_in_progress;
}
ts_UART_CFEX_TX_ACCESS ;

/* {{RELAX<SYNCHRONe_C_Code_8.17> : Enumerate define the MPC5777 UART line capacity. Every line does not need
   to be used or initialize.   */
typedef enum
{
   e_UART_LINE_0  = 0,
   e_UART_LINE_1  = 1,
   e_UART_LINE_2  = 2,
   e_UART_LINE_14 = 3,
   e_UART_LINE_15 = 4,
   e_UART_LINE_16 = 5,
   e_UART_LINE_NB = 6
}
te_UART_CFEX_LINE_NB;

/* }}<SYNCHRONe_C_Code_8.17> */

/* ------------------------------------------------------------------------------------------- */
/* --------------------------------------- UART DMA ------------------------------------------ */
/* ------------------------------------------------------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */


typedef struct
{
   /* DMA conf id */
   CMN_IOSP_ID_t     s_conf_id;
   /* DMA one-shot or cyclic buffer mode */
   te_DMA_BUFFER_MGT s_type_fill;
   /* DMA request size */
   te_DMA_BYTE_REQ   s_type_dma_transfert;
}
ts_UART_DMA_CFEX_CONFIG;


/* Configuration table structure */
typedef struct
{
   /* UART line number */
   te_UART_CFEX_LINE_NB       s_line_nb;
   /* UART hardware configuration */
   ts_UART_CFEX_HW_CONF       s_uart_hw_conf;
   /* Transfer mode */
   te_UART_CFEX_TRANSFER_MODE s_tranfer_mode;
   /* DMA TX configuration */
   ts_UART_DMA_CFEX_CONFIG    s_dma_conf_tx;
   /* DMA RX configuration */
   ts_UART_DMA_CFEX_CONFIG    s_dma_conf_rx;
}
ts_UART_CFEX_ELT;


/* Descriptor Structure */
typedef struct
{
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t                  s_address;
   /* UART TX access */
   ts_UART_CFEX_TX_ACCESS                 s_desc_tx;
   /* UART RX access */
   ts_UART_CFEX_RX_ACCESS                 s_desc_rx;
   /* DMA TX configuration */
   ts_UART_DMA_CFEX_CONFIG                s_dma_conf_tx;
   /* DMA RX configuration */
   ts_UART_DMA_CFEX_CONFIG                s_dma_conf_rx;
}
ts_UART_CONFIG_DESC;


/* ---------- provided constants: ------------------------------------------- */

extern const uint32_t FDX_c_UART_CFEX_tab_SIZE;
/* {{RELAX<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> Configuration Table, the size is specified and fixed at integration. */
extern ts_UART_CFEX_ELT FDX_c_UART_CFEX_CONFIGURATION_tab[];

/* ---------- provided data: ------------------------------------------------ */

/* UART descriptor */
extern ts_UART_CONFIG_DESC FDX_UART_CFEX_descriptor_tab[];
/* }}<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> */



#endif /* UART_CFEX_PUBLIC_H */
