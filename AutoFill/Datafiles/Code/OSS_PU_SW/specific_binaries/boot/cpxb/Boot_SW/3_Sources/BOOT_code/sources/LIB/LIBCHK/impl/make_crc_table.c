#include "BOOT_LIBCHK_public.h"

 void make_crc_table(void){ uint32_t rem; uint32_t i, j;    for (i = 0; i < 256; i++) {       rem = i;         for (j = 0; j < 8; j++) {          if (rem & 1) {             rem >>= 1;             rem ^= 0xedb88320;          } else             rem >>= 1;       }       crc_table[i] = rem;    }    have_crc_table = 1; }
