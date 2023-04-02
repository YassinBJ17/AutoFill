/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef P0_PRIVATE_H
#define P0_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Number of byte in SPI frame */
#define NB_BYTES_IN_FRAME     ((uint32_t)3)

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t s_address:4;   /* Address of the transducer that transmits the response */
   uint32_t s_status :3;   /* Status code of the response */
   uint32_t s_parity :1;   /* Parity bit for the response */
}
ts_p0_byte_1_bit;

typedef union
{
   uint8_t           u_word;  /* Byte 1 of P0 frame accessed by 32-bit word  */
   ts_p0_byte_1_bit  u_bit;   /* Byte 1 of P0 frame accessed bit by bit */
}
tu_p0_byte_1;

typedef struct
{
   tu_p0_byte_1   s_p0_byte_1;   /* Byte 1 of P0 frame, containing address, status and parity of the response */
   uint16_t       s_p0_pressure; /* Pressure value of P0 */
}
ts_spi_p0_frame;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* GPIO for reset of P0 */
extern uint8_t     *gpio_reset_p0;

/* GPIO for CE read command */
extern uint8_t     *gpio_ce_read_command;

/* Indicate if P0 has been reset since the beginning of the mission */
extern boolean_t   p0_has_been_reset;

/* Counter of faulty P0 */
extern uint8_t     p0_fault_counter;

/* Number of RTC since P0 activation */
extern uint32_t    p0_rtc_since_activation;

/* ---------- provided operations: ------------------------------------------ */
/* CBIT management */
void p0_cbit(const uint32_t p_read_size, uint16_t p_spi_tmp_frame[NB_BYTES_IN_FRAME],
             const ts_spi_p0_frame * const p_spi_p0_frame, boolean_t * const p_p0_is_faulty);

#endif /* P0_PRIVATE_H */
