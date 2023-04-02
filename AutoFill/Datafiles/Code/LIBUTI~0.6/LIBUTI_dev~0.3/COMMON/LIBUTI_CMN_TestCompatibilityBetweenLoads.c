#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_IsCompatible.h"


/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on FirstLoadCompatibilityRules and SecondLoadCompatibilityRules.*/
/* Poiter used as buffer with compatibility rules in it.*/
/*Can't use anrray because size depend on number of rules.*/
/*Overflow avoid by for instructions where index is compare to a max value*/

void LIBUTI_CMN_TestCompatibilityBetweenLoads
(
/*IN*/
    const uint8_t* const FirstLoadName,
    const uint32_t FirstLoadNumberOfCompatibilityRules,
    const TS_CompatibilityRule* const FirstLoadCompatibilityRules,
    const uint8_t* const SecondLoadName,
    const uint32_t SecondLoadNumberOfCompatibilityRules,
    const TS_CompatibilityRule* const SecondLoadCompatibilityRules,
/*OUT*/
    boolean_t* const LoadsAreIncompatible
)
{
    uint32_t index;
    uint32_t index_bis;
    TS_CompatibilityRule* FirstLoadCompatRuleTargetingSecondLoad;
    TS_CompatibilityRule* SecondLoadCompatRuleTargetingFirstLoad;
    boolean_t FirstLoadRuleTargetingSecondLoad;
    boolean_t SecondLoadRuleTargetingFirstLoad;
    *LoadsAreIncompatible = FALSE;
    FirstLoadRuleTargetingSecondLoad = FALSE;
    SecondLoadRuleTargetingFirstLoad = FALSE;
    FirstLoadCompatRuleTargetingSecondLoad = NULL;
    SecondLoadCompatRuleTargetingFirstLoad = NULL;
    for(index=((uint32_t) 0);index<FirstLoadNumberOfCompatibilityRules;index++)
    {
        FirstLoadRuleTargetingSecondLoad = TRUE;
        for(index_bis=((uint32_t) 0);index_bis<((uint32_t) C_LOAD_NAME_MAX_LENGTH);index_bis++)
        {
            if(FirstLoadCompatibilityRules[index].TargetName[index_bis]
                != SecondLoadName[index_bis])
            {
                FirstLoadRuleTargetingSecondLoad = FALSE;
                break;
            }
        }
        if(FirstLoadRuleTargetingSecondLoad)
        {
            FirstLoadCompatRuleTargetingSecondLoad
                = (TS_CompatibilityRule*) &(FirstLoadCompatibilityRules[index]);
            break;
        }
    }
    for(index=((uint32_t) 0);index<SecondLoadNumberOfCompatibilityRules;index++)
    {
        SecondLoadRuleTargetingFirstLoad = TRUE;
        for(index_bis=((uint32_t) 0);index_bis<((uint32_t) C_LOAD_NAME_MAX_LENGTH);index_bis++)
        {
            if(SecondLoadCompatibilityRules[index].TargetName[index_bis]
                != FirstLoadName[index_bis])
            {
                SecondLoadRuleTargetingFirstLoad = FALSE;
                break;
            }
        }
        if(SecondLoadRuleTargetingFirstLoad)
        {
            SecondLoadCompatRuleTargetingFirstLoad
                = (TS_CompatibilityRule*) &(SecondLoadCompatibilityRules[index]);
            break;
        }
    }
	/*
    if(( (FirstLoadRuleTargetingSecondLoad) && (!SecondLoadRuleTargetingFirstLoad) )
        || ( (SecondLoadRuleTargetingFirstLoad) && (!FirstLoadRuleTargetingSecondLoad) ))
    {
        *LoadsAreIncompatible = TRUE;
    }
    else if(FirstLoadRuleTargetingSecondLoad && SecondLoadRuleTargetingFirstLoad)
    {
        if((FirstLoadCompatRuleTargetingSecondLoad->RelativePriority
            == SecondLoadCompatRuleTargetingFirstLoad->RelativePriority)
        || ((FirstLoadCompatRuleTargetingSecondLoad->RelativePriority
                < SecondLoadCompatRuleTargetingFirstLoad->RelativePriority)
                First load has priority over second load
            && ((FirstLoadCompatRuleTargetingSecondLoad->Version
                < SecondLoadCompatRuleTargetingFirstLoad->Version)
                || ((FirstLoadCompatRuleTargetingSecondLoad->Version
                    == SecondLoadCompatRuleTargetingFirstLoad->Version)
                    && (FirstLoadCompatRuleTargetingSecondLoad->Revision
                        < SecondLoadCompatRuleTargetingFirstLoad->Revision))))
        )
        {
            *LoadsAreIncompatible = TRUE;
        }
		
		else if(((FirstLoadCompatRuleTargetingSecondLoad->RelativePriority
                > SecondLoadCompatRuleTargetingFirstLoad->RelativePriority)
                Second load has priority over first load
            && ((FirstLoadCompatRuleTargetingSecondLoad->Version
                > SecondLoadCompatRuleTargetingFirstLoad->Version)
                || ((FirstLoadCompatRuleTargetingSecondLoad->Version
                    == SecondLoadCompatRuleTargetingFirstLoad->Version)
                    && (FirstLoadCompatRuleTargetingSecondLoad->Revision
                        > SecondLoadCompatRuleTargetingFirstLoad->Revision))))
		)
		{
            *LoadsAreIncompatible = TRUE;
        }
    }*/
	
	LIBUTI_CMN_IsCompatible(FirstLoadRuleTargetingSecondLoad, SecondLoadRuleTargetingFirstLoad, FirstLoadCompatRuleTargetingSecondLoad, SecondLoadCompatRuleTargetingFirstLoad, LoadsAreIncompatible);
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */