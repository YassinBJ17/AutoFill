/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef TMOT_PRIVATE_H
#define TMOT_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */
/* Conversion from voltage to current */
#define CONV_VOLT_TO_CURRENT (float32_t)(59.4)

/* Gain to apply for obtain tmot computed voltage */
#define GAIN_TMOT_VOLT (float32_t)(0.124)

/* The number of the tmot current raw samples to acquire */
#define TMOT_CURRENT_NB_SAMPLES (uint32_t)12

/* Ground SARADC_B offset */
#define SARADC_GND_OFFSET (uint32_t)2048

/* Expected ref 2V5 value */
#define EXPECTED_REF_2V5 (float32_t)2.5

/* ---------- provided types: ----------------------------------------------- */
/* tmot PBIT bit field */
typedef struct
{
   uint32_t s_current_invalid_1: 1;
   uint32_t s_current_invalid_2: 1;
   uint32_t s_spare_29_to_00:   30;
}
ts_tmot_init_fault_word_u_bit;

/* tmot PBIT fault word */
typedef union
{
   uint32_t u_word;                          /* tmot init fault word accessed by 32-bit word */
   ts_tmot_init_fault_word_u_bit u_bit;      /* tmot init fault word accessed bit by bit */
}
tu_tmot_init_fault_word;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* tmot PBIT fault word */
extern tu_tmot_init_fault_word tmot_pbit;

/* -------------------------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0010 */
/* Acquire tmot samples from internal ADC (SARADC_B) */
extern void tmot_acquire_samples(float32_t* p_tmot_computed_volt,     /* out */
                                 float32_t* p_tmot_computed_current); /* out */


#endif /* TMOT_PRIVATE_H */
