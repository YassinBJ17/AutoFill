/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MBX_HAL_PUBLIC_H
#define MBX_HAL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/ethernet/ETH_MAC_public.h"

/* ---------- provided define constants: ------------------------------------ */
/* Parity Corruption Mask */
#define MBX_CORRUPT_PARITY_MASK (uint32_t)0x00000001

#define MBX_NB           ((CMN_IOSP_ID_t)1ul)

#define INTEG_MBX_CFEX_RX_BUF_SIZE (uint32_t)1536
#define INTEG_MBX_CFEX_RX_BUF_SIZE_IN_WORDS (INTEG_MBX_CFEX_RX_BUF_SIZE / 4)

/* ---------- provided types: ----------------------------------------------- */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_3_31            : 30;
      uint32_t s_tx_fifo_fifo_ovf_err     : 1;
      uint32_t s_tx_cmd_fifo_fifo_ovf_err : 1;
   } u_B;
}
tu_MBX_TX_STATUS;


typedef struct
{
   /* Transfer done  */
   int32_t s_len;
   te_CMN_FLAG_COMPLETE s_status;
}
ts_MBX_HAL_STATS_TRANSFERT;

/* Fifo 1rst data register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_Reserved1          : 12;
      uint32_t s_rx_tkeep           : 4;
      uint32_t s_Reserved2          : 5;
      uint32_t s_rx_tsize           : 11;
   } u_B;
}
tu_RX_FIRST_DATA_REG;

/* Fifo status register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_17_31          : 15;
      uint32_t s_rx_enable               : 1;
      uint32_t s_reserved_10_15          : 6;
      uint32_t s_rx_fifo_double_biterr   : 1;
      uint32_t s_rx_fifo_single_biterr   : 1;
      uint32_t s_reserved_6_7            : 2;
      uint32_t s_rx_fifo_overflow        : 1;
      uint32_t s_rx_fifo_flush_done      : 1;
      uint32_t s_rx_fifo_full            : 1;
      uint32_t s_reserved_2              : 1;
      uint32_t s_rx_fifo_almost_empty    : 1;
      uint32_t s_rx_fifo_empty           : 1;
   } u_B;
}
tu_MBX_RX_FIFO_STATUS_REG;


/* Fifo status acknowledge register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_3_31           : 29;
      uint32_t s_rx_fifo_biterr_ack      : 1;
      uint32_t s_rx_fifo_overflow_ack    : 1;
      uint32_t s_rx_fifo_flush_ack       : 1;
   } u_B;
}
tu_RX_FIFO_STATUS_ACK_REG;

/* Fifo control register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_3_31                   : 29;
      uint32_t s_rx_fifo_inject_double_biterr    : 1;
      uint32_t s_rx_fifo_inject_single_biterr    : 1;
      uint32_t s_rx_fifo_flush                   : 1;
   } u_B;
}
tu_RX_FIFO_CONTROL_REG;

/* Fifo configuration register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_29_31                  : 3;
      uint32_t s_rx_fifo_almost_full_threshold   : 13;
      uint32_t s_reserved_13_15                  : 3;
      uint32_t s_rx_fifo_almost_empty_threshold  : 13;
   } u_B;
}
tu_RX_FIFO_CONFIG1_REG;

/* Fifo status register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_10_31          : 22;
      uint32_t s_tx_fifo_double_biterr   : 1;
      uint32_t s_tx_fifo_single_biterr   : 1;
      uint32_t s_reserved_7              : 1;
      uint32_t tx_sending                : 1;
      uint32_t s_tx_fifo_overflow        : 1;
      uint32_t s_tx_fifo_flush_done      : 1;
      uint32_t s_tx_fifo_full            : 1;
      uint32_t s_tx_fifo_almost_full     : 1;
      uint32_t s_tx_fifo_almost_empty    : 1;
      uint32_t s_tx_fifo_empty           : 1;
   } u_B;
}
tu_MBX_TX_FIFO_STATUS_REG;

/* Fifo status acknowledge register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved                : 29;
      uint32_t s_tx_fifo_biterr_ack      : 1;
      uint32_t s_tx_fifo_overflow_ack    : 1;
      uint32_t s_tx_fifo_flush_ack       : 1;
   } u_B;
}
tu_TX_FIFO_STATUS_ACK_REG;

/* Fifo control register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved                        : 29;
      uint32_t s_tx_fifo_inject_double_biterr    : 1;
      uint32_t s_tx_fifo_inject_single_biterr    : 1;
      uint32_t s_tx_fifo_flush                   : 1;
   } u_B;
}
tu_TX_FIFO_CONTROL_REG;

/* Fifo configuration register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_29_31                  : 3;
      uint32_t s_tx_fifo_almost_full_threshold   : 13;
      uint32_t s_reserved_13_15                  : 3;
      uint32_t s_tx_fifo_almost_empty_threshold  : 13;
   } u_B;
}
tu_TX_FIFO_CONFIG_REG;

/* Fifo status register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_17_31              : 15;
      uint32_t s_tx_enable                   : 1;
      uint32_t s_reserved_11_15              : 5;
      uint32_t tx_corruption_status          : 1;
      uint32_t s_tx_cmd_fifo_double_biterr   : 1;
      uint32_t s_tx_cmd_fifo_single_biterr   : 1;
      uint32_t s_reserved_6_7                : 2;
      uint32_t s_tx_cmd_fifo_overflow        : 1;
      uint32_t s_tx_cmd_fifo_flush_done      : 1;
      uint32_t s_tx_cmd_fifo_full            : 1;
      uint32_t s_tx_cmd_fifo_almost_full     : 1;
      uint32_t s_tx_cmd_fifo_almost_empty    : 1;
      uint32_t s_tx_cmd_fifo_empty           : 1;
   } u_B;
}
tu_MBX_TX_CMD_FIFO_STATUS_REG;

/* Fifo status acknowledge register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved                    : 28;
      uint32_t s_tx_corruption_ack           : 1;
      uint32_t s_tx_cmd_fifo_biterr_ack      : 1;
      uint32_t s_tx_cmd_fifo_overflow_ack    : 1;
      uint32_t s_tx_cmd_fifo_flush_ack       : 1;
   } u_B;
}
tu_TX_CMD_FIFO_STATUS_ACK_REG;

/* Fifo control register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved                            : 29;
      uint32_t s_tx_cmd_fifo_inject_double_biterr    : 1;
      uint32_t s_tx_cmd_fifo_inject_single_biterr    : 1;
      uint32_t s_tx_cmd_fifo_flush                   : 1;
   } u_B;
}
tu_TX_CMD_FIFO_CONTROL_REG;

/* Fifo configuration register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_29_31                      : 3;
      uint32_t s_tx_cmd_fifo_almost_full_threshold   : 13;
      uint32_t s_reserved_13_15                      : 3;
      uint32_t s_tx_cmd_fifo_almost_empty_threshold  : 13;
   } u_B;
}
tu_TX_CMD_FIFO_CONFIG_REG;

/* Fifo configuration delay register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved                        : 22;
      uint32_t tx_delay                          : 10;
   } u_B;
}
tu_TX_CMD_FIFO_DELAY_CONFIG_REG;

/* Fifo configuration delay register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t tx_conf_start_address             : 20;
      uint32_t tx_source                         : 1;
      uint32_t tx_size                           : 11;
   } u_tx_auxiliary_send;
   struct
   {
      uint32_t s_reserved_18_31                  : 14;
      uint32_t tx_offset                         : 2;
      uint32_t s_reserved_12_15                  : 4;
      uint32_t tx_source                         : 1;
      uint32_t tx_size                           : 11;
   } u_tx_fifo_send;
}
tu_TX_CMD_DATA_REG;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided datas: ----------------------------------------------- */
extern uint32_t MBX_rxBuf [ INTEG_MBX_CFEX_RX_BUF_SIZE_IN_WORDS ] ;

