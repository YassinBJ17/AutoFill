#include <intc.h>
#include <compiler.h>
#include <xt_source_watchdog.h>

 void clear_xt_source_watchdog_interrupt(t_ast_uint32 core_id) {     const INTC_EOIR_t eoir_cleared = INTC_EOIR_EOI(0);     const SWT_IR_t swt_ir = SWT_IR_TIF(1);     COPY_WORD(SWT_0_IR, swt_ir);     COPY_WORD(INTC_0_EOIR(core_id), eoir_cleared); }
