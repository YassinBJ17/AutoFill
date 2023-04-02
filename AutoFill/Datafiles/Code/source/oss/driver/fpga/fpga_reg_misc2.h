/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_MISC2_H
#define FPGA_REG_MISC2_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Group of registers in 'misc2' named 'test_registers' */
typedef struct
{
   uint32_t s_test_reg;
   uint32_t spare_0x4_to_0x3fef[4091];
   uint32_t s_reg_ebi_aa;
   uint32_t s_reg_ebi_55;
}
ts_fpga_reg_misc2_test_registers;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'misc2' */

typedef struct
{
   ts_fpga_reg_misc2_test_registers s_test_registers_regs;
}
ts_fpga_reg_misc2;

#endif /* FPGA_REG_MISC2_H */
