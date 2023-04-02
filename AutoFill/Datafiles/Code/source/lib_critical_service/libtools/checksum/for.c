#include "libtools/checksum/LIB_CHKSUM_public.h"

    for(v_i = 0UL ; v_i < p_size ; v_i++)    {       v_table_index = ((v_crc_result >> 24UL ) ^ (*c_pt_area_start) ) & 0xFFUL;       v_crc_result = (v_crc_result << 8UL ) ^ c_CHKSUM_CRC_32_CODE_tab[ v_table_index ];       c_pt_area_start++;    }
