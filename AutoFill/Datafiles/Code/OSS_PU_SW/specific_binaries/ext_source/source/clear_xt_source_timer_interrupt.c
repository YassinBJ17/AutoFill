#include <intc.h>
#include <stm.h>
#include <compiler.h>
#include <xt_source_timer.h>

 void clear_xt_source_timer_interrupt(t_ast_uint32 core_id) {     const INTC_EOIR_t eoir_cleared = INTC_EOIR_EOI(0);     STM_CLEAR_PENDING(2, core_id);     COPY_WORD(INTC_0_EOIR(core_id), eoir_cleared); }
