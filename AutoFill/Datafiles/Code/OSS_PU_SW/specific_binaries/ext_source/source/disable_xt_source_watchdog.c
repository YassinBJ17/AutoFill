#include <intc.h>
#include <compiler.h>
#include <xt_source_watchdog.h>

 void disable_xt_source_watchdog(void) {     SWT_SR_t swt_sr = (SWT_SR_t) 0;     SWT_CR_t swt_cr = (SWT_CR_t) 0;     swt_sr = SWT_SR_WSC_SET(swt_sr, 0xC520);     COPY_WORD(SWT_0_SR, swt_sr);     swt_sr = SWT_SR_WSC_SET(swt_sr, 0xD928);     COPY_WORD(SWT_0_SR, swt_sr);     swt_cr = (0 | SWT_CR_MAP0(1) | SWT_CR_MAP1(1) | SWT_CR_MAP2(1) | SWT_CR_MAP3(1) | SWT_CR_MAP4(1) | SWT_CR_MAP5(1) | SWT_CR_MAP6(1) | SWT_CR_MAP7(1) | SWT_CR_SMD(0) | SWT_CR_WND(0) | SWT_CR_ITR(0) | SWT_CR_FRZ(1) | SWT_CR_STP(0) | SWT_CR_WEN(0));     COPY_WORD(SWT_0_CR, swt_cr); }
