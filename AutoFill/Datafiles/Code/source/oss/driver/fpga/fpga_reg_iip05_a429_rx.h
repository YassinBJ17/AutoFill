/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP05_A429_RX_H
#define FPGA_REG_IIP05_A429_RX_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Group of registers in 'iip05_a429_rx' named 'rx_ram' */
typedef struct
{
   uint32_t s_rx_data_0[2048];
}
ts_fpga_reg_iip05_a429_rx_rx_ram;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_ident_reg' */
typedef struct
{
   uint32_t s_Not Used : 16; /* Bits : 31:16 : Read 0                         */
   uint32_t s_IP_ID    :  8; /* Bits : 15:8  : Module identifier.Fixed value. */
   uint32_t s_IP_VER   :  8; /* Bits : 7:0   : Module version.Fixed value.    */
}
ts_fpga_reg_iip05_a429_rx_ident_reg_u_bit;

typedef union
{
   uint32_t                                  u_word;
   ts_fpga_reg_iip05_a429_rx_ident_reg_u_bit u_bit;
}
tu_fpga_reg_iip05_a429_rx_ident_reg;

/* Union definition for register 's_status_reg' */
typedef struct
{
   uint32_t s_rx_in_progress      :  1; /* Bits : 31    : Set to '1' during the reception of an ARINC word.                                                                                                     */
   uint32_t s_word_received       :  1; /* Bits : 30    : Set to '1' when an ARINC word has been received.Set to '0' after read.                                                                                */
   uint32_t s_level_err           :  1; /* Bits : 29    : Set to '1' when the two ARINC inputs have been detected at '1' at the same time.Set to '0' after read.                                                */
   uint32_t s_min_hbit_time_err   :  1; /* Bits : 28    : Set to '1' when a too short half bit time has been detected.Set to '0' after read.                                                                    */
   uint32_t s_max_hbit_time_err   :  1; /* Bits : 27    : Set to '1' when a too long half bit time has been detected.Set to '0' after read.                                                                     */
   uint32_t s_min_bit_time_err    :  1; /* Bits : 26    : Set to '1' when a too short bit time has been detected.Set to '0' after read.                                                                         */
   uint32_t s_max_bit_time_err    :  1; /* Bits : 25    : Set to '1' when a too long bit time has been detected.Set to '0' after read.                                                                          */
   uint32_t s_min_gap_time_err    :  1; /* Bits : 24    : Set to '1' when a too short gap has been detected.Set to '0' after read.                                                                              */
   uint32_t s_received_parity_err :  1; /* Bits : 23    : Set to '1' when a parity error has been detected in a received ARINC word.Set to '0' after read.                                                      */
   uint32_t s_Not Used            :  2; /* Bits : 22:21 : Read 0                                                                                                                                                */
   uint32_t s_part3_sal_received  :  1; /* Bits : 20    : Set to '1' when an ARINC word matching the configured SAL (part3_sal) has been received.Set to '0' after read.                                        */
   uint32_t s_rx_ram_parity_err   :  1; /* Bits : 19    : Set to '1' when a parity error has been detected during a {rx_ram} read access.Set to '0' after read.                                                 */
   uint32_t s_Not Used_00         :  3; /* Bits : 18:16 : Read 0                                                                                                                                                */
   uint32_t s_rx_ram_empty        :  1; /* Bits : 15    : {Sampling_mode} : Always at '0'.{Queueing_mode} : Set to '1' when {rx_ram} is empty.                                                                  */
   uint32_t s_rx_ram_full         :  1; /* Bits : 14    : {Sampling_mode} : Always at '0'.{Queueing_mode} : Set to '1' when {rx_ram} is full.                                                                   */
   uint32_t s_rx_ram_ovf_err      :  1; /* Bits : 13    : {Sampling_mode} : Always at '0'.{Queueing_mode} : Set to '1' when a write attempt has been made to {rx_ram} while it was full. Set to '0' after read. */
   uint32_t s_Not Used            :  1; /* Bits : 12    : Read 0                                                                                                                                                */
   uint32_t s_rx_ram_word_cnt     : 12; /* Bits : 11:0  : {Sampling_mode} : Always at 0.{Queueing_mode} : Number of ARINC words currently stored in {rx_ram}.                                                   */
}
ts_fpga_reg_iip05_a429_rx_status_reg_u_bit;

