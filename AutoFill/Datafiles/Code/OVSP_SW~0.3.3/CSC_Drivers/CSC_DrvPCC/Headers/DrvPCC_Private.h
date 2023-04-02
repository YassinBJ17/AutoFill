/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVPCC_PRIVATE_H
#define DRVPCC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVPCC_PCC_ADDRESS       0x40065000UL

#define DRVPCC_PCC_NB            128UL
#define DRVPCC_PCC_USED_NB       14UL

#define DRVPCC_FLEXCAN1_INDEX    37UL
#define DRVPCC_FTM3_INDEX        38UL
#define DRVPCC_ADC1_INDEX        39UL
#define DRVPCC_LPSPI2_INDEX      46UL
#define DRVPCC_LPIT_INDEX        55UL
#define DRVPCC_FTM0_INDEX        56UL
#define DRVPCC_FTM1_INDEX        57UL
#define DRVPCC_FTM2_INDEX        58UL
#define DRVPCC_ADC0_INDEX        59UL
#define DRVPCC_PORTA_INDEX       73UL
#define DRVPCC_PORTB_INDEX       74UL
#define DRVPCC_PORTC_INDEX       75UL
#define DRVPCC_PORTD_INDEX       76UL
#define DRVPCC_PORTE_INDEX       77UL

#define DRVPCC_PCS_CLOCK_OFF     0x00000000UL
#define DRVPCC_PCS_CLOCK_SOSC    0x01000000UL
#define DRVPCC_PCS_CLOCK_SIRC    0x02000000UL
#define DRVPCC_PCS_CLOCK_FIRC    0x03000000UL
#define DRVPCC_PCS_CLOCK_SPLL    0x06000000UL
#define DRVPCC_PCS_CLOCK_NONE    0x08000000UL

#define DRVPCC_CGC_CLEAR_MASK    0xBFFFFFFFUL
#define DRVPCC_CGC_ENABLE_MASK   0x40000000UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_PCC [DRVPCC_PCC_NB];
} TS_DrvPCC_Registers;

typedef struct
{
   uint32_t S_Index;
   uint32_t S_PCS_Value;
} TS_DrvPCC_PCS_Config;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvPCC_Registers * const C_DrvPCC_Registers;

extern const TS_DrvPCC_PCS_Config C_DrvPCC_PCS_Config [DRVPCC_PCC_USED_NB];


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVPCC_PRIVATE_H */
