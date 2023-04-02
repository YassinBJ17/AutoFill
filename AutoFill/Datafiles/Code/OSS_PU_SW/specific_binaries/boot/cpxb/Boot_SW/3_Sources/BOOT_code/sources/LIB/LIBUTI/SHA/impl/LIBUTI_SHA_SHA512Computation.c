/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
/*************************** HEADER FILES ***************************/
#include "LIBUTI_SHA.h"
#include "BOOT_LIBMEM_public.h"

/****************************** MACROS ******************************/
#define M(i) m[(i) & 0x0F]

#define SHA512_ROTR(a,b)  ( ( (a) >> (b) ) | ( (a) << (64 - b) ) )

/* Two of six logical functions used in SHA-256, SHA-384, and SHA-512: */
#define SHA512_CH(x,y,z)	(((x) & (y)) ^ ((~(x)) & (z)))
#define SHA512_MAJ(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define SHA512_EP0(x)  (SHA512_ROTR((x),28) ^ SHA512_ROTR((x),34) ^ SHA512_ROTR((x),39))
#define SHA512_EP1(x)  (SHA512_ROTR((x),14) ^ SHA512_ROTR((x),18) ^ SHA512_ROTR((x),41))
#define SHA512_SIG0(x)  (SHA512_ROTR((x),1)  ^ SHA512_ROTR((x),8)  ^ ((x)>>7))
#define SHA512_SIG1(x)  (SHA512_ROTR((x),19) ^ SHA512_ROTR((x),61) ^ ((x)>>6))

//
/**************************** VARIABLES *****************************/
/* SHA-512 use a sequence of eighty constant 64-bit words. These words represent the
 first sixty-four bits of the fractional parts of the cube roots of the first eighty
 prime numbers. In hex, these constant words are (from left to right).*/

static const uint64_t k[80] =
{
   0x428A2F98D728AE22, 0x7137449123EF65CD, 0xB5C0FBCFEC4D3B2F, 0xE9B5DBA58189DBBC,
   0x3956C25BF348B538, 0x59F111F1B605D019, 0x923F82A4AF194F9B, 0xAB1C5ED5DA6D8118,
   0xD807AA98A3030242, 0x12835B0145706FBE, 0x243185BE4EE4B28C, 0x550C7DC3D5FFB4E2,
   0x72BE5D74F27B896F, 0x80DEB1FE3B1696B1, 0x9BDC06A725C71235, 0xC19BF174CF692694,
   0xE49B69C19EF14AD2, 0xEFBE4786384F25E3, 0x0FC19DC68B8CD5B5, 0x240CA1CC77AC9C65,
   0x2DE92C6F592B0275, 0x4A7484AA6EA6E483, 0x5CB0A9DCBD41FBD4, 0x76F988DA831153B5,
   0x983E5152EE66DFAB, 0xA831C66D2DB43210, 0xB00327C898FB213F, 0xBF597FC7BEEF0EE4,
   0xC6E00BF33DA88FC2, 0xD5A79147930AA725, 0x06CA6351E003826F, 0x142929670A0E6E70,
   0x27B70A8546D22FFC, 0x2E1B21385C26C926, 0x4D2C6DFC5AC42AED, 0x53380D139D95B3DF,
   0x650A73548BAF63DE, 0x766A0ABB3C77B2A8, 0x81C2C92E47EDAEE6, 0x92722C851482353B,
   0xA2BFE8A14CF10364, 0xA81A664BBC423001, 0xC24B8B70D0F89791, 0xC76C51A30654BE30,
   0xD192E819D6EF5218, 0xD69906245565A910, 0xF40E35855771202A, 0x106AA07032BBD1B8,
   0x19A4C116B8D2D0C8, 0x1E376C085141AB53, 0x2748774CDF8EEB99, 0x34B0BCB5E19B48A8,
   0x391C0CB3C5C95A63, 0x4ED8AA4AE3418ACB, 0x5B9CCA4F7763E373, 0x682E6FF3D6B2B8A3,
   0x748F82EE5DEFB2FC, 0x78A5636F43172F60, 0x84C87814A1F0AB72, 0x8CC702081A6439EC,
   0x90BEFFFA23631E28, 0xA4506CEBDE82BDE9, 0xBEF9A3F7B2C67915, 0xC67178F2E372532B,
   0xCA273ECEEA26619C, 0xD186B8C721C0C207, 0xEADA7DD6CDE0EB1E, 0xF57D4F7FEE6ED178,
   0x06F067AA72176FBA, 0x0A637DC5A2C898A6, 0x113F9804BEF90DAE, 0x1B710B35131C471B,
   0x28DB77F523047D84, 0x32CAAB7B40C72493, 0x3C9EBE0A15C9BEBC, 0x431D67C49C100D4C,
   0x4CC5D4BECB3E42B6, 0x597F299CFC657E2A, 0x5FCB6FAB3AD6FAEC, 0x6C44198C4A475817
};

