/************ Copyright Krono-Safe S.A. 2019, All rights reserved ************/

/**
 * @file        intc.h
 * @brief       Interrupt controller management definition
 * @copyright   Copyright Krono-Safe S.A. 2019, All rights reserved.
 */

#ifndef AST_INTERRUPTS_INTC_H_
# define AST_INTERRUPTS_INTC_H_

# include <kstdint.h>

/** Maximum number of interrupt line on the Interrupt Controller */
# define INTC_IRQ_MAX (964)

/** Number of software interrupts on the Interrupt Controller */
# define INTC_SOFTIRQ_MAX (32)

# define INTC_SWT_0_IR    (32)  /**< Software Watchdog Timer 0 IRQ */
# define INTC_SWT_1_IR    (33)  /**< Software Watchdog Timer 1 IRQ */
# define INTC_SWT_2_IR    (34)  /**< Software Watchdog Timer 2 IRQ */
# define INTC_SWT_3_IR    (35)  /**< Software Watchdog Timer 3 IRQ */

# define INTC_STM0_CIR0   (36)  /**< System Timer Module 0 channel 0 IRQ */
# define INTC_STM0_CIR1   (37)  /**< System Timer Module 0 channel 1 IRQ */
# define INTC_STM0_CIR2   (38)  /**< System Timer Module 0 channel 2 IRQ */
# define INTC_STM0_CIR3   (39)  /**< System Timer Module 0 channel 3 IRQ */
# define INTC_STM1_CIR0   (40)  /**< System Timer Module 1 channel 0 IRQ */
# define INTC_STM1_CIR1   (41)  /**< System Timer Module 1 channel 1 IRQ */
# define INTC_STM1_CIR2   (42)  /**< System Timer Module 1 channel 2 IRQ */
# define INTC_STM1_CIR3   (43)  /**< System Timer Module 1 channel 3 IRQ */
# define INTC_STM2_CIR0   (44)  /**< System Timer Module 2 channel 0 IRQ */
# define INTC_STM2_CIR1   (45)  /**< System Timer Module 2 channel 1 IRQ */
# define INTC_STM2_CIR2   (46)  /**< System Timer Module 2 channel 2 IRQ */
# define INTC_STM2_CIR3   (47)  /**< System Timer Module 2 channel 3 IRQ */

/** Macro to get the IRQ of any STM channel */
# define INTC_STM(Module, Channel) (36 + (Module) * 4 + (Channel))

# define INTC_PIT_0_TFLG0 (226) /**< Periodic Interrupt Timer 0 channel 0 IRQ */
# define INTC_PIT_0_TFLG1 (227) /**< Periodic Interrupt Timer 0 channel 1 IRQ */
# define INTC_PIT_0_TFLG2 (228) /**< Periodic Interrupt Timer 0 channel 2 IRQ */
# define INTC_PIT_0_TFLG3 (229) /**< Periodic Interrupt Timer 0 channel 3 IRQ */
# define INTC_PIT_0_TFLG4 (230) /**< Periodic Interrupt Timer 0 channel 4 IRQ */
# define INTC_PIT_0_TFLG5 (231) /**< Periodic Interrupt Timer 0 channel 5 IRQ */
# define INTC_PIT_0_TFLG6 (232) /**< Periodic Interrupt Timer 0 channel 6 IRQ */
# define INTC_PIT_0_TFLG7 (233) /**< Periodic Interrupt Timer 0 channel 7 IRQ */

/** Software Interrupt number for fatal error broadcasting */
# define INTC_EM_ERROR_BROADCAST      (0)

/** Maximum interrupt priority on the controller */
# define INTC_PRIORITY_MAX  (63)


/**
 * @brief Enable an interrupt on the current CPU
 * @param[in] irq_num   The Interrupt ReQuest number
 * @param[in] priority  The interrupt priority
 *
 * The interrupt is enabled only on the calling CPU.
 */
void intc_irq_enable(t_ast_uint32 irq_num, t_ast_uint32 priority);

/**
 * @brief Send a software interrupt to all CPUs except the current one
 * @param[in] softirq_num   The software Interrupt ReQuest number
 */
void intc_softirq_broadcast(t_ast_uint32 softirq_num);


#endif /* !AST_INTERRUPTS_INTC_H_ */
