/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_private.h"

#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_ICMP_common.h"

#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/ethernet/ETH_porting.h"
#include "middleware/accom/accom_public.h"

/*---------------------------------------------------------------------------*/
/* NAME: ETH_DRV_Init()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  initialize the appropriate ethernet driver as follows:*/
/*    1. initialize the global state based on board type*/
/*    2. call the chip specific ethernet init routine*/
/*    3. return status of initialization attempt*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/
void ETH_INIT ( tu_CMN_RC * const p_rc )
{
   tu_accom_ch_bit_fault_word accom_word;

   /* Initialize device specific data structure pointer in main control object*/
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> cast is safe, array is initialized with zeros */
   LIB_MEM_SET ( (int8_t *) &v_ETH_DRV_ControlETH ,
                 (int8_t)0x00 ,
   /* >RELAX<SYNCHRONe_C_Code_10.7> cast is safe, size_t fits in uint32_t */
                 (uint32_t)sizeof(ts_ETH_CONTROL) ) ;

   /* Initialize the global Ethernet control struct with board specific data*/
   /* Identify channel */
   accom_word = accom_ch_cbit();
   if( FALSE == accom_word.u_bit.s_ch_id )
   {
      v_ETH_DRV_EtherOwnAddr.s_IpAddress.u_IP = ETH_CFEX_CDRAEtherAddr.u_IP ;
   }
   else
   {
      v_ETH_DRV_EtherOwnAddr.s_IpAddress.u_IP = ETH_CFEX_CDRBEtherAddr.u_IP ;
   }

   /* Connect the driver to the com layer  and initialize the device*/
   p_rc->u_r = 0ul ;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> cast is safe, array is copied byte to byte */
   hal_get_mac_pt( (ts_ETH_MACAddr * const) &v_ETH_DRV_EtherOwnAddr.s_HwAddress );

   if ( p_rc->u_r != 0ul )
   {
      v_ETH_DRV_ControlETH.s_DriverStatus = e_ETH_DRV_NOT_INITIALIZED ;
   }
   else
   {
      hal_establish_connection_pt( p_rc );
      if ( p_rc->u_r != 0ul )
      {
         v_ETH_DRV_ControlETH.s_DriverStatus = e_ETH_DRV_NO_LINK ;
      }
   }

   ETH_IP_Init ( ) ;

   ETH_ARP_INIT ( ) ;

   ETH_UDP_Init ( ) ;

   ETH_ICMP_Init ( ) ;
}

