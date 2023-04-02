/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_ICMP_PRIVATE_H
#define ETH_ICMP_PRIVATE_H

#include "middleware/stack_ip/ETH_common.h"

/*---------------------------------------------------------------------------*/
/*-- Definitions*/
/*---------------------------------------------------------------------------*/

/* ICMP Type definitions*/
#define K_ETH_ICMP_ECHO_REPLY                   (0)
#define K_ETH_ICMP_DESTINATION_UNREACHABLE      (3)
#define K_ETH_ICMP_SOURCE_QUENCH                (4)
#define K_ETH_ICMP_REDIRECT_MESSAGE             (5)
#define K_ETH_ICMP_ECHO_REQUEST                 (8)
#define K_ETH_ICMP_TIME_EXCEEDED                (11)
#define K_ETH_ICMP_PARAMETER_PROBLEM_MESSAGE    (12)
#define K_ETH_ICMP_TIMESTAMP_REQUEST            (13)
#define K_ETH_ICMP_TIMESTAMP_REPLY              (14)
#define K_ETH_ICMP_INFORMATION_REQUEST          (15)
#define K_ETH_ICMP_INFORMATION_REPLY            (16)

#define K_ETH_ICMP_ECH_REPLY_CODE               (0)




/*---------------------------------------------------------------------------*/
/*-- Typedefs*/
/*---------------------------------------------------------------------------*/
typedef struct
{
   ts_ETH_ReceiveBuffer s_RcvBuf;  /* saved rcv buffers */
   int8_t               s_TxPacket [ K_ETH_MAX_ENET_PACKET_SIZE ];
   ts_ETH_STATS_PACKET  s_ICMPstats;

} ts_ETH_ICMP_CONTROL ;


/*---------------------------------------------------------------------------*/
/*-- Data*/
/*---------------------------------------------------------------------------*/

extern  ts_ETH_ICMP_CONTROL v_ETH_ICMP_ControlObj ;

extern void ETH_ICMP_SendEchoReply( const ts_CMN_IOSP_BUFFER * const p_Data );

/*---------------------------------------------------------------------------*/
/*-- Local Functions/Procedures*/
/*---------------------------------------------------------------------------*/

#endif /* ETH_ICMP_PRIVATE_H */
