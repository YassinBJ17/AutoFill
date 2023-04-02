#include <intc.h>
#include <stm.h>
#include <compiler.h>
#include <xt_source_timer.h>

 void restart_xt_source_timer(t_ast_uint32 core_id, t_ast_uint32 timer_value) {     t_ast_uint32 armed_source;     STM_GET_COMPARATOR(2, core_id, armed_source);     STM_SET_COMPARATOR(2, core_id, armed_source + timer_value); }
