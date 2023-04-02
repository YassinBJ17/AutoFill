/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Sleep
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "libtools/time/LIB_TIME_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Increment the counter of elapsed RTC */
void LIBT_TIME_Wait(const CMN_SYSTEM_TIME_t delay)
{
   /* Local Variables Declaration */
   CMN_SYSTEM_TIME_t begin_time;
   CMN_SYSTEM_TIME_t end_time;

   /* Local Variables init */
   begin_time = (CMN_SYSTEM_TIME_t)0;
   end_time   = (CMN_SYSTEM_TIME_t)0;

   /* Timestamp using LIBT_TIME */
   LIBT_TIME_GET(&begin_time);

   /* Get time while the elapsed delay is not greater than the wanted delay */
   do
   {
      LIBT_TIME_GET(&end_time);
   }
   while ((end_time - begin_time) < delay);
}

/* ---------- internal operations: ------------------------------------------ */

