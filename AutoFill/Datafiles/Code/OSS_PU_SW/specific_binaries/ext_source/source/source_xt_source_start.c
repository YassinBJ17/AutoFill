#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 void source_xt_source_start(t_ast_source_duration length,                                       const void *first_wakeup,                                       const void *next_wakeup) {     const t_ast_uint32 cpuid = phys_cpu_id();     t_ast_boolean semaphore_locked = sema42_gate_trylock(SEMA42_GATE_XT_SRC);     const struct bsp_source_timer_stm2 *current_core_wakeup = first_wakeup;     const struct bsp_source_timer_stm2 *current_core_next_wakeup = next_wakeup;     UNUSED_ARG(length);     if (xt_source_current_date_in_FPGA_interval[cpuid] != 0)     {         raise_xt_source_error(ERR_XT_UNKNOWN);     }     else if (current_core_wakeup->first_value != fpga_period_in_timer_ticks)     {         raise_xt_source_error(ERR_XT_FIRST_TICK_IS_NOT_FPGA);     }     xt_source_last_wakeup[cpuid] = *current_core_wakeup;     xt_source_next_wakeup[cpuid] = *current_core_next_wakeup;     if (semaphore_locked)     {         enable_xt_source_gpio();         reset_xt_source_timer();         enable_xt_source_timer();         enable_xt_source_watchdog(watchdog_timeout_in_us);         sema42_gate_lock(SEMA42_GATE_XT_SRC_DONE);      }     else     {         do         {             semaphore_locked = sema42_gate_islocked(SEMA42_GATE_XT_SRC_DONE);         } while (!semaphore_locked);     } }
