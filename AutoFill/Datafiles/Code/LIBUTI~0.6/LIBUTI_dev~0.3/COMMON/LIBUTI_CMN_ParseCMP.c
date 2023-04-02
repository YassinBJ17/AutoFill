#include "LIBUTI_COMMON.h"

typedef struct{
    uint16_t CMP_Size;
    uint16_t CMP_Version;
    uint8_t Identifier[C_LOAD_NAME_MAX_LENGTH];
    uint8_t AmendmentInformation[C_AMENDMENT_INFO_MAX_LENGTH];
    uint32_t Destination;
    uint32_t LoadType;
    uint32_t OnBoardRunningLoad;
    uint32_t NumberOfCompatibilityCriteria;
}__attribute__((packed)) TS_CMP_FileConstantSizeFirstFields;

/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointers. Poiter used as buffer with files infos in it.*/
/*Can't use anrray because size is unknow.*/
/*Overflow avoid by for instructions where index is compare to a max value*/

void LIBUTI_CMN_ParseCMP
(
/*IN*/
    const uint8_t* const CMP_Address,
    const uint32_t MaxNumberOfCompatibilityRules,
/*OUT*/
    uint8_t* const LoadName,
    uint32_t* const NumberOfCompatibilityRules,
    TS_CompatibilityRule* const CompatibilityRules,
    boolean_t* const LoadLoadedByBoot,
    boolean_t* const LoadCheckedByBootInFlash,
    uint8_t* const AmendmentInfo,
    uint32_t* const Destination,
    uint32_t* const LoadType,
    boolean_t* const OutOfOperationalConditionCMP
)
{
    uint32_t index;
    TS_CMP_FileConstantSizeFirstFields* CMP_FileConstantSizeFirstFields;
    TS_CompatibilityRule* CompatibilityRulesIterator;
    *OutOfOperationalConditionCMP = FALSE;
    *LoadLoadedByBoot = FALSE;
    *LoadCheckedByBootInFlash = FALSE;
    CMP_FileConstantSizeFirstFields = ((TS_CMP_FileConstantSizeFirstFields*)CMP_Address); /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion from generic ptr to ptr to specific structure */
    for(index=((uint32_t) 0);index<((uint32_t) C_LOAD_NAME_MAX_LENGTH);index++)
    {
        LoadName[index] = (CMP_FileConstantSizeFirstFields->Identifier)[index];
    }
    *NumberOfCompatibilityRules = CMP_FileConstantSizeFirstFields->NumberOfCompatibilityCriteria;
    if(*NumberOfCompatibilityRules > MaxNumberOfCompatibilityRules)
    {
        *OutOfOperationalConditionCMP = TRUE;
        return;
    }
    CompatibilityRulesIterator = (TS_CompatibilityRule*)
        ((uint32_t)CMP_Address + (uint32_t)sizeof(TS_CMP_FileConstantSizeFirstFields)); /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
    for(index=(uint32_t) 0;index<*NumberOfCompatibilityRules;index++)
    {
        CompatibilityRules[index] = CompatibilityRulesIterator[index];
    }
    if((CMP_FileConstantSizeFirstFields->OnBoardRunningLoad) == ((uint32_t) 0xFFFFFFFF))
    {
        *LoadLoadedByBoot = TRUE;
    }
    else if((CMP_FileConstantSizeFirstFields->OnBoardRunningLoad) == ((uint32_t) 0x00000000))
    {
        *LoadCheckedByBootInFlash = TRUE;
    }
    else if((CMP_FileConstantSizeFirstFields->OnBoardRunningLoad) != ((uint32_t) 0x55555555))
    {
        *OutOfOperationalConditionCMP = TRUE;
        return;
    }
    for(index=((uint32_t) 0);index<((uint32_t) C_AMENDMENT_INFO_MAX_LENGTH);index++)
    {
        AmendmentInfo[index] = (CMP_FileConstantSizeFirstFields->AmendmentInformation)[index];
    }
    *LoadType = CMP_FileConstantSizeFirstFields->LoadType;
    *Destination = CMP_FileConstantSizeFirstFields->Destination;
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */