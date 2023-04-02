/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/*************************** HEADER FILES ***************************/

#include "LIBUTI_SHA.h"
#include "BOOT_LIBMEM_public.h"

/****************************** MACROS ******************************/
#define M_ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define M_ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define M_CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define M_MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define M_EP0(x) (M_ROTRIGHT(x,2) ^ M_ROTRIGHT(x,13) ^ M_ROTRIGHT(x,22))
#define M_EP1(x) (M_ROTRIGHT(x,6) ^ M_ROTRIGHT(x,11) ^ M_ROTRIGHT(x,25))
#define M_SIG0(x) (M_ROTRIGHT(x,7) ^ M_ROTRIGHT(x,18) ^ ((x) >> 3))
#define M_SIG1(x) (M_ROTRIGHT(x,17) ^ M_ROTRIGHT(x,19) ^ ((x) >> 10))

/**************************** VARIABLES *****************************/
/*SHA-256 use a sequence of sixty-four constant 32-bit words. These words represent the
first thirty-two bits of the fractional parts of the cube roots of the first sixty-four
prime numbers. In hex, these constant words are (from left to right) */

static const uint32_t k[64] =
{
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

void SHA_sha256_transform( ts_LIBUTI_SHA_SHA256_ctx * const Ctx, const uint8_t Data[] ) /* %RELAX<SYNCHRONe_C_Code_8.12> The size of Data is not known */
{
   uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];
   j = (uint32_t)0;
   /* Prepare the message schedule, {Mt} in 32-bits words : */
   /* {Wt} = Mt(t) for 0 <= t <= 15 */
   for ( i = (uint32_t)0; i < (uint32_t)16; ++i )
   {
      m[i] = (Data[j] << (uint32_t)24) | (Data[j + (uint32_t)1] << (uint32_t)16) | (Data[j + (uint32_t)2] << (uint32_t)8) | (Data[j + (uint32_t)3]);
      j += (uint32_t)4;
   }

   /* {Wt} = M_SIG1( Mt(t-2) ) + Mt(t-7) + M_SIG0( Mt(t-15) ) + Mt(t-16) for 16 <= t <= 63 */
   for ( i = (uint32_t)16 ; i < (uint32_t)64; ++i )
   {
      m[i] = M_SIG1(m[i - (uint32_t)2]) + m[i - (uint32_t)7] + M_SIG0(m[i - (uint32_t)15]) + m[i - (uint32_t)16];
   }

   /* Initialize the eight working variables, a, b, c, d, e, f, g, and h, with the (i-1)st hash value: */
   a = Ctx->State[0];
   b = Ctx->State[1];
   c = Ctx->State[2];
   d = Ctx->State[3];
   e = Ctx->State[4];
   f = Ctx->State[5];
   g = Ctx->State[6];
   h = Ctx->State[7];

   /* For t=0 to 63: */
   for ( i = (uint32_t)0; i < (uint32_t)64; ++i )
   {
      t1 = h + M_EP1(e) + M_CH(e,f,g) + k[i] + m[i];
      t2 = M_EP0(a) + M_MAJ(a,b,c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
   }

   /* Compute the ith intermediate hash value H(i): */
   Ctx->State[0] += a;
   Ctx->State[1] += b;
   Ctx->State[2] += c;
   Ctx->State[3] += d;
   Ctx->State[4] += e;
   Ctx->State[5] += f;
   Ctx->State[6] += g;
   Ctx->State[7] += h;
}

void LIBUTI_SHA_initSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx)
{
   BOOT_LIBMEM_SET( Ctx->Data_SHA256_ctx, 0, 64 );
   Ctx->Datalen = (uint32_t)0;
   Ctx->Bitlen  = (uint64_t)0;
   /* For SHA-256, the initial hash value, H(0), shall consist of the following eight 32-bit words,
    in hex: */
   Ctx->State[0] = (uint32_t)0x6a09e667;
   Ctx->State[1] = (uint32_t)0xbb67ae85;
   Ctx->State[2] = (uint32_t)0x3c6ef372;
   Ctx->State[3] = (uint32_t)0xa54ff53a;
   Ctx->State[4] = (uint32_t)0x510e527f;
   Ctx->State[5] = (uint32_t)0x9b05688c;
   Ctx->State[6] = (uint32_t)0x1f83d9ab;
   Ctx->State[7] = (uint32_t)0x5be0cd19;
}

