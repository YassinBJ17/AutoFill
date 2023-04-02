/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_hashes.h
 * CSC name   :
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/incl/LIBUTI_SIF_hashes.h/2 %
 *    Creation: Divided from LIBUTI_SIF_parsing.c on 04-02-2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */

#ifndef _LIBUTI_SIF_hashes_H_
#define _LIBUTI_SIF_hashes_H_
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "LIBMCP_Types.h"
#include "LIBUTI_SHA.h"
#include "LIBUTI_SIF.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* Add hash algorithms as they are implemented */
typedef union {
    ts_LIBUTI_SHA_SHA256 sha256;
    uint8_t data[64];
} tu_LIBUTI_SIF_hash;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_hash(const uint8_t * const DecodedHeaderAddress, const uint8_t *FileName, const uint32_t FileNameLength, const TE_LIBUTI_SIF_check_algorithm algo, tu_LIBUTI_SIF_hash * const hash_buffer);

#endif /* _LIBUTI_SIF_hashes_H_ */ 