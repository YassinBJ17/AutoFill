/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config ..\..\LIBBSP_api\LIBBSP_TYPE\config.txt
** Generation date: 2023-02-08T15:08:48
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#include "stddef.h"

#define KCG_MAPW_CPY

#include "user_macros_libbsp.h"

#ifndef kcg_char
#define kcg_char kcg_char
typedef char kcg_char;
#endif /* kcg_char */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_float32
#define kcg_float32 kcg_float32
typedef float kcg_float32;
#endif /* kcg_float32 */

#ifndef kcg_float64
#define kcg_float64 kcg_float64
typedef double kcg_float64;
#endif /* kcg_float64 */

#ifndef kcg_size
#define kcg_size kcg_size
typedef ptrdiff_t kcg_size;
#endif /* kcg_size */

#ifndef kcg_uint64
#define kcg_uint64 kcg_uint64
typedef unsigned long long kcg_uint64;
#endif /* kcg_uint64 */

#ifndef kcg_uint32
#define kcg_uint32 kcg_uint32
typedef unsigned long kcg_uint32;
#endif /* kcg_uint32 */

#ifndef kcg_uint16
#define kcg_uint16 kcg_uint16
typedef unsigned short kcg_uint16;
#endif /* kcg_uint16 */

#ifndef kcg_uint8
#define kcg_uint8 kcg_uint8
typedef unsigned char kcg_uint8;
#endif /* kcg_uint8 */

#ifndef kcg_int64
#define kcg_int64 kcg_int64
typedef signed long long kcg_int64;
#endif /* kcg_int64 */

#ifndef kcg_int32
#define kcg_int32 kcg_int32
typedef signed long kcg_int32;
#endif /* kcg_int32 */

#ifndef kcg_int16
#define kcg_int16 kcg_int16
typedef signed short kcg_int16;
#endif /* kcg_int16 */

#ifndef kcg_int8
#define kcg_int8 kcg_int8
typedef signed char kcg_int8;
#endif /* kcg_int8 */

#ifndef kcg_lit_float32
#define kcg_lit_float32(kcg_C1) ((kcg_float32) (kcg_C1))
#endif /* kcg_lit_float32 */

#ifndef kcg_lit_float64
#define kcg_lit_float64(kcg_C1) ((kcg_float64) (kcg_C1))
#endif /* kcg_lit_float64 */

#ifndef kcg_lit_size
#define kcg_lit_size(kcg_C1) ((kcg_size) (kcg_C1))
#endif /* kcg_lit_size */

#ifndef kcg_lit_uint64
#define kcg_lit_uint64(kcg_C1) ((kcg_uint64) (kcg_C1))
#endif /* kcg_lit_uint64 */

#ifndef kcg_lit_uint32
#define kcg_lit_uint32(kcg_C1) ((kcg_uint32) (kcg_C1))
#endif /* kcg_lit_uint32 */

#ifndef kcg_lit_uint16
#define kcg_lit_uint16(kcg_C1) ((kcg_uint16) (kcg_C1))
#endif /* kcg_lit_uint16 */

#ifndef kcg_lit_uint8
#define kcg_lit_uint8(kcg_C1) ((kcg_uint8) (kcg_C1))
#endif /* kcg_lit_uint8 */

#ifndef kcg_lit_int64
#define kcg_lit_int64(kcg_C1) ((kcg_int64) (kcg_C1))
#endif /* kcg_lit_int64 */

#ifndef kcg_lit_int32
#define kcg_lit_int32(kcg_C1) ((kcg_int32) (kcg_C1))
#endif /* kcg_lit_int32 */

#ifndef kcg_lit_int16
#define kcg_lit_int16(kcg_C1) ((kcg_int16) (kcg_C1))
#endif /* kcg_lit_int16 */

#ifndef kcg_lit_int8
#define kcg_lit_int8(kcg_C1) ((kcg_int8) (kcg_C1))
#endif /* kcg_lit_int8 */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_lsl_uint64
#define kcg_lsl_uint64(kcg_C1, kcg_C2)                                        \
  ((kcg_uint64) ((kcg_C1) << (kcg_C2)) & 0xffffffffffffffff)
#endif /* kcg_lsl_uint64 */

#ifndef kcg_lsl_uint32
#define kcg_lsl_uint32(kcg_C1, kcg_C2)                                        \
  ((kcg_uint32) ((kcg_C1) << (kcg_C2)) & 0xffffffff)
#endif /* kcg_lsl_uint32 */

#ifndef kcg_lsl_uint16
#define kcg_lsl_uint16(kcg_C1, kcg_C2)                                        \
  ((kcg_uint16) ((kcg_C1) << (kcg_C2)) & 0xffff)
#endif /* kcg_lsl_uint16 */

#ifndef kcg_lsl_uint8
#define kcg_lsl_uint8(kcg_C1, kcg_C2)                                         \
  ((kcg_uint8) ((kcg_C1) << (kcg_C2)) & 0xff)
#endif /* kcg_lsl_uint8 */

#ifndef kcg_lnot_uint64
#define kcg_lnot_uint64(kcg_C1) ((kcg_C1) ^ 0xffffffffffffffff)
#endif /* kcg_lnot_uint64 */

#ifndef kcg_lnot_uint32
#define kcg_lnot_uint32(kcg_C1) ((kcg_C1) ^ 0xffffffff)
#endif /* kcg_lnot_uint32 */

#ifndef kcg_lnot_uint16
#define kcg_lnot_uint16(kcg_C1) ((kcg_C1) ^ 0xffff)
#endif /* kcg_lnot_uint16 */

