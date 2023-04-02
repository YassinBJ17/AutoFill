/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_write_registered_log_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* Hash map associating each origin of event to a registered log address and a short occurrence counter */
ts_registeredLgbkHashMap V_registeredLgbkHashMap[REGISTERED_LOGS_NB ];

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* Update the registered log with a new event in the registered logbook */
void LOGBOOK_WRITE_REGISTERED_LOG ( const ts_eventBlock *p_eventBlock /* in */)
{
   /* Address in which the log will be saved */
   ts_registeredLog *registeredLogAddress;

   /* Increment the short occurrence counter (stored in flash) */
   V_registeredLgbkHashMap[p_eventBlock->s_originId].s_shortOccurrenceCounter++;

   /* Save the address associated to the given origin */
   registeredLogAddress = V_registeredLgbkHashMap[p_eventBlock->s_originId].s_registeredLogAddress;

   /* If it is the first occurrence of the fault associated to the origin of the given event block */
   if ( registeredLogAddress->s_longOccurrenceCounter == (uint32_t)0 )
   {
      /* Save the event in the blocks of first and last occurrences */
      registeredLogAddress->s_firstEventOccurred = *p_eventBlock;
      registeredLogAddress->s_lastEventOccurred = *p_eventBlock;
   }
   /* If it is not the first appearance of the fault associated to the origin of the given event block */
   else
   {
      /* Save the event only in the last occurrence block */
      registeredLogAddress->s_lastEventOccurred = *p_eventBlock;
   }

   /* Increment the counter of the registered log identifier by its origin */
   registeredLogAddress->s_longOccurrenceCounter++;
}

/* ---------- internal operations: ------------------------------------------ */
/* none */
