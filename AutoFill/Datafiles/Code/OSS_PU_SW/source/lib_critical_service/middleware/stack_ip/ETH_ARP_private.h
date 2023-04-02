/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_ARP_PRIVATE_H
#define ETH_ARP_PRIVATE_H

#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_INTEG_common.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"
#include "libtools/time/LIB_TIME_public.h"

/*---------------------------------------------------------------------------*/
/*-- Definitions*/
/*---------------------------------------------------------------------------*/

/* Hardware Address Format definition*/
#define K_ETH_ARP_ETHER_HW_ADDR    (1)    /* ethernet hardware address  RFC - 1700*/

/* ARP Operation definitions*/
#define K_ETH_ARP_REQUEST          (1)    /* Resolve address request*/
#define K_ETH_ARP_RESPONSE         (2)    /* Response to previous request*/


/*---------------------------------------------------------------------------*/
/*-- Typedefs*/
/*---------------------------------------------------------------------------*/




typedef struct
{
   int32_t     s_drop ;
   int32_t     s_ARPnok ;
   int32_t     s_ARPhandled ;
}ts_ETH_ARP_STATS ;

typedef struct
{
   ts_ETH_ARP_Packet s_TxBuf;
   ts_ETH_ARP_TableEntry s_Table[INTEG_ETH_ARP_MAX_ARP_ENTRIES];
   ts_ETH_ARP_STATS s_ARPstats;
} ts_ETH_ARP_CONTROL;


/*---------------------------------------------------------------------------*/
/*-- Data*/
/*---------------------------------------------------------------------------*/

/* table of ARP (IP to MAC address) entries*/
extern ts_ETH_ARP_CONTROL v_ETH_ARP_ControlObj ;

/*---------------------------------------------------------------------------*/
/*-- Local Functions/Procedures*/
/*---------------------------------------------------------------------------*/

extern void ETH_ARP_BuildARPPacket( ts_ETH_ARP_Packet *    const p_packet ,
                                    uint16_t               const p_ARPCode ,
                                    const ts_ETH_MACAddr * const p_DestAddr ,
                                    const tu_ETH_IPAddr *  const p_DestIP  );

extern void ETH_ARP_HandleARPRequest( const ts_ETH_ARP_Packet * const p_ARPRequest);

extern void ETH_ARP_HandleARPResponse( const ts_ETH_ARP_Packet * const p_ARPResponse);

extern void ETH_ARP_SendARP_Request( ts_ETH_ARP_TableEntry * const pt_TableEntry,
                                     const tu_ETH_IPAddr *   const p_destIP );



#endif /* ETH_ARP_PRIVATE_H */
