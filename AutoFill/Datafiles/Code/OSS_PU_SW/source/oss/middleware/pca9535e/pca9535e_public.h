/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef PCA9535E_PUBLIC_H
#define PCA9535E_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Device error bit */
#define C_PCA9535E_ERROR_DEVICE_42   ((uint8_t)0x01)
#define C_PCA9535E_ERROR_DEVICE_44   ((uint8_t)0x02)
#define C_PCA9535E_ERROR_DEVICE_48   ((uint8_t)0x04)
#define C_PCA9535E_ERROR_DEVICE_4A   ((uint8_t)0x08)
#define C_PCA9535E_ERROR_DEVICE_4C   ((uint8_t)0x10)

/* IO state */
#define C_PCA9535E_IO_SET   ((uint16_t)0x0001)
#define C_PCA9535E_IO_UNSET ((uint16_t)0x0000)

/* ---------- provided types: ----------------------------------------------- */
/* List of available IO Expanders */
typedef enum
{
   e_device_42 = 0,
   e_device_44,
   e_device_48,
   e_device_4A,
   e_device_4C,
   e_device_max
}
te_pca9535e_device;

/* PCA9535 IO state word */
typedef struct
{
   uint16_t s_io_07 : 1;   /* bit #15 (MSB) */
   uint16_t s_io_06 : 1;   /* bit #14 */
   uint16_t s_io_05 : 1;   /* bit #13 */
   uint16_t s_io_04 : 1;   /* bit #12 */
   uint16_t s_io_03 : 1;   /* bit #11 */
   uint16_t s_io_02 : 1;   /* bit #10 */
   uint16_t s_io_01 : 1;   /* bit #09 */
   uint16_t s_io_00 : 1;   /* bit #08 */
   uint16_t s_io_17 : 1;   /* bit #07 */
   uint16_t s_io_16 : 1;   /* bit #06 */
   uint16_t s_io_15 : 1;   /* bit #05 */
   uint16_t s_io_14 : 1;   /* bit #04 */
   uint16_t s_io_13 : 1;   /* bit #03 */
   uint16_t s_io_12 : 1;   /* bit #02 */
   uint16_t s_io_11 : 1;   /* bit #01 */
   uint16_t s_io_10 : 1;   /* bit #00 (LSB) */
}
ts_pca9535e_io_state_bit;

typedef union
{
   uint16_t                u_word;
   ts_pca9535e_io_state_bit u_bit;
}
tu_pca9535e_io_state;

/* PCA9535 status word */
typedef struct
{
   uint8_t spare_07_to_02 : 6;   /* 07 to 02 : Spare         */
   uint8_t s_i2c_wr_error : 1;   /* 01: write error occurred */
   uint8_t s_i2c_rd_error : 1;   /* 00: read error occurred  */
}
ts_pca9535e_status_bit;

typedef union
{
   uint8_t                u_word;
   ts_pca9535e_status_bit u_bit;
}
tu_pca9535e_status;

/* PCA9535e device */
typedef struct
{
   tu_pca9535e_io_state s_io_state;
   tu_pca9535e_status   s_status;
}
ts_pca9535a_device;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Array of all to access all IO of alll PCA9535 */
extern ts_pca9535a_device v_pca9535e_devices[e_device_max];

/* ---------- provided operations: ------------------------------------------ */
/* Initialize PCA9535 common interface */
extern void pca9535e_init_all(void);

/* Read and store locally all devices IO state */
extern uint8_t pca9535e_read_all(void);

/* Write to all devices locally stored IO state */
extern uint8_t pca9535e_write_all(void);

/* Read and store locally one device IO state */
extern uint8_t pca9535e_read_one(uint8_t const      p_i2c_address,
                                 te_pca9535e_device p_device_id,
                                 uint8_t const      p_error_bit);

/* Read and store locally one devices IO state */
extern uint8_t pca9535e_write_one(uint8_t const      p_i2c_address,
                                  te_pca9535e_device p_device_id,
                                  uint8_t const      p_error_bit);

/* Read and store automatically same device written by write_auto() */
extern uint8_t pca9535e_read_auto(void);

/* Choose an write one IO state to one IO Epxander */
extern uint8_t pca9535e_write_auto(void);


#endif /*PCA9535E_PUBLIC_H */
