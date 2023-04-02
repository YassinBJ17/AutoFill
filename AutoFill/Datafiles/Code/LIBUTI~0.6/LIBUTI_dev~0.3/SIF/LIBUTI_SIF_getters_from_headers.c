/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_getters_from_headers.c
 * CSC name   : LIBUTI_SIF
 *
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */


/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SIF_getters_from_headers.h"
/* ---------- include required interface: ----------------------------------- */
#include "Memcpy.h"
/* ---------- internal define constants: ------------------------------------ */
#define C_MAX_STR_LENGTH (60)

/* ---------- internal macros: ---------------------------------------------- */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */



/* Those three functions collect the value from the header and update pos */

/*{{RELAX<SYNCHRONe_C_Code_17.4>*/
/*In those function array indexing is used on the pointer hiter->header. */
/*hiter->header is used as a buffer of the SIF header*/

uint16_t LIBUTI_SIF_get_short(ts_LIBUTI_SIF_header_iterator * const hiter)
{
    uint16_t ret;
    uint32_t v_idx; 
    ret = (uint16_t)0;
    for(v_idx = (uint32_t)0; v_idx < (uint32_t)2; v_idx++)
    {
        ret = (uint16_t) ((uint16_t)ret << 8) + (uint16_t)(hiter->header[hiter->position]); 
        hiter->position++;
        if (hiter->position > hiter->header_length)
        {
            break;
        }
    }
    return ret;
}

uint32_t LIBUTI_SIF_get_long(ts_LIBUTI_SIF_header_iterator * const hiter)
{
    uint32_t ret;
    uint32_t v_idx;
    ret = (uint32_t)0;
    for(v_idx = (uint32_t)0; v_idx < (uint32_t)4; v_idx++)
    {
        ret = (uint32_t) ((uint32_t)ret << 8) + (uint32_t)(hiter->header[hiter->position]);
        hiter->position++;
        if (hiter->position > hiter->header_length)
        {
            break;
        }
    }
    return ret;
}

void LIBUTI_SIF_get_str(ts_LIBUTI_SIF_header_iterator * const hiter, const uint32_t len, uint8_t *const buffer)
{
    uint32_t tmp_len;
    if (len > (uint32_t)C_MAX_STR_LENGTH)
    {
        tmp_len = (uint32_t)C_MAX_STR_LENGTH;
    }
    else 
    {
        tmp_len = len;
    }
    if (hiter->position + tmp_len > hiter->header_length)
    {
        tmp_len = hiter->header_length - hiter->position;
    }
    LibC_Memcpy(buffer, hiter->header + hiter->position, tmp_len);
    hiter->position += ( (tmp_len % (uint32_t)2) ? tmp_len + (uint32_t)1 : tmp_len);
}

/*}}RELAX<SYNCHRONe_C_Code_17.4> */