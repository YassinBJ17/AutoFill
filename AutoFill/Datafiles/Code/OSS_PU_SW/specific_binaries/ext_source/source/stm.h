/************ Copyright Krono-Safe S.A. 2019, All rights reserved ************/

/**
 * @file        stm.h
 * @brief       Declaration of the System Timer Module specific functions.
 * @copyright   Copyright Krono-Safe S.A. 2019, All rights reserved.
 */

#ifndef AST_HELPERS_STM_H_
# define AST_HELPERS_STM_H_

# include <compiler.h>

/**
 * @brief STM timeout handler type.
 */
typedef void (*f_stm_handler)(void);


/* Longest timer tuple measurable by STM timers */
# define TIMER_MAX_VALUE (((t_ast_uint32)0xFFFFfffful))

# define STM0_PRESCALER 10                      /**< STM0 Prescaler value */
# define STM0_FREQ (50000000 / STM0_PRESCALER)  /**< STM0 timer final frequency */

# define STM1_PRESCALER 10                      /**< STM1 Prescaler value */
# define STM1_FREQ (50000000 / STM1_PRESCALER)  /**< STM1 timer final frequency */

# define STM2_PRESCALER              (50)
# define XT_SOURCE_TIMER_FREQUENCY   (50000000 / STM2_PRESCALER)

/* Helper macros for translating between decrementer ticks and time values */

/**
 * Set STM comparator tick count
 * @param ID      STM Identifier to be set.
 * @param Channel STM channel to be set
 * @param Value   Value for the trigger to be set
 */
# define STM_SET_COMPARATOR(ID, Channel, Value) do {                        \
    t_ast_uint32 value = (Value);                                           \
    COPY_WORD(STM_ ## ID ## _CHANNEL_CMP(Channel), value);                  \
  } while ((0))

/**
 * Retrieve current STM comparator tick count
 * @param ID      STM Identifier to be set.
 * @param Channel STM channel to be returned
 * @param Result  Return value of the channel
 */
# define STM_GET_COMPARATOR(ID, Channel, Result) do {                       \
    t_ast_uint32 reg;                                                       \
    COPY_WORD(reg, STM_ ## ID ## _CHANNEL_CMP(Channel));                    \
    Result = reg;                                                           \
  } while ((0))

/**
 * Retrieve current STM tick counter
 * @param ID     STM Identifier to be set.
 * @param Result Return value of the timer tick counter
 */
# define STM_GET_COUNTER(ID, Result) do {                                   \
    t_ast_uint32 res;                                                       \
    COPY_WORD(res, STM_ ## ID ## _CNT);                                     \
    Result = res;                                                           \
  } while ((0))

/**
 * Set current STM tick counter.
 * Probably useful only at initialization
 * @param ID    STM Identifier to be set.
 * @param Value Value to be set into the timer counter
 */
# define STM_SET_COUNTER(ID, Value) do {                                    \
    t_ast_uint32 val = (Value);                                             \
    COPY_WORD(STM_ ## ID ## _CNT, val);                                     \
  } while ((0))

# define STM_STATE_DISABLE 0
# define STM_STATE_ENABLE 1

/**
 * Enable/Disable STM timer
 * @param ID    STM Identifier to be set.
 * @param State Status of the STM timer
 */
# define STM_TIMER(ID, State) do {                                          \
    STM_CR_t cr;                                                            \
    COPY_WORD(cr, STM_ ## ID ## _CR);                                       \
    cr = STM_CR_TEN_SET(cr, State);                                         \
    COPY_WORD(STM_ ## ID ## _CR, cr);                                       \
  } while ((0))

/**
 * Enable/Disable STM channel
 * @param ID      STM Identifier to be set.
 * @param Channel STM Channel to be activated
 * @param State   Status to be applied
 */
# define STM_CHANNEL(ID, Channel, State) do {                               \
    STM_CHANNEL_CCR_t ccr;                                                  \
    const STM_CHANNEL_CIR_t cir = STM_CHANNEL_CIR_CIF(1);                   \
    COPY_WORD(ccr, STM_ ## ID ## _CHANNEL_CCR(Channel));                    \
    ccr = STM_CHANNEL_CCR_CEN_SET(ccr, State);                              \
    COPY_WORD(STM_ ## ID ## _CHANNEL_CCR(Channel), ccr);                    \
    COPY_WORD(STM_ ## ID ## _CHANNEL_CIR(Channel), cir);                    \
  } while ((0))

/**
 * Clear potential pending STM IRQ on a STM channel
 * @param ID      STM Identifier to be set.
 * @param Channel STM Channel to be cleared
 */
# define STM_CLEAR_PENDING(ID, Channel) do {                                \
    STM_CHANNEL_CIR_t cir;                                                  \
    COPY_WORD(cir, STM_ ##ID ## _CHANNEL_CIR(Channel));                     \
    cir = STM_CHANNEL_CIR_CIF_SET(cir, 1);                                  \
    COPY_WORD(STM_ ## ID ## _CHANNEL_CIR(Channel), cir);                    \
  } while ((0))

# define STM_CHANNEL0   (0) /**< STM Channel 0 */
# define STM_CHANNEL1   (1) /**< STM Channel 1 */
# define STM_CHANNEL2   (2) /**< STM Channel 2 */
# define STM_CHANNEL3   (3) /**< STM Channel 3 */

#endif /* !AST_HELPERS_STM_H_ */
