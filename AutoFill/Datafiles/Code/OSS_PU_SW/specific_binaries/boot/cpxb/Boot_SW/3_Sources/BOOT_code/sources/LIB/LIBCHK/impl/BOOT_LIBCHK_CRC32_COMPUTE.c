#include "BOOT_LIBCHK_public.h"

 void BOOT_LIBCHK_CRC32_COMPUTE( const uint8_t *p_buf, uint32_t p_size, uint32_t * const p_crc32) {    *p_crc32 = (uint32_t)update_crc32(0xFFFFFFFF, p_buf, p_size); }
