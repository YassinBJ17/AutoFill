/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_init_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "BOOT_LIBMEM_public.h"

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

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialize the variables used for logbook */
void LOGBOOK_INIT ( void )
{
   /* Pointer on the logbook header */
   ts_LgbkHeader* pt_lgbk_header = (ts_LgbkHeader*)HEADER_LGBK_START_ADDR;

   /* Just an iterator */
   uint32_t i;

   /* If the logbook has already been initialized */
   if ( pt_lgbk_header->s_initID == INIT_FLAG )
   {

      /* Make reading and writing pointers begin where it stops during last session */
      V_criticalLgbkHashMap.s_readEventBlockAddress = (ts_eventBlock *)( ( pt_lgbk_header->s_circularReadIndex
      * CRITICAL_LGBK_OFFSET_ADDR ) + CRITICAL_LGBK_START_ADDR );
      V_criticalLgbkHashMap.s_writeEventBlockAddress = (ts_eventBlock *)( ( pt_lgbk_header->s_circularWriteIndex
      * CRITICAL_LGBK_OFFSET_ADDR ) + CRITICAL_LGBK_START_ADDR );

      /* Initialize the previous originId and EventID to the last ones */
      V_previousOriginId = V_criticalLgbkHashMap.s_writeEventBlockAddress->s_originId;
      V_previousEventId = V_criticalLgbkHashMap.s_writeEventBlockAddress->s_eventId;
   }
   else
   {

      /* Initialize the MRAM area to 0 */
      /* Logbook header, Registered Logbook, Critical Logbook are initialized to 0*/
      BOOT_LIBMEM_SET32 ( (uint8_t*)HEADER_LGBK_START_ADDR,
                          (uint32_t)0,
                          LOGBOOK_AREA_SIZE );

      /* Initialize to a value not used in a functional behavior */
      V_previousOriginId = PREVIOUS_ORIGIN_AND_EVENT_VALUE;
      V_previousEventId = PREVIOUS_ORIGIN_AND_EVENT_VALUE;

      /* Make reading and writing pointers begin at the start of the critical logbook */
      V_criticalLgbkHashMap.s_readEventBlockAddress = (ts_eventBlock *)CRITICAL_LGBK_START_ADDR;
      V_criticalLgbkHashMap.s_writeEventBlockAddress = (ts_eventBlock *)CRITICAL_LGBK_START_ADDR;

      /* Indicate in NVM that the logbook has already been initialized */
      pt_lgbk_header->s_initID = INIT_FLAG;
   }

   /* Initialize the registered logbook */
   /* For all the origins */
   for ( i = (uint32_t)0; i < REGISTERED_LOGS_NB ; i++ )
   {
      /* Associate each origin (represented by the index) to a registered log address */
      V_registeredLgbkHashMap[i].s_registeredLogAddress = (ts_registeredLog *)( REGISTERED_LGBK_START_ADDR
      + ( i * REGISTERED_LGBK_OFFSET_ADDR ) );

      /* Initialize the short occurrence counter to 0 */
      V_registeredLgbkHashMap[i].s_shortOccurrenceCounter = (uint8_t)0;
   }

   /* In the initialization, no operation has already been completed in the critical logbook */
   V_overwriteFlag = e_CMN_FLAG_NO;

}
