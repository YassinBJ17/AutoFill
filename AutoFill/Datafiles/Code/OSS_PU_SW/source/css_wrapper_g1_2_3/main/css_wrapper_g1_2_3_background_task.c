/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : CSS wrapper G1_2_3 background task function definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "main/css_wrapper_g1_2_3_task_public.h"
#include "memory/memory_address_public.h"
#include "wrapper/cancel_as_calls.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0040 */
/* CSS wrapper G1_2_3 background task */
void css_wrapper_g1_2_3_background_task(void)
{
   if(CANCEL_AS_CALLS_KEY != cancel_as_calls_key)
   {
      /* Calling CSS wrapper G1_2_3 background task function stored in the flash address */
      (CSS_WRAPPER_G1_2_3_BACKGROUND_TASK_ADDR)();
   }
   return;
}

/* ---------- internal operations: ------------------------------------------ */
