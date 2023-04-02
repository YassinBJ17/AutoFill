/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ACCOM_FPGA_COMMON_H
#define ACCOM_FPGA_COMMON_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#define ACCOM_CST_PREF_KEY_SET      ((uint32_t) 0x2E702E70U)
#define ACCOM_CST_PREF_KEY_CLEAR    ((uint32_t) 0xA5A5A5A5U)

#define ACCOM_CST_UNABLE_KEY_SET    ((uint32_t) 0xAAAAAAAAU)
#define ACCOM_CST_UNABLE_KEY_CLEAR  ((uint32_t) 0x55555555U)

#define ACCOM_CST_REFUSAL_KEY_SET   ((uint32_t) 0x04EF04EFU)
#define ACCOM_CST_REFUSAL_KEY_CLEAR ((uint32_t) 0xC1EAC1EAU)

/* Keys needed for initializing Smot and Tmot */
#define DISCONNECT_CLEAR_KEY_1  (uint32_t)0x4930D19C
#define DISCONNECT_CLEAR_KEY_2  (uint32_t)0xBD9378C7
#define DISABLE_CLEAR_KEY_1     (uint32_t)0xC369FE09
#define DISABLE_CLEAR_KEY_2     (uint32_t)0xAF638D76

#define ACCOM_DEACTIVATED ((uint8_t) 0u) /* Enables  FORCE_DISCONNECTION signal */
#define ACCOM_ACTIVATED   ((uint8_t) 1u) /* Disables FORCE_DISCONNECTION signal */

/* ---------- provided types: ----------------------------------------------- */

/* Bit field of FPGA ACCOM status register */
typedef struct
{
   reg32_t s_spare_31_to_23     : 9;       /* 31 to 23 : Spare */
   reg32_t s_ibit_status        : 1;       /* 22 : ibit status */
   reg32_t s_select             : 1;       /* 21 : select bit */
   reg32_t s_freeze_sm_n        : 1;       /* 20 : freeze_sm_n output bit */
   reg32_t s_inconsistent_fault : 1;       /* 19 : inconsistency fault*/
   reg32_t s_channel_sel        : 1;       /* 18 : channel selected bit */
   reg32_t s_channel_id1        : 1;       /* 17 : channel_id1 = channel A info */
   reg32_t s_channel_id0        : 1;       /* 16 : channel_id0 = channel B info */
   reg32_t s_spare_15           : 1;       /* 15 : spare */
   reg32_t s_opp_inconsistent   : 1;       /* 14 : accom_opp_inconsistent input bit */
   reg32_t s_opp_inconsistent_n : 1;       /* 13 : accom_opp_inconsistent_n input bit */
   reg32_t s_loc_health_word    : 5;       /* 12 to 08 : Local Health word status */
   reg32_t s_spare_07_to_05     : 3;       /* 07 to 05 spare*/
   reg32_t s_opp_health_word    : 5;       /* 04 to 00 : opposite health word status */
}
ts_accom_status_bit_type;

/* FPGA ACCOM status register */
typedef union
{
   ts_accom_status_bit_type u_field;     /* FPGA local parameter register accessed field by field */
   uint32_t u_word;                      /* FPGA local parameter register word accessed by 32-bit word */
}
tu_accom_status_reg_type;

/* Bits field of FPGA ACCOM local parameter register */
typedef struct
{
   reg32_t s_spare_31_to_03  : 29;  /* 31 to 03: Spare */
   reg32_t s_unable          : 1;   /* 01 : unable bit */
   reg32_t s_refusal         : 1;   /* 01 : refusal bit */
   reg32_t s_pref            : 1;   /* 01 : pref bit */
}
ts_accom_local_param_bit_type;

/* FPGA ACCOM local parameter register */
typedef union
{
   ts_accom_local_param_bit_type u_field; /* FPGA local parameter register accessed field by field */
   uint32_t u_word;                       /* FPGA local parameter register word accessed by 32-bit word */
}
tu_accom_local_param_reg_type;

/* Bit field of FPGA ACCOM tmot configuration register */
typedef struct
{
   reg32_t s_spare_31_to_02  : 30;  /* 31 to 02: Spare */
   reg32_t s_freeze_sm_n_ibit: 1;   /* 01 : freeze_sm_n_ibit is used to force freeze_sm_n output value when ibit_status = '1' */
   reg32_t s_tmot_cfg        : 1;   /* 00 : Tmot CONFIGURATION bit */
}
ts_accom_tmot_conf_bit_type;

/* FPGA ACCOM tmot registers */
typedef union
{
   ts_accom_tmot_conf_bit_type u_field;   /* FPGA tmot configuration register accessed field by field */
   uint32_t u_word;                       /* FPGA tmot configuration register word accessed by 32-bit word */

}
tu_accom_tmot_config_reg_type;

/* FPGA ACCOM configuration registers */
typedef struct
{
   uint32_t s_local_unable_key;                 /* local unable key register*/
   uint32_t s_local_refusal_key;                /* local disable key register*/
   uint32_t s_local_pref_key;                   /* local pref key register*/
   tu_accom_local_param_reg_type s_loc_param;   /* local parameter register */
   tu_accom_tmot_config_reg_type s_tmot_conf;   /* TMOT configuration register*/
   uint32_t s_ibit_key;                         /* sets ibit_status to 1'b1 when 0x215D_0A3B is written here ; or to 1'b0 when 0x96D0_43CB is written */
}
ts_accom_conf_reg_type;

/* FPGA ACCOM Disconnect / disable register type */
typedef struct
{
   uint32_t s_disconnect_set_key_1;             /* disconnect set key 1*/
   uint32_t s_disconnect_set_key_2;             /* disconnect set key 2*/
   uint32_t s_disconnect_clear_key_1;           /* disconnect clear key 1*/
   uint32_t s_disconnect_clear_key_2;           /* disconnect clear key 2*/
   uint32_t s_disable_set_key_1;                /* disable set key 1*/
   uint32_t s_disable_set_key_2;                /* disable set key 2*/
   uint32_t s_disable_clear_key_1;              /* disable clear key 1*/
   uint32_t s_disable_clear_key_2;              /* disable clear key 2*/
}
ts_accom_dis_reg_type;

typedef struct
{
   ts_accom_conf_reg_type s_conf_reg;                /* Configuration registers */
   tu_accom_status_reg_type s_status_reg;            /* Status register */
   ts_accom_dis_reg_type s_dis_reg;                  /* Disconnect/disable registers*/
}
ts_accom_fpga_reg_type;


/* FPGA register to access the synchronization status */
typedef struct
{
   reg32_t s_spare_31_to_04   : 28; /* 31 to 04: Spare */
   reg32_t s_sync_ok          :  1; /* 03 : 1 if the RTC is synchronized */
   reg32_t s_sync_timeout_sts :  1; /* 02 : Timeout-threshold synchronization flag */
   reg32_t s_sync_high_sts    :  1; /* 01 :    High-threshold synchronization flag */
   reg32_t s_sync_low_sts     :  1; /* 00 :     Low-threshold synchronization flag */
}
ts_accom_fpga_ip02_rtc_sync_status_reg;

/* FPGA register to access the synchronization status */
typedef union
{
   ts_accom_fpga_ip02_rtc_sync_status_reg s_bit;
   uint32_t u_word;
}
tu_accom_fpga_ip02_rtc_sync_status_reg;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* FPGA register for accomodation */
extern ts_accom_fpga_reg_type * const accom_fpga_reg;
extern tu_accom_fpga_ip02_rtc_sync_status_reg * const sync_sts_reg;

#endif /* ACCOM_FPGA_COMMON_H */
