/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef TMOT_FPGA_REG_COMMON_H
#define TMOT_FPGA_REG_COMMON_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Bits field of FPGA tmot register */
typedef struct
{
   uint32_t s_spare_31_to_28 : 4;                    /* 31 to 28: Spare */
   uint32_t s_dac_cmd : 12;                          /* 27 to 16: Digital to Analog Converter */
   uint32_t s_spare_15_to_12 : 4;                    /* 15 to 12: Spare */
   uint32_t s_voltage_cmd: 12;                       /* 11 to 0: Tm voltage command */

}
ts_tmot_fpga_bit_type;

/* FPGA tmot register */
typedef union
{
   ts_tmot_fpga_bit_type u_field;                       /* FPGA tmot register accessed field by field */
   uint32_t u_word;                                     /* FPGA tmot register word accessed by 32-bit word */

}
tu_tmot_fpga_reg_type;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* FPGA tmot register */
extern tu_tmot_fpga_reg_type *tmot_fpga_reg;

#endif /* TMOT_FPGA_REG_COMMON_H */
