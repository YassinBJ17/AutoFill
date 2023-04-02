/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP04_A429_TX_H
#define FPGA_REG_IIP04_A429_TX_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Group of registers in 'iip04_a429_tx' named 'tx_fifo' */
typedef struct
{
   uint32_t s_data_1[256];
}
ts_fpga_reg_iip04_a429_tx_tx_fifo;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_ident_reg' */
typedef struct
{
   uint32_t s_Not Used : 16; /* Bits : 31:16 : Read 0                          */
   uint32_t s_IP_ID    :  8; /* Bits : 15:8  : IP identifier numberFixed value */
   uint32_t s_IP_REV   :  8; /* Bits : 7:0   : IP revision numberFixed value   */
}
ts_fpga_reg_iip04_a429_tx_ident_reg_u_bit;

typedef union
{
   uint32_t                                  u_word;
   ts_fpga_reg_iip04_a429_tx_ident_reg_u_bit u_bit;
}
tu_fpga_reg_iip04_a429_tx_ident_reg;

/* Union definition for register 's_status_reg' */
typedef struct
{
   uint32_t s_Not Used      : 14; /* Bits : 31:18 :                                                                                                                               */
   uint32_t s_FIFO_OVF_ERR  :  1; /* Bits : 17    : Read at '1' when a write attempt has been made to the FIFO while it was fullSet to '0' after read.                            */
   uint32_t s_FIFO_PRTY_ERR :  1; /* Bits : 16    : Read at '1' when a parity error has been detected during the internal read of the FIFO for transmissionSet to '0' after read. */
   uint32_t s_Not Used_00   :  4; /* Bits : 15:12 : Read 0                                                                                                                        */
   uint32_t s_FIFO_FULL     :  1; /* Bits : 11    : Read at '1' when the FIFO is full                                                                                             */
   uint32_t s_FIFO_EMPTY    :  1; /* Bits : 10    : Read at '1' when the FIFO is empty                                                                                            */
   uint32_t s_TX_BUSY       :  1; /* Bits : 09    : Read at '1' during the transmission of an ARINC word and during the gap time that follows the transmission.                   */
   uint32_t s_FIFO_WORD_CNT :  9; /* Bits : 8:0   : Number of ARINC words currently stored in the FIFO                                                                            */
}
ts_fpga_reg_iip04_a429_tx_status_reg_u_bit;

