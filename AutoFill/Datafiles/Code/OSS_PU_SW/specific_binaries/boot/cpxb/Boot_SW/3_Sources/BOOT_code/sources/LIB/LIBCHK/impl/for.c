#include "BOOT_LIBCHK_public.h"

    for ( DataIndex = 0; DataIndex < p_size; DataIndex++ )    {       CRC_TableIndex = p_buf[DataIndex] ^ (CRC_Value >> 8);       CRC_Value = (uint16_t)((CRC_Value << 8) ^ c_CHKSUM_CRC_16_CODE_tab[CRC_TableIndex]);    }
