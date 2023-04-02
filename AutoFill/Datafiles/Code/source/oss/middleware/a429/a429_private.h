/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef A429_PRIVATE_H
#define A429_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "memory/memory_address_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Number of maximum words on A429 RX */
#define A429_RX_MAX_WORD_NB (uint32_t)2048

/* Number of maximum words on A429 TX */
#define A429_TX_MAX_WORD_NB (uint32_t)256

/* A429 1A RX address in FPGA */
#define A429_1A_RX_ADDR (ts_a429_rx_reg *)(FPGA_MEMORY_ADDR + 0x00038000)

/* A429 2AB RX address in FPGA */
#define A429_2AB_RX_ADDR (ts_a429_rx_reg *)(FPGA_MEMORY_ADDR + 0x0003C000)

/* A429 1A and 2AB TX address in FPGA */
#define A429_1A_2AB_TX_ADDR (ts_a429_tx_reg *)(FPGA_MEMORY_ADDR + 0x00028000)

/* Number of maximum words the software can process from the A429 RX (in high speed) */
#define A429_MAX_WORD_PROCESSED_IN_HS_NB (uint32_t)27

/* Number of maximum words the software can process from the A429 RX (in low speed) */
#define A429_MAX_WORD_PROCESSED_IN_LS_NB (uint32_t)3

/* Number of configurable SDI-label */
#define SDI_LABEL_FILTERING_CONFIGURABLE_NB (uint32_t)128

/* Low speed filter time */
#define LS_FILTER_TIME (uint32_t)0x43

/* Low speed min half bit time */
#define LS_HBIT_TIME_MIN (uint32_t)0x218

/* Low speed max half bit time */
#define LS_HBIT_TIME_MAX (uint32_t)0xEB0

/* Low speed min bit time */
#define LS_BIT_TIME_MIN (uint32_t)0x10A8

/* Low speed max bit time */
#define LS_BIT_TIME_MAX (uint32_t)0x1900

/* Low speed gap bit time */
#define LS_GAP_BIT_TIME (uint32_t)0x14D0

/* High speed filter time */
#define HS_FILTER_TIME (uint32_t)0x43

/* High speed min half bit time */
#define HS_HBIT_TIME_MIN (uint32_t)0x43

/* High speed max half bit time */
#define HS_HBIT_TIME_MAX (uint32_t)0x1D6

/* High speed min bit time */
#define HS_BIT_TIME_MIN (uint32_t)0x215

/* High speed max bit time */
#define HS_BIT_TIME_MAX (uint32_t)0x320

/* High speed gap bit time */
#define HS_GAP_BIT_TIME (uint32_t)0x29A

/* ---------- provided types: ----------------------------------------------- */
/* Bits field of A429 word register */
typedef struct
{
   uint32_t s_parity : 1; /* 31: Parity error */
   uint32_t s_ssm : 2; /* 30 to 29: SSM error */
   uint32_t s_data : 19; /* 28 to 10: Data */
   uint32_t s_sdi_label : 10; /* 09 to 00: SDI (09 to 08) + label (07 to 00) */
}
ts_a429_word_u_bit;

/* A429 word register */
typedef union
{
   uint32_t u_word; /* A429 word register accessed by 32-bit word */
   ts_a429_word_u_bit u_bit; /* A429 word register accessed bit by bit */
}
ts_a429_word;

/* Bits field of A429 RX status register */
typedef struct
{
   uint32_t s_in_progress : 1; /* 31: [1: word reception in progress; 0: no word reception in progress] */
   uint32_t s_word_received : 1; /* 30: [1: word received; 0; word received has been read] */
   uint32_t s_err_level : 1; /* 29: TBD [1: two a429 inputs have been detected at 1 at same time; 0: otherwise] */
   uint32_t s_err_time_hbit_min : 1; /* 28: [1: too short half bit time detected: 0: otherwise] */
   uint32_t s_err_time_hbit_max : 1; /* 27: [1: too long half bit time detected: 0: otherwise] */
   uint32_t s_err_time_bit_min : 1; /* 26: [1: too short bit time detected: 0: otherwise] */
   uint32_t s_err_time_bit_max : 1; /* 25: [1: too long bit time detected: 0: otherwise] */
   uint32_t s_err_time_gap_min : 1; /* 24: [1: too short gap detected: 0: otherwise] */
   uint32_t s_err_parity : 1; /* 23: [1: parity error in a word detected; 0: otherwise] */
   uint32_t s_spare_22_to_21 : 2; /* 22 to 21: Spare */
   uint32_t s_part3_sal_received : 1; /* 20: [1: word received matching configured SAL; 0: otherwise] */
   uint32_t s_err_ram_parity : 1; /* 19: [1: Parity error in RAM detected; 0: otherwise] */
   uint32_t s_spare_18_to_16 : 3; /* 18 to 16: Spare */
   uint32_t s_ram_empty : 1; /* 15: [1: ram empty in queueing mode; 0: otherwise] */
   uint32_t s_ram_full : 1; /* 14: [1: ram is full in queueing mode; 0: otherwise] */
   uint32_t s_err_ram_overflow : 1; /* 13: [1: write attempt made on a full ram; 0: after read or otherwise] */
   uint32_t s_spare_12 : 1; /* 12: Spare */
   uint32_t s_ram_word_count : 12; /* 11 to 00: Number of words stored in ram (works only in queueing mode) */
}
ts_a429_rx_acq_fault_word_u_bit;

