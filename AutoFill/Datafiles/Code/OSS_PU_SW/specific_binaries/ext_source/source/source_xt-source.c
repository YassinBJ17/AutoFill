/********** Copyright Krono-Safe S.A. 2012-2020, All rights reserved *********/

/*!
 * \file source_xt_source.c
 * \brief External source API source file
 *
 * This source file implements the mandatory API functions of
 * the external source in order to interact with k2.
 */

#include "source_xt-source.h"

#include "khelper.h"
#include "intc.h"
#include "sema42.h"
#include <stm.h>

#include <xt_source_gpio.h>
#include <xt_source_timer.h>
#include <xt_source_watchdog.h>
#include <xt_source_errors.h>

#define SEMA42_GATE_XT_SRC      SEMA42_GATE_12
#define SEMA42_GATE_XT_SRC_DONE SEMA42_GATE_13


extern t_ast_uint32 phys_cpu_id(void); /* function in kernel ELF */

/*!
 * Transition types: indicates the interrupt source for the current
 * and the upcoming source ticks.
 * The interrupt source may be:
 *  either the FPGA,
 *  or the timer.
 * Transitions:
 *  FPGA_FPGA: current tick was triggered by the FPGA and next one shall
 *      be triggered by the FPGA as well,
 *  FPGA_TIMER: current tick was triggered by the FPGA and next one
 *      shall be triggered by the timer,
 *  TIMER_TIMER: current tick was triggered by the timer and next one
 *      shall be triggered by the timer as well,
 *  TIMER_FGPA: current tick was triggered by the timer and next one
 *      shall be triggered by the FPGA.
 */
typedef enum
{
    NONE = 0,
    FPGA_FPGA,
    FPGA_TIMER,
    TIMER_TIMER,
    TIMER_FPGA
} t_xt_source_transition;

#define MAX_CORES   (3)

#define MIN_FPGA_PERIOD_IN_US       (250)       /*! 250us */
#define MAX_FPGA_PERIOD_IN_US       (1000000)   /*! 1s  */
/*! input FPGA period length in us
 */
#define INPUT_MINOR_FRAME_PERIOD_IN_250US   (*((t_ast_uint32 *) 0x4000fff8))
/*! input FPGA timeout in us
 */
#define INPUT_TIMEOUT_IN_10US               (*((t_ast_uint32 *) 0x4000fffc))
/*! FPGA period length in number of source timer ticks
 */
t_ast_uint32 fpga_period_in_us = 0;
t_ast_uint32 fpga_period_in_timer_ticks = 0;
t_ast_uint32 fpga_timeout_in_us = 0;
t_ast_uint32 watchdog_timeout_in_us = 0;

/* external source current transitions (per CPU core) */
static t_xt_source_transition xt_source_current_transition[MAX_CORES] = {NONE};
/* external source current date (in timer ticks) */
static t_ast_uint32 xt_source_current_date_in_FPGA_interval[MAX_CORES] = {0};
/* last wakeup date received (per CPU core) */
static struct bsp_source_timer_stm2 xt_source_last_wakeup[MAX_CORES] = {0};
/* next wakeup date received (per CPU core) */
static struct bsp_source_timer_stm2 xt_source_next_wakeup[MAX_CORES] = {0};


/*!
 * The macro DECLARE_SOURCE_INDEX *must* be called exactly once in
 * the C source files including the source header
 */
DECLARE_SOURCE_INDEX()

/*!
 * This function is called first and is called once, *before* launching the
 * scheduler and the application, while booting the platform. The source must
 * not trigger ticks either before nor after this function is called.
 *
 * \param [in] index of the external source in the application. Must be given as
 *             argument to the macro REGISTER_SOURCE_INDEX
 */
