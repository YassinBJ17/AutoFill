/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef RTC_PRIVATE_H
#define RTC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* MRAM address for critical data */
#define MRAM_OSS_CRITICAL_DATA_ADDR           (uint32_t)0x20004600

/* FPGA Misc1 iip address */
#define K_FPGA_MISC1_REG_ADDR               (reg32_t)0x24000000

/* Initialization of counters values */
#define K_RTC_COUNTER_INIT_UINT_32VALUE     (uint32_t)0
#define K_RTC_COUNTER_INIT_FLOAT_32VALUE    (float32_t)0.0
#define K_FIRST_COUNTER_INIT_UINT_32VALUE   (uint32_t)40
#define K_QUOTIEN_INIT_UINT_32VALUE         (uint32_t)1

/* Unites converters values */
#define K_SEC_TO_MICRO_CONV_UINT_32VALUE    (uint32_t)1000000
#define K_SEC_TO_MILLI_CONV_UINT_32VALUE    (uint32_t)1000
#define K_SEC_TO_RTC_CONV_UINT_32VALUE      (uint32_t)100

#define K_RTC_TO_MILLI_CONV_UINT_32VALUE    (uint32_t)10
#define K_RTC_TO_MICRO_CONV_UINT_32VALUE    (uint32_t)10000

#define K_2MICRO_TO_MICRO_CONV_UINT_32VALUE (uint32_t)2

/* Command value to reset */
#define K_RESET_UINT_32VALUE                (uint32_t)1

/* ---------- provided types: ----------------------------------------------- */

/* OSS_PU COUNTERS SAVED functionality in MRAM */

typedef struct
{
   uint32_t s_power_up_count;      /* number of power up on the channel */
   uint32_t s_first_power_up_time; /* elapsed time since the first power up  */
   uint32_t s_last_power_up_time;  /* elapsed time since the last power up  */
}
ts_dates;

typedef struct
{
   uint32_t  s_power_up_count;         /* number of power up */
   uint32_t  s_first_power_up_time;    /* elapsed time since the first power up */


   uint32_t  s_ft_count;                /* Number of Fast Task call since the last power up */

   uint32_t  s_last_max_ft_time;        /* maximum execution time of the fast task during the previous power up*/
   ts_dates   s_last_max_ft_date;        /* date of the fast task with the max exec time during the previous power up*/

   uint32_t  s_max_last_max_ft_time;    /* maximum execution time of the fast task */
   ts_dates   s_max_last_max_ft_date;    /* date of the fast task with the max execution time */

   uint32_t  s_last_max_st_time;        /* maximum execution time of the slow task during the previous power up*/
   ts_dates   s_last_max_st_date;        /* date of the slow task with the max exec time during the previous power up*/

   uint32_t  s_max_last_max_st_time;    /* maximum execution time of the slow task */
   ts_dates   s_max_last_max_st_date;    /* date of the slow task with the maximum execution time */

   uint32_t  s_last_max_vst_time;       /* maximum execution time of the very slow task during the previous power up*/
   ts_dates   s_last_max_vst_date;       /* date of very slow task with max exec time during the previous power up*/

   uint32_t  s_max_last_max_vst_time;   /* maximum execution time of the very slow task */
   ts_dates   s_max_last_max_vst_date;   /* date of the very slow task with the maximum execution time */

   uint32_t  s_last_max_bg_time;        /* maximum execution time of the background task during the previous power up*/
   ts_dates   s_last_max_bg_date;        /* date of very background task with max exec time during the previous power up*/

   uint32_t  s_max_last_max_bg_time;    /* maximum execution time of the background task */
   ts_dates   s_max_last_max_bg_date;    /* date of the background task with the maximum execution time */

   uint32_t  s_last_max_oa_time;        /* maximum time execution of the OSS_PU during the previous power up */
   uint32_t  s_max_last_max_oa_time;    /* maximum time execution of the OSS_PU */

   float32_t s_max_tecu;                /* maximum temperature value of TECU */
   ts_dates  s_max_tecu_date;           /* date fo the maximum temperature value of TECU */
}
ts_MRAM_counter;

/* FPGA Miscellaneous resources Register */
typedef struct
{
   /*** Miscellaneous resources registers ***/
   /* PLD identification register (Offset: 0x0000) */
   reg32_t s_PLD_IDENT;

   /*** Test registers ***/
   /* Read-write test register */
   reg32_t s_TEST_REG;
   /* Fixed value 1 for test purpose */
   reg32_t s_REG_EBI_AA;
   /* Fixed value 2 for test purpose */
   reg32_t s_REG_EBI_55;
   /* Time stamp register */
   reg32_t s_TIMESTAMP_REG;
   /* PLD status register */
   reg32_t s_PLD_STATUS_REG;
   /* RTC reset key register */
   reg32_t s_RTC_RST_KEY_REG;
   /* RTC configuration register */
   reg32_t s_RTC_CFG_REG;
}
ts_misc1_reg;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0090 */
/* Save the counter in shared memory of elapsed RTC */
extern void rtc_counter_read(uint32_t* const p_cmd_rst);

/* Implements REQ_FADEX_OS_SRD-SCHED-0100 */
/* Reset every counter of elapsed RTC */
extern void rtc_counter_reset(void);

/* TODO - TBC at least revision of Asterios to K19.4 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0090 */
/* Write in MRAM RTC values of elapsed RTC */
extern void rtc_counter_write(void);

#endif /* RTC_PRIVATE_H  */
