/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SHARED_MEMORY_PUBLIC_H
#define SHARED_MEMORY_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* number of  CAN channel */
#define CAN_NB (uint32_t)2

/* Maximum number of bytes in a CAN received frame */
#define CAN_FRAME_BYTES_MAX_NB (uint32_t)8

/* Maximum number of CAN received frames */
#define CAN_RX_FRAMES_MAX_NB (uint32_t)64

/* Maximum number of CAN transmitted frames */
#define CAN_TX_FRAMES_MAX_NB (uint32_t)32

/* Number of HP output discrete */
#define HP_NB (uint32_t)5

/* Number of LP output discrete */
#define LP_NB (uint32_t)10

/* Number of A429 cHANNEL */
#define A429_NB (uint32_t) 2

/* maximal Number of A429 Word by message */
#define NB_A429_DATA (uint32_t) 27

/* maximal Number of RS422 Word by message */
#define NB_RS422_DATA (uint32_t) 256

/* size of ICDL buffer */
#define ICDL_BUFFER_SIZE (uint32_t) 1024
/* Number of AS messages */
#define ICDL_AS_NB_PORT (uint32_t) 8
/* UOD message index */
#define ICDL_UOD_MSG_INDEX (ICDL_AS_NB_PORT - 1)

/* nb of characters of reference string */
#define REF_SIZE (uint32_t) 16

/* nb of characters of serial number */
#define SERIAL_SIZE (uint32_t) 8

/* nb of Discret Inputs to acquire */
#define DIN_NB (uint32_t) 16

/* max nb of NFREQ2 measures */
#define NFREQ2_MAX_MEAS_NB (uint32_t) 100

/* max nb of NFREQ3 measures */
#define NFREQ3_MAX_MEAS_NB (uint32_t) 12

/* max nb of NFREQ4 measures */
#define NFREQ4_MAX_MEAS_NB (uint32_t) 100

/* max nb of NGAlT measures */
#define NGALT_MAX_MEAS_NB (uint32_t) 12

/* Size of CCDL message (CSS part) */
#define CCDL_MSG_SIZE (uint32_t) 256


/* ---------- provided types: ----------------------------------------------- */
/* State of completeness */
typedef enum
{
   e_not_done = 0,   /* Not done */
   e_done = 1        /* Done */
}
te_completeness_state;

/* Functionalities current execution time */
typedef struct
{
   int64_t s_watchdog;
   int64_t s_tmot;
   int64_t s_smot;
   int64_t s_powersup;
   int64_t s_adc_over_spi_start;
   int64_t s_adc_over_spi_stop;
   int64_t s_sg;
   int64_t s_xr;
   int64_t s_lvdt;
   int64_t s_nfreq;
   int64_t s_t4;
   int64_t s_tecu;
   int64_t s_vrt;
   int64_t s_can;
   int64_t s_a429;
   int64_t s_discrete;
   int64_t s_pot;
   int64_t s_calres;
   int64_t s_ccdl_tx;
   int64_t s_ccdl_rx;
   int64_t s_hpdisc;
   int64_t s_lpdisc;
   int64_t s_pan3;
   int64_t s_pca9535e_read;
   int64_t s_pca9535e_write;
   int64_t s_accom;
   int64_t s_icdl;
   int64_t s_pwm;
   int64_t s_uart;
   int64_t s_ovsp;
   int64_t s_mram;
   int64_t s_logbook;
   int64_t s_p0;
   int64_t s_global;
}
ts_fct_exec_time;


/* Bits field of torque motor read fault word */
typedef struct
{
   uint32_t s_spare_31_to_29 : 3;        /* 31 to 29: Spare */
   uint32_t s_out_of_range_current : 1;  /* 28: Is current out of range ? */
   uint32_t s_spare_27_to_25 : 3;        /* 27 to 25: Spare */
   uint32_t s_out_of_range_voltage : 1;  /* 24: Is voltage out of range ? */
   uint32_t s_spare_23_to_08 : 16;       /* 23 to 08: Spare */
   uint32_t s_out_of_range_final : 1;    /* 07: Is voltage or current out of range ? */
   uint32_t s_spare_06_to_01 : 6;        /* 06 to 01: Spare */
   uint32_t s_invalid : 1;               /* 00: Is torque motor read invalid ? */
}
ts_tmot_r_fault_word_u_bit;

/* Torque motor read fault word */
typedef union
{
   uint32_t u_word;                    /* Torque motor read fault word accessed by 32-bit word */
   ts_tmot_r_fault_word_u_bit u_bit;   /* Torque motor read fault word accessed bit by bit */
}
tu_tmot_r_fault_word;

/* Torque motor read functionality in shared memory */
typedef struct
{
   float32_t s_current;                   /* Current read */
   float32_t s_voltage;                   /* Voltage read */
   tu_tmot_r_fault_word s_fault_word;     /* Fault word of the torque motor read returned by the OSS_PU */
}
ts_tmot_r;

/* Bits field of torque motor write fault word */
typedef struct
{
   uint32_t s_spare_31_to_08 : 24;  /* 31 to 08: Spare */
   uint32_t s_out_of_range : 1;     /* 07: Is request out of range ? */
   uint32_t s_spare_06_to_00 : 7;   /* 06 to 00: Spare */
}
ts_tmot_w_fault_word_u_bit;

/* Torque motor write fault word */
typedef union
{
   uint32_t u_word;                    /* Torque motor write fault word accessed by 32-bit word */
   ts_tmot_w_fault_word_u_bit u_bit;   /* Torque motor write fault word accessed bit by bit */
}
tu_tmot_w_fault_word;

/* Torque motor write functionality in shared memory */
typedef struct
{
   float32_t s_current;                /* Current to write */
   tu_tmot_w_fault_word s_fault_word;  /* Fault word of the torque motor read returned by the OSS_PU */
}
ts_tmot_w;

/* CAN identifier range */
typedef struct
{
   uint32_t s_start_id;   /* Start identifier */
   uint32_t s_stop_id;    /* Stop identifier */
}
ts_can_id_range;

/* CAN configuration in shared memory */
typedef struct
{
   ts_can_id_range s_id_ranges[CAN_RX_FRAMES_MAX_NB]; /* Identifier ranges to configure */
   te_completeness_state s_configure_on_request;      /* Is the new configuration done ? */
}
ts_can_configure;

typedef struct
{
   uint32_t s_identifier;                      /* Frame identifier */
   uint8_t  s_data[CAN_FRAME_BYTES_MAX_NB];    /* Frame data */
   uint32_t s_length;                          /* Frame number of used bytes */
}
ts_can_frame;

/* Bits field of CAN read fault word */
typedef struct
{
   uint32_t s_spare_31_to_08 : 24;  /* 31 to 08: Spare */
   uint32_t s_crc_err : 1;          /* 07: Is there CRC error ? */
   uint32_t s_fifo_err : 1;         /* 06: Is there a FIFO error (busy or full) ? */
   uint32_t s_frame_err : 1;        /* 05: Error on the frame (bad format, stuff error) ? */
   uint32_t s_spare_04_to_01 : 4;   /* 04 to 01: Spare */
   uint32_t s_invalid : 1;          /* 00: Is CAN read invalid ? */
}
ts_can_rx_fault_word_u_bit;

/* CAN read fault word */
typedef union
{
   uint32_t u_word;                    /* CAN read fault word accessed by 32-bit word */
   ts_can_rx_fault_word_u_bit u_bit;   /* CAN read fault word accessed bit by bit */
}
tu_can_rx_fault_word;

/* CAN read functionality in shared memory */
typedef struct
{
   uint32_t s_frames_nb;                        /* Number of frames received */
   ts_can_frame s_frames[CAN_RX_FRAMES_MAX_NB]; /* Received frames */
   tu_can_rx_fault_word s_fault_word;           /* Fault word of the CAN read returned by the OSS_PU */
}
ts_can_rx;

/* Bits field of CAN write fault word */
typedef struct
{
   uint32_t s_spare_31_to_08 : 24;  /* 31 to 08: Spare */
   uint32_t s_ack_err : 1;          /* 07: Is there ack error (acknowledgement not received) ? */
   uint32_t s_fifo_err : 1;         /* 06: Is there a FIFO error (busy or full) ? */
   uint32_t s_frame_err : 1;        /* 05: Error on the frame (bad format, stuff error) ? */
   uint32_t s_spare_04_to_02 : 3;   /* 04 to 02: Spare */
   uint32_t s_busy : 1;             /* 01: Is the CAN line busy ? */
   uint32_t s_invalid : 1;          /* 00: Is CAN write invalid ? */
}
ts_can_tx_fault_word_u_bit;

/* CAN write fault word */
typedef union
{
   uint32_t u_word;                    /* CAN write fault word accessed by 32-bit word */
   ts_can_tx_fault_word_u_bit u_bit;   /* CAN write fault word accessed bit by bit */
}
tu_can_tx_fault_word;

/* CAN write functionality in shared memory */
typedef struct
{
   uint32_t s_frames_nb;                        /* Number of frames to transmit */
   ts_can_frame s_frames[CAN_TX_FRAMES_MAX_NB]; /* Frames to transmit */
   tu_can_tx_fault_word s_fault_word;           /* Fault word of the CAN write returned by the OSS_PU */
}
ts_can_tx;

/* Bits field of SG fault word */
typedef struct
{
   uint32_t s_open_circuit_sig : 1;          /* 31: Is signal greater than 2nd max value ? */
   uint32_t s_spare_30 : 1;                  /* 30: Spare */
   uint32_t s_short_to_gnd_sig : 1;          /* 29: Is signal short to ground ? */
   uint32_t s_spare_28_to_24 : 5;            /* 28 to 24: Spare */
   uint32_t s_open_circuit_exc : 1;          /* 23: Is exc open circuit (same condition for bit s_exc_short_to_gnd) */
   uint32_t s_short_diff_ls : 1;             /* 22: Is the low side voltage greater than max value ? */
   uint32_t s_short_to_gnd_exc : 1;          /* 21: Is exc short to gnd (same condition for bit s_exc_short_to_gnd) */
   uint32_t s_short_to_gnd_ls : 1;           /* 20: Is the low side voltage short to ground ? */
   uint32_t s_greater_than_max_sig : 1;      /* 19: Is signal greater than the 1st max value ? */
   uint32_t s_greater_than_max_exc : 1;      /* 18: Is excitation voltage greater than max val ? */
   uint32_t s_spare_17_to_08 : 10;           /* 17 to 08: Spare */
   uint32_t s_out_of_range_final : 1;        /* 07: Is final value processed out of range ? */
   uint32_t s_spare_06_to_05 : 2;            /* 06 to 05: Spare */
   uint32_t s_out_of_range_gnd : 1;          /* 04: Is ground signal out of range ? */
   uint32_t s_spare_03_to_02 : 2;            /* 03 to 02: Spare */
   uint32_t s_unavailable : 1;               /* 01: Is the opposite channel data received ? */
   uint32_t s_invalid : 1;                   /* 00: Is SG invalid ? */
}
ts_sg_fault_word_u_bit;

