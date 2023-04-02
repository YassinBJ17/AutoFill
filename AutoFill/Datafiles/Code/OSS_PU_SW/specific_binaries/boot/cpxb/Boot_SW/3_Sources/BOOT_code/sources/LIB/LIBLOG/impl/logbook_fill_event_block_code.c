/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_fill_event_block_public.h"

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
/* Fill all the fields of the event block located at the given address */
void LOGBOOK_FILL_EVENT_BLOCK ( const uint32_t p_originId /* in */,
                                const uint32_t p_eventId /* in */,
                                const uint32_t p_exceptionContext /* in */,
                                const uint32_t p_rawData1 /* in */,
                                const uint32_t p_rawData2 /* in */,
                                const uint32_t p_rawData3 /* in */,
                                const uint32_t p_rawData4 /* in */,
                                ts_eventBlock * const p_eventBlock /* inout */)
{
   p_eventBlock->s_originId = p_originId;
   p_eventBlock->s_eventId = p_eventId;
   p_eventBlock->s_timestamp = V_timestamp;
   p_eventBlock->s_powerUpCount = V_powerUpCounter;
   p_eventBlock->s_exceptionContext = p_exceptionContext;
   p_eventBlock->s_rawData1 = p_rawData1;
   p_eventBlock->s_rawData2 = p_rawData2;
   p_eventBlock->s_rawData3 = p_rawData3;
   p_eventBlock->s_rawData4 = p_rawData4;
   p_eventBlock->s_healthWord = V_healthWord;
   p_eventBlock->s_heat = V_heat;
   p_eventBlock->s_speed = V_speed;
   p_eventBlock->s_missionId = V_missionId;
}

/* ---------- internal operations: ------------------------------------------ */
/* none */
