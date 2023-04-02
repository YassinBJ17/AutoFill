/********** Copyright Krono-Safe S.A. 2012-2019, All rights reserved *********/
/********************* THIS IS A GENERATED FILE ******************************/

/*!
 * \file source_xt_source.h
 * \brief External source API header
 *
 * This auto-generated header declares the mandatory API functions to be
 * implemented by the external source in order to interact with k2. It also
 * provides a `SEND_TICK()` macro to be used by the source developer to trigger
 * a source tick to k2.
 */

#ifndef AST_SOURCE_XT_SOURCE_H_
#define AST_SOURCE_XT_SOURCE_H_ 1

#include <kstdint_private.h>
#include <kcompiler.h>
#include <hal.h>

/* k2 internal API */
extern void hal_alarm_raise_error (t_ast_size source_index);

/** internal index of the source */
extern t_ast_size _xt_source_index_psy;
/**
 * Description of the timer stm2 wired to the time-triggered
 * source xt_source.
 */
struct bsp_source_timer_stm2
{
  t_ast_uint32 first_value; /**< First value to count to. */
};

/*!
 * \def SEND_TICK()
 *
 * Tick-sending macro; must be called by the source in order to generate a
 * scheduling tick.
 */
/* k2 internal API */
extern void hal_alarm_optimized_source_tick (t_ast_size source_index,
                                             t_ast_size core_id);

#define SEND_TICK()                                           \
  hal_alarm_optimized_source_tick(_xt_source_index_psy, CPU_ID());

#define DECLARE_SOURCE_INDEX() t_ast_size _xt_source_index_psy;

#define REGISTER_SOURCE_INDEX(idx_) _xt_source_index_psy = (idx_);

#define AST_RAISE_ERROR()                                     \
  hal_alarm_raise_error(_xt_source_index_psy);

/******************************************************************************/
/* SOURCE API TO BE USED BY K2                                                */
/******************************************************************************/

/* 1. The macro DECLARE_SOURCE_INDEX *must* be called in exactly one of
 *    the C source files including this header
 * 2. The following functions *must* be implemented by the source developer
 */

/*!
 * This function is called first and is called once, *before* launching the
 * scheduler and the application, while booting the platform. The source must
 * not trigger ticks either before nor after this function is called.
 *
 * \param [in] index of the external source in the application. Must be given as
 *             argument to the macro REGISTER_SOURCE_INDEX
 */
void source_xt_source_init(t_ast_size index);

/*!
 * Source start routine
 * This function is called when all the cores that uses the source are ready to
 * start, and after source initialization. After this call the source can start
 * the generation of tick.
 *
 * \param[in] length       source ticks to program
 * \param[in] first_wakeup timer ticks to program (NULL when no timer)
 * \param[in] next_wakeup  next timer ticks to program (NULL when no timer)
 *
 * \warning
 * first_wakeup and next_wakeup should be cast in the right type structure.
 * You can find the declarations of the structures in the header source_xt_source_runtime.h
 */
void source_xt_source_start(t_ast_source_duration length,
                                      const void *first_wakeup,
                                      const void *next_wakeup);

/*!
 * This function is called when the scheduler whants to stop the source
 * generation of tick.
 * The call to this function may be followed by a later call to
 * source_xt_source_start() in order to restart the source.
 *
 * \note This function will be called if the system raises a fatal error
 */
void source_xt_source_stop(void);

/*!
 * When this function is called, the source shall only trigger the next
 * `duration`-th tick to the alarm, and skip all intermediate ticks. For
 * example, if the source is a hardware timer, then the comparator that triggers
 * the interrupt should be set to the current counter value plus `duration`.
 *
 * \param[in] length      source ticks to program
 * \param[in] wakeup      Timer ticks to program
 * \param[in] next_wakeup Next timer ticks to program
 *
 * \warning
 * first_wakeup and next_wakeup should be cast in the right type structure.
 * You can find the declarations of the structures in the header source_xt_source_runtime.h
 */
void source_xt_source_reload(t_ast_source_duration length,
                                      const void *wakeup,
                                      const void *next_wakeup);

#endif /* ! AST_SOURCE_XT_SOURCE_H_ */
