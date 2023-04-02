#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 void source_xt_source_reload(t_ast_source_duration length,                                       const void *wakeup,                                       const void *next_wakeup) {     const t_ast_uint32 cpuid = phys_cpu_id();     const struct bsp_source_timer_stm2 *current_core_wakeup = wakeup;     const struct bsp_source_timer_stm2 *current_core_next_wakeup = next_wakeup;     UNUSED_ARG(length);     if (xt_source_current_transition[cpuid] == NONE)     {         raise_xt_source_error(ERR_XT_INVALID_TRANSITION);     }     switch (xt_source_current_transition[cpuid])     {         case FPGA_FPGA:             break;         case FPGA_TIMER:             break;         case TIMER_TIMER:             restart_xt_source_timer(cpuid, current_core_wakeup->first_value);             break;         case TIMER_FPGA:             stop_xt_source_timer(cpuid);             break;         default:             raise_xt_source_error(ERR_XT_INVALID_TRANSITION);             break;     }     xt_source_current_transition[cpuid] = NONE;     xt_source_last_wakeup[cpuid] = *current_core_wakeup;     xt_source_next_wakeup[cpuid] = *current_core_next_wakeup; }