#ifndef kcg_lnot_uint8
#define kcg_lnot_uint8(kcg_C1) ((kcg_C1) ^ 0xff)
#endif /* kcg_lnot_uint8 */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* TE_LIBBSP_PQRFS_Line/ */
typedef enum kcg_tag_TE_LIBBSP_PQRFS_Line {
  E_LIBBSP_PQRFS_Line1,
  E_LIBBSP_PQRFS_Line4,
  E_LIBBSP_PQRFS_NbLine
} TE_LIBBSP_PQRFS_Line;
/* TE_LIBBSP_PQRFS_Label_PLD/ */
typedef enum kcg_tag_TE_LIBBSP_PQRFS_Label_PLD {
  E_LIBBSP_PQRFS_Label0,
  E_LIBBSP_PQRFS_Label1,
  E_LIBBSP_PQRFS_Label2,
  E_LIBBSP_PQRFS_Label3,
  E_LIBBSP_PQRFS_Label4,
  E_LIBBSP_PQRFS_Label5,
  E_LIBBSP_PQRFS_Label6,
  E_LIBBSP_PQRFS_Label7,
  E_LIBBSP_PQRFS_Label8,
  E_LIBBSP_PQRFS_Label9,
  E_LIBBSP_PQRFS_Label10,
  E_LIBBSP_PQRFS_Label11,
  E_LIBBSP_PQRFS_Label12
} TE_LIBBSP_PQRFS_Label_PLD;
/* TE_LIBBSP_PQRFS_Cycle/ */
typedef enum kcg_tag_TE_LIBBSP_PQRFS_Cycle {
  E_LIBBSP_PQRFS_Cycle1,
  E_LIBBSP_PQRFS_Cycle2,
  E_LIBBSP_PQRFS_Cycle3,
  E_LIBBSP_PQRFS_Cycle4
} TE_LIBBSP_PQRFS_Cycle;
/* TE_LIBBSP_PQRFS_Error/ */
typedef enum kcg_tag_TE_LIBBSP_PQRFS_Error {
  E_LIBBSP_PQRFS_KO,
  E_LIBBSP_PQRFS_OK
} TE_LIBBSP_PQRFS_Error;
/* TE_LIBBSP_A429_RxErrorCode/ */
typedef enum kcg_tag_TE_LIBBSP_A429_RxErrorCode {
  E_LIBBSP_A429_RX_OK,
  E_LIBBSP_A429_RX_INVALID_ID,
  E_LIBBSP_A429_RX_ROLLOVER,
  E_LIBBSP_A429_RX_PARITY_ERROR,
  E_LIBBSP_A429_RX_GAP_ERROR,
  E_LIBBSP_A429_RX_FORMAT_ERROR,
  E_LIBBSP_A429_RX_TOO_MANY_LABELS,
  E_LIBBSP_A429_RX_INCONSISTENT_ROLLOVER,
  E_LIBBSP_A429_POST_KO
} TE_LIBBSP_A429_RxErrorCode;
/* TE_LIBBSP_MEGIT_ItStatus/ */
typedef enum kcg_tag_TE_LIBBSP_MEGIT_ItStatus {
  E_LIBBSP_MEGIT_IT_SOURCE_INVALID = 0,
  E_LIBBSP_MEGIT_IT_SOURCE_VALID = 1
} TE_LIBBSP_MEGIT_ItStatus;
/* TE_LIBBSP_MEGIT_RsSyncSource/ */
typedef enum kcg_tag_TE_LIBBSP_MEGIT_RsSyncSource {
  E_LIBBSP_MEGIT_RS_NO_SOURCE = 0,
  E_LIBBSP_MEGIT_RS_SYNC_100HZ = 1,
  E_LIBBSP_MEGIT_RS_SYNC_APPL = 2,
  E_LIBBSP_MEGIT_RS_RTC_IDA = 3,
  E_LIBBSP_MEGIT_RS_RTC_2K = 4,
  E_LIBBSP_MEGIT_RS_CPU_RTC = 5,
  E_LIBBSP_MEGIT_RS_NB_SOURCE = 6
} TE_LIBBSP_MEGIT_RsSyncSource;
/* TE_LIBBSP_MEGIT_CpuSyncSource/ */
typedef enum kcg_tag_TE_LIBBSP_MEGIT_CpuSyncSource {
  E_LIBBSP_MEGIT_CPU_NO_SOURCE = 0,
  E_LIBBSP_MEGIT_CPU_SYNC_APPL = 1,
  E_LIBBSP_MEGIT_CPU_TIC_RDY = 2,
  E_LIBBSP_MEGIT_CPU_RT_RDY = 3,
  E_LIBBSP_MEGIT_CPU_IRQ_2KH_ALL = 4,
  E_LIBBSP_MEGIT_CPU_IRQ_APPL_ALL = 5,
  E_LIBBSP_MEGIT_CPU_IRQ_APPL_TIC = 6,
  E_LIBBSP_MEGIT_CPU_RTC_8K = 7,
  E_LIBBSP_MEGIT_CPU_NB_SOURCE = 8
} TE_LIBBSP_MEGIT_CpuSyncSource;
/* TE_LIBBSP_A429_RxLine/ */
typedef enum kcg_tag_TE_LIBBSP_A429_RxLine {
  E_LIBBSP_A429_RX_1 = 0,
  E_LIBBSP_A429_RX_2 = 1,
  E_LIBBSP_A429_RX_3 = 2,
  E_LIBBSP_A429_RX_4 = 3,
  E_LIBBSP_A429_RX_5 = 4,
  E_LIBBSP_A429_RX_6 = 5,
  E_LIBBSP_A429_RX_7 = 6,
  E_LIBBSP_A429_RX_8 = 7,
  E_LIBBSP_A429_RX_9 = 8
} TE_LIBBSP_A429_RxLine;
/* TE_LIBBSP_UART_TxErrorCode/ */
typedef enum kcg_tag_TE_LIBBSP_UART_TxErrorCode {
  E_LIBBSP_UART_TX_OK = 0,
  E_LIBBSP_UART_TX_INVALID_ID = 1,
  E_LIBBSP_UART_TX_OVERFLOW_CMD = 2,
  E_LIBBSP_UART_TX_OVERFLOW_FIFO = 3
} TE_LIBBSP_UART_TxErrorCode;
/* TE_LIBBSP_UART_RxErrorCode/ */
typedef enum kcg_tag_TE_LIBBSP_UART_RxErrorCode {
  E_LIBBSP_UART_RX_OK = 0,
  E_LIBBSP_UART_DEV_INVALID_ID = 1,
  E_LIBBSP_UART_RX_STOP_ERROR = 2,
  E_LIBBSP_UART_RX_PARITY_ERROR = 3,
  E_LIBBSP_UART_RX_OVERFLOW_ERROR = 4,
  E_LIBBSP_UART_RX_ROLLOVER_ERROR = 5,
  E_LIBBSP_UART_RX_INCONSISTENT_ERROR = 6,
  E_LIBBSP_UART_POST_KO = 7
} TE_LIBBSP_UART_RxErrorCode;
/* TE_LIBBSP_UART_StopBits/ */
typedef enum kcg_tag_TE_LIBBSP_UART_StopBits {
  E_LIBBSP_UART_STOPBITS_TWO = 0,
  E_LIBBSP_UART_STOPBITS_ONE = 1
} TE_LIBBSP_UART_StopBits;
/* TE_LIBBSP_UART_Parity/ */
typedef enum kcg_tag_TE_LIBBSP_UART_Parity {
  E_LIBBSP_UART_PARITY_NONE = 0,
  E_LIBBSP_UART_PARITY_ODD = 1,
  E_LIBBSP_UART_PARITY_EVEN = 2,
  /** Second value allowing to select the absence of parity for the RS */ E_LIBBSP_UART_PARITY_NONE_3 = 3
} TE_LIBBSP_UART_Parity;
/* TE_LIBBSP_UART_Speed/ */
typedef enum kcg_tag_TE_LIBBSP_UART_Speed {
  E_LIBBSP_UART_BAUDS_9600 = 0,
  E_LIBBSP_UART_BAUDS_19200 = 1,
  E_LIBBSP_UART_BAUDS_38400 = 2,
  E_LIBBSP_UART_BAUDS_115200 = 3,
  E_LIBBSP_UART_BAUDS_460800 = 4,
  E_LIBBSP_UART_BAUDS_921600 = 5
} TE_LIBBSP_UART_Speed;
/* TE_LIBBSP_UART_Dev/ */
typedef enum kcg_tag_TE_LIBBSP_UART_Dev {
  E_LIBBSP_UART_DEV_1_RX = 0,
  E_LIBBSP_UART_DEV_1_TX = 1,
  E_LIBBSP_UART_DEV_2_RX = 2,
  E_LIBBSP_UART_DEV_2_TX = 3,
  E_LIBBSP_UART_DEV_3_RX = 4,
  E_LIBBSP_UART_DEV_3_TX = 5,
  E_LIBBSP_UART_DEV_4_RX = 6,
  E_LIBBSP_UART_DEV_4_TX = 7,
  E_LIBBSP_UART_DEV_MAX = 8
} TE_LIBBSP_UART_Dev;
/* TE_LIBBSP_MRAM_ErrorCode/ */
typedef enum kcg_tag_TE_LIBBSP_MRAM_ErrorCode {
  E_LIBBSP_MRAM_OK = 0x0,
  E_LIBBSP_MRAM_OPEN_ESPI_ERROR = 0x1,
  E_LIBBSP_MRAM_CLOSE_ESPI_ERROR = 0x2,
  E_LIBBSP_MRAM_WRITE_ERROR = 0x3,
  E_LIBBSP_MRAM_READ_ERROR = 0x4,
  E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR = 0x5
} TE_LIBBSP_MRAM_ErrorCode;
/* TE_LIBBSP_PSUM_Status/ */
typedef enum kcg_tag_TE_LIBBSP_PSUM_Status {
  E_LIBBSP_PSUM_SUCCEEDED = 0,
  E_LIBBSP_PSUM_FAILED = 1
} TE_LIBBSP_PSUM_Status;
/* TE_LIBBSP_GPIO_Status/ */
typedef enum kcg_tag_TE_LIBBSP_GPIO_Status {
  E_LIBBSP_GPIO_SUCCEEDED = 0,
  E_LIBBSP_GPIO_FAILED = 1
} TE_LIBBSP_GPIO_Status;
/* TE_LIBBSP_A429_Speed/ */
typedef enum kcg_tag_TE_LIBBSP_A429_Speed {
  E_LIBBSP_A429_BAUDS_12 = 0,
  E_LIBBSP_A429_BAUDS_100 = 1
} TE_LIBBSP_A429_Speed;
/* TE_LIBBSP_ETSEC_NetConfigStop/ */
typedef enum kcg_tag_TE_LIBBSP_ETSEC_NetConfigStop {
  E_LIBBSP_ETSEC_STOP_NETWORK_TX = 1,
  E_LIBBSP_ETSEC_STOP_NETWORK_RX = 2,
  E_LIBBSP_ETSEC_STOP_NETWORK_RX_TX = 3
} TE_LIBBSP_ETSEC_NetConfigStop;
/* TE_LIBBSP_ETSEC_FrameStatus/ */
typedef enum kcg_tag_TE_LIBBSP_ETSEC_FrameStatus {
  E_LIBBSP_ETSEC_NO_PHYSICAL_ERROR = 0,
  E_LIBBSP_ETSEC_PHYSICAL_ERROR = 1,
  E_LIBBSP_ETSEC_NO_FRAME_RECEIVED = 2,
  E_LIBBSP_ETSEC_SOFTWARE_OVERRUN = 3
} TE_LIBBSP_ETSEC_FrameStatus;
/* TE_LIBBSP_ETSEC_NetConfigStart/ */
typedef enum kcg_tag_TE_LIBBSP_ETSEC_NetConfigStart {
  E_LIBBSP_ETSEC_START_NETWORK_TX = 1,
  E_LIBBSP_ETSEC_START_NETWORK_RX = 2,
  E_LIBBSP_ETSEC_START_NETWORK_RX_TX = 3
} TE_LIBBSP_ETSEC_NetConfigStart;
/* TE_LIBBSP_I2C_Bus/ */
typedef enum kcg_tag_TE_LIBBSP_I2C_Bus {
  E_LIBBSP_I2C_BUS_1 = 0,
  E_LIBBSP_I2C_BUS_2 = 1,
  E_LIBBSP_I2C_NB_I2C_BUS = 2
} TE_LIBBSP_I2C_Bus;
/* TE_LIBBSP_ETR_Ds1682State/ */
typedef enum kcg_tag_TE_LIBBSP_ETR_Ds1682State {
  E_LIBBSP_ETR_DS1682_CLOSED = 0,
  E_LIBBSP_ETR_DS1682_OPEN = 1
} TE_LIBBSP_ETR_Ds1682State;
/* TE_LIBBSP_ETSEC_Network/ */
typedef enum kcg_tag_TE_LIBBSP_ETSEC_Network {
  E_LIBBSP_ETSEC_NETWORK_1 = 0,
  E_LIBBSP_ETSEC_NETWORK_2 = 1,
  E_LIBBSP_ETSEC_NETWORK_3 = 2,
  E_LIBBSP_ETSEC_NB_NETWORK = 3
} TE_LIBBSP_ETSEC_Network;
/* TE_LIBBSP_ETSEC_NetworkStatus/ */
typedef enum kcg_tag_TE_LIBBSP_ETSEC_NetworkStatus {
  E_LIBBSP_ETSEC_OK = 0,
  E_LIBBSP_ETSEC_KO = 1
} TE_LIBBSP_ETSEC_NetworkStatus;
/* TE_LIBBSP_IMU_WriteEraseCmd/ */
typedef enum kcg_tag_TE_LIBBSP_IMU_WriteEraseCmd {
  E_LIBBSP_IMU_RESET_ALL_W_ADDR = 0,
  E_LIBBSP_IMU_RESET_ADD_W_ADDR = 1
} TE_LIBBSP_IMU_WriteEraseCmd;
/* TE_LIBBSP_IMU_ProgStatus/ */
typedef enum kcg_tag_TE_LIBBSP_IMU_ProgStatus {
  E_LIBBSP_IMU_NB_DATA_OK = 0,
  E_LIBBSP_IMU_NB_DATA_EXCEEDED = 1
} TE_LIBBSP_IMU_ProgStatus;
/* TE_LIBBSP_IMU_WriteAddr/ */
typedef enum kcg_tag_TE_LIBBSP_IMU_WriteAddr {
  E_LIBBSP_IMU_WRITE_ADDRESS = 0,
  E_LIBBSP_IMU_NO_WRITE_ADDRESS = 1
} TE_LIBBSP_IMU_WriteAddr;
/* TE_LIBBSP_ECCMEM_SeuStatus/ */
typedef enum kcg_tag_TE_LIBBSP_ECCMEM_SeuStatus {
  E_LIBBSP_ECCMEM_SEU_OK = 0,
  E_LIBBSP_ECCMEM_SEU_WRONG_NB = 1,
  E_LIBBSP_ECCMEM_SEU_THRESH_EXCEED = 2,
  E_LIBBSP_ECCMEM_MBU_NOT_DETECTED = 3
} TE_LIBBSP_ECCMEM_SeuStatus;
/* TE_LIBBSP_ECCMEM_SeuMbuIt/ */
typedef enum kcg_tag_TE_LIBBSP_ECCMEM_SeuMbuIt {
  E_LIBBSP_ECCMEM_MBU_ONLY_IT = 0x8,
  E_LIBBSP_ECCMEM_SEU_ONLY_IT = 0x4,
  E_LIBBSP_ECCMEM_MBU_SEU_IT = 0xc,
  E_LIBBSP_ECCMEM_MBU_SEU_IT_DIS = 0x0
} TE_LIBBSP_ECCMEM_SeuMbuIt;
/* TE_LIBBSP_ECCMEM_SeuMbuEn/ */
typedef enum kcg_tag_TE_LIBBSP_ECCMEM_SeuMbuEn {
  E_LIBBSP_ECCMEM_MBU_ONLY_EN = 0x4,
  E_LIBBSP_ECCMEM_SEU_ONLY_EN = 0x8,
  E_LIBBSP_ECCMEM_MBU_SEU_EN = 0x0,
  E_LIBBSP_ECCMEM_MBU_SEU_DIS = 0xc
} TE_LIBBSP_ECCMEM_SeuMbuEn;
/* TE_LIBBSP_GPIO_DiscName/ */
typedef enum kcg_tag_TE_LIBBSP_GPIO_DiscName {
  E_LIBBSP_GPIO_MEGA_GPIO2 = 0x0001,
  E_LIBBSP_GPIO_MEGA_GPIO1 = 0x0002,
  E_LIBBSP_GPIO_MEGA_GPIO0 = 0x0004,
  E_LIBBSP_GPIO_COMP_GPIO2 = 0x0008,
  E_LIBBSP_GPIO_COMP_GPIO1 = 0x0010,
  E_LIBBSP_GPIO_COMP_GPIO0 = 0x0020,
  E_LIBBSP_GPIO_SDHC_W_PROTECT = 0x0040,
  E_LIBBSP_GPIO_SDHC_CARD_DETECT = 0x0080,
  E_LIBBSP_GPIO_GREEN_LED = 0x0100,
  E_LIBBSP_GPIO_YELLOW_LED = 0x0200,
  E_LIBBSP_GPIO_RED_LED = 0x0400,
  E_LIBBSP_GPIO_IRQ11 = 0x0800,
  E_LIBBSP_GPIO_DSI_SG_LABO = 0x1000,
  E_LIBBSP_GPIO_DSI_DL = 0x2000,
  E_LIBBSP_GPIO_IRQ8 = 0x4000,
  E_LIBBSP_GPIO_MEGA_MEZA_SPI_SEL = 0x8000
} TE_LIBBSP_GPIO_DiscName;
/* TE_LIBBSP_A429_TxErrorCode/ */
typedef enum kcg_tag_TE_LIBBSP_A429_TxErrorCode {
  E_LIBBSP_A429_TX_OK = 0,
  E_LIBBSP_A429_TX_INVALID_ID = 1,
  E_LIBBSP_A429_TX_OVERFLOW_CMD = 2,
  E_LIBBSP_A429_TX_OVERFLOW_FIFO = 3
} TE_LIBBSP_A429_TxErrorCode;
/* TE_LIBBSP_A429_TxLine/ */
typedef enum kcg_tag_TE_LIBBSP_A429_TxLine {
  E_LIBBSP_A429_TX_1 = 15,
  E_LIBBSP_A429_TX_2 = 16,
  E_LIBBSP_A429_TX_3 = 17,
  E_LIBBSP_A429_TX_4 = 18,
  E_LIBBSP_A429_TX_5 = 19,
  E_LIBBSP_A429_TX_6 = 20,
  E_LIBBSP_A429_TX_7 = 21,
  E_LIBBSP_A429_TX_8 = 22
} TE_LIBBSP_A429_TxLine;
/* TE_LIBBSP_CMN_Status/ */
typedef enum kcg_tag_TE_LIBBSP_CMN_Status {
  E_LIBBSP_CMN_TIME_IS_REACHED = 0,
  E_LIBBSP_CMN_TIME_IS_NOT_REACHED = 1
} TE_LIBBSP_CMN_Status;
/* TE_LIBBSP_CMPSCR_Register/ */
typedef enum kcg_tag_TE_LIBBSP_CMPSCR_Register {
  E_LIBBSP_CMPSCR_SCRATCH_0 = 0,
  E_LIBBSP_CMPSCR_SCRATCH_1 = 1,
  E_LIBBSP_CMPSCR_SCRATCH_2 = 2,
  E_LIBBSP_CMPSCR_SCRATCH_3 = 3,
  E_LIBBSP_CMPSCR_SCRATCH_4 = 4,
  E_LIBBSP_CMPSCR_SCRATCH_5 = 5,
  E_LIBBSP_CMPSCR_SCRATCH_6 = 6,
  E_LIBBSP_CMPSCR_SCRATCH_7 = 7,
  E_LIBBSP_CMPSCR_SCRATCH_8 = 8,
  E_LIBBSP_CMPSCR_SCRATCH_9 = 9,
  E_LIBBSP_CMPSCR_SCRATCH_10 = 10,
  E_LIBBSP_CMPSCR_SCRATCH_11 = 11,
  E_LIBBSP_CMPSCR_SCRATCH_12 = 12,
  E_LIBBSP_CMPSCR_SCRATCH_13 = 13,
  E_LIBBSP_CMPSCR_SCRATCH_14 = 14,
  E_LIBBSP_CMPSCR_SCRATCH_15 = 15,
  E_LIBBSP_CMPSCR_SCRATCH_16 = 16,
  E_LIBBSP_CMPSCR_SCRATCH_17 = 17,
  E_LIBBSP_CMPSCR_SCRATCH_18 = 18,
  E_LIBBSP_CMPSCR_SCRATCH_19 = 19,
  E_LIBBSP_CMPSCR_SCRATCH_20 = 20,
  E_LIBBSP_CMPSCR_SCRATCH_21 = 21,
  E_LIBBSP_CMPSCR_SCRATCH_22 = 22,
  E_LIBBSP_CMPSCR_SCRATCH_23 = 23,
  E_LIBBSP_CMPSCR_SCRATCH_24 = 24,
  E_LIBBSP_CMPSCR_SCRATCH_25 = 25,
  E_LIBBSP_CMPSCR_SCRATCH_26 = 26,
  E_LIBBSP_CMPSCR_SCRATCH_27 = 27,
  E_LIBBSP_CMPSCR_SCRATCH_28 = 28,
  E_LIBBSP_CMPSCR_SCRATCH_29 = 29,
  E_LIBBSP_CMPSCR_SCRATCH_30 = 30,
  E_LIBBSP_CMPSCR_SCRATCH_31 = 31
} TE_LIBBSP_CMPSCR_Register;
/* TE_LIBBSP_DISC_Expander/ */
typedef enum kcg_tag_TE_LIBBSP_DISC_Expander {
  E_LIBBSP_DISC_EXPANDER_1 = 0,
  E_LIBBSP_DISC_EXPANDER_2 = 1,
  E_LIBBSP_DISC_NB_EXPANDER = 2
} TE_LIBBSP_DISC_Expander;
/* TE_LIBBSP_I2C_Code/ */
typedef enum kcg_tag_TE_LIBBSP_I2C_Code {
  E_LIBBSP_I2C_OK = 0,
  E_LIBBSP_I2C_INVALID_ID = 1,
  E_LIBBSP_I2C_ARBITRATION_LOST = 2,
  E_LIBBSP_I2C_NO_ACK = 3,
  E_LIBBSP_I2C_BUS_BUSY = 4,
  E_LIBBSP_I2C_TIMEOUT = 5,
  E_LIBBSP_I2C_CLOSED = 6
} TE_LIBBSP_I2C_Code;
/* TE_LIBBSP_I2C_CurrentStep/ */
typedef enum kcg_tag_TE_LIBBSP_I2C_CurrentStep {
  E_LIBBSP_I2C_IDLE = 0,
  E_LIBBSP_I2C_WAIT_FOR_SLV_CMD_W_ACK = 1,
  E_LIBBSP_I2C_WAIT_FOR_SLV_W_ACK = 2,
  E_LIBBSP_I2C_WAIT_FOR_SLV_CMD_R_ACK = 3,
  E_LIBBSP_I2C_WAIT_FOR_SLV_R_DATA = 4,
  E_LIBBSP_I2C_DATA_WRITTEN = 5,
  E_LIBBSP_I2C_DATA_READ = 6
} TE_LIBBSP_I2C_CurrentStep;
/* TE_LIBBSP_I2C_ErrorCode/ */
typedef enum kcg_tag_TE_LIBBSP_I2C_ErrorCode {
  E_LIBBSP_I2C_COMMAND_TAKEN = 0,
  E_LIBBSP_I2C_COMMAND_NOT_TAKEN = 1,
  E_LIBBSP_I2C_COMMAND_ERROR = 2,
  E_LIBBSP_I2C_WRITE_OVERSIZED = 3,
  E_LIBBSP_I2C_READ_OVERSIZED = 4
} TE_LIBBSP_I2C_ErrorCode;
/* TE_LIBBSP_MEGSCR_Register/ */
typedef enum kcg_tag_TE_LIBBSP_MEGSCR_Register {
  E_LIBBSP_MEGSCR_SCRATCH_0 = 0,
  E_LIBBSP_MEGSCR_SCRATCH_1 = 1,
  E_LIBBSP_MEGSCR_SCRATCH_2 = 2,
  E_LIBBSP_MEGSCR_SCRATCH_3 = 3,
  E_LIBBSP_MEGSCR_SCRATCH_4 = 4,
  E_LIBBSP_MEGSCR_SCRATCH_5 = 5,
  E_LIBBSP_MEGSCR_SCRATCH_6 = 6,
  E_LIBBSP_MEGSCR_SCRATCH_7 = 7,
  E_LIBBSP_MEGSCR_SCRATCH_8 = 8,
  E_LIBBSP_MEGSCR_SCRATCH_9 = 9,
  E_LIBBSP_MEGSCR_SCRATCH_10 = 10,
  E_LIBBSP_MEGSCR_SCRATCH_11 = 11,
  E_LIBBSP_MEGSCR_SCRATCH_12 = 12,
  E_LIBBSP_MEGSCR_SCRATCH_13 = 13,
  E_LIBBSP_MEGSCR_SCRATCH_14 = 14,
  E_LIBBSP_MEGSCR_SCRATCH_15 = 15,
  E_LIBBSP_MEGSCR_SCRATCH_16 = 16,
  E_LIBBSP_MEGSCR_SCRATCH_17 = 17,
  E_LIBBSP_MEGSCR_SCRATCH_18 = 18,
  E_LIBBSP_MEGSCR_SCRATCH_19 = 19,
  E_LIBBSP_MEGSCR_SCRATCH_20 = 20,
  E_LIBBSP_MEGSCR_SCRATCH_21 = 21,
  E_LIBBSP_MEGSCR_SCRATCH_22 = 22,
  E_LIBBSP_MEGSCR_SCRATCH_23 = 23,
  E_LIBBSP_MEGSCR_SCRATCH_24 = 24,
  E_LIBBSP_MEGSCR_SCRATCH_25 = 25,
  E_LIBBSP_MEGSCR_SCRATCH_26 = 26,
  E_LIBBSP_MEGSCR_SCRATCH_27 = 27,
  E_LIBBSP_MEGSCR_SCRATCH_28 = 28,
  E_LIBBSP_MEGSCR_SCRATCH_29 = 29,
  E_LIBBSP_MEGSCR_SCRATCH_30 = 30,
  E_LIBBSP_MEGSCR_SCRATCH_31 = 31
} TE_LIBBSP_MEGSCR_Register;
/* TE_LIBBSP_SHM_Register/ */
typedef enum kcg_tag_TE_LIBBSP_SHM_Register {
  E_LIBBSP_SHM_COMP_STATUS = 0,
  E_LIBBSP_SHM_BOARD_STATUS = 1,
  E_LIBBSP_SHM_NB_REGISTERS = 2
} TE_LIBBSP_SHM_Register;
/* TE_LIBBSP_PSUM_Adc/ */
typedef enum kcg_tag_TE_LIBBSP_PSUM_Adc {
  E_LIBBSP_PSUM_ADC_1 = 0,
  E_LIBBSP_PSUM_ADC_2 = 1,
  E_LIBBSP_PSUM_ADC_3 = 2,
  E_LIBBSP_PSUM_ADC_4 = 3,
  E_LIBBSP_PSUM_ADC_5 = 4,
  E_LIBBSP_PSUM_ADC_6 = 5,
  E_LIBBSP_PSUM_ADC_7 = 6,
  E_LIBBSP_PSUM_NB_ADC = 7
} TE_LIBBSP_PSUM_Adc;
/* TE_LIBBSP_SHM_Mode/ */
typedef enum kcg_tag_TE_LIBBSP_SHM_Mode {
  E_LIBBSP_SHM_POWER_UP_STATE = 1,
  E_LIBBSP_SHM_INITIALIZATION_STATE = 2,
  E_LIBBSP_SHM_IDLE_STATE = 4,
  E_LIBBSP_SHM_OPERATIONNAL_UP_STATE = 8,
  E_LIBBSP_SHM_DEGRADED_STATE = 16,
  E_LIBBSP_SHM_FAILURE_STATE = 32
} TE_LIBBSP_SHM_Mode;
/* TE_LIBBSP_TEMP_ReadRegAddr/ */
typedef enum kcg_tag_TE_LIBBSP_TEMP_ReadRegAddr {
  E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_HIGH_BYTE = 0x0,
  E_LIBBSP_TEMP_READ_LOCAL_REMOTE_HIGH_BYTE = 0x1,
  E_LIBBSP_TEMP_READ_STATUS_REGISTER = 0x2,
  E_LIBBSP_TEMP_READ_CONFIGURATION_REGISTER = 0x3,
  E_LIBBSP_TEMP_READ_CONVERSION_RATE_REGISTER = 0x4,
  E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_HIGH_LIMIT = 0x5,
  E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_LOW_LIMIT = 0x6,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_HIGH_LIMIT_HIGH_BITE = 0x7,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_LOW_LIMIT_HIGH_BITE = 0x8,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_LOW_BITE = 0x10,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_OFFSET_HIGH_BITE = 0x11,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_OFFSET_LOW_BITE = 0x12,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_HIGH_LIMIT_LOW_BITE = 0x13,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_LOW_LIMIT_LOW_BITE = 0x14,
  E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_LOW_BYTE = 0x15,
  E_LIBBSP_TEMP_READ_REMOTE_TEMPERATURE_THERM_LIMIT = 0x19,
  E_LIBBSP_TEMP_READ_LOCAL_TEMPERATURE_THERM_LIMIT = 0x20,
  E_LIBBSP_TEMP_READ_THERM_HISTERESYS = 0x21,
  E_LIBBSP_TEMP_READ_CONSECUTIVE_ALTER = 0x22,
  E_LIBBSP_TEMP_READ_FACTOR_CORECTION = 0x23,
  E_LIBBSP_TEMP_READ_DIGITAL_FILTER_CONTROL = 0x24,
  E_LIBBSP_TEMP_READ_DIGITAL_MANUFATURER_IR = 0xFE
} TE_LIBBSP_TEMP_ReadRegAddr;
/* TE_LIBBSP_TMP_Number/ */
typedef enum kcg_tag_TE_LIBBSP_TMP_Number {
  E_LIBBSP_TMP_TMP1 = 0,
  E_LIBBSP_TMP_TMP2 = 1,
  E_LIBBSP_TMP_TMP3 = 2
} TE_LIBBSP_TMP_Number;
/* TS_LIBBSP_PLDCMP_ErrorStatus/ */
typedef struct kcg_tag_TS_LIBBSP_PLDCMP_ErrorStatus {
  kcg_bool nvm_error;
  kcg_bool parity_error;
  kcg_bool addr_error;
  kcg_bool acc_error;
  kcg_bool timeout_error;
  kcg_bool overload_error;
  kcg_bool wdg_comp_rst;
} TS_LIBBSP_PLDCMP_ErrorStatus;

