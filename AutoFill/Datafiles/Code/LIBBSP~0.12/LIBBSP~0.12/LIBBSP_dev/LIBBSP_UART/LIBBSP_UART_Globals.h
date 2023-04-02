/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART.h"
#include "LIBBSP_MEGREG.h"

/*==== Definitions =====================================================================*/
extern volatile TU_LIBBSP_UART_Registers * const V_UARTRegs;
extern uint32_t V_UARTPointers[C_UART_DEVICES_COUNT];
extern uint32_t V_UARTSubPointers[C_UART_DEVICES_COUNT];

extern TU_LIBBSP_UART_Register * V_UARTReceiveBuffers[C_UART_DEVICES_COUNT];
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
