/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_COMMON_H
#define ETH_COMMON_H

#include "middleware/stack_ip/ETH_public.h"
#include "middleware/ethernet/ETH_porting.h"
#include "type/common_type.h"

/* ---------- provided define constants --------------------------------------- */

#define K_ETH_MAX_ENET_PACKET_SIZE (1518ul)   /* Maximum packet size*/

/*
 * MBX discard from Ethernet frame size the FCS
 */
#if (ETH_FEC != 0 )
#define K_ETH_MIN_ENET_PACKET_SIZE (64ul)     /* Minimum packet size FEC*/
#else
#define K_ETH_MIN_ENET_PACKET_SIZE (60ul)     /* Minimum packet size MBX*/
#endif


#define K_ETH_ARP_BROADCAST_ADDR   (0xFF)

/* ---------- provided types -------------------------------------------------- */

typedef enum
{
   e_ETH_PROTO_IP = 0x0800,
   e_ETH_PROTO_ARP = 0x0806
} te_ETH_PROTO_TYPE ;

typedef struct
{
   uint16_t s_msb;
   uint16_t s_lsb;
} ts_u16;

typedef union
{
   ts_u16   u_u16;
   uint32_t u_u32;
} tu_u32u16;

typedef struct
{
   uint16_t s_msbmsb;
   uint16_t s_msblsb;
   uint16_t s_lsbmsb;
   uint16_t s_lsblsb;
} ts_u16x4;

typedef union
{
   uint64_t u_u64;
   ts_u16x4 u_u16x4;
} tu_Timeu16;


typedef struct
{
   uint32_t         s_EtherLen;        /* data length in bytes */
   uint8_t          s_EtherBuf[ K_ETH_MAX_ENET_PACKET_SIZE ];
} ts_ETH_ReceiveBuffer;

typedef struct
{
   uint32_t s_handled ;
   uint32_t s_dropped ;
   uint32_t s_nok ;
} ts_ETH_STATS_PACKET ;

typedef struct
{
   ts_ETH_STATS_PACKET s_packet_rx;
   ts_ETH_STATS_PACKET s_packet_tx;

} ts_ETH_STATS;



/* ---------- provided constants and data  ------------------------------------ */

/* */
extern ts_ETH_EthernetAddress  v_ETH_DRV_EtherOwnAddr;    /* own ethernet hw & ip address */

/* ---------- provided function ----------------------------------------------- */

extern void ETH_DRV_OnRecv( const ts_CMN_IOSP_BUFFER * const p_Data,
                            te_CMN_FLAG_QUESTION       const p_broadcast );

extern uint32_t ETH_DRV_SEND_FRAME ( const ts_ETH_MACAddr *     const p_dest,
                                 te_ETH_PROTO_TYPE          const p_ProtocolType,
                                 const ts_CMN_IOSP_BUFFER * const p_buff  );

extern te_CMN_FLAG_QUESTION ETH_DRV_IsSameMAC_ADDR ( const ts_ETH_MACAddr * const p_m1 ,
                                                     const ts_ETH_MACAddr * const p_m2 ) ;

#endif /* ETH_COMMON_H */
