/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SMOT_PUBLIC_H
#define SMOT_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* smot PBIT bit field */
typedef struct
{
   uint32_t s_position_invalid_1: 1;  /*Bit 31 : Is smot position is at its default state at initialization ? */
   uint32_t s_position_invalid_2: 1;  /*Bit 30 : Is smot position is at its default state after the OSS_PU cmd ? */
   uint32_t s_spare_29_to_00:    30;  /*Bit 29 to 00 : Spare */
}
ts_smot_init_fault_word_u_bit;

/* smot PBIT fault word */
typedef union
{
   uint32_t u_word;                          /* smot init fault word accessed by 32-bit word */
   ts_smot_init_fault_word_u_bit u_bit;      /* smot init fault word accessed bit by bit */
}
tu_smot_init_fault_word;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* smot PBIT fault word */
extern tu_smot_init_fault_word smot_pbit;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0030 */
/* Implements REQ_FADEX_OS_SRD-TMOT-0040 */
/* Smot initialization function */
extern void smot_init(void);

/* Implements REQ_FADEX_OS_SRD-TMOT-0010 */
/* Smot periodic function */
extern void smot_periodic(void);


#endif /* SMOT_PUBLIC_H */
