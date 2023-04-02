/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_UDP_private.h"



/*---------------------------------------------------------------------------*/
/* NAME: ETH_DRV_CloseUDPPort()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE: Closes an UDP port*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/
void ETH_UDP_ClosePort( uint32_t                   const p_port,
                        te_ETH_UDP_PORT_Status *   const p_status )
{
   ts_ETH_UDP_RECEIVE_BUFF *  pt_buffPort;
   uint32_t                   v_i;

   *p_status = e_ETH_UDP_PORT_ALREADY_DONE ;

   for ( v_i = 0ul ; v_i < INTEG_ETH_UDP_OF_PORTS ; v_i ++)
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, table element's address is consistent with pointer type */
      pt_buffPort = &(v_ETH_UDP_ControlObj.s_RcvPort[ v_i ]) ;

      if ( pt_buffPort->s_PortNumber == p_port )
      {
         pt_buffPort->s_IP.u_IP = 0ul ;
         pt_buffPort->s_PortNumber = K_ETH_UDP_PORT_INVALID ;
         /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, it's used to initialize the pointer */
         pt_buffPort->s_BufReception = (int8_t*)NULL ;
      }
   }
}

