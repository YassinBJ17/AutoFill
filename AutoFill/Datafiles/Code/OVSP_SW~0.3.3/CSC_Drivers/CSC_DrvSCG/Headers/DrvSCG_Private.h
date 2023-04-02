/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVSCG_PRIVATE_H
#define DRVSCG_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVSCG_SCG_ADDRESS             0x40064000UL

#define DRVADC_SOSCCSR_CONFIG          0x04000000UL
#define DRVADC_SOSCDIV_CONFIG          0x00000101UL
#define DRVADC_SOSCCFG_CONFIG          0x00000034UL

#define DRVSCG_SOSCCSR_LOCK_MASK       0x00800000UL
#define DRVSCG_SOSCCSR_SOSCLPEN_MASK   0x00000004UL
#define DRVSCG_SOSCCSR_SOSCEN_MASK     0x00000001UL
#define DRVSCG_SOSCCSR_SOSCVLD_MASK    0x01000000UL

#define DRVADC_CLKOUTCNFG_CONFIG       0x06000000UL

#define DRVADC_SPLLCSR_CONFIG          0x04000000UL
#define DRVADC_SPLLDIV_CONFIG          0x00000202UL
#define DRVADC_SPLLCFG_CONFIG          0x00020200UL

#define DRVSCG_SPLLCSR_LOCK_MASK       0x00800000UL
#define DRVSCG_SPLLCSR_SPLLEN_MASK     0x00000001UL
#define DRVSCG_SPLLCSR_SPLLVLD_MASK    0x01000000UL

#define DRVADC_RCCR_CONFIG                 0x06000013UL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_VERID;
   uint32_t S_PARAM;
   uint32_t S_SCG_Reserved_1 [2];
   uint32_t S_CSR;
   uint32_t S_RCCR;
   uint32_t S_VCCR;
   uint32_t S_HCCR;
   uint32_t S_CLKOUTCNFG;
   uint32_t S_SCG_Reserved_2 [55];
   uint32_t S_SOSCCSR;
   uint32_t S_SOSCDIV;
   uint32_t S_SOSCCFG;
   uint32_t S_SCG_Reserved_3 [61];
   uint32_t S_SIRCCSR;
   uint32_t S_SIRCDIV;
   uint32_t S_SIRCCFG;
   uint32_t S_SCG_Reserved_4 [61];
   uint32_t S_FIRCCSR;
   uint32_t S_FIRCDIV;
   uint32_t S_FIRCCFG;
   uint32_t S_SCG_Reserved_5 [189];
   uint32_t S_SPLLCSR;
   uint32_t S_SPLLDIV;
   uint32_t S_SPLLCFG;
} TS_DrvSCG_Registers;


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVSCG_PRIVATE_H */
