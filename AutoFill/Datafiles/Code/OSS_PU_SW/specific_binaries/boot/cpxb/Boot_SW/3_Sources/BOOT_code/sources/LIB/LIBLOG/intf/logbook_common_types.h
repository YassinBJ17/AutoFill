/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_COMMON_TYPES_H
#define LOGBOOK_COMMON_TYPES_H

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- Linker command file symbol: ----------------------------------- */
/* none */

/* ---------- provided types: ----------------------------------------------- */
/* Event block definition (52 bytes) */
typedef struct
{
   /* OriginID : Source of event and impact criticity */
   uint32_t s_originId;

   /* EventID : Event signature */
   uint32_t s_eventId;

   /* Timestamp : Time of event */
   uint32_t s_timestamp;

   /* PowerUpCount : Power-up counter of the platform */
   uint32_t s_powerUpCount;

   /* ExceptionContext : Status of exceptions and interruptions */
   uint32_t s_exceptionContext;

   /* RawData1 : Part 1 of the raw data */
   uint32_t s_rawData1;

   /* RawData2 : Part 2 of the raw data */
   uint32_t s_rawData2;

   /* RawData3 : Part 3 of the raw data */
   uint32_t s_rawData3;

   /* RawData4 : Part 4 of the raw data */
   uint32_t s_rawData4;

   /* HealthWord : Health of channels and activity status */
   uint32_t s_healthWord;

   /* Temp : Calculator internal and external temperature */
   uint32_t s_heat;

   /* Speed : Rotation speed of engine */
   uint32_t s_speed;

   /* MissionID : Identifier of the mission */
   uint32_t s_missionId;
} ts_eventBlock;

/* Logbook header (12 bytes) */
typedef struct
{
   /* Initialization ID : flag that indicates if the Logbook has been initialized */
   uint32_t s_initID;
   /* Position in circular buffer for the read pointer */
   uint32_t s_circularReadIndex;
   /* Position in circular buffer for the write pointer */
   uint32_t s_circularWriteIndex;
} ts_LgbkHeader;

/* Registered log definition (108 bytes) */
typedef struct
{
   /* First event occurred in the current mission (52 bytes) */
   ts_eventBlock s_firstEventOccurred;

   /* Last event occurred in the current mission (52 bytes) */
   ts_eventBlock s_lastEventOccurred;

   /* Counter of the event occurrences (4 bytes) */
   uint32_t s_longOccurrenceCounter;
} ts_registeredLog;

/* Hash map associating registered log address to the origin of the event */
typedef struct
{
   /* Registered log start address */
   ts_registeredLog *s_registeredLogAddress;

   /* Occurrences number of the same origin */
   uint8_t s_shortOccurrenceCounter;
} ts_registeredLgbkHashMap;

/* Hash map associating critical log address to an appearance index */
typedef struct
{
   /* Critical log (= an event block) address to read */
   ts_eventBlock *s_readEventBlockAddress;

   /* Critical log (= an event block) address to write */
   ts_eventBlock *s_writeEventBlockAddress;

} ts_criticalLgbkHashMap;

/* Status indicating if a log has been read or not */
typedef enum
{
   /* A read has been performed */
   e_READ = 0,

   /* No read has been performed */
   e_NOT_READ = 1
} te_read_state;

/* ---------- provided define constants: ------------------------------------ */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif
