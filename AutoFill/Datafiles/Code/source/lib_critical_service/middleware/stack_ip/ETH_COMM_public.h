/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef ETH_COMM_PUBLIC_H
#define ETH_COMM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "middleware/stack_ip/ETH_public.h"
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
#define UDP_HEADER_SIZE 8
#define ETH_UDP_IP_SIZE 42

#define ETH_TX_FIFO_OVF_ERR   ( 0x8000ul )

/* ---------- provided types: ----------------------------------------------- */


typedef enum
{
   ETH_COMM_STATUS_OK       = 0,
   ETH_COMM_STATUS_FAILURE  = 1,
   ETH_COMM_STATUS_DISABLED = 2
} t_eth_comm_status;

typedef union
{
   uint32_t u_R;
   struct
   {
      uint32_t s_reserved_3_31               : 30;
      uint32_t s_tx_fifo_fifo_ovf_err        : 1;
      uint32_t s_tx_cmd_fifo_fifo_ovf_err    : 1;
   } u_B;
}
tu_ETH_TX_STATUS;


typedef struct
{
   uint32_t s_SrcPortAS;
   uint32_t s_SrcPortUOD;
   uint32_t s_DstPortUOD;
   ts_ETH_EthernetAddress s_IdDest ;
}ts_EthUdpInfo;

typedef struct
{
   uint32_t s_SrcPort;
   uint32_t s_DstPort;
}ts_PortUdpInfo;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided datas: ----------------------------------------------- */
extern const MAC_ETH_MACAddr_t c_mac_CDMAaddr;
extern const MAC_ETH_MACAddr_t c_mac_CDMBaddr;
extern ts_EthUdpInfo ethUdpInfo;

/* ---------- provided operations: ------------------------------------------ */
extern void ETH_COMM_INIT( void );

extern t_eth_comm_status ETH_COMM_read( uint8_t *in_msg,
                                        uint32_t nb_bytes,
                                        uint16_t *nb_bytes_read,
                                        uint16_t *p_port_dst,
                                        uint32_t *p_ip_dst,
                                        int8_t *in_buffer );

extern t_eth_comm_status ETH_COMM_write( const uint8_t *out_msg,
                                         uint32_t nb_bytes,
                                         uint16_t port_src,
                                         uint16_t port_dst,
                                         uint32_t p_ip_dst,
                                         uint32_t *p_out_tx_status );


#endif /* ETH_COMM_PUBLIC_H */