void source_xt_source_init(t_ast_size index)
{
    const t_ast_uint32 cpuid = phys_cpu_id();
    static t_ast_uint32 is_fpga_init_done = 0;

    REGISTER_SOURCE_INDEX(index);

    /* each core configure the FPGA one at a time */
    sema42_gate_lock(SEMA42_GATE_XT_SRC);

    /*! The following operations need only to be done once:
     *  - checking the FPGA period
     *  - computing the WD timeout
     *  - configuring the FPGA GPIO 
     */
    if (is_fpga_init_done == 0)
    {
        /* compute FPGA period in number of source timer ticks 
            *  - must be greater than 250 us and smaller than 1,000,000 us
            */
        fpga_period_in_us = INPUT_MINOR_FRAME_PERIOD_IN_250US * 250;
        if ((fpga_period_in_us < MIN_FPGA_PERIOD_IN_US) 
                || (fpga_period_in_us > MAX_FPGA_PERIOD_IN_US))
        {
            raise_xt_source_error(ERR_XT_INVALID_FPGA_PERIOD);
        }
        fpga_period_in_timer_ticks = (XT_SOURCE_TIMER_FREQUENCY / 1000000) * fpga_period_in_us;
        /*! compute watchdog timeout in us to detect jitter greater than
            * the specifed timeout
            *  - WD timeout must be greater than 0
            *  - WD timeout must be smaller than the FPGA period
            *  - WD timeout > FPGA_PERIOD + TIMEOUT
            */
        if ((INPUT_TIMEOUT_IN_10US == 0) 
                || (INPUT_TIMEOUT_IN_10US >= fpga_period_in_us))
        {
            raise_xt_source_error(ERR_XT_INVALID_FPGA_TIMEOUT);
        }
        fpga_timeout_in_us = INPUT_TIMEOUT_IN_10US * 10;
        watchdog_timeout_in_us = fpga_period_in_us + fpga_timeout_in_us;


        configure_xt_source_gpio();

        is_fpga_init_done = 1;
    }

    configure_xt_source_gpio_interrupt(cpuid);

    sema42_gate_unlock(SEMA42_GATE_XT_SRC);

    /* enable STM2 channel interrupt for current core with highest priority */
    configure_xt_source_timer(cpuid);

}

/*!
 * Source start routine
 * This function is called when all the cores that use the Source are ready to
 * start, and after source initialization. After this call, the Source can start
 * the generation of ticks.
 *
 * \param[in] length       Source ticks to program
 * \param[in] first_wakeup timer ticks to program (NULL when no timer)
 * \param[in] next_wakeup  next timer ticks to program (NULL when no timer)
 *
 * \warning `first_wakeup` and `next_wakeup` should be cast in
 *          `struct bsp_source_timer_stm2`
 */
void source_xt_source_start(t_ast_source_duration length,
                                      const void *first_wakeup,
                                      const void *next_wakeup)
{
    const t_ast_uint32 cpuid = phys_cpu_id();
    t_ast_boolean semaphore_locked = sema42_gate_trylock(SEMA42_GATE_XT_SRC);
    const struct bsp_source_timer_stm2 *current_core_wakeup = first_wakeup;
    const struct bsp_source_timer_stm2 *current_core_next_wakeup = next_wakeup;

    UNUSED_ARG(length);

    if (xt_source_current_date_in_FPGA_interval[cpuid] != 0)
    {
        raise_xt_source_error(ERR_XT_UNKNOWN);
    }
    else if (current_core_wakeup->first_value != fpga_period_in_timer_ticks)
    {
        raise_xt_source_error(ERR_XT_FIRST_TICK_IS_NOT_FPGA);
    }

    xt_source_last_wakeup[cpuid] = *current_core_wakeup;
    xt_source_next_wakeup[cpuid] = *current_core_next_wakeup;

    /* the first core to reach source_start performs the starting steps */
    if (semaphore_locked)
    {
        /* enable FPGA */
        enable_xt_source_gpio();

        /* enable STM2 counter */
        reset_xt_source_timer();
        enable_xt_source_timer();
        
        /* enable SWT */
        enable_xt_source_watchdog(watchdog_timeout_in_us);

        sema42_gate_lock(SEMA42_GATE_XT_SRC_DONE); /* signal other cores that the job is done */
    }
    /* the other cores wait till the first core has finished performing the starting steps */
    else
    {
        do
        {
            semaphore_locked = sema42_gate_islocked(SEMA42_GATE_XT_SRC_DONE);
        } while (!semaphore_locked);
    }

}

