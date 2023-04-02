/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_write_critical_log_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* Hash map associating critical log address to an appearance index */
ts_criticalLgbkHashMap V_criticalLgbkHashMap;

/* Origin of the previous event */
uint32_t V_previousOriginId;

/* Event source of the previous event */
uint32_t V_previousEventId;

/* Is a write operation already completed in the critical logbook ? */
te_CMN_FLAG_QUESTION V_overwriteFlag;

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* Log a given event in the critical logbook */
void LOGBOOK_WRITE_CRITICAL_LOG ( const ts_eventBlock *p_eventBlock /* in */)
{
   /* Pointer on the logbook header */
   ts_LgbkHeader* pt_lgbk_header = (ts_LgbkHeader*)HEADER_LGBK_START_ADDR;

   /* If the event origin is not the same than the previous one OR it is the same but the event source has changed */
   if ( V_previousOriginId != p_eventBlock->s_originId
   || ( V_previousOriginId == p_eventBlock->s_originId && V_previousEventId != p_eventBlock->s_eventId ) )
   {
      /* Save the critical log in NVM */
      *( V_criticalLgbkHashMap.s_writeEventBlockAddress ) = *p_eventBlock;

      /* If the updated content of address will be read (not good because the logs are read by appearance order) */
      if ( V_criticalLgbkHashMap.s_writeEventBlockAddress == V_criticalLgbkHashMap.s_readEventBlockAddress
      && V_overwriteFlag != e_CMN_FLAG_NO )
      {
         /* Make the read pointer point on the next critical log address */
         pt_lgbk_header->s_circularReadIndex = ( pt_lgbk_header->s_circularReadIndex + (uint32_t)1 ) % CRITICAL_LOGS_NB;
         V_criticalLgbkHashMap.s_readEventBlockAddress = (ts_eventBlock *)( ( ( pt_lgbk_header->s_circularReadIndex
         * CRITICAL_LGBK_OFFSET_ADDR )
                                                                              + CRITICAL_LGBK_START_ADDR ) );

      }

      /* Once the critical log is written and the check is done, point to the next available area for writing */
      pt_lgbk_header->s_circularWriteIndex = ( pt_lgbk_header->s_circularWriteIndex + (uint32_t)1 ) % CRITICAL_LOGS_NB;
      V_criticalLgbkHashMap.s_writeEventBlockAddress = (ts_eventBlock *)( ( ( pt_lgbk_header->s_circularWriteIndex
      * CRITICAL_LGBK_OFFSET_ADDR )
                                                                            + CRITICAL_LGBK_START_ADDR ) );

      /* After write pointer incremented, if the block pointed to by the read pointer can be read */
      if ( V_criticalLgbkHashMap.s_writeEventBlockAddress == V_criticalLgbkHashMap.s_readEventBlockAddress )
      {
         /* Make the flag allow the read */
         V_overwriteFlag = e_CMN_FLAG_YES;
      }

      /* Update the previous event source and origin */
      V_previousOriginId = p_eventBlock->s_originId;
      V_previousEventId = p_eventBlock->s_eventId;
   }
}

/* ---------- internal operations: ------------------------------------------ */
/* none */
