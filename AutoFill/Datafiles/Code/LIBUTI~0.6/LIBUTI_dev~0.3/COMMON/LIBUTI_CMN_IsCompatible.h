/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/


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
    boolean_t const FirstLoadRuleTargetingSecondLoad,
    boolean_t const SecondLoadRuleTargetingFirstLoad,
	const TS_CompatibilityRule* const FirstLoadCompatRuleTargetingSecondLoad,
    const TS_CompatibilityRule* const SecondLoadCompatRuleTargetingFirstLoad,
/*OUT*/
    boolean_t* const LoadsAreIncompatible

);