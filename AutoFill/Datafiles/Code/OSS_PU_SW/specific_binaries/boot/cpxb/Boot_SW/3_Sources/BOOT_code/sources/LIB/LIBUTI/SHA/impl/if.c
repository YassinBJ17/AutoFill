#include "LIBUTI_SHA.h"
#include "BOOT_LIBMEM_public.h"

    if ( i <  SHA512_MAXLASTIEST_BLOCK_NUMBER  )    { 	   BOOT_LIBMEM_SET( &Ctx->Data_SHA512_ctx[i], 0, SHA512_MAXLASTIEST_BLOCK_NUMBER - i );    }
