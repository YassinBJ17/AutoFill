#include <intc.h>
#include <compiler.h>
#include <xt_source_gpio.h>

 void configure_xt_source_gpio_interrupt(t_ast_uint32 core_id) {     INTC_PSR_t psr = (INTC_PSR_t) 0;     COPY_HALF(psr, INTC_0_PSR(INTC_EXTERNAL_INTERRUPT_NB));     psr = (INTC_PSR_t) INTC_PSR_PRIN_SET(psr, INTC_PRIORITY_MAX);     switch (core_id)     {         case 0:             psr = (INTC_PSR_t) INTC_PSR_PRC_SELN0_SET(psr, 1);             break;         case 1:             psr = (INTC_PSR_t) INTC_PSR_PRC_SELN1_SET(psr, 1);             break;         case 2:             psr = (INTC_PSR_t) INTC_PSR_PRC_SELN2_SET(psr, 1);             break;         case 3:             psr = (INTC_PSR_t) INTC_PSR_PRC_SELN3_SET(psr, 1);             break;         default:             break;     }     COPY_HALF(INTC_0_PSR(INTC_EXTERNAL_INTERRUPT_NB), psr); }
