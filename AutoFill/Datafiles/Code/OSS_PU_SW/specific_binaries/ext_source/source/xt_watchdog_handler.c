#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 void xt_watchdog_handler(void) {     const t_ast_uint32 cpuid = phys_cpu_id();     clear_xt_source_watchdog_interrupt(cpuid);     disable_xt_source_watchdog();      raise_xt_source_error(ERR_XT_WATCHDOG_TIMEOUT); }
