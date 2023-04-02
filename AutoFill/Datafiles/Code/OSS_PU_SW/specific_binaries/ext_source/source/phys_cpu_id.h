/************ Copyright Krono-Safe S.A. 2019, All rights reserved ************/

/**
 * @file        phys_cpu_id.h
 * @brief       Definition of the physical CPU ID getter function.
 * @copyright   Copyright Krono-Safe S.A. 2019, All rights reserved.
 *
 */

#ifndef AST_HELPERS_PHYS_CPU_ID_H_
# define AST_HELPERS_PHYS_CPU_ID_H_

# include <kstdint_private.h>

/**
 * @brief Get the current physical CPU ID.
 *
 * This function is different from CPU_ID() or hal_cpu_id() because it directly
 * reads the Processor Identification Register (SPR_PIR), whereas CPU_ID() may
 * return 0 on a monocore product, regardless of the currently running CPU.
 *
 * This function shall be used whenever the *real* physical CPU ID is needed,
 * for example to interact with the interrupt controller.
 *
 * @return the current physical CPU ID.
 */
t_ast_uint32 phys_cpu_id(void);

#endif /* !AST_HELPERS_PHYS_CPU_ID_H_ */
