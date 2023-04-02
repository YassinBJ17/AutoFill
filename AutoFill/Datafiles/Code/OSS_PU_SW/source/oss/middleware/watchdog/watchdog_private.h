/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef WATCHDOG_PRIVATE_H
#define WATCHDOG_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* WATCHDOG iip address */
#define K_WATCHDOG_REG_ADDR          (reg32_t)0x24024000

/*-- Generic watchdog parameters values --*/
#define WD_INIT_REG_VALUE32          (reg32_t)0x00000000
#define WD_INIT_REG_BITVALUE32       (reg32_t)0x00000001

#define WD_INIT_UINT_VALUE32         (uint32_t)0x00000000
#define WD_INIT_UINT_BITVALUE32      (uint32_t)0x00000001

#define WD_INIT_UINT_VALUE16         (uint16_t)0x0000

#define WD_NOFAIL_REPPORT            (uint32_t)0x00000000
#define WD_FAIL_BIT1                 (uint32_t)0x00000001

/*-- WATCHDOG MODE Values --*/
#define WD_OPERMODE_VALUE32          (uint32_t)0xFFFFFFFF
#define WD_INIT_MODE_CMD_VALUE       (reg32_t)0xB5D38F53

/*-- WATCHDOG REFRESH COMMAND Values --*/
#define WD_REFRESH_CMD_VALUE         (reg32_t)0xC6F49BA3

/*-- WATCHDOG ARM COMMAND Values --*/
#define WD_ARM_CMD_VALUE             (reg32_t)0x1F6EC8A2

/*-- WATCHDOG TIMER REFRESH COUNTER Values --*/
#define K_CBIT_WDG_MAX_COUNTER_UINT32VALUE (uint32_t)0x0000FFFF
#define K_CBIT_WDG_MAX_COUNTER_UINT16VALUE (uint16_t)0xFFFF

/*-- IRQ Values --*/
#define WD_IRQ_ENABLE_CMD_VALUE        (reg32_t)0x00000001
#define WD_IRQ_DISABLE_CMD_VALUE       (reg32_t)0x00000002
#define WD_IRQ_ACK_CMD_VALUE           (reg32_t)0x00000004

/*-- WATCHDOG inhibit Values --*/
#define WD_INIT_TIMER_INHIBIT_1_CMD_VALUE (reg32_t)0x1AD5C38C
#define WD_INIT_TIMER_INHIBIT_2_CMD_VALUE (reg32_t)0xFE64C79D


/* Initial watchdog parameters in original bit*/
#define WD_MAX_ARM_COUNTER_VALUE       (reg8_t)0xFF
#define WD_MAX_INIT_TIME_START_VALUE   (reg16_t)0x0578
#define WD_MAX_INIT_TIME_OPER_VALUE    (reg16_t)0x0FA0
#define WD_MAX_FAILURE_START_VALUE     (reg8_t)0xFF
#define WD_MAX_FAILURE_OPER_VALUE      (reg8_t)0xFF
#define WD_MIN_WINDOW_TIME_16VALUE     (reg16_t)0x264A
#define WD_MAX_WINDOW_TIME_16VALUE     (reg16_t)0x27D6
#define WD_HRESET_DELAY_VALUE          (reg16_t)0x0000

/* Initial watchdog parameters in 32bit*/
#define WD_MAX_ARM_COUNTER_32VALUE     (reg32_t)0x000000FF
#define WD_MAX_INIT_TIME_START_32VALUE (reg32_t)0x00000578
#define WD_MAX_INIT_TIME_OPER_32VALUE  (reg32_t)0x00000FA0
#define WD_MAX_FAILURE_START_32VALUE   (reg32_t)0x000000FF
#define WD_MAX_FAILURE_OPER_32VALUE    (reg32_t)0x000000FF
#define WD_MIN_WINDOW_TIME_32VALUE     (reg32_t)0x0000264A
#define WD_MAX_WINDOW_TIME_32VALUE     (reg32_t)0x000027D6
#define WD_HRESET_DELAY_32VALUE        (reg32_t)0x00000000


