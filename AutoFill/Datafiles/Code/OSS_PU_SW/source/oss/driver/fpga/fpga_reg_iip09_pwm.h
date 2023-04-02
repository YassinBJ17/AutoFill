/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP09_PWM_H
#define FPGA_REG_IIP09_PWM_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_ident_reg' */
typedef struct
{
   uint32_t s_Not Used : 16; /* Bits : 31:16 : Read 0                          */
   uint32_t s_ip_id    :  8; /* Bits : 15:8  : IP identifier numberFixed value */
   uint32_t s_ip_ver   :  8; /* Bits : 7:0   : IP version numberFixed value    */
}
ts_fpga_reg_iip09_pwm_ident_reg_u_bit;

typedef union
{
   uint32_t                              u_word;
   ts_fpga_reg_iip09_pwm_ident_reg_u_bit u_bit;
}
tu_fpga_reg_iip09_pwm_ident_reg;

/* Union definition for register 's_period_reg' */
typedef struct
{
   uint32_t s_Not Used   :  8; /* Bits : 31:24 : Read 0                                            */
   uint32_t s_pwm_period : 24; /* Bits : 23:0  : PWM period value expressed in {clk} clock period. */
}
ts_fpga_reg_iip09_pwm_period_reg_u_bit;

typedef union
{
   uint32_t                               u_word;
   ts_fpga_reg_iip09_pwm_period_reg_u_bit u_bit;
}
tu_fpga_reg_iip09_pwm_period_reg;

/* Union definition for register 's_high_time_reg' */
typedef struct
{
   uint32_t s_Not Used      :  8; /* Bits : 31:24 : Read 0                                                                                                                                                      */
   uint32_t s_pwm_high_time : 24; /* Bits : 23:0  : PWM high state duration expressed in {clk} clock period to set PWM duty cycle.PWM_HIGH_TIME value = expected duty cycle value multiply by PWM_PERIOD value. */
}
ts_fpga_reg_iip09_pwm_high_time_reg_u_bit;

typedef union
{
   uint32_t                                  u_word;
   ts_fpga_reg_iip09_pwm_high_time_reg_u_bit u_bit;
}
tu_fpga_reg_iip09_pwm_high_time_reg;

/* Union definition for register 's_command_reg' */
typedef struct
{
   uint32_t s_Not Used : 31; /* Bits : 31:1 : Read 0                                                                                                                      */
   uint32_t s_pwm_en   :  1; /* Bits : 00   : Writing a '1' enables the PWM output generation.Writing a '0' disables the PWM output generation when PWM period completes. */
}
ts_fpga_reg_iip09_pwm_command_reg_u_bit;

typedef union
{
   uint32_t                                u_word;
   ts_fpga_reg_iip09_pwm_command_reg_u_bit u_bit;
}
tu_fpga_reg_iip09_pwm_command_reg;

/* Group of registers in 'iip09_pwm' named 'configuration' */
typedef struct
{
   tu_fpga_reg_iip09_pwm_ident_reg     s_ident_reg;
   tu_fpga_reg_iip09_pwm_period_reg    s_period_reg;
   tu_fpga_reg_iip09_pwm_high_time_reg s_high_time_reg;
   tu_fpga_reg_iip09_pwm_command_reg   s_command_reg;
}
ts_fpga_reg_iip09_pwm_configuration;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip09_pwm' */

typedef struct
{
   ts_fpga_reg_iip09_pwm_configuration s_configuration_regs;
}
ts_fpga_reg_iip09_pwm;

#endif /* FPGA_REG_IIP09_PWM_H */
