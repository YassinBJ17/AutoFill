#include "LIBUTI_MEM.h"

 boolean_t LIBUTI_MEM_MemsNotEqual(     const uint8_t* const FirstAddress,     const uint8_t* const SecondAddress,     const uint32_t Size ) {     uint32_t index;     boolean_t MemsNotEqual;     MemsNotEqual = FALSE;     for(index=(uint32_t)0;index<Size;index++)     {         if(FirstAddress[index] != SecondAddress[index])         {             MemsNotEqual = TRUE;             break;         }     }     return MemsNotEqual; }
