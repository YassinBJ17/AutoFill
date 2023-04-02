/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LIB_MEM_PUBLIC_H
#define LIB_MEM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */

extern int32_t LIB_MEM_CMP ( int8_t const * const p_mem1 ,
                             int8_t const * const p_mem2 ,
                             uint32_t const p_length ) ;


extern void LIB_MEM_CPY ( int8_t * const p_destination ,
                          int8_t const * const p_source ,
                          uint32_t const p_length ) ; /* p_length in byte */


extern void LIB_MEM_MOVE ( int8_t * const p_destination ,
                           int8_t const * const p_source ,
                           uint32_t const p_length ) ; /* p_length in byte */


extern void LIB_MEM_SET ( int8_t * const p_buffer ,
                          int8_t const p_init_value ,
                          uint32_t const p_length ) ; /* p_length in byte */


extern void LIB_MEM_SET32 ( int8_t * const p_buffer ,
                            uint32_t const p_init_value ,
                            uint32_t const p_length ) ; /* p_length in byte */

#endif /* LIB_MEM_PUBLIC_H */
