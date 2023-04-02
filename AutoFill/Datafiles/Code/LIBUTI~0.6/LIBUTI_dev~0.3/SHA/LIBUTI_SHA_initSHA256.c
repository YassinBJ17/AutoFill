#include "LIBUTI_SHA.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SHA_Transform.h"

 void LIBUTI_SHA_initSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx) {    Ctx->Datalen = (uint32_t)0;    Ctx->Bitlen = (uint64_t)0;    Ctx->State[0] = (uint32_t)0x6a09e667;    Ctx->State[1] = (uint32_t)0xbb67ae85;    Ctx->State[2] = (uint32_t)0x3c6ef372;    Ctx->State[3] = (uint32_t)0xa54ff53a;    Ctx->State[4] = (uint32_t)0x510e527f;    Ctx->State[5] = (uint32_t)0x9b05688c;    Ctx->State[6] = (uint32_t)0x1f83d9ab;    Ctx->State[7] = (uint32_t)0x5be0cd19; }
