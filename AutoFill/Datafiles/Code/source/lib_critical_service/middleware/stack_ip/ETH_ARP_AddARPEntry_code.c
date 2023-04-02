/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_ARP_private.h"


/*---------------------------------------------------------------------------*/
/* NAME: ETH_ARP_AddARPEntry()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  This function adds a IP/MAC address pair with an entry type*/
/* and timeout  value to the ARP table.*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: number of ARP entries is limited by MAX_ARP_ENTRIES*/
/*---------------------------------------------------------------------------*/
te_ETH_ARP_TABLE_Status ETH_ARP_AddARPEntry ( const tu_ETH_IPAddr* const p_IPAddress ,
                                              const ts_ETH_MACAddr* const p_MACAddress )
{
   te_ETH_ARP_TABLE_Status v_Status ;
   uint32_t                v_i ;
   te_CMN_FLAG_FOUND       v_IPExists ;

   v_IPExists = e_CMN_FLAG_NOT_FOUND ;
   v_i = 0ul ;

   /* Search for an old entry that needs to be updated*/
   while ( ( v_IPExists == e_CMN_FLAG_NOT_FOUND ) &&
            ( v_i < INTEG_ETH_ARP_MAX_ARP_ENTRIES ) &&
            ( v_ETH_ARP_ControlObj.s_Table[ v_i ].s_ARPType != e_ETH_ARP_NOT_USED ) )
   {
      if ( v_ETH_ARP_ControlObj.s_Table[ v_i ].s_IP_Address.u_IP == p_IPAddress->u_IP )
      {
         v_IPExists = e_CMN_FLAG_FOUND ;
      }
      else
      {
         v_i++ ;
      }
   }
   /* If there was no previous entry add it at the end of the table*/
   if ( v_IPExists == e_CMN_FLAG_FOUND )
   {
      /* An entry in the ARP table stays unmodified until next Shutdown*/
      v_Status = e_ETH_ARP_TABLE_OK ;
      if ( v_ETH_ARP_ControlObj.s_Table[ v_i ].s_ARPType == e_ETH_ARP_SET )
      {
         v_ETH_ARP_ControlObj.s_Table[ v_i ].s_ARPType = e_ETH_ARP_REALLOCATED ;
      }
      else
      {
         v_ETH_ARP_ControlObj.s_Table[ v_i ].s_ARPType = e_ETH_ARP_SET ;
      }
      ETH_COPY_MAC_ADD ( & ( v_ETH_ARP_ControlObj.s_Table[ v_i ].s_PhysicalAddress ) ,
                         p_MACAddress ) ;
   }
   else
   {
      if ( v_i < INTEG_ETH_ARP_MAX_ARP_ENTRIES )
      {
         v_ETH_ARP_ControlObj.s_Table[ v_i ].s_IP_Address.u_IP = p_IPAddress->u_IP ;

         ETH_COPY_MAC_ADD ( & ( v_ETH_ARP_ControlObj.s_Table[ v_i ].s_PhysicalAddress ) ,
                            p_MACAddress ) ;

         v_ETH_ARP_ControlObj.s_Table[ v_i ].s_ARPType = e_ETH_ARP_SET ;

         v_Status = e_ETH_ARP_TABLE_OK ;
      }
      else
      {
         /* Table full*/
         v_Status = e_ETH_ARP_TABLE_FULL ;
      }
   }

   return ( v_Status ) ;
}
