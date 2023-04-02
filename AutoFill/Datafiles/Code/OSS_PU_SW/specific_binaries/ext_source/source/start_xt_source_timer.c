#include <intc.h>
#include <stm.h>
#include <compiler.h>
#include <xt_source_timer.h>

 void start_xt_source_timer(t_ast_uint32 core_id, t_ast_uint32 timer_value) {     STM_SET_COMPARATOR(2, core_id, timer_value);     STM_CHANNEL(2, core_id, STM_STATE_ENABLE); }
