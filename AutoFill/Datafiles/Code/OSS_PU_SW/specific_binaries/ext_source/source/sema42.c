/************ Copyright Krono-Safe S.A. 2019, All rights reserved ************/
#include <sema42.h>
#include <phys_cpu_id.h>
#include <compiler.h>

#include <kstdint_private.h>
#include <atomic.h>

t_ast_boolean sema42_gate_trylock(e_sema42_gate gate)
{
  t_ast_boolean locked = KFALSE;

  /* To lock a semaphore, one needs to write the CPU ID + 1 in the
   * gate register. Of course, this must be the physical CPU ID, so
   * we cannot rely on the CPU_ID() macro that may return a logical
   * CPU ID different from the physical one */
  const t_ast_uint8 lock_value = (t_ast_uint8) (phys_cpu_id() + 1);

  t_ast_uint8 stored_value;

  /* Try to write the lock value */
  COPY_BYTE(SEMA42_GATE(gate), lock_value);

  /* Barrier */
  atomic_store_fence();

  /* Now read again the register: value must match */
  COPY_BYTE(stored_value, SEMA42_GATE(gate));
  if (stored_value == lock_value)
  {
    /* A match means the gate is locked for us */
    locked = KTRUE;
  }

  /* A barrier is issued above, so any memory access after the lock
   * is obtained in program order should be also issued to the bus after
   * the lock is obtained. */
  return locked;
}

void sema42_gate_lock(e_sema42_gate gate)
{
  t_ast_boolean locked;

  do
  {
    locked = sema42_gate_trylock(gate);
  } while(KTRUE != locked);
}


t_ast_boolean sema42_gate_islocked(e_sema42_gate gate)
{
  t_ast_uint8 stored_value;

  /* Read the gate register */
  COPY_BYTE(stored_value, SEMA42_GATE(gate));

  /* If the gate is locked, gate register has a value different from 0 */
  return (stored_value != 0) ? KTRUE : KFALSE;
}

void sema42_gate_unlock(e_sema42_gate gate)
{
  /* Just write 0 to unlock an already locked gate */
  const t_ast_uint8 unlock_value = 0;

  /* TODO: Check the gate is locked for our core? Currently, if the gate
   * is not locked by this core, this has no effect. */

  /* Ensure previous memory access will be issued to the bus before the
   * gate is unlocked */
  atomic_store_fence();

  /* Unlock */
  COPY_BYTE(SEMA42_GATE(gate), unlock_value);
}