/* Operational watchdog parameters in 32bit*/
/* Count of transitions from disarmed to armed : one time only */
#define WD_ARM_COUNTER_EXPECT_32VALUE       (uint32_t)0x00000001
/* State of watchdog interrupt :        0b0 when {irq_ack_cmd} is written at 0b1. */
#define WD_IRQ_STATE_EXPECT_32VALUE         (uint32_t)0x00000000
/* Configuration of watchdog interrupt: 0b1 = interrupt is enabled. */
#define WD_IRQ_CONF_EXPECT_32VALUE          (uint32_t)0x00000001
/*wd_state   "Watchdog state:            0b1 = armed */
#define WD_ARM_STATUS_EXPECT_32VALUE        (uint32_t)0x00000001
/* Watchdog initialization mode:        0b1 = oper initialization mode. */
#define WD_INIT_MODE_EXPECT_32VALUE         (uint32_t)0x00000001

/* ---------- provided types: ----------------------------------------------- */
/* FPGA WATCHDOG Register */
typedef struct
{
   /*** Management ***/
   /* Status register (Offset: 0x0000) */
   reg32_t s_STATUS;
   /* Software Arm command register */
   reg32_t s_SW_ARM_CMD;
   /* Software Refresh command register */
   reg32_t s_SW_REFRESH_CMD;
   /* Interrupt Configuration register */
   reg32_t s_IRQ_CONF_CMD;
   /* Activity Check Input register */
   reg32_t s_ACTIVITY_CHECK_IN;
   /* Initialization Mode Command register*/
   reg32_t s_INIT_MODE_CMD;
   /* Initialization Timer Inhibition 1 register */
   reg32_t s_INIT_TIMER_INHIBIT_1;
   /* Initialization Timer inhibition 2 register */
   reg32_t s_INIT_TIMER_INHIBIT_2;

   /*** Configuration ***/
   /* Max Initialization Time In Start Mode register */
   reg32_t s_MAX_INIT_TIME_START;
   /* Max Initialization Time In Operational Mode register */
   reg32_t s_MAX_INIT_TIME_OPER;
   /* Max Failure In Start Mode register */
   reg32_t s_MAX_FAILURE_START;
   /* Max Failure In Operational Mode register */
   reg32_t s_MAX_FAILURE_OPER;
   /* Max ARM Counter register */
   reg32_t s_MAX_ARM_COUNTER;
   /* MIN Window Time register */
   reg32_t s_MIN_WINDOW_TIME;
   /* Max Window Time register */
   reg32_t s_MAX_WINDOW_TIME;
   /* Reset Output Delay register */
   reg32_t s_RESET_OUT_DELAY;

   /*** Monitoring ***/
   /* Activity Check Input register */
   reg32_t s_ACTIVITY_CHECK_OUT;
   /* Timer and Refresh counter register */
   reg32_t s_TIMER_REFRESH_COUNT;
}
ts_watchdog_reg;

/* iip03_watchdog Status Register from bridge_pld_memory_map */

/*-- Structures from iip03 mapping --*/
typedef struct
{
   uint32_t s_Arm_Counter         : 8;
   uint32_t s_Failure_Counter     : 8;
   uint32_t                       : 10;
   uint32_t s_Init_Timer_Config   : 1;
   uint32_t s_Init_Timer_Inhibit  : 1;
   uint32_t s_Irq_State           : 1;
   uint32_t s_Irq_Config          : 1;
   uint32_t s_Wd_State            : 1;
   uint32_t s_Init_mode           : 1;
}ts_watchdog_status;

typedef struct
{
   uint32_t                       : 29;
   uint32_t s_Irq_Ack             : 1;
   uint32_t s_Irq_Disable         : 1;
   uint32_t s_Irq_Enable          : 1;
}ts_watchdog_IRQ;

typedef struct
{
   uint32_t                       : 16;
   uint32_t s_Max_Init_Time_Start : 16;
}ts_watchdog_maxinittimestart;

typedef struct
{
   uint32_t                       : 16;
   uint32_t s_Max_Init_Time_Oper  : 16;
}ts_watchdog_maxinittimeoper;

typedef struct
{
   uint32_t                       : 24;
   uint32_t s_Max_Fail_Start      : 8;
}ts_watchdog_maxfailstart;

typedef struct
{
   uint32_t                       : 24;
   uint32_t s_Max_Fail_Oper       : 8;
}ts_watchdog_maxfailoper;

