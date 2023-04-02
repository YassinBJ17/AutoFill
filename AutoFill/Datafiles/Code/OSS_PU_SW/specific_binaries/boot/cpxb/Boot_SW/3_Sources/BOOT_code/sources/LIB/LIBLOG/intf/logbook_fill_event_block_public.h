/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_FILL_EVENT_BLOCK_PUBLIC_H
#define LOGBOOK_FILL_EVENT_BLOCK_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "logbook_common_data.h"

/* ---------- Linker command file symbol: ----------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */
/* none */

/* ---------- provided types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* Fill all the fields of the event block located at the given address */
extern void LOGBOOK_FILL_EVENT_BLOCK ( const uint32_t p_originId /* in */,
                                       const uint32_t p_eventId /* in */,
                                       const uint32_t p_exceptionContext /* in */,
                                       const uint32_t p_rawData1 /* in */,
                                       const uint32_t p_rawData2 /* in */,
                                       const uint32_t p_rawData3 /* in */,
                                       const uint32_t p_rawData4 /* in */,
                                       ts_eventBlock * const p_eventBlock /* out */);

#endif