/* TS_LIBBSP_PSUM_AdcErrorFlags/ */
typedef struct kcg_tag_TS_LIBBSP_PSUM_AdcErrorFlags {
  kcg_bool PresFail_or_Vin6Failure;
  kcg_bool OverVoltage;
  kcg_bool UnderVoltage;
  kcg_bool Vin7NotInRange;
  kcg_bool GeneralFailure;
} TS_LIBBSP_PSUM_AdcErrorFlags;

/* TS_LIBBSP_SHM_BoardStatus/ */
typedef struct kcg_tag_TS_LIBBSP_SHM_BoardStatus {
  kcg_bool pwr_good_28v1;
  kcg_bool pwr_good_28v2;
  kcg_bool ddr_vtt_uv;
  kcg_bool ddr_vtt_ov;
  kcg_bool vdd_uv;
  kcg_bool vdd_ov;
  kcg_bool cpcm_1v5_uv;
  kcg_bool cpcm_1v5_ov;
  kcg_bool vio_3v3_uv;
  kcg_bool vio_3v3_ov;
  kcg_bool cpcm_1v8_uv;
  kcg_bool cpcm_1v8_ov;
  kcg_bool mezz_pgood;
  kcg_bool mezz_fail;
  kcg_bool ready_p1;
  kcg_bool trig_out;
  kcg_bool pgood_p2v5;
  kcg_bool pgood_1v2meg;
  kcg_bool meg_fail;
  kcg_bool meg_pll_lock;
  kcg_bool therm;
  kcg_bool therm2;
  kcg_bool lvdd_type;
  kcg_bool tank_fail;
  kcg_bool pgood_vant;
  kcg_bool pgood_vrm;
  kcg_bool inhibit_wdg;
} TS_LIBBSP_SHM_BoardStatus;

