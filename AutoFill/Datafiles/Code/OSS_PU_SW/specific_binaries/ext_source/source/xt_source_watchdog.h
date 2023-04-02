/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#ifndef XT_SOURCE_WATCHDOG_H_
#define XT_SOURCE_WATCHDOG_H_

#include <kstdint.h>
#include <kstdint_private.h>
#include <mpc5777m_xt-source_defs.h>

/**
 * SWT 0 is used for XT_source watchdog
 */

/**
 * enable_xt_source_watchdog
 * @param  watchdog_timeout Watchdog timeout in us
 * Enable the watchdog with the timeout value and start it
 * @note The SWT IRQ is set only for the local CPU core
 */
void enable_xt_source_watchdog(t_ast_uint32 watchdog_timeout_in_us);

/**
 * disable_xt_source_watchdog
 * Disable the watchdog
 */
void disable_xt_source_watchdog(void);

/**
 * service_xt_source_watchdog
 * Service the watchdog
 */
void service_xt_source_watchdog(void);

/**
 * clear_xt_source_watchdog_interrupt
 * Clear the watchdog interrupt flag for specified CPU core
 * @param t_ast_uint32  CPU core id
 */
void clear_xt_source_watchdog_interrupt(t_ast_uint32 core_id);

#endif /* XT_SOURCE_WATCHDOG_H_*/
