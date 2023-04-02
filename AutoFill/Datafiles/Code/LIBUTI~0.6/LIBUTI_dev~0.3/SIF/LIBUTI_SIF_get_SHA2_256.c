#include "LIBUTI_SIF.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_getters_from_headers.h"

 TE_LIBUTI_SIF_status LIBUTI_SIF_get_SHA2_256(const uint8_t *DecodedHeaderAddress, const uint8_t *FileName, const uint32_t FileNameLength, ts_LIBUTI_SHA_SHA256 * const p_out) {     TE_LIBUTI_SIF_status ret;     tu_LIBUTI_SIF_hash buf;     ret = LIBUTI_SIF_get_hash(DecodedHeaderAddress, FileName, FileNameLength, E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256, &buf);     if (ret == E_LIBUTI_SIF_SUCCESS)     {         *p_out = buf.sha256;     }     return ret; }