typedef struct
{
   uint32_t                       : 24;
   uint32_t s_Max_Arm_Counter     : 8;
}ts_watchdog_maxarmcounter;

typedef struct
{
   uint32_t                       : 16;
   uint32_t s_Min_Window_Time     : 16;
}ts_watchdog_minwindowstime;

typedef struct
{
   uint32_t                       : 16;
   uint32_t s_Max_Window_Time     : 16;
}ts_watchdog_maxwindowstime;

typedef struct
{
   uint32_t                       : 16;
   uint32_t s_HReset_Delay        : 16;
}ts_watchdog_hresetdelay;


typedef struct
{
   uint32_t s_refresh_counter     : 16;
   uint32_t s_wd_timer            : 16;
}ts_watchdog_timerrefresh;


/*-- Union registers --*/
typedef union
{
   uint32_t                      u_register;
   ts_watchdog_status            u_bit_status;
   ts_watchdog_IRQ               u_bit_irq;
   ts_watchdog_maxinittimestart  u_bit_maxinittimstart;
   ts_watchdog_maxinittimeoper   u_bit_maxinittimoper;
   ts_watchdog_maxfailstart      u_bit_maxfailstart;
   ts_watchdog_maxfailoper       u_bit_maxfailoper;
   ts_watchdog_maxarmcounter     u_bit_maxarmcounter;
   ts_watchdog_minwindowstime    u_bit_minwindowstime;
   ts_watchdog_maxwindowstime    u_bit_maxwindowstime;
   ts_watchdog_hresetdelay       u_bit_hresetdelay;
   ts_watchdog_timerrefresh      u_bit_timerrefresh;
}tu_watchdog_cmd;

/*-- PBIT global failure --*/
typedef struct
{
   uint32_t                          : 24;
   uint32_t s_maxinittimestart_fail  : 1;
   uint32_t s_maxinittimeoper_fail   : 1;
   uint32_t s_maxfailurestart_fail   : 1;
   uint32_t s_maxfailureoper_fail    : 1;
   uint32_t s_maxarmcounter_fail     : 1;
   uint32_t s_windowslimitmin_fail   : 1;
   uint32_t s_windowslimitmax_fail   : 1;
   uint32_t s_hresetdelay_fail       : 1;
}ts_pbit_fail;

typedef union
{
   uint32_t      u_datafail;
   ts_pbit_fail  u_bit_pbit_fail;
}
tu_watchdog_pbit_fail;

/*-- CBIT global failure --*/
typedef struct
{
   uint32_t                          : 25;
   uint32_t s_Armcounter_fail        : 1;
   uint32_t s_Irqstate_fail          : 1;
   uint32_t s_Irqconfig_fail         : 1;
   uint32_t s_Armstate_fail          : 1;
   uint32_t s_Initmode_fail          : 1;
   uint32_t s_Refrechcounter_fail    : 1;
   uint32_t s_Activitycheck_fail     : 1;
}ts_cbit_fail;

typedef union
{
   uint32_t      u_datafail;
   ts_cbit_fail  u_bit_cbit_fail;
}
tu_watchdog_cbit_fail;

/* ---------- provided constants: ------------------------------------------- */
/*-- PBIT global failure --*/
extern uint32_t   c_watchdog_pbit_report;

/*-- CBIT global failure --*/
extern uint32_t   c_watchdog_cbit_report;

/*-- INIT a CBIT global failure --*/
extern uint32_t   c_watchdog_cbit_error;

/* ---------- provided data: ------------------------------------------------ */
/* Internal Data used to read the incremented Activity value and also for test purpose */
/* On 16 bits to conform to refresh counter register in the FPGA */
extern uint16_t               V_CBIT_WDG_ActivityValue;
/* Flag used for switch between the 2 values at each check of activity */
extern te_CMN_FLAG_QUESTION   V_CBIT_WDG_IsValue1ActivityCheck;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0001 */
/* Perform the PBIT on the watchdog */
extern void watchdog_pbit(void);

/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0010 */
/* Arm the watchdog */
extern void watchdog_arm(void);

/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0010 */
/* Refresh the watchdog */
extern void watchdog_refresh(void);

/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0010 */
/* Perform the CBIT on the watchdog */
extern void watchdog_cbit(void);

#endif /* WATCHDOG_PRIVATE_H */
