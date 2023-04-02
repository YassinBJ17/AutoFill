/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */
#include "middleware/stack_ip/ETH_ARP_private.h"
#include "middleware/stack_ip/ETH_common.h"

void ETH_ARP_BuildARPPacket( ts_ETH_ARP_Packet *      const p_packet,
                             uint16_t                 const p_ARPCode ,
                             const ts_ETH_MACAddr *   const p_DestAddr,
                             const tu_ETH_IPAddr *    const p_DestIP )
{
   const tu_ETH_IPAddr  * c_MyIPAdd_pt;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: address of tu_ETH_IPAddr is indeed (tu_ETH_IPAddr*) */
   c_MyIPAdd_pt = &v_ETH_DRV_EtherOwnAddr.s_IpAddress;

   /* Build the ARP header */
   p_packet->s_ARP_Header.s_ARP_HwAddrFmt    = (uint16_t)K_ETH_ARP_ETHER_HW_ADDR;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: the enum value (0x0800) fits in an uint16_t */
   p_packet->s_ARP_Header.s_ARP_ProtoAddrFmt = (uint16_t)e_ETH_PROTO_IP;
   p_packet->s_ARP_Header.s_ARP_HwAddrLen    = (uint8_t)K_HW_ADDR_LEN;
   p_packet->s_ARP_Header.s_ARP_ProtoAddrLen = (uint8_t)K_PROTOCOL_ADDR_LEN;
   p_packet->s_ARP_Header.s_ARP_Opcode       = p_ARPCode;

   /* Build the ARP Data */
   /* sender */
   ETH_COPY_MAC_ADD( &p_packet->s_ARP_SenderHwAddr,
                     &v_ETH_DRV_EtherOwnAddr.s_HwAddress );

   p_packet->s_ARP_SenderProtoAddr.u_IP = c_MyIPAdd_pt->u_IP  ;

   /* target */
   ETH_COPY_MAC_ADD( &p_packet->s_ARP_TargetHwAddr,
                     p_DestAddr );

   p_packet->s_ARP_TargetProtoAddr.u_IP = p_DestIP->u_IP;

}
