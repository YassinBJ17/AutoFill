#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_getters_from_headers.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_get_next_file_skip.h"

 TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_target(ts_LIBUTI_SIF_target * const target, ts_LIBUTI_SIF_iterator * const iter) {     uint32_t next_ptr; 	TE_LIBUTI_SIF_status ret;     ret = E_LIBUTI_SIF_FAILURE;     if (iter->data.position < iter->data.header_length)     {         LIBUTI_MEM_MemSet( (uint8_t *) target, (uint8_t)0, sizeof(ts_LIBUTI_SIF_target));          next_ptr = LIBUTI_SIF_get_long(&(iter->data));         iter->item_count--;         if (next_ptr == (uint32_t)0 || iter->item_count == (uint16_t)0)         {             next_ptr = iter->data.header_length;         }         else         {             next_ptr += iter->data.position - (uint32_t)4;         }         LIBUTI_SIF_get_strl(&(iter->data), &(target->hardware_identifier));         LIBUTI_SIF_get_strl(&(iter->data), &(target->Name));         ret = E_LIBUTI_SIF_SUCCESS;         iter->data.position = next_ptr;     }     return ret; }