/* ---------- provided operations: ------------------------------------------ */
/* Management function for Eth porting*/
/* */
extern void MBX_INIT( tu_CMN_RC * const p_return_code );

extern void MBX_INIT_tx( CMN_IOSP_ID_t const p_mbx_fifo_conf_id );

extern void MBX_INIT_rx( CMN_IOSP_ID_t const p_mbx_fifo_conf_id );

extern void MBX_ESTABLISH_CONNECTION ( tu_CMN_RC * const p_return_code );

extern void MBX_GET_STATUS_READ( ts_MBX_HAL_STATS_TRANSFERT * const p_pt_stats );

extern void MBX_GET_STATUS_WRITE( ts_MBX_HAL_STATS_TRANSFERT * const p_pt_stats );

extern void MBX_GET_MAC( MAC_ETH_MACAddr_t * const p_pt_mac_addr );

extern void MBX_ALLOW_RCV(void);

extern void MBX_READ ( ts_CMN_IOSP_BUFFER * const p_buffer );

extern void MBX_WRITE( const ts_CMN_IOSP_BUFFER* const p_buff  );

/* Management function for Mbx */
/* */
extern void MBX_FIFO_RX_READ_CONFIG1 ( CMN_IOSP_ID_t const p_conf_ip_id, tu_RX_FIFO_CONFIG1_REG * const p_status_value );

