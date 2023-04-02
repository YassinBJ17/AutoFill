#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 #define INPUT_TIMEOUT_IN_10US               (*((t_ast_uint32 *) 0x4000fffc)) t_ast_uint32 fpga_period_in_us = 0; t_ast_uint32 fpga_period_in_timer_ticks = 0; t_ast_uint32 fpga_timeout_in_us = 0; t_ast_uint32 watchdog_timeout_in_us = 0; static t_xt_source_transition xt_source_current_transition[MAX_CORES] = {NONE}; static t_ast_uint32 xt_source_current_date_in_FPGA_interval[MAX_CORES] = {0}; static struct bsp_source_timer_stm2 xt_source_last_wakeup[MAX_CORES] = {0}; static struct bsp_source_timer_stm2 xt_source_next_wakeup[MAX_CORES] = {0};
