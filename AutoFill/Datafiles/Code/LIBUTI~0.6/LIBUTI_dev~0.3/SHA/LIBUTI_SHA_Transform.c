/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SHA_Transform.c
 * CSC name   : LIBUTI_SHA
 *
 *
 * Copyright (c) 2022,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden. */
/*----------------------------------------------------------------------------*/


/*************************** HEADER FILES ***************************/
#include "LIBUTI_SHA_Transform.h"
#include "LIBUTI_SHA.h"
/****************************** MACROS ******************************/
/*
#define M_ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define M_ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define M_CH(x,y,z) (((x) & (y)) ^ ((~(x)) & (z)))
#define M_MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define M_EP0(x) (M_ROTRIGHT(x,2) ^ M_ROTRIGHT(x,13) ^ M_ROTRIGHT(x,22))
#define M_EP1(x) (M_ROTRIGHT(x,6) ^ M_ROTRIGHT(x,11) ^ M_ROTRIGHT(x,25))
#define M_SIG0(x) (M_ROTRIGHT(x,7) ^ M_ROTRIGHT(x,18) ^ ((x) >> 3))
#define M_SIG1(x) (M_ROTRIGHT(x,17) ^ M_ROTRIGHT(x,19) ^ ((x) >> 10))
*/
/**************************** VARIABLES *****************************/
const uint32_t k[64] = {
    0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
    0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
    0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
    0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
    0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
    0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
    0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
    0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

/*********************** FUNCTION DEFINITIONS ***********************/

void SHA_sha256_transform(ts_LIBUTI_SHA_SHA256_ctx * const Ctx, const uint8_t Data[]) /* %RELAX<SYNCHRONe_C_Code_8.12> The size of Data is not known */
{
   uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, mi2, mi15;
   uint32_t m[64] = {0};
   j = (uint32_t)0;
   for (i = (uint32_t)0; i < (uint32_t)16; ++i)
   {
       m[i] = ((uint32_t) Data[j] << (uint32_t)24) | ((uint32_t) Data[j + (uint32_t)1] << (uint32_t)16) | 
			  ((uint32_t) Data[j + (uint32_t)2] << (uint32_t)8) | ((uint32_t) Data[j + (uint32_t)3]);
       j += (uint32_t)4;
   }
   for (i = (uint32_t)16 ; i < (uint32_t)64; ++i)
   {
	   /*
       m[i] = M_SIG1(m[i - 2]) + m[i - 7] + M_SIG0(m[i - 15]) + m[i - 16];
	   */
	   mi2 = m[i - (uint32_t)2];
	   mi15 = m[i - (uint32_t)15];
	   m[i] = (((mi2 >> (uint32_t)17) | (mi2 << (uint32_t)15)) ^ ((mi2 >> (uint32_t)19) | (mi2 << (uint32_t)13)) ^ (mi2 >> (uint32_t)10)) + 
			  (((mi15 >> (uint32_t)7) | (mi15 << (uint32_t)25)) ^ ((mi15 >> (uint32_t)18) | (mi15 << (uint32_t)14)) ^ (mi15 >> (uint32_t)3)) +
			  m[i - (uint32_t)7] + m[i - (uint32_t)16];
   }
   a = Ctx->State[0];
   b = Ctx->State[1];
   c = Ctx->State[2];
   d = Ctx->State[3];
   e = Ctx->State[4]; 
   f = Ctx->State[5];
   g = Ctx->State[6];
   h = Ctx->State[7];

   for (i = (uint32_t)0; i < (uint32_t)64; ++i)
   {
	   /*
       t1 = h + M_EP1(e) + M_CH(e,f,g) + k[i] + m[i];
       t2 = M_EP0(a) + M_MAJ(a,b,c);
	   */
	   t1 = h + (((e >> (uint32_t)6) | (e << (uint32_t)26)) ^ ((e >> (uint32_t)11) | (e << (uint32_t)21)) ^ ((e >> (uint32_t)25) | (e << (uint32_t)7)))+ 
			((e & f) ^ ((~e) & g)) + k[i] + m[i];
	   
	   t2 = (((a >> (uint32_t)2) | (a << (uint32_t)30)) ^ ((a >> (uint32_t)13) | (a << (uint32_t)19)) ^ ((a >> (uint32_t)22) | (a << (uint32_t)10)))+
			((a & b) ^ (a & c) ^ (b & c));
			
       h = g;
       g = f;
       f = e;
       e = d + t1;
       d = c;
       c = b;
       b = a;
       a = t1 + t2;
   }
   Ctx->State[0] += a;
   Ctx->State[1] += b;
   Ctx->State[2] += c;
   Ctx->State[3] += d;
   Ctx->State[4] += e;
   Ctx->State[5] += f;
   Ctx->State[6] += g;
   Ctx->State[7] += h;
}