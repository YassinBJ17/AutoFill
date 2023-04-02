/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_ARP_private.h"

/*---------------------------------------------------------------------------*/
/* NAME: ETH_ARP_HandleARPResponse()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  This function is called to handle ARP responses recieved by the*/
/* calling interface.*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: Static ARP entries may be deleted if the ARP*/
/* table is full since all ARP responses are added to the ARP table even*/
/* if they were not requested.*/
/*---------------------------------------------------------------------------*/
void ETH_ARP_HandleARPResponse( const ts_ETH_ARP_Packet * const p_ARPResponse)
{
   ts_ETH_ARP_TableEntry *    pt_TableEntry ;
   tu_ETH_IPAddr *            pt_MyIPAddPtr;
   tu_ETH_IPAddr              v_TargetIPAddress;
   tu_ETH_IPAddr              v_SenderIPAddress;
   te_ETH_ARP_TABLE_Status    v_ARP_Status;

   v_TargetIPAddress.u_IP = p_ARPResponse->s_ARP_TargetProtoAddr.u_IP ;
   v_SenderIPAddress.u_IP = p_ARPResponse->s_ARP_SenderProtoAddr.u_IP ;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: address of v_SenderIPAddress is indeed (tu_ETH_IPAddr *) */
   pt_TableEntry = ETH_ARP_SearchInTable( &v_SenderIPAddress ) ;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: address is indeed (tu_ETH_IPAddr *) */
   pt_MyIPAddPtr = & v_ETH_DRV_EtherOwnAddr.s_IpAddress;

   /*  */
   if  (v_TargetIPAddress.u_IP == pt_MyIPAddPtr->u_IP)   /* is the ARP response is for me*/
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: NULL is used for comparison */
      if (  (pt_TableEntry != NULL) && /* is the IP Address has been request by me */
               (pt_TableEntry->s_ARPType == e_ETH_ARP_REQUEST_IN_PROGRESS) ) /* is the request was sent */
      {
         v_ETH_ARP_ControlObj.s_ARPstats.s_ARPhandled ++ ;
         /* update the new entry*/
         v_ARP_Status = ETH_ARP_AddARPEntry( &v_SenderIPAddress,
                              &p_ARPResponse->s_ARP_SenderHwAddr );
         if ( v_ARP_Status == e_ETH_ARP_TABLE_OK )
         {
            v_ETH_ARP_ControlObj.s_ARPstats.s_ARPhandled ++ ;
         }
         else
         {
            v_ETH_ARP_ControlObj.s_ARPstats.s_drop ++ ;
         }
      }
      else
      {
         v_ETH_ARP_ControlObj.s_ARPstats.s_ARPnok ++ ;
      }
   }

}
