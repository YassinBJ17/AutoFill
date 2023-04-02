/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP10_SPEED_H
#define FPGA_REG_IIP10_SPEED_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_control_reg' */
typedef struct
{
   uint32_t s_spare_31_to_2    : 30; /* Bits : 31:2 :                                            */
   uint32_t s_parity_error_ack :  1; /* Bits : 01   : Acknowledge a parity error in RAM (read 0) */
   uint32_t s_corrupt_parity   :  1; /* Bits : 00   : Force corruption of {rx_ram}               */
}
ts_fpga_reg_iip10_speed_control_reg_u_bit;

typedef union
{
   uint32_t                                  u_word;
   ts_fpga_reg_iip10_speed_control_reg_u_bit u_bit;
}
tu_fpga_reg_iip10_speed_control_reg;

/* Union definition for register 's_conf_reg' */
typedef struct
{
   uint32_t s_spare_31_to_4 : 28; /* Bits : 31:4 :                                                                                   */
   uint32_t s_inc_2_th_sel  :  2; /* Bits : 3:2  : Inconsistency 2 threshold selection :00 = 6,25 %.01 = 12,5 %.10 = 25 %.11 = 50 %. */
   uint32_t s_inc_1_th_sel  :  2; /* Bits : 1:0  : Inconsistency 1 threshold selection :00 = 6,25 %.01 = 12,5 %.10 = 25 %.11 = 50 %. */
}
ts_fpga_reg_iip10_speed_conf_reg_u_bit;

typedef union
{
   uint32_t                               u_word;
   ts_fpga_reg_iip10_speed_conf_reg_u_bit u_bit;
}
tu_fpga_reg_iip10_speed_conf_reg;

/* Union definition for register 's_status_reg' */
typedef struct
{
   uint32_t s_spare_31_to_21      : 11; /* Bits : 31:21 :                                                                                                                       */
   uint32_t s_glb_inconsistency_2 :  1; /* Bits : 20    : ? Set to 0b1 when at least one {inconsistency_2} was detected within the previous minor frame.? Set to 0b0 otherwise. */
   uint32_t s_glb_inconsistency_1 :  1; /* Bits : 19    : ? Set to 0b1 when at least one {inconsistency_1} was detected within the previous minor frame.? Set to 0b0 otherwise. */
   uint32_t s_glitch_detect       :  1; /* Bits : 18    : Detected glitches on speed input within the previous minor frame.                                                     */
   uint32_t s_overflow            :  1; /* Bits : 17    : Overflow on {rx_ram}                                                                                                  */
   uint32_t s_parity_error        :  1; /* Bits : 16    : Parity error in {rx_ram}                                                                                              */
   uint32_t s_spare_15_to_9       :  7; /* Bits : 15:9  :                                                                                                                       */
   uint32_t s_sample_number_last  :  9; /* Bits : 8:0   : Number of samples acquired during last minor frame                                                                    */
}
ts_fpga_reg_iip10_speed_status_reg_u_bit;

typedef union
{
   uint32_t                                 u_word;
   ts_fpga_reg_iip10_speed_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip10_speed_status_reg;

/* Union definition for register 's_counter_reg' */
typedef struct
{
   uint32_t s_spare_31_to_9 : 23; /* Bits : 31:9 :                                                                   */
   uint32_t s_sample_number :  9; /* Bits : 8:0  : Number of samples acquired since start of the current minor frame */
}
ts_fpga_reg_iip10_speed_counter_reg_u_bit;

typedef union
{
   uint32_t                                  u_word;
   ts_fpga_reg_iip10_speed_counter_reg_u_bit u_bit;
}
tu_fpga_reg_iip10_speed_counter_reg;

/* Group of registers in 'iip10_speed' named 'configuration___status' */
typedef struct
{
   tu_fpga_reg_iip10_speed_control_reg s_control_reg;
   tu_fpga_reg_iip10_speed_conf_reg    s_conf_reg;
   tu_fpga_reg_iip10_speed_status_reg  s_status_reg;
   tu_fpga_reg_iip10_speed_counter_reg s_counter_reg;
}
ts_fpga_reg_iip10_speed_configuration___status;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_rx_data_0[256]' */
typedef struct
{
   uint32_t s_inconsistency_2 :  1; /* Bits : 31    : ? Set {inconsistency_2} to 0b1 when the following equation is true:| [{period}(N)+{period}(N-1)] - [{period}(N-2)+{period}(N-3)] | > {inc_2_th} * [{period}(N-2)+{period}(N-3)] ? Set {inconsistency_2} to 0b0 otherwise.with  {inc_2_th} = 6.25% * 2^{inc_2_th_sel} */
   uint32_t s_inconsistency_1 :  1; /* Bits : 30    : ? Set {inconsistency_1} to 0b1 when the following equation is true:|{period}(N) - {period}(N-1)| > {inc_1_th} * {period}(N-1)? Set {inconsistency_1} to 0b0 otherwise.with {inc_1_th} = 6.25% * 2^{inc_1_th_sel}                                                     */
   uint32_t s_spare_29_to_24  :  6; /* Bits : 29:24 :                                                                                                                                                                                                                                                                      */
   uint32_t s_period          : 24; /* Bits : 23:0  : Period measurement with:? Accuracy: +/- 2 *{clk_main} period ? Resolution: {clk_main} period                                                                                                                                                                         */
   uint32_t s_inconsistency_1 :  1; /* Bits : 30    : ? Set {inconsistency_1} to 0b1 when the following equation is true:|{period}(N) - {period}(N-1)| > {inc_1_th} * {period}(N-1)? Set {inconsistency_1} to 0b0 otherwise.with {inc_1_th} = 6.25% * 2^{inc_1_th_sel}                                                     */
   uint32_t s_spare_29_to_24  :  6; /* Bits : 29:24 :                                                                                                                                                                                                                                                                      */
   uint32_t s_period_00       : 24; /* Bits : 23:0  : Period measurement with:? Accuracy: +/- 2 *{clk_main} period ? Resolution: {clk_main} period                                                                                                                                                                         */
}
ts_fpga_reg_iip10_speed_rx_data_0[256]_u_bit;

typedef union
{
   uint32_t                                     u_word;
   ts_fpga_reg_iip10_speed_rx_data_0[256]_u_bit u_bit;
}
tu_fpga_reg_iip10_speed_rx_data_0[256];

/* Group of registers in 'iip10_speed' named 'rx_ram' */
typedef struct
{
   tu_fpga_reg_iip10_speed_rx_data_0[256] s_rx_data_0[256];
}
ts_fpga_reg_iip10_speed_rx_ram;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip10_speed' */

typedef struct
{
   ts_fpga_reg_iip10_speed_configuration___status s_configuration___status_regs;
   ts_fpga_reg_iip10_speed_rx_ram                 s_rx_ram_regs;
}
ts_fpga_reg_iip10_speed;

#endif /* FPGA_REG_IIP10_SPEED_H */
