#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_getters_from_headers.h"

 void LIBUTI_SIF_get_strl(ts_LIBUTI_SIF_header_iterator * const hiter, TS_LIBUTI_SIF_Name_WithLength *out) {     out->Length = LIBUTI_SIF_get_short(hiter);     LIBUTI_SIF_get_str(hiter, (uint32_t)(out->Length), out->Name); }
