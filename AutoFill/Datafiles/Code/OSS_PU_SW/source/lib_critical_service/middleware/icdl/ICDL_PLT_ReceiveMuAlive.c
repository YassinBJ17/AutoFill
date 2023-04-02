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
#define K_MU_ALIVE_CMD_UDP_PORTS_SRC  49300
#define K_MU_ALIVE_CMD_UDP_PORTS_DST  49300


/* ---------- provided operation bodies: ------------------------------------ */
boolean_t ICDL_PLT_ReceiveMuAlive (uint8_t * pt_buff, uint32_t * pt_size )
{
   ts_DRV_COM_MNT_ETH_RX l_eth_rx;

   boolean_t status = FALSE;

   l_eth_rx.LCH_CTRL_RX_DATA                  = &(pt_buff[0]);
   l_eth_rx.LCH_CTRL_RX_DATA_COUNT            = 0; /* receive size will be filled after */
   l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_SRC      = K_MU_ALIVE_CMD_UDP_PORTS_DST;
   l_eth_rx.LCH_CTRL_RX_MSG_UDP_PORT_DST      = K_MU_ALIVE_CMD_UDP_PORTS_DST;

   DRV_COM_MNT_ETH_READ( &l_eth_rx );

   if ( l_eth_rx.LCH_CTRL_RX_DATA_COUNT != 0 )
   {
      status = TRUE;
      *pt_size = l_eth_rx.LCH_CTRL_RX_DATA_COUNT;
   }
   else
   {
      status = FALSE;
      *pt_size = 0;
   }
   return status;
}

/* ---------- internal operation bodies: ------------------------------------ */
