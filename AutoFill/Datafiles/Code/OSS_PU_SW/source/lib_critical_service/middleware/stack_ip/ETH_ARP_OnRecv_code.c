/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_ARP_private.h"

void ETH_ARP_OnRecv(const ts_CMN_IOSP_BUFFER * const p_Data)
{
   const ts_ETH_ARP_Packet* c_ARP_Pckt_pt;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, size_t fits in uint32_t */
   if( p_Data->s_buffer_size >= (uint32_t)sizeof (ts_ETH_ARP_Packet) )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: this cast is needed because s_buffer contains bytes */
      c_ARP_Pckt_pt = (const ts_ETH_ARP_Packet*)p_Data->s_buffer;
      if (c_ARP_Pckt_pt->s_ARP_Header.s_ARP_Opcode == (uint16_t)K_ETH_ARP_REQUEST)
      {
         ETH_ARP_HandleARPRequest( c_ARP_Pckt_pt );
      }
      else
      {
         if (c_ARP_Pckt_pt->s_ARP_Header.s_ARP_Opcode == (uint16_t)K_ETH_ARP_RESPONSE)
         {
            ETH_ARP_HandleARPResponse( c_ARP_Pckt_pt );
         }
         else
         {
            v_ETH_ARP_ControlObj.s_ARPstats.s_ARPnok ++;
         }
      }
   }
   else
   {
      v_ETH_ARP_ControlObj.s_ARPstats.s_ARPnok ++;
   }
}