/* SG fault word */
typedef union
{
   uint32_t u_word;              /* SG fault word accessed by 32-bit word */
   ts_sg_fault_word_u_bit u_bit; /* SG fault word accessed bit by bit */
}
tu_sg_fault_word;

/* SG functionality in shared memory */
typedef struct
{
   float32_t s_measure;             /* Measure acquired and processed */
   tu_sg_fault_word s_fault_word;   /* Fault word of the SG returned by the OSS_PU */
}
ts_sg;

/* Bits field of XR fault word */
typedef struct
{
   uint32_t s_open_circuit_sin   : 1;  /* 31: Is measure 1 (cosinus) open circuit ?       */
   uint32_t s_short_diff_sin     : 1;  /* 30: Is measure 1 (cosinus) short differential ? */
   uint32_t s_short_to_gnd_sin   : 1;  /* 29: Is measure 1 (cosinus) short to ground ?    */
   uint32_t s_out_of_range_sin   : 1;  /* 28: Is measure 1 (cosinus) out of range ?       */
   uint32_t s_open_circuit_cos   : 1;  /* 27: Is measure 2 (sinus) open circuit ?         */
   uint32_t s_short_diff_cos     : 1;  /* 26: Is measure 2 (sinus) short differential ?   */
   uint32_t s_short_to_gnd_cos   : 1;  /* 25: Is measure 2 (sinus) short to ground ?      */
   uint32_t s_out_of_range_cos   : 1;  /* 24: Is measure 2 (sinus) out of range ?         */
   uint32_t s_open_circuit_exc   : 1;  /* 23: Is excitation measure open circuit ?        */
   uint32_t s_short_diff_exc     : 1;  /* 22: Is excitation measure short differential ?  */
   uint32_t s_short_to_gnd_exc   : 1;  /* 21: Is excitation measure short to gnd ?        */
   uint32_t s_spare_20_to_19     : 2;  /* 20 to 19: Spare                                 */
   uint32_t s_out_of_range_exc   : 1;  /* 18: Is excitation measure out of range ?        */
   uint32_t s_spare_17_to_08     : 10; /* 17 to 08: Spare                                 */
   uint32_t s_out_of_range_final : 1;  /* 07: Is final result out of range ?              */
   uint32_t s_spare_06_to_05     : 2;  /* 06 to 05: Spare                                 */
   uint32_t s_internal_failure   : 1;  /* 04: Is at least one average out of range ?      */
   uint32_t s_spare_03_to_02     : 2;  /* 03 to 02: Spare                                 */
   uint32_t s_unavailable        : 1;  /* 01: Is data from opposite channel received ?    */
   uint32_t s_invalid            : 1;  /* 00: Is XR invalid ?                             */
}
ts_xr_fault_word_u_bit;

/* XR fault word */
typedef union
{
   uint32_t u_word;              /* XR fault word accessed by 32-bit word */
   ts_xr_fault_word_u_bit u_bit; /* XR fault word accessed bit by bit */
}
tu_xr_fault_word;

/* XR functionality in shared memory */
typedef struct
{
   float32_t s_measure;             /* Angular measure (in deg) of the resolver */
   float32_t s_vcos_measure;        /* Cosinus measure */
   float32_t s_vsin_measure;        /* Sinus measure */
   tu_xr_fault_word s_fault_word;   /* Fault word of the XR returned by the OSS_PU */
}
ts_xr;

/* Bits field of HP fault word */
typedef struct
{
   uint32_t s_out_open_circuit    :  1;   /* 31: Output Open Circuit  */
   uint32_t s_out_short_diff      :  1;   /* 30: Output Differential (N/A for HP 1, 2, 3 and 5) */
   uint32_t s_out_short_hs_to_gnd :  1;   /* 29: Output short High Side to GND */
   uint32_t s_out_short_ls_to_gnd :  1;   /* 28: Output short Low Side to GND (N/A for HP 1, 2, 3 and 5) */
   uint32_t s_sw1_faulty          :  1;   /* 27: Switch 1 error */
   uint32_t s_sw2_faulty          :  1;   /* 26: Switch 2 error */
   uint32_t s_cmd_failed          :  1;   /* 25: Command failed */
   uint32_t s_spare_24_to_18      :  7;   /* 24 to 18: Spare */
   uint32_t s_signature_fault     :  1;   /* 17: undetermined fault signature */
   uint32_t s_unexpected_cmd      :  1;   /* 16: Unexpected command */
   uint32_t s_spare_15_to_06      : 10;   /* 15 to 06: Spare */
   uint32_t s_i2c_not_working     :  1;   /* 05: I2C communication failed */
   uint32_t s_spare_04_to_01      :  4;   /* 4 to 1: Spare */
   uint32_t s_invalid             :  1;   /* 00: invalid HP command */
}
ts_hp_fault_word_u_bit;

/* HP fault word */
typedef union
{
   uint32_t u_word;              /* HP fault word accessed by 32-bit word */
   ts_hp_fault_word_u_bit u_bit; /* HP fault word accessed bit by bit */
}
tu_hp_fault_word;

/* HP WRITE functionality in shared memory */
typedef struct
{
   uint32_t s_hp_command[HP_NB];       /* Command of the different HP output*/
   tu_hp_fault_word s_hp_status[HP_NB]; /* status word of the HP command returned by the OSS_PU */
}
ts_hp_w;

/* Bits field of LP fault word */
typedef struct
{
   uint32_t s_out_open_circuit    :  1;   /* 31: Open circuit (or short to ground or erroneous command)  */
   uint32_t s_out_short_diff      :  1;   /* 30: Short Differential (or command failed) */
   uint32_t s_spare_29            :  1;   /* 29: Spare */
   uint32_t s_out_short_ls_to_gnd :  1;   /* 28: Output short to GND */
   uint32_t s_sw1_faulty          :  1;   /* 27: Switch 1 error */
   uint32_t s_sw2_faulty          :  1;   /* 26: Switch 2 error (N/A for LP 1, 2, 3, 4 and 9)*/
   uint32_t s_cmd_failed          :  1;   /* 25: Command failed */
   uint32_t s_spare_24_to_17      :  8;   /* 24 to 17: Spare */
   uint32_t s_unexpected_cmd      :  1;   /* 16: Unexpected command */
   uint32_t s_spare_15_to_06      : 10;   /* 15 to 06: Spare */
   uint32_t s_i2c_not_working     :  1;   /* 05: I2C communication failed */
   uint32_t s_spare_04_to_01      :  4;   /* 4 to 1: Spare */
   uint32_t s_invalid             :  1;   /* 00: invalid HP command */
}
ts_lp_fault_word_u_bit;

/* LP fault word */
typedef union
{
   uint32_t u_word;              /* LP fault word accessed by 32-bit word */
   ts_lp_fault_word_u_bit u_bit; /* LP fault word accessed bit by bit */
}
tu_lp_fault_word;

/* LP WRITE functionality in shared memory */
typedef struct
{
   uint32_t s_lp_command[LP_NB];       /* Command of the different LP output*/
   tu_lp_fault_word s_lp_status[LP_NB]; /* status word of the LP command returned by the OSS_PU */
}
ts_lp_w;

/* Bits field of PWM1 fault word */
typedef struct
{
   uint32_t s_open_circuit              : 1;    /* 31   : Open circuit (or short to ground or erroneous command)  */
   uint32_t s_spare_30                  : 1;    /* 30   : Spare */
   uint32_t s_hs_short_to_gnd           : 1;    /* 29   : High side short to ground */
   uint32_t s_ls_short_to_gnd           : 1;    /* 28   : Low side short to ground */
   uint32_t s_stuck_high                : 1;    /* 27   : Stuck high */
   uint32_t s_spare_26_to_01            : 26;   /* 26-01: Spare */
   uint32_t s_invalid                   : 1;    /* 00   : Invalidity */
}
ts_pwm_fault_word_u_bit;

/* PWM1 fault word */
typedef union
{
   uint32_t u_word;                 /* PWM1 fault word accessed by 32-bit word */
   ts_pwm_fault_word_u_bit u_bit;   /* PWM1 fault word accessed bit by bit */
}
tu_pwm_fault_word;

/* PWM1 WRITE functionality in shared memory */
typedef struct
{
   float32_t s_pwm_ratio;             /* PWM1 ratio command*/
   float32_t s_last_commanded_ratio;  /* Last commanded ratio (0.0 if the PWM1 is deactivated) */
   float32_t s_pwm_fbk_period;        /* Measured PWM period feedback from FPGA */
   float32_t s_pwm_fbk_high_time;     /* Measured PWM feedback high time from FPGA */
   tu_pwm_fault_word s_pwm_status;    /* status word of the PWM1 command returned by the OSS_PU */
}
ts_pwm_w;

/* Bits field of A429 WRITE fault word */
typedef struct
{
   uint32_t s_spare_31_to_24           : 8;  /* 31 to 24: Spare */
   uint32_t s_nb_word_fifo             : 8;  /* 23 to 16: number of word present in fifo */
   uint32_t s_spare_15_to_05           : 11; /* 15 to 05: Spare */
   uint32_t s_parity_err               : 1;  /* 04: parity error SRAM A429 Tx (previous frame) */
   uint32_t s_spare_03_to_02           : 2;  /* 03 to 02: Spare */
   uint32_t s_busy                     : 1;  /* 01  Busy (service unavailable)*/
   uint32_t s_invalid                  : 1;  /* 00: invalid A429 command */
}
ts_a429_tx_fault_word_u_bit;

/* A429 fault word */
typedef union
{
   uint32_t u_word;                 /* A429 fault word accessed by 32-bit word */
   ts_a429_tx_fault_word_u_bit u_bit; /* A429 fault word accessed bit by bit */
}
tu_a429_tx_fault_word;

/* A429 WRITE functionality in shared memory */
typedef struct
{
   uint32_t s_tx_count;                /* number of A429 word to transmit*/
   uint32_t s_tx_word[NB_A429_DATA];  /* A429 Data to transmit */
   tu_a429_tx_fault_word s_tx_status;    /* status word of the A429 command returned by the OSS_PU */
}
ts_a429_tx;

