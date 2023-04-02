/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_A429_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
const uint32_t C_A429_AUTHORIZED = 1;
const uint32_t C_A429_NOT_AUTHORIZED = 0;
const uint32_t C_A429_RX_DIVIDED_COEFF = 4;

volatile TU_LIBBSP_A429_Registers * const V_A429Regs = (TU_LIBBSP_A429_Registers * const) C_LIBBSP_MEGREG_A429; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */


/*==== Services ========================================================================*/

/*==== END =============================================================================*/
