/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

/*==== Definitions =====================================================================*/
#ifndef LIBBSP_CMPREG_H
#define LIBBSP_CMPREG_H

#include "LIBMCP_Types.h"

/* there contants are used in the application */
/* sw to initialize the adsresse used by      */
/* the driver. It doesn't aim to contain      */
/* all the registers of the Compagnon PLD     */

#define C_LIBBSP_CMPREG_COMPAGNON               ((uint32_t)0xF2000000)
#define C_LIBBSP_CMPREG_GLOBAL_REGISTERS_DELTA  ((uint32_t)0x00003000)
#define C_LIBBSP_CMPREG_PSU_MONITORING_DELTA    ((uint32_t)0x00001000)
#define C_LIBBSP_CMPREG_WD_REGISTERS_DELTA      ((uint32_t)0x00002000)
#define C_LIBBSP_CMPREG_SHM_REGISTERS_DELTA     ((uint32_t)0x00000000)
#define C_LIBBSP_CMPREG_SCRATCH_REGISTERS_DELTA ((uint32_t)0x00004000)
#define C_LIBBSP_CMPREG_ENVM_REGISTERS_DELTA 	((uint32_t)0x00008000)

#define C_LIBBSP_CMPREG_GLOBAL_REGISTERS        (C_LIBBSP_CMPREG_COMPAGNON+C_LIBBSP_CMPREG_GLOBAL_REGISTERS_DELTA)
#define C_LIBBSP_CMPREG_PSU                     (C_LIBBSP_CMPREG_COMPAGNON+C_LIBBSP_CMPREG_PSU_MONITORING_DELTA)
#define C_LIBBSP_CMPREG_WD                      (C_LIBBSP_CMPREG_COMPAGNON+C_LIBBSP_CMPREG_WD_REGISTERS_DELTA)
#define C_LIBBSP_CMPREG_SHM                     (C_LIBBSP_CMPREG_COMPAGNON+C_LIBBSP_CMPREG_SHM_REGISTERS_DELTA)
#define C_LIBBSP_CMPREG_SCRATCH                 (C_LIBBSP_CMPREG_COMPAGNON+C_LIBBSP_CMPREG_SCRATCH_REGISTERS_DELTA)
#define C_LIBBSP_CMPREG_ENVM                	(C_LIBBSP_CMPREG_COMPAGNON+C_LIBBSP_CMPREG_ENVM_REGISTERS_DELTA)


/*==== Variables========================================================================*/


/*==== Services ========================================================================*/

    
/*==== END =============================================================================*/
#endif /* LIBBSP_CMPREG_H */