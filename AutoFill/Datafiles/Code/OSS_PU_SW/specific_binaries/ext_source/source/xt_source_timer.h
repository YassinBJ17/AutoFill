/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#ifndef XT_SOURCE_TIMER_H_
#define XT_SOURCE_TIMER_H_

#include <kstdint_private.h>
#include <mpc5777m_xt-source_defs.h>

/**
 * STM2 is used for XT_source watchdog
 * - Channel 0 for CPU Core 0
 * - Channel 1 for CPU Core 1
 * - Channel 2 for CPU Core 2
 */

/**
 * enable_xt_source_timer
 * Enable the timer
 * @note Timer enabled but NO channel interrupt configured
 */
void enable_xt_source_timer(void);

/**
 * disable_xt_source_timer
 * Disable the timer
 */
void disable_xt_source_timer(void);

/**
 * configure_xt_source_timer
 * Configure the channel for specified CPU core
 * @param t_ast_uint32  CPU core id
 */
void configure_xt_source_timer(t_ast_uint32 core_id);

/**
 * start_xt_source_timer
 * @param t_ast_uint32  CPU core id
 * @param timer_value   next timeout in number of timer ticks
 * Enable specified CPU core channel and set its comparator the specified value
 */
void start_xt_source_timer(t_ast_uint32 core_id, t_ast_uint32 timer_value);

/**
 * restart_xt_source_timer
 * @param t_ast_uint32  CPU core id
 * @param timer_value   next timeout in number of timer ticks
 * Increase the comparator of the channel (for specified CPU core) by the specified value
 */
void restart_xt_source_timer(t_ast_uint32 core_id, t_ast_uint32 timer_value);

/**
 * stop_xt_source_timer
 * @param t_ast_uint32  CPU core id
 * Disable Channel for specified CPU core
 */
void stop_xt_source_timer(t_ast_uint32 core_id);

/**
 * reset_xt_source_timer
 * Reset the timer count value
 */
void reset_xt_source_timer(void);

/**
 * clear_xt_source_timer_interrupt
 * @param t_ast_uint32  CPU core id
 * Clear the timer interrupt flag for specified CPU core
 */
void clear_xt_source_timer_interrupt(t_ast_uint32 core_id);

#endif /* XT_SOURCE_TIMER_H_ */