/* Bits field of RS422 write fault word */
typedef struct
{
   uint32_t s_spare_31_to_17           : 15;  /* 31 to 18: Spare */
   uint32_t s_range_err_tx_count       : 1;  /* 16 sw range error on paramter 1*/
   uint32_t s_spare_15_to_05           : 11;  /* 15 to 05: Spare */
   uint32_t s_frame_err                : 1;  /* 04: frame error */
   uint32_t s_spare_03_to_02           : 2;  /* 03 to 02: Spare */
   uint32_t s_busy                     : 1;  /* 01  Busy (service unavailable) */
   uint32_t s_invalid                  : 1;  /* 00: invalid RS422 write command */
}
ts_rs422_tx_fault_word_u_bit;

/* RS422 fault word */
typedef union
{
   uint32_t u_word;                 /* RS422 fault word accessed by 32-bit word */
   ts_rs422_tx_fault_word_u_bit u_bit; /* RS422 fault word accessed bit by bit */
}
tu_rs422_tx_fault_word;

/* RS422 WRITE functionality in shared memory */
typedef struct
{
   uint32_t s_tx_count;                /* number of RS422 byte to transmit*/
   uint8_t s_tx_word[NB_RS422_DATA];  /* RS422 Data to transmit */
   tu_rs422_tx_fault_word s_tx_status;    /* status word of the RS422 write command returned by the OSS_PU */
}
ts_rs422_tx;

/* Bits field of RS422 read fault word */
typedef struct
{
   uint32_t s_spare_31_to_09           : 23; /* 31 - 09: Spare */
   uint32_t s_no_new_rx                : 1;  /* 08     : no new reception since last call of service */
   uint32_t s_spare_07_to_06           : 2;  /* 07 - 06: Spare */
   uint32_t s_overflow_err             : 1;  /* 05     : CRC or checksum error) */
   uint32_t s_frame_err                : 1;  /* 04     : frame error */
   uint32_t s_spare_03_to_01           : 3;  /* 03 - 01: Spare */
   uint32_t s_invalid                  : 1;  /* 00     : invalid RS422 read command */
}
ts_rs422_rx_fault_word_u_bit;

/* RS422 fault word */
typedef union
{
   uint32_t u_word;                 /* RS422 fault word accessed by 32-bit word */
   ts_rs422_rx_fault_word_u_bit u_bit; /* RS422 fault word accessed bit by bit */
}
tu_rs422_rx_fault_word;

/* RS422 WRITE functionality in shared memory */
typedef struct
{
   uint32_t s_rx_count;                /* number of received RS422 byte */
   uint8_t s_rx_word[NB_RS422_DATA];   /* received RS422 Data */
   tu_rs422_rx_fault_word s_rx_status;   /* status word of the RS422 read command returned by the OSS_PU */
}
ts_rs422_rx;

/* Bits field of A429 READ fault word */
typedef struct
{
   uint32_t s_spare_31_to_16           : 16; /* 31 to 16: Spare */
   uint32_t s_timestamp_old            : 1;  /* 15: Time stamp too old */
   uint32_t s_spare_14_to_07           : 8;  /* 14 to 07: Spare */
   uint32_t s_sram_parity_err          : 1;  /* 06: parity error in SRAM A429 Rx */
   uint32_t s_frame_parity_err         : 1;  /* 05: parity error on the A429 received frame  */
   uint32_t s_frame_integrity_err      : 1;  /* 04  frame integrity error*/
   uint32_t s_spare_03_to_01           : 3;  /* 03 to 01: Spare */
   uint32_t s_invalid                  : 1;  /* 00: invalid A429 command */
}
ts_a429_rx_fault_word_u_bit;

/* A429 READ fault word */
typedef union
{
   uint32_t u_word;                   /* A429 fault word accessed by 32-bit word */
   ts_a429_rx_fault_word_u_bit u_bit; /* A429 fault word accessed bit by bit */
}
tu_a429_rx_fault_word;

/* ARINC READ functionality in shared memory */
typedef struct
{
   uint32_t s_rx_count;                /* number of received A429 word */
   uint32_t s_rx_word[NB_A429_DATA];   /* received A429 Data  */
   tu_a429_rx_fault_word s_rx_status;  /* status word of the A429 command returned by the OSS_PU */
}
ts_a429_rx;


/* Bits field of ICDL READ fault word */
typedef struct
{
   uint32_t s_spare_31_to_16           : 16; /* 31 to 16: Spare */
   uint32_t s_timestamp_old            : 1;  /* 15: Time stamp too old */
   uint32_t s_spare_14_to_07           : 8;  /* 14 to 07: Spare */
   uint32_t s_sram_parity_err          : 1;  /* 06: parity error in SRAM A429 Rx */
   uint32_t s_frame_parity_err         : 1;  /* 05: parity error on the A429 received frame  */
   uint32_t s_frame_integrity_err      : 1;  /* 04  frame integrity error*/
   uint32_t s_spare_03_to_01           : 3;  /* 03 to 01: Spare */
   uint32_t s_invalid                  : 1;  /* 00: invalid A429 command */
}
ts_icdl_rx_fault_word_u_bit;

/* ICDL READ fault word */
typedef union
{
   uint32_t u_word;                    /* ICDL fault word accessed by 32-bit word */
   ts_icdl_rx_fault_word_u_bit u_bit;  /* ICDL fault word accessed bit by bit */
}
tu_icdl_rx_fault_word;

/* ICDL READ message */
typedef struct
{
   uint32_t    s_length;
   uint32_t    s_port;
   uint8_t     s_data_buffer[ICDL_BUFFER_SIZE];
} ts_icdl_message_element_rx ;

typedef struct
{
   tu_icdl_rx_fault_word      s_status;
   ts_icdl_message_element_rx rx_message_tab[ICDL_AS_NB_PORT]; /* 1 message per port */
}
ts_icdl_rx;

/* Bits field of ICDL WRITE fault word */
typedef struct
{
   uint32_t s_spare_31_to_13           : 19; /* 31 to 13: Spare */
   uint32_t s_fifo_full                : 1;  /* 12: fifo full */
   uint32_t s_spare_11_to_07           : 5;  /* 11 to 07: Spare */
   uint32_t s_fifo_double_bit_err      : 1;  /* 06: FIFO double bit error */
   uint32_t s_fifo_overflow            : 1;  /* 05: fifo overflow  */
   uint32_t s_frame_err                : 1;  /* 04  frame  error*/
   uint32_t s_spare_03_to_02           : 2;  /* 03 to 02: Spare */
   uint32_t s_unavailable              : 1;  /* 01:  busy (service unavailable) */
   uint32_t s_invalid                  : 1;  /* 00: invalid A429 command */
}
ts_icdl_tx_fault_word_u_bit;

/* ICDL WRITE fault word */
typedef union
{
   uint32_t u_word;                    /* ICDL fault word accessed by 32-bit word */
   ts_icdl_tx_fault_word_u_bit u_bit;  /* ICDL fault word accessed bit by bit */
}
tu_icdl_tx_fault_word;

/* ICDL WRITE functionality in shared memory */
typedef struct
{
   uint32_t    s_length;
   uint32_t    s_port;
   uint8_t     s_data_buffer[ICDL_BUFFER_SIZE];
} ts_icdl_message_element_tx ;

typedef struct
{
   tu_icdl_tx_fault_word      s_status;
   ts_icdl_message_element_tx tx_message_tab[ICDL_AS_NB_PORT] ; /* 1 message per port */
}
ts_icdl_tx;

/* CHANNEL STATE READ functionality in shared memory */
typedef struct
{
   uint32_t s_channel_state;  /* Control state of the current channel. */
   uint32_t s_channel_pref;   /* Preferential state of the current channel. */
   uint32_t s_channel_sync;   /* Synchronization state between the channels. */
}
ts_chan_state;

/* PT_REF READ functionality in shared memory */
typedef struct
{
   uint8_t s_eecu_ref[REF_SIZE];          /* Reference of the EECU */
   uint8_t s_eecu_sn[SERIAL_SIZE];        /* Serial number of the EECU*/
   uint8_t s_oll_ref[REF_SIZE];           /* Reference of the OLL */
   uint8_t s_oll_rev[SERIAL_SIZE];        /* Revision of the OLL*/
   uint32_t s_oll_crc;                    /* CRC of OLL */
   uint8_t s_boot_ref[REF_SIZE];          /* Reference of the BOOT */
   uint8_t s_boot_rev[SERIAL_SIZE];       /* Revision  of the BOOT*/
   uint32_t s_boot_crc;                   /* CRC of BOOT */
   uint8_t s_oss_param_ref[REF_SIZE];     /* Reference of the OSS parameter table */
   uint8_t s_oss_param_rev[SERIAL_SIZE];  /* Revision  of the OSS parameter table*/
   uint32_t s_oss_param_crc;              /* CRC of OSS parameter table */
   uint8_t s_oss_ref[REF_SIZE];           /* Reference of the OSS  */
   uint8_t s_oss_rev[SERIAL_SIZE];         /* Revision  of the OSS */
   uint32_t s_oss_crc;                    /* CRC of OSS */
   uint8_t s_css_param_ref[REF_SIZE];     /* Reference of the CSS parameter table */
   uint8_t s_css_param_rev[SERIAL_SIZE];   /* Revision  of the CSS parameter table*/
   uint32_t s_css_param_crc;              /* CRC of CSS parameter table */
   uint8_t s_css_ref[REF_SIZE];           /* Reference of the CSS  */
   uint8_t s_css_rev[SERIAL_SIZE];         /* Revision  of the CSS */
   uint32_t s_css_crc;                    /* CRC of CSS */
   uint8_t s_mcss_param_ref[REF_SIZE];    /* Reference of the MCSS parameter table */
   uint8_t s_mcss_param_rev[SERIAL_SIZE];  /* Revision  of the MCSS parameter table*/
   uint32_t s_mcss_param_crc;             /* CRC of MCSS parameter table */
   uint8_t s_mcss_ref[REF_SIZE];          /* Reference of the MCSS  */
   uint8_t s_mcss_rev[SERIAL_SIZE];        /* Revision  of the MCSS */
   uint32_t s_mcss_crc;                   /* CRC of MCSS */
   uint8_t s_oll_cert_ref[REF_SIZE];      /* Reference of the OLL certificate table */
   uint8_t s_oll_cert_rev[SERIAL_SIZE];    /* Revision  of the OLL certificate table*/
   uint32_t s_oll_cert_crc;               /* CRC of OLL certificate table */
}
ts_pt_ref;

