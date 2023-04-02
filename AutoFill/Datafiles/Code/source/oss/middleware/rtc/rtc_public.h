/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef RTC_PUBLIC_H
#define RTC_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Maximum value of RTC counter */
#define RTC_COUNTER_MAX (uint32_t)0xFFFFFFFF

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Elapsed RTC counter */
extern uint32_t rtc_counter;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0090 */
/* Initialize the counter of elapsed RTC */
extern void rtc_init(void);

/* Implements REQ_FADEX_OS_SRD-SCHED-0090 */
/* Increment the counter of elapsed RTC */
extern void rtc_count(void);

#endif /* RTC_PUBLIC_H  */
