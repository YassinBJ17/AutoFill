/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef RESET_PRIVATE_H
#define RESET_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/*-- Generic RESET parameters values --*/
#define RST_INIT_REG_VALUE32                    (reg32_t)0x00000000ULL
#define RST_INIT_REG_BITVALUE32                 (reg32_t)0x00000001ULL

#define RST_INIT_UINT_VALUE32                   (uint32_t)0x00000000ULL
#define RST_INIT_UINT_BITVALUE32                (uint32_t)0x00000001ULL

/*-- Generic RESET commands values --*/
/* Key 1 Commands Values */
#define RST_SW_SET_KEY_1_CMD_VALUE              (reg32_t)0xE1BFA4B3ull
#define RST_PERM_SET_KEY_1_CMD_VALUE            (reg32_t)0x1F86FBFEull
#define RST_PBIT_MODE_SET_KEY_1_CMD_VALUE       (reg32_t)0x1F7A208Eull
#define RST_PBIT_MODE_CLEAR_KEY_1_CMD_VALUE     (reg32_t)0x0148C3BDull
#define RST_MDISC_CMD_N_SET_KEY_1_CMD_VALUE     (reg32_t)0xA5C84B7Dull
#define RST_MDISC_CMD_N_CLEAR_KEY_1_CMD_VALUE   (reg32_t)0x5A37B482ull
#define RST_SECONDARY_KEY_1_CMD_VALUE           (reg32_t)0x7191DFCDull

/* Key 2 Commands Values */
#define RST_SW_SET_KEY_2_CMD_VALUE              (reg32_t)0x9883A742ull
#define RST_PERM_SET_KEY_2_CMD_VALUE            (reg32_t)0x2AE594C0ull
#define RST_PBIT_MODE_SET_KEY_2_CMD_VALUE       (reg32_t)0xD0F4E2F1ull
#define RST_PBIT_MODE_CLEAR_KEY_2_CMD_VALUE     (reg32_t)0xA30122A0ull
#define RST_MDISC_CMD_N_SET_KEY_2_CMD_VALUE     (reg32_t)0x81F57E6Dull
#define RST_MDISC_CMD_N_CLEAR_KEY_2_CMD_VALUE   (reg32_t)0x7E0A8192ull
#define RST_SECONDARY_KEY_2_CMD_VALUE           (reg32_t)0x1157CF9Full


/* ---------- provided types: ----------------------------------------------- */
/* FPGA RESET Register */
typedef struct
{
   /*-- STATUS RESET                   (offset 0x0000_0000)--*/
   reg32_t s_reset_counter;

   reg32_t s_reset_source;

   reg32_t s_reset_prev_source;

   reg32_t s_status;

   /* Empty registers */
   reg32_t s_spare_0x10;
   reg32_t s_spare_0x14;
   reg32_t s_spare_0x18;
   reg32_t s_spare_0x1C;

   /*-- SECONDARY RESET Set and Clear  (offset 0x0000_0020)--*/
   reg32_t s_reset_secondary_val_set;

   reg32_t s_reset_secondary_val_clear;

   reg32_t s_reset_secondary_val_read;

   /* Empty registers */
   reg32_t s_spare_0x2C;
   reg32_t s_spare_0x30;
   reg32_t s_spare_0x34;
   reg32_t s_spare_0x38;
   reg32_t s_spare_0x3C;

   /*-- Secure software access key1    (offset 0x0000_0040)--*/
   reg32_t s_reset_soft_set_key_1;

   reg32_t s_reset_perm_set_key_1;

   reg32_t s_pbit_mode_set_key_1;

   reg32_t s_pbit_mode_clear_key_1;

   reg32_t s_mdisc_command_n_set_key_1;

   reg32_t s_mdisc_command_n_clear_key_1;

   reg32_t s_reset_secondary_key_1;

   /* Empty registers */
   reg32_t s_spare_0x5C;
   reg32_t s_spare_0x60;
   reg32_t s_spare_0x64;
   reg32_t s_spare_0x68;
   reg32_t s_spare_0x6C;

   /*-- Secure software access key2    (offset 0x0000_0070)--*/
   reg32_t s_reset_soft_set_key_2;

   reg32_t s_reset_perm_set_key_2;

   reg32_t s_pbit_mode_set_key_2;

   reg32_t s_pbit_mode_clear_key_2;

   reg32_t s_mdisc_command_n_set_key_2;

   reg32_t s_mdisc_command_n_clear_key_2;

   reg32_t s_reset_secondary_key_2;
}
ts_reset_reg;

/* iip07_reset Status Register from bridge_pld_memory_map */
/*-- Structures from iip07 mapping --*/
typedef struct
{
   uint32_t                       : 8;
   uint32_t s_reset_pbitctr       : 8;
   uint32_t                       : 8;
   uint32_t s_reset_criticalctr   : 8;
}ts_reset_counter;

typedef struct
{
   uint32_t                       :14;
   uint32_t s_reset_xmap          : 1;
   uint32_t s_reset_sw            : 1;
   uint32_t s_reset_criticalxmap  :16;
}ts_reset_source;

typedef struct
{
   uint32_t                       :14;
   uint32_t s_reset_xmap          : 1;
   uint32_t s_reset_sw            : 1;
   uint32_t s_reset_criticalxmap  :16;
}ts_reset_prevsource;

typedef struct
{
   uint32_t                       :14;
   uint32_t s_reset_mdisccommandn : 1;
   uint32_t s_reset_pbitmode      : 1;
   uint32_t s_reset_secondary     :16;
}ts_reset_status;

typedef struct
{
   uint32_t                       :16;
   uint32_t s_reset_valset        :16;
}ts_reset_secondaryvalset;

typedef struct
{
   uint32_t                       :16;
   uint32_t s_reset_valclear      :16;
}ts_reset_secondaryvalclear;

typedef struct
{
   uint32_t                       :16;
   uint32_t s_reset_valkey        :16;
}ts_reset_secondaryvalkey;

/*-- Union registers --*/
typedef union
{
   uint32_t                      u_register;
   ts_reset_counter              u_bit_counter;
   ts_reset_source               u_bit_source;
   ts_reset_prevsource           u_bit_prevsource;
   ts_reset_status               u_bit_status;
   ts_reset_secondaryvalset      u_bit_secondaryvalset;
   ts_reset_secondaryvalclear    u_bit_secondaryvalclear;
   ts_reset_secondaryvalkey      u_bit_secondaryvalkey;
}tu_reset_cmd;

/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */



#endif /* RESET_PRIVATE_H */
