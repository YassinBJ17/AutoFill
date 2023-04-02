#include "LIBUTI_SIF_getters_from_headers.h"
#include "BOOT_LIBMEM_public.h"

 uint16_t LIBUTI_SIF_get_short( ts_LIBUTI_SIF_header_iterator * const hiter ) {    uint16_t ret;    uint32_t v_idx;     ret = (uint16_t)0;    for( v_idx = (uint32_t)0; v_idx < (uint32_t)2; v_idx++ )    {       ret = (uint16_t) ((uint16_t)ret << 8) + (uint16_t)(hiter->header[hiter->position]);        hiter->position++;       if ( hiter->position > hiter->header_length )       {          break;       }    }    return ( ret ); }
