/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_GPIO_H
#define FPGA_REG_GPIO_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_gpio_in' */
typedef struct
{
   uint32_t s_spare_31_to_4       : 28; /* Bits : 31:4 : N/A             */
   uint32_t s_pwm_imon_reg        :  1; /* Bits : 03   : PWM monitoring  */
   uint32_t s_mdin                :  1; /* Bits : 02   : PLD Input value */
   uint32_t s_pbit_uvd_status     :  1; /* Bits : 01   :                 */
   uint32_t s_pbit_ovd_pld_status :  1; /* Bits : 00   :                 */
}
ts_fpga_reg_gpio_gpio_in_u_bit;

typedef union
{
   uint32_t                       u_word;
   ts_fpga_reg_gpio_gpio_in_u_bit u_bit;
}
tu_fpga_reg_gpio_gpio_in;

/* Union definition for register 's_gpio_in_ack' */
typedef struct
{
   uint32_t s_spare_31_to_1     : 31; /* Bits : 31:1 : N/A                                                                                           */
   uint32_t s_pwm_imon_reg _ack :  1; /* Bits : 00   : pwm_imon_reg  acknowledge command:0b1 = acknowledges the pwm_imon_reg  status0b0 = no effect. */
}
ts_fpga_reg_gpio_gpio_in_ack_u_bit;

typedef union
{
   uint32_t                           u_word;
   ts_fpga_reg_gpio_gpio_in_ack_u_bit u_bit;
}
tu_fpga_reg_gpio_gpio_in_ack;

/* Union definition for register 's_gpio_out_val' */
typedef struct
{
   uint32_t s_spare_31_to_12            : 20; /* Bits : 31:12 : N/A                                  */
   uint32_t s_pbit_ovd_p3v3_pld_val     :  1; /* Bits : 11    : 'Intermediate' discrete output value */
   uint32_t s_pbit_ovd_p2v5_pld_val     :  1; /* Bits : 10    :                                      */
   uint32_t s_pbit_ovd_p1v2_pld_val     :  1; /* Bits : 09    :                                      */
   uint32_t s_pbit_ovd_p15v0_pld_val    :  1; /* Bits : 08    :                                      */
   uint32_t s_pbit_uvd_p3v3_pld_val     :  1; /* Bits : 07    :                                      */
   uint32_t s_pbit_uvd_p2v5_pld_val     :  1; /* Bits : 06    :                                      */
   uint32_t s_pbit_uvd_p1v2_pld_val     :  1; /* Bits : 05    :                                      */
   uint32_t s_pbit_uvd_p15v0_pld_val    :  1; /* Bits : 04    :                                      */
   uint32_t s_pbit_enable_val           :  1; /* Bits : 03    :                                      */
   uint32_t s_pbit_d_to_zero_val        :  1; /* Bits : 02    :                                      */
   uint32_t s_pbit_inhib_rst_val        :  1; /* Bits : 01    :                                      */
   uint32_t s_pbit_inhib_cutoff_pld_val :  1; /* Bits : 00    :                                      */
}
ts_fpga_reg_gpio_gpio_out_val_u_bit;

typedef union
{
   uint32_t                            u_word;
   ts_fpga_reg_gpio_gpio_out_val_u_bit u_bit;
}
tu_fpga_reg_gpio_gpio_out_val;

/* Union definition for register 's_gpio_out' */
typedef struct
{
   uint32_t s_spare_31_to_12         : 20; /* Bits : 31:12 : N/A                   */
   uint32_t s_pbit_ovd_p3v3_pld_cmd  :  1; /* Bits : 11    : Discrete output value */
   uint32_t s_pbit_ovd_p2v5_pld_cmd  :  1; /* Bits : 10    :                       */
   uint32_t s_pbit_ovd_p1v2_pld_cmd  :  1; /* Bits : 09    :                       */
   uint32_t s_pbit_ovd_p15v0_pld_cmd :  1; /* Bits : 08    :                       */
   uint32_t s_pbit_uvd_p3v3_pld_cmd  :  1; /* Bits : 07    :                       */
   uint32_t s_pbit_uvd_p2v5_pld_cmd  :  1; /* Bits : 06    :                       */
   uint32_t s_pbit_uvd_p1v2_pld_cmd  :  1; /* Bits : 05    :                       */
   uint32_t s_pbit_uvd_p15v0_pld_cmd :  1; /* Bits : 04    :                       */
   uint32_t s_pbit_enable            :  1; /* Bits : 03    :                       */
   uint32_t s_pbit_d_to_zero         :  1; /* Bits : 02    :                       */
   uint32_t s_pbit_inhib_rst         :  1; /* Bits : 01    :                       */
   uint32_t s_pbit_inhib_cutoff_pld  :  1; /* Bits : 00    :                       */
}
ts_fpga_reg_gpio_gpio_out_u_bit;

typedef union
{
   uint32_t                        u_word;
   ts_fpga_reg_gpio_gpio_out_u_bit u_bit;
}
tu_fpga_reg_gpio_gpio_out;

/* Group of registers in 'gpio' named 'configuration_and_status_registers' */
typedef struct
{
   tu_fpga_reg_gpio_gpio_in      s_gpio_in;
   tu_fpga_reg_gpio_gpio_in_ack  s_gpio_in_ack;
   tu_fpga_reg_gpio_gpio_out_val s_gpio_out_val;
   tu_fpga_reg_gpio_gpio_out     s_gpio_out;
   uint32_t                      s_gpio_key_1;
   uint32_t                      s_gpio_key_2;
}
ts_fpga_reg_gpio_configuration_and_status_registers;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'gpio' */

typedef struct
{
   ts_fpga_reg_gpio_configuration_and_status_registers s_configuration_and_status_registers_regs;
}
ts_fpga_reg_gpio;

#endif /* FPGA_REG_GPIO_H */
