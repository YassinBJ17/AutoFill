/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : RESET function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/reset/reset_public.h"
#include "middleware/reset/reset_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/mram/mram_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-RESET-0010 */
void reset_critical(void)
{
   /* Local Variable Declaration */
   uint32_t       k_integre;

   /* Initialization Variable */

   k_integre      = RST_INIT_UINT_VALUE32;

   /* Source code start */

   /* Prepare MRAM for reset */
   mram_reset();

   while (k_integre == RST_INIT_UINT_VALUE32)
   {

   };

   return;
}

/* ---------- internal operations: ------------------------------------------ */
