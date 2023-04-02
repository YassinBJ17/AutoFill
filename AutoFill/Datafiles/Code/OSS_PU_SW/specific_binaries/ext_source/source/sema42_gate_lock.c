#include <sema42.h>
#include <phys_cpu_id.h>
#include <compiler.h>
#include <kstdint_private.h>
#include <atomic.h>

 void sema42_gate_lock(e_sema42_gate gate) {   t_ast_boolean locked;   do   {     locked = sema42_gate_trylock(gate);   } while(KTRUE != locked); }
