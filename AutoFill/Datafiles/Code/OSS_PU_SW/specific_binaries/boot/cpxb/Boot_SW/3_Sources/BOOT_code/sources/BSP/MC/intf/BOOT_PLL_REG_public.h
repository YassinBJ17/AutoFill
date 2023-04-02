#ifndef BOOT_PLL_REG_private_H
#define BOOT_PLL_REG_private_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* Base address of PLLDIG interface */
#define PLLDIG_BASE_ADDR (0xFFFB0100)

/* */
#define PLLDIG_RSRVD_A_SIZE (5)

/* Access masks to PLL0DV and PLL1DV registers */
#define PLLDIG_PLL0DV_MSK (0x87C08F80UL)
#define PLLDIG_PLL1DV_MSK (0xFFC0FF80UL)

/* Clear LOLF and EXTPDF status bits for s_PLLDIG_PLL0SR register */
#define PLLDIG_PLL0SR_CLR_VAL  (0x00000088UL)
/* Clear LOLF status bit for s_PLLDIG_PLL0SR register */
#define PLLDIG_PLL0SR_LOLF_CLR (0x00000008UL)
/* Clear LOLF and EXTPDF status bits for s_PLLDIG_PLL1SR register */
#define PLLDIG_PLL1SR_CLR_VAL  (0x00000088UL)
/* Clear LOLF status bit for s_PLLDIG_PLL1SR register */
#define PLLDIG_PLL1SR_LOLF_CLR (0x00000008UL)


/* PLLDIG_PLL0DV configuration */
/* RFDPHI1 = 8, PLL0_DIV_RFDPHI=1, PLL0_DIV_PREDIV=3, PLL0_DIV_MFD=30 */
/* configuration carte Module v2 */
#define PLLDIG_PLL0DV_VAL (0x40014040UL)

/* PLLDIG_PLL1DV configuration */
/* PLL1_REF = PLL0_PHI1 = 50MHz, PLL1_PHI = 600MHz, PLL1_VCO = 1200MHz */
/* PLL1_DIV_RFDPHI = 1, PLL0_DIV_RFD_MFD = 24 */
#define PLLDIG_PLL1DV_VAL (0x00010018UL)

/* ---------- internal types: ----------------------------------------------- */


/************/
/*  PLLDIG  */
/************/

/* */
typedef struct
{
   reg32_t s_PLLDIG_PLL0CR;
   reg32_t s_PLLDIG_PLL0SR;
   reg32_t s_PLLDIG_PLL0DV;
   reg32_t s_PLLDIG_rsvdA[PLLDIG_RSRVD_A_SIZE];
   reg32_t s_PLLDIG_PLL1CR;
   reg32_t s_PLLDIG_PLL1SR;
   reg32_t s_PLLDIG_PLL1DV;
   reg32_t s_PLLDIG_PLL1FM;
   reg32_t s_PLLDIG_PLL1FD;
}
ts_PLLDIG_REG;

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal datas: ----------------------------------------------- */
/* none */ 

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* none */
#define PLLDIG_REGS   (*(ts_PLLDIG_REG volatile * ) PLLDIG_BASE_ADDR)

#endif /* BOOT_PLL_REG_private_H */
