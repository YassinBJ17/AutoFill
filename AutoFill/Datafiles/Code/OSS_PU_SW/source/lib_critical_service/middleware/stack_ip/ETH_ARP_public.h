/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_ARP_PUBLIC_H
#define ETH_ARP_PUBLIC_H

#include "middleware/stack_ip/ETH_public.h"


/* ---------- provided define constants --------------------------------------- */

/* ---------- provided types -------------------------------------------------- */

/* */
typedef enum
{
   e_ETH_ARP_RESOL_WAITING_REPONSE = 1,
   e_ETH_ARP_RESOL_TABLE_FULL = 2,
   e_ETH_ARP_RESOL_RESPONSE_TIMEOUT = 3,
   e_ETH_ARP_RESOL_OK = 4
} te_ETH_ARP_RESOL_Status;

/* ---------- provided constants and data  ------------------------------------ */

/* ---------- provided function ----------------------------------------------- */

/* */
extern te_ETH_ARP_RESOL_Status ETH_ARP_Resolve( const tu_ETH_IPAddr * const p_AddressToResolve,
                                                ts_ETH_MACAddr      * const p_MacAddr);

#endif /* ETH_ARP_PUBLIC_H */
