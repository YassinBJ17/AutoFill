/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LIB_TIME_PUBLIC_H
#define LIB_TIME_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"


/* ---------- provided define constants: ------------------------------------ */
#define LIB_TIME_MICRO_SEC (1000UL)
#define LIB_TIME_MILLI_SEC (1000UL*LIB_TIME_MICRO_SEC)
#define LIB_TIME_SECONDE   (1000UL*LIB_TIME_MILLI_SEC)

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   CMN_SYSTEM_TIME_t s_start;
   uint32_t s_ongoing;
   uint32_t s_end;
}
ts_LIB_TIME_CHRONO;

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void LIBT_TIME_GET ( CMN_SYSTEM_TIME_t * const p_timeNanoSec ) ;

/* */
extern void LIBT_TIME_INIT(void) ;

extern void LIBT_TIME_Update( ts_LIB_TIME_CHRONO* const p_chrono);

extern void LIBT_TIME_Wait(const CMN_SYSTEM_TIME_t delay);

extern void LIBT_WAIT_REG_TIMEOUT ( uint32_t          const reg,
                                    int32_t           const expected_state,
                                    CMN_SYSTEM_TIME_t  const time_to_wait,
                                    tu_CMN_RC         * return_code_pt );

#endif /* LIB_TIME_PUBLIC_H */

