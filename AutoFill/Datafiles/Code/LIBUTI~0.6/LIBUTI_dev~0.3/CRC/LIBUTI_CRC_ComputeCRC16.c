#include "LIBUTI_CRC.h"

 uint16_t LIBUTI_CRC_ComputeCRC16(const uint8_t* const DataAddress, const uint32_t DataSize) {    uint16_t v_ret;    v_ret = LIBUTI_CRC_UpdateCRC16(DataAddress, DataSize, C_CRC16_INIT_VALUE);     return ( v_ret ); }
