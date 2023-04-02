/*----------------------------------------------------------------------------*/
/* File name  : LIBMCP_Types.h                                                          */
/* CSC name   :                                                                 */
/*                                                                              */
/* Description:                                                                 */
/*                                                                              */
/* Configuration management identification:                                     */
/*    %full_name:  sknNEXT#1/incl/LIBMCP_Types.h/1 %                                                            */
/*    Creation: F073244            on Fri Sep 20 14:56:49 CEST 2019                       */
/*                                                                              */
/* Copyright (c) 2019,                                                          */
/* Safran Electronics & Defense document. Reproduction and disclosure forbidden.*/
/*----------------------------------------------------------------------------*/
#ifndef _LIBMCP_TYPES_H_
#define _LIBMCP_TYPES_H_

#ifndef __DCC__
#include "stdint.h"
#endif

/* ---------- DLD symbol ---------------------------------------------------- */
/* ---------- include required interface: ----------------------------------- */
/* ---------- provided define constants: ------------------------------------ */
#ifndef NULL
#define NULL         (void*)(0L)
#endif

#ifndef ZERO
#define ZERO         (0L)
#endif

#ifndef FALSE
#define FALSE ((boolean_t) (0 == 1))   /* Expression returns '0' */
#endif

#ifndef TRUE
#define TRUE  ((boolean_t) (1 == 1))   /* Expression returns '1' */
#endif
/* ---------- provided macros: ---------------------------------------------- */
/* ---------- provided types: ----------------------------------------------- */
typedef unsigned   long       boolean_t;

#ifdef __DCC__
typedef unsigned char      uint8_t;
typedef signed   char      int8_t;
typedef unsigned short     uint16_t;
typedef signed   short     int16_t;
typedef unsigned long      uint32_t;
typedef signed   long      int32_t;
typedef unsigned long long uint64_t;
typedef signed   long long int64_t;
#endif

typedef float              float32_t;
typedef double             float64_t;
/* ---------- provided constants: ------------------------------------------- */
/* ---------- provided data: ------------------------------------------------ */
/* ---------- provided operations: ------------------------------------------ */


#endif /* _LIBMCP_TYPES_H_ */

