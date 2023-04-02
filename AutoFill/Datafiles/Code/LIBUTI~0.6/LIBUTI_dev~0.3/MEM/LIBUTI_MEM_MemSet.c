#include "LIBUTI_MEM.h"

 void LIBUTI_MEM_MemSet(     uint8_t* const Address,     const uint8_t Value,     const uint32_t Size ) {     uint32_t index;     for(index=(uint32_t)0;index<Size;index++)     {         Address[index] = Value;     } }
