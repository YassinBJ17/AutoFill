/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP02_RTC_SYNC_H
#define FPGA_REG_IIP02_RTC_SYNC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_minor_frame_per_reg' */
typedef struct
{
   uint32_t s_spare_31_to_16     : 16; /* Bits : 31:16 :                                                                                                                                         */
   uint32_t s_minor_frame_period : 16; /* Bits : 15:0  : Minor frame period value that is applied to the module at the MINOR_FRAME_ PERIOD input(1 LSB = 1 internal time base period = 1.005 탎) */
}
ts_fpga_reg_iip02_rtc_sync_minor_frame_per_reg_u_bit;

typedef union
{
   uint32_t                                             u_word;
   ts_fpga_reg_iip02_rtc_sync_minor_frame_per_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_minor_frame_per_reg;

/* Union definition for register 's_microtick_per_reg' */
typedef struct
{
   uint32_t s_spare_31_to_16   : 16; /* Bits : 31:16 :                                                                                                                                           */
   uint32_t s_microtick_period : 16; /* Bits : 15:0  : Microtick clock period value that is applied to the module at the MICROTICK_ PERIOD input(1 LSB = 1 internal time base period = 1.005 탎) */
}
ts_fpga_reg_iip02_rtc_sync_microtick_per_reg_u_bit;

typedef union
{
   uint32_t                                           u_word;
   ts_fpga_reg_iip02_rtc_sync_microtick_per_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_microtick_per_reg;

/* Union definition for register 's_sync_window_time_reg' */
typedef struct
{
   uint32_t s_spare_31_to_16   : 16; /* Bits : 31:16 :                                                                                                                                             */
   uint32_t s_sync_window_time : 16; /* Bits : 15:0  : HW Synchronization window time that is applied to the module at the SYNC_ WINDOW_TIME input(1 LSB = 1 internal time base period = 1.005 탎) */
}
ts_fpga_reg_iip02_rtc_sync_sync_window_time_reg_u_bit;

typedef union
{
   uint32_t                                              u_word;
   ts_fpga_reg_iip02_rtc_sync_sync_window_time_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_sync_window_time_reg;

/* Union definition for register 's_sync_th_low_reg' */
typedef struct
{
   uint32_t s_spare_31_to_16 : 16; /* Bits : 31:16 :                                                                                                                     */
   uint32_t s_sync_th_low    : 16; /* Bits : 15:0  : Low threshold synchronization, that is applied to the module at the SYNC_TH_LOW input(1 LSB = 1 clk period = 15 ns) */
}
ts_fpga_reg_iip02_rtc_sync_sync_th_low_reg_u_bit;

typedef union
{
   uint32_t                                         u_word;
   ts_fpga_reg_iip02_rtc_sync_sync_th_low_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_sync_th_low_reg;

/* Union definition for register 's_sync_th_high_reg' */
typedef struct
{
   uint32_t s_spare_31_to_16 : 16; /* Bits : 31:16 :                                                                                                                       */
   uint32_t s_sync_th_high   : 16; /* Bits : 15:0  : High threshold synchronization, that is applied to the module at the SYNC_TH_HIGH input(1 LSB = 1 clk period = 15 ns) */
}
ts_fpga_reg_iip02_rtc_sync_sync_th_high_reg_u_bit;

typedef union
{
   uint32_t                                          u_word;
   ts_fpga_reg_iip02_rtc_sync_sync_th_high_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_sync_th_high_reg;

/* Union definition for register 's_sync_th_timeout_reg' */
typedef struct
{
   uint32_t s_spare_31_to_16  : 16; /* Bits : 31:16 :                                                                                                                                            */
   uint32_t s_sync_th_timeout : 16; /* Bits : 15:0  : High threshold synchronization, that is applied to the module at the SYNC_TH_TIMEOUT input(1 LSB = 1 internal time base period = 1.005 탎) */
}
ts_fpga_reg_iip02_rtc_sync_sync_th_timeout_reg_u_bit;

typedef union
{
   uint32_t                                             u_word;
   ts_fpga_reg_iip02_rtc_sync_sync_th_timeout_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_sync_th_timeout_reg;

/* Union definition for register 's_microtick_cnt_reg' */
typedef struct
{
   uint32_t s_spare_31_to_11    : 21; /* Bits : 31:11 :                                                                                                          */
   uint32_t s_microtick_cnt_val : 11; /* Bits : 10:0  : Number of Microtick pulses that have been generated by the module from the beginning of the minor frame. */
}
ts_fpga_reg_iip02_rtc_sync_microtick_cnt_reg_u_bit;

typedef union
{
   uint32_t                                           u_word;
   ts_fpga_reg_iip02_rtc_sync_microtick_cnt_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_microtick_cnt_reg;

/* Union definition for register 's_sync_sts_reg' */
typedef struct
{
   uint32_t s_spare_31_to_4    : 28; /* Bits : 31:4 :                                                              */
   uint32_t s_sync_ok          :  1; /* Bits : 03   : 0 if the RTC is not synchronized1 if the RTC is synchronized */
   uint32_t s_sync_timeout_sts :  1; /* Bits : 02   : Timeout-threshold  synchronization flag                      */
   uint32_t s_sync_high_sts    :  1; /* Bits : 01   : High-threshold  synchronization flag                         */
   uint32_t s_sync_low_sts     :  1; /* Bits : 00   : Low-threshold  synchronization flag                          */
}
ts_fpga_reg_iip02_rtc_sync_sync_sts_reg_u_bit;

typedef union
{
   uint32_t                                      u_word;
   ts_fpga_reg_iip02_rtc_sync_sync_sts_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_sync_sts_reg;

/* Union definition for register 's_sync_cmd_reg' */
typedef struct
{
   uint32_t s_spare_31_to_2 : 30; /* Bits : 31:2 :                                                                                                                                                                        */
   uint32_t s_sync_cmd      :  1; /* Bits : 01   : writing a 0 => no actionwriting a 1 => generation of a SW synchronization command.Command is asserted fugitively when writing {sync_cmd} at 1 and is then de-asserted. */
   uint32_t s_raz_mf_activ  :  1; /* Bits : 00   : writing a 0 => no actionwriting a 1 => reset of the TST_MF_ACTIV signal.Command is asserted fugitively when writing {sync_cmd} at 1 and is then de-asserted.           */
}
ts_fpga_reg_iip02_rtc_sync_sync_cmd_reg_u_bit;

typedef union
{
   uint32_t                                      u_word;
   ts_fpga_reg_iip02_rtc_sync_sync_cmd_reg_u_bit u_bit;
}
tu_fpga_reg_iip02_rtc_sync_sync_cmd_reg;

/* Group of registers in 'iip02_rtc_sync' named 'configuration_and_status_values' */
typedef struct
{
   tu_fpga_reg_iip02_rtc_sync_minor_frame_per_reg  s_minor_frame_per_reg;
   tu_fpga_reg_iip02_rtc_sync_microtick_per_reg    s_microtick_per_reg;
   tu_fpga_reg_iip02_rtc_sync_sync_window_time_reg s_sync_window_time_reg;
   tu_fpga_reg_iip02_rtc_sync_sync_th_low_reg      s_sync_th_low_reg;
   tu_fpga_reg_iip02_rtc_sync_sync_th_high_reg     s_sync_th_high_reg;
   tu_fpga_reg_iip02_rtc_sync_sync_th_timeout_reg  s_sync_th_timeout_reg;
   tu_fpga_reg_iip02_rtc_sync_microtick_cnt_reg    s_microtick_cnt_reg;
   tu_fpga_reg_iip02_rtc_sync_sync_sts_reg         s_sync_sts_reg;
   tu_fpga_reg_iip02_rtc_sync_sync_cmd_reg         s_sync_cmd_reg;
}
ts_fpga_reg_iip02_rtc_sync_configuration_and_status_values;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip02_rtc_sync' */

typedef struct
{
   ts_fpga_reg_iip02_rtc_sync_configuration_and_status_values s_configuration_and_status_values_regs;
}
ts_fpga_reg_iip02_rtc_sync;

#endif /* FPGA_REG_IIP02_RTC_SYNC_H */
