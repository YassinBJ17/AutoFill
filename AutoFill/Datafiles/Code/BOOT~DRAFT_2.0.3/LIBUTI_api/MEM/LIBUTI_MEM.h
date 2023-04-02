#ifndef _LIBUTI_MEM_
#define _LIBUTI_MEM_

#include "LIBMCP_Types.h"

void LIBUTI_MEM_MemSet(
    uint8_t* const Address,
    const uint8_t Value,
    const uint32_t Size
);

boolean_t LIBUTI_MEM_MemsNotEqual(
    const uint8_t* const FirstAddress,
    const uint8_t* const SecondAddress,
    const uint32_t Size
);

#endif