/* TS_LIBBSP_IMU_FloatTab/ */
typedef kcg_float64 TS_LIBBSP_IMU_FloatTab[13];

/* TS_LIBBSP_IMU_AdditionalDataReadBufferOut/ */
typedef kcg_float64 TS_LIBBSP_IMU_AdditionalDataReadBufferOut[5];

/* TS_LIBBSP_IMU_Vect3/ */
typedef kcg_float64 TS_LIBBSP_IMU_Vect3[3];

/* TS_LIBBSP_IMU_Vect9/ */
typedef kcg_float64 TS_LIBBSP_IMU_Vect9[9];

/* TS_LIBBSP_IMU_InstrumIMUData/ */
typedef struct kcg_tag_TS_LIBBSP_IMU_InstrumIMUData {
  kcg_float64 v_lambda_ext_0;
  kcg_float64 v_lambda_ext_1;
  kcg_float64 v_lambda_ext_2;
  kcg_float64 v_cfPilot_A1_0;
  kcg_float64 v_cfPilot_A1_1;
  kcg_float64 v_cfPilot_A1_2;
  kcg_float64 v_cfPilot_A1_3;
  kcg_float64 v_cfPilot_A1_4;
  kcg_float64 v_cfPilot_A2_1;
  kcg_float64 v_cfPilot_A2_2;
  kcg_float64 v_cfPilot_A2_3;
  kcg_float64 v_cfPilot_A2_4;
  kcg_float64 v_cfPilot_A3_1;
  kcg_float64 v_cfPilot_A3_0;
  kcg_float64 v_cfPilot_A3_2;
  kcg_float64 v_cfPilot_A3_3;
  kcg_float64 v_cfPilot_A3_4;
  kcg_float64 v_cfPilot_A4_0;
  kcg_float64 v_cfPilot_A4_1;
  kcg_float64 v_cfPilot_A4_2;
  kcg_float64 v_cfPilot_A4_3;
  kcg_float64 v_cfPilot_A4_4;
  kcg_float64 v_cfPilot_B1_0;
  kcg_float64 v_cfPilot_B1_1;
  kcg_float64 v_cfPilot_B1_2;
  kcg_float64 v_cfPilot_B1_3;
  kcg_float64 v_cfPilot_B1_4;
  kcg_float64 v_cfPilot_B2_0;
  kcg_float64 v_cfPilot_B2_1;
  kcg_float64 v_cfPilot_B2_2;
  kcg_float64 v_cfPilot_B2_3;
  kcg_float64 v_cfPilot_B2_4;
  kcg_float64 v_cfPilot_B3_0;
  kcg_float64 v_cfPilot_B3_1;
  kcg_float64 v_cfPilot_B3_2;
  kcg_float64 v_cfPilot_B3_3;
  kcg_float64 v_cfPilot_B3_4;
  kcg_float64 v_cfPilot_B4_0;
  kcg_float64 v_cfPilot_B4_1;
  kcg_float64 v_cfPilot_B4_2;
  kcg_float64 v_cfPilot_B4_3;
  kcg_float64 v_cfPilot_B4_4;
  kcg_float64 v_cfPilot_E1_0;
  kcg_float64 v_cfPilot_E1_1;
  kcg_float64 v_cfPilot_E1_2;
  kcg_float64 v_cfPilot_E1_3;
  kcg_float64 v_cfPilot_E1_4;
  kcg_float64 v_cfPilot_E2_0;
  kcg_float64 v_cfPilot_E2_1;
  kcg_float64 v_cfPilot_E2_2;
  kcg_float64 v_cfPilot_E2_3;
  kcg_float64 v_cfPilot_E2_4;
  kcg_float64 v_cfPilot_E3_0;
  kcg_float64 v_cfPilot_E3_1;
  kcg_float64 v_cfPilot_E3_2;
  kcg_float64 v_cfPilot_E3_3;
  kcg_float64 v_cfPilot_E3_4;
  kcg_float64 v_cfPilot_E4_0;
  kcg_float64 v_cfPilot_E4_1;
  kcg_float64 v_cfPilot_E4_2;
  kcg_float64 v_cfPilot_E4_3;
  kcg_float64 v_cfPilot_E4_4;
  kcg_float64 v_cfPilot_F1_0;
  kcg_float64 v_cfPilot_F1_1;
  kcg_float64 v_cfPilot_F1_2;
  kcg_float64 v_cfPilot_F1_3;
  kcg_float64 v_cfPilot_F1_4;
  kcg_float64 v_cfPilot_F2_0;
  kcg_float64 v_cfPilot_F2_1;
  kcg_float64 v_cfPilot_F2_2;
  kcg_float64 v_cfPilot_F2_3;
  kcg_float64 v_cfPilot_F2_4;
  kcg_float64 v_cfPilot_F3_0;
  kcg_float64 v_cfPilot_F3_1;
  kcg_float64 v_cfPilot_F3_2;
  kcg_float64 v_cfPilot_F3_3;
  kcg_float64 v_cfPilot_F3_4;
  kcg_float64 v_cfPilot_F4_0;
  kcg_float64 v_cfPilot_F4_1;
  kcg_float64 v_cfPilot_F4_2;
  kcg_float64 v_cfPilot_F4_3;
  kcg_float64 v_cfPilot_F4_4;
} TS_LIBBSP_IMU_InstrumIMUData;

