/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef _LIBUTI_SHA_H_
#define _LIBUTI_SHA_H_

/*************************** HEADER FILES ***************************/
#include "CMN_TYPES_common.h"

/****************************** MACROS ******************************/
#define K_CHUNK_SIZE 2048            /* Buffer size admitance */

#define SHA256_BLOCK_SIZE 32         /* SHA256 outputs a 32 byte digest */
#define SHA512_BLOCK_SIZE 64         /* SHA512 outputs a 64 byte digest */

/* TO DO */

/* Constants values of SHA */
#define SHA256_HIGH_BLOCK_NUMBER 64          /* SHA256 number max of 32 byte block in 512 bits length message */
#define SHA256_MAXLASTIEST_BLOCK_NUMBER 55   /* SHA256 last number max of 32 byte block in 512 bits length message */
#define SHA512_HIGH_BLOCK_NUMBER 128         /* SHA512 number max of 64 byte block in 1024 bits length message */
#define SHA512_MAXLASTIEST_BLOCK_NUMBER (SHA512_HIGH_BLOCK_NUMBER - 16)  /* SHA512 last number max of 64 byte block in 1024 bits length message */


/**************************** DATA TYPES ****************************/
typedef struct
{
   uint8_t Data_SHA256_ctx[SHA256_HIGH_BLOCK_NUMBER];
   uint32_t Datalen;
   uint64_t Bitlen;
   uint32_t State[8];
}
ts_LIBUTI_SHA_SHA256_ctx;

typedef struct
{
   uint8_t Data_SHA256[SHA256_BLOCK_SIZE];
}
ts_LIBUTI_SHA_SHA256;

typedef struct
{
   uint8_t  Data_SHA512_ctx[SHA512_HIGH_BLOCK_NUMBER];     // 128 blocks by 8 bits = 1024 bits size
   uint64_t	Bitlen[2];
   uint64_t State[8];           // 8 sections by 64 bits = 512 bits
   uint32_t Datalen;
}
ts_LIBUTI_SHA_SHA512_ctx;

typedef struct
{
   uint8_t Data_SHA512[SHA512_BLOCK_SIZE];         // Message size result 64 block by 8 bits = 512 bits
}
ts_LIBUTI_SHA_SHA512;

/*********************** FUNCTION DECLARATIONS **********************/
extern void LIBUTI_SHA_initSHA256( ts_LIBUTI_SHA_SHA256_ctx * const Ctx );

extern void LIBUTI_SHA_updateSHA256(
   ts_LIBUTI_SHA_SHA256_ctx * const Ctx,
   const uint8_t Data[],
   const uint32_t Length );

extern void LIBUTI_SHA_finalSHA256(
   ts_LIBUTI_SHA_SHA256_ctx * const Ctx,
   ts_LIBUTI_SHA_SHA256 * const ComputedHash);

extern void LIBUTI_SHA_ComputeSHA256(
   const uint8_t * const File,
   const uint32_t Length,
   ts_LIBUTI_SHA_SHA256 * const ComputedHash );

extern void SHA_sha512_transform(
   ts_LIBUTI_SHA_SHA512_ctx * const Ctx,
   const uint64_t Data[] );

extern void LIBUTI_SHA_initSHA512( ts_LIBUTI_SHA_SHA512_ctx * const Ctx );

extern void LIBUTI_SHA_updateSHA512(
   ts_LIBUTI_SHA_SHA512_ctx * const Ctx,
   const uint8_t Data[],
   const uint32_t Length );

extern void LIBUTI_SHA_finalSHA512(
   ts_LIBUTI_SHA_SHA512_ctx * const Ctx,
   ts_LIBUTI_SHA_SHA512 * const ComputedHash );

extern void LIBUTI_SHA_ComputeSHA512(
   const uint8_t * const File,
   const uint32_t Length,
   ts_LIBUTI_SHA_SHA512 * const ComputedHash );

#endif   /* _LIBUTI_SHA_H_ */