/* Bits field of Alternator power fault word */
typedef struct
{
   uint32_t s_not_selected    : 1;  /* 31: Is pw NGALT not selected ? */
   uint32_t s_open_phase      : 1;  /* 30: Is pw NGALT in open phase ? */
   uint32_t s_short_circuit   : 1;  /* 29: Is pw NGALT open circuit ? */
   uint32_t s_spare_28_to_06  :23;  /* 28 to 06: Spare*/
   uint32_t s_i2c_not_working : 1;  /* 05: I2C communication failed */
   uint32_t s_spare_04_to_02  : 3;  /* 04 to 02: Spare */
   uint32_t s_unavailable     : 1;  /* 01 : Is pw NGALT unavailable */
   uint32_t s_invalid         : 1;  /* 00: Is pw NGALT invalid ? */
}
ts_pw_alt_fault_word_u_bit;

/* Bits field of 28V A/C fault word */
typedef struct
{
   uint32_t s_out_of_range_low  : 1;  /* 31: Is 28V A/C voltage out of range low  */
   uint32_t s_out_of_range_high : 1;  /* 30: Is 28V A/C voltage out of range high */
   uint32_t s_glob_switch_fault : 1;  /* 29: 28V A/C switch fault                 */
   uint32_t s_switch_fault_high : 1;  /* 28: 28V A/C high side switch fault       */
   uint32_t s_switch_fault_low  : 1;  /* 27: 28V A/C low side switch fault        */
   uint32_t s_spare_26_to_24    : 3;  /* 26 to 24: Spare                          */
   uint32_t s_is_disc           : 1;  /* 23: Is 28V A/C low disconnected ?        */
   uint32_t s_spare_22_to_06    :17;  /* 22 to 06: Spare                          */
   uint32_t s_i2c_not_working   : 1;  /* 05: I2C communication failed             */
   uint32_t s_spare_04_to_02    : 3;  /* 04 to 02: Spare                          */
   uint32_t s_unavailable       : 1;  /* 01: Is 28V A/C unavailable ?             */
   uint32_t s_spare_00          : 1;  /* 00: Spare                                */
}
ts_pw_28v_fault_word_u_bit;

typedef union
{
   uint32_t                   u_word;     /* alternator power fault word accessed by 32-bit word */
   ts_pw_alt_fault_word_u_bit u_bit;     /* alternator power fault word accessed bit by bit */
}
tu_pw_alt_fault_word;


typedef union
{
   uint32_t                   u_word;      /* 28V A/C fault word accessed by 32-bit word */
   ts_pw_28v_fault_word_u_bit u_bit;       /* 28V A/C fault word accessed bit by bit */
}
tu_pw_28v_fault_word;

/* POWER_SOURCE_READ functionality in shared memory */
typedef struct
{
   tu_pw_alt_fault_word s_pw_alt_fault;  /* alternator power source fault  */
   tu_pw_28v_fault_word s_pw_28v_fault;  /* 28V power source fault */
}
ts_pw_srce_r;


/* Bits field of OVS STATE READ fault word */
typedef struct
{
   uint32_t s_incons_ntlos_hs          : 1;  /* 31: Freq inconsistency between NTLOS1 and NTLOS2 on HS */
   uint32_t s_incons_ntlos_lss         : 1;  /* 30: Freq inconsistency between NTLOS1 and NTLOS2 on LS*/
   uint32_t s_incons_ngos_hs           : 1;  /* 29: Freq inconsistency between NGOS1 and NGOS2 on HS */
   uint32_t s_incons_ngos_ls           : 1;  /* 28: Freq inconsistency between NGOS1 and NGOS2 on LS*/
   uint32_t s_incons_ntlos_hs_ls       : 1;  /* 27: Freq inconsistency on NTLOS between HS and LS */
   uint32_t s_incons_ngos_hs_ls        : 1;  /* 26: Freq inconsistency on NTLOS  between HS and  LS */
   uint32_t s__spare_25_to_24          : 2;  /* 25 to 24: Spare */
   uint32_t s_cam_err_cmd_ls           : 1;  /* 23: Erroneous command LS or CAM short to GND HS or LS */
   uint32_t s_cam_err_cmd_hs           : 1;  /* 22: CAM erroneous command HS or short to 28V */
   uint32_t s_cam_out_open_circuit     : 1;  /* 21: CAM output Open circuit */
   uint32_t s_spare_20_to_19           : 2;  /* 20 to 19: Spare */
   uint32_t s_current_voltage_invalid  : 1;  /* 18: invalid current or voltage measurement*/
   uint32_t s_cam_fully_activated      : 1;  /* 17: CAM fully activated (voltage and current) */
   uint32_t s_cam_activated            : 1;  /* 16: CAM activated (voltage only) */
   uint32_t s__spare_15_to_14          : 2;  /* 15 to 14: Spare */
   uint32_t s_dininhib_state           : 1;  /* 13: DININHIB discrete input state */
   uint32_t s_doutinhib_state          : 1;  /* 12: DOUTINHIB discrete output state */
   uint32_t s_spare_11_to_08           : 4;  /* 11 to 08: Spare */
   uint32_t s_com_error                : 1;  /* 07: Comm error or no comm with OVS (OVS may be in Fail State) */
   uint32_t s_ovsp_config_integ        : 1;  /* 06: OVSP Config Integrity fault (0=OK ; 1=NOK) */
   uint32_t s_spare_05                 : 1;  /* 05: Spare */
   uint32_t s_err_css_command          : 1;  /* 04: monitoring inconsistency between OVSP HS and OVSP LS */
   uint32_t s_fault_detected_hs        : 1;  /* 03: Fault detected on OVS HS */
   uint32_t s_fault_detected_ls        : 1;  /* 02: Fault detected on OVS LS */
   uint32_t s_ovs_trigger_test_status  : 1;  /* 01: Trigger test in progress status */
   uint32_t s_invalid                  : 1;  /* 00: OVSP invalidity bit */
}
ts_ovs_state_fault_word_u_bit;

/* OVS STATE READ fault word */
typedef union
{
   uint32_t u_word;                    /* ICDL fault word accessed by 32-bit word */
   ts_ovs_state_fault_word_u_bit u_bit;  /* ICDL fault word accessed bit by bit */
}
tu_ovs_state_word;

typedef struct
{
   uint32_t s_power_up_count;      /* number of power up on the channel */
   uint32_t s_first_power_up_time; /* elapsed time since the first power up  */
   uint32_t s_last_power_up_time;  /* elapsed time since the last power up  */
}
ts_date;


/* OSS_PU COUNTERS READ functionality in shared memory */
typedef struct
{
   uint32_t  s_pw_up_count;             /* number of power up */
   uint32_t  s_first_power_up_time;     /* elapsed time since the first power up */
   uint32_t  s_last_power_up_time;      /* elapsed time since the last power up */
   uint32_t  s_fast_task_count;         /* number of call of the fast task since the last power up */
   uint32_t  s_last_max_ft_time;        /* maximum execution time of the fast task during the previous power up*/
   ts_date   s_last_max_ft_date;        /* date of the fast task with the max exec time during the previous power up*/
   uint32_t  s_max_last_max_ft_time;    /* maximum execution time of the fast task */
   ts_date   s_max_last_max_ft_date;    /* date of the fast task with the max execution time */
   uint32_t  s_last_max_st_time;        /* maximum execution time of the slow task during the previous power up*/
   ts_date   s_last_max_st_date;        /* date of the slow task with the max exec time during the previous power up*/
   uint32_t  s_max_last_max_st_time;    /* maximum execution time of the slow task */
   ts_date   s_max_last_max_st_date;    /* date of the slow task with the maximum execution time */
   uint32_t  s_last_max_vst_time;       /* maximum execution time of the very slow task during the previous power up*/
   ts_date   s_last_max_vst_date;       /* date of very slow task with max exec time during the previous power up*/
   uint32_t  s_max_last_max_vst_time;   /* maximum execution time of the very slow task */
   ts_date   s_max_last_max_vst_date;   /* date of the very slow task with the maximum execution time */
   uint32_t  s_last_max_bg_time;        /* maximum execution time of the background task during the previous power up*/
   ts_date   s_last_max_bg_date;        /* date of very background task with max exec time during the previous power up*/
   uint32_t  s_max_last_max_bg_time;    /* maximum execution time of the background task */
   ts_date   s_max_last_max_bg_date;    /* date of the background task with the maximum execution time */
   uint32_t  s_last_max_oa_time;        /* maximum time execution of the OSS_PU during the previous power up */
   uint32_t  s_max_last_max_oa_time;    /* maximum time execution of the OSS_PU */
   float32_t s_max_tecu;                /* maximum temperature value of TECU */
   ts_date   s_max_tecu_date;           /* date fo the maximum temperature value of TECU */
   float32_t s_twear;                   /* thermal wear counter */
}
ts_oss_counter;


/* Bits field of P0 fault word */
typedef struct
{
   uint32_t s_spare_31_to_16        : 16; /* 31 to 16: Spare */
   uint32_t s_p0_int_cbit_fault     : 1;  /* 15: P0 internal CBIT fault detection */
   uint32_t s_p0_update_frame_fault : 1;  /* 14: P0 update frame fault */
   uint32_t s_p0_fatal_fault        : 1;  /* 13: P0 fatal fault (P0 discrete set) */
   uint32_t s_spare_12_to_08        : 5;  /* 12 to 08: Spare */
   uint32_t s_out_of_range          : 1;  /* 07: Out of range (on final measure) */
   uint32_t spare_06                : 1;  /* 06: spare */
   uint32_t s_p0_com_fault          : 1;  /* 05: P0 communication fault */
   uint32_t spare_04_to_02          : 3;  /* 04 to 02: spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: P0 invalid  */
}
ts_p0_fault_word_u_bit;

/* P0 fault word */
typedef union
{
   uint32_t u_word;              /* P0 fault word accessed by 32-bit word */
   ts_p0_fault_word_u_bit u_bit; /* P0 fault word accessed bit by bit */
}
tu_p0_fault_word;

/* P0 functionality in shared memory */
typedef struct
{
   float32_t s_measure;             /* Measure acquired and processed */
   tu_p0_fault_word s_fault_word;   /* Fault word of the P0 returned by the OSS_PU */
}
ts_p0;

/* Bits field of NGOS fault word */
typedef struct
{
   uint32_t s_open_circuit          : 1;  /* 31: NGOS open circuit on High or Low side */
   uint32_t s_short_diff            : 1;  /* 30: NGOS short differential */
   uint32_t s_spare_29_to_16        : 14; /* 29 to 16: Spare */
   uint32_t s_incons_NGOS1_NGALT    : 1;  /* 15: Freq inconsistency NGOS1-NGALT detected on HS and LS*/
   uint32_t s_spare_14_to_09        : 6;  /* 14 to 09: Spare */
   uint32_t s_time_out              : 1;  /* 08: TimeOut detected by OVSP HS and LS*/
   uint32_t s_out_of_range          : 1;  /* 07: Out of range detected by OVSP HS and LS*/
   uint32_t spare_06                : 1;  /* 06: spare */
   uint32_t s_transfer_err          : 1;  /* 05: CAN OVS error on HS and LS */
   uint32_t s_intern_failure        : 1;  /* Internal failure (real of ground measurement */
   uint32_t spare_03_to_01          : 3;  /* 03 to 01: spare */
   uint32_t s_invalid               : 1;  /* 00: NGOS invalid measure  */
}
ts_ngos_fault_word_u_bit;

