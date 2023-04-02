/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_A429_GLOBALS_H
#define LIBBSP_A429_GLOBALS_H
#include "LIBBSP_A429.h"
#include "LIBBSP_MEGREG.h"

/*==== Definitions =====================================================================*/
extern const uint32_t C_A429_AUTHORIZED;
extern const uint32_t C_A429_NOT_AUTHORIZED;
extern const uint32_t C_A429_RX_DIVIDED_COEFF;

extern volatile TU_LIBBSP_A429_Registers * const V_A429Regs; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/

#endif