/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_READ_OLDEST_CRITICAL_LOG_PUBLIC_H
#define LOGBOOK_READ_OLDEST_CRITICAL_LOG_PUBLIC_H

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
/* Read the oldest critical log */
extern te_read_state LOGBOOK_READ_OLDEST_CRITICAL_LOG ( ts_eventBlock * const p_eventBlock /* out */);

#endif
