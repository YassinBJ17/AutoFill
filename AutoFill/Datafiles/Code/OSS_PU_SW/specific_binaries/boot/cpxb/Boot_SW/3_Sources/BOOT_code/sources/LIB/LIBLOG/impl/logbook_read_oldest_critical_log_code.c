/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_read_oldest_critical_log_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* Read the oldest critical log */
te_read_state LOGBOOK_READ_OLDEST_CRITICAL_LOG ( ts_eventBlock * const p_eventBlock /* out */)
{
   /* Pointer on the logbook header */
   ts_LgbkHeader* pt_lgbk_header = (ts_LgbkHeader*)HEADER_LGBK_START_ADDR;
   /* Status indicating if a log has been read (or not) */
   te_read_state readState = e_NOT_READ;

   /* If no write has been done since the last time or the read is still allowed because the write pointer is so faster that it overwrites oldest log already read (at the top of the critical logbook) */
   if ( V_overwriteFlag != e_CMN_FLAG_NO
   || V_criticalLgbkHashMap.s_writeEventBlockAddress != V_criticalLgbkHashMap.s_readEventBlockAddress )
   {
      /* Save the log read from the NVM */
      *p_eventBlock = *( V_criticalLgbkHashMap.s_readEventBlockAddress );

      /* Prepare the pointer for the next read */
      pt_lgbk_header->s_circularReadIndex = ( pt_lgbk_header->s_circularReadIndex + (uint32_t)1 ) % CRITICAL_LOGS_NB;
      V_criticalLgbkHashMap.s_readEventBlockAddress = (ts_eventBlock *)( ( ( pt_lgbk_header->s_circularReadIndex
      * CRITICAL_LGBK_OFFSET_ADDR )
                                                                           + CRITICAL_LGBK_START_ADDR ) );

      /* Flag is not useful anymore because V_criticalLgbkHashMap.s_writeEventBlockAddress != V_criticalLgbkHashMap.s_readEventBlockAddress */
      V_overwriteFlag = e_CMN_FLAG_NO;

      /* Indicate a log has been read */
      readState = e_READ;
   }

   /* Indicate to the caller if a read has been performed (or not) */
   return readState;
}

/* ---------- internal operations: ------------------------------------------ */
/* none */