/* TS_LIBBSP_IMU_WriteDataBuffer/ */
typedef kcg_float32 TS_LIBBSP_IMU_WriteDataBuffer[32];

/* TS_LIBBSP_IMU_AdditionalDataWriteBuffer/ */
typedef kcg_float32 TS_LIBBSP_IMU_AdditionalDataWriteBuffer[6];

/* TS_LIBBSP_IMU_WriteAddrBuffer2/ */
typedef kcg_uint32 TS_LIBBSP_IMU_WriteAddrBuffer2[33];

/* TS_LIBBSP_PSUM_Conf/ */
typedef struct kcg_tag_TS_LIBBSP_PSUM_Conf {
  kcg_uint32 v_address;
  kcg_uint32 v_data;
} TS_LIBBSP_PSUM_Conf;

/* TS_LIBBSP_A429_Buffer/ */
typedef kcg_uint32 TS_LIBBSP_A429_Buffer[64];

/* TS_LIBBSP_IMU_InertialData/ */
typedef struct kcg_tag_TS_LIBBSP_IMU_InertialData {
  TS_LIBBSP_IMU_Vect3 dTheta;
  TS_LIBBSP_IMU_Vect3 dV;
  TS_LIBBSP_IMU_Vect3 Cp;
  TS_LIBBSP_IMU_Vect3 TheteE;
  TS_LIBBSP_IMU_Vect3 ErrFEP;
  TS_LIBBSP_IMU_Vect3 IndFEP;
  kcg_uint32 synth_umi;
  kcg_uint32 cpt_tache_fNav;
  TS_LIBBSP_IMU_Vect3 fs_filtA_BdL_fPilot_custUnit;
  TS_LIBBSP_IMU_Vect3 fs_filtB_BdL_fPilot_custUnit;
  TS_LIBBSP_IMU_Vect3 pqr_filtE_fPilot_custUnit;
  TS_LIBBSP_IMU_Vect3 pqr_filtF_fPilot_custUnit;
  TS_LIBBSP_IMU_Vect3 accAng_filtE_fPilot_custUnit;
  TS_LIBBSP_IMU_Vect3 accAng_filtF_fPilot_custUnit;
  TS_LIBBSP_IMU_Vect3 Tacc_filtre;
  kcg_float64 Tida_filtre;
  TS_LIBBSP_IMU_Vect3 Tacc_sature;
  TS_LIBBSP_IMU_Vect3 Cpulse_sature;
  kcg_float64 Tida_sature;
  kcg_uint32 AccStatus;
  kcg_uint32 HrgStatus1;
  kcg_uint32 HrgStatus2;
  kcg_uint32 TicStatus1;
  kcg_uint32 TicStatus2;
  TS_LIBBSP_IMU_Vect9 TmgyrData;
} TS_LIBBSP_IMU_InertialData;

