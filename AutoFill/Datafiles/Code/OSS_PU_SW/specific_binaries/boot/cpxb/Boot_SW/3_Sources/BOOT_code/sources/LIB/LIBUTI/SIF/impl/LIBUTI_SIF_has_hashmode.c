#include "LIBUTI_SIF.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_SIF_getters_from_headers.h"
#include "BOOT_LIBMEM_public.h"

 te_CMN_FLAG_QUESTION LIBUTI_SIF_has_hashmode(    const uint8_t                  *DecodedHeaderAddress,    const uint8_t                  *FileName,    const uint32_t                 FileNameLength,    TE_LIBUTI_SIF_check_algorithm       *hashmode ) {    ts_LIBUTI_SIF_file_info     v_finfo;    ts_LIBUTI_SIF_global_check  v_gcheck;    ts_LIBUTI_SIF_iterator      v_fiter, v_giter;    TE_LIBUTI_SIF_status        status;    te_CMN_FLAG_QUESTION        is_hashmode;    status = LIBUTI_SIF_init_file_iterator( DecodedHeaderAddress, &v_fiter );    while ( status == E_LIBUTI_SIF_SUCCESS )    {       status = LIBUTI_SIF_get_next_file( &v_finfo, &v_fiter );       if ( ( status == E_LIBUTI_SIF_SUCCESS ) && ( FileNameLength == v_finfo.Name.Length ) )       {          if ( BOOT_LIBMEM_NOTEQUAL( FileName, v_finfo.Name.Name, v_finfo.Name.Length ) == e_CMN_FLAG_NO )          {             break;          }       }    }    LIBUTI_SIF_init_global_check_iterator( &v_finfo, &v_fiter, &v_giter );    status = LIBUTI_SIF_get_next_global_check( &v_gcheck, &v_giter );    if ( status == E_LIBUTI_SIF_SUCCESS )    {       is_hashmode = e_CMN_FLAG_YES;       *hashmode = v_gcheck.check_type;    }    else    {       *hashmode = E_LIBUTI_SIF_CHECK_ALGORITHM_MD5;       is_hashmode = e_CMN_FLAG_NO;    }    return ( is_hashmode ); }
