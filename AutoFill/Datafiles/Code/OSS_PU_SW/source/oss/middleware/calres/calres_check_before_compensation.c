/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_private.h"
#include "memory/shared_memory_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Perform a minimal set of range checks on the acquired Calres signals,
 *   So that the compensation can be done with knowledge of the OC faults.
 */
boolean_t calres_check_before_compensation(
                                    const ts_calres_measures * const s_measures)
{
   return (CALRES_EXPECTED_VOLTAGE_RANGE_MAX <= s_measures->v_signal);
}
