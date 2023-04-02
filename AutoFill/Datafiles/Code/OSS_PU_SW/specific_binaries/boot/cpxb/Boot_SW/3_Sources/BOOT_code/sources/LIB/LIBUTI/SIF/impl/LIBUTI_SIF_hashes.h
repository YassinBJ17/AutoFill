/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef _LIBUTI_SIF_hashes_H_
#define _LIBUTI_SIF_hashes_H_

 
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
#include "LIBUTI_SHA.h"
#include "LIBUTI_SIF.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */



/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_hash( const uint8_t * const DecodedHeaderAddress, const uint8_t * FileName, const uint32_t FileNameLength,
                                                 const TE_LIBUTI_SIF_check_algorithm algo, tu_LIBUTI_SIF_hash * const hash_buffer );

#endif /* _LIBUTI_SIF_hashes_H_ */
