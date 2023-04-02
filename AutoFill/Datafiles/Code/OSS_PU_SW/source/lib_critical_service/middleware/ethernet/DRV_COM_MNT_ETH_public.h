/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef DRV_COM_MNT_ETH_PUBLIC_H
#define DRV_COM_MNT_ETH_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/stack_ip/ETH_UDP_public.h"

/* ---------- provided define constants: ------------------------------------ */
#define DRV_COM_MNT_ETH_MSG_TX_MAX 5610
#define DRV_COM_MNT_ETH_MSG_RX_MAX 6000
#define DRV_COM_MNT_NB_FRAG_MAX (DRV_COM_MNT_ETH_MSG_TX_MAX % K_MAX_MF_DATA_SIZE )

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint16_t LCH_CTRL_TX_MSG_UDP_PORT_SRC;
   uint16_t LCH_CTRL_TX_MSG_UDP_PORT_DST;
   uint32_t LCH_CTRL_TX_MSG_IP_DST;
   uint32_t LCH_CTRL_TX_MSG_SIZE;
   const uint8_t *LCH_CTRL_TX_MSG_DATA;
   uint32_t LCH_CTRL_TX_STATUS;
} ts_DRV_COM_MNT_ETH_TX;

typedef struct
{
   uint16_t LCH_CTRL_RX_MSG_UDP_PORT_SRC;
   uint16_t LCH_CTRL_RX_MSG_UDP_PORT_DST;
   uint32_t LCH_CTRL_RX_MSG_IP_DST;
   uint32_t LCH_CTRL_RX_status;
   uint16_t LCH_CTRL_RX_DATA_COUNT;
   uint8_t *LCH_CTRL_RX_DATA;
} ts_DRV_COM_MNT_ETH_RX;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided datas: ----------------------------------------------- */
extern ts_CMN_IOSP_BUFFER udpBufferUODReception;

/* ---------- provided operations: ------------------------------------------ */
/**
* The DRV_COM_MNT_ETH_INIT operation allow to initialize IP source
*
* @param[in] p_myIP is the IP source
*
*/
extern void DRV_COM_MNT_ETH_INIT( void );

/**
* The DRV_COM_MNT_ETH_HANDLE_RECEPTION operation allow to handle reception of an Ethernet Frame
*
*/
extern void DRV_COM_MNT_ETH_HANDLE_RECEPTION( void );

/**
* The DRV_COM_MNT_ETH_HANDLE_PORT operation allow to open / close UDP ports for reception
*
* @param[in] p_cmd_port is 0 to Open Port, different 0 to Close port
*
* @param[in] p_port_src is the number UDP Port to open or close
*
* @param[in] p_isUOD is e_CMN_FLAG_YES for UOD port, e_CMN_FLAG_NO for others types of Ports
*
* @param[in] p_udpBuffer is the Buffer associated to the Open UDP port
*
* @param[out] p_ETH_Init_status is e_ETH_UDP_PORT_OPEN, e_ETH_UDP_PORT_ALREADY_DONE, e_ETH_UDP_PORT_ALREADY_CLOSED and e_ETH_UDP_PORT_ACTION_FAILED
*
*/
extern void DRV_COM_MNT_ETH_HANDLE_PORT( uint32_t const p_cmd_port,
                                         uint32_t const p_port_src,
                                         te_CMN_FLAG_QUESTION p_isUOD,
                                         ts_CMN_IOSP_BUFFER * p_udpBuffer,
                                         te_ETH_UDP_PORT_Status * p_ETH_Init_status );

/**
* The DRV_COM_MNT_ETH_WRITE operation allow to send a message (UDP datagram)
*
* @param[in] LCH_CTRL_TX_MSG_UDP_PORT_SRC is the UDP Port SRC used for tx
*
* @param[in] LCH_CTRL_TX_MSG_UDP_PORT_DST is the UDP Port DST used for tx
*
* @param[in] LCH_CTRL_TX_MSG_IP_DST is the IP DST used for tx
*
* @param[in] LCH_CTRL_TX_MSG_SIZE is the size of the Message to send
*
* @param[in] LCH_CTRL_TX_MSG_DATA is the data of the Message to send
*
* @param[out] LCH_CTRL_TX_STATUS is the status of transmission
*
*/
extern void DRV_COM_MNT_ETH_WRITE( ts_DRV_COM_MNT_ETH_TX * p_eth_tx );

/**
* The DRV_COM_MNT_ETH_READ operation allow to receive a message (UDP datagram)
*
* @param[in] p_eth_rx->LCH_CTRL_TX_MSG_UDP_PORT_SRC is the UDP Port SRC used for rx
*
* @param[out] p_eth_rx->LCH_CTRL_TX_MSG_UDP_PORT_DST is the UDP Port DST received from Transmitter
*
* @param[out] p_eth_rx->LCH_CTRL_TX_MSG_IP_DST is the IP DST received from Transmitter
*
* @param[out] p_eth_rx->LCH_CTRL_RX_status is the status of reception

* @param[out] p_eth_rx->LCH_CTRL_RX_DATA_COUNT is the size of the Message received
*
* @param[out] p_eth_rx->LCH_CTRL_RX_DATA is the data of the Message received
*
*
*/
extern void DRV_COM_MNT_ETH_READ( ts_DRV_COM_MNT_ETH_RX * p_eth_rx );

#endif /* DRV_COM_MNT_ETH_PUBLIC_H */
