/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_get_next_file_skip.h
 * CSC name   : LIBUTI_SIF
 *
 * Description:
 *
 *    Creation: Divided from  LIBUTI_SIF_get_next_file in LIBUTI_SIF_iterators.c on 23-03-2022
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */

#ifndef _LIBUTI_SIF_get_next_file_skip_H_
#define _LIBUTI_SIF_get_next_file_skip_H_

/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBMCP_Types.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

void LIBUTI_SIF_get_next_file_skip(ts_LIBUTI_SIF_file_info * const file, ts_LIBUTI_SIF_iterator * const iter);

#endif /* _LIBUTI_SIF_get_next_file_skip_H_ */ 