/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_MAC_PUBLIC_H
#define ETH_MAC_PUBLIC_H

#include "type/common_type.h"

/* ---------- provided define constants --------------------------------------- */
#define ETH_HAL_MAC_SIZE (6ul)
#define MAC_ETH_CDRA_MAC_ADDR { 0x02 , 0xFA , 0xDE , 0xC0 , 0x0A, 0x01 }
#define MAC_ETH_CDMA_MAC_ADDR { 0x02 , 0xFA , 0xDE , 0xC0 , 0x0A, 0x02 }
#define MAC_ETH_CDRB_MAC_ADDR { 0x02 , 0xFA , 0xDE , 0xC0 , 0x0B, 0x01 }
#define MAC_ETH_CDMB_MAC_ADDR { 0x02 , 0xFA , 0xDE , 0xC0 , 0x0B, 0x02 }
#define MAC_ETH_BROADCAST_ADDR{ 0xFF , 0xFF , 0xFF , 0xFF , 0xFF, 0xFF }
#define MAC_ETH_CDM_MAC_MAC_SRC_MASK_ADDR { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF, 0xFF }
#define MAC_ETH_CDM_MAC_MAC_DEST_MASK_ADDR { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF, 0xFF }



/* ---------- provided define types --------------------------------------- */
typedef uint8_t MAC_ETH_MACAddr_t[ ETH_HAL_MAC_SIZE ];


/* ---------- provided define data --------------------------------------- */

#endif /* ETH_MAC_PUBLIC_H */
