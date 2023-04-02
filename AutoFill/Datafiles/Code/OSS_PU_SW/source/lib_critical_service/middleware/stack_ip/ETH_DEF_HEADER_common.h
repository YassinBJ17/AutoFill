/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_DEF_HEADER_COMMON_H
#define ETH_DEF_HEADER_COMMON_H

#include "type/common_type.h"

#include "middleware/stack_ip/ETH_public.h"


/**/
/*         Ethernet II Protocol s_Header Format*/
/**/
/*   0               1               2               3               */
/*   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |                 Destination MAC Address[0..3]                 |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   | Destination MAC Address[4..5] |   Source MAC Address[0..1]    |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |                    Source MAC Address[2..5]                   |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |         Protocol Type         |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/**/
/* Ethernet s_Header Type Definition*/
typedef PACKED_U08 struct
{
   ts_ETH_MACAddr       s_DestinationHost;
   ts_ETH_MACAddr       s_SourceHost;
   uint16_t             s_ProtocolType;
}
ts_ETH_EthernetHeader;

/**/
/*          Internet Protocol(IP) s_Header Format*/
/**/
/*   0               1               2               3               */
/*   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |Version|  IHL  |Type of Service|          Total Length         |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |         Identification        |Flags|      Fragment Offset    |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |  Time to Live |    Protocol   |         s_Header Checksum       |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |                         Source Address                        |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |                      Destination Address                      |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |                    Options                    |    Padding    |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/**/

/* IP header structure type definition*/

typedef PACKED_U08 struct
{
   /* >RELAX<SYNCHRONe_C_Code_7.2>: Literal are used to define 2 bitfield of 4 bits */
   uint8_t        s_IP_V   : 4,          /* Version*/
                  s_IP_IHL : 4;          /* Internet s_Header Length*/
   uint8_t        s_IP_TypeOfService;
   uint16_t       s_IP_TotalLength;      /* Total Length of packet*/
   uint16_t       s_IP_Id;               /* Identification*/
   uint16_t       s_IP_Flags_FragOffset; /* Flags[16..18], FragOff[19..31]*/
   uint8_t        s_IP_TimeToLive;       /* time to live in sec */
   uint8_t        s_IP_Protocol;
   uint16_t       s_IP_Checksum;
   tu_ETH_IPAddr  s_SourceAddress;
   tu_ETH_IPAddr  s_DestinationAddress;
}
ts_ETH_IP_Header;

typedef PACKED_U08  struct
{
   ts_ETH_EthernetHeader s_IP_eth;
   ts_ETH_IP_Header      s_IP_ip ;
} ts_ETH_IP_PacketHeader ;

/**/
/*      Internet Control Message Protocol(ICMP) Packet s_Header Formats*/
/**/
/*                      Destination Unreachable Message*/
/**/
/*    0               1               2               3               */
/*    0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |     Type      |     Code      |          Checksum             |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |                             unused                            |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |      Internet s_Header + 64 bits of Original Data Datagram      |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/**/
/**/
/*                            Time Exceeded Message*/
/**/
/*    0               1               2               3               */
/*    0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |     Type      |     Code      |          Checksum             |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |                             unused                            |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |      Internet s_Header + 64 bits of Original Data Datagram      |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/**/
/**/
/*                         Parameter Problem Message*/
/**/
/*    0               1               2               3               */
/*    0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |     Type      |     Code      |          Checksum             |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |    Pointer    |                   unused                      |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*    |      Internet s_Header + 64 bits of Original Data Datagram      |*/
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/**/
/**/
/*                          Source Quench Message*/
/**/
/*    0               1               2               3               */
/*    0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*   |     Type      |     Code      |          Checksum             |*/
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*   |                             unused                            |*/
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*   |      Internet s_Header + 64 bits of Original Data Datagram      |*/
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/**/
/**/
/*                            Redirect Message*/
/**/
/*    0               1               2               3               */
/*    0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*   |     Type      |     Code      |          Checksum             |*/
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*   |                 Gateway Internet Address                      |*/
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/*   |      Internet s_Header + 64 bits of Original Data Datagram      |*/
/*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+*/
/**/
/**/
/*                Echo Reply or Request Message s_Header Format*/
/**/
/*   0               1               2               3               */
/*   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |     Type      |     Code      |         Checksum              |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |         s_Identifier            |         Sequence Number       |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   | Data ...                                                      |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/**/

/* ICMP s_Header structure type definition*/
typedef PACKED_U08 struct
{
   uint8_t    s_Type; /* Type of service*/
   uint8_t    s_Code;
   uint16_t   s_Checksum;
}
ts_ETH_ICMP_Header;

typedef PACKED_U08 struct
{
   ts_ETH_EthernetHeader         s_ICMP_EtherHeader;
   ts_ETH_IP_Header              s_ICMP_IP_Header;
   ts_ETH_ICMP_Header            s_ICMP_ICMPHeader;
}ts_ETH_ICMP_Packet;

/* Packet structure used for ICMP Echo request/reply message*/
typedef PACKED_U08 struct
{
   ts_ETH_EthernetHeader         s_ICMPEcho_EtherHeader;
   ts_ETH_IP_Header              s_ICMPEcho_IP_Header;
   ts_ETH_ICMP_Header            s_ICMPEcho_ICMPHeader;
   uint16_t                      s_ICMPEcho_Identifier;
   uint16_t                      s_ICMPEcho_SequenceNo;
}
ts_ETH_ICMP_EchoPacket;


/**/
/**/
/*    Address Resolution Protocol(ARP) s_Header Format*/
/**/
/*   0               1               2               3               */
/*   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |    Hardware Address Format    |    Protocol Address Format    |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   | HW Addr Length| Proto Addr Len|          ARP Operation        |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/**/
/**/

/* ARP s_Header structure type definition*/
typedef PACKED_U08 struct
{
   uint16_t          s_ARP_HwAddrFmt;      /* format of hardware address*/
   uint16_t          s_ARP_ProtoAddrFmt;   /* format of protocol address*/
   uint8_t           s_ARP_HwAddrLen;      /* length of hardware address*/
   uint8_t           s_ARP_ProtoAddrLen;   /* length of protocol address*/
   uint16_t          s_ARP_Opcode;         /* (I.e. Request or Reply)*/
}
ts_ETH_ARP_Header;

/**/
/* ARP packets are variable in size; the ARP_Header_T structure defines*/
/* the fixed-length portion. Protocol type values are the same as*/
/* those for 10/100 Mb/s Ethernet. It is followed by the variable-sized*/
/* fields s_ARP_SenderHwAddr, s_ARP_SenderProtoAddr, s_ARP_TargetHwAddr and*/
/* s_ARP_TargetProtoAddr in that order, according to the lengths specified.*/
/**/
/*        Ethernet II ARP Packet Format*/
/*   0               1               2               3               */
/*   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |                       ARP Packet s_Header                       |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |                  Sender MAC Address[0..3]                     |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |   Sender MAC Address[4..5]    |  Sender Protocol Address (IP) |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |          Target MAC Address[0..3]           |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |   Target MAC Address[4..5]    |  Target Protocol Address (IP) |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/**/
typedef PACKED_U08 struct
{
   ts_ETH_EthernetHeader  s_ARP_EtherHeader;
   ts_ETH_ARP_Header      s_ARP_Header;
   ts_ETH_MACAddr         s_ARP_SenderHwAddr;    /* sender hardware address*/
   tu_ETH_IPAddr          s_ARP_SenderProtoAddr; /* sender protocol address*/
   ts_ETH_MACAddr         s_ARP_TargetHwAddr;    /* target hardware address*/
   tu_ETH_IPAddr          s_ARP_TargetProtoAddr; /* target protocol address*/
}
ts_ETH_ARP_Packet;

/**/
/**/
/*       User Datagram Protocol(UDP) s_Header Format*/
/**/
/*   0               1               2               3               */
/*   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 */
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |          Source Port          |       Destination Port        |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/*   |             Length            |           Checksum            |*/
/*   +-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|-+-+-+-+-+-+-+-|*/
/**/

/* UDP s_Header structure type definition*/
typedef PACKED_U08 struct
{
   uint16_t s_UDP_SourcePort;
   uint16_t s_UDP_DestinationPort;
   uint16_t s_UDP_Length;
   uint16_t s_UDP_Checksum;
}
ts_ETH_UDP_Header;

typedef PACKED_U08 struct
{
   ts_ETH_EthernetHeader  s_MAC_Header;
   ts_ETH_IP_Header       s_IP_Header;
   ts_ETH_UDP_Header      s_UDP_Header;
}
ts_ETH_UDP_PacketHeader;




#endif /* ETH_DEF_HEADER_COMMON_H */