extern void MBX_FIFO_READ_DATA ( CMN_IOSP_ID_t        const p_MBX_FIFO_conf_id,
                                 CMN_SYSTEM_SIZE_t    const p_buff_size,
                                 uint32_t             const p_offset,
                                 ts_CMN_IOSP_BUFFER * const p_buffer);

extern void MBX_FIFO_READ_SIZE_DATA ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_RX_FIRST_DATA_REG  * const  p_rx_first_data);

extern void MBX_READ_STATUS ( CMN_IOSP_ID_t const p_conf_ip_id, tu_MBX_RX_FIFO_STATUS_REG * const p_status_value );

extern void MBX_FIFO_READ_TIMESTAMP_DATA ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, uint32_t * const  p_timestamp);

extern void MBX_FIFO_RX_WRITE_CONFIG1 ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_RX_FIFO_CONFIG1_REG * const p_status_value );

extern void MBX_FIFO_RX_WRITE_CONTROL ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_RX_FIFO_CONTROL_REG * const p_status_value );

extern void MBX_FIFO_RX_WRITE_STATUS_ACK ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_RX_FIFO_STATUS_ACK_REG * const p_status_value );

extern void MBX_FIFO_TX_CMD_READ_STATUS ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_MBX_TX_CMD_FIFO_STATUS_REG * const p_status_value );

extern void MBX_FIFO_TX_CMD_WRITE_CONFIG ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_CMD_FIFO_CONFIG_REG * const p_status_value );

extern void MBX_FIFO_TX_CMD_WRITE_CONTROL ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_CMD_FIFO_CONTROL_REG * const p_status_value );

extern void MBX_FIFO_TX_CMD_WRITE_DATA ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_CMD_DATA_REG * const p_tx_fifo_data );

extern void MBX_FIFO_TX_CMD_WRITE_DELAY_CONFIG ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_CMD_FIFO_DELAY_CONFIG_REG * const p_status_value );

extern void MBX_FIFO_TX_CMD_WRITE_STATUS_ACK ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_CMD_FIFO_STATUS_ACK_REG * const p_status_value );

extern void MBX_FIFO_TX_READ_STATUS ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_MBX_TX_FIFO_STATUS_REG * const p_status_value );

extern void MBX_FIFO_TX_WRITE_CONFIG ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_FIFO_CONFIG_REG * const p_status_value );

extern void MBX_FIFO_TX_WRITE_CONTROL ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_FIFO_CONTROL_REG * const p_status_value );

extern void MBX_FIFO_TX_WRITE_DATA ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, uint32_t p_tx_fifo_data );

extern void MBX_FIFO_TX_WRITE_STATUS_ACK ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_FIFO_STATUS_ACK_REG * const p_status_value );

extern void MBX_FIFO_TX_READ_CONFIG ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id, tu_TX_FIFO_CONFIG_REG * const p_status_value );

#endif /* MBX_HAL_PUBLIC_H */