/* NGOS fault word */
typedef union
{
   uint32_t u_word;              /* NGOS fault word accessed by 32-bit word */
   ts_ngos_fault_word_u_bit u_bit; /* NGOS fault word accessed bit by bit */
}
tu_ngos_fault_word;

/* NGOS functionality in shared memory */
typedef struct
{
   float32_t s_measure;             /* Measure acquired and processed */
   tu_ngos_fault_word s_fault_word;   /* Fault word of the NGOS returned by the OSS_PU */
}
ts_ngos;


/* Bits field of NTLOS fault word */
typedef struct
{
   uint32_t s_open_circuit          : 1;  /* 31: NGOS open circuit on High or Low side */
   uint32_t s_short_diff            : 1;  /* 30: NGOS short differential */
   uint32_t s_spare_29_to_16        : 14; /* 29 to 16: Spare */
   uint32_t s_incons_NTLOS1_NFREQ2  : 1;  /* 15: Freq inconsistency NTLOS1-NFREQ2 detected on HS and LS*/
   uint32_t s_spare_14_to_09        : 6;  /* 14 to 09: Spare */
   uint32_t s_time_out              : 1;  /* 08: TimeOut detected by OVSP HS and LS*/
   uint32_t s_out_of_range          : 1;  /* 07: Out of range detected by OVSP HS and LS*/
   uint32_t spare_06                : 1;  /* 06: spare */
   uint32_t s_transfer_err          : 1;  /* 05: CAN OVS error on HS and LS */
   uint32_t s_intern_failure        : 1;  /* Internal failure (real of ground measurement */
   uint32_t spare_03_to_01          : 3;  /* 03 to 01: spare */
   uint32_t s_invalid               : 1;  /* 00: NTLOS invalid measure  */
}
ts_ntlos_fault_word_u_bit;

/* NTLOS fault word */
typedef union
{
   uint32_t u_word;                 /* NTLOS fault word accessed by 32-bit word */
   ts_ntlos_fault_word_u_bit u_bit; /* NTLOS fault word accessed bit by bit */
}
tu_ntlos_fault_word;

/* NTLOS functionality in shared memory */
typedef struct
{
   float32_t s_measure;                /* Measure acquired and processed */
   tu_ntlos_fault_word s_fault_word;   /* Fault word of the NTLOS returned by the OSS_PU */
}
ts_ntlos;


/* DIN READ functionality in shared memory */
typedef struct
{
   uint32_t s_raw_measure[DIN_NB];                /* Raw Measure acquired */
   uint32_t s_filt_measure[DIN_NB];                /* filtered Measure processed */
}
ts_din;


/* Bits field of SVOI fault word */
typedef struct
{
   uint32_t s_spare_31_to_22        : 10; /* 31 to 22: Spare */
   uint32_t s_short_gnd             : 1;  /* 21: short to ground*/
   uint32_t s_spare_20_to_02        : 19;  /* 20 to 02: Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: svoi invalid measure  */
}
ts_svoi_fault_word_u_bit;

/* SVOI fault word */
typedef union
{
   uint32_t u_word;                 /* SVOI fault word accessed by 32-bit word */
   ts_svoi_fault_word_u_bit u_bit; /* SVOI fault word accessed bit by bit */
}
tu_svoi_fault_word;

/* SVOI READ functionality in shared memory */
typedef struct
{
   uint32_t s_raw_measure;                /* Raw Measure acquired */
   uint32_t s_filt_measure;               /* filtered Measure processed */
   tu_svoi_fault_word s_fault_word;       /* Fault word of the SVOI returned by the OSS_PU */
}
ts_svoi;

/* Bits field of EMAN fault word */
typedef struct
{
   uint32_t s_spare_31_to_22        : 10; /* 31 to 22: Spare */
   uint32_t s_short_gnd             : 1;  /* 21: short to ground*/
   uint32_t s_spare_20_to_02        : 19;  /* 20 to 02: Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: eman invalid measure  */
}
ts_eman_fault_word_u_bit;

/* EMAN fault word */
typedef union
{
   uint32_t u_word;                 /* EMAN fault word accessed by 32-bit word */
   ts_eman_fault_word_u_bit u_bit; /* EMAN fault word accessed bit by bit */
}
tu_eman_fault_word;

/* EMAN READ functionality in shared memory */
typedef struct
{
   uint32_t s_raw_measure;                /* Raw Measure acquired */
   uint32_t s_filt_measure;               /* filtered Measure processed */
   tu_eman_fault_word s_fault_word;       /* Fault word of the EMAN returned by the OSS_PU */
}
ts_eman;

/* CONTINUOUS TEST READ functionality in shared memory */
typedef struct
{
   uint32_t s_ct_nvm_status;                /* MRAM CBIT status */
   uint32_t s_int_pwr_status;               /* Internal Power supply CBIT status */
}
ts_cbit_status;


/* Bits field of HEALTH_WORD_STATUS */
typedef struct
{
   uint32_t s_spare_31_to_05        : 27; /* 31 to 05 : Spare */
   uint32_t s_cpu_err               : 1;  /* 04: CPU Failure on the local channel */
   uint32_t s_mcss_inconsistency    : 1;  /* 03: MCSS inconsistency between local channel and opposite channel*/
   uint32_t s_css_control_imposs    : 1;  /* 02: impossibility for css to control the local channel*/
   uint32_t s_css_control_refuse    : 1;  /* 01: control refuse of css on the local channel*/
   uint32_t s_css_pref_refuse       : 1;  /* 00  preferential refuse of css on the local channel*/
}
ts_health_fault_word_u_bit;

/*  HEALTH_WORD_STATUS */
typedef union
{
   uint32_t u_word;                       /* EMAN fault word accessed by 32-bit word */
   ts_health_fault_word_u_bit u_bit;      /* EMAN fault word accessed bit by bit */
}
tu_health_word;

typedef struct
{
   uint32_t s_spare_31_to_20       : 12;      /* 31 to 22 : Spare */
   uint32_t s_inconsistency_status : 1;       /* 19 : inconsistency fault*/
   uint32_t s_spare_18_to_15       : 4;       /* 18 to 15 : Spare */
   uint32_t s_opp_inconsistent     : 1;       /* 14 : accom_opp_inconsistent input bit */
   uint32_t s_opp_inconsistent_n   : 1;       /* 13 : accom_opp_inconsistent_n input bit */
   uint32_t s_spare_10_to_00       : 13;      /* 12 to 00 : Spare */
}
ts_local_mcss_inconsistency;

typedef union
{
   ts_local_mcss_inconsistency   u_bit;
   uint32_t                      u_word;
}
tu_local_mcss_inconsistency;

/* Bits field of Tx fault word */
typedef struct
{
   uint32_t s_meas1_oc_fault        : 1;  /* 31: Open circuit on measure 1*/
   uint32_t s_meas1_short_diff      : 1;  /* 30: short differential on measure 1*/
   uint32_t s_meas1_short_gnd       : 1;  /* 29: short to ground*/
   uint32_t s_spare_28_to_24        : 5;  /* 28 to 24: Spare */
   uint32_t s_exc_oc_fault          : 1;  /* 23: Open circuit on excitation*/
   uint32_t s_exc_short_diff        : 1;  /* 22: short differential or overload on excitation*/
   uint32_t s_exc_short_gnd         : 1;  /* 21: short to ground on excitation*/
   uint32_t s_spare_20_to_08        : 13;  /* 20 to 08: Spare */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_05        : 2;  /* 06 to 05: Spare */
   uint32_t s_internal_failure      : 1;  /* 04: internal failure */
   uint32_t s_spare_03_to_02        : 2;  /* 03 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_temp_fault_word_u_bit;

/* Tx fault word */
typedef union
{
   uint32_t u_word;                 /* fault word accessed by 32-bit word */
   ts_temp_fault_word_u_bit u_bit;  /* fault word accessed bit by bit */
}
tu_temp_fault_word;

/* Tx READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                /*  Measure acquired */
   tu_temp_fault_word s_fault_word;    /* Fault word of the Tx returned by the OSS_PU */
}
ts_temp;

/* Bits field of T4 fault word */
typedef struct
{
   uint32_t s_meas1_oc_fault        : 1;  /* 31: Open circuit*/
   uint32_t s_spare_30_to_25        : 6;  /* 30 to 25: spare*/
   uint32_t s_tcj_out_of_range      : 1;  /* 24: out of range: TCJ*/
   uint32_t s_spare_23_to_16        : 8;  /* 28 to 16: Spare */
   uint32_t s_tcj_status            : 1;  /* 15: TCJ status*/
   uint32_t s_spare_14_to_08        : 7;  /* 14 to 08: Spare */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_05        : 2;  /* 06 to 05: Spare */
   uint32_t s_internal_failure      : 1;  /* 04: internal failure */
   uint32_t s_spare_03_to_02        : 2;  /* 03 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_temp4_fault_word_u_bit;

/* T4 fault word */
typedef union
{
   uint32_t u_word;                 /* fault word accessed by 32-bit word */
   ts_temp4_fault_word_u_bit u_bit;  /* fault word accessed bit by bit */
}
tu_temp4_fault_word;

/* T4 READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                /*  Measure acquired */
   tu_temp4_fault_word s_fault_word;    /* Fault word of the Tx returned by the OSS_PU */
}
ts_temp4;

