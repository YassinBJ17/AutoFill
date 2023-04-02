#include "LIBUTI_COMMON.h"

/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointers. Poiter used as buffer with files infos in it.*/
/*Can't use anrray because size is unknow.*/
/*Overflow avoid by for instructions where index is compare to a max value*/

void LIBUTI_CMN_ParseLUD
(
/*IN*/
    const uint8_t* const LUD_Address,
    const uint32_t MaxNumberOfSecondaryLoads,
/*OUT*/
    uint32_t* const NumberOfSecondaryLoads,
    TS_SecondaryLoadInfo* SecondaryLoadsInfo,
    boolean_t* const OutOfOperationalConditionLUD
)
{
    uint32_t index;
    TS_SecondaryLoadInfo* SecondaryLoadInfoIterator;
    *OutOfOperationalConditionLUD = FALSE;
    *NumberOfSecondaryLoads = *((uint32_t*)((uint32_t)LUD_Address + (uint32_t)4)); /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
    if(*NumberOfSecondaryLoads > MaxNumberOfSecondaryLoads)
    {
        *OutOfOperationalConditionLUD = TRUE;
    }
    else
    {
        SecondaryLoadInfoIterator = (TS_SecondaryLoadInfo*)((uint32_t)LUD_Address + (uint32_t)8);/*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
        for(index=(uint32_t)0;index<*NumberOfSecondaryLoads;index++)
        {
            SecondaryLoadsInfo[index] = SecondaryLoadInfoIterator[index];
        }
    }
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */