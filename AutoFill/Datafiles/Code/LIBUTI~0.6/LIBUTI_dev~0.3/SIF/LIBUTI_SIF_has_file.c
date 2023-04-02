#include "LIBUTI_SIF.h"
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_getters_from_headers.h"

 boolean_t LIBUTI_SIF_has_file(const uint8_t *DecodedHeaderAddress, const uint8_t *FileName, const uint32_t FileNameLength) {     ts_LIBUTI_SIF_file_info v_finfo;     ts_LIBUTI_SIF_iterator v_fiter;     boolean_t is_file;     TE_LIBUTI_SIF_status status;     is_file = FALSE; 	v_finfo.Name.Length = (uint16_t)0;     status = LIBUTI_SIF_init_file_iterator(DecodedHeaderAddress, &v_fiter);     if (status == E_LIBUTI_SIF_SUCCESS)     {         status = LIBUTI_SIF_get_next_file(&v_finfo, &v_fiter);     }     while(status != E_LIBUTI_SIF_FAILURE && (!is_file))     {         if((uint32_t)(v_finfo.Name.Length) == FileNameLength)         {             is_file = !LIBUTI_MEM_MemsNotEqual(FileName, v_finfo.Name.Name, (uint32_t)(v_finfo.Name.Length));         }         else         {             is_file = FALSE;         }         status = LIBUTI_SIF_get_next_file(&v_finfo, &v_fiter);     }     return is_file; }
