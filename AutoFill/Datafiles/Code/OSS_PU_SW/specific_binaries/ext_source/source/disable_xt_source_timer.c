#include <intc.h>
#include <stm.h>
#include <compiler.h>
#include <xt_source_timer.h>

 void disable_xt_source_timer(void) {     STM_TIMER(2, STM_STATE_DISABLE); }
