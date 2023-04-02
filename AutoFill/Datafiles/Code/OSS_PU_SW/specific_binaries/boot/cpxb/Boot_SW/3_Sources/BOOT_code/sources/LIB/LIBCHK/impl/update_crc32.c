#include "BOOT_LIBCHK_public.h"

 uint32_t update_crc32(uint32_t crc, const uint8_t *buf, uint32_t len) {    uint8_t n;    const uint8_t *p, *q;     if (!have_crc_table)       make_crc_table();    q = buf + len;    for (p = buf; p < q; p++) {       n = *p;         crc = crc_table[(crc & 0xff) ^ n] ^ (crc >> 8);    }    return crc ^ 0xffffffffL; }
