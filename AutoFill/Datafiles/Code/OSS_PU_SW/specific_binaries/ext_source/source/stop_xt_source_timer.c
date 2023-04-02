#include <intc.h>
#include <stm.h>
#include <compiler.h>
#include <xt_source_timer.h>

 void stop_xt_source_timer(t_ast_uint32 core_id) {     STM_CHANNEL(2, core_id, STM_STATE_DISABLE); }