typedef union
{
   uint32_t                                   u_word;
   ts_fpga_reg_iip04_a429_tx_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip04_a429_tx_status_reg;

/* Union definition for register 's_speed_cfg1_reg' */
typedef struct
{
   uint32_t s_TX_BIT_TIME_HS : 16; /* Bits : 31:16 : High Speed Bit time value of the transmitted ARINC bits, expressed in clk clock periods (15 ns)Initialised with dft_bit_time_hs(15:0)  value at reset deactivation.Value less than 0x0004 shall not be used by user project, due to quarter bit resolution in design. */
   uint32_t s_TX_BIT_TIME_LS : 16; /* Bits : 15:0  : Low Speed Bit time value of the transmitted ARINC bits, expressed in clk clock periods (15 ns)Initialised with dft_bit_time_ls(15:0)  value at reset deactivationValue less than 0x0004 shall not be used by user project, due to quarter bit resolution in design.   */
}
ts_fpga_reg_iip04_a429_tx_speed_cfg1_reg_u_bit;

typedef union
{
   uint32_t                                       u_word;
   ts_fpga_reg_iip04_a429_tx_speed_cfg1_reg_u_bit u_bit;
}
tu_fpga_reg_iip04_a429_tx_speed_cfg1_reg;

/* Union definition for register 's_speed_cfg2_reg' */
typedef struct
{
   uint32_t s_Not Used     : 18; /* Bits : 31:14 : Read 0                                                                                                                                                                                                                                                                                                                                                                  */
   uint32_t s_GAP_TIME     :  6; /* Bits : 13:8  : GAP time between two  transmitted ARINC words expressed in bit time number.Initialised with value dft_gap_time at reset deactivation.                                                                                                                                                                                                                                   */
   uint32_t s_Not Used_00  :  7; /* Bits : 7:1   : Read 0                                                                                                                                                                                                                                                                                                                                                                  */
   uint32_t s_TX_SPEED_SEL :  1; /* Bits : 00    : Select the {bit time} value as follow :    1: {bit time} = TX_BIT_TIME_HS, for High speed    0: {bit time} = TX_BIT_TIME_LS,  for Low speedandControl of the {tx_speed_sel} output signal as follows :    1: tx_speed_sel output = '1' means "High Speed"    0: tx_speed_sel output = '0' means "Low Speed", Initialised with value dft_speed_sel at reset deactivation */
}
ts_fpga_reg_iip04_a429_tx_speed_cfg2_reg_u_bit;

typedef union
{
   uint32_t                                       u_word;
   ts_fpga_reg_iip04_a429_tx_speed_cfg2_reg_u_bit u_bit;
}
tu_fpga_reg_iip04_a429_tx_speed_cfg2_reg;

/* Union definition for register 's_command_reg' */
typedef struct
{
   uint32_t s_Not Used             : 20; /* Bits : 31:12 : Read 0                                                                                                                                                           */
   uint32_t s_FIFO_PRTY_ERR_CMD(3) :  1; /* Bits : 11    : Writing a '1' causes the parity bit for byte DATA#(31:24) to be inverted (byte corruption forcing) when a word is written in the FIFO                            */
   uint32_t s_FIFO_PRTY_ERR_CMD(2) :  1; /* Bits : 10    : Writing a '1' causes the parity bit for byte DATA#(23:16) to be  inverted (byte corruption forcing)  when a word is written in the FIFO                          */
   uint32_t s_FIFO_PRTY_ERR_CMD(1) :  1; /* Bits : 09    : Writing a '1' causes the parity bit for byte DATA#(15:8) to be  inverted (byte corruption forcing)  when a word is written in the FIFO                           */
   uint32_t s_FIFO_PRTY_ERR_CMD(0) :  1; /* Bits : 08    : Writing a '1' causes the parity bit for byte DATA#(7:0) to be inverted (byte corruption forcing)  when a word is written in the FIFO                             */
   uint32_t s_Not Used_00          :  3; /* Bits : 7:5   :                                                                                                                                                                  */
   uint32_t s_FIFO_FLUSH_CMD       :  1; /* Bits : 04    : Writing a '1' causes  the re_initialization of the FIFO (all stored datas are lost) , the bit is automatically clear to '0' after write inside the IIP.Read '0'. */
   uint32_t s_TX_PRTY_ERR_CMD      :  1; /* Bits : 03    : Writing a '1' causes the transmitted words to have an erroneous parity bit                                                                                       */
   uint32_t s_Not Used_01          :  2; /* Bits : 2:1   : Read 0                                                                                                                                                           */
   uint32_t s_TRANSMIT_ENABLE      :  1; /* Bits : 00    : Writing a '1' enables the transmission of the ARINC 429 words present in the  FIFO.                                                                              */
}
ts_fpga_reg_iip04_a429_tx_command_reg_u_bit;

typedef union
{
   uint32_t                                    u_word;
   ts_fpga_reg_iip04_a429_tx_command_reg_u_bit u_bit;
}
tu_fpga_reg_iip04_a429_tx_command_reg;

/* Group of registers in 'iip04_a429_tx' named 'configuration' */
typedef struct
{
   tu_fpga_reg_iip04_a429_tx_ident_reg      s_ident_reg;
   tu_fpga_reg_iip04_a429_tx_status_reg     s_status_reg;
   tu_fpga_reg_iip04_a429_tx_speed_cfg1_reg s_speed_cfg1_reg;
   tu_fpga_reg_iip04_a429_tx_speed_cfg2_reg s_speed_cfg2_reg;
   tu_fpga_reg_iip04_a429_tx_command_reg    s_command_reg;
}
ts_fpga_reg_iip04_a429_tx_configuration;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip04_a429_tx' */

typedef struct
{
   ts_fpga_reg_iip04_a429_tx_tx_fifo       s_tx_fifo_regs;
   ts_fpga_reg_iip04_a429_tx_configuration s_configuration_regs;
}
ts_fpga_reg_iip04_a429_tx;

#endif /* FPGA_REG_IIP04_A429_TX_H */
