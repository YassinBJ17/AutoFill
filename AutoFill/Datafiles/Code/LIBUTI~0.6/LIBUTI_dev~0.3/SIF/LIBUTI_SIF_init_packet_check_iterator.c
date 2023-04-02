#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_getters_from_headers.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_get_next_file_skip.h"

 void LIBUTI_SIF_init_packet_check_iterator(const ts_LIBUTI_SIF_file_info * const finfo, const ts_LIBUTI_SIF_iterator * const fiter, ts_LIBUTI_SIF_iterator * const iter) {     iter->data = fiter->data;     iter->item_count = finfo->packet_check_number;     iter->format_version = fiter->format_version;     iter->format_revision = fiter->format_revision;     if (finfo->packet_check_number == (uint16_t)0)     {         iter->data.position = iter->data.header_length;     }     else     {         iter->data.position = finfo->first_packet_check_addr;     } }
