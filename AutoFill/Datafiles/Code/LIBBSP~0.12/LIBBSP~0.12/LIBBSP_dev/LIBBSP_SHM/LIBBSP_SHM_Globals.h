/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_SHM_GLOBALS_H
#define LIBBSP_SHM_GLOBALS_H

#include "LIBBSP_SHM.h"
#include "LIBBSP_CMPREG.h"

/*==== Definitions =====================================================================*/
#define C_SHM_STATE (0x8)

#define C_SHM_PBITOK (0x4)
#define C_SHM_FAIL_SWITCH (0x10)

#define C_SHM_IDLE (0x12345678ul)
#define C_SHM_FAIL (0x12345678ul)

extern volatile TS_LIBBSP_SHM_Registers * const V_SHMRegs;
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
