#include "LIBUTI_SIF.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_SIF_getters_from_headers.h"
#include "BOOT_LIBMEM_public.h"

 te_CMN_FLAG_QUESTION LIBUTI_SIF_has_file( const uint8_t * DecodedHeaderAddress, const uint8_t * FileName, const uint32_t FileNameLength ) {    ts_LIBUTI_SIF_file_info v_finfo;    ts_LIBUTI_SIF_iterator  v_fiter;    te_CMN_FLAG_QUESTION    is_file;    TE_LIBUTI_SIF_status    status;    is_file = e_CMN_FLAG_NO;    v_finfo.Name.Length = (uint16_t)0;    status = LIBUTI_SIF_init_file_iterator( DecodedHeaderAddress, &v_fiter );    if ( status == E_LIBUTI_SIF_SUCCESS )    {       status = LIBUTI_SIF_get_next_file( &v_finfo, &v_fiter );    }    while( ( status != E_LIBUTI_SIF_FAILURE ) && ( is_file == e_CMN_FLAG_NO ) )    {       if ( (uint32_t)(v_finfo.Name.Length) == FileNameLength )       {             if ( BOOT_LIBMEM_NOTEQUAL(FileName, v_finfo.Name.Name, v_finfo.Name.Length) == e_CMN_FLAG_NO )             {                is_file = e_CMN_FLAG_YES;             }             else             {                is_file = e_CMN_FLAG_NO;             }       }       else       {           is_file = e_CMN_FLAG_NO;       }       status = LIBUTI_SIF_get_next_file( &v_finfo, &v_fiter );    }    return ( is_file ); }
