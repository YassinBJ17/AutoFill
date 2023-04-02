#ifndef MAC_INTERFACE_H
#define MAC_INTERFACE_H

#include "LIBMCP_Types.h"

#define ETH_ADDR_LEN 6

/* Adresse MAC */
#ifdef _DIAB_TOOL
#pragma pack(1,1,0)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
    uint8_t addr [ETH_ADDR_LEN];
} tMAC_addr;
#ifdef _DIAB_TOOL
#pragma pack(0,0,0)
#else
#pragma pack(pop)
#endif

typedef enum
{
   E_MAC_HEALTHY=1,
   E_MAC_LOSS_OF_LINK=2,
   E_MAC_IN_FAULT=3,
   E_MAC_UNKNOWN=4
} TE_ETHERNET_stat_mac_status;


typedef struct
{
   uint16_t MACIndex;
   uint8_t MACAddress[6];
   TE_ETHERNET_stat_mac_status MACstatus;
   uint32_t MACInOctets;
   uint32_t MACOutOctets;
   uint32_t MACInFrames;
   uint32_t MACOutFrames;
   //uint32_t MACDestAddrErrors;
   uint32_t MACAlignmentErrors;
   uint32_t MACCRCErrors;
   uint32_t MACFrameLengthErrors;
   uint32_t MACIntMACRxErrors;
   uint32_t MACInOverrun;
   uint32_t MACOutDiscards;
   //uint32_t MACUnknownType;
} TS_ETHERNET_stat_mac;

#endif
