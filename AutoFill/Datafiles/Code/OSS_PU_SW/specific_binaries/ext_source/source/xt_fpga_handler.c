#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 void xt_fpga_handler(void) {     const t_ast_uint32 cpuid = phys_cpu_id();     t_ast_uint32 next_date;     service_xt_source_watchdog();     clear_xt_source_gpio_interrupt(cpuid);     reset_xt_source_timer();     if (xt_source_last_wakeup[cpuid].first_value == 0)     {         raise_xt_source_error(ERR_XT_INVALID_WAKEUP_VALUE);     }     if (xt_source_next_wakeup[cpuid].first_value == 0)     {         raise_xt_source_error(ERR_XT_INVALID_WAKEUP_VALUE);     }     xt_source_current_date_in_FPGA_interval[cpuid] = 0;     next_date = xt_source_current_date_in_FPGA_interval[cpuid] + xt_source_next_wakeup[cpuid].first_value;     if (next_date > fpga_period_in_timer_ticks)     {         raise_xt_source_error(ERR_XT_MISSING_NEXT_FPGA_TICK);     }     else if (next_date == fpga_period_in_timer_ticks)     {         xt_source_current_transition[cpuid] = FPGA_FPGA;     }     else     {         start_xt_source_timer(cpuid, xt_source_next_wakeup[cpuid].first_value);         xt_source_current_transition[cpuid] = FPGA_TIMER;     }     SEND_TICK(); }
