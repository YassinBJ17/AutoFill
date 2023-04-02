/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Rx official capability */
#define UART_RS422_CAPABILITY_SIZE 256

/* Rx buffer sizes with margin */
#define UART_RS422_MAX_SIZE        512

/* State of UART transmission */
#define TX_IN_PROGRESS             1
#define TX_IDLE                    0

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
extern ts_CMN_IOSP_BUFFER context_tx;
extern ts_CMN_IOSP_BUFFER context_rx;
extern int8_t uart_rx_double_buffer_0[UART_RS422_MAX_SIZE];
extern int8_t uart_rx_double_buffer_1[UART_RS422_MAX_SIZE];
extern int8_t is_currently_sending;
extern int8_t disable_uart_for_uod;

/* ---------- provided operations: ------------------------------------------ */

/* Manage UART configuration */
void uart_configuration(const boolean_t p_channel_is_a);

/* Manage UART transmission */
extern void uart_tx(void);

/* Manage UART reception */
extern void uart_rx(void);

#endif /* UART_PRIVATE_H  */
