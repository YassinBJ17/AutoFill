/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP03_WATCHDOG_H
#define FPGA_REG_IIP03_WATCHDOG_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_wd_status_reg' */
typedef struct
{
   uint32_t s_arm_counter        :  8; /* Bits : 31:24 : Count of transitions from disarmed to armed.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           */
   uint32_t s_failure_counter    :  8; /* Bits : 23:16 : Count of watchdog failures.This counter is increased if it is less than {max_failure_start}  when {init_mode} = 0b0 (start mode), or less than {max_failure_oper} when {init_mode} = 0b1 (oper mode), and one of the following conditions occurs:- {wd_state} = 0b0 (disarmed state) for a duration longer than {max_init_time_start} when {init_mode} = 0b0 (start mode), or longer than {max_init_time_oper} when {init_mode} = 0b1 (oper mode).- {wd_state} = 0b1 (armed state) and there is a refresh command whereas the time elapsed since the activation of the armed state or since the last refresh command is lower than {min_window_time}.- {wd_state} = 0b1 (armed state), and the time elapsed since the activation of the armed state or since the last refresh command is greater than {max_window_time}.- {wd_state} = 0b1 (armed state) and arm command is performed. */
   uint32_t s_Not Used           : 10; /* Bits : 15:6  :                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        */
   uint32_t s_init_timer_config  :  1; /* Bits : 05    : State of {init_timer} inhibition:0b1 = {init_timer} is inhibited.0b0 = {init_timer} is enabled.This bit is at 0b1 when at least one of the following conditions is true:- When {init_timer_inhibit_1} is equal to 0x1AD5C38C and {init_timer_inhibit} is high.- When {init_timer_inhibit_1} is equal to 0x1AD5C38C and {init_timer_inhibit_2} is equal to 0xFE64C79D.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  */
   uint32_t s_init_timer_inhibit :  1; /* Bits : 04    : State of {init_timer_inhibit} input:0b1 = {init_timer_inhibit} input is high.0b0 = {init_timer_inhibit} input is low.This bit takes part in initialization timer inhibition:- When {init_timer_inhibit_1} is equal to 0x1AD5C38C and {init_timer_inhibit} is high, the initialization timer is inhibited.- When {init_timer_inhibit_1} is equal to 0x1AD5C38C and {init_timer_inhibit_2} is equal to 0xFE64C79D, the initialization timer is inhibited.- Other values disable the timer inhibition.                                                                                                                                                                                                                                                                                                                                                                                    */
   uint32_t s_wd_irq             :  1; /* Bits : 03    : State of watchdog interrupt.This bit is set to 0b1 when a {watchdog failure event} occurs while {irq_config = 0b1} (interrupt enabled) and reset to 0b0 when {irq_ack_cmd} is written at 0b1 (interrupt acknowledge command).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          */
   uint32_t s_irq_config         :  1; /* Bits : 02    : Configuration of watchdog interrupt:0b0 = interrupt is disabled.0b1 = interrupt is enabled.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            */
   uint32_t s_wd_state           :  1; /* Bits : 01    : Watchdog state:0b0 = disarmed.0b1 = armed.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             */
   uint32_t s_init_mode          :  1; /* Bits : 00    : Watchdog initialization mode:0b0 = start initialization mode.0b1 = oper initialization mode.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           */
}
ts_fpga_reg_iip03_watchdog_wd_status_reg_u_bit;

