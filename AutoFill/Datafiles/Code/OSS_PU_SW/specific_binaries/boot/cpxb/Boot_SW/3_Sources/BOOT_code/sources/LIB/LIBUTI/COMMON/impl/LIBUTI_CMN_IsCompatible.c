/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */



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
   te_CMN_FLAG_QUESTION const FirstLoadRuleTargetingSecondLoad,
   te_CMN_FLAG_QUESTION const SecondLoadRuleTargetingFirstLoad,
   const TS_CompatibilityRule * const FirstLoadCompatRuleTargetingSecondLoad,
   const TS_CompatibilityRule * const SecondLoadCompatRuleTargetingFirstLoad,
/*OUT*/
   te_CMN_FLAG_QUESTION * const LoadsAreIncompatible

)
{

   if ( ( FirstLoadRuleTargetingSecondLoad && (!SecondLoadRuleTargetingFirstLoad) )
     || ( SecondLoadRuleTargetingFirstLoad && (!FirstLoadRuleTargetingSecondLoad) ) )
   {
      *LoadsAreIncompatible = e_CMN_FLAG_YES;
   }
   else if( FirstLoadRuleTargetingSecondLoad && SecondLoadRuleTargetingFirstLoad )
   {
      if ((/*First load has priority over second load*/
            ( ( FirstLoadCompatRuleTargetingSecondLoad->Major < SecondLoadCompatRuleTargetingFirstLoad->Major )
              ||
              ( ( FirstLoadCompatRuleTargetingSecondLoad->Major == SecondLoadCompatRuleTargetingFirstLoad->Major )
                &&
                ( FirstLoadCompatRuleTargetingSecondLoad->Minor < SecondLoadCompatRuleTargetingFirstLoad->Minor )
              )
            )
          )
          ||
          (/*Second load has priority over first load*/
            ( ( FirstLoadCompatRuleTargetingSecondLoad->Major > SecondLoadCompatRuleTargetingFirstLoad->Major )
              ||
              ( ( FirstLoadCompatRuleTargetingSecondLoad->Major == SecondLoadCompatRuleTargetingFirstLoad->Major )
                &&
                ( FirstLoadCompatRuleTargetingSecondLoad->Minor > SecondLoadCompatRuleTargetingFirstLoad->Minor )
              )
            )
          )
        )
      {
         *LoadsAreIncompatible = e_CMN_FLAG_YES;
      }
   }
}