/* Bits field of POTx fault word */
typedef struct
{
   uint32_t s_meas_oc_fault         : 1;  /* 31: Open circuit*/
   uint32_t s_meas_short_diff       : 1;  /* 30: Short to diff */
   uint32_t s_meas_short_gnd        : 1;  /* 29: short to ground*/
   uint32_t s_spare_28_to_24        : 5;  /* 28 to 24: Spare */
   uint32_t s_exc_oc_fault          : 1;  /* 23: Excitation open circuit */
   uint32_t s_exc_short_diff        : 1;  /* 22: Excitation short differential */
   uint32_t s_exc_short_gnd         : 1;  /* 21: Excitation short to ground HS or LS */
   uint32_t s_exc_short_gnd_ls      : 1;  /* 20: Excitation short to ground LS */
   uint32_t s_exc_short_to_signal   : 1;  /* 19: Excitation short to signal */
   uint32_t s_exc_out_of_range      : 1;  /* 18: Excitation out of range */
   uint32_t s_spare_17_to_08        : 10;  /* 17 to 08: Spare */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_05        : 2;  /* 06 to 05: Spare */
   uint32_t s_internal_failure      : 1;  /* 04: internal failure (ref or gnd measurement) */
   uint32_t s_spare_03_to_02        : 2;  /* 03 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_pot_fault_word_u_bit;

/* POTx fault word */
typedef union
{
   uint32_t u_word;                 /* fault word accessed by 32-bit word */
   ts_pot_fault_word_u_bit u_bit;   /* fault word accessed bit by bit */
}
tu_pot_fault_word;


/* POTx READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                /*  Measure acquired */
   tu_pot_fault_word s_fault_word;     /* Fault word of the POTx returned by the OSS_PU */
}
ts_pot;

/* Bits field of POTDIFFx fault word */
typedef struct
{
   uint32_t s_meas_oc_fault         : 1;  /* 31: Open circuit*/
   uint32_t s_meas_short_diff       : 1;  /* 30: Short to diff */
   uint32_t s_meas_short_gnd        : 1;  /* 29: Short to ground */
   uint32_t s_spare_28_to_08        : 21;  /* 28 to 08: Spare */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_05        : 2;  /* 06 to 05: Spare */
   uint32_t s_internal_failure      : 1;  /* 04: internal failure (ref or gnd measurement) */
   uint32_t s_spare_03_to_02        : 2;  /* 03 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_potdiff_fault_word_u_bit;

/* POTDIFFx fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_potdiff_fault_word_u_bit u_bit;  /* fault word accessed bit by bit */
}
tu_potdiff_fault_word;


/* POTDIFFx READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                /*  Measure acquired */
   tu_potdiff_fault_word s_fault_word; /* Fault word of the POTDIFFx returned by the OSS_PU */
}
ts_potdiff;

/* Bits field of TECU fault word */
typedef struct
{
   uint32_t s_spare_31_to_18        : 13;  /* 31 to 19 : spare*/
   uint32_t s_err_taccom            : 1;   /* 18: TACCOM invalid or out of range*/
   uint32_t s_err_tcu1              : 1;   /* 17: TCU1 invalid or out of range*/
   uint32_t s_err_tcu2              : 1;   /* 16: TCU2 invalid or out of range*/
   uint32_t s_err_tpsf              : 1;   /* 15: TPFS invalid or out of range*/
   uint32_t s_err_tcj               : 1;   /* 14: TCJ invalid or out of range*/
   uint32_t s_err_tohs              : 1;   /* 13: TOHS invalid or out of range*/
   uint32_t s_err_tols              : 1;   /* 12: TOLS invalid or out of range*/
   uint32_t s_spare_11_to_08        : 4;  /* 11 to 08: Spare */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_02        : 5;  /* 11 to 08: Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_tecu_fault_word_u_bit;

/* TECU fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_tecu_fault_word_u_bit u_bit;     /* fault word accessed bit by bit */
}
tu_tecu_fault_word;


/* TECUx READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                /*  Measure acquired */
   tu_tecu_fault_word s_fault_word; /* Fault word of the TECU returned by the OSS_PU */
}
ts_tecu;


/* Bits field of NFREQ2-4 fault word */
typedef struct
{
   uint32_t s_meas_oc_fault         : 1;  /* 31: Open circuit*/
   uint32_t s_spare_30              : 1;  /* 30: spare*/
   uint32_t s_meas_short_gnd        : 1;  /* 29: short to ground*/
   uint32_t s_spare_28_to_12        : 17; /* 28 to 12: Spare */
   uint32_t s_freq_parity_err       : 1;  /* 11: parity error (freq inputs buffer error) */
   uint32_t s_freq_overflow         : 1;  /* 10: overflow error (freq inputs buffer error) */
   uint32_t s_freq_inconsistency    : 1;  /* 09: inconsistency (freq inputs) */
   uint32_t s_freq_time_out         : 1;  /* 08: time out (freq inputs) */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_02        : 5;  /* 06 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_nfreq24_fault_word_u_bit;

/* NFREQ2-4 fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_nfreq24_fault_word_u_bit u_bit;     /* fault word accessed bit by bit */
}
tu_nfreq24_fault_word;

/* NFREQ2 READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                      /* Calculated measure */
   float32_t s_t_measure[NFREQ2_MAX_MEAS_NB]; /* Acquired periods */
   uint32_t  s_t_sample_count;               /* Number of acquired periods */
   tu_nfreq24_fault_word s_fault_word;       /* Fault word of the NFREQ2 returned by the OSS_PU */
}
ts_nfreq2;

/* NFREQ4 READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                      /* Calculated measure */
   float32_t s_t_measure[NFREQ4_MAX_MEAS_NB]; /* Acquired periods */
   uint32_t  s_t_sample_count;               /* Number of acquired periods */
   tu_nfreq24_fault_word s_fault_word;       /* Fault word of the NFREQ4 returned by the OSS_PU */
}
ts_nfreq4;
/* Bits field of NFREQ2-4 fault word */
typedef struct
{
   uint32_t s_meas_oc_fault         : 1;  /* 31: Open circuit*/
   uint32_t s_spare_30              : 1;  /* 30: spare*/
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
ts_nfreq3_fault_word_u_bit;

/* NFREQ3 fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_nfreq3_fault_word_u_bit u_bit;   /* fault word accessed bit by bit */
}
tu_nfreq3_fault_word;

/* NFREQ3 READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                        /* Calculated measure */
   float32_t s_ratio;                          /* Calculated ratio */
   float32_t s_t_measure[NFREQ3_MAX_MEAS_NB];  /* Acquired periods */
   float32_t s_tpn_measure[NFREQ3_MAX_MEAS_NB];/*  Measure acquired */
   uint32_t  s_t_sample_count;                 /* Number of acquired periods */
   tu_nfreq3_fault_word s_fault_word;          /* Fault word of the NFREQ3 returned by the OSS_PU */
}
ts_nfreq3;

/* Bits field of NGALT fault word */
typedef struct
{
   uint32_t s_meas_oc_fault         : 1;  /* 31: Open circuit*/
   uint32_t s_meas_short_diff       : 1;  /* 30: short differential (short between phases)*/
   uint32_t s_spare_29_to_12        : 18; /* 29 to 12: Spare */
   uint32_t s_freq_parity_err       : 1;  /* 11: parity error (freq inputs buffer error) */
   uint32_t s_freq_overflow         : 1;  /* 10: overflow error (freq inputs buffer error) */
   uint32_t s_freq_inconsistency    : 1;  /* 09: inconsistency (freq inputs) */
   uint32_t s_freq_time_out         : 1;  /* 08: time out (freq inputs) */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_02        : 5;  /* 06 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_ngalt_fault_word_u_bit;

/* NGALT fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_ngalt_fault_word_u_bit u_bit;    /* fault word accessed bit by bit */
}
tu_ngalt_fault_word;


/* NGALT READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;                      /* Calculated measure */
   float32_t s_t_measure[NGALT_MAX_MEAS_NB];  /* Acquired periods */
   uint32_t  s_t_sample_count;               /* Number of acquired periods */
   tu_ngalt_fault_word s_fault_word;         /* Fault word of the NGALT returned by the OSS_PU */
}
ts_ngalt;


/* Bits field of LVDT fault word */
typedef struct
{
   uint32_t s_meas1_oc_fault        : 1;  /* 31: Open circuit on measure 1*/
   uint32_t s_meas1_short_diff      : 1;  /* 30: short differential on measure 1*/
   uint32_t s_meas1_short_gnd       : 1;  /* 29: short to ground on measure 1*/
   uint32_t s_meas1_out_of_range    : 1;  /* 28: out of range on measure 1*/
   uint32_t s_meas2_oc_fault        : 1;  /* 27: Open circuit on measure 2*/
   uint32_t s_meas2_short_diff      : 1;  /* 26: short differential on measure 2*/
   uint32_t s_meas2_short_gnd       : 1;  /* 25: short to ground on measure 2*/
   uint32_t s_meas2_out_of_range    : 1;  /* 24: out of range on measure 2*/
   uint32_t s_exc_oc_fault          : 1;  /* 23: Open circuit on excitation*/
   uint32_t s_exc_short_diff        : 1;  /* 22: short differential on excitation or overload*/
   uint32_t s_exc_short_to_gnd      : 1;  /* 21: Is excitation measure short to gnd ? */
   uint32_t s_spare_20_to_19        : 2;  /* 20 to 19: Spare */
   uint32_t s_exc_out_of_range      : 1;  /* 18: out of range on excitation*/
   uint32_t s_spare_17_to_08        : 10; /* 17 to 08: Spare */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_05        : 2;  /* 06 to 05 : Spare */
   uint32_t s_int_failure           : 1;  /* 04: internal failure */
   uint32_t s_spare_03_to_02        : 2;  /* 03 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_lvdt_fault_word_u_bit;

/* LVDT fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_lvdt_fault_word_u_bit u_bit;    /* fault word accessed bit by bit */
}
tu_lvdt_fault_word;

/* LVDT READ functionality in shared memory */
typedef struct
{
   float32_t s_measure;             /*  ratio Measure */
   float32_t s_vs1_measure;         /*  Vs1/Vexc Measure  */
   float32_t s_vs2_measure;         /*  Vs2/Vexc Measure  */
   tu_lvdt_fault_word s_fault_word; /* Fault word of the LVDT returned by the OSS_PU */
}
ts_lvdt;

/* Bits field of CALRES fault word */
typedef struct
{
   uint32_t s_meas1_oc_fault        : 1;  /* 31: Open circuit on measure 1 */
   uint32_t s_spare_30              : 1;  /* 30: spare*/
   uint32_t s_meas1_short_gnd       : 1;  /* 29: Short to ground on measure 1 */
   uint32_t s_meas1_out_of_range    : 1;  /* 28: Out of range on measure 1 */
   uint32_t s_meas2_oc_fault        : 1;  /* 27: Open circuit on measure 2 */
   uint32_t s_spare_260             : 1;  /* 26: spare*/
   uint32_t s_meas2_short_gnd       : 1;  /* 25: Short to ground on measure 2 */
   uint32_t s_meas2_out_of_range    : 1;  /* 24: Out of range on measure 2 */
   uint32_t s_spare_23_to_08        : 16;  /* 23 to 08: spare */
   uint32_t s_out_of_range          : 1;  /* 07: out of range on final measure */
   uint32_t s_spare_06_to_05        : 2;  /* 06 to 05 : Spare */
   uint32_t s_int_failure           : 1;  /* 04: internal failure */
   uint32_t s_spare_03_to_02        : 2;  /* 03 to 02 : Spare */
   uint32_t s_unavailable           : 1;  /* 01: unavailable */
   uint32_t s_invalid               : 1;  /* 00: invalid measure  */
}
ts_calres_fault_word_u_bit;

