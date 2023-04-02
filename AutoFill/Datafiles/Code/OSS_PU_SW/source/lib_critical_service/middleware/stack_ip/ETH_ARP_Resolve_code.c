/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ARP_public.h"
#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_ARP_private.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "libtools/time/LIB_TIME_public.h"

#define K_ETH_ARP_INVALID_ADDR 0x00



/*---------------------------------------------------------------------------*/
/* NAME: ETH_ARP_DoARP()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE: Resolve MAC address for specified IP address*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/
te_ETH_ARP_RESOL_Status ETH_ARP_Resolve( const tu_ETH_IPAddr * const p_AddressToResolve,
                                         ts_ETH_MACAddr      * const p_MacAddr )
{
   te_ETH_ARP_RESOL_Status        v_status;
   te_ETH_ARP_TABLE_Status        v_ARP_Status;
   ts_ETH_ARP_TableEntry *        pt_TableEntry;
   ts_ETH_MACAddr                 v_BroadCastAddr;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, no precision is lost */
   pt_TableEntry = ETH_ARP_SearchInTable (  p_AddressToResolve ) ;

   /* If no entry add a new one and perform a ARP Request */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: NULL is used for comparison */
   if (pt_TableEntry == NULL)
   {
      /* Build the ARP request packet*/
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is initialized with zeros */
      LIB_MEM_SET( (int8_t*) v_BroadCastAddr.s_val,
                   (int8_t) K_ETH_ARP_INVALID_ADDR,
                   (uint32_t) K_HW_ADDR_LEN);

      v_ARP_Status = ETH_ARP_AddARPEntry( p_AddressToResolve,
                                        &v_BroadCastAddr );

      if( v_ARP_Status == e_ETH_ARP_TABLE_OK )
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, no precision is lost */
         pt_TableEntry = ETH_ARP_SearchInTable (  p_AddressToResolve ) ;

         ETH_ARP_SendARP_Request( pt_TableEntry ,
                                  p_AddressToResolve ) ;

         v_status = e_ETH_ARP_RESOL_WAITING_REPONSE;
      }
      else
      {
         v_status = e_ETH_ARP_RESOL_TABLE_FULL ;
      }
   }
   else
   {

      switch (pt_TableEntry->s_ARPType  )
      {
         case e_ETH_ARP_REQUEST_IN_PROGRESS :
            /* Make sure the ARP system time is current*/
            LIBT_TIME_Update( & pt_TableEntry->s_timeoutChrono );

            if ( pt_TableEntry->s_timeoutChrono.s_ongoing < pt_TableEntry->s_timeoutChrono.s_end)
            {
               /* Still waiting ARP response*/
               v_status = e_ETH_ARP_RESOL_WAITING_REPONSE;
            }
            else
            {
               /* Timed out*/
               v_status = e_ETH_ARP_RESOL_RESPONSE_TIMEOUT;

               /* Allow a new ARP to start since this one is done*/
               pt_TableEntry->s_timeoutChrono.s_ongoing = 0ul ;
               pt_TableEntry->s_timeoutChrono.s_end = INTEG_ETH_ARP_ARP_REQUEST_TIME_BEFORE_RELAUNCH ;
               pt_TableEntry->s_ARPType = e_ETH_ARP_RESPONSE_TIMEOUT ;
            }
            break;

         case e_ETH_ARP_RESPONSE_TIMEOUT :
            /* Make sure the ARP system time is current*/
            LIBT_TIME_Update( & pt_TableEntry->s_timeoutChrono );

            if ( pt_TableEntry->s_timeoutChrono.s_ongoing < pt_TableEntry->s_timeoutChrono.s_end)
            {
               /* Still waiting ARP response*/
               v_status = e_ETH_ARP_RESOL_RESPONSE_TIMEOUT;
            }
            else
            {
               ETH_ARP_SendARP_Request( pt_TableEntry ,
                                        p_AddressToResolve ) ;
               v_status = e_ETH_ARP_RESOL_WAITING_REPONSE;
            }
            break;

         case e_ETH_ARP_NOT_USED:
         case e_ETH_ARP_SET:
         case e_ETH_ARP_REALLOCATED:
         default:
            /* Found the IP address in ARP table so update output parameter and return OK*/
            ETH_COPY_MAC_ADD( p_MacAddr,
                              & pt_TableEntry->s_PhysicalAddress );

            v_status = e_ETH_ARP_RESOL_OK;
            break;
      }
   }

   return (v_status);
}


