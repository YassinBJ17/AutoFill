#include <intc.h>
#include <compiler.h>
#include <xt_source_watchdog.h>

 void service_xt_source_watchdog(void) {     SWT_SR_t swt_sr = (SWT_SR_t) 0;     swt_sr = SWT_SR_WSC_SET(swt_sr, 0xa602);     COPY_WORD(SWT_0_SR, swt_sr);     swt_sr = SWT_SR_WSC_SET(swt_sr, 0xb480);     COPY_WORD(SWT_0_SR, swt_sr); }
