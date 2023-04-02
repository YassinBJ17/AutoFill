#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_getters_from_headers.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_get_next_file_skip.h"

 TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_global_check(ts_LIBUTI_SIF_global_check * const check, ts_LIBUTI_SIF_iterator * const iter) {     uint32_t next_ptr, hash_length; 	TE_LIBUTI_SIF_status ret;     ret = E_LIBUTI_SIF_FAILURE;     if (iter->data.position < iter->data.header_length)     {         next_ptr = LIBUTI_SIF_get_long(&(iter->data));         iter->item_count--;         if (next_ptr == (uint32_t)0 || iter->item_count == (uint16_t)0)         {             next_ptr = iter->data.header_length;         }         else         {             next_ptr += iter->data.position - (uint32_t)4;         }         check->check_type = (TE_LIBUTI_SIF_check_algorithm) LIBUTI_SIF_get_short(&(iter->data));         hash_length = LIBUTI_SIF_get_hash_length(check->check_type);         LIBUTI_SIF_get_str(&(iter->data), hash_length, check->check);         iter->data.position = next_ptr;         ret = E_LIBUTI_SIF_SUCCESS;     }     return ret; }
