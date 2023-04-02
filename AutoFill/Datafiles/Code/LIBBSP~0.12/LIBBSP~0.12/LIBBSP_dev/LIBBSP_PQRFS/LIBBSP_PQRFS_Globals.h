/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PQRFS_Globals_H
#define LIBBSP_PQRFS_Globals_H

#include "LIBBSP_PQRFS.h"
#include "LIBBSP_BLADES.h"
/*==== Definitions =====================================================================*/

typedef struct
{
    uint32_t spare : 29;
    uint32_t Reg_pqr_en : 1;
    uint32_t Reg_pqr_en_atx4 : 1;
    uint32_t Reg_pqr_en_atx1 : 1;
} TS_LIBBSP_PQRFS_RegPqrCmd;

typedef struct
{
    uint32_t spare : 24;
    uint32_t data_tic_label : 8;
} TS_LIBBSP_PQRFS_data_tic_label;

typedef struct
{
    uint32_t spare : 19;
    uint32_t label_err_13 : 1;
    uint32_t label_err_12 : 1;
    uint32_t label_err_11 : 1;
    uint32_t label_err_10 : 1;
    uint32_t label_err_9 : 1;
    uint32_t label_err_8 : 1;
    uint32_t label_err_7 : 1;
    uint32_t label_err_6 : 1;
    uint32_t label_err_5 : 1;
    uint32_t label_err_4 : 1;
    uint32_t label_err_3 : 1;
    uint32_t label_err_2 : 1;
    uint32_t label_err_1 : 1;
} TS_LIBBSP_PQRFS_Status_data_bitField;

typedef struct 
{
    uint32_t spare : 31;
    uint32_t TBC : 1;
} TS_LIBBSP_PQRFS_Status_status_bitField;


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