/*********************** FUNCTION DEFINITIONS ***********************/

void SHA_sha512_transform(
   ts_LIBUTI_SHA_SHA512_ctx * const Ctx,
   const uint64_t Data[]
) /* %RELAX<SYNCHRONe_C_Code_8.12> The size of Data is not known */
{
   uint64_t a, b, c, d, e, f, g, h, t1, t2, m[80];
   uint32_t i;

   /* Initialize the eight working variables, a, b, c, d, e, f, g, and h, with the (i-1)st hash value */
   a = Ctx->State[0];
   b = Ctx->State[1];
   c = Ctx->State[2];
   d = Ctx->State[3];
   e = Ctx->State[4];
   f = Ctx->State[5];
   g = Ctx->State[6];
   h = Ctx->State[7];

   /* For t = 0 to 16 */
   for ( i = (uint32_t)0 ; i < (uint32_t)16 ; ++i )
   {
	  m[i] = Data[i];
      t1 = h + SHA512_EP1(e) + SHA512_CH(e,f,g) + k[i] + m[i];
      t2 = SHA512_EP0(a) + SHA512_MAJ(a,b,c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
   }

   /* For t = 0 to 16 */
   for ( i = (uint32_t)16 ; i < (uint32_t)80 ; ++i )
   {
	  M(i) += SHA512_SIG1(M(i+14)) + M(i+9) + SHA512_SIG0(M(i+1));
      t1 = h + SHA512_EP1(e) + SHA512_CH(e,f,g) + k[i] + M(i);
      t2 = SHA512_EP0(a) + SHA512_MAJ(a,b,c);
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


void LIBUTI_SHA_initSHA512(ts_LIBUTI_SHA_SHA512_ctx* const Ctx) {

	BOOT_LIBMEM_SET( Ctx->Data_SHA512_ctx, 0, 128 );

	Ctx->Bitlen[1] = (uint64_t)0;
	Ctx->Bitlen[0]  = (uint64_t)0;

	/*For SHA-512, the initial hash value, H(0), shall consist of the following eight 64-bit words,
	in hex:*/
	Ctx->State[0] = (uint64_t)0x6A09E667F3BCC908;
	Ctx->State[1] = (uint64_t)0xBB67AE8584CAA73B;
	Ctx->State[2] = (uint64_t)0x3C6EF372FE94F82B;
	Ctx->State[3] = (uint64_t)0xA54FF53A5F1D36F1;
	Ctx->State[4] = (uint64_t)0x510E527FADE682D1;
	Ctx->State[5] = (uint64_t)0x9B05688C2B3E6C1F;
	Ctx->State[6] = (uint64_t)0x1F83D9ABFB41BD6B;
	Ctx->State[7] = (uint64_t)0x5BE0CD19137E2179;
}


void LIBUTI_SHA_updateSHA512(
   /* OUT */
   ts_LIBUTI_SHA_SHA512_ctx * const Ctx,
   /* IN */
   const uint8_t *          Data,         // Adress of the message start
   const uint32_t           Length        // Lenght of the message from buffer
)
{
   uint32_t i;

   Ctx->Datalen = 0;

   for ( i = (uint32_t)0; i < Length; ++i  )
   {
      Ctx->Data_SHA512_ctx[Ctx->Datalen] = Data[i]; /* %RELAX<SYNCHRONe_C_Code_17.4> Here Data is used like a buffer */
      Ctx->Datalen++;
      if (Ctx->Datalen == SHA512_HIGH_BLOCK_NUMBER)
      {
         SHA_sha512_transform( Ctx, (uint64_t *) Ctx->Data_SHA512_ctx );
         Ctx->Bitlen[0] += (uint64_t)Ctx->Datalen * 8;
         if (Ctx->Bitlen[0] < (Ctx->Datalen * 8)) {Ctx->Bitlen[1]++;}
         Ctx->Datalen = (uint32_t)0;
      }
   }

   if (Ctx->Datalen > 0){
	   BOOT_LIBMEM_CPY( Ctx->Data_SHA512_ctx, &Data[ Length - Ctx->Datalen], Ctx->Datalen );
       Ctx->Bitlen[0] += (uint64_t)Ctx->Datalen * 8;
       if (Ctx->Bitlen[0] < (Ctx->Datalen * 8)) {Ctx->Bitlen[1]++;}
   }
}

void LIBUTI_SHA_finalSHA512(
   /* IN */
   ts_LIBUTI_SHA_SHA512_ctx * const Ctx,
   /* OUT */
   ts_LIBUTI_SHA_SHA512 * const ComputedHash)
{
   uint32_t i;

   i = Ctx->Datalen;;

   Ctx->Data_SHA512_ctx[i++] = (uint8_t)0x80;

   if ( i <  SHA512_MAXLASTIEST_BLOCK_NUMBER  )
   {
	   BOOT_LIBMEM_SET( &Ctx->Data_SHA512_ctx[i], 0, SHA512_MAXLASTIEST_BLOCK_NUMBER - i );
   }
   else
   {
	   if (i < SHA512_HIGH_BLOCK_NUMBER) {
		   BOOT_LIBMEM_SET( &Ctx->Data_SHA512_ctx[i], 0, SHA512_HIGH_BLOCK_NUMBER - i );
	   }

	   SHA_sha512_transform( Ctx, (uint64_t *) Ctx->Data_SHA512_ctx );

	   BOOT_LIBMEM_SET( Ctx->Data_SHA512_ctx, 0, SHA512_HIGH_BLOCK_NUMBER - 2);
   }

   Ctx->Data_SHA512_ctx[127] = (uint8_t) (Ctx->Bitlen[0]);
   Ctx->Data_SHA512_ctx[126] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[0]) ,8);
   Ctx->Data_SHA512_ctx[125] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[0]) , 16);
   Ctx->Data_SHA512_ctx[124] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[0]) , 24);
   Ctx->Data_SHA512_ctx[123] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[0]) , 32);
   Ctx->Data_SHA512_ctx[122] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[0]) , 40);
   Ctx->Data_SHA512_ctx[121] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[0]) , 48);
   Ctx->Data_SHA512_ctx[120] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[0]) , 56);
   Ctx->Data_SHA512_ctx[119] = (uint8_t) (Ctx->Bitlen[1]);
   Ctx->Data_SHA512_ctx[118] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[1]) , 8);
   Ctx->Data_SHA512_ctx[117] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[1]) , 16);
   Ctx->Data_SHA512_ctx[116] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[1]) , 24);
   Ctx->Data_SHA512_ctx[115] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[1]) , 32);
   Ctx->Data_SHA512_ctx[114] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[1]) , 40);
   Ctx->Data_SHA512_ctx[113] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[1]) , 48);
   Ctx->Data_SHA512_ctx[112] = (uint8_t) SHA512_ROTR((Ctx->Bitlen[1]) , 56);

   SHA_sha512_transform( Ctx, (uint64_t *) Ctx->Data_SHA512_ctx );

   BOOT_LIBMEM_CPY( ComputedHash, Ctx->State, SHA512_BLOCK_SIZE );

   BOOT_LIBMEM_SET( (uint8_t*) Ctx, 0, sizeof(ts_LIBUTI_SHA_SHA512_ctx) );

}
