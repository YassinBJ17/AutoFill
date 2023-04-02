/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVECC_PRIVATE_H
#define DRVECC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVECC_EIM_ADDRESS             0x40019000UL
#define DRVECC_ERM_ADDRESS             0x40018000UL

#define DRVECC_SRAM_L_ADDRESS          0x1FFFFFFCUL
#define DRVECC_SRAM_U_ADDRESS          0x20000000UL

#define DRVECC_EIM_EIMCR_DISABLE       0x00000000UL
#define DRVECC_EIM_EIMCR_ENABLE        0x00000001UL

#define DRVECC_EIM_EICHEN_DISABLE      0x00000000UL
#define DRVECC_EIM_EICHEN_ENABLE       0xC0000000UL

#define DRVECC_EIM_EICHDN_NO_ERROR     0x00000000UL
#define DRVECC_EIM_EICHD0_SING_ERROR   0x00000002UL
#define DRVECC_EIM_EICHD1_MULT_ERROR   0x00000060UL

#define DRVECC_ERM_CR0_VALUE           0xCC000000UL

#define DRVECC_ERM_CR0_DISABLE_S       0x77FFFFFFUL
#define DRVECC_ERM_CR0_DISABLE_M       0xBBFFFFFFUL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_EIMCR;
   uint32_t S_EICHEN;
   uint32_t S_EIM_Reserved_1 [62];
   uint32_t S_EICHD0_WORD0;
   uint32_t S_EICHD0_WORD1;
   uint32_t S_EIM_Reserved_2 [62];
   uint32_t S_EICHD1_WORD0;
   uint32_t S_EICHD1_WORD1;
} TS_DrvECC_EIM_Registers;

typedef struct
{
   uint32_t S_CR0;
   uint32_t S_ERM_Reserved_1 [3];
   uint32_t S_SR0;
   uint32_t S_ERM_Reserved_2 [59];
   uint32_t S_EAR0;
   uint32_t S_ERM_Reserved_3 [3];
   uint32_t S_EAR1;
} TS_DrvECC_ERM_Registers;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvECC_EIM_Registers * const C_DrvECC_EIM_Registers;
extern TS_DrvECC_ERM_Registers * const C_DrvECC_ERM_Registers;


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVECC_PRIVATE_H */