void LIBUTI_SHA_updateSHA256( ts_LIBUTI_SHA_SHA256_ctx * const Ctx, const uint8_t *Data, const uint32_t Length )
{
   uint32_t i;

   for ( i = (uint32_t)0; i < Length; ++i  )
   {
      Ctx->Data_SHA256_ctx[Ctx->Datalen] = Data[i]; /* %RELAX<SYNCHRONe_C_Code_17.4> Here Data is used like a buffer */
      Ctx->Datalen++;
      if (Ctx->Datalen == SHA256_HIGH_BLOCK_NUMBER)
      {
         SHA_sha256_transform( Ctx, Ctx->Data_SHA256_ctx );
         Ctx->Bitlen += (uint64_t)512;
         Ctx->Datalen = (uint32_t)0;
      }
   }
}

void LIBUTI_SHA_finalSHA256( ts_LIBUTI_SHA_SHA256_ctx * const Ctx, ts_LIBUTI_SHA_SHA256 * const ComputedHash )
{
   uint32_t i;

   i = Ctx->Datalen;

   /* Pad whatever data is left in the buffer. */
   if ( Ctx->Datalen < ( SHA256_MAXLASTIEST_BLOCK_NUMBER + 1 ) )
   {
      Ctx->Data_SHA256_ctx[i] = (uint8_t)0x80;
      i++;
      while ( i < ( SHA256_MAXLASTIEST_BLOCK_NUMBER + 1 ) )
      {
         Ctx->Data_SHA256_ctx[i] = (uint8_t)0x00;
         i++;
      }
   }
   else
   {
      Ctx->Data_SHA256_ctx[i] = (uint8_t)0x80;
      i++;
      while ( i < SHA256_HIGH_BLOCK_NUMBER )
      {
         Ctx->Data_SHA256_ctx[i] = (uint8_t)0x00;
         i++;
      }
      SHA_sha256_transform( Ctx, Ctx->Data_SHA256_ctx );
      BOOT_LIBMEM_SET( Ctx->Data_SHA256_ctx, 0, 56 );
   }


   /*{{RELAX<SYNCHRONe_C_Code_10.7>*/
   /*For the line 95 to 102 >> and cast to uint8_t are used to split the uint64_t variable in 8 uint8_t*/
   /* Here the loss of precision is wanted*/
   /*It is the same goal for the line 109 to 116*/
   
   /* Append to the padding the total message's length in bits and transform. */
   Ctx->Bitlen += Ctx->Datalen * 8;
   Ctx->Data_SHA256_ctx[63] = (uint8_t) (Ctx->Bitlen);
   Ctx->Data_SHA256_ctx[62] = (uint8_t) (Ctx->Bitlen >> 8);
   Ctx->Data_SHA256_ctx[61] = (uint8_t) (Ctx->Bitlen >> 16);
   Ctx->Data_SHA256_ctx[60] = (uint8_t) (Ctx->Bitlen >> 24);
   Ctx->Data_SHA256_ctx[59] = (uint8_t) (Ctx->Bitlen >> 32);
   Ctx->Data_SHA256_ctx[58] = (uint8_t) (Ctx->Bitlen >> 40);
   Ctx->Data_SHA256_ctx[57] = (uint8_t) (Ctx->Bitlen >> 48);
   Ctx->Data_SHA256_ctx[56] = (uint8_t) (Ctx->Bitlen >> 56);
   SHA_sha256_transform( Ctx, Ctx->Data_SHA256_ctx );

   /* Since this implementation uses little endian byte ordering and SHA uses big endian,
   ** reverse all the bytes when copying the final State to the output hash.
   ***/
   for ( i = (uint32_t)0; i < (uint32_t)4; ++i )
   {
      ComputedHash->Data_SHA256[i              ]  = (uint8_t)((Ctx->State[0] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
      ComputedHash->Data_SHA256[i + (uint32_t)4]  = (uint8_t)((Ctx->State[1] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
      ComputedHash->Data_SHA256[i + (uint32_t)8]  = (uint8_t)((Ctx->State[2] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
      ComputedHash->Data_SHA256[i + (uint32_t)12] = (uint8_t)((Ctx->State[3] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
      ComputedHash->Data_SHA256[i + (uint32_t)16] = (uint8_t)((Ctx->State[4] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
      ComputedHash->Data_SHA256[i + (uint32_t)20] = (uint8_t)((Ctx->State[5] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
      ComputedHash->Data_SHA256[i + (uint32_t)24] = (uint8_t)((Ctx->State[6] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
      ComputedHash->Data_SHA256[i + (uint32_t)28] = (uint8_t)((Ctx->State[7] >> ((uint32_t)24 - (i * (uint32_t)8))) & (uint32_t)0x000000ff);
   }
   
   /*}}RELAX<SYNCHRONe_C_Code_10.7> */
}
