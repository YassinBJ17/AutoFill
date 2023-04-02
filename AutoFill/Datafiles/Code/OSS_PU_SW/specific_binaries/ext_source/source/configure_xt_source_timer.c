#include <intc.h>
#include <stm.h>
#include <compiler.h>
#include <xt_source_timer.h>

 void configure_xt_source_timer(t_ast_uint32 core_id) {     const STM_CR_t cr = (0 | STM_CR_CPS(STM2_PRESCALER - 1) | STM_CR_FRZ(1) | STM_CR_TEN(0));     STM_SET_COUNTER(2, 0);           COPY_WORD(STM_2_CR, cr);         intc_irq_enable(INTC_STM(2, core_id), INTC_PRIORITY_MAX);     STM_CHANNEL(2, core_id, STM_STATE_DISABLE);     STM_SET_COMPARATOR(2, core_id, TIMER_MAX_VALUE); }
