#include <sema42.h>
#include <phys_cpu_id.h>
#include <compiler.h>
#include <kstdint_private.h>
#include <atomic.h>

 t_ast_boolean sema42_gate_islocked(e_sema42_gate gate) {   t_ast_uint8 stored_value;   COPY_BYTE(stored_value, SEMA42_GATE(gate));   return (stored_value != 0) ? KTRUE : KFALSE; }
