#include "LIBUTI_SHA_Transform.h"
#include "LIBUTI_SHA.h"

 void SHA_sha256_transform(ts_LIBUTI_SHA_SHA256_ctx * const Ctx, const uint8_t Data[])  {    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, mi2, mi15;    uint32_t m[64] = {0};
