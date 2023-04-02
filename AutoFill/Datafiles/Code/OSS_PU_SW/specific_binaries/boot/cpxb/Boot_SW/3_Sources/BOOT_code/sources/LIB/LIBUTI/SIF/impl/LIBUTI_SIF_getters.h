/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef _LIBUTI_SIF_getters_H_
#define _LIBUTI_SIF_getters_H_

 
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
#include "LIBUTI_SIF.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

typedef struct
{
   uint32_t header_length;
   uint16_t format_version;
   uint16_t format_revision;
   uint32_t software_chars_abs_ptr;
   uint32_t targets_chars_abs_ptr;
   uint32_t tool_chars_abs_ptr;
   uint32_t requester_info_abs_ptr;
   uint32_t files_chars_abs_ptr;
   uint32_t header_addr;
} ts_LIBUTI_SIF_header;

typedef struct
{
   const uint8_t *header;
   uint32_t position;
   uint32_t header_length;
} ts_LIBUTI_SIF_header_iterator;

/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_header( const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_header *out );
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_header_iterator( const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_header_iterator *out );
extern uint16_t LIBUTI_SIF_get_short( ts_LIBUTI_SIF_header_iterator *hiter );
extern uint32_t LIBUTI_SIF_get_long( ts_LIBUTI_SIF_header_iterator *hiter );
extern void LIBUTI_SIF_get_str( ts_LIBUTI_SIF_header_iterator *hiter, const uint32_t len, uint8_t *buffer );
extern void LIBUTI_SIF_get_strl( ts_LIBUTI_SIF_header_iterator *hiter, TS_LIBUTI_SIF_Name_WithLength *out );
extern uint32_t LIBUTI_SIF_get_hash_length( const TE_LIBUTI_SIF_check_algorithm algo );

#endif /* _LIBUTI_SIF_getters_H_ */
