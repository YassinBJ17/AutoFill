/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : MCSS wrapper initialization function definition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "main/mcss_wrapper_task_public.h"
#include "memory/mcss_wrapper_section_def_data.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* MCSS wrapper initialization function */
void mcss_wrapper_init(void)
{
   make_asterios_identify_this_file_1 = (uint32_t)0;

   if ((MCSS_WRAPPER_INITIALIZATION_TASK_ADDR)!= 0)
   {
      /* Calling MCSS wrapper initialization function stored in the flash address */
      (MCSS_WRAPPER_INITIALIZATION_TASK_ADDR)();
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
