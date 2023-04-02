/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#ifndef XT_SOURCE_GPIO
#define XT_SOURCE_GPIO

#include <kstdint_private.h>

/**
 * configure_xt_source_gpio
 * Configure the GPIO used by the FPGA
 */
void configure_xt_source_gpio(void);

/**
 * configure_xt_source_gpio_interrupt
 * Configure the Interrupt Controller for the GPIO 
 * used by the FPGA for specified CPOU core
 * @param t_ast_uint32  CPU core id
 */
void configure_xt_source_gpio_interrupt(t_ast_uint32 core_id);

/**
 * enable_xt_source_gpio
 * Enable the GPIO used by the FPGA
 */
void enable_xt_source_gpio(void);

/**
 * disable_xt_source_gpio
 * Disable the GPIO used by the FPGA
 */
void disable_xt_source_gpio(void);

/**
 * clear_xt_source_gpio_interrupt
 * Clear the GPIO interrupt flag for specified CPU core
 * @param t_ast_uint32  CPU core id
 */
void clear_xt_source_gpio_interrupt(t_ast_uint32 core_id);

#endif /* XT_SOURCE_GPIO */
