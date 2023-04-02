#include "LIBUTI_SIF.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_getters_from_headers.h"

 TE_LIBUTI_SIF_status LIBUTI_SIF_get_software_info(const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_software_info * const out) {     ts_LIBUTI_SIF_header header;     ts_LIBUTI_SIF_header_iterator hiter;     TE_LIBUTI_SIF_status ret;     ret = LIBUTI_SIF_get_header(DecodedHeaderAddress, &header);     if (ret == E_LIBUTI_SIF_SUCCESS)     {         hiter.header = DecodedHeaderAddress;         hiter.header_length = header.header_length;         hiter.position = header.software_chars_abs_ptr;         LIBUTI_SIF_get_strl(&hiter, &(out->PN));         LIBUTI_SIF_get_strl(&hiter, &(out->Name));     }     return ret; }
