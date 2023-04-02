#include <sema42.h>
#include <phys_cpu_id.h>
#include <compiler.h>
#include <kstdint_private.h>
#include <atomic.h>

 t_ast_boolean sema42_gate_trylock(e_sema42_gate gate) {   t_ast_boolean locked = KFALSE;   const t_ast_uint8 lock_value = (t_ast_uint8) (phys_cpu_id() + 1);   t_ast_uint8 stored_value;   COPY_BYTE(SEMA42_GATE(gate), lock_value);   atomic_store_fence();   COPY_BYTE(stored_value, SEMA42_GATE(gate));   if (stored_value == lock_value)   {     locked = KTRUE;   }   return locked; }
