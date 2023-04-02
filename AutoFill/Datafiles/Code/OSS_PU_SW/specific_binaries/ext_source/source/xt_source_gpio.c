/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#include <intc.h>
#include <compiler.h>

#include <xt_source_gpio.h>


extern t_ast_uint32 phys_cpu_id(void); /* function in kernel ELF */

#define INTC_SIU_EXTERNAL_INTERRUPT_0    (243)  /*int_0: EIRQ0, etc. */
#define INTC_SIU_EXTERNAL_INTERRUPT_1    (244)  /*int_1: EIRQ10, EIRQ11, etc. */

#define IRQ_NB  (10)
#define INTC_EXTERNAL_INTERRUPT_NB  (INTC_SIU_EXTERNAL_INTERRUPT_1)


/**
 * MPC5777M related definitions and types
 */
#define __TO_BITVALUE(V, O, S, T) ( ( ( (T) (V) ) & ( (1 << (S)) - 1 ) ) << (O))
#define __CL_BITVALUE(V, O, S, T) ( ( (T) (V) ) & ~( ( (1 << (S)) - 1 ) << (O) ) )

/* SIUL2 related definitions and types */
#define SIUL2               ((volatile t_ast_uint8 *) (0xFFFC0000UL))
#define SIUL2_DIRER0        (*((volatile t_ast_uint32 *) (SIUL2 + 0x18)))
#define SIUL2_IREER0        (*((volatile t_ast_uint32 *) (SIUL2 + 0x28)))
#define SIUL2_IFEER0        (*((volatile t_ast_uint32 *) (SIUL2 + 0x30)))
#define SIUL2_DISR0         (*((volatile t_ast_uint32 *) (SIUL2 + 0x10)))
#define SIUL2_DIRSR0        (*((volatile t_ast_uint32 *) (SIUL2 + 0x20)))
#define SIUL2_MSCR_IO(Y)    (((volatile SIUL2_MSCR_IO_t *) (SIUL2 + 0x240))[Y])

#define SIUL2_MSCR_IO_OERC(X)   __TO_BITVALUE(X, 28, 3, t_ast_uint32)
#define SIUL2_MSCR_IO_ILS(X)    __TO_BITVALUE(X, 20, 2, t_ast_uint32)
#define SIUL2_MSCR_IO_IBE(X)    __TO_BITVALUE(X, 19, 1, t_ast_uint32)
#define SIUL2_MSCR_IO_HYS(X)    __TO_BITVALUE(X, 18, 1, t_ast_uint32)

typedef t_ast_uint32 SIUL2_MSCR_IO_t;
typedef t_ast_uint32 SIUL2_DIRER0_t;

/* INTC related definitions and types */
#define INTC_0             ((volatile t_ast_uint8 *) (0xFC040000UL))
#define INTC_0_EOIR(Y)     (((volatile t_ast_uint32 *) (INTC_0 + 0x30))[Y])
#define INTC_0_PSR(Y)      (((volatile t_ast_uint16 *) (INTC_0 + 0x60))[Y])

#define INTC_PSR_PRIN_SET(V,X)          (__CL_BITVALUE(V, 0, 6, t_ast_uint16) | __TO_BITVALUE(X, 0, 6, t_ast_uint16))
#define INTC_PSR_PRC_SELN0_SET(V,X)     (__CL_BITVALUE(V, 15, 1, t_ast_uint16) | __TO_BITVALUE(X, 15, 1, t_ast_uint16))
#define INTC_PSR_PRC_SELN1_SET(V,X)     (__CL_BITVALUE(V, 14, 1, t_ast_uint16) | __TO_BITVALUE(X, 14, 1, t_ast_uint16))
#define INTC_PSR_PRC_SELN2_SET(V,X)     (__CL_BITVALUE(V, 13, 1, t_ast_uint16) | __TO_BITVALUE(X, 13, 1, t_ast_uint16))
#define INTC_PSR_PRC_SELN3_SET(V,X)     (__CL_BITVALUE(V, 12, 1, t_ast_uint16) | __TO_BITVALUE(X, 12, 1, t_ast_uint16))
#define INTC_EOIR_EOI(X)                 __TO_BITVALUE(X, 0, 32, t_ast_uint32)

typedef t_ast_uint16 INTC_PSR_t;
typedef t_ast_uint32 INTC_EOIR_t;


/**
 * configure_xt_source_gpio
 * Configure the GPIO used by the FPGA
 */
