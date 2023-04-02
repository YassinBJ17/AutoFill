/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */
#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_ARP_private.h"


ts_ETH_ARP_TableEntry * ETH_ARP_SearchInTable( const tu_ETH_IPAddr * const p_AddressToResolve )
{
   ts_ETH_ARP_TableEntry * pt_TableEntry;
   uint32_t v_i;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, NULL is used for initialization */
   pt_TableEntry = (ts_ETH_ARP_TableEntry *)NULL;

   /* searh into table  */
   for ( v_i = 0ul ; v_i < INTEG_ETH_ARP_MAX_ARP_ENTRIES ; v_i ++ )
   {
      if ( v_ETH_ARP_ControlObj.s_Table[ v_i ].s_IP_Address.u_IP == p_AddressToResolve->u_IP )
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, address of an element is indeed (ts_ETH_ARP_TableEntry*) */
         pt_TableEntry = & v_ETH_ARP_ControlObj.s_Table[ v_i ] ;
      }
   }

   return (pt_TableEntry) ;
}
