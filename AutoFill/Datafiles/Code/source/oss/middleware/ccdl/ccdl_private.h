/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CCDL_PRIVATE_H
#define CCDL_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "memory/memory_address_public.h"
#include "middleware/ccdl/ccdl_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/fpga/fpga_reg_iip13_uart_ccdl.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Number of maximum words on CCDL TX */
#define CCDL_MAX_WORD_NB  ((uint32_t)256)

/* Spare data */
#define SPARE_32BITS_8    ((uint32_t)(958))

/* CCDL address in FPGA */
#define CCDL_ADDR ((ts_ccdl *)(FPGA_MEMORY_ADDR + 0x000A0000))

/* ---------- provided types: ----------------------------------------------- */
/* Bits field of CCDL RX control register */
typedef struct
{
   uint32_t s_rx_enable             : 1;  /* 31 */
   uint32_t s_spare_30_to_24        : 7;  /* 30-24:*/
   uint32_t s_parity_err_ack        : 1;  /* 23: */
   uint32_t s_new_frame_ack         : 1;  /* 22:  */
   uint32_t s_spare_21_to_1         : 21; /* 21-1 */
   uint32_t s_echo_mode             : 1;  /* 0 */
}
ts_ccdl_rx_control_u_bit;

/* CCDL RX control register */
typedef union
{
   uint32_t u_word;                /*CCDL RX command register accessed by 32-bit word */
   ts_ccdl_rx_control_u_bit u_bit; /* CCDL RX control register accessed bit by bit */
}
ts_ccdl_rx_control;

/* Bits field of CCDL RX status register */
typedef struct
{
   uint32_t s_busy              : 1;  /* 31: */
   uint32_t s_crc_valid         : 1;  /* 30: */
   uint32_t s_size_valid        : 1;  /* 29:  */
   uint32_t s_sof_valid         : 1;  /* 28: */
   uint32_t s_spare_27_to_24    : 4;  /* 27-24:  */
   uint32_t s_parity_err        : 1;  /* 23:  */
   uint32_t s_new_frame         : 1;  /* 22:  */
   uint32_t s_spare_21_to_00    : 22; /* 24:  */
}
ts_ccdl_rx_status_reg_u_bit;

/* CCDL RX status register */
typedef union
{
   uint32_t u_word;                   /* CCDL RX status register accessed by 32-bit word */
   ts_ccdl_rx_status_reg_u_bit u_bit; /* CCDL RX status register accessed bit by bit */
}
ts_ccdl_rx_status_reg;

/* CCDL RX/TX registers */
typedef struct
{
   tu_fpga_reg_iip13_uart_ccdl_tx_control_reg       s_tx_control;
   tu_fpga_reg_iip13_uart_ccdl_tx_status_reg        s_tx_status;
   tu_fpga_reg_iip13_uart_ccdl_tx_command_reg       s_tx_cmd;
   uint32_t                                         s_spare_00;
   uint32_t                                         s_spare_01;
   uint32_t                                         s_sss[59];
   ts_ccdl_rx_control                               s_rx_control;
   ts_ccdl_rx_status_reg                            s_rx_status;
   uint32_t                                         s_spare_02[SPARE_32BITS_8];
   ts_ccdl_frame                                    s_tx_data;
   uint32_t                                         s_spare_04[341];
   ts_ccdl_frame                                    s_rx_data;
}
ts_ccdl;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Registers for CCDL */
extern ts_ccdl * fpga_ccdl;

/* CCDL frame size */
extern uint32_t ccdl_frame_size_in_bytes;

/* ---------- provided operations: ------------------------------------------ */
/* Read the CCDL frame from opposite channel */
extern void ccdl_rx(const boolean_t channel_is_a);

/* Transmit the CCDL frame to opposite channel*/
extern void ccdl_tx(const boolean_t channel_is_a);

#endif /* CCDL_PRIVATE_H  */