typedef union
{
   uint32_t                                       u_word;
   ts_fpga_reg_iip03_watchdog_wd_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_status_reg;

/* Union definition for register 's_wd_irq_cmd_reg' */
typedef struct
{
   uint32_t s_Not Used        : 29; /* Bits : 31:3 :                                                                                          */
   uint32_t s_irq_ack_cmd     :  1; /* Bits : 02   : Watchdog interrupt acknowledge command:0b1 = acknowledges the interrupt.0b0 = no effect. */
   uint32_t s_irq_disable_cmd :  1; /* Bits : 01   : Watchdog interrupt disable comand:0b1 = disables the interrupt.0b0 = no effect.          */
   uint32_t s_irq_enable_cmd  :  1; /* Bits : 00   : Watchdog interrupt enable comand:0b1 = enables the interrupt.0b0 = no effect.            */
}
ts_fpga_reg_iip03_watchdog_wd_irq_cmd_reg_u_bit;

typedef union
{
   uint32_t                                        u_word;
   ts_fpga_reg_iip03_watchdog_wd_irq_cmd_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_irq_cmd_reg;

/* Group of registers in 'iip03_watchdog' named 'management' */
typedef struct
{
   tu_fpga_reg_iip03_watchdog_wd_status_reg  s_wd_status_reg;
   uint32_t                                  s_wd_arm_cmd_reg;
   uint32_t                                  s_wd_refresh_cmd_reg;
   tu_fpga_reg_iip03_watchdog_wd_irq_cmd_reg s_wd_irq_cmd_reg;
   uint32_t                                  s_wd_activity_check_in_reg;
   uint32_t                                  s_wd_init_mode_cmd_reg;
   uint32_t                                  s_wd_init_timer_inhibit_1_reg;
   uint32_t                                  s_wd_init_timer_inhibit_2_reg;
}
ts_fpga_reg_iip03_watchdog_management;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_wd_max_init_time_start_reg' */
typedef struct
{
   uint32_t s_Not Used            : 16; /* Bits : 31:16 :                                                                                                                                                                                                                                              */
   uint32_t s_max_init_time_start : 16; /* Bits : 15:0  : This value corresponds to the maximum initialization time in the disarmed state in start initialization mode:- 1 LSB = 1000 periods of {internal time base}.- Possible range = [0 to 65535].- A value of 0xFFFF deactivates this time limit. */
}
ts_fpga_reg_iip03_watchdog_wd_max_init_time_start_reg_u_bit;

typedef union
{
   uint32_t                                                    u_word;
   ts_fpga_reg_iip03_watchdog_wd_max_init_time_start_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_max_init_time_start_reg;

/* Union definition for register 's_wd_max_init_time_oper_reg' */
typedef struct
{
   uint32_t s_Not Used           : 16; /* Bits : 31:16 :                                                                                                                                                                                                                                             */
   uint32_t s_max_init_time_oper : 16; /* Bits : 15:0  : This value corresponds to the maximum initialization time in the disarmed state in oper initialization mode:- 1 LSB = 1000 periods of {internal time base}.- Possible range = [0 to 65535].- A value of 0xFFFF deactivates this time limit. */
}
ts_fpga_reg_iip03_watchdog_wd_max_init_time_oper_reg_u_bit;

typedef union
{
   uint32_t                                                   u_word;
   ts_fpga_reg_iip03_watchdog_wd_max_init_time_oper_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_max_init_time_oper_reg;

/* Union definition for register 's_wd_max_failure_start_reg' */
typedef struct
{
   uint32_t s_Not Used          : 24; /* Bits : 31:8 :                                                                                                                                                                                                */
   uint32_t s_max_failure_start :  8; /* Bits : 7:0  : This value corresponds to the maximum allowed watchdog failure events in start initialization mode:- 1 LSB = 1 failure.- Possible range = [0 to 255].- A value of 0xFF deactivates this limit. */
}
ts_fpga_reg_iip03_watchdog_wd_max_failure_start_reg_u_bit;

typedef union
{
   uint32_t                                                  u_word;
   ts_fpga_reg_iip03_watchdog_wd_max_failure_start_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_max_failure_start_reg;

/* Union definition for register 's_wd_max_failure_oper_reg' */
typedef struct
{
   uint32_t s_Not Used         : 24; /* Bits : 31:8 :                                                                                                                                                                                               */
   uint32_t s_max_failure_oper :  8; /* Bits : 7:0  : This value corresponds to the maximum allowed watchdog failure events in oper initialization mode:- 1 LSB = 1 failure.- Possible range = [0 to 255].- A value of 0xFF deactivates this limit. */
}
ts_fpga_reg_iip03_watchdog_wd_max_failure_oper_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_iip03_watchdog_wd_max_failure_oper_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_max_failure_oper_reg;

/* Union definition for register 's_wd_max_arm_counter_reg' */
typedef struct
{
   uint32_t s_Not Used        : 24; /* Bits : 31:8 :                                                                                                                                                                     */
   uint32_t s_max_arm_counter :  8; /* Bits : 7:0  : This value corresponds to the maximum disarmed to armed allowed transitions:- 1 LSB = 1 arm.- Possible range = [0 to 255].- A value of 0xFF deactivates this limit. */
}
ts_fpga_reg_iip03_watchdog_wd_max_arm_counter_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_iip03_watchdog_wd_max_arm_counter_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_max_arm_counter_reg;

/* Union definition for register 's_wd_min_window_time_reg' */
typedef struct
{
   uint32_t s_Not Used        : 16; /* Bits : 31:16 :                                                                                                                                                                                                             */
   uint32_t s_min_window_time : 16; /* Bits : 15:0  : This value corresponds to the minimum time between watchdog refresh events:- 1 LSB = 1 period of {internal time base}.- Possible range = [0 to 65535].- A value of 0x0000 inhibits this minimum time limit. */
}
ts_fpga_reg_iip03_watchdog_wd_min_window_time_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_iip03_watchdog_wd_min_window_time_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_min_window_time_reg;

/* Union definition for register 's_wd_max_window_time_reg' */
typedef struct
{
   uint32_t s_Not Used        : 16; /* Bits : 31:16 :                                                                                                                                                        */
   uint32_t s_max_window_time : 16; /* Bits : 15:0  : This value corresponds to the maximum time between watchdog refresh events:- 1 LSB = 1 period of {internal time base}.- Possible range = [0 to 65535]. */
}
ts_fpga_reg_iip03_watchdog_wd_max_window_time_reg_u_bit;

typedef union
{
   uint32_t                                                u_word;
   ts_fpga_reg_iip03_watchdog_wd_max_window_time_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_max_window_time_reg;

/* Union definition for register 's_wd_hreset_delay_reg' */
typedef struct
{
   uint32_t s_Not Used     : 16; /* Bits : 31:16 :                                                                                                                                                                                                                  */
   uint32_t s_hreset_delay : 16; /* Bits : 15:0  : This value corresponds to the delay between a watchdog failure event and reset output assertion:- 1 LSB = 1 period of {clk_wd} clock.- 1 LSB = 1 period of {internal time base}.- Possible range = [0 to 65535]. */
}
ts_fpga_reg_iip03_watchdog_wd_hreset_delay_reg_u_bit;

typedef union
{
   uint32_t                                             u_word;
   ts_fpga_reg_iip03_watchdog_wd_hreset_delay_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_hreset_delay_reg;

/* Group of registers in 'iip03_watchdog' named 'configuration' */
typedef struct
{
   tu_fpga_reg_iip03_watchdog_wd_max_init_time_start_reg s_wd_max_init_time_start_reg;
   tu_fpga_reg_iip03_watchdog_wd_max_init_time_oper_reg  s_wd_max_init_time_oper_reg;
   tu_fpga_reg_iip03_watchdog_wd_max_failure_start_reg   s_wd_max_failure_start_reg;
   tu_fpga_reg_iip03_watchdog_wd_max_failure_oper_reg    s_wd_max_failure_oper_reg;
   tu_fpga_reg_iip03_watchdog_wd_max_arm_counter_reg     s_wd_max_arm_counter_reg;
   tu_fpga_reg_iip03_watchdog_wd_min_window_time_reg     s_wd_min_window_time_reg;
   tu_fpga_reg_iip03_watchdog_wd_max_window_time_reg     s_wd_max_window_time_reg;
   tu_fpga_reg_iip03_watchdog_wd_hreset_delay_reg        s_wd_hreset_delay_reg;
}
ts_fpga_reg_iip03_watchdog_configuration;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_wd_timer_refresh_reg' */
typedef struct
{
   uint32_t s_refresh_counter : 16; /* Bits : 31:16 : Refresh counter value.This counter is increased by 1 when a valid refresh command is performed.                                                                                            */
   uint32_t s_wd_timer        : 16; /* Bits : 15:0  : Timer value.When {wd_state} = {disarmed} : kept at 0.When {wd_state} = {armed} : increased by one each {internal time base} period and reset when successful refresh command is performed. */
}
ts_fpga_reg_iip03_watchdog_wd_timer_refresh_reg_u_bit;

typedef union
{
   uint32_t                                              u_word;
   ts_fpga_reg_iip03_watchdog_wd_timer_refresh_reg_u_bit u_bit;
}
tu_fpga_reg_iip03_watchdog_wd_timer_refresh_reg;

/* Group of registers in 'iip03_watchdog' named 'monitoring' */
typedef struct
{
   uint32_t                                        s_wd_activity_check_out_reg;
   tu_fpga_reg_iip03_watchdog_wd_timer_refresh_reg s_wd_timer_refresh_reg;
}
ts_fpga_reg_iip03_watchdog_monitoring;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip03_watchdog' */

typedef struct
{
   ts_fpga_reg_iip03_watchdog_management    s_management_regs;
   ts_fpga_reg_iip03_watchdog_configuration s_configuration_regs;
   ts_fpga_reg_iip03_watchdog_monitoring    s_monitoring_regs;
}
ts_fpga_reg_iip03_watchdog;

#endif /* FPGA_REG_IIP03_WATCHDOG_H */
