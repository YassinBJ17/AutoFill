/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVLPSPI_PRIVATE_H
#define DRVLPSPI_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVLPSPI_LPSPI2_ADDRESS      0x4002E000UL

#define DRVLPSPI_CR_RESET            0x00000000UL
#define DRVLPSPI_CR_CONFIG           0x00000009UL
#define DRVLPSPI_IER_CONFIG          0x00000000UL
#define DRVLPSPI_DER_CONFIG          0x00000000UL
#define DRVLPSPI_CFGR0_CONFIG        0x00000000UL
#define DRVLPSPI_CFGR1_CONFIG        0x00000001UL
#define DRVLPSPI_CCR_CONFIG          0x0202F817UL
#define DRVLPSPI_FCR_CONFIG          0x00000003UL
#define DRVLPSPI_TCR_CONFIG          0x4000000FUL

#define DRVLPSPI_SR_RDF_READY_MASK   0x00000002UL

#define DRVLPSPI_TX_RX_FIFO_SIZE     4UL

#define DRVLPSPI_FSR_TXCOUNT_MASK    0x00000007UL
#define DRVLPSPI_FSR_RXCOUNT_MASK    0x00070000UL
#define DRVLPSPI_FSR_RX_EMPTY        0x00000000UL

#define DRVLPSPI_DATA_8BIT_NB        4UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_VERID;
   uint32_t S_PARAM;
   uint32_t S_LPSPI_Reserved_1 [2];
   uint32_t S_CR;
   uint32_t S_SR;
   uint32_t S_IER;
   uint32_t S_DER;
   uint32_t S_CFGR0;
   uint32_t S_CFGR1;
   uint32_t S_LPSPI_Reserved_2 [2];
   uint32_t S_DMR0;
   uint32_t S_DMR1;
   uint32_t S_LPSPI_Reserved_3 [2];
   uint32_t S_CCR;
   uint32_t S_LPSPI_Reserved_4 [5];
   uint32_t S_FCR;
   uint32_t S_FSR;
   uint32_t S_TCR;
   uint32_t S_TDR;
   uint32_t S_LPSPI_Reserved_5 [2];
   uint32_t S_RSR;
   uint32_t S_RDR;
} TS_DrvLPSPI_Registers;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvLPSPI_Registers * const C_DrvLPSPI_Registers;


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVLPSPI_PRIVATE_H */
