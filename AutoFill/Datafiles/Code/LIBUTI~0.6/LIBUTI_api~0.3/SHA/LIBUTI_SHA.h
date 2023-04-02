/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SHA.h
 * CSC name   : LIBUTI
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/incl/LIBUTI_SHA.h/2 %
 *    Creation: FT131472            on Tue Mar  9 14:35:00 CET 2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden. */
/*----------------------------------------------------------------------------*/

#ifndef SHA256_H
#define SHA256_H

/*************************** HEADER FILES ***************************/
#include "LIBMCP_Types.h"

/****************************** MACROS ******************************/
#define SHA256_BLOCK_SIZE 32            /* SHA256 outputs a 32 byte digest */

/**************************** DATA TYPES ****************************/
typedef struct {
    uint8_t Data[64];
    uint32_t Datalen;
    uint64_t Bitlen;
    uint32_t State[8];
} ts_LIBUTI_SHA_SHA256_ctx;

typedef struct {
    uint8_t Data[32];
} ts_LIBUTI_SHA_SHA256;

/*********************** FUNCTION DECLARATIONS **********************/
extern void LIBUTI_SHA_initSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx);
extern void LIBUTI_SHA_updateSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx, const uint8_t *Data, const uint32_t Length);
extern void LIBUTI_SHA_finalSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx, ts_LIBUTI_SHA_SHA256 * const ComputedHash);
extern void LIBUTI_SHA_ComputeSHA256(const uint8_t * const File, const uint32_t Length, ts_LIBUTI_SHA_SHA256 * const ComputedHash);

#endif   /* SHA256_H */
