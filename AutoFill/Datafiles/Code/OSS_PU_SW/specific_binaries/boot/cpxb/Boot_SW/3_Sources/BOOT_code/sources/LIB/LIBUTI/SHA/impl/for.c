#include "LIBUTI_SHA.h"
#include "BOOT_LIBMEM_public.h"

    for ( i = (uint32_t)0; i < Length; ++i  )    {       Ctx->Data_SHA512_ctx[Ctx->Datalen] = Data[i];        Ctx->Datalen++;       if (Ctx->Datalen == SHA512_HIGH_BLOCK_NUMBER)       {          SHA_sha512_transform( Ctx, (uint64_t *) Ctx->Data_SHA512_ctx );          Ctx->Bitlen[0] += (uint64_t)Ctx->Datalen * 8;          if (Ctx->Bitlen[0] < (Ctx->Datalen * 8)) {Ctx->Bitlen[1]++;}          Ctx->Datalen = (uint32_t)0;       }    }
