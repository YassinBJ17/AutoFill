/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LOGBOOK_WRITE_REGISTERED_LOG_PUBLIC_H
#define LOGBOOK_WRITE_REGISTERED_LOG_PUBLIC_H

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
/* Update the registered log with a new event in the registered logbook */
extern void LOGBOOK_WRITE_REGISTERED_LOG ( const ts_eventBlock *p_eventBlock /* in */);

#endif
