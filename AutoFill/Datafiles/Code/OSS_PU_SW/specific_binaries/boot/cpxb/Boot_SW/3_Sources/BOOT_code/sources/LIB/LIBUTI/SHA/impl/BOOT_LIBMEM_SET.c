#include "LIBUTI_SHA.h"
#include "BOOT_LIBMEM_public.h"

 	   BOOT_LIBMEM_SET( &Ctx->Data_SHA512_ctx[i], 0, SHA512_MAXLASTIEST_BLOCK_NUMBER - i );    }    else    { 	   if (i < SHA512_HIGH_BLOCK_NUMBER) { 		   BOOT_LIBMEM_SET( &Ctx->Data_SHA512_ctx[i], 0, SHA512_HIGH_BLOCK_NUMBER - i ); 	   } 	   SHA_sha512_transform( Ctx, (uint64_t *) Ctx->Data_SHA512_ctx ); 	   BOOT_LIBMEM_SET( Ctx->Data_SHA512_ctx, 0, SHA512_HIGH_BLOCK_NUMBER - 2);    }
