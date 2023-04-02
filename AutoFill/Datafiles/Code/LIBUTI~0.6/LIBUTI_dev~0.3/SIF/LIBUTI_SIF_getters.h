/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_getters.h
 * CSC name   : LIBUTI_SIF
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/incl/LIBUTI_SIF_getters.h/2 %
 *    Creation: Divided from LIBUTI_SIF_parsing.c on 04-02-2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/


#ifndef _LIBUTI_SIF_getters_H_
#define _LIBUTI_SIF_getters_H_
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "LIBMCP_Types.h"
#include "LIBUTI_SIF.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

typedef struct  {
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

typedef struct {
    const uint8_t *header;
    uint32_t position;
    uint32_t header_length;
} ts_LIBUTI_SIF_header_iterator;

/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_header(const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_header * const out);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_header_iterator(const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_header_iterator * const out);
extern void LIBUTI_SIF_get_strl(ts_LIBUTI_SIF_header_iterator * const hiter, TS_LIBUTI_SIF_Name_WithLength *out);
extern uint32_t LIBUTI_SIF_get_hash_length(const TE_LIBUTI_SIF_check_algorithm algo);

#endif /* _LIBUTI_SIF_getters_H_ */ 