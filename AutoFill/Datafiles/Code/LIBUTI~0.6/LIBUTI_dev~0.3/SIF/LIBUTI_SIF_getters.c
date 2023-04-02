/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_getters.c
 * CSC name   : LIBUTI_SIF
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/csrc/LIBUTI_SIF_getters.c/4 %
 *    Creation: Divided from LIBUTI_SIF_parsing.c on 04-02-2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */


/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_getters_from_headers.h"
/* ---------- internal define constants: ------------------------------------ */
#define C_MIN_HEADER_LENGTH (122)

/* ---------- internal macros: ---------------------------------------------- */

/* Unneeded for now, in case of endianness */
/*
#define M_LIBUTI_SIF_FLIP32(VAL) (((VAL) >> 24) +\
                                 (((VAL) << 8) >> 16)+\
                                 (((VAL) << 16) >> 8)+\
                                 ((VAL) << 24))
#define M_LIBUTI_SIF_FLIP16(VAL) (((VAL) >> 8) + ((VAL) << 8)) 
*/

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

uint32_t LIBUTI_SIF_get_hash_length(const TE_LIBUTI_SIF_check_algorithm algo)
{
    uint32_t ret;
    switch (algo)
    {
    case E_LIBUTI_SIF_CHECK_ALGORITHM_MD5:
        ret = (uint32_t)16;
        break;
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA1:
        ret = (uint32_t)20;
        break;
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_256:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_256:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2S_256:
        ret = (uint32_t)32;
        break;
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_512:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_512:
    case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_512:
    default:
        ret = (uint32_t)64;
        break;
    }
    return ret;
}

TE_LIBUTI_SIF_status LIBUTI_SIF_get_header(const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_header * const out)
{
    TE_LIBUTI_SIF_status ret;
    ts_LIBUTI_SIF_header_iterator hiter;
    ret = E_LIBUTI_SIF_FAILURE;
    if (DecodedHeaderAddress != (uint8_t *)0)
    {
        hiter.header = DecodedHeaderAddress;
        hiter.header_length = (uint32_t)64;
        hiter.position = (uint32_t)0;
        out->header_length = LIBUTI_SIF_get_long(&hiter);
        out->format_version = LIBUTI_SIF_get_short(&hiter);
        out->format_revision = LIBUTI_SIF_get_short(&hiter);
        out->software_chars_abs_ptr = LIBUTI_SIF_get_long(&hiter);
        out->targets_chars_abs_ptr = LIBUTI_SIF_get_long(&hiter);
        out->tool_chars_abs_ptr = LIBUTI_SIF_get_long(&hiter);
        out->requester_info_abs_ptr = LIBUTI_SIF_get_long(&hiter);
        out->files_chars_abs_ptr = LIBUTI_SIF_get_long(&hiter);
        if (out->header_length >= (uint32_t)C_MIN_HEADER_LENGTH &&
            out->software_chars_abs_ptr < out->header_length &&
            out->targets_chars_abs_ptr < out->header_length)
        {
			
            if (out->tool_chars_abs_ptr < out->header_length &&
            out->requester_info_abs_ptr < out->header_length &&
            out->files_chars_abs_ptr < out->header_length)
			{
				ret = E_LIBUTI_SIF_SUCCESS;
			}
			
        }
    }
    return ret;
}



void LIBUTI_SIF_get_strl(ts_LIBUTI_SIF_header_iterator * const hiter, TS_LIBUTI_SIF_Name_WithLength *out)
{
    out->Length = LIBUTI_SIF_get_short(hiter);
    LIBUTI_SIF_get_str(hiter, (uint32_t)(out->Length), out->Name);
}
