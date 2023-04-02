/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MAC_ETH_HAL_PUBLIC_H
#define MAC_ETH_HAL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/ethernet/ETH_MAC_public.h"

/* ---------- provided define constants: ------------------------------------ */
#define MAC_ETH_NB           ((CMN_IOSP_ID_t)1ul)

/* ---------- provided types: ----------------------------------------------- */
/* Status of MAC ethernet receiver (1/2) register */
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_Reserved                           : 24;
      uint32_t s_eth_rx_stat_frame_filtre           : 8;
   } u_B;
}
tu_MAC_ETH_RX_STATUS_1_REG;

/* Status of MAC ethernet receiver (2/2) register*/
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_eth_rx_stat_frame_err_phy         : 8;
      uint32_t s_eth_rx_stat_frame_err_fcs         : 8;
      uint32_t s_eth_rx_stat_frame_err_sz          : 8;
      uint32_t s_eth_rx_stat_frame_err_ifg         : 8;
   } u_B;
}
tu_MAC_ETH_RX_STATUS_2_REG;

/* Status of MAC ethernet receiver (2/2) register*/
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_Reserved                          : 23;
      uint32_t s_eth_tx_buffer_idle                : 1;
      uint32_t s_eth_tx_stat_frame_err_sz          : 8;
   } u_B;
}
tu_MAC_ETH_TX_STATUS_REG;

/* MSB de {eth_rx_filtre_dest_adr_0} register*/
typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_Reserved                          : 16;
      uint32_t s_eth_rx_filtre_dest_adr_0_h1_reg   : 8;
      uint32_t s_eth_rx_filtre_dest_adr_0_h0_reg   : 8;
   } u_B;
}
tu_MAC_ETH_RX_FILTRE_DEST_ADR_0_H_REG;

typedef struct
{
   /* Transfer done  */
   int32_t s_len;
   te_CMN_FLAG_COMPLETE s_status;
}
ts_MAC_ETH_HAL_STATS_TRANSFERT;


/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided datas: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void MAC_ETH_INIT( tu_CMN_RC * const p_return_code );

extern void MAC_ETH_READ_RX_STATUS1 ( CMN_IOSP_ID_t const p_conf_ip_id, uint32_t * const  p_eth_rx_stat_frame_filtre );

extern void MAC_ETH_READ_RX_STATUS2 ( CMN_IOSP_ID_t const p_conf_ip_id, tu_MAC_ETH_RX_STATUS_2_REG * const  p_status_value );

extern void MAC_ETH_READ_TX_STATUS  ( CMN_IOSP_ID_t const p_conf_ip_id, tu_MAC_ETH_TX_STATUS_REG * const  p_status_value );

extern void MAC_ETH_SET_MAC_DST ( CMN_IOSP_ID_t const p_conf_ip_id, const MAC_ETH_MACAddr_t * p_mac_addr );

extern void MAC_ETH_SET_MAC_DST_MASK ( CMN_IOSP_ID_t const p_conf_ip_id, const MAC_ETH_MACAddr_t * const p_mac_mask_addr);

extern void MAC_ETH_SET_MAC_SRC  ( CMN_IOSP_ID_t const p_conf_ip_id, const MAC_ETH_MACAddr_t * p_mac_addr );

extern void MAC_ETH_SET_MAC_SRC_MASK  ( CMN_IOSP_ID_t const p_conf_ip_id, const MAC_ETH_MACAddr_t * const p_mac_mask_addr);

#endif /* MAC_ETH_HAL_PUBLIC_H */