void configure_xt_source_gpio(void)
{
    /**
     * I/O Pin 0 Multiplexed Signal Configuration Register
     *  - Output Edge Rate Control: set to Medium Drive (200 ohm)
     *  - Input Level Selection: set to TTL
     *  - Input Buffer Enable: set to Enabled
     *  - Input Hysteresis: set to Enabled
     */
    const SIUL2_MSCR_IO_t mscr = (0 | SIUL2_MSCR_IO_OERC(1) | SIUL2_MSCR_IO_ILS(1) | SIUL2_MSCR_IO_IBE(1) | SIUL2_MSCR_IO_HYS(1));
    t_ast_uint32 mask = 0;
    SIUL2_DIRER0_t direr0_backup = SIUL2_DIRER0;

    COPY_WORD(SIUL2_DIRER0, mask);

    /**
     * Interrupt Rising-Edge Event Enable Register0
     *  - Rising-edge event enabled for Pad 0
     */
    SIUL2_IREER0 |= (0x1 << IRQ_NB);

    /**
     * Interrupt Falling-Edge Event Enable Register0
     *  - Falling-edge event disable for Pad 0
     */
    SIUL2_IFEER0 &= ~(0x1 << IRQ_NB);

    COPY_WORD(SIUL2_MSCR_IO(0), mscr);

    /**
     * DMA/Interrupt Request Select Register0
     *  - Select interrupt request for Pad 0
     */
    SIUL2_DIRSR0 &= ~(0x1 << IRQ_NB);
    /**
     * DMA/Interrupt Status Flag Register0
     *  - Clear flag for Pad 0
     */
    SIUL2_DISR0 |= (0x1 << IRQ_NB);

    /**
     * DMA/Interrupt Request Enable Register0
     *  - Disable interrupt for Pad 0
     */
    direr0_backup &= ~(0x1 << IRQ_NB);
    COPY_WORD(SIUL2_DIRER0, direr0_backup);
}

/**
 * configure_xt_source_gpio_interrupt
 * Configure the Interrupt Controller for the GPIO 
 * used by the FPGA for specified CPOU core
 * @param t_ast_uint32  CPU core id
 */
void configure_xt_source_gpio_interrupt(t_ast_uint32 core_id)
{
    INTC_PSR_t psr = (INTC_PSR_t) 0;

    /* set SIUL2 interrupt in INTC for current core */
    COPY_HALF(psr, INTC_0_PSR(INTC_EXTERNAL_INTERRUPT_NB));
    psr = (INTC_PSR_t) INTC_PSR_PRIN_SET(psr, INTC_PRIORITY_MAX);
    switch (core_id)
    {
        case 0:
            psr = (INTC_PSR_t) INTC_PSR_PRC_SELN0_SET(psr, 1);
            break;
        case 1:
            psr = (INTC_PSR_t) INTC_PSR_PRC_SELN1_SET(psr, 1);
            break;
        case 2:
            psr = (INTC_PSR_t) INTC_PSR_PRC_SELN2_SET(psr, 1);
            break;
        case 3:
            psr = (INTC_PSR_t) INTC_PSR_PRC_SELN3_SET(psr, 1);
            break;
        default:
            break;
    }
    COPY_HALF(INTC_0_PSR(INTC_EXTERNAL_INTERRUPT_NB), psr);
}

/**
 * enable_xt_source_gpio
 * Enable the GPIO used by the FPGA
 */
void enable_xt_source_gpio(void)
{
    SIUL2_IREER0 |= (0x1 << IRQ_NB);
    /**
     * DMA/Interrupt Request Enable Register0
     *  - Enable interrupt for Pad 0
     */
    SIUL2_DIRER0 |= (0x1 << IRQ_NB);
}

/**
 * disable_xt_source_gpio
 * Disable the GPIO used by the FPGA
 */
void disable_xt_source_gpio(void)
{
    SIUL2_IREER0 &= ~(0x1 << IRQ_NB);
    /**
     * DMA/Interrupt Request Enable Register0
     *  - Disable interrupt for Pad 0
     */
    SIUL2_DIRER0 &= ~(0x1 << IRQ_NB);
}

/**
 * clear_xt_source_gpio_interrupt
 * Clear the GPIO interrupt flag
 * @note The GPIO IRQ is clear only for the local CPU core
 */
void clear_xt_source_gpio_interrupt(t_ast_uint32 core_id)
{
    const INTC_EOIR_t eoir_cleared = INTC_EOIR_EOI(0);

    /**
     * DMA/Interrupt Status Flag Register0
     *  - Clear flag for Pad 0
     */
    SIUL2_DISR0 |= (0x1 << IRQ_NB);

    /* signal the end of interrupt to the Interrupt Controller (for local CPU core) */
    COPY_WORD(INTC_0_EOIR(core_id), eoir_cleared);
}
