/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_main.c
 * CSC name   : LIBUTI_SIF
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/csrc/LIBUTI_SIF_main.c/2 %
 *    Creation: Divided from LIBUTI_SIF_parsing.c on 04-02-2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */


/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SIF.h"
/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SIF_getters_from_headers.h"
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

TE_LIBUTI_SIF_status LIBUTI_SIF_get_software_info(const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_software_info * const out)
{
    ts_LIBUTI_SIF_header header;
    ts_LIBUTI_SIF_header_iterator hiter;
    TE_LIBUTI_SIF_status ret;
    ret = LIBUTI_SIF_get_header(DecodedHeaderAddress, &header);
    if (ret == E_LIBUTI_SIF_SUCCESS)
    {
        hiter.header = DecodedHeaderAddress;
        hiter.header_length = header.header_length;
        hiter.position = header.software_chars_abs_ptr;
        LIBUTI_SIF_get_strl(&hiter, &(out->PN));
        LIBUTI_SIF_get_strl(&hiter, &(out->Name));
    }
    return ret;
}

TE_LIBUTI_SIF_status LIBUTI_SIF_get_tool_chars(const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_tool_info * const out)
{
    ts_LIBUTI_SIF_header header;
    ts_LIBUTI_SIF_header_iterator hiter;
    TE_LIBUTI_SIF_status ret;
    ret = LIBUTI_SIF_get_header(DecodedHeaderAddress, &header);
    if (ret == E_LIBUTI_SIF_SUCCESS)
    {
        hiter.header = DecodedHeaderAddress;
        hiter.header_length = header.header_length;
        hiter.position = header.tool_chars_abs_ptr;
        LIBUTI_SIF_get_strl(&hiter, &(out->Name));
        LIBUTI_SIF_get_strl(&hiter, &(out->Version));
    }
    return ret;
}

TE_LIBUTI_SIF_status LIBUTI_SIF_get_requester_info(const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_requester_info * const out)
{
    ts_LIBUTI_SIF_header header;
    ts_LIBUTI_SIF_header_iterator hiter;
    TE_LIBUTI_SIF_status ret;
    ret = LIBUTI_SIF_get_header(DecodedHeaderAddress, &header);
    if (ret == E_LIBUTI_SIF_SUCCESS)
    {
        hiter.header = DecodedHeaderAddress;
        hiter.header_length = header.header_length;
        hiter.position = header.requester_info_abs_ptr;
        LIBUTI_SIF_get_str(&hiter, (uint32_t)14, out->DateTime);
        LIBUTI_SIF_get_strl(&hiter, &(out->Name));
    }
    return ret;
}


boolean_t LIBUTI_SIF_has_target(const uint8_t *DecodedHeaderAddress, const uint8_t *TargetName, const uint32_t TargetNameLength, const uint8_t *HardwareID, const uint32_t HardwareIDLength)
{
    boolean_t is_target;
    ts_LIBUTI_SIF_target v_target;
    ts_LIBUTI_SIF_iterator v_titer;
    TE_LIBUTI_SIF_status status;
    status = LIBUTI_SIF_init_target_iterator(DecodedHeaderAddress, &v_titer);
	v_target.Name.Length = (uint16_t)0;
	v_target.hardware_identifier.Length = (uint16_t)0;

    is_target = FALSE;
    if (status == E_LIBUTI_SIF_SUCCESS)
    {
        status = LIBUTI_SIF_get_next_target(&v_target, &v_titer);
    }
    while(status != E_LIBUTI_SIF_FAILURE && (!is_target))
    {
        is_target = TRUE;
        if (TargetName != NULL)
        {
            if (TargetNameLength == (uint32_t)(v_target.Name.Length))
            {
                is_target = !LIBUTI_MEM_MemsNotEqual(TargetName, v_target.Name.Name, (uint32_t)(v_target.Name.Length));
            }
            else
            {
                is_target = FALSE;
            }
        }
        if (is_target && (HardwareID != NULL))
        {
            if (HardwareIDLength == (uint32_t)(v_target.hardware_identifier.Length))
            {
                is_target = !LIBUTI_MEM_MemsNotEqual(HardwareID, v_target.hardware_identifier.Name, (uint32_t)(v_target.hardware_identifier.Length));
            }
            else
            {
                is_target = FALSE;
            }
        }
        status = LIBUTI_SIF_get_next_target(&v_target, &v_titer);
    }
    return is_target;
}

boolean_t LIBUTI_SIF_has_file(const uint8_t *DecodedHeaderAddress, const uint8_t *FileName, const uint32_t FileNameLength)
{
    ts_LIBUTI_SIF_file_info v_finfo;
    ts_LIBUTI_SIF_iterator v_fiter;
    boolean_t is_file;
    TE_LIBUTI_SIF_status status;
    is_file = FALSE;
	v_finfo.Name.Length = (uint16_t)0;
    status = LIBUTI_SIF_init_file_iterator(DecodedHeaderAddress, &v_fiter);
    if (status == E_LIBUTI_SIF_SUCCESS)
    {
        status = LIBUTI_SIF_get_next_file(&v_finfo, &v_fiter);
    }
    while(status != E_LIBUTI_SIF_FAILURE && (!is_file))
    {
        if((uint32_t)(v_finfo.Name.Length) == FileNameLength)
        {
            is_file = !LIBUTI_MEM_MemsNotEqual(FileName, v_finfo.Name.Name, (uint32_t)(v_finfo.Name.Length));
        }
        else
        {
            is_file = FALSE;
        }
        status = LIBUTI_SIF_get_next_file(&v_finfo, &v_fiter);

    }
    return is_file;
}

uint16_t LIBUTI_SIF_file_count(const uint8_t *DecodedHeaderAddress)
{
    ts_LIBUTI_SIF_iterator fiter;
    TE_LIBUTI_SIF_status status;
    uint16_t ret;
    status = LIBUTI_SIF_init_file_iterator(DecodedHeaderAddress, &fiter);
    if (status == E_LIBUTI_SIF_SUCCESS)
    {
        ret = fiter.item_count;
    }
    else
    {
        ret = (uint16_t)0;
    }
    return ret;
}


TE_LIBUTI_SIF_status LIBUTI_SIF_get_SHA2_256(const uint8_t *DecodedHeaderAddress, const uint8_t *FileName, const uint32_t FileNameLength, ts_LIBUTI_SHA_SHA256 * const p_out)
{
    TE_LIBUTI_SIF_status ret;
    tu_LIBUTI_SIF_hash buf;
    ret = LIBUTI_SIF_get_hash(DecodedHeaderAddress, FileName, FileNameLength, E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256, &buf);
    if (ret == E_LIBUTI_SIF_SUCCESS)
    {
        *p_out = buf.sha256;
    }
    return ret;
}
/* if the function is in an exported api */
/* Declaration of the function is in CSC_api.h */