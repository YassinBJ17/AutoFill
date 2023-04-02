/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "driver/mailbox/MAC_ETH_CFEX_public.h"
#include "driver/mailbox/MAC_ETH_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/mailbox/CFEX_HAL_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
const uint32_t c_MAC_ETH_CFEX_tab_SIZE = MAC_ETH_NB;

/* MBX configuration table */
const ts_MAC_ETH_CFEX_ELT c_MAC_ETH_CFEX_CONFIGURATION_tab[ MAC_ETH_NB ] =
{
   /* 0 - MBX 0 */
   {
      MAC_ETH_RX_REG_ADDR,                /* RX conf */
      MAC_ETH_RX_STATUS_REG_ADDR,         /* RX status */
      MAC_ETH_TX_STATUS_REG_ADDR,         /* TX status */
      MAC_ETH_MDIO_REG_ADDR,              /* MDIO */
      {                                   /* MAC rx filtering address source */
         MAC_ETH_CDMA_MAC_ADDR,
         MAC_ETH_CDMB_MAC_ADDR,
         0x00000000,
         0x00000000,
         0x00000000,
         0x00000000,
         0x00000000,
         0x00000000
      },
      {                                     /* MAC rx filtering address destination */
         MAC_ETH_CDRA_MAC_ADDR,
         MAC_ETH_BROADCAST_ADDR,
         MAC_ETH_CDRB_MAC_ADDR,
         0x00000000,
         0x00000000,
         0x00000000,
         0x00000000,
         0x00000000
      },
      MAC_ETH_CDM_MAC_MAC_SRC_MASK_ADDR,   /* MAC rx filter mask address destination */
      MAC_ETH_CDM_MAC_MAC_DEST_MASK_ADDR   /* MAC rx filter mask  address destination */
   }
};

/* ---------- internal data: ------------------------------------------------ */
/* MBX descriptor declaration */
ts_MAC_ETH_CONFIG_DESC MAC_ETH_CFEX_descriptor ;

/* ---------- provided operation bodies: ------------------------------------ */

