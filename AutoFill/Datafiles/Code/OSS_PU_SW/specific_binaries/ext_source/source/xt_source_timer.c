/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#include <intc.h>
#include <stm.h>
#include <compiler.h>

#include <xt_source_timer.h>


/**
 * enable_xt_source_timer
 * Enable the timer
 * @note Timer enabled but NO channel interrupt configured
 */
void enable_xt_source_timer(void)
{
    STM_TIMER(2, STM_STATE_ENABLE); /**< start timer counter */
}

/**
 * disable_xt_source_timer
 * Disable the timer
 */
void disable_xt_source_timer(void)
{
    STM_TIMER(2, STM_STATE_DISABLE);
}

/**
 * configure_xt_source_timer
 * Configure the channel for specified CPU core
 * @param t_ast_uint32  CPU core id
 */
void configure_xt_source_timer(t_ast_uint32 core_id)
{
    /* set timer prescaler, freeze on debug */
    const STM_CR_t cr = (0 | STM_CR_CPS(STM2_PRESCALER - 1) | STM_CR_FRZ(1) | STM_CR_TEN(0));

    STM_SET_COUNTER(2, 0);      /**< set timer count value to 0 */
    COPY_WORD(STM_2_CR, cr);    /**< set timer configuration */

    intc_irq_enable(INTC_STM(2, core_id), INTC_PRIORITY_MAX);
    STM_CHANNEL(2, core_id, STM_STATE_DISABLE);
    STM_SET_COMPARATOR(2, core_id, TIMER_MAX_VALUE);
}

/**
 * start_xt_source_timer
 * @param t_ast_uint32  CPU core id
 * @param timer_value   next timeout in number of timer ticks
 * Enable specified CPU core channel and set its comparator the specified value
 */
void start_xt_source_timer(t_ast_uint32 core_id, t_ast_uint32 timer_value)
{
    STM_SET_COMPARATOR(2, core_id, timer_value);
    STM_CHANNEL(2, core_id, STM_STATE_ENABLE);
}

/**
 * restart_xt_source_timer
 * @param t_ast_uint32  CPU core id
 * @param timer_value   next timeout in number of timer ticks
 * Increase the comparator of the channel (for specified CPU core) by the specified value
 */
void restart_xt_source_timer(t_ast_uint32 core_id, t_ast_uint32 timer_value)
{
    t_ast_uint32 armed_source;

    STM_GET_COMPARATOR(2, core_id, armed_source);
    STM_SET_COMPARATOR(2, core_id, armed_source + timer_value);
}

/**
 * stop_xt_source_timer
 * @param t_ast_uint32  CPU core id
 * Disable Channel for specified CPU core
 */
void stop_xt_source_timer(t_ast_uint32 core_id)
{
    STM_CHANNEL(2, core_id, STM_STATE_DISABLE);
}

/**
 * reset_xt_source_timer
 * Reset the timer count value
 */
void reset_xt_source_timer(void)
{
    STM_TIMER(2, STM_STATE_DISABLE);    /**< disable STM2 timer */
    STM_SET_COUNTER(2, 0);              /**< set STM2 timer count value to 0 */
    STM_TIMER(2, STM_STATE_ENABLE);     /**< enable STM2 timer */
}

/**
 * clear_xt_source_timer_interrupt
 * @param t_ast_uint32  CPU core id
 * Clear the timer interrupt flag for specified CPU core
 */
void clear_xt_source_timer_interrupt(t_ast_uint32 core_id)
{
    const INTC_EOIR_t eoir_cleared = INTC_EOIR_EOI(0);

    /* clear the interrupt flag for STM2 timer channel associated to local CPU core */
    STM_CLEAR_PENDING(2, core_id);

    /* signal the end of interrupt to the Interrupt Controller (for local CPU core) */
    COPY_WORD(INTC_0_EOIR(core_id), eoir_cleared);
}

