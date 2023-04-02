/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_DRIVER_SM_H
#define FPGA_REG_DRIVER_SM_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_sm_cmd_reg' */
typedef struct
{
   uint32_t s_spare_31_to_6 : 26; /* Bits : 31:6 :                                                                                   */
   uint32_t s_sm_inc_sign   :  1; /* Bits : 05   : SM increment sign register:'1': increment the position'0': decrement the position */
   uint32_t s_sm_inc_cmd    :  5; /* Bits : 4:0  : SM increment command register:Number of increment from the current position.      */
}
ts_fpga_reg_driver_sm_sm_cmd_reg_u_bit;

typedef union
{
   uint32_t                               u_word;
   ts_fpga_reg_driver_sm_sm_cmd_reg_u_bit u_bit;
}
tu_fpga_reg_driver_sm_sm_cmd_reg;

/* Union definition for register 's_sm_config_reg' */
typedef struct
{
   uint32_t s_spare_31_to_10 : 22; /* Bits : 31:10 :                                                                                                                                   */
   uint32_t s_tech           : 10; /* Bits : 9:0   : The duration of each transitory position equals to [1ms+ {tech}*1.005us](1 LSB for tech = 1 internal time base period = 1.005 µs) */
}
ts_fpga_reg_driver_sm_sm_config_reg_u_bit;

typedef union
{
   uint32_t                                  u_word;
   ts_fpga_reg_driver_sm_sm_config_reg_u_bit u_bit;
}
tu_fpga_reg_driver_sm_sm_config_reg;

/* Union definition for register 's_sm_control_reg' */
typedef struct
{
   uint32_t s_spare_31_to_1 : 31; /* Bits : 31:1 :                                                                                     */
   uint32_t s_sm_error_ack  :  1; /* Bits : 00   : sm_error acknowledge command:0b1 = acknowledges the sm_error status0b0 = no effect. */
}
ts_fpga_reg_driver_sm_sm_control_reg_u_bit;

typedef union
{
   uint32_t                                   u_word;
   ts_fpga_reg_driver_sm_sm_control_reg_u_bit u_bit;
}
tu_fpga_reg_driver_sm_sm_control_reg;

/* Union definition for register 's_sm_status_reg' */
typedef struct
{
   uint32_t s_spare_31_to_27 :  5; /* Bits : 31:27 :                                                                                                       */
   uint32_t s_sm_position    :  3; /* Bits : 26:24 : Steper Motor position (8 positions from 0 to 7)                                                       */
   uint32_t s_spare_23_to_20 :  4; /* Bits : 23:20 :                                                                                                       */
   uint32_t s_sm_cmd         :  4; /* Bits : 19:16 : Steper Motor command output status                                                                    */
   uint32_t s_spare_15_to_2  : 14; /* Bits : 15:2  :                                                                                                       */
   uint32_t s_sm_busy        :  1; /* Bits : 01    : Stepper Motor busy indicator:  '1': SM position is changing.  '0': SM position is not changing.       */
   uint32_t s_sm_error       :  1; /* Bits : 00    : Stepper Motor error indicator: Asserted when a SM position change is requested while {sm_busy} = 1'b1 */
}
ts_fpga_reg_driver_sm_sm_status_reg_u_bit;

typedef union
{
   uint32_t                                  u_word;
   ts_fpga_reg_driver_sm_sm_status_reg_u_bit u_bit;
}
tu_fpga_reg_driver_sm_sm_status_reg;

/* Group of registers in 'Driver_SM' named 'configuration_stétus_registers' */
typedef struct
{
   tu_fpga_reg_driver_sm_sm_cmd_reg     s_sm_cmd_reg;
   tu_fpga_reg_driver_sm_sm_config_reg  s_sm_config_reg;
   tu_fpga_reg_driver_sm_sm_control_reg s_sm_control_reg;
   tu_fpga_reg_driver_sm_sm_status_reg  s_sm_status_reg;
}
ts_fpga_reg_driver_sm_configuration_stétus_registers;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'Driver_SM' */

typedef struct
{
   ts_fpga_reg_driver_sm_configuration_stétus_registers s_configuration_stétus_registers_regs;
}
ts_fpga_reg_driver_sm;

#endif /* FPGA_REG_DRIVER_SM_H */
