/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_ARP_COMMON_H
#define ETH_ARP_COMMON_H

/*---------------------------------------------------------------------------*/
/*-- Includes*/
/*---------------------------------------------------------------------------*/

#include "middleware/stack_ip/ETH_public.h"
#include "libtools/time/LIB_TIME_public.h"
#include "type/common_type.h"

/*---------------------------------------------------------------------------*/
/*-- Definitions*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*-- Typedefs*/
/*---------------------------------------------------------------------------*/
typedef enum
{
   e_ETH_ARP_TABLE_FULL,
   e_ETH_ARP_TABLE_OK
} te_ETH_ARP_TABLE_Status ;

typedef enum
{
   e_ETH_ARP_NOT_USED = 0,
   e_ETH_ARP_REQUEST_IN_PROGRESS = 1,
   e_ETH_ARP_RESPONSE_TIMEOUT = 2,
   e_ETH_ARP_SET =  3,
   e_ETH_ARP_REALLOCATED = 4

} te_ETH_ARP_ENTRY_Status ;

typedef struct
{
   tu_ETH_IPAddr               s_IP_Address;
   ts_ETH_MACAddr              s_PhysicalAddress;
   ts_LIB_TIME_CHRONO          s_timeoutChrono;
   te_ETH_ARP_ENTRY_Status     s_ARPType;
} ts_ETH_ARP_TableEntry;


/*---------------------------------------------------------------------------*/
/*-- Constants*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*-- Data*/
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*-- Function prototypes*/
/*---------------------------------------------------------------------------*/


extern te_ETH_ARP_TABLE_Status ETH_ARP_AddARPEntry ( const tu_ETH_IPAddr* const p_IPAddress ,
                                                     const ts_ETH_MACAddr* const p_MACAddress );

extern void ETH_ARP_INIT(void);

extern void ETH_ARP_OnRecv(const ts_CMN_IOSP_BUFFER * const p_Data) ;


extern ts_ETH_ARP_TableEntry * ETH_ARP_SearchInTable(  const tu_ETH_IPAddr * const p_AddressToResolve);


#endif /* ETH_ARP_COMMON_H */



