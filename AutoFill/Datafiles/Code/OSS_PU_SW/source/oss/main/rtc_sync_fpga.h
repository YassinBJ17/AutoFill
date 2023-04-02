/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef RTC_SYNC_FPGA_H
#define RTC_SYNC_FPGA_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* Bits field for FPGA 'SW synchronization command register' */
typedef struct
{
   uint32_t s_spare_31_to_02 : 30;                   /* 31 to 02 : Spare */
   uint32_t s_sync_cmd       : 1;                    /* Bit 1 : Synchronization command */
   uint32_t s_raz_mf_activ   : 1;                    /* Bit 0 : RAZ command */
}
ts_sync_cmd_fpga_reg_type;

/* FPGA 'SW synchronization command register' */
typedef union
{
   uint32_t                  u_word;             /* Smot control register accessed by 32-bit word */
   ts_sync_cmd_fpga_reg_type u_bit;              /* Smot control register accessed field by field */
}
tu_sync_cmd_fpga_reg_type;

/* FPGA smot common register */
typedef struct
{
   tu_sync_cmd_fpga_reg_type s_sync_cmd_reg;         /* Sync command register */
}
ts_rtc_sync_fpga_reg;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* FPGA sync common register */
extern ts_rtc_sync_fpga_reg * rtc_sync_fpga_reg;

#endif /* RTC_SYNC_FPGA_H */
