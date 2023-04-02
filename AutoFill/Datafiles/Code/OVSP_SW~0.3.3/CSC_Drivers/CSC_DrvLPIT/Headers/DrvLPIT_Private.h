/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVLPIT_PRIVATE_H
#define DRVLPIT_PRIVATE_H

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include required interface: ----------------------------------- */
/* None */

/* ---------- provided define constants: ------------------------------------ */

/* LPIT - Size of Registers Arrays */
#define DRVLPIT_TCTRL_NB                   4UL
#define DRVLPIT_RESERVED                   4UL

/* MCR Bit Fields */
#define DRVLPIT_MCR_M_CEN_MASK             1UL
#define DRVLPIT_MCR_M_CEN_SHIFT            0UL

#define DRVLPIT_MCR_SW_RST_MASK            2UL
#define DRVLPIT_MCR_SW_RST_SHIFT           1UL

#define DRVLPIT_MCR_DOZE_EN_MASK           4UL
#define DRVLPIT_MCR_DOZE_EN_SHIFT          2UL

#define DRVLPIT_MCR_DBG_EN_MASK            8UL
#define DRVLPIT_MCR_DBG_EN_SHIFT           3UL

/* MSR Bit Fields */
#define DRVLPIT_MSR_TIF_MASK               0x0000000FUL
#define DRVLPIT_MSR_TIF_0_MASK             1UL
#define DRVLPIT_MSR_TIF_0_SHIFT            0UL

#define DRVLPIT_MSR_TIF_1_MASK             2UL
#define DRVLPIT_MSR_TIF_1_SHIFT            1UL

/* MIER Bit Fields */
#define DRVLPIT_MIER_TIE_0_MASK            1UL
#define DRVLPIT_MIER_TIE_0_SHIFT           0UL

#define DRVLPIT_MIER_TIE_1_MASK            2UL
#define DRVLPIT_MIER_TIE_1_SHIFT           1UL

/* TVAL Bit Fields */
#define DRVLPIT_TVAL_TMR_CONFIG            0xFFFFFFFFUL

/* TCTRL Bit Fields */
#define DRVLPIT_TCTRL_T_EN_MASK            1UL
#define DRVLPIT_TCTRL_T_EN_SHIFT           0UL

#define DRVLPIT_TCTRL_CHAIN_MASK           2UL
#define DRVLPIT_TCTRL_CHAIN_SHIFT          1UL

#define DRVLPIT_TCTRL_TRG_SEL_MASK         0xF000000UL
#define DRVLPIT_TCTRL_TRG_SEL_SHIFT        24UL

#define DRVLPIT_DIV_FACTOR_375             375UL
#define DRVLPIT_DIV_FACTOR_500             500UL
#define DRVLPIT_DIV_FACTOR_800             800UL
#define DRVLPIT_DIV_FACTOR_1120            1120UL

#define DRVLPIT_WAIT_CYCLES_NB             4UL


#define DRVLPIT_MCR_CONFIG              0x00000001UL
#define DRVLPIT_TCTRL0_CONFIG           0x01000000UL

#define DRVLPIT_TCTRL1_CONFIG           0x01000000UL

#define DRVLPIT_TVAL2_CONFIG            0xFFFFFFFFUL
#define DRVLPIT_TCTRL2_CONFIG           0x00000001UL

#define DRVLPIT_TVAL3_CONFIG            0xFFFFFFFFUL
#define DRVLPIT_TCTRL3_CONFIG           0x00000003UL


/* Peripheral LPIT base address */
#define DRVLPIT_LPIT_BASE_ADDRESS          0x40037000UL

/* ---------- provided types: ----------------------------------------------- */
/* LPIT - Register Layout Typedef */
typedef struct
{
    uint32_t S_VERID;      /* Version ID Register, offset: 0x0 */
    uint32_t S_PARAM;      /* Parameter Register, offset: 0x4 */
    uint32_t S_MCR;        /* Module Control Register, offset: 0x8 */
    uint32_t S_MSR;        /* Module Status Register, offset: 0xC */
    uint32_t S_MIER;       /* Module Interrupt Enable Register, offset: 0x10 */
    uint32_t S_SETTEN;     /* Set Timer Enable Register, offset: 0x14 */
    uint32_t S_CLRTEN;     /* Clear Timer Enable Register, offset: 0x18 */
    uint8_t S_RESERVED_A[DRVLPIT_RESERVED];
    struct
    {                     /* offset: 0x20, array step: 0x10 */
        uint32_t S_TVAL;    /* Timer Value Register, array offset: 0x20, array step: 0x10 */
        uint32_t S_CVAL;    /* Current Timer Value, array offset: 0x24, array step: 0x10 */
        uint32_t S_TCTRL;   /* Timer Control Register, array offset: 0x28, array step: 0x10 */
        uint8_t S_RESERVED_B[DRVLPIT_RESERVED];
    }
    S_TVAL_CVAL_TCTRL[DRVLPIT_TCTRL_NB];
} TS_DrvLPIT_Registers;

/* ---------- provided constants: ------------------------------------------- */

/* Peripheral LPIT base pointer */
extern TS_DrvLPIT_Registers * const DrvLPIT_LPIT_Registers;

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operations: ------------------------------------------ */
/* None */

#endif /* DRVLPIT_PRIVATE_H */


