/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Perform init function for ebreaker
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/ebreaker/ebreaker_public.h"
#include "middleware/ebreaker/ebreaker_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */
void ebreaker_init(void)
{
   /* Local Variable Declaration        */

   /* Initialized value                 */
   ebreaker_previous_cmd = EBREACKER_INIT_VALUE;

   return;
}
