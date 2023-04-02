#include "source_xt-source.h"
#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>
#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

 extern t_ast_uint32 phys_cpu_id(void);  typedef enum {     NONE = 0,     FPGA_FPGA,     FPGA_TIMER,     TIMER_TIMER,     TIMER_FPGA } t_xt_source_transition;
