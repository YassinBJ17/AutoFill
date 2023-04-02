#ifndef LIB_TIME_PUBLIC_H
#define LIB_TIME_PUBLIC_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */

#include "CMN_TYPES_common.h"


/* ---------- provided define constants: ------------------------------------ */
/* none */

/* ---------- provided types: ----------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void BOOT_LIBTIME_GET ( CMN_SYSTEM_TIME_t * const p_timeNanoSec ) ;

/* */
extern void BOOT_LIBTIME_INIT(void) ;

#endif /* LIBTIME_PUBLIC_H */