/* CALRES fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_calres_fault_word_u_bit u_bit;    /* fault word accessed bit by bit */
}
tu_calres_fault_word;

/* CALRES READ functionality in shared memory */
typedef struct
{
   float32_t s_calres_measure1;         /*  calres Measure 1 */
   float32_t s_calres_measure2;         /*  calres Measure 2 */
   tu_calres_fault_word s_fault_word; /* Fault word of the CALRES returned by the OSS_PU */
}
ts_calres;



/* Bits field of CCDL TX fault word */
typedef struct
{
   uint32_t s_spare_31_to_02        : 30; /* 31-02: spare */
   uint32_t s_busy                  :  1; /* 01   : unavailable - service busy */
   uint32_t s_invalid               :  1; /* 00   : invalid measure */
}
ts_ccdl_tx_fault_word_u_bit;

/* CCDL TX fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_ccdl_tx_fault_word_u_bit u_bit;    /* fault word accessed bit by bit */
}
tu_ccdl_tx_fault_word;

/* CCDL Tx message structure */
typedef struct
{
   uint32_t s_length;                   /*  length of message */
   uint8_t s_data[CCDL_MSG_SIZE];       /*  data of message */
}
ts_ccdl_mes;


/* CCDL Tx functionality in shared memory */
typedef struct
{
   uint32_t s_index;                   /*  index of message to transmit */
   ts_ccdl_mes s_message;              /*  Message to transmit */
   tu_ccdl_tx_fault_word s_fault_word; /* Fault word of the CCDL Tx returned by the OSS_PU */
}
ts_ccdl_tx;

/* Bits field of CCDL RX fault word */
typedef struct
{
   uint32_t s_spare_31_to_17        : 15;  /* 31-17: spare                                            */
   uint32_t s_no_new_frame          :  1;  /* 16   : no new frame received since last call of service */
   uint32_t s_spare_15_to_09        :  7;  /* 15-09: spare                                            */
   uint32_t s_parity_invalid        :  1;  /* 08   : parity error                                     */
   uint32_t s_size_invalid          :  1;  /* 07   : size error                                       */
   uint32_t s_sof_invalid           :  1;  /* 06   : sof error                                        */
   uint32_t s_crc_invalid           :  1;  /* 05   : CRC error                                        */
   uint32_t s_spare_04_to_02        :  3;  /* 04-02: spare                                            */
   uint32_t s_busy                  :  1;  /* 01   : unavailable-service busy                         */
   uint32_t s_invalid               :  1;  /* 00   : invalid                                          */
}
ts_ccdl_rx_fault_word_u_bit;

/* CCDL RX fault word */
typedef union
{
   uint32_t                    u_word; /* fault word accessed by 32-bit word */
   ts_ccdl_rx_fault_word_u_bit u_bit;  /* fault word accessed bit by bit */
}
tu_ccdl_rx_fault_word;

/* CCDL Rx functionality in shared memory */
typedef struct
{
   uint32_t s_index;                   /*  index of received message  */
   ts_ccdl_mes s_message;              /*  received Message  */
   tu_ccdl_rx_fault_word s_fault_word; /* Fault word of the CCDL Rx returned by the OSS_PU */
}
ts_ccdl_rx;

/* Bits field for pbit fault word */
typedef struct
{
   uint32_t s_pbit_mram_bus_ebi    : 1;   /* 31      : MRAM bus EBI faulty          */
   uint32_t s_pbit_ovsp_hs_com     : 1;   /* 30      : OVSP HS communication faulty */
   uint32_t s_pbit_ovsp_ls_com     : 1;   /* 29      : OVSP LS communication faulty */
   uint32_t s_spare_28_to_00       : 29;  /* 28 - 00 : Spare                        */
}
ts_pbit_fault_word_u_bit;

/* Pbit fault word */
typedef union
{
   uint32_t                 u_word;       /* fault word accessed by 32-bit word */
   ts_pbit_fault_word_u_bit u_bit;        /* fault word accessed bit by bit */
}
tu_pbit_fault_word;

/* Bits field of SM WRITE fault word */
typedef struct
{
   uint32_t s_output_phase_oc          : 1;  /* 31: Open circuit phase (High or Low side) */
   uint32_t s_short_diff               : 1;  /* 30: short phase differential  */
   uint32_t s_spare_29                 : 1;  /* 29: Spare */
   uint32_t s_short_to_gnd_ls          : 1;  /* 28: short phase low side to GND */
   uint32_t s_vcom_mon_out_of_range    : 1;  /* 27: VCOM_mon out of range */
   uint32_t s_i_phase_out_of_range     : 1;  /* 26: I phase out of range*/
   uint32_t s_spare_25_to_24           : 2;  /* 25 to 24  spare */
   uint32_t s_oc_common_voltage        : 1; /* 23: Open circuit common voltage*/
   uint32_t s_short_gnd_common_voltage : 1; /* 22: Common voltage short to gnd */
   uint32_t s_short_between_phases     : 1; /* 21: Short between phases */
   uint32_t s_busy                     : 1; /* 20: Smot busy - CSS command rejected */
   uint32_t s_err_sequence             : 1; /* 19: erroneous sequence (loss of steps)*/
   uint32_t s_disconnect_fault         : 1; /* 18: Disconnect Fault */
   uint32_t s_inhibition_fault         : 1; /* 17: Inhibition Fault */
   uint32_t s_css_cmd_out_of_range     : 1; /* 16: css command out of range */
   uint32_t s_spare_15_to_01           : 15;/* 15 to 01: Spare */
   uint32_t s_invalid                  : 1; /* 00: invalid   */
}
ts_smot_fault_word_u_bit;

/* SM WRITE fault word */
typedef union
{
   uint32_t u_word;                    /* fault word accessed by 32-bit word */
   ts_smot_fault_word_u_bit u_bit;     /* fault word accessed bit by bit */
}
tu_smot_fault_word;

/* SM WRITE functionality in shared memory */
typedef struct
{
   int32_t s_half_step_nb;             /*  stepper motor command  */
   uint32_t s_position;                 /* Smot position feedback */
   float32_t s_current;                 /* Current read */
   float32_t s_voltage;                 /* Voltage read */
   tu_smot_fault_word s_fault_word;     /* Fault word of the SM WRITE returned by the OSS_PU */
}
ts_smot_w;

/* intrusive tests launch functionality in shared memory*/
typedef struct
{
   uint32_t s_cooperative_test_state;         /*  state of the cooperative tests */
   uint32_t s_din_status[DIN_NB];             /* status of the Discrete inputs ibit */
   uint32_t s_eman_status;                    /* status of the Discrete EMAN ibit */
   uint32_t s_svoi_status;                    /* status of the Discrete SVOI ibit */
   uint32_t s_t4_status;                      /* status of the T4 input ibit */
   uint32_t s_lvdta_status;                   /* status of the LVDTA input ibit */
   uint32_t s_lvdtb_status;                   /* status of the LVDTB input ibit */
   uint32_t s_lvdtc_status;                   /* status of the LVDTC input ibit */
   uint32_t s_xr_status;                      /* status of the XR input ibit */
   uint32_t s_xrb_status;                     /* status of the XRB input ibit */
   uint32_t s_calres12_status;                /* status of the CALRES 1 & 2 inputs ibit */
   uint32_t s_calres34_status;                /* status of the CALRES 3 & 4 inputs ibit */
   uint32_t s_pwr_supp_protect_status;        /* status of ibit on the protection function of power supply */
   uint32_t s_smot_status;                    /* status of the ibit on the Stepper motor output */
   uint32_t s_tmot_status;                    /* status of the ibit on the torque motor output */
   uint32_t s_pwm_status;                     /* status of the ibit on the PWM output */
   uint32_t s_pan3_status;                    /* status of the ibit on the PAN3 function */
   uint32_t s_hpdisc_status[HP_NB];           /* status of the ibit on the HP discrete outputs */
   uint32_t s_lpdisc_status[LP_NB];           /* status of the ibit on the LP discrete outputs */
   uint32_t s_wd_status;                      /* status of the ibit on the watchdog function */
   uint32_t s_rs422_status;                   /* status of the ibit on the RS422 communication link */
   uint32_t s_a429_status[A429_NB];           /* status of the ibit on the A429 communication links */
   uint32_t s_can_status[CAN_NB];             /* status of the ibit on the CAN communication links */
   uint32_t s_ccdl_status;                    /* status of the ibit on the CCDL communication link */
   uint32_t s_commut_status;                  /* status of the ibit on the commutation function */
   uint32_t s_nvm_status;                     /* status of the ibit on the MRAM areat */
   uint32_t s_consistency_oss_status;         /* status of the ibit on the OSS consistency between both channels */
   uint32_t s_consistency_oss_param_status;   /* status of the ibit on the OSS_conf consistency between both channels */
   uint32_t s_consistency_css_status;         /* status of the ibit on the CSS consistency between both channels */
   uint32_t s_consistency_css_param_status;   /* status of the ibit on the CSS_conf consistency between both channels */
   uint32_t s_consistency_mcss_status;        /* status of the ibit on the MCSS consistency between both channels */
   uint32_t s_consistency_mcss_param_status;  /* status of the ibit on the MCSS_conf consistency between both channels */
}
ts_intrusive_test;

/* OVS functionalities in shared memory*/
typedef struct
{
   uint32_t s_ovs_cmd1_on;         /* OVS detect functionality in shared memory */
   uint32_t s_ovs_cmd1_off;         /* OVS detect functionality in shared memory */
   uint32_t s_ovs_cmd2_on;         /* OVS detect functionality in shared memory */
   uint32_t s_ovs_cmd2_off;         /* OVS detect functionality in shared memory */
   uint32_t s_rearm;                /* OVS_REARM functionality in shared memory */
   uint32_t s_one_ng_sensor_auth;   /* OVS ONE NG SENSOR AUTHORIZE functionality in shared memory */
   uint32_t s_one_ntl_sensor_auth;  /* OVS ONE NTL SENSOR AUTHORIZE functionality in shared memory */
   tu_ovs_state_word s_ovs_state;   /* OVS_STATE READ functionality in shared memory */
   uint32_t s_ovs_trig_test;        /* OVS_TRIG_TEST functionality in shared memory */
   uint32_t s_ovs_trigtest_state;   /* OVS Trigtest_status RREAD functionality in shared memory */
}
ts_ovs;

