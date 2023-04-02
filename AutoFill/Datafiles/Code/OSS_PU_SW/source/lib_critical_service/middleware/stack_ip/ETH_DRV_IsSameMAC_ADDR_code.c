/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_common.h"

te_CMN_FLAG_QUESTION ETH_DRV_IsSameMAC_ADDR ( const ts_ETH_MACAddr * const p_m1 ,
                                              const ts_ETH_MACAddr * const p_m2 )
{
   te_CMN_FLAG_QUESTION v_same ;
   uint32_t v_i ;

   v_same = e_CMN_FLAG_YES ;
   for ( v_i = 0ul ; v_i < (uint32_t)K_HW_ADDR_LEN ; v_i++ )
   {
      if ( p_m1->s_val[ v_i ] != p_m2->s_val[ v_i ] )
      {
         v_same = e_CMN_FLAG_NO ;
      }
   }

   return ( v_same ) ;
}
