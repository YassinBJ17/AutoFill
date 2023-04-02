/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SHA_computation.c
 * CSC name   : LIBUTI_SHA
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/csrc/LIBUTI_SHA_Computation.c/2 %
 *    Creation: FT131472            on Tue Mar  9 14:40:54 CET 2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden. */
/*----------------------------------------------------------------------------*/


/*************************** HEADER FILES ***************************/

#include "LIBUTI_SHA.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SHA_Transform.h"
/****************************** MACROS ******************************/
/**************************** VARIABLES *****************************/
/*********************** FUNCTION DEFINITIONS ***********************/


void LIBUTI_SHA_initSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx)
{
   Ctx->Datalen = (uint32_t)0;
   Ctx->Bitlen = (uint64_t)0;
   Ctx->State[0] = (uint32_t)0x6a09e667;
   Ctx->State[1] = (uint32_t)0xbb67ae85;
   Ctx->State[2] = (uint32_t)0x3c6ef372;
   Ctx->State[3] = (uint32_t)0xa54ff53a;
   Ctx->State[4] = (uint32_t)0x510e527f;
   Ctx->State[5] = (uint32_t)0x9b05688c;
   Ctx->State[6] = (uint32_t)0x1f83d9ab;
   Ctx->State[7] = (uint32_t)0x5be0cd19;
}

void LIBUTI_SHA_updateSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx, const uint8_t *Data, const uint32_t Length)
{
   uint32_t i;

   for (i = (uint32_t)0; i < Length; ++i) 
   {
       Ctx->Data[Ctx->Datalen] = Data[i];  /* %RELAX<SYNCHRONe_C_Code_17.4> Here Data is used like a buffer */
       Ctx->Datalen++;
       if (Ctx->Datalen == (uint32_t)64) 
       {
           SHA_sha256_transform(Ctx, Ctx->Data);
           Ctx->Bitlen += (uint64_t)512;
           Ctx->Datalen = (uint32_t)0;
       }
   }
}

void LIBUTI_SHA_finalSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx, ts_LIBUTI_SHA_SHA256 * const ComputedHash)
{
   uint32_t i;

   i = Ctx->Datalen;

   /* Pad whatever data is left in the buffer. */
   if (Ctx->Datalen < (uint32_t)56) 
   {
       Ctx->Data[i] = (uint8_t)0x80;
       i++;
       while (i < (uint32_t)56)
       {
           Ctx->Data[i] = (uint8_t)0x00;
           i++;
       }
   }
   else 
   {
       Ctx->Data[i] = (uint8_t)0x80;
       i++;
       while (i < (uint32_t)64)
       {
           Ctx->Data[i] = (uint8_t)0x00;
           i++;
       }
       SHA_sha256_transform(Ctx, Ctx->Data);
       LIBUTI_MEM_MemSet(Ctx->Data, (uint8_t)0, (uint32_t)56);
   }


   /*{{RELAX<SYNCHRONe_C_Code_10.7>*/
   /*For the line 95 to 102 >> and cast to uint8_t are used to split the uint64_t variable in 8 uint8_t*/
   /* Here the loss of precision is wanted*/
   /*It is the same goal for the line 109 to 116*/
   
   /* Append to the padding the total message's length in bits and transform. */
   Ctx->Bitlen += (uint64_t)Ctx->Datalen * (uint64_t)8;
   Ctx->Data[63] = (uint8_t) (Ctx->Bitlen);
   Ctx->Data[62] = (uint8_t) (Ctx->Bitlen >> 8);
   Ctx->Data[61] = (uint8_t) (Ctx->Bitlen >> 16);
   Ctx->Data[60] = (uint8_t) (Ctx->Bitlen >> 24);
   Ctx->Data[59] = (uint8_t) (Ctx->Bitlen >> 32);
   Ctx->Data[58] = (uint8_t) (Ctx->Bitlen >> 40);
   Ctx->Data[57] = (uint8_t) (Ctx->Bitlen >> 48);
   Ctx->Data[56] = (uint8_t) (Ctx->Bitlen >> 56);
   SHA_sha256_transform(Ctx, Ctx->Data);

   /* Since this implementation uses little endian byte ordering and SHA uses big endian,
   ** reverse all the bytes when copying the final State to the output hash.
   ***/
   for (i = (uint32_t)0; i < (uint32_t)4; ++i) {
       ComputedHash->Data[i]                = (uint8_t) ( (Ctx->State[0] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
       ComputedHash->Data[i + (uint32_t)4]  = (uint8_t) ( (Ctx->State[1] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
       ComputedHash->Data[i + (uint32_t)8]  = (uint8_t) ( (Ctx->State[2] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
       ComputedHash->Data[i + (uint32_t)12] = (uint8_t) ( (Ctx->State[3] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
       ComputedHash->Data[i + (uint32_t)16] = (uint8_t) ( (Ctx->State[4] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
       ComputedHash->Data[i + (uint32_t)20] = (uint8_t) ( (Ctx->State[5] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
       ComputedHash->Data[i + (uint32_t)24] = (uint8_t) ( (Ctx->State[6] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
       ComputedHash->Data[i + (uint32_t)28] = (uint8_t) ( (Ctx->State[7] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff );
   }
   
   /*}}RELAX<SYNCHRONe_C_Code_10.7> */
}