/* WAN REQUEST WRITE functionality in shared memory*/
typedef struct
{
   uint32_t s_wlan_rqst;         /* is WLAN activated? */
   uint32_t s_wwan_rqst;         /* is WWAN activated?*/
}
ts_wan_request;

/* MU_ALIVE ICDL frame */
typedef struct
{
   uint32_t s_mu_heathword;              /* MU health word */
   uint32_t s_mu_icdl_a_frame_counter;   /* ICDL A frame counter*/
   uint32_t s_mu_icdl_b_frame_counter;   /* ICDL B frame counter*/
   uint32_t s_mu_os_mu_counter;          /* OS_MU counter */
}
ts_cdm_mu_alive_frame;

/* CDM STATE functionality in shared memory*/
typedef struct
{
   uint32_t s_mu_overtemp_status;  /* is no MU overtemp detected? */
   uint32_t s_mu_security_alert;   /* is MU security alert detected?*/
   uint32_t s_mu_status;           /* is MU available?*/
   ts_cdm_mu_alive_frame mu_alive_frame;
}
ts_cdm_state;






/* Implements REQ_FADEX_OS_SRD-SCHED-0050 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0070 */
/* Content of the shared memory */
typedef struct
{
   uint32_t            s_alt_rearm;        /* ALTERNATOR REARM functionality in shared memory               */
   ts_a429_rx          s_a429_1a_rx;       /* ARINC1 READ functionality in shared memory                    */
   ts_a429_tx          s_a429_1a_tx;       /* ARINC1 WRITE functionality in shared memory                   */
   ts_a429_rx          s_a429_2ab_rx;      /* ARINC2 READ functionality in shared memory                    */
   ts_a429_tx          s_a429_2ab_tx;      /* ARINC2 WRITE functionality in shared memory                   */
   ts_calres           s_calres_1_2;       /* CALRES12 functionality in shared memory                       */
   ts_calres           s_calres_3_4;       /* CALRES34 functionality in shared memory                       */
   ts_can_configure    s_can1_configure;   /* CAN 1 configuration functionality in shared memory            */
   ts_can_rx           s_can1_rx;          /* CAN 1 read functionality in shared memory                     */
   ts_can_tx           s_can1_tx;          /* CAN 1 write functionality in shared memory                    */
   ts_can_configure    s_can2_configure;   /* CAN 2 configuration functionality in shared memory            */
   ts_can_rx           s_can2_rx;          /* CAN 2 read functionality in shared memory                     */
   ts_can_tx           s_can2_tx;          /* CAN 2 write functionality in shared memory                    */
   ts_cbit_status      s_cbit_status;      /* CONTINUOUS TEST READ functionality in shared memory           */
   ts_ccdl_rx          s_ccdl_rx;          /* CCDL Rx functionality in shared memory                        */
   ts_ccdl_tx          s_ccdl_tx;          /* CCDL Tx functionality in shared memory                        */
   ts_cdm_state        s_cdm_state;        /* CDM_STATE READ functionality in shared memory                 */
   uint32_t            s_channel_id;       /* CHANNEL_ID READ functionality in shared memory                */
   ts_chan_state       s_channel_state;    /* CHANNEL STATE READ functionality in shared memory             */
   ts_din              s_din;              /* DIN READ functionality in shared memory                       */
   uint32_t            s_dld_request;      /* DATALOADING REQUEST WRITE functionality in shared memory      */
   uint32_t            s_ebreaker_enable;  /* EBREAKER ENABLE functionality in shared memory                */
   ts_eman             s_eman;             /* EMAN READ functionality in shared memory                      */
   tu_health_word      s_health_wd_status; /* HEALTH_WORD_STATUS_READ functionality in shared memory        */
   ts_hp_w             s_hp_w;             /* HP Write functionality in shared memory                       */
   ts_intrusive_test   s_ibit;             /* intrusive tests launch functionality in shared memory         */
   ts_icdl_rx          s_icdl_rx;          /* ICDL READ functionality in shared memory                      */
   ts_icdl_tx          s_icdl_tx;          /* ICDL WRITE functionality in shared memory                     */
   tu_local_mcss_inconsistency s_local_mcss_inconsistency; /* MCSS inconsistency and its status fault, as per the FPGA */
   ts_lp_w             s_lp_w;             /* LP Write functionality in shared memory                       */
   ts_lvdt             s_lvdta;            /* LVDTA functionality in shared memory                          */
   ts_lvdt             s_lvdtb;            /* LVDTB functionality in shared memory                          */
   ts_lvdt             s_lvdtc;            /* LVDTC functionality in shared memory                          */
   uint32_t            s_mcss_state;       /* MSCC_STATE READ functionality in shared memory                */
   uint32_t            s_mdin_measure;     /* MDIN READ functionality in shared memory                      */
   uint32_t            s_mu_shutdown_rqst; /* MU_SHUTDOWN_REQUEST functionality in shared mem */
   ts_nfreq2           s_nfreq2_a;         /* NFREQ 2 from channel A functionality in shared memory         */
   ts_nfreq2           s_nfreq2_b;         /* NFREQ 2 from channel B functionality in shared memory         */
   ts_nfreq3           s_nfreq3_a;         /* NFREQ 3 from channel A functionality in shared memory         */
   ts_nfreq3           s_nfreq3_b;         /* NFREQ 3 from channel B functionality in shared memory         */
   ts_nfreq4           s_nfreq4;           /* NFREQ 4 from channel A or B functionality in shared memory    */
   ts_ngalt            s_ngalt_a;          /* NGALT A from channel A functionality in shared memory         */
   ts_ngalt            s_ngalt_b;          /* NGALT A from channel A functionality in shared memory         */
   ts_ngos             s_ngos1;            /* NGOS1 READ functionality in shared memory                     */
   ts_ngos             s_ngos2;            /* NGOS2 READ functionality in shared memory                     */
   ts_ntlos            s_ntlos1;           /* NTLOS1 READ functionality in shared memory                    */
   ts_ntlos            s_ntlos2;           /* NTLOS2 READ functionality in shared memory                    */
   tu_health_word      s_o_health_wd_status_fpga; /* OTHER_HEALTH_WORD_STATUS_READ functionality in shared memory, as per the FPGA */
   tu_health_word      s_o_health_wd_status_ccdl; /* OTHER_HEALTH_WORD_STATUS_READ functionality in shared memory, as per the CCDL */
   uint32_t            s_oc_it_state;      /* OC_IT_STATE READ functionality in shared memory               */
   uint32_t            s_oc_pwr;           /* OC_POWERED READ functionality in shared memory                */
   ts_oss_counter      s_oss_counter;      /* OSS_PU COUNTERS READ functionality in shared memory           */
   uint32_t            s_oss_counter_reset;/* OSS_PU COUNTERS reset functionality in shared memory          */
   ts_ovs              s_ovs;              /* OVS functionalities in shared memory                          */
   ts_p0               s_p0;               /* P0 READ functionality in shared memory                        */
   ts_sg               s_p3_a;             /* P3 functionality from channel A in shared memory              */
   ts_sg               s_p3_b;             /* P3 functionality from channel B in shared memory              */
   tu_pbit_fault_word  s_pbit_fault_word;  /* Pbit                                                          */
   uint32_t            s_pending_fls_available; /* PENDING FLS AVAILABLE functionality in shared memory     */
   ts_pot              s_pot1;             /* POT1 functionality in shared memory                           */
   ts_pot              s_pot2;             /* POT2 functionality in shared memory                           */
   ts_pot              s_pot3;             /* POT3 functionality in shared memory                           */
   ts_potdiff          s_potdiff1;         /* POTDIFF1 functionality in shared memory                       */
   ts_potdiff          s_potdiff2;         /* POTDIFF2 functionality in shared memory                       */
   ts_pt_ref           s_pt_ref;           /* PT_REF READ functionality in shared memory                    */
   ts_pw_srce_r        s_pw_srce;          /* POWER_SOURCE_READ functionality in shared memory              */
   ts_pwm_w            s_pwm_w;            /* PWM1 WRITE functionality in shared memory                     */
   ts_rs422_rx         s_rs422_rx;         /* RS422 READ functionality in shared memory                     */
   ts_rs422_tx         s_rs422_tx;         /* RS422 WRITE functionality in shared memory                    */
   ts_sg               s_sg1_a;            /* SG1/SAI1 functionality from channel A in shared memory        */
   ts_sg               s_sg2_a;            /* SG2/SAI2 functionality from channel A in shared memory        */
   ts_sg               s_sg3_b;            /* SG3/SAI3 functionality from channel B in shared memory        */
   ts_sg               s_sg4_b;            /* SG4 functionality from channel B in shared memory             */
   ts_sg               s_sg5_b;            /* SG5/SAI4 functionality from channel B in shared memory        */
   ts_smot_w           s_smot_w;           /* Stepper motor write functionality in shared memory            */
   ts_svoi             s_svoi;             /* SVOI READ functionality in shared memory                      */
   ts_temp             s_t1a;              /* T1A READ functionality in shared memory                       */
   ts_temp             s_t1b;              /* T1B READ functionality in shared memory                       */
   ts_temp             s_t2a;              /* T2A READ functionality in shared memory                       */
   ts_temp             s_t2b;              /* T2B READ functionality in shared memory                       */
   ts_temp4            s_t4a;              /* T4A READ functionality in shared memory                       */
   ts_temp4            s_t4b;              /* T4B READ functionality in shared memory                       */
   ts_tecu             s_tecua;            /* TECU A functionality in shared memory                         */
   ts_tecu             s_tecub;            /* TECU B functionality in shared memory                         */
   ts_temp             s_tffa;             /* TFFA READ functionality in shared memory                      */
   ts_temp             s_tffb;             /* TFFB READ functionality in shared memory                      */
   uint32_t            s_time_base;        /* time base functionality in shared memory                      */
   ts_tmot_r           s_tmot_r_a;         /* Torque motor read functionality in shared memory channel A    */
   ts_tmot_r           s_tmot_r_b;         /* Torque motor read functionality in shared memory channel B    */
   ts_tmot_w           s_tmot_w;           /* Torque motor write functionality in shared memory             */
   ts_wan_request      s_wan_request;      /* WAN REQUEST WRITE functionality in shared memory              */
   ts_xr               s_xr;               /* XR functionality in shared memory                             */
   ts_xr               s_xr_b;             /* XR B functionality in shared memory                           */
   uint32_t            s_din_uod_bypass_enable ; /* DIN_UOD activate bypass UOD used only for CSS_STUB      */ /* NEW */
   ts_fct_exec_time    s_times;            /* Execution times of the functions                              */
}
ts_shmem;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* SHARED_MEMORY_PUBLIC_H */
