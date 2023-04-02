/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_GPIO_GLOBALS_H
#define LIBBSP_GPIO_GLOBALS_H

#include "LIBBSP_GPIO.h"
#include "LIBBSP_CCSR.h"

/*==== Definitions =====================================================================*/
extern const uint16_t C_GPIO_GPDIR;
extern const uint16_t C_GPIO_GPIER;
extern volatile TS_LIBBSP_GPIO_Reg* const V_GPIOReg; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */
extern const uint16_t C_GPIO_MASK;
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
