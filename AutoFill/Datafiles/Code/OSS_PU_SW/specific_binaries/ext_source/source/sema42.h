/************ Copyright Krono-Safe S.A. 2019, All rights reserved ************/

/**
 * @file        sema42.h
 * @brief       Declaration of the SEMA42 module functions
 * @copyright   Copyright Krono-Safe S.A. 2019, All rights reserved.
 */

#ifndef AST_HELPERS_SEMA42_H_
# define AST_HELPERS_SEMA42_H_

# include <kstdint_private.h>

/** Available gates on the SEMA42 module */
typedef enum
{
  SEMA42_GATE_0  = 0,
  SEMA42_GATE_1  = 1,
  SEMA42_GATE_2  = 2,
  SEMA42_GATE_3  = 3,
  SEMA42_GATE_4  = 4,
  SEMA42_GATE_5  = 5,
  SEMA42_GATE_6  = 6,
  SEMA42_GATE_7  = 7,
  SEMA42_GATE_8  = 8,
  SEMA42_GATE_9  = 9,
  SEMA42_GATE_10 = 10,
  SEMA42_GATE_11 = 11,
  SEMA42_GATE_12 = 12,
  SEMA42_GATE_13 = 13,
  SEMA42_GATE_14 = 14,
  SEMA42_GATE_15 = 15,
  SEMA42_GATE_COUNT = 16
} e_sema42_gate;


typedef t_ast_uint8 SEMA42_GATE_t;
# define __VPTR(X) ((volatile t_ast_uint8 *) (X))
/* Base address of the SEMA42 controller */
# define SEMA42 __VPTR(0xFC03C000UL)
/* Computes the address of a given gate */
# define SEMA42_GATE(Y)         (((volatile SEMA42_GATE_t *) (SEMA42 + 0x0))[Y])

/* Do not use the enum above direclty. Instead, use the following "define" value */
/** SEMA42 gate for Compare And Swap */
# define SEMA42_GATE_CAS         SEMA42_GATE_0
/** SEMA42 gate to lock relocalisation process */
# define SEMA42_GATE_RELOC       SEMA42_GATE_1
/** SEMA42 gate to lock after relocalisation is done */
# define SEMA42_GATE_RELOC_DONE  SEMA42_GATE_2

/**@brief Lock a gate of the SEMA42 module for the current core
 *
 * @param gate  The gate to lock
 *
 * When this function returns, the current core will hold the designed
 * gate. It *must* call sema42_gate_unlock() to unlock the gate afterward.
 */
void sema42_gate_lock(e_sema42_gate gate);

/**@brief Try to lock a gate of the SEMA42 module for the current core
 *
 * @param gate  The gate to lock
 *
 * @return KTRUE if the gate is locked by this call, false otherwise.
 *
 * If this function returns KTRUE, the current core will hold the designed
 * gate. It *must* call sema42_gate_unlock() to unlock the gate afterward.
 */
t_ast_boolean sema42_gate_trylock(e_sema42_gate gate);

/**@brief Check if a gate is currently locked by any core
 *
 * @param gate  The gate to check
 *
 * @return KTRUE if the gate is locked by any core.
 *
 * @note This function returns KTRUE if the gate is locked by *any* core,
 *       not only by the *current* core!
 *       But if someone needs to know if the current core has locked a gate,
 *       this is certainly a design error...
 */
t_ast_boolean sema42_gate_islocked(e_sema42_gate gate);

/**@brief Unlock a gate of the SEMA42 module
 *
 * @param gate  The gate to unlock
 *
 * If the designed gate is held by the current core, when this function
 * returns, the gate is unlocked.
 * This function has no effect if the core does not currently hold the gate.
 */
void sema42_gate_unlock(e_sema42_gate gate);

#endif /* !AST_HELPERS_SEMA42_H_ */
