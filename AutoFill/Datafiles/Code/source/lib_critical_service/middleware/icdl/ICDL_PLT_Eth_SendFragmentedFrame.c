/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_PLT_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_IP_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void ICDL_PLT_Eth_SendFragmentedFrame(void)
{
   uint32_t v_ChannelId;
   boolean_t v_ChanneisFree;

   if ( v_ETH_IP_ControlObj.s_TxFragment.s_nbLeftToSent != 0 )
   {
      /*
      * Sending IP fragments of an UDP message
      */
      ETH_DRV_HandleEmission();
   }
   else
   {
      /*
       * Free channel at the end of a transmission
       */
      v_ChanneisFree = ICDL_LG_GetChannelToFree (&v_ChannelId);

      if ( v_ChanneisFree == TRUE )
      {
         ICDL_LG_InitializeChannel( v_ChannelId );
      }
         p_ElectedFFInTransmission = NULL;
   }
}

