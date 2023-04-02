#include "LIBUTI_SIF.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_getters_from_headers.h"

 uint16_t LIBUTI_SIF_file_count(const uint8_t *DecodedHeaderAddress) {     ts_LIBUTI_SIF_iterator fiter;     TE_LIBUTI_SIF_status status;     uint16_t ret;     status = LIBUTI_SIF_init_file_iterator(DecodedHeaderAddress, &fiter);     if (status == E_LIBUTI_SIF_SUCCESS)     {         ret = fiter.item_count;     }     else     {         ret = (uint16_t)0;     }     return ret; }
