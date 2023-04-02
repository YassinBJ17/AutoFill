#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 void source_xt_source_init(t_ast_size index) {     const t_ast_uint32 cpuid = phys_cpu_id();     static t_ast_uint32 is_fpga_init_done = 0;     REGISTER_SOURCE_INDEX(index);     sema42_gate_lock(SEMA42_GATE_XT_SRC);     if (is_fpga_init_done == 0)     {         fpga_period_in_us = INPUT_MINOR_FRAME_PERIOD_IN_250US * 250;         if ((fpga_period_in_us < MIN_FPGA_PERIOD_IN_US)                  || (fpga_period_in_us > MAX_FPGA_PERIOD_IN_US))         {             raise_xt_source_error(ERR_XT_INVALID_FPGA_PERIOD);         }         fpga_period_in_timer_ticks = (XT_SOURCE_TIMER_FREQUENCY / 1000000) * fpga_period_in_us;         if ((INPUT_TIMEOUT_IN_10US == 0)                  || (INPUT_TIMEOUT_IN_10US >= fpga_period_in_us))         {             raise_xt_source_error(ERR_XT_INVALID_FPGA_TIMEOUT);         }         fpga_timeout_in_us = INPUT_TIMEOUT_IN_10US * 10;         watchdog_timeout_in_us = fpga_period_in_us + fpga_timeout_in_us;         configure_xt_source_gpio();         is_fpga_init_done = 1;     }     configure_xt_source_gpio_interrupt(cpuid);     sema42_gate_unlock(SEMA42_GATE_XT_SRC);     configure_xt_source_timer(cpuid); }