typedef union
{
   uint32_t                                   u_word;
   ts_fpga_reg_iip05_a429_rx_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip05_a429_rx_status_reg;

/* Union definition for register 's_command_reg' */
typedef struct
{
   uint32_t s_storage_mode                  :  1; /* Bits : 31    : RX RAM storage mode :'0' = {sampling_mode}.'1' = {queueing_mode}.                                                                                                                                                                                                                                                                                           */
   uint32_t s_Not Used                      : 21; /* Bits : 30:10 : Read 0                                                                                                                                                                                                                                                                                                                                                      */
   uint32_t s_part3_fifo_flush_cmd
Not used :  1; /* Bits : 09    : Writing a '1' causes the flushing of {part3_fifo}.Always read at '0'.                                                                                                                                                                                                                                                                                       */
   uint32_t s_part3_enable                  :  1; /* Bits : 08    : Writing a '1' enables the writing in {part3_fifo} of the received words matching the configured SAL (part3_sal).Writing a '1' enables the writing in {rx_ram} of the received words matching the configured SAL (part3_sal) if {storage_mode} = {queueing_mode}.                                                                                            */
   uint32_t s_corrupt_parity_cmd            :  4; /* Bits : 7:4   : Writing a '1' causes the parity bit to be written erroneous when a word is writen in {rx_ram} or {part3_fifo} as follows :- corrupt_parity_cmd[3] for the parity bit of byte[31:24]- corrupt_parity_cmd[2] for the parity bit of byte[23:16]- corrupt_parity_cmd[1] for the parity bit of byte[15:8]- corrupt_parity_cmd[0] for the parity bit of byte[7:0] */
   uint32_t s_Not Used_00                   :  2; /* Bits : 3:2   : Read 0                                                                                                                                                                                                                                                                                                                                                      */
   uint32_t s_rx_ram_flush_cmd              :  1; /* Bits : 01    : Writing a '1' causes the flushing of {rx_ram}.Always read at '0'.                                                                                                                                                                                                                                                                                           */
   uint32_t s_rx_enable                     :  1; /* Bits : 00    : Writing a '1' enables the reception of the ARINC 429 signals.                                                                                                                                                                                                                                                                                               */
}
ts_fpga_reg_iip05_a429_rx_command_reg_u_bit;

typedef union
{
   uint32_t                                    u_word;
   ts_fpga_reg_iip05_a429_rx_command_reg_u_bit u_bit;
}
tu_fpga_reg_iip05_a429_rx_command_reg;

/* Union definition for register 's_cfg_filter_gap_reg' */
typedef struct
{
   uint32_t s_gap_bit_time : 16; /* Bits : 31:16 : Bit time used to verify the minimum gap of 4 bit times between 2 ARINC words, expressed in clk clock periods.Initialized with value dflt_gap_bit_time at reset deactivation. */
   uint32_t s_Not Used     :  3; /* Bits : 15:13 : Read 0                                                                                                                                                                       */
   uint32_t s_filter_time  : 13; /* Bits : 12:0  : ARINC inputs confirmation time, expressed in clk clock periods.Initialized with value dflt_filter_time at reset deactivation.                                                */
}
ts_fpga_reg_iip05_a429_rx_cfg_filter_gap_reg_u_bit;

typedef union
{
   uint32_t                                           u_word;
   ts_fpga_reg_iip05_a429_rx_cfg_filter_gap_reg_u_bit u_bit;
}
tu_fpga_reg_iip05_a429_rx_cfg_filter_gap_reg;

/* Union definition for register 's_cfg_hbit_time_reg' */
typedef struct
{
   uint32_t s_Not Used      :  1; /* Bits : 31    : Read 0                                                                                                                                            */
   uint32_t s_max_hbit_time : 15; /* Bits : 30:16 : Maximum half bit time of the received ARINC bits, expressed in clk clock periods.Initialized with value dflt_max_hbit_time at reset deactivation. */
   uint32_t s_Not Used      :  1; /* Bits : 15    : Read 0                                                                                                                                            */
   uint32_t s_min_hbit_time : 15; /* Bits : 14:0  : Minimum half bit time of the received ARINC bits, expressed in clk clock periods.Initialized with value dflt_min_hbit_time at reset deactivation. */
}
ts_fpga_reg_iip05_a429_rx_cfg_hbit_time_reg_u_bit;

typedef union
{
   uint32_t                                          u_word;
   ts_fpga_reg_iip05_a429_rx_cfg_hbit_time_reg_u_bit u_bit;
}
tu_fpga_reg_iip05_a429_rx_cfg_hbit_time_reg;

/* Union definition for register 's_cfg_bit_time_reg' */
typedef struct
{
   uint32_t s_max_bit_time : 16; /* Bits : 31:16 : Maximum bit time of the received ARINC bits, expressed in clk clock periods.Initialized with value dflt_max_bit_time at reset deactivation. */
   uint32_t s_min_bit_time : 16; /* Bits : 15:0  : Minimum bit time of the received ARINC bits, expressed in clk clock periods.Initialized with value dflt_min_bit_time at reset deactivation. */
}
ts_fpga_reg_iip05_a429_rx_cfg_bit_time_reg_u_bit;

typedef union
{
   uint32_t                                         u_word;
   ts_fpga_reg_iip05_a429_rx_cfg_bit_time_reg_u_bit u_bit;
}
tu_fpga_reg_iip05_a429_rx_cfg_bit_time_reg;

/* Union definition for register 's_cfg_part3_sal' */
typedef struct
{
   uint32_t s_Not Used  : 24; /* Bits : 31:8 : Read 0                                                                                                                                              */
   uint32_t s_part3_sal :  8; /* Bits : 7:0  : System Address Label to be be compared to the received word label for Part3 reception.Initialized with value dflt_part_3_sal at reset deactivation. */
}
ts_fpga_reg_iip05_a429_rx_cfg_part3_sal_u_bit;

typedef union
{
   uint32_t                                      u_word;
   ts_fpga_reg_iip05_a429_rx_cfg_part3_sal_u_bit u_bit;
}
tu_fpga_reg_iip05_a429_rx_cfg_part3_sal;

/* Group of registers in 'iip05_a429_rx' named 'registers' */
typedef struct
{
   tu_fpga_reg_iip05_a429_rx_ident_reg          s_ident_reg;
   tu_fpga_reg_iip05_a429_rx_status_reg         s_status_reg;
   tu_fpga_reg_iip05_a429_rx_command_reg        s_command_reg;
   tu_fpga_reg_iip05_a429_rx_cfg_filter_gap_reg s_cfg_filter_gap_reg;
   tu_fpga_reg_iip05_a429_rx_cfg_hbit_time_reg  s_cfg_hbit_time_reg;
   tu_fpga_reg_iip05_a429_rx_cfg_bit_time_reg   s_cfg_bit_time_reg;
   tu_fpga_reg_iip05_a429_rx_cfg_part3_sal      s_cfg_part3_sal;
}
ts_fpga_reg_iip05_a429_rx_registers;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip05_a429_rx' */

typedef struct
{
   ts_fpga_reg_iip05_a429_rx_rx_ram    s_rx_ram_regs;
   ts_fpga_reg_iip05_a429_rx_registers s_registers_regs;
}
ts_fpga_reg_iip05_a429_rx;

#endif /* FPGA_REG_IIP05_A429_RX_H */
