/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef NFREQ_PRIVATE_H
#define NFREQ_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Flag setting */
#define C_UNSET ((uint32_t)0x0)
#define C_SET   ((uint32_t)0x1)

/* Samples parsing */
#define C_INCONSISTENT ((uint32_t)0x0)
#define C_CONSISTENT   ((uint32_t)0x1)

/* FPGA iip10 offset */
#define C_FPGA_IIP10_0_OFFSET ((uint32_t)0x00054000)
#define C_FPGA_IIP10_1_OFFSET ((uint32_t)0x00058000)
#define C_FPGA_IIP10_2_OFFSET ((uint32_t)0x0005C000)
#define C_FPGA_IIP10_3_OFFSET ((uint32_t)0x00060000)

#define C_NFREQ_RX_BUFF_OFFSET ((uint32_t)0x00000400)
#define C_NFREQ_MAX_RX_DATA    ((uint32_t)256)

/* NFREQ max values */
#define C_MAX_FREQ_NFREQ2  ((float32_t)20002.5)
#define C_MAX_FREQ_NFREQ3  ((float32_t)4000.8)
#define C_MAX_FREQ_NFREQ4  ((float32_t)2630.5)
#define C_MAX_FREQ_NGALT   ((float32_t)1000.4)

/* NFREQ3 ratioo bounds */
#define C_NFREQ3_LOWER_RATIO     ((float32_t)0.5)
#define C_NFREQ3_UPPER_RATIO     ((float32_t)0.80001)

/* Number of samples per period */
#define C_1_SAMPLES_PER_PERIOD   ((uint32_t)1)
#define C_2_SAMPLES_PER_PERIOD   ((uint32_t)2)

/* Periods conversion */
#define C_PERIOD_TICK_TO_SEC  ((float32_t)1.25E-8)
#define C_PERIOD_TICK_TO_MS   ((float32_t)1.25E-5)
#define C_PERIOD_TICK_TO_US   ((float32_t)1.25E-2)

/* GPIO Handling */
#define C_NFREQ2_MON ((uint32_t)0xFFFC159C)  /* GPDI 156 */
#define C_NFREQ3_MON ((uint32_t)0xFFFC159D)  /* GPDI 157 */
#define C_NFREQ4_MON ((uint32_t)0xFFFC159E)  /* GPDI 158 */
#define C_POR_OPP_N  ((uint32_t)0xFFFC15C5)  /* GPDI 197 */

/* ---------- provided types: ----------------------------------------------- */
/* nFreq control register */
typedef struct
{
   reg32_t s_unused_2_31       : 30;
   reg32_t s_parity_error_ack  :  1;
   reg32_t s_corrupt_parity    :  1;
}
ts_nfreq_reg_ctrl;

/* nFreq configuration register */
typedef struct
{
   reg32_t s_unused_4_31  : 28;
   reg32_t s_inc_2_th_sel :  2;
   reg32_t s_inc_1_th_sel :  2;
}
ts_nfreq_reg_conf;

/* nFreq status register */
typedef struct
{
   reg32_t s_unused_21_31        : 11;
   reg32_t s_glb_inconsistency_2 :  1;
   reg32_t s_glb_inconsistency_1 :  1;
   reg32_t s_glitch_detect       :  1;
   reg32_t s_overflow            :  1;
   reg32_t s_parity_error        :  1;
   reg32_t s_unused_9_15         :  7;
   reg32_t s_sample_number_last  :  9;
}
ts_nfreq_reg_status;

/* nFreq counter register */
typedef struct
{
   reg32_t s_unused_9_31   : 23;
   reg32_t s_sample_number :  9;
}
ts_nfreq_reg_count;

/* FPGA nFREQ Registers */
typedef struct
{
   ts_nfreq_reg_ctrl    s_control_register;
   ts_nfreq_reg_conf    s_conf_register;
   ts_nfreq_reg_status  s_status_register;
   ts_nfreq_reg_count   s_counter_register;
}
ts_nfreq_registers;

/* FPGA nFREQ Data */
typedef struct
{
   reg32_t s_inconsistency_2 :  1;
   reg32_t s_inconsistency_1 :  1;
   reg32_t s_unused_24_29    :  6;
   reg32_t s_period          : 24;
}
ts_nfreq_data;

/* Generic status bitfield (match all nfreq) */
typedef struct
{
   uint32_t s_meas_oc_fault         : 1;  /* 31: Open circuit*/
   uint32_t s_meas_short_diff       : 1;  /* 30: short differential (short between phases)*/
   uint32_t s_meas_short_gnd        : 1;  /* 29: short to ground*/
   uint32_t s_out_of_range_freq     : 1;  /* 28: Out of range (frequency calculation)  */
   uint32_t s_spare_27_to_25        : 3;  /* 27 to 25: Spare */
   uint32_t s_out_of_range_duty     : 1;  /* 24: Out of range (duty cycle calculation)  */
   uint32_t s_spare_23_to_12        : 12; /* 23 to 12: Spare */
   uint32_t s_freq_parity_err       : 1;  /* 11: parity error (freq inputs buffer error) */
   uint32_t s_freq_overflow         : 1;  /* 10: overflow error (freq inputs buffer error) */
   uint32_t s_freq_inconsistency    : 1;  /* 09: inconsistency (freq inputs) */
   uint32_t s_freq_time_out         : 1;  /* 08: time out (freq inputs) */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_02        : 5;  /* 06 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_nfreq_status_bitfield;

/* NFREQ2-4 fault word */
typedef union
{
   uint32_t                 u_word;    /* fault word accessed by 32-bit word */
   ts_nfreq_status_bitfield u_bit;     /* fault word accessed bit by bit */
}
tu_nfreq_status;

/* Sensors parameters */
typedef struct
{
   /* iip10[] adresses */
   uint32_t        s_fpga_register;   /* FPGA register start address */
   uint32_t        s_fpga_data;       /* FPGA rx_data[] start address */
   /* GPIO adress */
   uint32_t        s_gpio_input;
   /* sensor parameters */
   uint32_t        s_width;           /* number of samples per period */
   uint32_t        s_n_max;           /* max number of periods for calculation */
   uint32_t        s_n_min;           /* min number of periods for calculation */
   uint32_t        s_n_rev;           /* number of period per rotation */
   uint32_t        s_timeout;         /* max RTC duration for calculation validity */
   float32_t       s_freq_min;        /* lower bound */
   float32_t       s_freq_max;        /* upper bound */
   /* Local parameters */
   uint32_t        s_samples[C_NFREQ_MAX_RX_DATA];
   uint32_t        s_sample_count;
   uint32_t        s_periods;
   uint32_t        s_maintain_counter;/* actual count of RTC to invalidity */
   float32_t       s_measure_freq;    /* calculated frequency value */
   float32_t       s_measure_ratio;   /* calculated ratio value (nFreq3 only) */
   tu_nfreq_status s_status_word;
   /* shared mem parameters */
   uint32_t        s_max_shmem;
}
ts_nfreq_sensor_info;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Array holding parameters of all known sensors  */
extern ts_nfreq_sensor_info v_nfreq_sensors[e_SensorMax];

/* ---------- provided operations: ------------------------------------------ */


#endif /* NFREQ_PRIVATE_H */
