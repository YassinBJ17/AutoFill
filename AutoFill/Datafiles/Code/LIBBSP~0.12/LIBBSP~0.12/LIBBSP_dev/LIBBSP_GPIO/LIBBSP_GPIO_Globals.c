/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_GPIO_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
volatile TS_LIBBSP_GPIO_Reg* const V_GPIOReg = (volatile TS_LIBBSP_GPIO_Reg* const) C_LIBBSP_CCSR_GPIO; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */
const uint16_t C_GPIO_MASK = 0xFFFF;
const uint16_t C_GPIO_GPDIR = 0x8700;
const uint16_t C_GPIO_GPIER = 0xFFFF;
/*==== Services ========================================================================*/

/*==== END =============================================================================*/
