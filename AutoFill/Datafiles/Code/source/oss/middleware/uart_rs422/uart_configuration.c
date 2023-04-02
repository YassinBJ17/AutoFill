/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : uart_configuration which allows UART configuration
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/uart_rs422/uart_private.h"
#include "driver/uart/UART_CFEX_public.h"
#include "conf/oss_conf_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* UARTCR default configuration */
#define UARTCR_DEFAULT_CONFIG    ((reg32_t)0x00000333)

/* DMA slots definitions */
#define DMA_CFEX_ELT_UART_TX     ((uint32_t)6) /* UART for RS422 Tx link */
#define DMA_CFEX_ELT_UART_RX     ((uint32_t)7) /* UART for RS422 Rx link */

/* Baud rate configuration index */
#define BAUD_RATE_9600           ((uint32_t)0)
#define BAUD_RATE_19200          ((uint32_t)1)
#define BAUD_RATE_115200         ((uint32_t)2)
#define BAUD_RATE_460800         ((uint32_t)3)
#define BAUD_RATE_921600         ((uint32_t)4)
#define BAUD_RATE_1000000        ((uint32_t)5)

/* Integer Baud rate values (assuming 100 MHz baud clock) */
#define INT_BAUD_RATE_9600       ((reg32_t)651)
#define INT_BAUD_RATE_19200      ((reg32_t)325)
#define INT_BAUD_RATE_115200     ((reg32_t)54)
#define INT_BAUD_RATE_460800     ((reg32_t)13)
#define INT_BAUD_RATE_921600     ((reg32_t)6)
#define INT_BAUD_RATE_1000000    ((reg32_t)6)

/* Fractionnal Baud rate values (assuming 100 MHz baud clock) */
#define FRAC_BAUD_RATE_9600      ((reg32_t)1)
#define FRAC_BAUD_RATE_19200     ((reg32_t)8)
#define FRAC_BAUD_RATE_115200    ((reg32_t)4)
#define FRAC_BAUD_RATE_460800    ((reg32_t)9)
#define FRAC_BAUD_RATE_921600    ((reg32_t)12)
#define FRAC_BAUD_RATE_1000000   ((reg32_t)4)

/* Parity control index */
#define PARITY_NONE              ((uint32_t)0)
#define PARITY_ODD               ((uint32_t)1)
#define PARITY_EVEN              ((uint32_t)2)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Manage UART configuration */
void uart_configuration(const boolean_t p_channel_is_a)
{
   /* Configuration table */
   const ts_oss_conf_table *oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* Configurable elements of UART */
   uint32_t baud_rate;
   uint32_t parity_bit;
   uint32_t stop_bit;

   /* Get configuration */
   if (p_channel_is_a)
   {
      baud_rate = oss_conf->s_rs422a_baud;
      parity_bit = oss_conf->s_rs422a_parity_bit;
      stop_bit = oss_conf->s_rs422a_stop_bit;
   }
   else
   {
      baud_rate = oss_conf->s_rs422b_baud;
      parity_bit = oss_conf->s_rs422b_parity_bit;
      stop_bit = oss_conf->s_rs422b_stop_bit;
   }

   /* Default configuration */
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_line_nb = e_UART_LINE_0;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_UARTCR_conf.u_R = UARTCR_DEFAULT_CONFIG;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_tranfer_mode = e_UART_CFEX_TRANSFER_MODE_DMA;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_dma_conf_tx.s_conf_id = DMA_CFEX_ELT_UART_TX;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_dma_conf_tx.s_type_fill = e_DMA_BUFFER_ONE_SHOT;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_dma_conf_tx.s_type_dma_transfert = e_DMA_REQUEST_8_BIT;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_dma_conf_rx.s_conf_id = DMA_CFEX_ELT_UART_RX;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_dma_conf_rx.s_type_fill = e_DMA_BUFFER_ONE_SHOT;
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_dma_conf_rx.s_type_dma_transfert = e_DMA_REQUEST_8_BIT;


   /* Configure baud rate */
   switch (baud_rate)
   {
      case BAUD_RATE_9600:
      {
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_int_part_LFDIV = INT_BAUD_RATE_9600;
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_frac_part_LFDIV = FRAC_BAUD_RATE_9600;
         break;

      }

      case BAUD_RATE_19200:
      {
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_int_part_LFDIV = INT_BAUD_RATE_19200;
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_frac_part_LFDIV = FRAC_BAUD_RATE_19200;
         break;

      }

      case BAUD_RATE_115200:
      {
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_int_part_LFDIV = INT_BAUD_RATE_115200;
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_frac_part_LFDIV = FRAC_BAUD_RATE_115200;
         break;

      }

      case BAUD_RATE_460800:
      {
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_int_part_LFDIV = INT_BAUD_RATE_460800;
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_frac_part_LFDIV = FRAC_BAUD_RATE_460800;
         break;

      }

      case BAUD_RATE_921600:
      {
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_int_part_LFDIV = INT_BAUD_RATE_921600;
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_frac_part_LFDIV = FRAC_BAUD_RATE_921600;
         break;

      }

      case BAUD_RATE_1000000:
      {
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_int_part_LFDIV = INT_BAUD_RATE_1000000;
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_frac_part_LFDIV = FRAC_BAUD_RATE_1000000;
         break;

      }

      default:
      {
         /* Unknown configuration */
         break;

      }
   }

   /* When the parity configuration is set to no parity */
   if (PARITY_NONE == parity_bit)
   {
      /* Disable parity control */
      FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_UARTCR_conf.u_B.s_PCE = (reg32_t)0;
   }
   else
   {
      /* Enable parity control */
      FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_UARTCR_conf.u_B.s_PCE = (reg32_t)1;

      /* When the parity configuration is set to odd */
      if (PARITY_ODD == parity_bit)
      {
         /* Configure the parity sent to be odd */
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_UARTCR_conf.u_B.s_PC0 = (reg32_t)1;
      }
      /* When the parity configuration is set to even */
      else
      {
         /* Configure the parity sent to be even */
         FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_UARTCR_conf.u_B.s_PC0 = (reg32_t)0;
      }
   }

   /* Configure stop bit */
   FDX_c_UART_CFEX_CONFIGURATION_tab[e_UART_LINE_0].s_uart_hw_conf.s_UARTCR_conf.u_B.s_SBUR = (reg32_t)stop_bit;
}

/* ---------- internal operation bodies: ------------------------------------ */