/* TS_LIBBSP_PQRFS_Status_data/ */
typedef struct kcg_tag_TS_LIBBSP_PQRFS_Status_data {
  kcg_uint32 label_err_13;
  kcg_uint32 label_err_12;
  kcg_uint32 label_err_11;
  kcg_uint32 label_err_10;
  kcg_uint32 label_err_9;
  kcg_uint32 label_err_8;
  kcg_uint32 label_err_7;
  kcg_uint32 label_err_6;
  kcg_uint32 label_err_5;
  kcg_uint32 label_err_4;
  kcg_uint32 label_err_3;
  kcg_uint32 label_err_2;
  kcg_uint32 label_err_1;
} TS_LIBBSP_PQRFS_Status_data;

/* TS_LIBBSP_PQRFS_Status/ */
typedef struct kcg_tag_TS_LIBBSP_PQRFS_Status {
  TS_LIBBSP_PQRFS_Status_data data;
  kcg_uint32 status;
} TS_LIBBSP_PQRFS_Status;

/* TS_LIBBSP_ETR_ReadInfos/ */
typedef struct kcg_tag_TS_LIBBSP_ETR_ReadInfos {
  kcg_uint32 v_AlarmRegdata;
  kcg_uint32 v_ETregdata;
  kcg_uint16 v_EventCountdata;
} TS_LIBBSP_ETR_ReadInfos;

/* TS_LIBBSP_PLDMEG_IfCpuStatus/ */
typedef struct kcg_tag_TS_LIBBSP_PLDMEG_IfCpuStatus {
  kcg_bool parity_error;
  kcg_bool addr_error;
  kcg_bool acc_error;
  kcg_bool timeout_error;
  kcg_bool overload_error;
  kcg_uint8 error_counter;
} TS_LIBBSP_PLDMEG_IfCpuStatus;

/* TS_LIBBSP_SHM_CompStatus/ */
typedef struct kcg_tag_TS_LIBBSP_SHM_CompStatus {
  kcg_uint8 wd_failure_cnt;
  kcg_uint8 sw_reset_request_cnt;
  kcg_uint8 hw_reset_request_cnt;
  kcg_uint8 critical_uvd_cnt;
} TS_LIBBSP_SHM_CompStatus;

/* TA_LIBBSP_UART_RxBuffer/ */
typedef kcg_uint8 TA_LIBBSP_UART_RxBuffer[2048];

/* TS_LIBBSP_ETSEC_EthBuffer/ */
typedef kcg_uint8 TS_LIBBSP_ETSEC_EthBuffer[1518];

/* TS_LIBBSP_ETSEC_MacAddr/ */
typedef kcg_uint8 TS_LIBBSP_ETSEC_MacAddr[6];

/* TS_LIBBSP_ETSEC_ConfHostMac/ */
typedef struct kcg_tag_TS_LIBBSP_ETSEC_ConfHostMac {
  TS_LIBBSP_ETSEC_MacAddr mac_addr;
} TS_LIBBSP_ETSEC_ConfHostMac;

/* TS_LIBBSP_PQRFS_LabelConfig/ */
typedef struct kcg_tag_TS_LIBBSP_PQRFS_LabelConfig {
  kcg_float32 min;
  kcg_float32 max;
  kcg_int32 msb;
  kcg_int32 lsb;
  kcg_float32 q_value;
  kcg_int32 label_id;
  kcg_uint32 label_index;
} TS_LIBBSP_PQRFS_LabelConfig;

#ifndef kcg_copy_TS_LIBBSP_PQRFS_Status_data
#define kcg_copy_TS_LIBBSP_PQRFS_Status_data(kcg_C1, kcg_C2)                  \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_PQRFS_Status_data)))
#endif /* kcg_copy_TS_LIBBSP_PQRFS_Status_data */

#ifndef kcg_copy_TS_LIBBSP_IMU_InstrumIMUData
#define kcg_copy_TS_LIBBSP_IMU_InstrumIMUData(kcg_C1, kcg_C2)                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_IMU_InstrumIMUData)))
#endif /* kcg_copy_TS_LIBBSP_IMU_InstrumIMUData */

#ifndef kcg_copy_TS_LIBBSP_IMU_InertialData
#define kcg_copy_TS_LIBBSP_IMU_InertialData(kcg_C1, kcg_C2)                   \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_IMU_InertialData)))
#endif /* kcg_copy_TS_LIBBSP_IMU_InertialData */

#ifndef kcg_copy_TS_LIBBSP_SHM_BoardStatus
#define kcg_copy_TS_LIBBSP_SHM_BoardStatus(kcg_C1, kcg_C2)                    \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_SHM_BoardStatus)))
#endif /* kcg_copy_TS_LIBBSP_SHM_BoardStatus */

#ifndef kcg_copy_TS_LIBBSP_PQRFS_Status
#define kcg_copy_TS_LIBBSP_PQRFS_Status(kcg_C1, kcg_C2)                       \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_PQRFS_Status)))
#endif /* kcg_copy_TS_LIBBSP_PQRFS_Status */

#ifndef kcg_copy_TS_LIBBSP_PSUM_AdcErrorFlags
#define kcg_copy_TS_LIBBSP_PSUM_AdcErrorFlags(kcg_C1, kcg_C2)                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_PSUM_AdcErrorFlags)))
#endif /* kcg_copy_TS_LIBBSP_PSUM_AdcErrorFlags */

#ifndef kcg_copy_TS_LIBBSP_ETSEC_ConfHostMac
#define kcg_copy_TS_LIBBSP_ETSEC_ConfHostMac(kcg_C1, kcg_C2)                  \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_ETSEC_ConfHostMac)))
#endif /* kcg_copy_TS_LIBBSP_ETSEC_ConfHostMac */

#ifndef kcg_copy_TS_LIBBSP_PSUM_Conf
#define kcg_copy_TS_LIBBSP_PSUM_Conf(kcg_C1, kcg_C2)                          \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_PSUM_Conf)))
#endif /* kcg_copy_TS_LIBBSP_PSUM_Conf */

#ifndef kcg_copy_TS_LIBBSP_SHM_CompStatus
#define kcg_copy_TS_LIBBSP_SHM_CompStatus(kcg_C1, kcg_C2)                     \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_SHM_CompStatus)))
#endif /* kcg_copy_TS_LIBBSP_SHM_CompStatus */

