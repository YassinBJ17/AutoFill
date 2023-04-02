/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_iterators.h
 * CSC name   : LIBUTI_SIF
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/incl/LIBUTI_SIF_iterators.h/3 %
 *    Creation: Divided from LIBUTI_SIF_parsing.c on 04-02-2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */

#ifndef _LIBUTI_SIF_iterators_H_
#define _LIBUTI_SIF_iterators_H_
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "LIBMCP_Types.h"
#include "LIBUTI_SIF.h"
#include "LIBUTI_SIF_getters.h"
/* ---------- provided define constants: ------------------------------------ */
#define C_LIBUTI_SIF_MAX_CHECK_LENGTH 64
#define C_LIBUTI_SIF_MAX_PACKET_NUMBER 256
/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

typedef struct {
    ts_LIBUTI_SIF_header_iterator data;
    uint16_t item_count;
    uint16_t format_version;
    uint16_t format_revision;
} ts_LIBUTI_SIF_iterator;

typedef struct {
    TE_LIBUTI_SIF_check_algorithm check_type;
    uint8_t check[C_LIBUTI_SIF_MAX_CHECK_LENGTH];
} ts_LIBUTI_SIF_global_check;

typedef struct {
    uint32_t packet_length;
    uint32_t packet_number;
    TE_LIBUTI_SIF_check_algorithm check_type;
    uint8_t check_list[C_LIBUTI_SIF_MAX_CHECK_LENGTH][C_LIBUTI_SIF_MAX_PACKET_NUMBER];
} ts_LIBUTI_SIF_data_packet_check;

typedef struct {
    TS_LIBUTI_SIF_Name_WithLength Name;
    uint32_t file_length;
    uint16_t global_check_number;
    uint32_t first_check_addr;
    uint16_t packet_check_number;
    uint32_t first_packet_check_addr;
} ts_LIBUTI_SIF_file_info;


/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
extern TE_LIBUTI_SIF_status LIBUTI_SIF_init_target_iterator(const uint8_t * const DecodedHeaderAddress, ts_LIBUTI_SIF_iterator * const i);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_target(ts_LIBUTI_SIF_target * const target, ts_LIBUTI_SIF_iterator * const i);

extern TE_LIBUTI_SIF_status LIBUTI_SIF_init_file_iterator(const uint8_t * const DecodedHeaderAddress, ts_LIBUTI_SIF_iterator * const i);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_file(ts_LIBUTI_SIF_file_info * const info, ts_LIBUTI_SIF_iterator * const i);

extern void LIBUTI_SIF_init_global_check_iterator(const ts_LIBUTI_SIF_file_info * const info, const ts_LIBUTI_SIF_iterator * const fiter, ts_LIBUTI_SIF_iterator * const i);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_global_check(ts_LIBUTI_SIF_global_check * const check, ts_LIBUTI_SIF_iterator * const i);

extern void LIBUTI_SIF_init_packet_check_iterator(const ts_LIBUTI_SIF_file_info * const info, const ts_LIBUTI_SIF_iterator * const fiter, ts_LIBUTI_SIF_iterator * const i);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_packet_check(ts_LIBUTI_SIF_data_packet_check * const check, ts_LIBUTI_SIF_iterator * const i);

#endif /* _LIBUTI_SIF_iterators_H_ */ 
