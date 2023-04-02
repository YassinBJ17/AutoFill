#include "LIBUTI_SIF_getters_from_headers.h"
#include "Memcpy.h"

 void LIBUTI_SIF_get_str(ts_LIBUTI_SIF_header_iterator * const hiter, const uint32_t len, uint8_t *const buffer) {     uint32_t tmp_len;     if (len > (uint32_t)C_MAX_STR_LENGTH)     {         tmp_len = (uint32_t)C_MAX_STR_LENGTH;     }     else      {         tmp_len = len;     }     if (hiter->position + tmp_len > hiter->header_length)     {         tmp_len = hiter->header_length - hiter->position;     }     LibC_Memcpy(buffer, hiter->header + hiter->position, tmp_len);     hiter->position += ( (tmp_len % (uint32_t)2) ? tmp_len + (uint32_t)1 : tmp_len); }
