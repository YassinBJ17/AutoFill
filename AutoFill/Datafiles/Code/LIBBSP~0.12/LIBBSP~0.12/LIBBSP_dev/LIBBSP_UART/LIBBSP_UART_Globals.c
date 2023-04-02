/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_UART_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

volatile TU_LIBBSP_UART_Registers * const V_UARTRegs = (volatile TU_LIBBSP_UART_Registers * const) C_LIBBSP_MEGREG_UART; /* %RELAX<SYNCHRONe_C_Code_10.7> verifier si perte de precision*/

/* pointer for the words */
uint32_t V_UARTPointers[C_UART_DEVICES_COUNT];
/* pointer inside the word */
uint32_t V_UARTSubPointers[C_UART_DEVICES_COUNT];

TU_LIBBSP_UART_Register * V_UARTReceiveBuffers[C_UART_DEVICES_COUNT];
/*==== Services ========================================================================*/

/*==== END =============================================================================*/
