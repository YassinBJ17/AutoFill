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
/* NAME: ETH_ARP_HandleARPRequest()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  This function is called to handle an ARP request packet. If*/
/* the ARP request is for the interface that recieved the request an ARP entry*/
/* is added to the ARP table and an ARP response is sent to the originator.*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/
void ETH_ARP_HandleARPRequest (const ts_ETH_ARP_Packet * const p_ARPRequest )
{
   te_ETH_ARP_TABLE_Status v_ARP_Status;
   tu_ETH_IPAddr           v_IPAddress ;
   tu_ETH_IPAddr *         pt_MyIPAddPtr ;
   ts_CMN_IOSP_BUFFER      v_buff ;

   /* If the request is not for us just ignore it*/
   v_IPAddress.u_IP = p_ARPRequest->s_ARP_TargetProtoAddr.u_IP ;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: address of tu_ETH_IPAddr is indeed (tu_ETH_IPAddr*) */
   pt_MyIPAddPtr = &v_ETH_DRV_EtherOwnAddr.s_IpAddress ;

   if ( v_IPAddress.u_IP == pt_MyIPAddPtr->u_IP )
   {
      v_ETH_ARP_ControlObj.s_ARPstats.s_ARPhandled ++ ;
      /* Add the sender to the ARP table*/
      v_IPAddress.u_IP = p_ARPRequest->s_ARP_SenderProtoAddr.u_IP ;

      v_ARP_Status = ETH_ARP_AddARPEntry ( &v_IPAddress ,
                                           &p_ARPRequest->s_ARP_SenderHwAddr ) ;

      if ( v_ARP_Status == e_ETH_ARP_TABLE_OK )
      {
         ETH_ARP_BuildARPPacket ( &v_ETH_ARP_ControlObj.s_TxBuf ,
                                  (const uint16_t)K_ETH_ARP_RESPONSE ,
                                  &p_ARPRequest->s_ARP_SenderHwAddr ,
                                  &v_IPAddress ) ;

         /* Send the ARP response*/
         /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: this cast is needed to handle txBuf as bytes */
         v_buff.s_buffer = (int8_t *) &v_ETH_ARP_ControlObj.s_TxBuf ;
         /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: size_t fits in uint32_t */
         v_buff.s_buffer_size = (uint32_t)sizeof(ts_ETH_ARP_Packet) ;

         ETH_DRV_SEND_FRAME ( &p_ARPRequest->s_ARP_SenderHwAddr ,
                              e_ETH_PROTO_ARP,
                              &v_buff ) ;
      }
      else
      {
         v_ETH_ARP_ControlObj.s_ARPstats.s_drop ++ ;
      }

   }
}
