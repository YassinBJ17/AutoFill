#include <intc.h>
#include <stm.h>
#include <compiler.h>
#include <xt_source_timer.h>

 void reset_xt_source_timer(void) {     STM_TIMER(2, STM_STATE_DISABLE);         STM_SET_COUNTER(2, 0);                   STM_TIMER(2, STM_STATE_ENABLE);      }
