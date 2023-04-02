/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_DRIVER_TM_H
#define FPGA_REG_DRIVER_TM_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_tm_cmd_reg' */
typedef struct
{
   uint32_t s_spare_31_to_28 :  4; /* Bits : 31:28 :                                                                                                                                                                                                  */
   uint32_t s_DAC_cmd        : 12; /* Bits : 27:16 : DAC command register:? if {tm_sm_disable_n} = 1'b0, then {DAC_cmd} = xxx (0mA+-0.4mA).? if {tm_sm_disable_n} = 1'b1, then {DAC_cmd} = {vtmot}.Note: {tm_sm_disable_n} is an input of BRIDGE PLD. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                                                                                                                                                                  */
   uint32_t s_vtmot          : 12; /* Bits : 11:0  : Vtmot command register                                                                                                                                                                           */
}
ts_fpga_reg_driver_tm_tm_cmd_reg_u_bit;

typedef union
{
   uint32_t                               u_word;
   ts_fpga_reg_driver_tm_tm_cmd_reg_u_bit u_bit;
}
tu_fpga_reg_driver_tm_tm_cmd_reg;

/* Group of registers in 'Driver_TM' named 'configuration_registers' */
typedef struct
{
   tu_fpga_reg_driver_tm_tm_cmd_reg s_tm_cmd_reg;
}
ts_fpga_reg_driver_tm_configuration_registers;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'Driver_TM' */

typedef struct
{
   ts_fpga_reg_driver_tm_configuration_registers s_configuration_registers_regs;
}
ts_fpga_reg_driver_tm;

#endif /* FPGA_REG_DRIVER_TM_H */
