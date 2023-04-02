/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LIB_CHKSUM_PUBLIC_H
#define LIB_CHKSUM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Compute CRC16 algorithm */
extern void LIB_CHKSUM_CRC_16_COMPUTE(uint8_t  const * const p_InputMsg,
                                      uint32_t   const p_InputMsgLen,
                                      uint16_t * const p_crc16);

extern void LIB_CHKSUM_CRC_16_A665_COMPUTE(uint8_t  const * const p_InputMsg,
                                      uint32_t   const p_InputMsgLen,
                                      uint16_t * const p_crc16);


/* Compute CRC32 algorithm */
extern void LIB_CHKSUM_CRC_32_COMPUTE(  uint32_t         const p_crc_start,
                                        uint8_t  const * const p_buf,
                                        uint32_t         const p_size,
                                        uint32_t       * const p_crc32 );

/* */
extern void LIB_CHKSUM_32_COMPUTE( uint32_t const * const p_buff,
                                   uint32_t const p_buffLen,
                                   uint32_t * const p_chck32);

extern void LIB_CHKSUM_16_COMPUTE( uint8_t const * const p_buff,
                                   uint16_t const p_nb_bytes,
                                   uint16_t * const p_chck16 );

/* */
extern void LIB_CHKSUM_8_COMPUTE( uint8_t  const * const p_buff,
                                   uint32_t const p_buffLen,
                                   uint8_t * const p_chck8);

#endif /* LIB_CHKSUM_PUBLIC_H */
