/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : MCSS wrapper task function definition
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
/* MCSS wrapper task function */
void mcss_wrapper_task(void)
{

   if ((MCSS_WRAPPER_TASK_ADDR)!=0)
   {
   /* Calling MCSS wrapper task function stored in the flash address */
      (MCSS_WRAPPER_TASK_ADDR)();
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
