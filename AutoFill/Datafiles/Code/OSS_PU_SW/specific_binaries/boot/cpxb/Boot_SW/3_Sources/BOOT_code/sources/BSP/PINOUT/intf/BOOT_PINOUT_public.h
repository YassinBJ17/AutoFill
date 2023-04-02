#ifndef BOOT_PINOUT_public_H
#define BOOT_PINOUT_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
/* none */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */
/* none */
#define SIUL2_BASE_ADDR 0xFFFC0000UL
#define SIUL2 (*(ts_SIUL2_tag volatile *) SIUL2_BASE_ADDR)

#define SIUL2_REG_RESERVED0TO7_SIZE  (4)
#define SIUL2_REG_RESERVED8_SIZE  (60)
#define SIUL2_REG_RESERVED9_SIZE  (316)
#define SIUL2_REG_IFMCR_SIZE (32)
#define SIUL2_REG_MSCR_IO_SIZE  (512)
#define SIUL2_REG_MSCR_MUX_SIZE  (512)
#define SIUL2_REG_RESERVED10_SIZE  (192)
#define SIUL2_REG_GPD_SIZE (512)
#define SIUL2_REG_PGPD_SIZE (32)

/* ---------- external types: ----------------------------------------------- */

/* */
typedef struct
{
   uint32_t s_Register;
   uint32_t s_Value;
}
ts_PAD_ELT_CFG;

/* */
#define PAD_IO_CFG_MAX (512UL)

/* */
typedef struct
{
   ts_PAD_ELT_CFG s_conf_pad_io_elt[PAD_IO_CFG_MAX];
}
ts_PAD_IO_CFG;

/* */
#define PAD_MUX_CFG_MAX (421UL)

/* */
typedef struct
{
   ts_PAD_ELT_CFG s_conf_pad_mux_elt[PAD_MUX_CFG_MAX];
}
ts_PAD_MUX_CFG;

/* ============================================================================
   =============================== Module: SIUL2 ==============================
   ============================================================================ */

typedef struct
{
   reg8_t s_SIUL2_reserved0[SIUL2_REG_RESERVED0TO7_SIZE];
   /* MCU ID Register #1 */
   reg32_t s_MIDR1;

   /* MCU ID Register #2 */
   reg32_t s_MIDR2;

   reg8_t s_SIUL2_reserved1[SIUL2_REG_RESERVED0TO7_SIZE];

   /* DMA/Interrupt Status Flag Register0 */
   reg32_t s_DISR0;

   reg8_t s_SIUL2_reserved2[SIUL2_REG_RESERVED0TO7_SIZE];
   /* DMA/Interrupt Request Enable Register0 */
   reg32_t s_DIRER0;

   reg8_t s_SIUL2_reserved3[SIUL2_REG_RESERVED0TO7_SIZE];
   /* DMA/Interrupt Request Select Register0 */
   reg32_t s_DIRSR0;

   reg8_t s_SIUL2_reserved4[SIUL2_REG_RESERVED0TO7_SIZE];

   /* Interrupt Rising-Edge Event Enable Register0 */
   reg32_t s_IREER0;

   reg8_t s_SIUL2_reserved5[SIUL2_REG_RESERVED0TO7_SIZE];
   /* Interrupt Falling-Edge Event Enable Register0 */
   reg32_t s_IFEER0;

   reg8_t s_SIUL2_reserved6[SIUL2_REG_RESERVED0TO7_SIZE];
   /* Interrupt Filter Enable Register0 */
   reg32_t s_IFER0;

   reg8_t s_SIUL2_reserved7[SIUL2_REG_RESERVED0TO7_SIZE];
   /* Interrupt Filter Maximum Counter Register */
   reg32_t s_IFMCR[SIUL2_REG_IFMCR_SIZE];

   /* Interrupt Filter Clock Prescaler */
   reg32_t s_IFCPR;

   reg8_t s_SIUL2_reserved8[SIUL2_REG_RESERVED8_SIZE];
   /* SoC Configuration Register0 */
   reg32_t s_SCR0;

   reg8_t s_SIUL2_reserved9[SIUL2_REG_RESERVED9_SIZE];
   /* I/O Pin Multiplexed Signal Configuration Registers */
   reg32_t s_MSCR_IO[SIUL2_REG_MSCR_IO_SIZE];

   /* Multiplexed Signal Configuration Register for Multiplexed Input Selection */
   reg32_t s_MSCR_MUX[SIUL2_REG_MSCR_MUX_SIZE];

   reg8_t s_SIUL2_reserved10[SIUL2_REG_RESERVED10_SIZE];
   /* GPIO Pad Data Out Register */
   reg8_t s_GPDO[SIUL2_REG_GPD_SIZE];

   /* GPIO Pad Data In Register */
   reg8_t s_GPDI[SIUL2_REG_GPD_SIZE];

   /* Parallel GPIO Pad Data Out Register */
   reg16_t s_PGPDO[SIUL2_REG_PGPD_SIZE];

   /* Parallel GPIO Pad Data In Register */
   reg16_t s_PGPDI[SIUL2_REG_PGPD_SIZE];

   /* Masked Parallel GPIO Pad Data Out Register */
   reg32_t s_MPGPDO[SIUL2_REG_PGPD_SIZE];
}
ts_SIUL2_tag;

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/* none */ 

/* ---------- external constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* */
extern void BOOT_PINOUT_INIT( void );



#endif /* BOOT_PINOUT_public_H */
