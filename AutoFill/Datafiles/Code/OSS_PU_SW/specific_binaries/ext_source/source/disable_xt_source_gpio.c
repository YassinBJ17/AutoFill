#include <intc.h>
#include <compiler.h>
#include <xt_source_gpio.h>

 void disable_xt_source_gpio(void) {     SIUL2_IREER0 &= ~(0x1 << IRQ_NB);     SIUL2_DIRER0 &= ~(0x1 << IRQ_NB); }
