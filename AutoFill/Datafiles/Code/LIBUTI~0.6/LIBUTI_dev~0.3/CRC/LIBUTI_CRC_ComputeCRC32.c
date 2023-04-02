#include "LIBUTI_CRC.h"

 uint32_t LIBUTI_CRC_ComputeCRC32(const uint8_t* const DataAddress, const uint32_t DataSize) {    uint32_t CRC_Value;    uint32_t v_ret;    CRC_Value =  (C_CRC32_INIT_VALUE ^ ((uint32_t) 0xFFFFFFFF));    v_ret = LIBUTI_CRC_UpdateCRC32(DataAddress, DataSize, CRC_Value);     return ( v_ret ); }
