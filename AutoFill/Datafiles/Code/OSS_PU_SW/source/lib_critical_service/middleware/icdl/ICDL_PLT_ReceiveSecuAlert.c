/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_PLT_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/icdl/ICDL_LG_public.h"
#include "middleware/stack_ip/ETH_IP_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- provided define constants: ------------------------------------ */
#define K_SECU_ALERT_ACK_CMD_UDP_PORTS_SRC  49200
#define K_SECU_ALERT_ACK_CMD_UDP_PORTS_DST  49200


/* ---------- provided operation bodies: ------------------------------------ */
boolean_t ICDL_PLT_ReceiveSecuAlert (void)
{
   ts_DRV_COM_MNT_ETH_RX l_eth_rx;
   uint8_t buffer[64];
   boolean_t status = FALSE;

   l_eth_rx.LCH_CTRL_RX_DATA                  = &(buffer[0]);
   l_eth_rx.LCH_CTRL_RX_DATA_COUNT            = 0; /* receive size will be filled after */
   l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_SRC      = K_SECU_ALERT_ACK_CMD_UDP_PORTS_SRC;
   l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_DST      = K_SECU_ALERT_ACK_CMD_UDP_PORTS_SRC;

   DRV_COM_MNT_ETH_READ( &l_eth_rx );

   if ( l_eth_rx.LCH_CTRL_RX_DATA_COUNT != 0 )
   {
      status = TRUE;
   }
   return ( status );
}

/* ---------- internal operation bodies: ------------------------------------ */
