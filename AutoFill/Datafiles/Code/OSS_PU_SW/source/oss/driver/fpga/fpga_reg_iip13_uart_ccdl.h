/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP13_UART_CCDL_H
#define FPGA_REG_IIP13_UART_CCDL_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_tx_control_reg' */
typedef struct
{
   uint32_t s_ccdl_tx_enable           :  1; /* Bits : 31    : Enable transmission                   */
   uint32_t s_recerved                 :  3; /* Bits : 30:28 : NA                                    */
   uint32_t s_ccdl_tx_corrupt_parity   :  1; /* Bits : 27    : Force corruption of {ccdl_tx_ram}     */
   uint32_t s_reserved                 :  3; /* Bits : 26:24 : NA                                    */
   uint32_t s_ccdl_tx_parity_error_ack :  1; /* Bits : 23    : Acknowledge of {ccdl_tx_parity_error} */
   uint32_t s_reserved_00              : 23; /* Bits : 22:0  : NA                                    */
}
ts_fpga_reg_iip13_uart_ccdl_tx_control_reg_u_bit;

typedef union
{
   uint32_t                                         u_word;
   ts_fpga_reg_iip13_uart_ccdl_tx_control_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_tx_control_reg;

/* Union definition for register 's_tx_status_reg' */
typedef struct
{
   uint32_t s_ccdl_tx_busy         :  1; /* Bits : 31    : Transmission in progress      */
   uint32_t s_reserved             :  7; /* Bits : 30:24 : NA                            */
   uint32_t s_ccdl_tx_parity_error :  1; /* Bits : 23    : Parity error in {ccdl_tx_ram} */
   uint32_t s_reserved_00          : 23; /* Bits : 22:0  : NA                            */
}
ts_fpga_reg_iip13_uart_ccdl_tx_status_reg_u_bit;

typedef union
{
   uint32_t                                        u_word;
   ts_fpga_reg_iip13_uart_ccdl_tx_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_tx_status_reg;

/* Union definition for register 's_tx_command_reg' */
typedef struct
{
   uint32_t s_ccdl_tx_start                      :  1; /* Bits : 31    : Start a transfer                                     */
   uint32_t s_ccdl_tx_mode                       :  1; /* Bits : 30    : 0b1 {delay_mode} 0b0 {immediate_mode}                */
   uint32_t s_ccdl_tx_cmd                        :  1; /* Bits : 29    : Read/Write selection                                 */
   uint32_t s_reserved                           :  7; /* Bits : 28:22 : NA                                                   */
   uint32_t s_ccdl_tx_sof_error_flag_ack         :  1; /* Bits : 21    : Acknowledge received {ccdl_rx_sof_error_flag}        */
   uint32_t s_ccdl_tx_long_frame_error_flag_ack  :  1; /* Bits : 20    : Acknowledge received {ccdl_rx_long_frame_error_flag} */
   uint32_t s_ccdl_tx_short_frame_error_flag_ack :  1; /* Bits : 19    : Acknowledge received{ccdl_rx_short_frame_error_flag} */
   uint32_t s_ccdl_tx_crc_error_flag_ack         :  1; /* Bits : 18    : Acknowledge received {ccdl_rx_crc_error_flag}        */
   uint32_t s_ccdl_tx_parity_error_flag_ack      :  1; /* Bits : 17    : Acknowledge received {ccdl_rx_parity_error_flag}     */
   uint32_t s_ccdl_tx_addr_error_flag_ack        :  1; /* Bits : 16    : Acknowledge received{ccdl_rx_addr_error_flag}        */
   uint32_t s_reserved_00                        :  6; /* Bits : 15:10 : NA                                                   */
   uint32_t s_ccdl_tx_size                       : 10; /* Bits : 9:0   : Amount of Data to transfer                           */
}
ts_fpga_reg_iip13_uart_ccdl_tx_command_reg_u_bit;

typedef union
{
   uint32_t                                         u_word;
   ts_fpga_reg_iip13_uart_ccdl_tx_command_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_tx_command_reg;

/* Union definition for register 's_tx_delay_reg' */
typedef struct
{
   uint32_t s_reserved      : 18; /* Bits : 31:14 :                                                    */
   uint32_t s_ccdl_tx_delay : 14; /* Bits : 13:0  : Delay in {delay_mode}, 1LSB = 10 * {ccdl_bit_time} */
}
ts_fpga_reg_iip13_uart_ccdl_tx_delay_reg_u_bit;

typedef union
{
   uint32_t                                       u_word;
   ts_fpga_reg_iip13_uart_ccdl_tx_delay_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_tx_delay_reg;

/* Union definition for register 's_tx_slave_id_addr_reg' */
typedef struct
{
   uint32_t s_ccdl_tx_id   :  8; /* Bits : 31:24 : Slave Id in {ccdl_word}  {ccdl_h1}          */
   uint32_t s_ccdl_tx_addr : 24; /* Bits : 23:0  : Slave Address inside {ccdl_word}  {ccdl_h1} */
}
ts_fpga_reg_iip13_uart_ccdl_tx_slave_id_addr_reg_u_bit;

typedef union
{
   uint32_t                                               u_word;
   ts_fpga_reg_iip13_uart_ccdl_tx_slave_id_addr_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_tx_slave_id_addr_reg;

/* Union definition for register 's_rx_control_reg' */
typedef struct
{
   uint32_t s_ccdl_rx_enable           :  1; /* Bits : 31    : Enable reception                      */
   uint32_t s_reserved                 :  3; /* Bits : 30:28 : NA                                    */
   uint32_t s_ccdl_rx_corrupt_parity   :  1; /* Bits : 27    : Force corruption of {ccdl_rx_ram}     */
   uint32_t s_reserved_00              :  3; /* Bits : 26:24 : NA                                    */
   uint32_t s_ccdl_rx_parity_error_ack :  1; /* Bits : 23    : Acknowledge of {ccdl_rx_parity_error} */
   uint32_t s_ccdl_rx_new_frame_ack    :  1; /* Bits : 22    : Acknowledge of {ccdl_rx_new_frame}    */
   uint32_t s_ccdl_rx_timeout_ack      :  1; /* Bits : 21    : Acknowledge of {ccdl_rx_timeout}      */
   uint32_t s_reserved_01              : 20; /* Bits : 20:1  : NA                                    */
   uint32_t s_ccdl_rx_echo_mode        :  1; /* Bits : 00    : Echo mode (force reception)           */
}
ts_fpga_reg_iip13_uart_ccdl_rx_control_reg_u_bit;

typedef union
{
   uint32_t                                         u_word;
   ts_fpga_reg_iip13_uart_ccdl_rx_control_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_rx_control_reg;

/* Union definition for register 's_rx_status_reg' */
typedef struct
{
   uint32_t s_ccdl_rx_busy         :  1; /* Bits : 31    : Reception in progress                                                                                                */
   uint32_t s_ccdl_rx_crc_valid    :  1; /* Bits : 30    : 1: {ccdl_crc} of last received {ccdl_frame} is valid0: {ccdl_crc} of last received {ccdl_frame} is not valid         */
   uint32_t s_ccdl_rx_size_valid   :  1; /* Bits : 29    : 1: {ccdl_rx_size} of last received {ccdl_frame} is valid0: {ccdl_rx_size} of last received {ccdl_frame} is not valid */
   uint32_t s_ccdl_rx_sof_valid    :  1; /* Bits : 28    : 1: {ccdl_sof} of last received {ccdl_frame} is valid0: {ccdl_sof} of last received {ccdl_frame} is not valid         */
   uint32_t s_reserved             :  4; /* Bits : 27:24 : NA                                                                                                                   */
   uint32_t s_ccdl_rx_parity_error :  1; /* Bits : 23    : Parity error in {ccdl_rx_ram}                                                                                        */
   uint32_t s_ccdl_rx_new_frame    :  1; /* Bits : 22    : New {ccdl_frame} received                                                                                            */
   uint32_t s_ccdl_rx_timeout      :  1; /* Bits : 21    : Timeout error                                                                                                        */
   uint32_t s_reserved_00          : 21; /* Bits : 20:0  : NA                                                                                                                   */
}
ts_fpga_reg_iip13_uart_ccdl_rx_status_reg_u_bit;

typedef union
{
   uint32_t                                        u_word;
   ts_fpga_reg_iip13_uart_ccdl_rx_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_rx_status_reg;

/* Union definition for register 's_rx_size_reg' */
typedef struct
{
   uint32_t s_reserved     : 22; /* Bits : 31:10 : NA                                        */
   uint32_t s_ccdl_rx_size : 10; /* Bits : 9:0   : Last received {ccdl_frame} amount of Data */
}
ts_fpga_reg_iip13_uart_ccdl_rx_size_reg_u_bit;

typedef union
{
   uint32_t                                      u_word;
   ts_fpga_reg_iip13_uart_ccdl_rx_size_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_rx_size_reg;

/* Union definition for register 's_rx_timestamp_reg' */
typedef struct
{
   uint32_t s_reserved          : 16; /* Bits : 31:16 : NA                             */
   uint32_t s_ccdl_rx_timestamp : 16; /* Bits : 15:0  : Timestamp of last {ccdl_frame} */
}
ts_fpga_reg_iip13_uart_ccdl_rx_timestamp_reg_u_bit;

typedef union
{
   uint32_t                                           u_word;
   ts_fpga_reg_iip13_uart_ccdl_rx_timestamp_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_rx_timestamp_reg;

/* Union definition for register 's_rx_timeout_reg' */
typedef struct
{
   uint32_t s_reserved             : 18; /* Bits : 31:14 : NA                                                 */
   uint32_t s_ccdl_rx_timeout_conf : 14; /* Bits : 13:0  : Timeout configuration. 1LSB = 10 * {ccdl_bit_time} */
}
ts_fpga_reg_iip13_uart_ccdl_rx_timeout_reg_u_bit;

typedef union
{
   uint32_t                                         u_word;
   ts_fpga_reg_iip13_uart_ccdl_rx_timeout_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_rx_timeout_reg;

/* Union definition for register 's_rx_slave_id_addr_reg' */
typedef struct
{
   uint32_t s_ccdl_rx_id   :  8; /* Bits : 31:24 : {ccdl_h1}[31:24] of last received {ccdl_frame} */
   uint32_t s_ccdl_rx_addr : 24; /* Bits : 23:0  : {ccdl_h1}[23:0] of last received {ccdl_frame}  */
}
ts_fpga_reg_iip13_uart_ccdl_rx_slave_id_addr_reg_u_bit;

typedef union
{
   uint32_t                                               u_word;
   ts_fpga_reg_iip13_uart_ccdl_rx_slave_id_addr_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_rx_slave_id_addr_reg;

/* Union definition for register 's_rx_cmd_size_reg' */
typedef struct
{
   uint32_t s_ccdl_rx_cmd                    :  1; /* Bits : 31    : {ccdl_h2}[31] of last received {ccdl_frame}    */
   uint32_t s_ccdl_rx_slave_rsv1             :  9; /* Bits : 30:22 : {ccdl_h2}[30:22] of last received {ccdl_frame} */
   uint32_t s_ccdl_rx_sof_error_flag         :  1; /* Bits : 21    : {ccdl_h2}[21] of last received {ccdl_frame}    */
   uint32_t s_ccdl_rx_long_frame_error_flag  :  1; /* Bits : 20    : {ccdl_h2}[20] of last received {ccdl_frame}    */
   uint32_t s_ccdl_rx_short_frame_error_flag :  1; /* Bits : 19    : {ccdl_h2}[19] of last received {ccdl_frame}    */
   uint32_t s_ccdl_rx_crc_error_flag         :  1; /* Bits : 18    : {ccdl_h2}[18] of last received {ccdl_frame}    */
   uint32_t s_ccdl_rx_parity_error_flag      :  1; /* Bits : 17    : {ccdl_h2}[17] of last received {ccdl_frame}    */
   uint32_t s_ccdl_rx_addr_error_flag        :  1; /* Bits : 16    : {ccdl_h2}[16] of last received {ccdl_frame}    */
   uint32_t s_ccdl_rx_slave_rsv2             :  6; /* Bits : 15:10 : {ccdl_h2}[15:10] of last received {ccdl_frame} */
   uint32_t s_ccdl_rx_size_command           : 10; /* Bits : 9:0   : {ccdl_h2}[9:0] of last received {ccdl_frame}   */
}
ts_fpga_reg_iip13_uart_ccdl_rx_cmd_size_reg_u_bit;

typedef union
{
   uint32_t                                          u_word;
   ts_fpga_reg_iip13_uart_ccdl_rx_cmd_size_reg_u_bit u_bit;
}
tu_fpga_reg_iip13_uart_ccdl_rx_cmd_size_reg;

/* Group of registers in 'iip13_uart_ccdl' named 'configuration_values' */
typedef struct
{
   tu_fpga_reg_iip13_uart_ccdl_tx_control_reg       s_tx_control_reg;
   tu_fpga_reg_iip13_uart_ccdl_tx_status_reg        s_tx_status_reg;
   tu_fpga_reg_iip13_uart_ccdl_tx_command_reg       s_tx_command_reg;
   tu_fpga_reg_iip13_uart_ccdl_tx_delay_reg         s_tx_delay_reg;
   tu_fpga_reg_iip13_uart_ccdl_tx_slave_id_addr_reg s_tx_slave_id_addr_reg;
   uint32_t                                         spare_0x14_to_0xff[59];
   tu_fpga_reg_iip13_uart_ccdl_rx_control_reg       s_rx_control_reg;
   tu_fpga_reg_iip13_uart_ccdl_rx_status_reg        s_rx_status_reg;
   tu_fpga_reg_iip13_uart_ccdl_rx_size_reg          s_rx_size_reg;
   tu_fpga_reg_iip13_uart_ccdl_rx_timestamp_reg     s_rx_timestamp_reg;
   tu_fpga_reg_iip13_uart_ccdl_rx_timeout_reg       s_rx_timeout_reg;
   uint32_t                                         s_rx_header_sof_reg;
   uint32_t                                         s_rx_header_size_reg;
   tu_fpga_reg_iip13_uart_ccdl_rx_slave_id_addr_reg s_rx_slave_id_addr_reg;
   tu_fpga_reg_iip13_uart_ccdl_rx_cmd_size_reg      s_rx_cmd_size_reg;
   uint32_t                                         s_rx_crc_reg;
}
ts_fpga_reg_iip13_uart_ccdl_configuration_values;

/* ------------------------------------------------------------------------------- */

/* Group of registers in 'iip13_uart_ccdl' named 'ccdl_tx_ram' */
typedef struct
{
   uint32_t s_ccdl_tx_ram[256];
}
ts_fpga_reg_iip13_uart_ccdl_ccdl_tx_ram;

/* ------------------------------------------------------------------------------- */

/* Group of registers in 'iip13_uart_ccdl' named 'ccdl_rx_ram' */
typedef struct
{
   uint32_t s_ccdl_rx_ram[256];
}
ts_fpga_reg_iip13_uart_ccdl_ccdl_rx_ram;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip13_uart_ccdl' */

typedef struct
{
   ts_fpga_reg_iip13_uart_ccdl_configuration_values s_configuration_values_regs;
   uint32_t                                         s_spare_00[950];
   ts_fpga_reg_iip13_uart_ccdl_ccdl_tx_ram          s_ccdl_tx_ram_regs;
   uint32_t                                         s_spare_01[256];
   ts_fpga_reg_iip13_uart_ccdl_ccdl_rx_ram          s_ccdl_rx_ram_regs;
}
ts_fpga_reg_iip13_uart_ccdl;

#endif /* FPGA_REG_IIP13_UART_CCDL_H */
