#include <intc.h>
#include <compiler.h>
#include <xt_source_gpio.h>

 void configure_xt_source_gpio(void) {     const SIUL2_MSCR_IO_t mscr = (0 | SIUL2_MSCR_IO_OERC(1) | SIUL2_MSCR_IO_ILS(1) | SIUL2_MSCR_IO_IBE(1) | SIUL2_MSCR_IO_HYS(1));     t_ast_uint32 mask = 0;     SIUL2_DIRER0_t direr0_backup = SIUL2_DIRER0;     COPY_WORD(SIUL2_DIRER0, mask);     SIUL2_IREER0 |= (0x1 << IRQ_NB);     SIUL2_IFEER0 &= ~(0x1 << IRQ_NB);     COPY_WORD(SIUL2_MSCR_IO(0), mscr);     SIUL2_DIRSR0 &= ~(0x1 << IRQ_NB);     SIUL2_DISR0 |= (0x1 << IRQ_NB);     direr0_backup &= ~(0x1 << IRQ_NB);     COPY_WORD(SIUL2_DIRER0, direr0_backup); }
