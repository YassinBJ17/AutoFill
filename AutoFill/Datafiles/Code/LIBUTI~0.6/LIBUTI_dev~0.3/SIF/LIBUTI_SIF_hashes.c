/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_hashes.c
 * CSC name   : LIBUTI_SIF
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/csrc/LIBUTI_SIF_hashes.c/3 %
 *    Creation: Divided from LIBUTI_SIF_parsing.c on 04-02-2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */


/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SIF_hashes.h"
/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_MEM.h"
#include "Memcpy.h"
#include "LIBUTI_SIF_getters.h"
/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal macros: ---------------------------------------------- */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */



TE_LIBUTI_SIF_status LIBUTI_SIF_get_hash(const uint8_t * const DecodedHeaderAddress, const uint8_t *FileName, const uint32_t FileNameLength, const TE_LIBUTI_SIF_check_algorithm algo, tu_LIBUTI_SIF_hash * const hash_buffer) /* %RELAX<SYNCHRONe_C_Code_8.18> hash_buffer is output */
{
    ts_LIBUTI_SIF_file_info v_finfo;
    ts_LIBUTI_SIF_global_check v_gcheck;
    ts_LIBUTI_SIF_iterator v_fiter, v_giter;
    TE_LIBUTI_SIF_status ret;
    boolean_t test;
    uint32_t hash_length;
    ret = LIBUTI_SIF_init_file_iterator(DecodedHeaderAddress, &v_fiter);
    while (ret == E_LIBUTI_SIF_SUCCESS)
    {
        ret = LIBUTI_SIF_get_next_file(&v_finfo, &v_fiter);
        if ( (ret == E_LIBUTI_SIF_SUCCESS) && (FileNameLength == (uint32_t)(v_finfo.Name.Length)) )
        {
            test = LIBUTI_MEM_MemsNotEqual(FileName, v_finfo.Name.Name, (uint32_t)(v_finfo.Name.Length));
            if (test == FALSE)
            {
                break;
            }
        }
    }
    if(ret == E_LIBUTI_SIF_SUCCESS)
    {
        LIBUTI_SIF_init_global_check_iterator(&v_finfo, &v_fiter, &v_giter);
        ret = LIBUTI_SIF_get_next_global_check(&v_gcheck, &v_giter);
    }
    while (ret == E_LIBUTI_SIF_SUCCESS)
    {
        if (v_gcheck.check_type == algo)
        {
            break;
        }
        ret = LIBUTI_SIF_get_next_global_check(&v_gcheck, &v_giter);
    }
    if (ret == E_LIBUTI_SIF_SUCCESS)
    {
        hash_length = LIBUTI_SIF_get_hash_length(algo);
        LibC_Memcpy(hash_buffer->data, v_gcheck.check, hash_length);
    }
    return ret;
}

/* if the function is in an exported api */
/* Declaration of the function is in CSC_api.h */
