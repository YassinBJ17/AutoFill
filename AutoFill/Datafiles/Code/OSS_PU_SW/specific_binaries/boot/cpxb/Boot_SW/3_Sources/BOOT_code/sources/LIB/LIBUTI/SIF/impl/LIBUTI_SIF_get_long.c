#include "LIBUTI_SIF_getters_from_headers.h"
#include "BOOT_LIBMEM_public.h"

 uint32_t LIBUTI_SIF_get_long( ts_LIBUTI_SIF_header_iterator * const hiter ) {    uint32_t ret;    uint32_t v_idx;    ret = (uint32_t)0;    for( v_idx = (uint32_t)0; v_idx < (uint32_t)4; v_idx++ )    {       ret = (uint32_t) ((uint32_t)ret << 8) + (uint32_t)(hiter->header[hiter->position]);       hiter->position++;       if ( hiter->position > hiter->header_length )       {          break;       }    }    return ( ret ); }
