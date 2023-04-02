/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_getters_from_headers.h
 * CSC name   : LIBUTI_SIF
 *
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/


#ifndef _LIBUTI_SIF_getters_from_headers_H_
#define _LIBUTI_SIF_getters_from_headers_H_
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "LIBMCP_Types.h"
#include "LIBUTI_SIF_getters.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
uint16_t LIBUTI_SIF_get_short(ts_LIBUTI_SIF_header_iterator * const hiter);
uint32_t LIBUTI_SIF_get_long(ts_LIBUTI_SIF_header_iterator * const hiter);
void LIBUTI_SIF_get_str(ts_LIBUTI_SIF_header_iterator * const hiter, const uint32_t len, uint8_t * const buffer);

#endif /* _LIBUTI_SIF_getters_H_ */ 