#ifndef kcg_copy_TS_LIBBSP_ETR_ReadInfos
#define kcg_copy_TS_LIBBSP_ETR_ReadInfos(kcg_C1, kcg_C2)                      \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_ETR_ReadInfos)))
#endif /* kcg_copy_TS_LIBBSP_ETR_ReadInfos */

#ifndef kcg_copy_TS_LIBBSP_PLDCMP_ErrorStatus
#define kcg_copy_TS_LIBBSP_PLDCMP_ErrorStatus(kcg_C1, kcg_C2)                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_PLDCMP_ErrorStatus)))
#endif /* kcg_copy_TS_LIBBSP_PLDCMP_ErrorStatus */

#ifndef kcg_copy_TS_LIBBSP_PQRFS_LabelConfig
#define kcg_copy_TS_LIBBSP_PQRFS_LabelConfig(kcg_C1, kcg_C2)                  \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_PQRFS_LabelConfig)))
#endif /* kcg_copy_TS_LIBBSP_PQRFS_LabelConfig */

#ifndef kcg_copy_TS_LIBBSP_PLDMEG_IfCpuStatus
#define kcg_copy_TS_LIBBSP_PLDMEG_IfCpuStatus(kcg_C1, kcg_C2)                 \
  (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_PLDMEG_IfCpuStatus)))
#endif /* kcg_copy_TS_LIBBSP_PLDMEG_IfCpuStatus */

#ifndef kcg_copy_TS_LIBBSP_ETSEC_MacAddr
#define kcg_copy_TS_LIBBSP_ETSEC_MacAddr(kcg_C1, kcg_C2)                      \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_ETSEC_MacAddr)))
#endif /* kcg_copy_TS_LIBBSP_ETSEC_MacAddr */

#ifndef kcg_copy_TS_LIBBSP_ETSEC_EthBuffer
#define kcg_copy_TS_LIBBSP_ETSEC_EthBuffer(kcg_C1, kcg_C2)                    \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_ETSEC_EthBuffer)))
#endif /* kcg_copy_TS_LIBBSP_ETSEC_EthBuffer */

#ifndef kcg_copy_TS_LIBBSP_A429_Buffer
#define kcg_copy_TS_LIBBSP_A429_Buffer(kcg_C1, kcg_C2)                        \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_A429_Buffer)))
#endif /* kcg_copy_TS_LIBBSP_A429_Buffer */

#ifndef kcg_copy_TS_LIBBSP_IMU_AdditionalDataWriteBuffer
#define kcg_copy_TS_LIBBSP_IMU_AdditionalDataWriteBuffer(kcg_C1, kcg_C2)      \
  (kcg_assign_array(                                                          \
      (kcg_C1),                                                               \
      (kcg_C2),                                                               \
      sizeof (TS_LIBBSP_IMU_AdditionalDataWriteBuffer)))
#endif /* kcg_copy_TS_LIBBSP_IMU_AdditionalDataWriteBuffer */

#ifndef kcg_copy_TS_LIBBSP_IMU_Vect9
#define kcg_copy_TS_LIBBSP_IMU_Vect9(kcg_C1, kcg_C2)                          \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_IMU_Vect9)))
#endif /* kcg_copy_TS_LIBBSP_IMU_Vect9 */

#ifndef kcg_copy_TS_LIBBSP_IMU_Vect3
#define kcg_copy_TS_LIBBSP_IMU_Vect3(kcg_C1, kcg_C2)                          \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_IMU_Vect3)))
#endif /* kcg_copy_TS_LIBBSP_IMU_Vect3 */

#ifndef kcg_copy_TA_LIBBSP_UART_RxBuffer
#define kcg_copy_TA_LIBBSP_UART_RxBuffer(kcg_C1, kcg_C2)                      \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TA_LIBBSP_UART_RxBuffer)))
#endif /* kcg_copy_TA_LIBBSP_UART_RxBuffer */

#ifndef kcg_copy_TS_LIBBSP_IMU_WriteDataBuffer
#define kcg_copy_TS_LIBBSP_IMU_WriteDataBuffer(kcg_C1, kcg_C2)                \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_IMU_WriteDataBuffer)))
#endif /* kcg_copy_TS_LIBBSP_IMU_WriteDataBuffer */

#ifndef kcg_copy_TS_LIBBSP_IMU_WriteAddrBuffer2
#define kcg_copy_TS_LIBBSP_IMU_WriteAddrBuffer2(kcg_C1, kcg_C2)               \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_IMU_WriteAddrBuffer2)))
#endif /* kcg_copy_TS_LIBBSP_IMU_WriteAddrBuffer2 */

#ifndef kcg_copy_TS_LIBBSP_IMU_AdditionalDataReadBufferOut
#define kcg_copy_TS_LIBBSP_IMU_AdditionalDataReadBufferOut(kcg_C1, kcg_C2)    \
  (kcg_assign_array(                                                          \
      (kcg_C1),                                                               \
      (kcg_C2),                                                               \
      sizeof (TS_LIBBSP_IMU_AdditionalDataReadBufferOut)))
#endif /* kcg_copy_TS_LIBBSP_IMU_AdditionalDataReadBufferOut */

#ifndef kcg_copy_TS_LIBBSP_IMU_FloatTab
#define kcg_copy_TS_LIBBSP_IMU_FloatTab(kcg_C1, kcg_C2)                       \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (TS_LIBBSP_IMU_FloatTab)))
#endif /* kcg_copy_TS_LIBBSP_IMU_FloatTab */

