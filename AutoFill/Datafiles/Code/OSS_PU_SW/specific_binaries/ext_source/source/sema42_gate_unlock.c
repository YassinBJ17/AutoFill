#include <sema42.h>
#include <phys_cpu_id.h>
#include <compiler.h>
#include <kstdint_private.h>
#include <atomic.h>

 void sema42_gate_unlock(e_sema42_gate gate) {   const t_ast_uint8 unlock_value = 0;   atomic_store_fence();   COPY_BYTE(SEMA42_GATE(gate), unlock_value); }
