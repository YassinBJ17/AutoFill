/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_MISC1_H
#define FPGA_REG_MISC1_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_pld_ident' */
typedef struct
{
   uint32_t s_ident       : 8; /* Bits : 31:24 : PLD ID                  */
   uint32_t s_version     : 8; /* Bits : 23:16 : PLD version             */
   uint32_t s_sub_version : 8; /* Bits : 15:8  : PLD sub-version         */
   uint32_t s_build       : 8; /* Bits : 7:0   : PLD integration version */
}
ts_fpga_reg_misc1_pld_ident_u_bit;

typedef union
{
   uint32_t                          u_word;
   ts_fpga_reg_misc1_pld_ident_u_bit u_bit;
}
tu_fpga_reg_misc1_pld_ident;

/* Group of registers in 'misc1' named 'miscellaneous_resources_registers' */
typedef struct
{
   tu_fpga_reg_misc1_pld_ident s_pld_ident;
}
ts_fpga_reg_misc1_miscellaneous_resources_registers;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_pld_status_reg' */
typedef struct
{
   uint32_t s_pll_lock_ebi_64m          :  1; /* Bits : 31   : 1 = PLL is locked.0 = PLL is not locked. */
   uint32_t s_pll_lock_ebi_80m (SPEED)  :  1; /* Bits : 30   : 1 = PLL is locked.0 = PLL is not locked. */
   uint32_t s_pll_lock_wd_80m (PSF_MON) :  1; /* Bits : 29   : 1 = PLL is locked.0 = PLL is not locked. */
   uint32_t s_Not Used                  : 29; /* Bits : 28:0 :                                          */
}
ts_fpga_reg_misc1_pld_status_reg_u_bit;

typedef union
{
   uint32_t                               u_word;
   ts_fpga_reg_misc1_pld_status_reg_u_bit u_bit;
}
tu_fpga_reg_misc1_pld_status_reg;

/* Group of registers in 'misc1' named 'test_registers' */
typedef struct
{
   uint32_t                         s_test_reg;
   uint32_t                         s_reg_ebi_aa;
   uint32_t                         s_reg_ebi_55;
   uint32_t                         s_timestamp_reg;
   tu_fpga_reg_misc1_pld_status_reg s_pld_status_reg;
}
ts_fpga_reg_misc1_test_registers;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'misc1' */

typedef struct
{
   ts_fpga_reg_misc1_miscellaneous_resources_registers s_miscellaneous_resources_registers_regs;
   ts_fpga_reg_misc1_test_registers                    s_test_registers_regs;
}
ts_fpga_reg_misc1;

#endif /* FPGA_REG_MISC1_H */
