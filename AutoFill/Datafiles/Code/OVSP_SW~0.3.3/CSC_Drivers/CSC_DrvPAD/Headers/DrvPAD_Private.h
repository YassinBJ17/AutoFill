/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVPAD_PRIVATE_H
#define DRVPAD_PRIVATE_H

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include required interface: ----------------------------------- */
/* None */

/* ---------- provided define constants: ------------------------------------ */
#define DRVPAD_PAD_ADDRESS   0x40049000UL

#define DRVPAD_UINT32_0                0UL

/* Pins configuration */
#define DRVPAD_PIN_USED_OFFSET         28UL
#define DRVPAD_PIN_USED                0x00000000UL << DRVPAD_PIN_USED_OFFSET
#define DRVPAD_PIN_NOT_USED            0x0000000FUL << DRVPAD_PIN_USED_OFFSET

#define DRVPAD_ISF_OFFSET              24UL
#define DRVPAD_ISF_DETECTED            0x00000001UL << DRVPAD_ISF_OFFSET
#define DRVPAD_ISF_NOT_DETECTED        0x00000000UL << DRVPAD_ISF_OFFSET

#define DRVPAD_IRQC_OFFSET             16UL
#define DRVPAD_IRQC_DISABLE            0x00000000UL << DRVPAD_IRQC_OFFSET
#define DRVPAD_IRQC_OTHER(irqc)        (uint32_t(irqc) << DRVPAD_IRQC_OFFSET)

#define DRVPAD_LK_OFFSET               15UL
#define DRVPAD_LK_LOCKED               0x00000001UL << DRVPAD_LK_OFFSET
#define DRVPAD_LK_NOT_LOCKED           0x00000000UL << DRVPAD_LK_OFFSET

#define DRVPAD_MUX_OFFSET              8UL

#define DRVPAD_MUX_PIN_DIS_ANAL        0x00000000UL << DRVPAD_MUX_OFFSET
#define DRVPAD_MUX_GPIO                0x00000001UL << DRVPAD_MUX_OFFSET
#define DRVPAD_MUX_ALTER_2             0x00000002UL << DRVPAD_MUX_OFFSET
#define DRVPAD_MUX_ALTER_3             0x00000003UL << DRVPAD_MUX_OFFSET
#define DRVPAD_MUX_ALTER_4             0x00000004UL << DRVPAD_MUX_OFFSET
#define DRVPAD_MUX_ALTER_5             0x00000005UL << DRVPAD_MUX_OFFSET
#define DRVPAD_MUX_ALTER_6             0x00000006UL << DRVPAD_MUX_OFFSET
#define DRVPAD_MUX_ALTER_7             0x00000007UL << DRVPAD_MUX_OFFSET

#define DRVPAD_DSE_OFFSET              6UL
#define DRVPAD_DSE_LOW_DRIVE           0x00000000UL << DRVPAD_DSE_OFFSET
#define DRVPAD_DSE_HIGH_DRIVE          0x00000001UL << DRVPAD_DSE_OFFSET

#define DRVPAD_PFE_OFFSET              4UL
#define DRVPAD_PFE_ENABLED             0x00000001UL << DRVPAD_PFE_OFFSET
#define DRVPAD_PFE_DISABLED            0x00000000UL << DRVPAD_PFE_OFFSET

#define DRVPAD_PE_OFFSET               1UL
#define DRVPAD_PE_ENABLED              0x00000001UL << DRVPAD_PE_OFFSET
#define DRVPAD_PE_NOT_ENABLED          0x00000000UL << DRVPAD_PE_OFFSET

#define DRVPAD_PS_OFFSET               0UL
#define DRVPAD_PS_PULL_UP              0x00000001UL << DRVPAD_PS_OFFSET
#define DRVPAD_PS_PULL_DOWN            0x00000000UL << DRVPAD_PS_OFFSET


/* 32 for S32K144 */
#define DRVPAD_MAX_PINS_NB             (uint32_t)(32)   /* Not for port E */
#define DRVPAD_DEF_PINS_NB             (uint32_t)(18)   /* Not for port E */
/* Number of ports */
#define DRVPAD_MAX_PORTS_NB            (uint32_t)(5)


/* ---------- provided types: ----------------------------------------------- */

typedef struct
{
   uint32_t PCR[DRVPAD_MAX_PINS_NB];  /* Pin Control Register n           */
   uint32_t GPCLR;                            /* Global Pin Control Low Register  */
   uint32_t GPCHR;                            /* Global Pin Control High Register */
   uint32_t RESERVED_0[6];
   uint32_t ISFR;                             /* Interrupt Status Flag Register   */
   uint32_t RESERVED_1[7];
   uint32_t DFER;                             /* Digital Filter Enable Register   */
   uint32_t DFCR;                             /* Digital Filter Clock Register    */
   uint32_t DFWR;                             /* Digital Filter Width Register    */
   uint32_t RESERVED_2[973];
} ts_DrvPAD_Registers;

/* -------------------------------------------------------------------------- */

typedef struct
{
   /* Port : A, B, C, D & E */
   ts_DrvPAD_Registers Port[DRVPAD_MAX_PORTS_NB];
} ts_DrvPAD_PortCtrl;


/* ---------- provided constants: ------------------------------------------- */
/* Controller register mapping */
extern ts_DrvPAD_PortCtrl * const C_DrvPAD_PortCtrl;

/* Register mapping */
extern ts_DrvPAD_Registers * const PAD_Registers[DRVPAD_MAX_PORTS_NB];

/* Configuration data */
extern const uint32_t C_DrvPAD_HS_Config[DRVPAD_MAX_PORTS_NB][DRVPAD_MAX_PINS_NB];
extern const uint32_t C_DrvPAD_LS_Config[DRVPAD_MAX_PORTS_NB][DRVPAD_MAX_PINS_NB];


/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operations: ------------------------------------------ */
/* None */

#endif /* PAD_PRIVATE_H */


