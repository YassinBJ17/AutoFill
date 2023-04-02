/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef PCA9535E_PRIVATE_H
#define PCA9535E_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* I2C0 Baudrate of 91 */
#define I2C0_BAUD ((uint8_t)0x5B)

/* IO Expanders I2C addresses */
#define  C_I2C_ADDRESS_42   ((uint8_t)0x42)
#define  C_I2C_ADDRESS_44   ((uint8_t)0x44)
#define  C_I2C_ADDRESS_48   ((uint8_t)0x48)
#define  C_I2C_ADDRESS_4A   ((uint8_t)0x4A)
#define  C_I2C_ADDRESS_4C   ((uint8_t)0x4C)

/* IO Expanders configuration values */
#define  C_IOEXP_42_CONF   ((uint16_t)0x00F9)
#define  C_IOEXP_44_CONF   ((uint16_t)0x03FD)
#define  C_IOEXP_48_CONF   ((uint16_t)0xDFFD)
#define  C_IOEXP_4A_CONF   ((uint16_t)0xAAFD)
#define  C_IOEXP_4C_CONF   ((uint16_t)0xAAFD)

/* IO Expanders registers address */
#define C_PCA9535E_INPUT_REGISTER    ((uint8_t)0x00)
#define C_PCA9535E_OUTPUT_REGISTER   ((uint8_t)0x02)
#define C_PCA9535E_CONFIG_REGISTER   ((uint8_t)0x06)

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */


#endif /*PCA9535E_PRIVATE_H */
