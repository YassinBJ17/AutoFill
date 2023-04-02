/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_private.h"
#include "middleware/ethernet/ETH_porting.h"

void ETH_ESTABLISH_CONNECTION( te_CMN_FLAG_ACTIVATION * const p_done )
{
   tu_CMN_RC v_rc ;

   v_rc.u_r = 0ul ;

   hal_establish_connection_pt( &v_rc );

   if (v_rc.u_r == 0ul )
   {
      *p_done = e_CMN_FLAG_ACTIVATE ;
      v_ETH_DRV_ControlETH.s_DriverStatus = e_ETH_DRV_READY ;
   }
   else
   {
      v_ETH_DRV_ControlETH.s_DriverStatus = e_ETH_DRV_NO_LINK ;
      *p_done = e_CMN_FLAG_NOT_ACTIVATE ;
   }
}

