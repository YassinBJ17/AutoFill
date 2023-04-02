/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_BLADES_DEFINES_H
#define LIBBSP_BLADES_DEFINES_H
#include "LIBBSP_BLADES_Globals.h"

/*==== Definitions =====================================================================*/

#define C_LIBBSP_BLADES_REG_ALL_BLADES_DBG_FORCE_DBG    (uint32_t)(0x526000)
#define C_LIBBSP_BLADES_START_BLADES                    (0x00000000)
#define C_LIBBSP_BLADES_STOP_BLADES                     (0x00000001)
#define C_LIBBSP_BLADES_STOPPED_VALUE                   (0x3)
#define C_LIBBSP_BLADES_STARTED_VALUE                   (0x00000000)
#define C_LIBBSP_BLADES_REG_SELELECT_ADDR               (0x4)
#define C_LIBBSP_BLADES_REG_CAL_HRG                     (0xA365E167)
#define C_LIBBSP_BLADES_REG_OPE                         (0xA365E13A)
#define C_LIBBSP_BLADES_TIMEOUT_MS                      (50)
#define C_LIBBSP_BLADES_10_MICRO                        (0x1a0ul)

/*==== Service =========================================================================*/

#endif
