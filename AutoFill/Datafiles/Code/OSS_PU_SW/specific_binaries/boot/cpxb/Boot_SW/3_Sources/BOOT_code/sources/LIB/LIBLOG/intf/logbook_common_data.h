/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_COMMON_DATA_H
#define LOGBOOK_COMMON_DATA_H

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
#include "logbook_common_types.h"
#include "logbook_CFEX_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */
/* none */

/* ---------- provided types: ----------------------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */
/* Registered Logbook Start Address */
#define REGISTERED_LGBK_START_ADDR  (uint32_t)(HEADER_LGBK_START_ADDR + ((uint32_t)sizeof(ts_LgbkHeader)))

/* Offset between two logs in the registered logbook (108 bytes) */
#define REGISTERED_LGBK_OFFSET_ADDR (uint32_t)sizeof(ts_registeredLog)

/* Start address in the NVM of the critical logbook */
#define CRITICAL_LGBK_START_ADDR (uint32_t)(REGISTERED_LGBK_START_ADDR + (REGISTERED_LGBK_OFFSET_ADDR * REGISTERED_LOGS_NB))

/* Offset between two logs in the critical logbook (52 bytes) */
#define CRITICAL_LGBK_OFFSET_ADDR (uint32_t)sizeof(ts_eventBlock)

/* Total size of NVM area reserved to logbook */
#define LOGBOOK_AREA_SIZE (uint32_t)(((uint32_t)sizeof(ts_LgbkHeader)) + (REGISTERED_LOGS_NB*REGISTERED_LGBK_OFFSET_ADDR) + (CRITICAL_LOGS_NB*CRITICAL_LGBK_OFFSET_ADDR))

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */

/* Hash map associating critical log address to an appearance index */
extern ts_criticalLgbkHashMap V_criticalLgbkHashMap;

/* Origin of the previous event */
extern uint32_t V_previousOriginId;

/* Event source of the previous event */
extern uint32_t V_previousEventId;

/* Overwrite flag */
extern te_CMN_FLAG_QUESTION V_overwriteFlag;

/* Hash map associating each origin of event to a registered log address and a short occurrence counter */
extern ts_registeredLgbkHashMap V_registeredLgbkHashMap[REGISTERED_LOGS_NB ];

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif
