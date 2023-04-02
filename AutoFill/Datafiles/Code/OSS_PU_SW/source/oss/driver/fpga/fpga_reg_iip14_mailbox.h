/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP14_MAILBOX_H
#define FPGA_REG_IIP14_MAILBOX_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_rx_fifo_status_reg' */
typedef struct
{
   uint32_t s_reserved              : 15; /* Bits : 31:17 : N/A                                                                                                                                                                                                                  */
   uint32_t s_rx_enable             :  1; /* Bits : 16    : Reception enable/disable statusenable and disable is done thanks to secure software access:-enable : {rx_enable_set_key_1} then {rx_enable_set_key_2}-disable : {rx_enable_clear_key_1} then {rx_enable_clear_key_2} */
   uint32_t s_reserved_00           :  6; /* Bits : 15:10 : N/A                                                                                                                                                                                                                  */
   uint32_t s_rx_fifo_double_biterr :  1; /* Bits : 09    : a double {ecc} error has occured while reading {rx_fifo}                                                                                                                                                             */
   uint32_t s_rx_fifo_single_biterr :  1; /* Bits : 08    : a single {ecc} error has occured while reading {rx_fifo}                                                                                                                                                             */
   uint32_t s_reserved_01           :  2; /* Bits : 7:6   : N/A                                                                                                                                                                                                                  */
   uint32_t s_rx_fifo_overflow      :  1; /* Bits : 05    : An {rx_tvalid} have been received while {rx_fifo} is full                                                                                                                                                            */
   uint32_t s_rx_fifo_flush_done    :  1; /* Bits : 04    : {rx_fifo} have been flushed                                                                                                                                                                                          */
   uint32_t s_rx_fifo_full          :  1; /* Bits : 03    : {rx_fifo} number of {rx_data} ? {rx_fifo_almost_full_threshold}                                                                                                                                                      */
   uint32_t s_reserved              :  1; /* Bits : 02    : N/A                                                                                                                                                                                                                  */
   uint32_t s_rx_fifo_almost_empty  :  1; /* Bits : 01    : {rx_fifo} number of {rx_data} ? {rx_fifo_almost_empty_threshold}                                                                                                                                                     */
   uint32_t s_rx_fifo_empty         :  1; /* Bits : 00    : {rx_fifo} is empty                                                                                                                                                                                                   */
}
ts_fpga_reg_iip14_mailbox_rx_fifo_status_reg_u_bit;

typedef union
{
   uint32_t                                           u_word;
   ts_fpga_reg_iip14_mailbox_rx_fifo_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_rx_fifo_status_reg;

/* Union definition for register 's_rx_fifo_status_ack_reg' */
typedef struct
{
   uint32_t s_reserved             : 29; /* Bits : 31:3 : N/A                                                             */
   uint32_t s_rx_fifo_biterr_ack   :  1; /* Bits : 02   : set {rx_fifo_single_biterr} and {rx_fifo_double_biterr} to 1'b0 */
   uint32_t s_rx_fifo_overflow_ack :  1; /* Bits : 01   : set {rx_fifo_overflow} to 1'b0                                  */
   uint32_t s_rx_fifo_flush_ack    :  1; /* Bits : 00   : set {rx_fifo_flush_done} to 1'b0                                */
}
ts_fpga_reg_iip14_mailbox_rx_fifo_status_ack_reg_u_bit;

typedef union
{
   uint32_t                                               u_word;
   ts_fpga_reg_iip14_mailbox_rx_fifo_status_ack_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_rx_fifo_status_ack_reg;

/* Union definition for register 's_rx_fifo_control_reg' */
typedef struct
{
   uint32_t s_reserved                     : 29; /* Bits : 31:3 : N/A                                        */
   uint32_t s_rx_fifo_inject_double_biterr :  1; /* Bits : 02   : used to inject a double error in {rx_fifo} */
   uint32_t s_rx_fifo_inject_single_biterr :  1; /* Bits : 01   : used to inject a simple error in {rx_fifo} */
   uint32_t s_rx_fifo_flush                :  1; /* Bits : 00   : used to flush the {rx_fifo}                */
}
ts_fpga_reg_iip14_mailbox_rx_fifo_control_reg_u_bit;

typedef union
{
   uint32_t                                            u_word;
   ts_fpga_reg_iip14_mailbox_rx_fifo_control_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_rx_fifo_control_reg;

/* Union definition for register 's_rx_fifo_config1_reg' */
typedef struct
{
   uint32_t s_reserved                       :  3; /* Bits : 31:29 : N/A                                       */
   uint32_t s_rx_fifo_almost_full_threshold  : 13; /* Bits : 28:16 : used for {rx_fifo_almost_full} assertion  */
   uint32_t s_reserved_00                    :  3; /* Bits : 15:13 : N/A                                       */
   uint32_t s_rx_fifo_almost_empty_threshold : 13; /* Bits : 12:0  : used for {rx_fifo_almost_empty} assertion */
}
ts_fpga_reg_iip14_mailbox_rx_fifo_config1_reg_u_bit;

typedef union
{
   uint32_t                                            u_word;
   ts_fpga_reg_iip14_mailbox_rx_fifo_config1_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_rx_fifo_config1_reg;

/* Group of registers in 'iip14_mailbox' named 'rx' */
typedef struct
{
   uint32_t                                         s_rx_data_reg;
   tu_fpga_reg_iip14_mailbox_rx_fifo_status_reg     s_rx_fifo_status_reg;
   tu_fpga_reg_iip14_mailbox_rx_fifo_status_ack_reg s_rx_fifo_status_ack_reg;
   tu_fpga_reg_iip14_mailbox_rx_fifo_control_reg    s_rx_fifo_control_reg;
   tu_fpga_reg_iip14_mailbox_rx_fifo_config1_reg    s_rx_fifo_config1_reg;
   uint32_t                                         s_rx_enable_set_key_1_reg;
   uint32_t                                         s_rx_enable_set_key_2_reg;
   uint32_t                                         s_rx_enable_clear_key_1_reg;
   uint32_t                                         s_rx_enable_clear_key_2_reg;
}
ts_fpga_reg_iip14_mailbox_rx;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_tx_fifo_status_reg' */
typedef struct
{
   uint32_t s_reserved              : 22; /* Bits : 31:10 : N/A                                                              */
   uint32_t s_tx_fifo_double_biterr :  1; /* Bits : 09    : a double {ecc} error has occured while reading {tx_fifo}         */
   uint32_t s_tx_fifo_single_biterr :  1; /* Bits : 08    : a single {ecc} error has occured while reading {tx_fifo}         */
   uint32_t s_reserved              :  1; /* Bits : 07    : N/A                                                              */
   uint32_t s_tx_sending            :  1; /* Bits : 06    : Data are currently send on {tx_axi_stream}                       */
   uint32_t s_tx_fifo_overflow      :  1; /* Bits : 05    : A write have been performed in the {tx_fifo} while full          */
   uint32_t s_tx_fifo_flush_done    :  1; /* Bits : 04    : {tx_fifo} have been flushed                                      */
   uint32_t s_tx_fifo_full          :  1; /* Bits : 03    : {tx_fifo} is full                                                */
   uint32_t s_tx_fifo_almost_full   :  1; /* Bits : 02    : {tx_fifo} number of {tx_data} ? {tx_fifo_almost_full_threshold}  */
   uint32_t s_tx_fifo_almost_empty  :  1; /* Bits : 01    : {tx_fifo} number of {tx_data} ? {tx_fifo_almost_empty_threshold} */
   uint32_t s_tx_fifo_empty         :  1; /* Bits : 00    : {tx_fifo} is empty                                               */
}
ts_fpga_reg_iip14_mailbox_tx_fifo_status_reg_u_bit;

typedef union
{
   uint32_t                                           u_word;
   ts_fpga_reg_iip14_mailbox_tx_fifo_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_fifo_status_reg;

/* Union definition for register 's_tx_fifo_status_ack_reg' */
typedef struct
{
   uint32_t s_reserved             : 29; /* Bits : 31:3 : N/A                                                             */
   uint32_t s_tx_fifo_biterr_ack   :  1; /* Bits : 02   : set {tx_fifo_single_biterr} and {tx_fifo_double_biterr} to 1'b0 */
   uint32_t s_tx_fifo_overflow_ack :  1; /* Bits : 01   : set {tx_fifo_overflow} to 1'b0                                  */
   uint32_t s_tx_fifo_flush_ack    :  1; /* Bits : 00   : set {tx_fifo_flush_done} to 1'b0                                */
}
ts_fpga_reg_iip14_mailbox_tx_fifo_status_ack_reg_u_bit;

typedef union
{
   uint32_t                                               u_word;
   ts_fpga_reg_iip14_mailbox_tx_fifo_status_ack_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_fifo_status_ack_reg;

/* Union definition for register 's_tx_fifo_control_reg' */
typedef struct
{
   uint32_t s_reserved                     : 29; /* Bits : 31:3 : N/A                                        */
   uint32_t s_tx_fifo_inject_double_biterr :  1; /* Bits : 02   : used to inject a double error in {tx_fifo} */
   uint32_t s_tx_fifo_inject_single_biterr :  1; /* Bits : 01   : used to inject a simple error in {tx_fifo} */
   uint32_t s_tx_fifo_flush                :  1; /* Bits : 00   : used to flush the {tx_fifo}                */
}
ts_fpga_reg_iip14_mailbox_tx_fifo_control_reg_u_bit;

typedef union
{
   uint32_t                                            u_word;
   ts_fpga_reg_iip14_mailbox_tx_fifo_control_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_fifo_control_reg;

/* Union definition for register 's_tx_fifo_config_reg' */
typedef struct
{
   uint32_t s_reserved                       :  3; /* Bits : 31:29 : N/A                                       */
   uint32_t s_tx_fifo_almost_full_threshold  : 13; /* Bits : 28:16 : used for {tx_fifo_almost_full} assertion  */
   uint32_t s_reserved_00                    :  3; /* Bits : 15:13 : N/A                                       */
   uint32_t s_tx_fifo_almost_empty_threshold : 13; /* Bits : 12:0  : used for {tx_fifo_almost_empty} assertion */
}
ts_fpga_reg_iip14_mailbox_tx_fifo_config_reg_u_bit;

typedef union
{
   uint32_t                                           u_word;
   ts_fpga_reg_iip14_mailbox_tx_fifo_config_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_fifo_config_reg;

/* Group of registers in 'iip14_mailbox' named 'tx' */
typedef struct
{
   uint32_t                                         s_tx_data_reg;
   tu_fpga_reg_iip14_mailbox_tx_fifo_status_reg     s_tx_fifo_status_reg;
   tu_fpga_reg_iip14_mailbox_tx_fifo_status_ack_reg s_tx_fifo_status_ack_reg;
   tu_fpga_reg_iip14_mailbox_tx_fifo_control_reg    s_tx_fifo_control_reg;
   tu_fpga_reg_iip14_mailbox_tx_fifo_config_reg     s_tx_fifo_config_reg;
}
ts_fpga_reg_iip14_mailbox_tx;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_tx_cmd_fifo_status_reg' */
typedef struct
{
   uint32_t s_reserved                  : 15; /* Bits : 31:17 : N/A                                                                                                                                                                                                                     */
   uint32_t s_tx_enable                 :  1; /* Bits : 16    : transmission enable/disable statusenable and disable is done thanks to secure software access:-enable : {tx_enable_set_key_1} then {tx_enable_set_key_2}-disable : {tx_enable_clear_key_1} then {tx_enable_clear_key_2} */
   uint32_t s_reserved_00               :  5; /* Bits : 15:11 : N/A                                                                                                                                                                                                                     */
   uint32_t s_tx_corruption_status      :  1; /* Bits : 10    : A {tx_tcorrupt} have been send                                                                                                                                                                                          */
   uint32_t s_tx_cmd_fifo_double_biterr :  1; /* Bits : 09    : a double {ecc} error has occured while reading {tx_cmd_fifo}                                                                                                                                                            */
   uint32_t s_tx_cmd_fifo_single_biterr :  1; /* Bits : 08    : a single {ecc} error has occured while reading {tx_cmd_fifo}                                                                                                                                                            */
   uint32_t s_reserved_01               :  2; /* Bits : 7:6   : N/A                                                                                                                                                                                                                     */
   uint32_t s_tx_cmd_fifo_overflow      :  1; /* Bits : 05    : A write have been performed in the {tx_cmd_fifo} while full                                                                                                                                                             */
   uint32_t s_tx_cmd_fifo_flush_done    :  1; /* Bits : 04    : {tx_cmd_fifo} have been flushed                                                                                                                                                                                         */
   uint32_t s_tx_cmd_fifo_full          :  1; /* Bits : 03    : {tx_cmd_fifo} is full                                                                                                                                                                                                   */
   uint32_t s_tx_cmd_fifo_almost_full   :  1; /* Bits : 02    : {tx_cmd_fifo} number of {tx_cmd} ? {tx_cmd_fifo_almost_full_threshold}                                                                                                                                                  */
   uint32_t s_tx_cmd_fifo_almost_empty  :  1; /* Bits : 01    : {tx_cmd_fifo} number of {tx_cmd} ? {tx_cmd_fifo_almost_empty_threshold}                                                                                                                                                 */
   uint32_t s_tx_cmd_fifo_empty         :  1; /* Bits : 00    : {tx_cmd_fifo} is empty                                                                                                                                                                                                  */
}
ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_reg_u_bit;

typedef union
{
   uint32_t                                               u_word;
   ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_reg;

/* Union definition for register 's_tx_cmd_fifo_status_ack_reg' */
typedef struct
{
   uint32_t s_reserved                 : 28; /* Bits : 31:4 : N/A                                                                     */
   uint32_t s_tx_corruption_ack        :  1; /* Bits : 03   : set {tx_corruption_status} to 1'b0                                      */
   uint32_t s_tx_cmd_fifo_biterr_ack   :  1; /* Bits : 02   : set {tx_cmd_fifo_single_biterr} and {tx_cmd_fifo_double_biterr} to 1'b0 */
   uint32_t s_tx_cmd_fifo_overflow_ack :  1; /* Bits : 01   : set {tx_cmd_fifo_overflow} to 1'b0                                      */
   uint32_t s_tx_cmd_fifo_flush_ack    :  1; /* Bits : 00   : set {tx_cmd_fifo_flush_done} to 1'b0                                    */
}
ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_ack_reg_u_bit;

typedef union
{
   uint32_t                                                   u_word;
   ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_ack_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_ack_reg;

/* Union definition for register 's_tx_cmd_fifo_control_reg' */
typedef struct
{
   uint32_t s_reserved                         : 29; /* Bits : 31:3 : N/A                                            */
   uint32_t s_tx_cmd_fifo_inject_double_biterr :  1; /* Bits : 02   : used to inject a double error in {tx_cmd_fifo} */
   uint32_t s_tx_cmd_fifo_inject_single_biterr :  1; /* Bits : 01   : used to inject a simple error in {tx_cmd_fifo} */
   uint32_t s_tx_cmd_fifo_flush                :  1; /* Bits : 00   : used to flush the {tx_cmd_fifo}                */
}
ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_control_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_control_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_control_reg;

/* Union definition for register 's_tx_cmd_fifo_config_reg' */
typedef struct
{
   uint32_t s_reserved                           :  6; /* Bits : 31:26 : N/A                                           */
   uint32_t s_tx_cmd_fifo_almost_full_threshold  : 10; /* Bits : 25:16 : used for {tx_cmd_fifo_almost_full} assertion  */
   uint32_t s_reserved_00                        :  6; /* Bits : 15:10 : N/A                                           */
   uint32_t s_tx_cmd_fifo_almost_empty_threshold : 10; /* Bits : 9:0   : used for {tx_cmd_fifo_almost_empty} assertion */
}
ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_config_reg_u_bit;

typedef union
{
   uint32_t                                               u_word;
   ts_fpga_reg_iip14_mailbox_tx_cmd_fifo_config_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_config_reg;

/* Union definition for register 's_tx_delay_config_reg' */
typedef struct
{
   uint32_t s_reserved   : 22; /* Bits : 31:10 : N/A                                                                                                                         */
   uint32_t s_{tx_delay} : 10; /* Bits : 9:0   : add a minimum delay of {tx_delay}*{TX_DELAY_RATIO}*{clk} period before sending new data on {tx_axi_stream}value : 0 to 1023 */
}
ts_fpga_reg_iip14_mailbox_tx_delay_config_reg_u_bit;

typedef union
{
   uint32_t                                            u_word;
   ts_fpga_reg_iip14_mailbox_tx_delay_config_reg_u_bit u_bit;
}
tu_fpga_reg_iip14_mailbox_tx_delay_config_reg;

/* Group of registers in 'iip14_mailbox' named 'tx_cmd' */
typedef struct
{
   uint32_t                                             s_tx_cmd_data_reg;
   tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_reg     s_tx_cmd_fifo_status_reg;
   tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_status_ack_reg s_tx_cmd_fifo_status_ack_reg;
   tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_control_reg    s_tx_cmd_fifo_control_reg;
   tu_fpga_reg_iip14_mailbox_tx_cmd_fifo_config_reg     s_tx_cmd_fifo_config_reg;
   tu_fpga_reg_iip14_mailbox_tx_delay_config_reg        s_tx_delay_config_reg;
   uint32_t                                             s_tx_enable_set_key_1_reg;
   uint32_t                                             s_tx_enable_set_key_2_reg;
   uint32_t                                             s_tx_enable_clear_key_1_reg;
   uint32_t                                             s_tx_enable_clear_key_2_reg;
}
ts_fpga_reg_iip14_mailbox_tx_cmd;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip14_mailbox' */

typedef struct
{
   ts_fpga_reg_iip14_mailbox_rx     s_rx_regs;
   uint32_t                         s_spare_00[3];
   ts_fpga_reg_iip14_mailbox_tx     s_tx_regs;
   uint32_t                         s_spare_01[3];
   ts_fpga_reg_iip14_mailbox_tx_cmd s_tx_cmd_regs;
}
ts_fpga_reg_iip14_mailbox;

#endif /* FPGA_REG_IIP14_MAILBOX_H */
