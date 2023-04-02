/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SMOT_FPGA_REG_COMMON_H
#define SMOT_FPGA_REG_COMMON_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Bits field of the FPGA smot command register */
typedef struct
{
   uint32_t s_spare_31_to_6 : 26;                    /* 31 to 6: Spare */
   uint32_t s_inc_sign : 1;                          /* Bit 5 : Smot increment sign */
   uint32_t s_inc_cmd : 5;                           /* 4 to 0 : Smot number of increment command */

}ts_smot_cmd_fpga_bit_type;

/* FPGA smot command register */
typedef union
{
   uint32_t u_word;                                  /* Smot command register accessed by 32-bit word */
   ts_smot_cmd_fpga_bit_type u_bit;                  /* Smot command register accessed field by field */

}tu_smot_cmd_fpga_reg_type;

/* Bits field of FPGA smot configuration register */
typedef struct
{
   uint32_t s_spare_31_to_10 : 22;                   /* 31 to 10 : Spare */
   uint32_t s_tech : 10;                             /* 9 to 0 : Duration of each transitory position */

}ts_smot_conf_fpga_bit_type;

/* FPGA smot configuration register */
typedef union
{
   uint32_t u_word;                                  /* Smot configuration register accessed by 32-bit word */
   ts_smot_conf_fpga_bit_type u_bit;                 /* Smot configuration register accessed field by field */

}tu_smot_conf_fpga_reg_type;

/* Bits field of FPGA smot control register */
typedef struct
{
   uint32_t s_spare_31_to_1 : 31;                    /* 31 to 1 : Spare */
   uint32_t s_error_ack : 1;                         /* Bit 1 : Smot error acknowledge command */

}ts_smot_control_fpga_bit_type;

/* FPGA smot control register */
typedef union
{
   uint32_t u_word;                                  /* Smot control register accessed by 32-bit word */
   ts_smot_control_fpga_bit_type u_bit;              /* Smot control register accessed field by field */

}tu_smot_control_fpga_reg_type;

/* Bits field of FPGA smot status register */
typedef struct
{
   uint32_t s_spare_31_to_27 : 5;                    /* 31 to 27 : Spare */
   uint32_t s_smot_position : 3;                     /* 26 to 24 : Smot position (8 positions from 0 to 7) */
   uint32_t s_spare_23_to_20 : 4;                    /* 23 to 20 : Spare */
   uint32_t s_smot_cmd_status : 4;                   /* 19 to 16 : Smot command output states */
   uint32_t s_spare_15_to_2 : 13;                    /* 15 to 2 : Spare */
   uint32_t s_smot_busy : 1;                           /* Bit 1 : Smot busy indicator */
   uint32_t s_smot_error : 1;                          /* Bit 0 : Smot error indicator */

}ts_smot_status_fpga_bit_type;

/* FPGA smot status register */
typedef union
{
   uint32_t u_word;                                  /* Smot status register accessed by 32-bit word */
   ts_smot_status_fpga_bit_type u_bit;               /* Smot status register accessed field by field */

}tu_smot_status_fpga_reg_type;

/* FPGA smot common register */
typedef struct
{
   tu_smot_cmd_fpga_reg_type s_smot_cmd_reg;           /* Smot command register */
   tu_smot_conf_fpga_reg_type s_smot_conf_reg;         /* Smot configuration register */
   tu_smot_control_fpga_reg_type s_smot_control_reg;   /* Smot control register */
   tu_smot_status_fpga_reg_type s_smot_status_reg;     /* Smot status register */

}ts_smot_fpga_reg;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* FPGA smot common register */
extern ts_smot_fpga_reg *smot_fpga_reg;


#endif /* SMOT_FPGA_REG_COMMON_H */
