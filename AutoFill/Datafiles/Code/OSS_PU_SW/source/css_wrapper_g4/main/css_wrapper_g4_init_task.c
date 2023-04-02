/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : CSS wrapper GX initialization function definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "main/css_wrapper_g4_task_public.h"
#include "memory/css_wrapper_g4_section_def_data.h"
#include "memory/memory_address_public.h"
#include "wrapper/cancel_as_calls.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
uint32_t cancel_as_calls_key;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0040 */
/* CSS wrapper GX initialization function */
void css_wrapper_g4_init_task(void)
{
   make_asterios_identify_this_file_2 = (uint32_t)0;

   if(CANCEL_AS_CALLS_KEY != cancel_as_calls_key)
   {
      /* Calling CSS wrapper GX initialization function stored in the flash address */
      (CSS_WRAPPER_GX_INITIALIZATION_TASK_ADDR)();
   }
   return;
}

/* ---------- internal operations: ------------------------------------------ */