/* A429 RX status register */
typedef union
{
   uint32_t u_word; /* AA429 RX status register accessed by 32-bit word */
   ts_a429_rx_acq_fault_word_u_bit u_bit; /* A429 RX status register accessed bit by bit */
}
ts_a429_rx_fault_word;

/* Bits field of A429 TX status register */
typedef struct
{
   uint32_t s_spare_31_to_18 : 14; /* 31 to 18: Spare */
   uint32_t s_err_fifo_overflow : 1; /* 17: [1: write attempt made to fifo that is full; 0: after read or otherwise] */
   uint32_t s_err_fifo_parity : 1; /* 16: [1: Parity error in fifo detected; 0: otherwise] */
   uint32_t s_spare_15_to_12 : 4; /* 15 to 12: Spare */
   uint32_t s_fifo_full : 1; /* 11: [1: fifo is full; 0: otherwise] */
   uint32_t s_fifo_empty : 1; /* 10: [1: fifo empty; 0: otherwise] */
   uint32_t s_busy : 1; /* 09: [1: during the gap time that follows the transmission; 0: otherwise] */
   uint32_t s_fifo_word_count : 9; /* 08 to 00: Number of words stored in fifo */
}
ts_a429_tx_acq_fault_word_u_bit;

/* A429 TX status register */
typedef union
{
   uint32_t u_word; /* AA429 TX status register accessed by 32-bit word */
   ts_a429_tx_acq_fault_word_u_bit u_bit; /* A429 TX status register accessed bit by bit */
}
ts_a429_tx_fault_word;

/* Bits field of A429 RX command register */
typedef struct
{
   uint32_t s_storage_mode : 1; /* 31: Storage mode: [0: sampling; 1: queueing] */
   uint32_t s_spare_30_to_09 : 22; /* 30 to 09: Spare */
   uint32_t s_part3_enable : 1; /* 08: TBD */
   uint32_t s_corrupt_parity_cmd : 4; /* 07 to 04: TBD */
   uint32_t s_spare_03_to_02 : 2; /* 03 to 02: Spare */
   uint32_t s_flush_cmd : 1; /* 01: Write 1 to flush the rx ram */
   uint32_t s_enable_rx : 1; /* 00: Write 1 to enable rx */
}
ts_a429_rx_command_u_bit;

/* A429 RX command register */
typedef union
{
   uint32_t u_word; /* A429 RX config register accessed by 32-bit word */
   ts_a429_rx_command_u_bit u_bit; /* A429 RX config register accessed bit by bit */
}
ts_a429_rx_command;

/* Bits field of A429 RX filter gap configuration register */
typedef struct
{
   uint32_t s_gap_bit_time : 16; /* 31 to 16: Bit time used to verify the minimum gap of 4 bit times between 2 words */
   uint32_t s_spare_15_to_13 : 3; /* 15 to 12: Spare */
   uint32_t s_filter_time : 13; /* 12 to 00: Inputs confirmation time */
}
ts_a429_rx_filter_gap_config_u_bit;

/* A429 RX filter gap configuration register */
typedef union
{
   uint32_t u_word; /* A429 RX filter gap configuration register accessed by 32-bit word */
   ts_a429_rx_filter_gap_config_u_bit u_bit; /* A429 RX filter gap configuration register accessed bit by bit */
}
ts_a429_rx_filter_gap_config;

/* Bits field of half bit time configuration register */
typedef struct
{
   uint32_t s_spare_31 : 1; /* 31: Spare */
   uint32_t s_max_hbit_time : 15; /* 30 to 16 : Maximum half bit time of the received bits */
   uint32_t s_spare_15 : 1; /* 15: Spare */
   uint32_t s_min_hbit_time: 15; /* 14 to 00: Minimum half bit time of the received bits */
}
ts_a429_rx_half_bit_config_u_bit;

/* A429 RX half bit time configuration register */
typedef union
{
   uint32_t u_word; /* A429 RX half bit time configuration register accessed by 32-bit word */
   ts_a429_rx_half_bit_config_u_bit u_bit; /* A429 RX half bit time configuration register accessed bit by bit */
}
ts_a429_rx_half_bit_config;

/* Bits field of bit time configuration register */
typedef struct
{
   uint32_t s_max_bit_time : 16; /* 31 to 16 : Maximum bit time of the received bits */
   uint32_t s_min_bit_time : 16; /* 15 to 00: Minimum bit time of the received bits */
}
ts_a429_rx_bit_config_u_bit;