/*!
 * When this function is called, the Source shall call `SEND_TICK` when `length`
 * Source ticks will have elapsed. All intermediate Source ticks shall be
 * skipped. Refer to the "External Sources reference Guide" to read more about
 * how to use the parameters of this function.
 *
 * \param[in] length      Source ticks to program
 * \param[in] wakeup      Timer ticks to program
 * \param[in] next_wakeup Next timer ticks to program
 *
 * \warning `first_wakeup` and `next_wakeup` should be cast in
 *          `struct bsp_source_timer_stm2`
 */
void source_xt_source_reload(t_ast_source_duration length,
                                      const void *wakeup,
                                      const void *next_wakeup)
{
    const t_ast_uint32 cpuid = phys_cpu_id();
    const struct bsp_source_timer_stm2 *current_core_wakeup = wakeup;
    const struct bsp_source_timer_stm2 *current_core_next_wakeup = next_wakeup;

    UNUSED_ARG(length);

    if (xt_source_current_transition[cpuid] == NONE)
    {
        raise_xt_source_error(ERR_XT_INVALID_TRANSITION);
    }

    switch (xt_source_current_transition[cpuid])
    {
        case FPGA_FPGA:
            /* STM2 timer does not have to be started -> wait for the next FPGA tick */
            break;
        case FPGA_TIMER:
            /* STM2 timer already started in FPGA handler */
            break;
        case TIMER_TIMER:
            /* re-load STM2 timer comparator */
            restart_xt_source_timer(cpuid, current_core_wakeup->first_value);
            break;
        case TIMER_FPGA:
            /* disable the STM2 timer and wait for the next FPGA tick */
            stop_xt_source_timer(cpuid);
            break;
        default:
            raise_xt_source_error(ERR_XT_INVALID_TRANSITION);
            break;
    }

    xt_source_current_transition[cpuid] = NONE;

    xt_source_last_wakeup[cpuid] = *current_core_wakeup;
    xt_source_next_wakeup[cpuid] = *current_core_next_wakeup;

}

/*!
 * This function is called when the scheduler whants to stop the source
 * generation of tick.
 * The call to this function may be followed by a later call to
 * source_xt_source_start() in order to restart the source.
 *
 * \note This function will be called if the system raises a fatal error
 */
void source_xt_source_stop(void)
{
    const t_ast_uint32 cpuid = phys_cpu_id();

    /* disable SWT */
    disable_xt_source_watchdog();
    
    /* disable FPGA */
    disable_xt_source_gpio();
    clear_xt_source_gpio_interrupt(cpuid);

    /* stop STM2 timer */
    stop_xt_source_timer(cpuid);
    disable_xt_source_timer();
}

/*!
 * Handlers implementation
 */

/*!
 * xt_fpga_handler
 */
