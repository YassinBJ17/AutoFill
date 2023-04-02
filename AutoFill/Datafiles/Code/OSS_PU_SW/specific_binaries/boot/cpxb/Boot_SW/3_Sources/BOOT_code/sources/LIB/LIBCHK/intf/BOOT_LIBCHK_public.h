#ifndef BOOT_LIBCHKSUM_PUBLIC_H
#define BOOT_LIBCHKSUM_PUBLIC_H
/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "CMN_CARTRIDGE_public.h"
/* ---------- provided define constants: ------------------------------------ */
/* none */

/* ---------- provided types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* */

/* @param p_endMemoryArea: this parameter is used to check that the end code is in bound. */
extern te_CMN_FLAG_VALIDITY BOOT_LIBCHK_CARTRIDGE( const ts_SAFRAN_HEADER * const p_cartridge,
                                                 uint32_t const p_startMemoryArea,
                                                 uint32_t const p_endMemoryArea ) ;

/* Compute CRC16 algorithm */
extern void BOOT_LIBCHK_CRC16_COMPUTE( uint16_t         const p_crc_start,
                                       uint8_t  const * const p_buf,
                                       uint32_t         const p_size,
                                       uint16_t       * const p_crc16 );
                                       
/* Compute CRC32 algorithm */
extern void BOOT_LIBCHK_CRC32_COMPUTE( const uint8_t *p_buf,
                                       uint32_t p_size,
                                       uint32_t * const p_crc32 );

#endif /* BOOT_LIBCHKSUM_PUBLIC_H */
