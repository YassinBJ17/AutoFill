/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_WD_GLOBALS_H
#define LIBBSP_WD_GLOBALS_H

#include "LIBBSP_WD.h"
#include "LIBBSP_CMPREG.h"

/*==== Definitions =====================================================================*/
#define C_WD_MASK_CNT_CFG (0x07ff07fful)
#define C_WD_SHIFT_DELAY (0)
#define C_WD_SHIFT_WIDTH (16)

#define C_WD_CNT_CFG (0x4)

#define C_WD_PWD (0)
/*==== Variables =======================================================================*/
extern volatile TS_LIBBSP_WD_Registers * const V_WDRegs;
/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
