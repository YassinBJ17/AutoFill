/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : MAC ETH Init function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MAC_ETH_CFEX_public.h"
#include "driver/mailbox/MAC_ETH_HAL_public.h"
#include "driver/mailbox/MAC_ETH_REG_common.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */


/* ---------- provided operation bodies: ------------------------------------ */
void MAC_ETH_INIT( tu_CMN_RC * const p_return_code )
{
   /* Local Variable Declaration */
   const ts_MAC_ETH_CFEX_ELT * pt_conf ;
   uint32_t                    v_conf_ind;
   tu_MAC_ETH_TX_STATUS_REG    v_status_value;

   for( v_conf_ind = 0UL; v_conf_ind < c_MAC_ETH_CFEX_tab_SIZE; v_conf_ind++ )
   {
      /* Get Configuration descriptor */
      pt_conf = &(c_MAC_ETH_CFEX_CONFIGURATION_tab[v_conf_ind]);

      /*
       * Configure Source MAC addr Rx filtering
       */
      MAC_ETH_SET_MAC_SRC ( v_conf_ind , &pt_conf->s_mac_filtering_addr_src[0] );
      MAC_ETH_SET_MAC_SRC_MASK ( v_conf_ind , &pt_conf->s_mac_rx_filter_mask_addr_dst );

      /*
       * Configure Destination MAC addr Rx filtering
       */
      MAC_ETH_SET_MAC_DST ( v_conf_ind , &pt_conf->s_mac_filtering_addr_dst[0] );
      MAC_ETH_SET_MAC_DST_MASK ( v_conf_ind , &pt_conf->s_mac_rx_filter_mask_addr_dst );

      /*
       * Get Status MAC ETH tx
       */
      MAC_ETH_READ_TX_STATUS  ( v_conf_ind , &v_status_value);
   }

   p_return_code->u_r = 0;
}

/* ---------- internal operation bodies: ------------------------------------ */
