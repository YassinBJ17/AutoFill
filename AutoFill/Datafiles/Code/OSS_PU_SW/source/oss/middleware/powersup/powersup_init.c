/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Powersupp initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/powersup/powersup_private.h"
#include "middleware/powersup/powersup_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* power supply initialization function */
void powersup_init(const boolean_t           channel_is_a)
{
   /* Initialization of the consecutive out of range high and low rtc counter  */
   V_POWERSUP_ERROR_RTC.u_word = (uint32_t)0;

   /* Get the alternator frequency */
   if(channel_is_a == TRUE )
   {
      /* none */;
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
