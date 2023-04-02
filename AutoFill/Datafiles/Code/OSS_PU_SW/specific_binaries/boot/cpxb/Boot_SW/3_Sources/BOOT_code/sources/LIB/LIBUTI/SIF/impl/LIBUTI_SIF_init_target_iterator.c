#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_getters_from_headers.h"
#include "LIBUTI_SIF_get_next_file_skip.h"
#include "BOOT_LIBMEM_public.h"

 TE_LIBUTI_SIF_status LIBUTI_SIF_init_target_iterator( const uint8_t * const DecodedHeaderAddress, ts_LIBUTI_SIF_iterator * const iter ) {    ts_LIBUTI_SIF_header header;    TE_LIBUTI_SIF_status ret;    ret = LIBUTI_SIF_get_header( DecodedHeaderAddress, &header );    if ( ret == E_LIBUTI_SIF_SUCCESS )    {       iter->data.header        = DecodedHeaderAddress;       iter->data.header_length = header.header_length;       iter->data.position      = header.targets_chars_abs_ptr;       iter->item_count         = LIBUTI_SIF_get_short( &(iter->data) );       iter->format_version     = header.format_version;       iter->format_revision    = header.format_revision;    }    return ( ret ); }
