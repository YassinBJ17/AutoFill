/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_GPIO_Configure.h"


/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_GPIO_AddrStatus LIBBSP_GPIO_Configure( void )
 {
	TE_LIBBSP_GPIO_AddrStatus v_AddrStatus;

	/* Set register's values to the values of power on state */
	V_GPIOReg->GPDIR = C_GPIO_GPDIR; /* configure GPIO[0] and GPIO[5..7] as an output. Other GPIO are inputs*/
	V_GPIOReg->GPODR = (uint16_t)0x0; /* GPODR = 0 = HW value at reset;  All outputs are "normal" output (= not open drain)*/
	V_GPIOReg->GPDAT = (uint16_t)0x0; /*GPDAT = 0 = HW value at reset;  see 21.3.1.3 of P2020 QorIQ Integrated Processor Reference Manual*/
	V_GPIOReg->GPIER = C_GPIO_GPIER; /* GPIER is undefined at reset. User should write "1" to clear before use; see 21.3.1.4 of P2020 QorIQ Integrated Processor Reference Manual*/
	V_GPIOReg->GPIMR = (uint16_t)0x0; /* GPIMR = 0 = HW value at reset;  => no interruption declared*/
	V_GPIOReg->GPICR = (uint16_t)0x0; /* GPICR = 0 = HW value at reset;  => no interruption declared*/

	v_AddrStatus = E_LIBBSP_GPIO_VALID_ADDR;

    return v_AddrStatus;
}
/*==== END =============================================================================*/
