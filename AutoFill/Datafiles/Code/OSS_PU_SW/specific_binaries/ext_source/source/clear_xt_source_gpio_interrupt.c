#include <intc.h>
#include <compiler.h>
#include <xt_source_gpio.h>

 void clear_xt_source_gpio_interrupt(t_ast_uint32 core_id) {     const INTC_EOIR_t eoir_cleared = INTC_EOIR_EOI(0);     SIUL2_DISR0 |= (0x1 << IRQ_NB);     COPY_WORD(INTC_0_EOIR(core_id), eoir_cleared); }
