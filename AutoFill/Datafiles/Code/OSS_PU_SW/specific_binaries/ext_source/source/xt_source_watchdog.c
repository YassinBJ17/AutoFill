/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#include <intc.h>
#include <compiler.h>

#include <xt_source_watchdog.h>

/**
 * enable_xt_source_watchdog
 * @param  watchdog_timeout Watchdog timeout in us
 * Enable the watchdog with the timeout value and start it
 * @note The SWT IRQ is set only for the local CPU core
 */
void enable_xt_source_watchdog(t_ast_uint32 watchdog_timeout_in_us)
{
    SWT_SR_t swt_sr = (SWT_SR_t) 0;
    SWT_CR_t swt_cr = (SWT_CR_t) 0;
    t_ast_uint32 watchdog_timeout = 0;

    /* unlock soft lock */
    swt_sr = SWT_SR_WSC_SET(swt_sr, 0xC520);
    COPY_WORD(SWT_0_SR, swt_sr);
    swt_sr = SWT_SR_WSC_SET(swt_sr, 0xD928);
    COPY_WORD(SWT_0_SR, swt_sr);

    /* enable SWT 0 interrupt for local CPU core in Interrupt Controller */
    intc_irq_enable(INTC_SWT_0_IR, INTC_PRIORITY_MAX);

    /*! compute watchdog timeout in SWT clock ticks
     *  - WD clock @16MHz
     */
    watchdog_timeout = watchdog_timeout_in_us * 16;

    /* set SWT 0 timeout to watchdog_timeout value */
    COPY_WORD(SWT_0_TO, watchdog_timeout);

    /* configure SWT 0:
     * - fixed service mode
     * - regular mode (no windowed mode)
     * - generate an interrupt on a initial time-out and reset on a second consecutive time-out
     * - stops on debug
     * and enable it
     */
    swt_cr = (0 | SWT_CR_MAP0(1) | SWT_CR_MAP1(1) | SWT_CR_MAP2(1) | SWT_CR_MAP3(1) | SWT_CR_MAP4(1) | SWT_CR_MAP5(1) | SWT_CR_MAP6(1) | SWT_CR_MAP7(1) | SWT_CR_SMD(0) | SWT_CR_WND(0) | SWT_CR_ITR(1) | SWT_CR_FRZ(1) | SWT_CR_STP(0) | SWT_CR_WEN(1));
    COPY_WORD(SWT_0_CR, swt_cr);
}

/**
 * disable_xt_source_watchdog
 * Disable the watchdog
 */
void disable_xt_source_watchdog(void)
{
    SWT_SR_t swt_sr = (SWT_SR_t) 0;
    SWT_CR_t swt_cr = (SWT_CR_t) 0;

    /* unlock SWT 0 soft lock */
    swt_sr = SWT_SR_WSC_SET(swt_sr, 0xC520);
    COPY_WORD(SWT_0_SR, swt_sr);
    swt_sr = SWT_SR_WSC_SET(swt_sr, 0xD928);
    COPY_WORD(SWT_0_SR, swt_sr);

    /* disable SWT 0 */
    swt_cr = (0 | SWT_CR_MAP0(1) | SWT_CR_MAP1(1) | SWT_CR_MAP2(1) | SWT_CR_MAP3(1) | SWT_CR_MAP4(1) | SWT_CR_MAP5(1) | SWT_CR_MAP6(1) | SWT_CR_MAP7(1) | SWT_CR_SMD(0) | SWT_CR_WND(0) | SWT_CR_ITR(0) | SWT_CR_FRZ(1) | SWT_CR_STP(0) | SWT_CR_WEN(0));
    COPY_WORD(SWT_0_CR, swt_cr);
}

/**
 * service_xt_source_watchdog
 * Service the watchdog
 */
void service_xt_source_watchdog(void)
{
    SWT_SR_t swt_sr = (SWT_SR_t) 0;

    /* service SWT 0 */
    swt_sr = SWT_SR_WSC_SET(swt_sr, 0xa602);
    COPY_WORD(SWT_0_SR, swt_sr);
    swt_sr = SWT_SR_WSC_SET(swt_sr, 0xb480);
    COPY_WORD(SWT_0_SR, swt_sr);
}

/**
 * clear_xt_source_watchdog_interrupt
 * Clear the watchdog interrupt flag for specified CPU core
 * @param t_ast_uint32  CPU core id
 */
void clear_xt_source_watchdog_interrupt(t_ast_uint32 core_id)
{
    const INTC_EOIR_t eoir_cleared = INTC_EOIR_EOI(0);
    const SWT_IR_t swt_ir = SWT_IR_TIF(1);

    /* clear the interrupt flag for SWT 0 */
    COPY_WORD(SWT_0_IR, swt_ir);

    /* signal the end of interrupt to the Interrupt Controller (for local CPU core) */
    COPY_WORD(INTC_0_EOIR(core_id), eoir_cleared);
}

