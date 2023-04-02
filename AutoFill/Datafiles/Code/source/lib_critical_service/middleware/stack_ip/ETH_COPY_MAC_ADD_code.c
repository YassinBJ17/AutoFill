/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_public.h"


void ETH_COPY_MAC_ADD( ts_ETH_MACAddr *       const p_dst,
                       const ts_ETH_MACAddr * const p_src)
{
   uint32_t v_i ;

   for ( v_i = 0ul ; v_i < (uint32_t)K_HW_ADDR_LEN; v_i ++)
   {
      p_dst->s_val[ v_i ] = p_src->s_val[ v_i ];
   }
}
