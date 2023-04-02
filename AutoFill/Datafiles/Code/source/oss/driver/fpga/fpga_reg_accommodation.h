/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_ACCOMMODATION_H
#define FPGA_REG_ACCOMMODATION_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_accom_local_reg' */
typedef struct
{
   uint32_t s_spare_31_to_3 : 29; /* Bits : 31:3 :                               */
   uint32_t s_accom_unable  :  1; /* Bits : 02   : Accomodation local parameters */
   uint32_t s_accom_refusal :  1; /* Bits : 01   :                               */
   uint32_t s_accom_pref    :  1; /* Bits : 00   :                               */
}
ts_fpga_reg_accommodation_accom_local_reg_u_bit;

typedef union
{
   uint32_t                                        u_word;
   ts_fpga_reg_accommodation_accom_local_reg_u_bit u_bit;
}
tu_fpga_reg_accommodation_accom_local_reg;

/* Union definition for register 's_tmot_cfg_reg' */
typedef struct
{
   uint32_t s_spare_31_to_1 : 31; /* Bits : 31:1 :                                                                                 */
   uint32_t s_tmot_cfg      :  1; /* Bits : 00   : TMOT Configuration:'0': tm_disconnect_n = '1''1': tm_disconnect_n = freeze_sm_n */
}
ts_fpga_reg_accommodation_tmot_cfg_reg_u_bit;

typedef union
{
   uint32_t                                     u_word;
   ts_fpga_reg_accommodation_tmot_cfg_reg_u_bit u_bit;
}
tu_fpga_reg_accommodation_tmot_cfg_reg;

/* Group of registers in 'Accommodation' named 'configuration_registers' */
typedef struct
{
   uint32_t                                  s_local_unable_key_reg;
   uint32_t                                  s_local_refusal_key_reg;
   uint32_t                                  s_local_pref_key_reg;
   tu_fpga_reg_accommodation_accom_local_reg s_accom_local_reg;
   tu_fpga_reg_accommodation_tmot_cfg_reg    s_tmot_cfg_reg;
}
ts_fpga_reg_accommodation_configuration_registers;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_status_reg' */
typedef struct
{
   uint32_t s_spare_31_to_22           : 10; /* Bits : 31:22 :                                                                                                                                                                                      */
   uint32_t s_select                   :  1; /* Bits : 21    : select input                                                                                                                                                                         */
   uint32_t s_freeze_sm_n              :  1; /* Bits : 20    : freeze_sm_n output                                                                                                                                                                   */
   uint32_t s_accom_inconsistent_fault :  1; /* Bits : 19    : Inconsistency fault:'0': no inconsistency between accom_opp_inconsistent and accom_opp_inconsistent_n'1':  inconsistency between accom_opp_inconsistent and accom_opp_inconsistent_n */
   uint32_t s_channel_sel              :  1; /* Bits : 18    : Channel selected:'0': Channel A'1': Channel B                                                                                                                                        */
   uint32_t s_channel_id_latch         :  2; /* Bits : 17:16 : channel_id input is stored in channel_id_latch when por_n de-assertion                                                                                                               */
   uint32_t s_Not used                 :  1; /* Bits : 15    :                                                                                                                                                                                      */
   uint32_t s_accom_opp_inconsistent   :  1; /* Bits : 14    : accom_opp_inconsistent input                                                                                                                                                         */
   uint32_t s_accom_opp_inconsistent_n :  1; /* Bits : 13    : accom_opp_inconsistent_n input                                                                                                                                                       */
   uint32_t s_loc_health_word          :  5; /* Bits : 12:8  : Local Health word status                                                                                                                                                             */
   uint32_t s_spare_7_to_5             :  3; /* Bits : 7:5   :                                                                                                                                                                                      */
   uint32_t s_opp_health_word          :  5; /* Bits : 4:0   : Opposite Health word status                                                                                                                                                          */
}
ts_fpga_reg_accommodation_status_reg_u_bit;

typedef union
{
   uint32_t                                   u_word;
   ts_fpga_reg_accommodation_status_reg_u_bit u_bit;
}
tu_fpga_reg_accommodation_status_reg;

/* Group of registers in 'Accommodation' named 'status_registers' */
typedef struct
{
   tu_fpga_reg_accommodation_status_reg s_status_reg;
}
ts_fpga_reg_accommodation_status_registers;

/* ------------------------------------------------------------------------------- */

/* Group of registers in 'Accommodation' named 'disconnect_disable_registers' */
typedef struct
{
   uint32_t s_disconnect_set_key_1;
   uint32_t s_disconnect_set_key_2;
   uint32_t s_disconnect_clear_key_1;
   uint32_t s_disconnect_clear_key_2;
   uint32_t s_disable_set_key_1;
   uint32_t s_disable_set_key_2;
   uint32_t s_disable_clear_key_1;
   uint32_t s_disable_clear_key_2;
}
ts_fpga_reg_accommodation_disconnect_disable_registers;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'Accommodation' */

typedef struct
{
   ts_fpga_reg_accommodation_configuration_registers      s_configuration_registers_regs;
   ts_fpga_reg_accommodation_status_registers             s_status_registers_regs;
   ts_fpga_reg_accommodation_disconnect_disable_registers s_disconnect_disable_registers_regs;
}
ts_fpga_reg_accommodation;

#endif /* FPGA_REG_ACCOMMODATION_H */
