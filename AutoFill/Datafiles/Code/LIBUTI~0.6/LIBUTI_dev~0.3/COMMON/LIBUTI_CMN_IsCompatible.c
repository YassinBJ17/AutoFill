/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/



/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_CMN_IsCompatible.h"
/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal macros: ---------------------------------------------- */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

void LIBUTI_CMN_IsCompatible
(
/*IN*/
    boolean_t const FirstLoadRuleTargetingSecondLoad,
    boolean_t const SecondLoadRuleTargetingFirstLoad,
	const TS_CompatibilityRule* const FirstLoadCompatRuleTargetingSecondLoad,
    const TS_CompatibilityRule* const SecondLoadCompatRuleTargetingFirstLoad,
/*OUT*/
    boolean_t* const LoadsAreIncompatible

)
{
	
    if((FirstLoadRuleTargetingSecondLoad && (!SecondLoadRuleTargetingFirstLoad))
        || (SecondLoadRuleTargetingFirstLoad && (!FirstLoadRuleTargetingSecondLoad)))
    {
        *LoadsAreIncompatible = TRUE;
    }
    else if(FirstLoadRuleTargetingSecondLoad && SecondLoadRuleTargetingFirstLoad)
    {
        if((FirstLoadCompatRuleTargetingSecondLoad->RelativePriority
            == SecondLoadCompatRuleTargetingFirstLoad->RelativePriority)
        || ((FirstLoadCompatRuleTargetingSecondLoad->RelativePriority
                < SecondLoadCompatRuleTargetingFirstLoad->RelativePriority)
                /*First load has priority over second load*/
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
                /*Second load has priority over first load*/
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
    }
}