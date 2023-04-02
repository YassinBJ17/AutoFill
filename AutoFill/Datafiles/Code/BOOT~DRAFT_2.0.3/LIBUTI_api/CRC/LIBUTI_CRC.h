#ifndef _LIBUTI_CRC_
#define _LIBUTI_CRC_

#include "LIBMCP_Types.h"

uint16_t LIBUTI_CRC_ComputeCRC16(
    const uint8_t* const DataAddress,
    const uint32_t DataSize
);
uint16_t LIBUTI_CRC_UpdateCRC16(
    const uint8_t* const DataAddress,
    const uint32_t DataSize,
    const uint16_t BaseCRC16
);
uint32_t LIBUTI_CRC_ComputeCRC32(
    const uint8_t* const DataAddress,
    const uint32_t DataSize
);
uint32_t LIBUTI_CRC_UpdateCRC32(
    const uint8_t* const DataAddress,
    const uint32_t DataSize,
    const uint32_t BaseCRC32
);

#endif