/* A429 RX bit time configuration register */
typedef union
{
   uint32_t u_word; /* A429 RX bit time configuration register accessed by 32-bit word */
   ts_a429_rx_bit_config_u_bit u_bit; /* A429 RX bit time configuration register accessed bit by bit */
}
ts_a429_rx_bit_config;

/* Bits field of A429 TX speed configuration 2 register */
typedef struct
{
   uint32_t s_spare_31_to_14 : 18; /* 31 to 14: Spare */
   uint32_t s_gap_time : 6; /* 13 to 08: Gap time between two transmitted a429 words */
   uint32_t s_spare_07_to_01 : 7; /* 07 to 01: Spare */
   uint32_t s_speed_select : 1; /* 00: Speed mode: [0: low speed; 1: high speed] */
}
ts_a429_tx_configure_u_bit;

/* A429 TX speed configuration 2 register */
typedef union
{
   uint32_t u_word; /* A429 TX speed configuration 2 register accessed by 32-bit word */
   ts_a429_tx_configure_u_bit u_bit; /* A429 TX speed configuration 2 register accessed bit by bit */
}
ts_a429_tx_configure;

/* Bits field of A429 TX command register */
typedef struct
{
   uint32_t s_spare_31_to_12 : 20; /* 31 to 12: Spare */
   uint32_t s_cmd_err_fifo_parity_3 : 1; /* 11: Write 1 to inject parity bit error for data byte 31 to 24 */
   uint32_t s_cmd_err_fifo_parity_2 : 1; /* 10: Write 1 to inject parity bit error for data byte 23 to 16 */
   uint32_t s_cmd_err_fifo_parity_1 : 1; /* 09: Write 1 to inject parity bit error for data byte 15 to 08 */
   uint32_t s_cmd_err_fifo_parity_0 : 1; /* 08: Write 1 to inject parity bit error for data byte 07 to 00 */
   uint32_t s_spare_07_to_05 : 3; /* 07 to 05: Spare */
   uint32_t s_flush_cmd : 1; /* 04: Write 1 to flush tx ram */
   uint32_t s_cmd_err_parity : 1; /* 03: Write 1 to inject parity error in transmitted words */
   uint32_t s_spare_02_to_01 : 2; /* 02 to 01: Spare */
   uint32_t s_enable_tx : 1; /* 00: Write 1 to enable tx */
}
ts_a429_tx_command_u_bit;

/* A429 TX command register */
typedef union
{
   uint32_t u_word; /*A429 TX command register accessed by 32-bit word */
   ts_a429_tx_command_u_bit u_bit; /* A429 TX command register accessed bit by bit */
}
ts_a429_tx_command;

/* A429 RX registers */
typedef struct
{
   ts_a429_word rx[A429_RX_MAX_WORD_NB];
   uint32_t reserved_1;
   ts_a429_rx_fault_word fault_word;
   uint32_t reserved_2;
   ts_a429_rx_command cmd;
   ts_a429_rx_filter_gap_config gap;
   ts_a429_rx_half_bit_config hbit;
   ts_a429_rx_bit_config bit;
}
ts_a429_rx_reg;

/* A429 TX registers */
typedef struct
{
   ts_a429_word tx[A429_TX_MAX_WORD_NB];
   uint32_t reserved_1;
   ts_a429_tx_fault_word fault_word;
   uint32_t reserved_2;
   ts_a429_tx_configure conf;
   ts_a429_tx_command cmd;
}
ts_a429_tx_reg;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Registers for A429 1A RX & TX */
extern ts_a429_rx_reg* fpga_a429_1a_rx;
extern ts_a429_tx_reg* fpga_a429_1a_tx;

/* Registers for A429 2AB RX & TX */
extern ts_a429_rx_reg* fpga_a429_2ab_rx;
extern ts_a429_tx_reg* fpga_a429_2ab_tx;

/* Maximum number of received words to process for A429 1A and A429 2AB */
extern uint32_t a429_1a_words_max;
extern uint32_t a429_2ab_words_max;

/* Configured SDI+label read from configuration table for A429 1A and A429 2AB */
extern uint16_t a429_1a_rx_sdi_label[SDI_LABEL_FILTERING_CONFIGURABLE_NB];
extern uint16_t a429_2ab_rx_sdi_label[SDI_LABEL_FILTERING_CONFIGURABLE_NB];

/* Configuration for the transmitter of the A429 2AB */
extern uint32_t a429_2ab_tx_conf;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-A429-0030 */
/* Read A429 message(s) */
extern void a429_rx(const uint32_t a429_words_max, ts_a429_rx_reg* const fpga_a429_rx, ts_a429_rx* const shmem_a429_rx, const uint16_t* const a429_rx_sdi_label);

/* Implements REQ_FADEX_OS_SRD-A429-0040 */
/* Transmit messages in the serial link given in parameter */
extern void a429_tx(const uint32_t a429_words_max, ts_a429_tx_reg* const fpga_a429_tx, ts_a429_tx* const shmem_a429_tx);

#endif /* A429_PRIVATE_H  */
