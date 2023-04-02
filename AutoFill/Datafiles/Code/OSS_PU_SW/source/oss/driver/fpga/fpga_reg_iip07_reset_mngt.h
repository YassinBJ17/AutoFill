/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP07_RESET_MNGT_H
#define FPGA_REG_IIP07_RESET_MNGT_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_reset_counter_reg' */
typedef struct
{
   uint32_t s_reserved           : 8; /* Bits : 31:24 : NA                                          */
   uint32_t s_reset_pbit_ctr     : 8; /* Bits : 23:16 : Number of reset that occured in {pbit_mode} */
   uint32_t s_reserved_00        : 8; /* Bits : 15:8  : NA                                          */
   uint32_t s_reset_critical_ctr : 8; /* Bits : 7:0   : Number of critical reset                    */
}
ts_fpga_reg_iip07_reset_mngt_reset_counter_reg_u_bit;

typedef union
{
   uint32_t                                             u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_counter_reg_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_counter_reg;

/* Union definition for register 's_reset_source_reg' */
typedef struct
{
   uint32_t s_reserved     : 14; /* Bits : 31:18 : N/A                                                                                                                                                  */
   uint32_t s_reset_source : 18; /* Bits : 17:0  : reset_source[17] : {reset_xmap}  source savereset_source[16] :  {reset_software}  source savereset_source[15:0] : {reset_critical_xmap}  source save */
}
ts_fpga_reg_iip07_reset_mngt_reset_source_reg_u_bit;

typedef union
{
   uint32_t                                            u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_source_reg_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_source_reg;

/* Union definition for register 's_reset_prev_source_reg' */
typedef struct
{
   uint32_t s_reserved          : 14; /* Bits : 31:18 : N/A                                                                                                           */
   uint32_t s_reset_prev_source : 18; /* Bits : 17:0  : previous {reset_critical_xmap}, {reset_xmap}, {reset_software}  source save, same structure as {reset_source} */
}
ts_fpga_reg_iip07_reset_mngt_reset_prev_source_reg_u_bit;

typedef union
{
   uint32_t                                                 u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_prev_source_reg_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_prev_source_reg;

/* Union definition for register 's_status_reg' */
typedef struct
{
   uint32_t s_reserved        : 14; /* Bits : 31:18 :                                                                                                    */
   uint32_t s_mdisc_command_n :  1; /* Bits : 17    : Status of the { mdisc_command_n} output.                                                           */
   uint32_t s_pbit_mode       :  1; /* Bits : 16    : enable and disable is done thanks to secure software access1'b0 = operational mode1'b1 = PBIT_mode */
   uint32_t s_reset_secondary : 16; /* Bits : 15:0  : Status of the {reset_secondary} output.                                                            */
}
ts_fpga_reg_iip07_reset_mngt_status_reg_u_bit;

typedef union
{
   uint32_t                                      u_word;
   ts_fpga_reg_iip07_reset_mngt_status_reg_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_status_reg;

/* Group of registers in 'iip07_reset_mngt' named 'status' */
typedef struct
{
   tu_fpga_reg_iip07_reset_mngt_reset_counter_reg     s_reset_counter_reg;
   tu_fpga_reg_iip07_reset_mngt_reset_source_reg      s_reset_source_reg;
   tu_fpga_reg_iip07_reset_mngt_reset_prev_source_reg s_reset_prev_source_reg;
   tu_fpga_reg_iip07_reset_mngt_status_reg            s_status_reg;
}
ts_fpga_reg_iip07_reset_mngt_status;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_reset_secondary_val_set_reg' */
typedef struct
{
   uint32_t s_reserved                : 16; /* Bits : 31:16 : N/A                                                               */
   uint32_t s_reset_secondary_val_set : 16; /* Bits : 15:0  : writting 1'b1 set {reset_secondary_val} corresponding bit to 1'b1 */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_val_set_reg_u_bit;

typedef union
{
   uint32_t                                                       u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_val_set_reg_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_val_set_reg;

/* Union definition for register 's_reset_secondary_val_clear_reg' */
typedef struct
{
   uint32_t s_reserved                  : 16; /* Bits : 31:16 : N/A                                                               */
   uint32_t s_reset_secondary_val_clear : 16; /* Bits : 15:0  : writting 1'b1 set {reset_secondary_val} corresponding bit to 1'b0 */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_val_clear_reg_u_bit;

typedef union
{
   uint32_t                                                         u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_val_clear_reg_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_val_clear_reg;

/* Union definition for register 's_reset_secondary_val_reg' */
typedef struct
{
   uint32_t s_reserved            : 16; /* Bits : 31:16 : N/A                                                                                                                                                                                   */
   uint32_t s_reset_secondary_val : 16; /* Bits : 15:0  : {reset_secondary_val} value direct write. {reset_secondary} is drive to this value only when secure access have been performed in {reset_secondary_key_1} and {reset_secondary_key_2} */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_val_reg_u_bit;

typedef union
{
   uint32_t                                                   u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_val_reg_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_val_reg;

/* Group of registers in 'iip07_reset_mngt' named 'reset_secondary_set_and_clear' */
typedef struct
{
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_val_set_reg   s_reset_secondary_val_set_reg;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_val_clear_reg s_reset_secondary_val_clear_reg;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_val_reg       s_reset_secondary_val_reg;
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_set_and_clear;

/* ------------------------------------------------------------------------------- */

/* Group of registers in 'iip07_reset_mngt' named 'secure_software_access_key1' */
typedef struct
{
   uint32_t s_reset_soft_set_key_1_reg;
   uint32_t s_reset_perm_set_key_1_reg;
   uint32_t s_pbit_mode_set_key_1_reg;
   uint32_t s_pbit_mode_clear_key_1_reg;
   uint32_t s_mdisc_command_n_set_key_1_reg;
   uint32_t s_mdisc_command_n_clear_key_1_reg;
   uint32_t s_reset_secondary_key_1_reg;
}
ts_fpga_reg_iip07_reset_mngt_secure_software_access_key1;

/* ------------------------------------------------------------------------------- */

/* Group of registers in 'iip07_reset_mngt' named 'secure_software_access_key2' */
typedef struct
{
   uint32_t s_reset_soft_set_key_2_reg;
   uint32_t s_reset_perm_set_key_2_reg;
   uint32_t s_pbit_mode_set_key_2_reg;
   uint32_t s_pbit_mode_clear_key_2_reg;
   uint32_t s_mdisc_command_n_set_key_2_reg;
   uint32_t s_mdisc_command_n_clear_key_2_reg;
   uint32_t s_reset_secondary_key_2_reg;
}
ts_fpga_reg_iip07_reset_mngt_secure_software_access_key2;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_reset_secondary_time_reg0' */
typedef struct
{
   uint32_t s_reset_secondary_time[0] : 16; /* Bits : 31:16 : Time of the reset_secondary[0] pulse duration, if set to 0 {reset_secondary}[0] stay at 1'b1 else reset_secondary_time[0]*{ratio_reset_secondary}*{Tclk_xmap} */
   uint32_t s_reset_secondary_time[1] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description                                                                                                                     */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg0_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg0_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg0;

/* Union definition for register 's_reset_secondary_time_reg1' */
typedef struct
{
   uint32_t s_reset_secondary_time[2] : 16; /* Bits : 31:16 : see {reset_secondary_time}[0] description */
   uint32_t s_reset_secondary_time[3] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg1_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg1_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg1;

/* Union definition for register 's_reset_secondary_time_reg2' */
typedef struct
{
   uint32_t s_reset_secondary_time[4] : 16; /* Bits : 31:16 : see {reset_secondary_time}[0] description */
   uint32_t s_reset_secondary_time[5] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg2_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg2_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg2;

/* Union definition for register 's_reset_secondary_time_reg3' */
typedef struct
{
   uint32_t s_reset_secondary_time[6] : 16; /* Bits : 31:16 : see {reset_secondary_time}[0] description */
   uint32_t s_reset_secondary_time[7] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg3_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg3_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg3;

/* Union definition for register 's_reset_secondary_time_reg4' */
typedef struct
{
   uint32_t s_reset_secondary_time[8] : 16; /* Bits : 31:16 : see {reset_secondary_time}[0] description */
   uint32_t s_reset_secondary_time[9] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg4_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg4_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg4;

/* Union definition for register 's_reset_secondary_time_reg5' */
typedef struct
{
   uint32_t s_reset_secondary_time[10] : 16; /* Bits : 31:16 : see {reset_secondary_time}[0] description */
   uint32_t s_reset_secondary_time[11] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg5_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg5_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg5;

/* Union definition for register 's_reset_secondary_time_reg6' */
typedef struct
{
   uint32_t s_reset_secondary_time[12] : 16; /* Bits : 31:16 : see {reset_secondary_time}[0] description */
   uint32_t s_reset_secondary_time[13] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg6_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg6_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg6;

/* Union definition for register 's_reset_secondary_time_reg7' */
typedef struct
{
   uint32_t s_reset_secondary_time[14] : 16; /* Bits : 31:16 : see {reset_secondary_time}[0] description */
   uint32_t s_reset_secondary_time[15] : 16; /* Bits : 15:0  : see {reset_secondary_time}[0] description */
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg7_u_bit;

typedef union
{
   uint32_t                                                     u_word;
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg7_u_bit u_bit;
}
tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg7;

/* Group of registers in 'iip07_reset_mngt' named 'reset_secondary_configuration' */
typedef struct
{
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg0 s_reset_secondary_time_reg0;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg1 s_reset_secondary_time_reg1;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg2 s_reset_secondary_time_reg2;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg3 s_reset_secondary_time_reg3;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg4 s_reset_secondary_time_reg4;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg5 s_reset_secondary_time_reg5;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg6 s_reset_secondary_time_reg6;
   tu_fpga_reg_iip07_reset_mngt_reset_secondary_time_reg7 s_reset_secondary_time_reg7;
}
ts_fpga_reg_iip07_reset_mngt_reset_secondary_configuration;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip07_reset_mngt' */

typedef struct
{
   ts_fpga_reg_iip07_reset_mngt_status                        s_status_regs;
   uint32_t                                                   s_spare_00[4];
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_set_and_clear s_reset_secondary_set_and_clear_regs;
   uint32_t                                                   s_spare_01[5];
   ts_fpga_reg_iip07_reset_mngt_secure_software_access_key1   s_secure_software_access_key1_regs;
   uint32_t                                                   s_spare_02[5];
   ts_fpga_reg_iip07_reset_mngt_secure_software_access_key2   s_secure_software_access_key2_regs;
   uint32_t                                                   s_spare_03[29];
   ts_fpga_reg_iip07_reset_mngt_reset_secondary_configuration s_reset_secondary_configuration_regs;
}
ts_fpga_reg_iip07_reset_mngt;

#endif /* FPGA_REG_IIP07_RESET_MNGT_H */
