/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef POWERSUP_PRIVATE_H
#define POWERSUP_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"
#include "memory/oss_section_def_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- provided define constants: ------------------------------------ */
/* TODO - For testing code */
#define CMD_ALT_REARM_TEST            (uint32_t)1
#define AC_VOLTAGE_NOM_TEST           (float32_t)28.0
#define CONST_RTC_LIMIT               (uint32_t)10
#define POWERSUP_INIT_VALUE           (uint32_t)0

/* Maximum alternator speed frequency in order to filter the CBIT fault word (Hz)*/
#define PWSUP_NGALT_HIGH_FREQ         (float32_t)330.0
#define PWSUP_NULL_CALCULUS           (float32_t)0.0

/* Number of RTC where A/C voltage is out of range, needed to trigger fault in fault word  */
#define NB_RTC_AC_FAULTY              (uint32_t)0

/* Maximum voltage for 28V A/C */
#define AC_VOLTAGE_MAX                (float32_t)32.0
/* (DEC)32.0 x (DEC)2^(12) x 1/(DEC)5 x (DEC)0,048 = (DEC) 1258 */
/*        ^                                        = (HEX) 055A */
/*        L MAX Voltage limit                                   */
#define HEX_VOLTAGE_MAX               (uint16_t)0x055A

/* Minimum voltage for 28V A/C */
#define AC_VOLTAGE_MIN                (float32_t)16.0
/* (DEC)16.0 x (DEC)2^(12) x 1/(DEC)5 x (DEC)0,048 = (DEC)  630 */
/*        ^                                        = (HEX) 0276 */
/*        L MIN Voltage limit                                   */
#define HEX_VOLTAGE_MIN               (uint16_t)0x0256

/* Emergency minimum voltage for 28V A/C */
#define AC_EMERG_VOLTAGE_MIN          (float32_t)10.0
/* (DEC)10.0 x (DEC)2^(12) x 1/(DEC)5 x (DEC)0,048 = (DEC)  394 */
/*        ^                                        = (HEX) 018A */
/*        L MIN Voltage limit                                   */
#define HEX_EMERG_VOLTAGE_MIN         (uint16_t)0x0176

#define C_CBIT_FREQ_NGALT              (float32_t)200.0

/* Extracted from Table 5-2. Peripheral (PBRIDGE_A, PBRIDGE_B) memory map */
/* System Integration Unit Lite 2 (SIUL2) */
/* Extract from 16.2 SIUL2 memory map - GPIO 197, opposite channel power state - 8bits */
#define GPIO_OPP_CHANNEL_PW_STATE     (uint32_t)(0xFFFC0000 + 0x000013C5)

#define GPDO_197_POR_OPP_N            (reg8_t*)(0xFFFC13C5)
#define GPDI_197_POR_OPP_N            (reg8_t*)(0xFFFC15C5)

/* GPIO access for rearm ALTERNATOR */
#define GPDO_205_REARM_PMA            (reg8_t*)(0xFFFC13CD)
#define GPDI_205_REARM_PMA            (reg8_t*)(0xFFFC15CD)

/* I2C line 0 */
#define I2C0_LINE                     (uint8_t)0

/* I2C0 Baudrate of 91 */
#define I2C0_BAUD                     (uint8_t)0x5B

/* I2C0 IO Expanders Address */
#define I2C0_IO_EXP_PIB_A_B_ADD       (uint8_t)0b01001000
#define I2C0_IO_EXP_PIB_A_START_ADD   (uint8_t)0b01000010
#define I2C0_IO_EXP_PIB_A_END_ADD     (uint8_t)0b01000100
#define I2C0_IO_EXP_PIB_B_START_ADD   (uint8_t)0b01001010
#define I2C0_IO_EXP_PIB_B_END_ADD     (uint8_t)0b01001100

/* I2C0 IO Expanders commands */
#define I2C0_INIT_WRITE_CMD           (uint8_t)0x06
#define I2C0_CMD                      (uint8_t)0x02

/* I2C0 IO Expanders messages */
#define I2C0_INIT_PIB_A_B_MSG         (uint16_t)0xDFFD
#define I2C0_INIT_PIB_A_START_MSG     (uint16_t)0x00F9
#define I2C0_INIT_PIB_A_END_MSG       (uint16_t)0x03FD
#define I2C0_INIT_PIB_B_START_MSG     (uint16_t)0xAAFD
#define I2C0_INIT_PIB_B_END_MSG       (uint16_t)0xAAFD

