/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef PAN3_PUBLIC_H
#define PAN3_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Bits field of PAN3 fault word */
typedef struct
{
   uint32_t s_spare_28_to_31 :  4; /* 28 to 31: Spare */
   uint32_t s_commanded      :  1; /* 27: Is PAN3 on */
   uint32_t s_spare_02_to_26 : 25; /* 22 to 26: Spare */
   uint32_t s_unavailable    :  1; /* 01: Is PAN3 unavailable ? */
   int32_t s_spare_0         :  1; /* 0 : Spare */
}
ts_pan3_fault_word_u_bit;

/* PAN3 fault word */
typedef union
{
   uint32_t                 u_word; /* PAN3 fault word accessed by 32-bit word */
   ts_pan3_fault_word_u_bit u_bit;  /* PAN3 fault word accessed bit by bit */
}
tu_pan3_fault_word;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/*  */
extern tu_pan3_fault_word v_pan3_status_word;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PAN3-0010 */
/* Manage PAN3 */
extern void pan3_periodic(const boolean_t channel_is_a);


#endif /* PAN3_PUBLIC_H */

