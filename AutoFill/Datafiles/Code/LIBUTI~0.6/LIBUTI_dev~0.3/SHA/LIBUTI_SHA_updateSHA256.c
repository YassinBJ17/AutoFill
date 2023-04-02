#include "LIBUTI_SHA.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SHA_Transform.h"

 void LIBUTI_SHA_updateSHA256(ts_LIBUTI_SHA_SHA256_ctx * const Ctx, const uint8_t *Data, const uint32_t Length) {    uint32_t i;    for (i = (uint32_t)0; i < Length; ++i)     {        Ctx->Data[Ctx->Datalen] = Data[i];          Ctx->Datalen++;        if (Ctx->Datalen == (uint32_t)64)         {            SHA_sha256_transform(Ctx, Ctx->Data);            Ctx->Bitlen += (uint64_t)512;            Ctx->Datalen = (uint32_t)0;        }    } }