/* ---------- provided types: ----------------------------------------------- */
/* I2C0 IO Expander address 0x01001000 structure */
typedef struct
{
   uint16_t s_en_boost             : 1;   /* 15: P0-7 PBIT monitoring for boost     (MSB) */
   uint16_t s_p5v_serv_mon         : 1;   /* 14: P0-6 P5V_SERV monitoring for OVD and UVD */
   uint16_t s_hp4_cmd              : 1;   /* 13: P0-5 HP4 output command                  */
   uint16_t s_spare_12_to_08       : 5;   /* 12 to 08 : Spare                             */
   uint16_t s_ac_disc_cmd          : 1;   /* 07: P1-7 BSIS 28V_DISC_CMD                   */
   uint16_t s_ngatl_oc_stat        : 1;   /* 06: P1-6 NGALT_OC_STATUS_N                   */
   uint16_t s_ngalt_cc_stat        : 1;   /* 05: P1-5 NGALT_CC_STATUS_N                   */
   uint16_t s_ac_glob_switch_fault : 1;   /* 04: P1-4 28V_SWITCH_FAULT_N                  */
   uint16_t s_ac_hs_switch_stat    : 1;   /* 03: P1-3 28VHS_SWITCH_STATUS                 */
   uint16_t s_ac_ls_switch_stat    : 1;   /* 02: P1-2 28VLS_SWITCH_STATUS                 */
   uint16_t s_io_11                : 1;   /* 01: P1-1 N/A                                 */
   uint16_t s_io_10                : 1;   /* 00: P1-0 N/A                           (LSB) */
}
ts_io_expanders_u_bit;

/* i2c0 address 0x01001000 union */
typedef union
{
   uint16_t              u_word;   /* i2c0 address 0x01001000 accessed by 16-bit word */
   ts_io_expanders_u_bit u_bit;    /* i2c0 address 0x01001000 accessed bit by bit */
}
tu_i2c0;

/* Re arming act */
typedef enum
{
   e_rearm_no  = 0ul,
   e_rearm_yes = 1ul
}te_powersup_rearm;

/* Enumerate error type */
typedef enum
{
   e_no_fault    = 0ul,
   e_low_fault   = 1ul,
   e_high_fault  = 2ul
}te_powersup_err_type;

/* Bite field fault value error */
typedef struct
{
   uint32_t     s_nb_rtc_hs_er      : 16;
   uint32_t     s_nb_rtc_ls_er      : 16;
}ts_powersup_err_bit;

/* Union bit field */
typedef union
{
   uint32_t            u_word;
   ts_powersup_err_bit u_bit;
}tu_powersup_err;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Global fault error value */
/* XXXX  XXXX  => Value in HEX on 8 octet                */
/*    ^     ^                                            */
/*    |     |---> NB of RTC in voltage low level error   */
/*    |---------> NB of RTC in voltage high level error  */
extern tu_powersup_err V_POWERSUP_ERROR_RTC;

/* -------------------------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Acquire power supply I2C discret and convert 28v voltage */
extern void powersup_get(
      const boolean_t           channel_is_a,
      tu_i2c0 *           const pu_i2c0,
      uint32_t*           const p_i2c0_err,
      uint16_t*           const p_voltage,
      float32_t*          const p_alt_freq_meas,
      te_powersup_rearm*  const p_rearm_mode);

/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Monitor 28v voltage */
extern void powersup_monitor(
      /* INPUT */
      const uint16_t *    const p_voltage);

/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Monitor 28v voltage */
extern void powersup_transmit(
      uint32_t*          const c_alt_fault_word,
      uint32_t*          const c_28v_fault_word);

/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Acquire power supply discrete and perform CBIT */
extern void powersup_cbit(
      /* Inputs value */
      const tu_i2c0 *       const i2c0,
      const uint32_t*       const p_i2c0_err,
      const uint16_t*       const p_voltage,
      const float32_t*      const p_alt_freq_meas,
      /* Output values */
      tu_pw_alt_fault_word* const c_alt_fault_word,
      tu_pw_28v_fault_word* const c_28v_fault_word);

/* Implements REQ_FADEX_OS_SRD-POWERSUP-0020 */
/* Powersup alternator rearm service */
extern void powersup_alt_rearm(void);

#endif /* POWERSUP_PRIVATE_H */
