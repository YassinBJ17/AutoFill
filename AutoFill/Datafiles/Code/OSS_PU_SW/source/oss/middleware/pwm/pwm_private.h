/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"
#include "memory/memory_address_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* PWM space adress in FPGA */
#define PWM_FPGA_ADDR                  ((ts_pwm *)(FPGA_MEMORY_ADDR + 0x00050000))

/* PWM MON space address in FPGA */
#define PWM_IMON_FPGA_ADDR             ((ts_pwm_imon *)(FPGA_MEMORY_ADDR + 0x00064000))

#define PWM_CONVERTER                  ((float32_t)66666.65)

#define PWM_CONVERTED_PERIOD           ((uint32_t)0x00145855)  /* 20ms */

#define PWM_CONVERTED_FBK_PERIOD_MIN   ((uint32_t)0x00124F7F)  /* 18ms */
#define PWM_CONVERTED_FBK_PERIOD_MAX   ((uint32_t)0x0016612A)  /* 22ms */

#define PWM_RATIO_MIN                  ((float32_t)0.1f)
#define PWM_RATIO_MAX                  ((float32_t)0.9f)

#define PWM_CONVERTED_HIGH_TIME_INIT   ((uint32_t)0x000208D5)  /* CONVERTED_PERIOD * MIN_RATIO = 0x145855 * 0.1 */

#define PWM_DISABLE_VALUE              ((uint32_t)0)
#define PWM_ENABLE_VALUE               ((uint32_t)1)

/* ---------- provided types: ----------------------------------------------- */
/* Bits field of IP identification register */
typedef struct
{
   uint32_t s_spare_31_to_16  :16;  /* 31 to 16: Read 0 */
   uint32_t s_ip_id           :8;   /* 15 to 08: IP identifier number */
   uint32_t s_ip_ver          :8;   /* 07 to 00: IP version number */
}
ts_pwm_ident_reg_u_bit;

/* IP identification register */
typedef union
{
   uint32_t                u_word;  /* IP identification register accessed by 32-bit word */
   ts_pwm_ident_reg_u_bit  u_bit;   /* IP identification register accessed bit by bit */
}
tu_pwm_ident_reg;

/* Bits field of PWM Period Configuration register */
typedef struct
{
   uint32_t s_spare_31_to_24     :8;   /* 31 to 24: Read 0 */
   uint32_t s_pwm_period         :24;  /* 23 to 00: PWM period value expressed in {clk} clock period */
}
ts_pwm_period_reg_u_bit;

/* PWM Period Configuration register */
typedef union
{
   uint32_t                u_word;  /* PWM Period Configuration register accessed by 32-bit word */
   ts_pwm_period_reg_u_bit u_bit;   /* PWM Period Configuration register accessed bit by bit */
}
tu_pwm_period_reg;

/* Bits field of PWM High time Configuration register */
typedef struct
{
   uint32_t s_spare_32_to_24     :8;   /* 31 to 24: Read 0 */
   uint32_t s_pwm_high_time      :24;  /* 23 to 00: PWM high state duration expressed in {clk} clock period */
}
ts_pwm_high_time_reg_u_bit;

/* PWM High time Configuration register */
typedef union
{
   uint32_t                   u_word;  /* PWM High time Configuration register accessed by 32-bit word */
   ts_pwm_high_time_reg_u_bit u_bit;   /* PWM High time Configuration register accessed bit by bit */
}
tu_pwm_high_time_reg;

/* Bits field of Command register */
typedef struct
{
   uint32_t s_spare_31_to_01  :31;  /* 31 to 01: Read 0 */
   uint32_t s_pwm_en          :1;   /* 00: Enables the PWM output generation */
}
ts_pwm_command_reg_u_bit;

/* Command register */
typedef union
{
   uint32_t                   u_word;  /* Command register accessed by 32-bit word */
   ts_pwm_command_reg_u_bit   u_bit;   /* Command register accessed bit by bit */
}
tu_pwm_command_reg;

/* PWM FPGA registers */
typedef struct
{
   tu_pwm_ident_reg     s_ident;       /* IP identification register */
   tu_pwm_period_reg    s_period;      /* PWM Period Configuration register */
   tu_pwm_high_time_reg s_high_time;   /* PWM High time Configuration register */
   tu_pwm_command_reg   s_command;     /* Command register */
}
ts_pwm;

/* Bits field of PWM IMON period register */
typedef struct
{
   uint32_t s_spare_31_to_24     :8;   /* 31 to 24: Not used */
   uint32_t s_pwm_imon_period    :24;  /* 23 to 00: PWM IMON period value expressed in {clk_mpc} clock period */
}
ts_pwm_imon_period_reg_u_bit;

/* PWM IMON period register */
typedef union
{
   uint32_t                      u_word;  /* PWM IMON period register accessed by 32-bit word */
   ts_pwm_imon_period_reg_u_bit  u_bit;   /* PWM IMON period register accessed bit by bit */
}
tu_pwm_imon_period_reg;

/* Bits field of PWM IMON high time register */
typedef struct
{
   uint32_t s_spare_31_to_24     :8;   /* 31 to 24: Not used */
   uint32_t s_pwm_imon_high_time :24;  /* 23 to 00: PWM IMON high state duration expressed in {clk_mpc} clock period */
}
ts_pwm_imon_high_time_reg_u_bit;

/* PWM IMON high time register */
typedef union
{
   uint32_t                         u_word;  /* PWM IMON high time register accessed by 32-bit word */
   ts_pwm_imon_high_time_reg_u_bit  u_bit;   /* PWM IMON high time register accessed bit by bit */
}
tu_pwm_imon_high_time_reg;

/* PWM IMON FPGA registers */
typedef struct
{
   tu_pwm_imon_period_reg     s_imon_period;    /* PWM IMON period register */
   tu_pwm_imon_high_time_reg  s_imon_high_time; /* PWM IMON high time register */
}
ts_pwm_imon;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* GPIO manipulation */
extern reg8_t      *pwm_gpio_enable;

/* FPGA registers for PWM */
extern ts_pwm      *pwm_fpga;

/* FPGA registers for PWM IMON */
extern ts_pwm_imon *pwm_imon_fpga;

/* ---------- provided operations: ------------------------------------------ */

#endif /* PWM_PRIVATE_H */
