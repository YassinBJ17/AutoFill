#ifndef BOOT_WDG_REG_PRIVATE_H
#define BOOT_WDG_REG_PRIVATE_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */
#define SWT_IR_CLEAR_VAL ((uint32_t)0x1)
#define SWT_REGS_SIZE (2)

/* ---------- external types: ----------------------------------------------- */

/* ============================================================================
   =============================== Module: SWT ================================
   ============================================================================ */

typedef struct
{
   /* SWT Control Register */
   reg32_t s_CR;

   /* SWT Interrupt Register */
   reg32_t s_IR;
   
   /* Other registers */
   reg32_t s_regs_A[SWT_REGS_SIZE];
   
   /* SWT Service Register */
   reg32_t s_SR;
   
   /* Other registers */
   reg32_t s_regs_B[SWT_REGS_SIZE];
}
ts_WDG_SWT_tag;

#define SWT_KEYS_1 0x0000c520
#define SWT_KEYS_2 0x0000d928

#define SWT_0_BASE_ADDR 0xFC050000UL
#define SWT_1_BASE_ADDR 0xFC054000UL
#define SWT_2_BASE_ADDR 0xFC058000UL
#define SWT_3_BASE_ADDR 0xFC05C000UL

#define SWT_0 (*(ts_WDG_SWT_tag volatile *) SWT_0_BASE_ADDR)
#define SWT_1 (*(ts_WDG_SWT_tag volatile *) SWT_1_BASE_ADDR)
#define SWT_2 (*(ts_WDG_SWT_tag volatile *) SWT_2_BASE_ADDR)
#define SWT_3 (*(ts_WDG_SWT_tag volatile *) SWT_3_BASE_ADDR)
/* SWT */
#define SWT_0_CR             SWT_0.s_CR                    /* SWT Control Register */
#define SWT_0_SR             SWT_0.s_SR                    /* SWT Service Register */
#define SWT_0_IR             SWT_0.s_IR                    /* SWT Interrupt Register */
/* SWT */
#define SWT_1_CR             SWT_1.s_CR                    /* SWT Control Register */
#define SWT_1_SR             SWT_1.s_SR                    /* SWT Service Register */
#define SWT_1_IR             SWT_1.s_IR                    /* SWT Interrupt Register */
/* SWT */
#define SWT_2_CR             SWT_2.s_CR                    /* SWT Control Register */
#define SWT_2_SR             SWT_2.s_SR                    /* SWT Service Register */
#define SWT_2_IR             SWT_2.s_IR                    /* SWT Interrupt Register */
/* SWT */
#define SWT_3_CR             SWT_3.s_CR                    /* SWT Control Register */
#define SWT_3_SR             SWT_3.s_SR                    /* SWT Service Register */
#define SWT_3_IR             SWT_3.s_IR                    /* SWT Interrupt Register */

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/* none */

/* ---------- external constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */

#endif
