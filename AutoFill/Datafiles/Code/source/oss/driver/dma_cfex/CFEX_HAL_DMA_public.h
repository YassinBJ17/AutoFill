/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CFEX_HAL_DMA_PUBLIC_H
#define CFEX_HAL_DMA_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* DMA slots definitions */
typedef enum
{
   e_DMA_CFEX_ELT_SPI_ADC1_TX = 0,  /* ADC1 OVER SPI Tx */
   e_DMA_CFEX_ELT_SPI_ADC1_RX    ,  /* ADC1 OVER SPI Rx */
   e_DMA_CFEX_ELT_SPI_ADC2_TX    ,  /* ADC2 OVER SPI Tx */
   e_DMA_CFEX_ELT_SPI_ADC2_RX    ,  /* ADC2 OVER SPI Rx */
   e_DMA_CFEX_ELT_SPI_ADC3_TX    ,  /* ADC3 OVER SPI Tx */
   e_DMA_CFEX_ELT_SPI_ADC3_RX    ,  /* ADC3 OVER SPI Rx */
   e_DMA_CFEX_ELT_UART_TX        ,  /* UART for RS422 Tx link */
   e_DMA_CFEX_ELT_UART_RX        ,  /* UART for RS422 Rx link */
   e_DMA_CFEX_ELT_NB
}
te_cfex_dma_conf;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* CFEX_HAL_DMA_PUBLIC_H */
