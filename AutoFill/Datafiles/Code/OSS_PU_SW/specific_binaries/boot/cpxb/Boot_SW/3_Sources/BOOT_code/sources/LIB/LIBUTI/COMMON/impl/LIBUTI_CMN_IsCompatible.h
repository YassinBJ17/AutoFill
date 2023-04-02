/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_COMMON.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation: ------------------------------------ */
void LIBUTI_CMN_IsCompatible
(
/*IN*/
   te_CMN_FLAG_QUESTION const FirstLoadRuleTargetingSecondLoad,
   te_CMN_FLAG_QUESTION const SecondLoadRuleTargetingFirstLoad,
   const TS_CompatibilityRule* const FirstLoadCompatRuleTargetingSecondLoad,
   const TS_CompatibilityRule* const SecondLoadCompatRuleTargetingFirstLoad,
/*OUT*/
   te_CMN_FLAG_QUESTION* const LoadsAreIncompatible

);
