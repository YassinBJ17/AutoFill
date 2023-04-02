/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_CFEX_PUBLIC_H
#define LOGBOOK_CFEX_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
#include "logbook_common_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */

/* Start address of the NVM */
#define NVM_START_ADDR (uint32_t)0x20004A00

/*Position of the logbook from the NVM_START_ADDR */
#define LGBK_OFFSET (uint32_t)0x0

/* Start address in the NVM of the registered logbook */
#define HEADER_LGBK_START_ADDR (uint32_t)(NVM_START_ADDR + LGBK_OFFSET)

/* Flag indicating that the logbook has been initialized */
#define INIT_FLAG (uint32_t)0x0FACADE0

/* Number of registered logs in the registered logbook */
#define REGISTERED_LOGS_NB (uint32_t)40 /* TBD */

/* Number of event blocks which can be saved in the critical logbook */
#define CRITICAL_LOGS_NB (uint32_t)4 /* TBD */

/* Initializion value not used in a functional behavior*/
#define PREVIOUS_ORIGIN_AND_EVENT_VALUE (uint32_t)150 /* TBD */

/* ---------- provided types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */

/* Number of Power Up */
extern uint32_t V_powerUpCounter;

/* the timestamp : either the value of a timer or the RTC */
extern uint32_t V_timestamp;

/* Health word indicating the health of the cross channels */
extern uint32_t V_healthWord;

/* Temp : Calculator internal and external temperature */
extern uint32_t V_heat;

/* Speed : Rotation speed of engine */
extern uint32_t V_speed;

/* Mission identifier */
extern uint32_t V_missionId;

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif
