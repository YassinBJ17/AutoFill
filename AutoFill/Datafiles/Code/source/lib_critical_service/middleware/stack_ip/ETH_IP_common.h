/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_IP_COMMON_H
#define ETH_IP_COMMON_H

/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#include "type/common_type.h"
#include "middleware/stack_ip/ETH_public.h"

/* ---------- provided define constants --------------------------------------- */
#define K_ETH_IP_FCS_SIZE             (4ul)     /* Frame Control State : checksum of the frame */

/* ---------- provided types: ----------------------------------------------- */
/* IP Protocol field definitions from RFC 1700*/
typedef enum
{
   e_ETH_IP_PROTO_ICMP = 1 , /* Internet Control Message Protocol*/
   e_ETH_IP_PROTO_UDP = 17 /* User Datagram Protocol*/
} te_ETH_IP_PROTO;


/* ---------- provided variables: ------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */

extern void ETH_IP_Manage( const ts_CMN_IOSP_BUFFER * const p_Data,
                           ts_CMN_IOSP_BUFFER *       const p_DataReassembly);

/* p_header = could be null, in this case the Ethernet header are store in p_data. */
extern uint32_t ETH_IP_SEND ( const ts_ETH_EthernetAddress * const p_dest ,
                          te_ETH_IP_PROTO                const p_protocolType ,
                          const ts_CMN_IOSP_BUFFER *     const p_header,
                          const ts_CMN_IOSP_BUFFER *     const p_data ) ;


extern uint16_t ETH_IP_InCheckSum( uint16_t *p_Data,
                                   uint32_t p_Length );

extern void ETH_IP_Init(void) ;

extern void ETH_IP_HandleEmission(void) ;

#endif /* ETH_IP_COMMON_H */
