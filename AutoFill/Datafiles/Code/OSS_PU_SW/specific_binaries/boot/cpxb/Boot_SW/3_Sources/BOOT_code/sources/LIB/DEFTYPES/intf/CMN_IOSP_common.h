#ifndef CMN_IOSP_COMMON_H
#define CMN_IOSP_COMMON_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- provided types: ----------------------------------------------- */

/* */
/* Define IOSP ID type */
typedef uint32_t CMN_IOSP_ID_t;

typedef struct
{
   int8_t * s_buffer;
   uint32_t s_buffer_size;
}
ts_CMN_IOSP_BUFFER;

/* ---------- provided define constants: ------------------------------------ */
/* Invalid minor ID */
#define CMN_IOSP_INVALID_ID  ((CMN_IOSP_ID_TYPE) -1)

/* */
/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif /* CMN_IOSP_COMMON_H */
