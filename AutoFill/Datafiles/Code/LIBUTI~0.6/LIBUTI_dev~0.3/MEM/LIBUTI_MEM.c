#include "LIBUTI_MEM.h"
/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used because can't guess the size of memory to set or check.*/
/* Overflow avoid with for instruction*/
void LIBUTI_MEM_MemSet(
    uint8_t* const Address,
    const uint8_t Value,
    const uint32_t Size
)
{
    uint32_t index;
    for(index=(uint32_t)0;index<Size;index++)
    {
        Address[index] = Value;
    }
}

boolean_t LIBUTI_MEM_MemsNotEqual(
    const uint8_t* const FirstAddress,
    const uint8_t* const SecondAddress,
    const uint32_t Size
)
{
    uint32_t index;
    boolean_t MemsNotEqual;
    MemsNotEqual = FALSE;
    for(index=(uint32_t)0;index<Size;index++)
    {
        if(FirstAddress[index] != SecondAddress[index])
        {
            MemsNotEqual = TRUE;
            break;
        }
    }
    return MemsNotEqual;
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */