#ifndef BOOT_LIBMEM_PUBLIC_H
#define BOOT_LIBMEM_PUBLIC_H
/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "CMN_TYPES_common.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */
/* */

extern void BOOT_LIBMEM_SET( uint8_t const * p_buffer_pt,
                             uint32_t  const p_init_value,
                             uint32_t const p_length); /* p_length in byte */
extern void BOOT_LIBMEM_SET32 ( uint8_t * const p_buffer ,
                            uint32_t const p_init_value ,
                            uint32_t const p_length ) ; /* p_length in byte */
extern void BOOT_LIBMEM_CPY( void const * destination_pt,
                             void const * const source_pt,
                             uint32_t const length);
extern te_CMN_FLAG_QUESTION BOOT_LIBMEM_NOTEQUAL(
   const uint8_t * const FirstAddress,
   const uint8_t * const SecondAddress,
   const uint32_t        Size
);
#endif /* BOOT_LIBMEM_PUBLIC_H */