void xt_fpga_handler(void)
{
    const t_ast_uint32 cpuid = phys_cpu_id();
    t_ast_uint32 next_date;

    /* SWT servicing operation */
    service_xt_source_watchdog();

    /* clear FPGA interrupt flag for local CPU core */
    clear_xt_source_gpio_interrupt(cpuid);

    /* reset STM2 counter because we are at the beginning
     * of a new FPGA interval
     */
    reset_xt_source_timer();

    /* check the values of last_wakeup and next_wakeup that have
     * been updated in start/reload function
     *  => null values should not occur */
    if (xt_source_last_wakeup[cpuid].first_value == 0)
    {
        raise_xt_source_error(ERR_XT_INVALID_WAKEUP_VALUE);
    }
    if (xt_source_next_wakeup[cpuid].first_value == 0)
    {
        raise_xt_source_error(ERR_XT_INVALID_WAKEUP_VALUE);
    }

    /* new FPGA interval -> reset current date in interval */
    xt_source_current_date_in_FPGA_interval[cpuid] = 0;

    /* compute next date that has been requested by the RTK in
     * the start/reload function */
    next_date = xt_source_current_date_in_FPGA_interval[cpuid] + xt_source_next_wakeup[cpuid].first_value;

    /* if next_date is greater than the FPGA period, then an
     * error must be raised */
    if (next_date > fpga_period_in_timer_ticks)
    {
        raise_xt_source_error(ERR_XT_MISSING_NEXT_FPGA_TICK);
    }
    /* otherwise, if the next requested date corresponds to an FPGA
     * tick, then the timer does not need to be armed*/
    else if (next_date == fpga_period_in_timer_ticks)
    {
        xt_source_current_transition[cpuid] = FPGA_FPGA;
    }
    /* eventually, if the next requested date corresponds to a tick
     * with an FPGA intervall, then the time needs to be started with
     * the corresponding value */
    else
    {
        /* load STM2 timer comparator and enable channel */
        start_xt_source_timer(cpuid, xt_source_next_wakeup[cpuid].first_value);
        xt_source_current_transition[cpuid] = FPGA_TIMER;
    }

    SEND_TICK();
}

/*!
 * xt_timer_handler
 */
void xt_timer_handler(void)
{
    const t_ast_uint32 cpuid = phys_cpu_id();
    t_ast_uint32 next_date;

    /* clear STM2 timer interrupt flag */
    clear_xt_source_timer_interrupt(cpuid);

    /* check the values of last_wakeup and next_wakeup that have
     * been updated in start/reload function
     *  => null values should not occur */
    if (xt_source_last_wakeup[cpuid].first_value == 0)
    {
        raise_xt_source_error(ERR_XT_INVALID_WAKEUP_VALUE);
    }
    if (xt_source_next_wakeup[cpuid].first_value == 0)
    {
        raise_xt_source_error(ERR_XT_INVALID_WAKEUP_VALUE);
    }

    /* update current date */
    xt_source_current_date_in_FPGA_interval[cpuid] += xt_source_last_wakeup[cpuid].first_value;

    /* compute next date that has been requested by the RTK in
     * the reload function */
    next_date = xt_source_current_date_in_FPGA_interval[cpuid] + xt_source_next_wakeup[cpuid].first_value;

    /* if next_date is greater than the FPGA period, then an
     * error must be raised */
    if (next_date > fpga_period_in_timer_ticks)
    {
        raise_xt_source_error(ERR_XT_MISSING_NEXT_FPGA_TICK);
    }
    /* otherwise, if the next requested date corresponds to an FPGA
     * tick, then the TIMER_FPGA transition is set
     *  => this transition will be checked in the reload function
     *  called by the RTK after receiving SEND_TICK to disable the timer */
    else if (next_date == fpga_period_in_timer_ticks)
    {
        xt_source_current_transition[cpuid] = TIMER_FPGA;
    }
    /* eventually, if the next requested date corresponds to a tick
     * with an FPGA intervall, then the TIMER_TIMER transition is set
     *  => this transition will be checked in the reload function
     *  called by the RTK after receiving SEND_TICK to reload the timer */
    else
    {
        xt_source_current_transition[cpuid] = TIMER_TIMER;
    }

    SEND_TICK();
}

/*!
 * xt_watchdog_handler
 */
void xt_watchdog_handler(void)
{
    const t_ast_uint32 cpuid = phys_cpu_id();

    /* disable watchdog to avoid 2 interrupt leading to board reset */
    clear_xt_source_watchdog_interrupt(cpuid);
    disable_xt_source_watchdog(); 

    raise_xt_source_error(ERR_XT_WATCHDOG_TIMEOUT);
}

