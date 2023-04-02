/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function computes the CRC-32 of the given memory zone.
 Coming from : https://www.w3.org/TR/2003/REC-PNG-20031110/#D-CRCAppendix
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */
#include "BOOT_LIBCHK_public.h"

/* ---------- internal define constants: ------------------------------------ */


/* ---------- internal types: ----------------------------------------------- */
uint32_t crc_table[256];
uint8_t have_crc_table;

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none for a faster speed */

/* ---------- provided operation bodies: ------------------------------------ */

/* Make the table for a fast CRC. */
void make_crc_table(void){

uint32_t rem;
uint32_t i, j;

/* This check is not thread safe; there is no mutex. */
   /* Calculate CRC table. */
   for (i = 0; i < 256; i++) {
      rem = i;  /* remainder from polynomial division */
      for (j = 0; j < 8; j++) {
         if (rem & 1) {
            rem >>= 1;
            rem ^= 0xedb88320;
         } else
            rem >>= 1;
      }
      crc_table[i] = rem;
   }
   have_crc_table = 1;
}

uint32_t update_crc32(uint32_t crc, const uint8_t *buf, uint32_t len)
{
   uint8_t n;
   const uint8_t *p, *q;

    if (!have_crc_table)
      make_crc_table();

   q = buf + len;
   for (p = buf; p < q; p++) {
      n = *p;  /* Cast to unsigned octet. */
      crc = crc_table[(crc & 0xff) ^ n] ^ (crc >> 8);
   }
   return crc ^ 0xffffffffL;
}

void BOOT_LIBCHK_CRC32_COMPUTE( const uint8_t *p_buf, uint32_t p_size, uint32_t * const p_crc32)
{
   *p_crc32 = (uint32_t)update_crc32(0xFFFFFFFF, p_buf, p_size);
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */

