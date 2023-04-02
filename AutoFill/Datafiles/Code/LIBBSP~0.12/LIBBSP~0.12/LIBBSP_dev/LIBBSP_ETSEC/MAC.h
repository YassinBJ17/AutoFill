#ifndef MAC_H
#define MAC_H

#include "LIBMCP_Types.h"
#include "MAC_interface.h"

#define ETH_HWADDR_LEN 6

/* Type de trames ethernet supportees */
#define ETHTYPE_IPV4 ((uint16_t)0x0800)
#define ETHTYPE_ARP  ((uint16_t)0x0806)

/* Entete MAC */
#ifdef _DIAB_TOOL
#pragma pack(1,1,0)
#else
#pragma pack(push, 1)
#endif
typedef	struct
{
  tMAC_addr des;
  tMAC_addr src;
  uint16_t    type;
} tMAC_header;

/* Trame ethernet */
typedef struct
{
    tMAC_header macheader;
    void        *payload;
} tETH_frame;
#ifdef _DIAB_TOOL
#pragma pack(0,0,0)
#else
#pragma pack(pop)
#endif

#endif
