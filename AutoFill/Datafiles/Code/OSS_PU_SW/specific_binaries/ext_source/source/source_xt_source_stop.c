#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 void source_xt_source_stop(void) {     const t_ast_uint32 cpuid = phys_cpu_id();     disable_xt_source_watchdog();     disable_xt_source_gpio();     clear_xt_source_gpio_interrupt(cpuid);     stop_xt_source_timer(cpuid);     disable_xt_source_timer(); }