#ifdef kcg_use_TS_LIBBSP_PQRFS_Status_data
#ifndef kcg_comp_TS_LIBBSP_PQRFS_Status_data
extern kcg_bool kcg_comp_TS_LIBBSP_PQRFS_Status_data(
  TS_LIBBSP_PQRFS_Status_data *kcg_c1,
  TS_LIBBSP_PQRFS_Status_data *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_PQRFS_Status_data */
#endif /* kcg_use_TS_LIBBSP_PQRFS_Status_data */

#ifdef kcg_use_TS_LIBBSP_IMU_InstrumIMUData
#ifndef kcg_comp_TS_LIBBSP_IMU_InstrumIMUData
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_InstrumIMUData(
  TS_LIBBSP_IMU_InstrumIMUData *kcg_c1,
  TS_LIBBSP_IMU_InstrumIMUData *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_InstrumIMUData */
#endif /* kcg_use_TS_LIBBSP_IMU_InstrumIMUData */

#ifdef kcg_use_TS_LIBBSP_IMU_InertialData
#ifndef kcg_comp_TS_LIBBSP_IMU_InertialData
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_InertialData(
  TS_LIBBSP_IMU_InertialData *kcg_c1,
  TS_LIBBSP_IMU_InertialData *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_InertialData */
#endif /* kcg_use_TS_LIBBSP_IMU_InertialData */

#ifdef kcg_use_TS_LIBBSP_SHM_BoardStatus
#ifndef kcg_comp_TS_LIBBSP_SHM_BoardStatus
extern kcg_bool kcg_comp_TS_LIBBSP_SHM_BoardStatus(
  TS_LIBBSP_SHM_BoardStatus *kcg_c1,
  TS_LIBBSP_SHM_BoardStatus *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_SHM_BoardStatus */
#endif /* kcg_use_TS_LIBBSP_SHM_BoardStatus */

#ifdef kcg_use_TS_LIBBSP_PQRFS_Status
#ifndef kcg_comp_TS_LIBBSP_PQRFS_Status
extern kcg_bool kcg_comp_TS_LIBBSP_PQRFS_Status(
  TS_LIBBSP_PQRFS_Status *kcg_c1,
  TS_LIBBSP_PQRFS_Status *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_PQRFS_Status */
#endif /* kcg_use_TS_LIBBSP_PQRFS_Status */

#ifdef kcg_use_TS_LIBBSP_PSUM_AdcErrorFlags
#ifndef kcg_comp_TS_LIBBSP_PSUM_AdcErrorFlags
extern kcg_bool kcg_comp_TS_LIBBSP_PSUM_AdcErrorFlags(
  TS_LIBBSP_PSUM_AdcErrorFlags *kcg_c1,
  TS_LIBBSP_PSUM_AdcErrorFlags *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_PSUM_AdcErrorFlags */
#endif /* kcg_use_TS_LIBBSP_PSUM_AdcErrorFlags */

#ifdef kcg_use_TS_LIBBSP_ETSEC_ConfHostMac
#ifndef kcg_comp_TS_LIBBSP_ETSEC_ConfHostMac
extern kcg_bool kcg_comp_TS_LIBBSP_ETSEC_ConfHostMac(
  TS_LIBBSP_ETSEC_ConfHostMac *kcg_c1,
  TS_LIBBSP_ETSEC_ConfHostMac *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_ETSEC_ConfHostMac */
#endif /* kcg_use_TS_LIBBSP_ETSEC_ConfHostMac */

#ifdef kcg_use_TS_LIBBSP_PSUM_Conf
#ifndef kcg_comp_TS_LIBBSP_PSUM_Conf
extern kcg_bool kcg_comp_TS_LIBBSP_PSUM_Conf(
  TS_LIBBSP_PSUM_Conf *kcg_c1,
  TS_LIBBSP_PSUM_Conf *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_PSUM_Conf */
#endif /* kcg_use_TS_LIBBSP_PSUM_Conf */

#ifdef kcg_use_TS_LIBBSP_SHM_CompStatus
#ifndef kcg_comp_TS_LIBBSP_SHM_CompStatus
extern kcg_bool kcg_comp_TS_LIBBSP_SHM_CompStatus(
  TS_LIBBSP_SHM_CompStatus *kcg_c1,
  TS_LIBBSP_SHM_CompStatus *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_SHM_CompStatus */
#endif /* kcg_use_TS_LIBBSP_SHM_CompStatus */

#ifdef kcg_use_TS_LIBBSP_ETR_ReadInfos
#ifndef kcg_comp_TS_LIBBSP_ETR_ReadInfos
extern kcg_bool kcg_comp_TS_LIBBSP_ETR_ReadInfos(
  TS_LIBBSP_ETR_ReadInfos *kcg_c1,
  TS_LIBBSP_ETR_ReadInfos *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_ETR_ReadInfos */
#endif /* kcg_use_TS_LIBBSP_ETR_ReadInfos */

#ifdef kcg_use_TS_LIBBSP_PLDCMP_ErrorStatus
#ifndef kcg_comp_TS_LIBBSP_PLDCMP_ErrorStatus
extern kcg_bool kcg_comp_TS_LIBBSP_PLDCMP_ErrorStatus(
  TS_LIBBSP_PLDCMP_ErrorStatus *kcg_c1,
  TS_LIBBSP_PLDCMP_ErrorStatus *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_PLDCMP_ErrorStatus */
#endif /* kcg_use_TS_LIBBSP_PLDCMP_ErrorStatus */

#ifdef kcg_use_TS_LIBBSP_PQRFS_LabelConfig
#ifndef kcg_comp_TS_LIBBSP_PQRFS_LabelConfig
extern kcg_bool kcg_comp_TS_LIBBSP_PQRFS_LabelConfig(
  TS_LIBBSP_PQRFS_LabelConfig *kcg_c1,
  TS_LIBBSP_PQRFS_LabelConfig *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_PQRFS_LabelConfig */
#endif /* kcg_use_TS_LIBBSP_PQRFS_LabelConfig */

#ifdef kcg_use_TS_LIBBSP_PLDMEG_IfCpuStatus
#ifndef kcg_comp_TS_LIBBSP_PLDMEG_IfCpuStatus
extern kcg_bool kcg_comp_TS_LIBBSP_PLDMEG_IfCpuStatus(
  TS_LIBBSP_PLDMEG_IfCpuStatus *kcg_c1,
  TS_LIBBSP_PLDMEG_IfCpuStatus *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_PLDMEG_IfCpuStatus */
#endif /* kcg_use_TS_LIBBSP_PLDMEG_IfCpuStatus */

#ifdef kcg_use_TS_LIBBSP_ETSEC_MacAddr
#ifndef kcg_comp_TS_LIBBSP_ETSEC_MacAddr
extern kcg_bool kcg_comp_TS_LIBBSP_ETSEC_MacAddr(
  TS_LIBBSP_ETSEC_MacAddr *kcg_c1,
  TS_LIBBSP_ETSEC_MacAddr *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_ETSEC_MacAddr */
#endif /* kcg_use_TS_LIBBSP_ETSEC_MacAddr */

#ifdef kcg_use_TS_LIBBSP_ETSEC_EthBuffer
#ifndef kcg_comp_TS_LIBBSP_ETSEC_EthBuffer
extern kcg_bool kcg_comp_TS_LIBBSP_ETSEC_EthBuffer(
  TS_LIBBSP_ETSEC_EthBuffer *kcg_c1,
  TS_LIBBSP_ETSEC_EthBuffer *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_ETSEC_EthBuffer */
#endif /* kcg_use_TS_LIBBSP_ETSEC_EthBuffer */

#ifdef kcg_use_TS_LIBBSP_A429_Buffer
#ifndef kcg_comp_TS_LIBBSP_A429_Buffer
extern kcg_bool kcg_comp_TS_LIBBSP_A429_Buffer(
  TS_LIBBSP_A429_Buffer *kcg_c1,
  TS_LIBBSP_A429_Buffer *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_A429_Buffer */
#endif /* kcg_use_TS_LIBBSP_A429_Buffer */

#ifdef kcg_use_TS_LIBBSP_IMU_AdditionalDataWriteBuffer
#ifndef kcg_comp_TS_LIBBSP_IMU_AdditionalDataWriteBuffer
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_AdditionalDataWriteBuffer(
  TS_LIBBSP_IMU_AdditionalDataWriteBuffer *kcg_c1,
  TS_LIBBSP_IMU_AdditionalDataWriteBuffer *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_AdditionalDataWriteBuffer */
#endif /* kcg_use_TS_LIBBSP_IMU_AdditionalDataWriteBuffer */

#ifdef kcg_use_TS_LIBBSP_IMU_Vect9
#ifndef kcg_comp_TS_LIBBSP_IMU_Vect9
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_Vect9(
  TS_LIBBSP_IMU_Vect9 *kcg_c1,
  TS_LIBBSP_IMU_Vect9 *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_Vect9 */
#endif /* kcg_use_TS_LIBBSP_IMU_Vect9 */

#ifdef kcg_use_TS_LIBBSP_IMU_Vect3
#ifndef kcg_comp_TS_LIBBSP_IMU_Vect3
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_Vect3(
  TS_LIBBSP_IMU_Vect3 *kcg_c1,
  TS_LIBBSP_IMU_Vect3 *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_Vect3 */
#endif /* kcg_use_TS_LIBBSP_IMU_Vect3 */

#ifdef kcg_use_TA_LIBBSP_UART_RxBuffer
#ifndef kcg_comp_TA_LIBBSP_UART_RxBuffer
extern kcg_bool kcg_comp_TA_LIBBSP_UART_RxBuffer(
  TA_LIBBSP_UART_RxBuffer *kcg_c1,
  TA_LIBBSP_UART_RxBuffer *kcg_c2);
#endif /* kcg_comp_TA_LIBBSP_UART_RxBuffer */
#endif /* kcg_use_TA_LIBBSP_UART_RxBuffer */

#ifdef kcg_use_TS_LIBBSP_IMU_WriteDataBuffer
#ifndef kcg_comp_TS_LIBBSP_IMU_WriteDataBuffer
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_WriteDataBuffer(
  TS_LIBBSP_IMU_WriteDataBuffer *kcg_c1,
  TS_LIBBSP_IMU_WriteDataBuffer *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_WriteDataBuffer */
#endif /* kcg_use_TS_LIBBSP_IMU_WriteDataBuffer */

#ifdef kcg_use_TS_LIBBSP_IMU_WriteAddrBuffer2
#ifndef kcg_comp_TS_LIBBSP_IMU_WriteAddrBuffer2
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_WriteAddrBuffer2(
  TS_LIBBSP_IMU_WriteAddrBuffer2 *kcg_c1,
  TS_LIBBSP_IMU_WriteAddrBuffer2 *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_WriteAddrBuffer2 */
#endif /* kcg_use_TS_LIBBSP_IMU_WriteAddrBuffer2 */

#ifdef kcg_use_TS_LIBBSP_IMU_AdditionalDataReadBufferOut
#ifndef kcg_comp_TS_LIBBSP_IMU_AdditionalDataReadBufferOut
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_AdditionalDataReadBufferOut(
  TS_LIBBSP_IMU_AdditionalDataReadBufferOut *kcg_c1,
  TS_LIBBSP_IMU_AdditionalDataReadBufferOut *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_AdditionalDataReadBufferOut */
#endif /* kcg_use_TS_LIBBSP_IMU_AdditionalDataReadBufferOut */

#ifdef kcg_use_TS_LIBBSP_IMU_FloatTab
#ifndef kcg_comp_TS_LIBBSP_IMU_FloatTab
extern kcg_bool kcg_comp_TS_LIBBSP_IMU_FloatTab(
  TS_LIBBSP_IMU_FloatTab *kcg_c1,
  TS_LIBBSP_IMU_FloatTab *kcg_c2);
#endif /* kcg_comp_TS_LIBBSP_IMU_FloatTab */
#endif /* kcg_use_TS_LIBBSP_IMU_FloatTab */

#endif /* _KCG_TYPES_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** kcg_types.h
** Generation date: 2023-02-08T15:08:48
*************************************************************$ */

